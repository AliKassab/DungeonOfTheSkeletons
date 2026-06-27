// Game.cpp -- see Game.h for the design overview.

#include "Game.h"
#include <string>
#include <fstream>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

namespace {
// Story slide filenames, in the order the original referenced s1..s28.
const char* kStoryFiles[28] = {
    "story1.jpg", "story2.jpg", "story3.jpg", "story4.jpg", "story5.jpg", "story6.jpg",
    "story7.jpg", "story8.jpg", "story1a.jpg", "story2b.jpg", "story3c.jpg", "story4d.jpg",
    "story2.1.jpg", "story2.2.jpg", "story2.3.jpg", "story2.4.jpg", "story2.5.jpg",
    "story2.6.jpg", "story2.7.jpg", "story3.1.jpg", "story3.2.jpg", "story3.3.jpg",
    "story3.4.jpg", "story3.5.jpg", "story3.6.jpg", "story3.7.jpg", "story3.8.jpg", "story3.9.jpg"
};
}

void Game::setup() {
    black.setTexture(assets.texture("Black.png")); black.setScale(0.75, 0.65);
    red.setTexture(assets.texture("Red.png"));     red.setScale(0.75, 0.65);

    GameFont& ui = assets.font("OpenSans-Italic.ttf");

    mainmenu.setFont(ui); mainmenu.setFillColor(RED); mainmenu.setString("Main Menu");
    mainmenu.setPosition(530, 200); mainmenu.setScale(1.5, 1.5);

    start.setFont(ui); start.setFillColor(RED); start.setString("Start");
    start.setPosition(600, 300); start.setScale(1, 1);

    about.setFont(ui); about.setFillColor(RED); about.setString("Controls");
    about.setPosition(595, 360); about.setScale(1, 1);

    exitText.setFont(ui); exitText.setFillColor(RED); exitText.setString("Exit");
    exitText.setCharacterSize(25); exitText.setPosition(607, 420); exitText.setScale(1.2, 1.2);

    info.setFont(ui); info.setFillColor(RED);
    info.setString("Use 'Left' and 'Right' to move\nPress 'Down' to crouch\nPress 'Up' to Jump\n\n\nBack");
    info.setPosition(500, 200); info.setScale(1, 1);

    player.init(assets);
    level1.build(assets);
    level2.build(assets);

    for (int i = 0; i < 28; i++) {
        storyImg[i].setTexture(assets.texture(kStoryFiles[i]));
    }

    scoreLabel.setFont(ui); scoreLabel.setFillColor(RED); scoreLabel.setString("Score :");
    scoreLabel.setPosition(10, 5); scoreLabel.setScale(0.7, 0.7);

    scoreValue.setFont(ui); scoreValue.setFillColor(RED);
    scoreValue.setPosition(80, 5); scoreValue.setScale(0.7, 0.7);

    highValue.setFont(ui); highValue.setFillColor(RED); highValue.setCharacterSize(25);
    highValue.setPosition(250, 5); highValue.setScale(0.9, 0.9);

    highLabel.setFont(ui); highLabel.setFillColor(RED); highLabel.setString("Highscore :");
    highLabel.setCharacterSize(25); highLabel.setPosition(130, 5); highLabel.setScale(0.9, 0.9);

    // audio
    eat.loadFromFile("coineat.mp3");                              eat.setVolume(5);
    ost.loadFromFile("Medieval_Music_-_Haunted_Ferryman.mp3");   ost.setVolume(50);
    telep.loadFromFile("TELEP.mp3");                             telep.setVolume(50);
    fireBall.loadFromFile("fireball.mp3");                       fireBall.setVolume(70);
    drink.loadFromFile("drink.mp3");                             drink.setVolume(100);
    spiderS.loadFromFile("spider.mp3");                          spiderS.setVolume(100);
    voice1.loadFromFile("First.mp3");                            voice1.setVolume(100);
    voice2.loadFromFile("Second_1.mp3");                         voice2.setVolume(100);
    voice3.loadFromFile("Third.mp3");                            voice3.setVolume(100);
    back1.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme.mp3");   back1.setVolume(100);
    back2.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_1.mp3"); back2.setVolume(100);
    back3.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_2.mp3"); back3.setVolume(100);
    mainMenu11.loadFromFile("game.mp3");                         mainMenu11.setVolume(80);
    lost.loadFromFile("lost.mp3");                               lost.setVolume(50);

    // HUD
    heart.setTexture(assets.texture("heart.png")); heart.setPosition(1050, 10); heart.setScale(0.2, 0.2);
    frame.setTexture(assets.texture("frame.png")); frame.setPosition(1060, 10); frame.setScale(1.03, 0.3);
    bar.setTexture(assets.texture("bar.png"));     bar.setPosition(1060, 16); bar.setScale(100, 0.3); bar.setColor(RED);
    lose.setTexture(assets.texture("lose.png"));   lose.setPosition(400, 150); lose.setScale(1, 1);
    win.setTexture(assets.texture("cong.png"));    win.setPosition(100, -50); win.setScale(1, 1);

    if (storyStart == 0) {
        mainMenu11.play();
        mainMenu11.setLoop(true);
    }
}

int Game::run() {
    window.create(1280, 720, "Dungeon of the skeletons");
    window.setFramerateLimit(30);
    // Use the native OS cursor (the browser draws it, so it tracks reliably on web);
    // the old in-game cur.png sprite is no longer drawn.

    setup();

#ifdef __EMSCRIPTEN__
    // The browser owns the loop. Use requestAnimationFrame (fps arg 0) so mouse/key
    // events sync correctly; tick() throttles game logic to 30 Hz internally.
    emscripten_set_main_loop_arg(
        [](void* self) { static_cast<Game*>(self)->tick(); }, this, 0, 1);
#else
    while (window.isOpen()) {
        tick();
    }
    CloseAudioDevice();
    CloseWindow();
#endif
    return 0;
}

void Game::tick() {
    // Keep the original fixed 30 Hz step regardless of how fast the browser calls us.
    static double lastStep = 0.0;
    double now = GetTime();
    if (now - lastStep < 1.0 / 30.0) return;
    lastStep = now;

    Level* current = (level == 1) ? static_cast<Level*>(&level1) : static_cast<Level*>(&level2);
    PlayContext ctx{ player, score, level, ending, eat, telep, drink, spiderS, fireBall, ost, assets };
    {

        // Alias the player's fields so the input logic reads like the original.
        Sprite& skeleton = player.sprite;
        int& cnterX = player.cnterX;
        int& cnterY = player.cnterY;
        int& jump = player.jump;
        bool& jumping = player.jumping;
        int& HP = player.hp;

        // ---- input: stand up when Down is released ----
        if (IsKeyReleased(KEY_DOWN) && jump >= 50 && ending == false && die == false) {
            if (cnterX == 0) { cnterY = 0; }
            else if (cnterX == 1) { cnterX = 3; cnterY = 1; }
            skeleton.move(0, -25);
        }

        // ---- menu buttons ----
        if (Mouse::isButtonPressed(Mouse::Left) && Cntgame == 0) {
            Mouse::Vec mousePos = Mouse::getPosition();
            if (mousePos.x > 607 && mousePos.x < 660 && mousePos.y > 425 && mousePos.y < 450) {
                window.close();
            } else if (mousePos.x > 600 && mousePos.x < 675 && mousePos.y > 300 && mousePos.y < 340) {
                storyStart = 1;
                mainMenu11.stop();
            } else if (mousePos.x > 595 && mousePos.x < 685 && mousePos.y > 365 && mousePos.y < 392) {
                Cntgame = 2;
            }
        }

        // ---- crouch ----
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
            if (cnterY == 0) { cnterY = 2; cnterX = 0; }
            else if (cnterY == 1) { cnterY = 2; cnterX = 1; }
        }

        // ---- walk ----
        if (Keyboard::isKeyPressed(Keyboard::Key::Right) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
            cnterY = 0;
            cnterX++;
            if (current->atRightEdge()) { skeleton.move(8, 0); } else { current->scroll(-8, 0); }
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
            if (current->atLeftEdge()) { skeleton.move(-8, 0); } else { current->scroll(8, 0); }
            cnterY = 1;
            cnterX++;
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && jump >= 50 && Cntgame == 1 && jumping == true && ending == false && die == false) {
            jump = 0;
            jumping = false;
            if (cnterY == 0) { cnterX = 2; }
            else if (cnterY == 1) { cnterX = 1; }
        }

        player.animate();
        bar.setScale(HP, 0.3);
        jump++;

        if (jump < 50) {
            skeleton.move(0, -8);
            skeleton.move(0, (jump - 25) / 2.7);
            if (Keyboard::isKeyPressed(Keyboard::Key::Right) && ending == false && die == false) {
                cnterY = 0;
                cnterX = 2;
                if (current->atRightEdge()) { skeleton.move(5, 0); } else { current->scroll(-5, 0); }
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Left) && ending == false && die == false) {
                if (current->atLeftEdge()) { skeleton.move(-5, 0); } else { current->scroll(5, 0); }
                cnterX = 1;
                cnterY = 1;
            }
        }

        if (skeleton.getPosition().x < 60) { skeleton.move(8, 0); }
        if (skeleton.getPosition().x > 1190) { skeleton.move(-8, 0); }

        // ---- level logic (kept as two sequential checks so a same-frame level
        //      switch matches the original behaviour exactly) ----
        if (level == 1 && die == false) level1.update(ctx);
        if (level == 2 && die == false) level2.update(ctx);

        if (Keyboard::isKeyPressed(Keyboard::Key::L)) {
            level = 2;
            skeleton.setPosition(150, 100);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Space) && Cntgame == 0 && storyStart == 1) {
            Cntgame = 1;
            voice1.stop(); voice2.stop(); voice3.stop();
            back1.stop(); back2.stop(); back3.stop();
            ost.play();
            ost.setLoop(true);
        }

        // ---- render ----
        window.clear();
        Cntmainmenubg++;

        if (Cntgame == 0) {
            if (Cntmainmenubg < 31) { window.draw(black); }
            else { window.draw(red); }
            if (Cntmainmenubg == 62) { Cntmainmenubg = 0; }
            window.draw(mainmenu);
            window.draw(start);
            window.draw(about);
            window.draw(exitText);
        }

        if (Cntgame == 2) {
            if (Cntmainmenubg < 31) { window.draw(black); }
            else { window.draw(red); }
            if (Cntmainmenubg == 62) { Cntmainmenubg = 0; }
            window.draw(info);
            if (Mouse::isButtonPressed(Mouse::Left)) {
                Mouse::Vec mousePos = Mouse::getPosition();
                if (mousePos.x > 500 && mousePos.x < 570 && mousePos.y > 410 && mousePos.y < 430) {
                    Cntgame = 0;
                }
            }
        }

        if (storyStart == 1 && Cntgame == 0) {
            story++;
            sec++;
            if (sec < 750) {
                if (sec == 60) { voice1.play(); }
                if (sec < 5) { back1.play(); }
                if (story < 5)       { window.draw(storyImg[0]); }
                else if (story < 10) { window.draw(storyImg[1]); }
                else if (story < 15) { window.draw(storyImg[2]); }
                else if (story < 20) { window.draw(storyImg[3]); }
                else if (story < 25) { window.draw(storyImg[4]); }
                else if (story < 30) { window.draw(storyImg[5]); }
                else if (story < 35) { window.draw(storyImg[6]); }
                else if (story < 40) {
                    window.draw(storyImg[7]);
                    if (sec < 750 && story == 39) { story = 0; }
                }
            } else if (sec > 750 && sec < 1200) {
                if (sec == 755) { voice2.play(); back2.play(); }
                if (story < 45)       { window.draw(storyImg[8]); }
                else if (story < 50)  { window.draw(storyImg[9]); }
                else if (story < 55)  { window.draw(storyImg[10]); }
                else if (story < 60)  { window.draw(storyImg[11]); }
                else if (story < 65)  { window.draw(storyImg[12]); }
                else if (story < 70)  { window.draw(storyImg[13]); }
                else if (story < 75)  { window.draw(storyImg[14]); }
                else if (story < 80)  { window.draw(storyImg[15]); }
                else if (story < 85)  { window.draw(storyImg[16]); }
                else if (story < 90)  { window.draw(storyImg[17]); }
                else if (story < 95)  {
                    window.draw(storyImg[18]);
                    if (story == 94) { story = 40; }
                }
            } else {
                if (sec == 1200) { voice3.play(); back3.play(); }
                if (story < 100)      { window.draw(storyImg[19]); }
                else if (story < 105) { window.draw(storyImg[20]); }
                else if (story < 110) { window.draw(storyImg[21]); }
                else if (story < 115) { window.draw(storyImg[22]); }
                else if (story < 120) { window.draw(storyImg[23]); }
                else if (story < 125) { window.draw(storyImg[24]); }
                else if (story < 130) { window.draw(storyImg[25]); }
                else if (story < 135) { window.draw(storyImg[26]); }
                else if (story < 140) { window.draw(storyImg[27]); }
                if (story == 139) { story = 95; }
            }
        }

        if (Cntgame == 1) {
            if (HP <= 0) { HP = 0; ost.stop(); }

            if (skeleton.getPosition().x > -10 && ending == false) {
                skeleton.move(0, 8);
            }

            if (level == 1) level1.render(ctx, window);
            if (level == 2) level2.render(ctx, window);

            window.draw(skeleton);
            if (level == 2) level2.drawOverlay(window);

            // high score persistence
            {
                std::ifstream readFile("assets/Highscore.txt");
                if (readFile.is_open()) { readFile >> highscore; }
                readFile.close();
                std::ofstream writeFile("assets/Highscore.txt");
                if (writeFile.is_open()) {
                    if (score > highscore) { highscore = score; }
                    writeFile << highscore;
                }
                writeFile.close();
            }
            scoreValue.setString(std::to_string(score));
            highValue.setString(std::to_string(highscore));

            window.draw(scoreLabel);
            window.draw(scoreValue);
            window.draw(highLabel);
            window.draw(highValue);
            window.draw(bar);
            window.draw(frame);
            window.draw(heart);
        }

        if (HP <= 0 && die == false) { die = true; lost.play(); }
        if (die) { window.draw(lose); skeleton.move(0, -8); }
        if (ending == true) { window.draw(win); }

        window.display();
    }
}
