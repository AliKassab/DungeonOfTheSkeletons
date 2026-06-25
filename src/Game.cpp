// Game.cpp -- see Game.h for the design overview.

#include "Game.h"
#include <string>
#include <fstream>

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
    cursor.setTexture(assets.texture("cur.png"));

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

    level1Phase();
    level2Phase();
    buildPlatforms();
    buildCoins();

    Tex& boxTex = assets.texture("box.png");
    for (int i = 0; i < 4; i++) {
        box[i].setTexture(boxTex);
        box[i].setTextureRect(IntRect(0, 0, 32, 32));
        box[i].setScale(1, 1);
    }
    box[0].setPosition(154 + 1280, 60 + 720);
    box[1].setPosition(262 + 1280, 229 + 720);
    box[2].setPosition(624 + 1280, 298 + 720);
    box[3].setPosition(710 + 1280, 60 + 720);

    archer.init(assets);

    arrow.setTexture(assets.texture("arrow1.png"));
    arrow.setPosition(1100, 1030);
    arrow.setTextureRect(IntRect(0, 0, 32, 12));
    arrow.rotate(180);

    fireball1.setTexture(assets.texture("fireball.png"));
    fireball1.setPosition(1100, 200);
    fireball1.setTextureRect(IntRect(0, 0, 164, 84));
    fireball1.rotate(180);
    fireball1.setScale(0.4, 0.4);

    fireball2.setTexture(assets.texture("fireball.png"));
    fireball2.setPosition(80, 300);
    fireball2.setTextureRect(IntRect(0, 0, 164, 84));
    fireball2.setScale(0.4, 0.4);

    finalDoor.setTexture(assets.texture("final.png"));
    finalDoor.setPosition(1300, 850);
    finalDoor.setTextureRect(IntRect(0, 0, 28, 48));
    finalDoor.setScale(1, 1);

    Tex& hiddenTex = assets.texture("hidden.png");
    for (int i = 0; i < 20; i++) {
        hidden[i].setTexture(hiddenTex);
        hidden[i].setTextureRect(IntRect(0, 0, 206.25, 30));
        hidden[i].setScale(1, 0.7);
        hidden[0].setPosition(60, 980);
        hidden[1].setPosition(266, 980);
        hidden[2].setPosition(472, 980);
        hidden[3].setPosition(678, 980);
        hidden[4].setPosition(884, 980);
        hidden[5].setPosition(1018, 1140);
        hidden[6].setPosition(812, 1140);
        hidden[7].setPosition(606, 1140);
        hidden[8].setPosition(400, 1140);
        hidden[9].setPosition(294, 1140);
        hidden[9].setScale(0.5, 0.7);
    }

    Tex& p1Tex = assets.texture("p1.png");
    for (int i = 0; i < 15; i++) {
        p1[i].setTexture(p1Tex);
        p1[i].setScale(1, 1);
        p1[i].setTextureRect(IntRect(0, 0, 128, 50));
        if (i < 8) { poison(62, 1000, i); }
        else { poison(320, 1150, i); }
    }

    Tex& potionTex = assets.texture("heal.png");
    for (int i = 0; i < 2; i++) {
        potion[i].setTexture(potionTex);
        potion[i].setTextureRect(IntRect(0, 0, 40, 47));
        potion[0].setPosition(1100, 1345);
        potion[1].setPosition(2050, 251 + 690);
        potionbool[i] = 1;
    }

    key.setTexture(assets.texture("key.png"));
    key.setPosition(2400, 120);
    key.setTextureRect(IntRect(0, 0, 318, 222));
    key.setScale(0.13, 0.13);
    keyi.setTexture(assets.texture("key.png"));
    keyi.setPosition(63, 1333);
    keyi.setTextureRect(IntRect(0, 0, 318, 222));
    keyi.setScale(0.13, 0.13);

    int pos = 0;
    Tex& spikeTex = assets.texture("spike.png");
    for (int i = 1; i < 28; i++) {
        spike[i].setTextureRect(IntRect(0, 0, 556, 259));
        spike[i].setTexture(spikeTex);
        spike[i].setScale(0.1, 0.1);
    }
    for (int i = 4; i < 25; i++) {
        spike[i].setPosition(1290 + pos, 1350);
        pos += 59;
    }
    int space = 0;
    for (int i = 25; i < 28; i++) {
        spike[i].setPosition(300 + space, 652);
        space += 300;
    }
    spike[1].setPosition(2250, 385);
    spike[2].setPosition(1750, 961);
    spike[3].setPosition(1500, 961);

    Tex& portalTex = assets.texture("portal.png");
    portalg1.setTexture(portalTex); portalg1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg1.setScale(0.2, 0.2); portalg1.setPosition(2500, 575);

    portalg2.setTexture(portalTex); portalg2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg2.setScale(0.2, 0.2); portalg2.setPosition(100, 1000); portalg2.rotate(180);

    portalg3.setTexture(portalTex); portalg3.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg3.setScale(0.2, 0.2); portalg3.setPosition(2500, 130);

    portalg4.setTexture(portalTex); portalg4.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg4.setScale(0.2, 0.2); portalg4.setPosition(100, 1000); portalg4.rotate(180);

    Tex& portalPTex = assets.texture("portalp.png");
    portalp1.setTexture(portalPTex); portalp1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalp1.setScale(0.2, 0.2); portalp1.setPosition(2480, 950);

    portalp2.setTexture(portalPTex); portalp2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalp2.setScale(0.2, 0.2); portalp2.setPosition(100, 250); portalp2.rotate(180);

    Tex& portalRTex = assets.texture("portalr.png");
    portalr1.setTexture(portalRTex); portalr1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalr1.setScale(0.2, 0.2); portalr1.setPosition(2500, 590);

    portalr2.setTexture(portalRTex); portalr2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalr2.setScale(-0.2, 0.2); portalr2.setPosition(1405, 100); portalr2.rotate(90);

    Tex& brickTex = assets.texture("up.png");
    for (int i = 0; i < 3; i++) {
        brick[i].setTexture(brickTex);
        brick[i].setTextureRect(IntRect(0, 0, 207, 74));
        brick[i].setScale(0.7, 0.7);
        brick[0].setPosition(1380, 1285);
        brick[1].setPosition(2000, 1285);
        brick[2].setPosition(2150, 1310);
    }

    for (int i = 0; i < 28; i++) {
        storyImg[i].setTexture(assets.texture(kStoryFiles[i]));
    }

    spider.init(assets);

    scoreLabel.setFont(ui); scoreLabel.setFillColor(RED); scoreLabel.setString("Score :");
    scoreLabel.setPosition(10, 5); scoreLabel.setScale(0.7, 0.7);

    scoreValue.setFont(ui); scoreValue.setFillColor(RED);
    scoreValue.setPosition(80, 5); scoreValue.setScale(0.7, 0.7);

    highValue.setFont(ui); highValue.setFillColor(RED); highValue.setCharacterSize(25);
    highValue.setPosition(250, 5); highValue.setScale(0.9, 0.9);

    highLabel.setFont(ui); highLabel.setFillColor(RED); highLabel.setString("Highscore :");
    highLabel.setCharacterSize(25); highLabel.setPosition(130, 5); highLabel.setScale(0.9, 0.9);

    // audio
    eat.loadFromFile("coineat.wav");                              eat.setVolume(5);
    ost.loadFromFile("Medieval_Music_-_Haunted_Ferryman.wav");   ost.setVolume(50);
    telep.loadFromFile("TELEP.wav");                             telep.setVolume(50);
    fireBall.loadFromFile("fireball.wav");                       fireBall.setVolume(70);
    drink.loadFromFile("drink.wav");                             drink.setVolume(100);
    spiderS.loadFromFile("spider.wav");                          spiderS.setVolume(100);
    voice1.loadFromFile("First.wav");                            voice1.setVolume(100);
    voice2.loadFromFile("Second_1.wav");                         voice2.setVolume(100);
    voice3.loadFromFile("Third.wav");                            voice3.setVolume(100);
    back1.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme.wav");   back1.setVolume(100);
    back2.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_1.wav"); back2.setVolume(100);
    back3.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_2.wav"); back3.setVolume(100);
    mainMenu11.loadFromFile("game.wav");                         mainMenu11.setVolume(80);
    lost.loadFromFile("lost.wav");                               lost.setVolume(50);

    // HUD
    heart.setTexture(assets.texture("heart.png")); heart.setPosition(1050, 10); heart.setScale(0.2, 0.2);
    frame.setTexture(assets.texture("frame.png")); frame.setPosition(1060, 10); frame.setScale(1.03, 0.3);
    bar.setTexture(assets.texture("bar.png"));     bar.setPosition(1060, 16); bar.setScale(100, 0.3); bar.setColor(RED);
    lose.setTexture(assets.texture("lose.png"));   lose.setPosition(400, 150); lose.setScale(1, 1);
    win.setTexture(assets.texture("cong.png"));    win.setPosition(100, -50); win.setScale(1, 1);

    Tex& fireTex = assets.texture("fireb.png");
    for (int i = 0; i < 3; i++) {
        fire[i].setTexture(fireTex);
        fire[i].setTextureRect(IntRect(0, 0, 74, 121));
        fire[0].setPosition(1455, 510);
        fire[1].setPosition(1865, 510);
        fire[2].setPosition(2195, 510);
    }

    Tex& up2Tex = assets.texture("up2.png");
    for (int i = 0; i < 5; i++) {
        up2[i].setTexture(up2Tex);
        up2[i].setTextureRect(IntRect(0, 0, 207, 74));
        up2[0].setPosition(1448, 485);
        up2[1].setPosition(1850, 485);
        up2[2].setPosition(2180, 485);
        up2[i].setScale(0.7, 0.7);
    }

    wizard.init(assets);

    if (storyStart == 0) {
        mainMenu11.play();
        mainMenu11.setLoop(true);
    }
}

int Game::run() {
    window.create(1280, 720, "Dungeon of the skeletons");
    window.setFramerateLimit(30);
    window.setMouseCursorVisible(false);

    setup();

    while (window.isOpen()) {
        // Alias the player's fields so the gameplay logic below reads exactly like the
        // original while operating on the Player object.
        Sprite& skeleton = player.sprite;
        int& cnterX = player.cnterX;
        int& cnterY = player.cnterY;
        int& jump = player.jump;
        bool& jumping = player.jumping;
        int& HP = player.hp;
        int& damage = player.damage;

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

        // ---- player move ----
        if (Keyboard::isKeyPressed(Keyboard::Key::Right) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
            cnterY = 0;
            cnterX++;
            if (level == 1) {
                if (phase2.getPosition().x < 0) { skeleton.move(8, 0); }
                else { move(-8, 0); }
            }
            if (level == 2) {
                if (phase6.getPosition().x < 0) { skeleton.move(8, 0); }
                else { move2(-8, 0); }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
            if (level == 1) {
                if (phase1.getPosition().x > 0) { skeleton.move(-8, 0); }
                else { move(8, 0); }
            }
            if (level == 2) {
                if (phase5.getPosition().x > 0) { skeleton.move(-8, 0); }
                else { move2(8, 0); }
            }
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
                if (level == 1) {
                    if (phase2.getPosition().x < 0) { skeleton.move(5, 0); }
                    else { move(-5, 0); }
                }
                if (level == 2) {
                    if (phase6.getPosition().x < 0) { skeleton.move(5, 0); }
                    else { move2(-5, 0); }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Left) && ending == false && die == false) {
                if (level == 1) {
                    if (phase1.getPosition().x > 0) { skeleton.move(-5, 0); }
                    else { move(5, 0); }
                }
                if (level == 2) {
                    if (phase5.getPosition().x > 0) { skeleton.move(-5, 0); }
                    else { move2(5, 0); }
                }
                cnterX = 1;
                cnterY = 1;
            }
        }

        pr++;
        pr %= 100000;
        if (pr % 10 == 0) {
            cnterPr++;
            cnterPr %= 4;
            portalg2.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalg3.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalg1.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalp1.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalp2.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalr1.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
            portalr2.setTextureRect(IntRect(cnterPr * 297.5, cnterPr * 0, 297.5, 570));
        }

        if (skeleton.getPosition().x < 60) { skeleton.move(8, 0); }
        if (skeleton.getPosition().x > 1190) { skeleton.move(-8, 0); }

        if (level == 1 && die == false) {
            spider.update();

            if (skeleton.getGlobalBounds().intersects(portalg1.getGlobalBounds()) && keyopen == true) {
                telep.play();
                skeleton.setPosition(150, 200);
                move(1300, -720);
            } else if (skeleton.getGlobalBounds().intersects(portalg2.getGlobalBounds())) {
                telep.play();
                skeleton.setPosition(1150, 600);
                move(-1300, 720);
            }
            if (skeleton.getGlobalBounds().intersects(portalp1.getGlobalBounds())) {
                telep.play();
                level = 2;
                skeleton.setPosition(150, 100);
            }

            bricks++;
            if (bricks <= 70) { brick[0].move(3, 0); brick[1].move(-3, 0); }
            else if (bricks > 70 && bricks <= 140) { brick[0].move(-3, 0); brick[1].move(3, 0); }
            else { bricks = 0; }

            brickUp++;
            if (brickUp <= 100) { brick[2].move(0, -4); }
            else if (brickUp > 100 && brickUp <= 200) { brick[2].move(0, 4); }
            else { brickUp = 0; }

            if (skeleton.getGlobalBounds().intersects(brick[0].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[0].getPosition().y) {
                skeleton.move(0, -8);
                jumping = true;
                if (bricks <= 70) { skeleton.move(3, 0); } else { skeleton.move(-3, 0); }
            }
            if (skeleton.getGlobalBounds().intersects(brick[1].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[1].getPosition().y) {
                skeleton.move(0, -8);
                jumping = true;
                if (bricks <= 70) { skeleton.move(-3, 0); } else { skeleton.move(3, 0); }
            }
            if (skeleton.getGlobalBounds().intersects(brick[2].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[2].getPosition().y) {
                jumping = true;
                if (brickUp <= 100) { skeleton.move(0, -12); } else { skeleton.move(0, -8); }
            }

            archer.animate();

            for (int i = 0; i < 20; i++) {
                if ((skeleton.getGlobalBounds().intersects(platform[i].getGlobalBounds()))) {
                    skeleton.move(0, -8); jumping = true; jump = 51;
                }
                if ((skeleton.getGlobalBounds().intersects(platform1[i].getGlobalBounds()))) {
                    jump = 51; skeleton.move(0, 8);
                }
                if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) { move(-8, 0); }
                if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) { move(8, 0); }
            }

            if (skeleton.getGlobalBounds().intersects(key.getGlobalBounds()) && keyopen == false) {
                keyopen = true; eat.play();
            }
            if (skeleton.getGlobalBounds().intersects(keyi.getGlobalBounds()) && keyis == false) {
                keyis = true; eat.play();
            }
        }

        if (level == 2 && die == false) {
            for (int i = 21; i < 60; i++) {
                if ((skeleton.getGlobalBounds().intersects(platform[i].getGlobalBounds()))) {
                    skeleton.move(0, -8); jumping = true; jump = 51;
                }
                if ((skeleton.getGlobalBounds().intersects(platform1[i].getGlobalBounds()))) {
                    jump = 51; skeleton.move(0, 8);
                }
                if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) { move2(-8, 0); }
                if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) { move2(8, 0); }
                if (skeleton.getGlobalBounds().intersects(portalp2.getGlobalBounds())) {
                    telep.play(); level = 1; skeleton.setPosition(1150, 150);
                }
                if (skeleton.getGlobalBounds().intersects(portalr1.getGlobalBounds())) {
                    telep.play(); skeleton.setPosition(30, 100);
                }
            }
            fp++;
            if (fp % 3 == 0) {
                cntfp++;
                cntfp %= 61;
                for (int i = 0; i < 5; i++) { fire[i].setTextureRect(IntRect(cntfp * 74, cntfp * 0, 74, 121)); }
            }
            fireScale++;
            if (fireScale < 100) {
                fireY++;
                for (int i = 0; i < 5; i++) { fire[i].setScale(fireY / 50, fireY / 100); fire[i].move(-0.7, 0); }
            } else if (fireScale < 200) {
                fireY--;
                for (int i = 0; i < 5; i++) { fire[i].setScale(fireY / 50, fireY / 100); fire[i].move(0.7, 0); }
            } else {
                fireScale = 0; fireY = 70;
            }

            wizard.animate();

            for (int i = 0; i < 20; i++) {
                if ((skeleton.getGlobalBounds().intersects(hidden[i].getGlobalBounds())) && hiddenarr[i] < 3) {
                    Cnthiddenarr[i]++; jump = 51; jumping = true; skeleton.move(0, -8);
                }
                if (Cnthiddenarr[i] > 0) { Cnthiddenarr[i]++; }
                if (Cnthiddenarr[i] == 0) { continue; }
                if (Cnthiddenarr[i] % 13 == 0) { hiddenarr[i]++; }
                hidden[i].setTextureRect(IntRect(hiddenarr[i] * 206.25, hiddenarr[i] * 0, 206.25, 30));
            }

            if (skeleton.getGlobalBounds().intersects(portalg3.getGlobalBounds())) {
                telep.play(); skeleton.setPosition(70, 100); move2(1320, -720);
            }

            pr1++;
            if (pr1 % 7 == 0 && ending == false) {
                cnterPr1++;
                cnterPr1 %= 5;
                for (int i = 0; i < 15; i++) { p1[i].setTextureRect(IntRect(cnterPr1 * 128, cnterPr1 * 0, 128, 50)); }
            }

            for (int i = 0; i < 4; i++) {
                if (skeleton.getPosition().x > box[i].getPosition().x - 25 && skeleton.getPosition().y > box[i].getPosition().y) {
                    boxtrap[i] = true;
                }
                if (boxtrap[i] == true) { box[i].move(0, 10); }
                if (skeleton.getGlobalBounds().intersects(box[i].getGlobalBounds())) { HP -= 1; }
            }

            if (skeleton.getGlobalBounds().intersects(finalDoor.getGlobalBounds()) && ending == false) {
                ending = true;
            }

            if (ending == true) {
                assets.reload("skeleton.png", "ameer.png");
                skeleton.setTextureRect(IntRect(0, 0, 64, 80));
                skeleton.setScale(-0.8, 1);
                ost.stop();
            }
        }

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

        Mouse::Vec mpos = Mouse::getPosition();
        cursor.setPosition(mpos.x, mpos.y);

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

            int firePosX = phase5.getPosition().x;
            int firePosY = phase5.getPosition().y;
            if (wizard.getFrame() == 5) {
                fireball1.setPosition(1240 + firePosX, 270 + firePosY);
                fireball2.setPosition(50 + firePosX, 410 + firePosY);
            }
            fireball1.move(-30, 0);
            fireball2.move(30, 0);

            if (skeleton.getPosition().x > -10 && ending == false) {
                skeleton.move(0, 8);
            }

            if (level == 1) {
                for (int i = 0; i < 20; i++) {
                    window.draw(platform[i]);
                    window.draw(platform1[i]);
                    window.draw(platform2[i]);
                    window.draw(platform3[i]);
                }
                window.draw(phase4);
                window.draw(phase3);
                window.draw(phase2);
                window.draw(phase1);
                window.draw(portalg2);
                window.draw(portalp1);
                window.draw(archer.sprite);
                window.draw(arrow);
                window.draw(spider.sprite);

                if (keyopen == 0) { window.draw(key); }
                if (keyopen)      { window.draw(portalg1); }
                if (keyis == 0)   { window.draw(keyi); }

                for (int i = 0; i < 2; i++) {
                    if (potionbool[i] == 1) { window.draw(potion[i]); }
                    if (skeleton.getGlobalBounds().intersects(potion[i].getGlobalBounds()) && HP < 71 && potionbool[i] == true) {
                        potionbool[i] = 0; HP += 30; drink.play();
                    } else if (skeleton.getGlobalBounds().intersects(potion[i].getGlobalBounds()) && HP > 70 && potionbool[i] == 1) {
                        potionbool[i] = 0; drink.play(); HP = 100;
                    }
                }

                for (int i = 1; i < 28; i++) {
                    if (i == 4 || i == 24) { continue; }
                    if (skeleton.getGlobalBounds().intersects(spike[i].getGlobalBounds())) { HP -= 1; }
                    window.draw(spike[i]);
                }

                for (int i = 0; i < 41; i++) {
                    if (skeleton.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && coinbool[i] == 1) {
                        coinbool[i] = 0; eat.play(); score += 10;
                    }
                    if (coinbool[i] == 1) { window.draw(coin[i]); }
                }
                if (keyis) {
                    for (int i = 0; i < 3; i++) { window.draw(brick[i]); }
                }

                int arrowPosX = phase1.getPosition().x;
                int arrowPosY = phase1.getPosition().y;
                if (archer.getFrame() == 6) {
                    arrow.setPosition(1170 + arrowPosX, 210 + 835 + arrowPosY);
                }
                arrow.move(-18, 0);

                if (skeleton.getGlobalBounds().intersects(arrow.getGlobalBounds()) && damage == 0) {
                    HP -= 30; damage = 1;
                } else if (skeleton.getGlobalBounds().intersects(spider.getGlobalBounds()) && damage == 0) {
                    HP -= 30; damage = 1; spiderS.play();
                } else if (skeleton.getGlobalBounds().intersects(arrow.getGlobalBounds()) && damage == 1) {
                    damage = 1;
                } else if (skeleton.getGlobalBounds().intersects(spider.getGlobalBounds()) && damage == 1) {
                    damage = 1;
                } else {
                    damage = 0;
                }
            }

            if (level == 2) {
                for (int i = 21; i < 60; i++) {
                    window.draw(platform1[i]);
                    window.draw(platform3[i]);
                    window.draw(platform2[i]);
                    window.draw(platform[i]);
                }
                window.draw(phase5);
                window.draw(phase6);
                window.draw(phase7);
                window.draw(phase8);
                window.draw(portalg3);
                window.draw(portalp2);
                window.draw(portalr1);
                window.draw(portalr2);
                window.draw(fireball1);
                window.draw(fireball2);

                for (int i = 0; i < 20; i++) { window.draw(hidden[i]); }
                if (wizard.getFrame() == 3 && phase5.getPosition().x >= -1200 && phase5.getPosition().y >= -10) {
                    fireBall.play();
                }

                if ((skeleton.getGlobalBounds().intersects(fireball1.getGlobalBounds()) ||
                     skeleton.getGlobalBounds().intersects(fireball2.getGlobalBounds())) && damage == 0) {
                    HP -= 30; damage = 1;
                } else if ((skeleton.getGlobalBounds().intersects(fireball1.getGlobalBounds()) ||
                            skeleton.getGlobalBounds().intersects(fireball2.getGlobalBounds())) && damage == 1) {
                    damage = 1;
                } else {
                    damage = 0;
                }

                for (int i = 0; i < 15; i++) {
                    if (skeleton.getGlobalBounds().intersects(p1[i].getGlobalBounds())) { HP -= 10; }
                }

                for (int i = 41; i < 60; i++) {
                    if (skeleton.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && coinbool[i] == 1) {
                        coinbool[i] = 0; eat.play(); score += 10;
                    }
                    if (coinbool[i] == 1) { window.draw(coin[i]); }
                }

                for (int i = 0; i < 5; i++) {
                    window.draw(fire[i]);
                    if (skeleton.getGlobalBounds().intersects(fire[i].getGlobalBounds()) &&
                        skeleton.getPosition().x > up2[i].getPosition().x &&
                        skeleton.getPosition().x < up2[i].getPosition().x + 145) {
                        HP -= 1;
                    }
                }
                for (int i = 0; i < 5; i++) { window.draw(up2[i]); }
                wizard.draw(window);
                if (ending == false) { window.draw(finalDoor); }
            }

            window.draw(skeleton);
            if (level == 2) {
                for (int i = 0; i < 15; i++) { window.draw(p1[i]); }
                for (int i = 0; i < 4; i++) { window.draw(box[i]); }
            }

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

        window.draw(cursor);
        window.display();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}

// ================= helpers =====================

void Game::coinn(int x, int y, int co, int i) {
    coin[i].setPosition(x + co, y);
    coinPos += 40;
    coinbool[i] = 1;
    if (i > 40) { coinPos2 += 40; }
}

void Game::level1Phase() {
    phase1.setTexture(assets.texture("phase1.png"));
    phase1.setTextureRect(IntRect(0, 0, 1280, 720)); phase1.setPosition(0, 0); phase1.setScale(1, 1);
    phase2.setTexture(assets.texture("phase2.png"));
    phase2.setTextureRect(IntRect(0, 0, 1280, 720)); phase2.setPosition(1280, 0); phase2.setScale(1, 1);
    phase3.setTexture(assets.texture("phase3.png"));
    phase3.setTextureRect(IntRect(0, 0, 1280, 720)); phase3.setPosition(0, 720); phase3.setScale(1, 1);
    phase4.setTexture(assets.texture("phase4.png"));
    phase4.setTextureRect(IntRect(0, 0, 1280, 720)); phase4.setPosition(1280, 720); phase4.setScale(1, 1);
}

void Game::level2Phase() {
    phase5.setTexture(assets.texture("phase5.png"));
    phase5.setTextureRect(IntRect(0, 0, 1280, 720)); phase5.setPosition(0, 0); phase5.setScale(1, 1);
    phase6.setTexture(assets.texture("phase6.png"));
    phase6.setTextureRect(IntRect(0, 0, 1280, 720)); phase6.setPosition(1280, 0); phase6.setScale(1, 1);
    phase7.setTexture(assets.texture("phase7.png"));
    phase7.setTextureRect(IntRect(0, 0, 1280, 720)); phase7.setPosition(0, 720); phase7.setScale(1, 1);
    phase8.setTexture(assets.texture("phase8.png"));
    phase8.setTextureRect(IntRect(0, 0, 1280, 720)); phase8.setPosition(1280, 720); phase8.setScale(1, 1);
}

void Game::buildPlatforms() {
    Tex& t0 = assets.texture("platform.png");
    for (int i = 0; i < 60; i++) { platform[i].setTextureRect(IntRect(0, 0, 88, 5)); platform[i].setTexture(t0); }
    platform[0].setScale(11.1, 2);   platform[0].setPosition(70, 265);
    platform[1].setScale(12.4, 2);   platform[1].setPosition(345, 433);
    platform[2].setScale(1.3, 2);    platform[2].setPosition(1520, 530);
    platform[3].setScale(1.3, 2);    platform[3].setPosition(1600, 365);
    platform[4].setScale(1.3, 2);    platform[4].setPosition(1825, 285);
    platform[5].setScale(1.3, 2);    platform[5].setPosition(2075, 240);
    platform[6].setScale(1.7, 2);    platform[6].setPosition(2343, 185);
    platform[7].setScale(6.7, 2);    platform[7].setPosition(1900, 410);
    platform[8].setScale(9.4, 2);    platform[8].setPosition(1260, 990);
    platform[9].setScale(10.4, 2);   platform[9].setPosition(68, 1070);
    platform[10].setScale(0.5, 2);   platform[10].setPosition(1170, 1070);
    platform[11].setScale(0.5, 2);   platform[11].setPosition(1216, 60);
    platform[12].setScale(0.5, 2);   platform[12].setPosition(1216, 780);
    platform[13].setScale(30, 1);    platform[13].setPosition(0, 680);
    platform[14].setScale(30, 1);    platform[14].setPosition(0, 1380);
    platform[15].setScale(1.2, 1);   platform[15].setPosition(1345, 605);
    platform[21].setScale(1.8, 1.5); platform[21].setPosition(67, 325);
    platform[22].setScale(0.8, 1.5); platform[22].setPosition(350, 330);
    platform[23].setScale(0.8, 1.5); platform[23].setPosition(535, 335);
    platform[24].setScale(0.8, 1.5); platform[24].setPosition(715, 335);
    platform[25].setScale(0.8, 1.5); platform[25].setPosition(880, 335);
    platform[26].setScale(10.8, 1.5);platform[26].setPosition(260, 505);
    platform[27].setScale(28.35, 1.5);platform[27].setPosition(67, 700);
    platform[28].setScale(1.5, 1.5); platform[28].setPosition(1260, 230);
    platform[29].setScale(1.4, 1.5); platform[29].setPosition(1540, 230);
    platform[30].setScale(1.4, 1.5); platform[30].setPosition(1780, 230);
    platform[31].setScale(1.4, 1.5); platform[31].setPosition(2050, 230);
    platform[32].setScale(1.4, 1.5); platform[32].setPosition(2300, 230);
    platform[33].setScale(1.3, 1.5); platform[33].setPosition(1465, 490);
    platform[34].setScale(1.3, 1.5); platform[34].setPosition(1865, 490);
    platform[35].setScale(1.3, 1.5); platform[35].setPosition(2200, 490);
    platform[36].setScale(11.5, 0.5);platform[36].setPosition(84, 1050);
    platform[37].setScale(10.5, 0.5);platform[37].setPosition(316, 1192);
    platform[38].setScale(30, 1.5);  platform[38].setPosition(68, 1415);
    platform[39].setScale(0.7, 1.5); platform[39].setPosition(1085, 1011);
    platform[40].setScale(0.7, 1.5); platform[40].setPosition(259, 1158);
    platform[41].setScale(1.4, 1.5); platform[41].setPosition(212 + 1280, 188 + 720);
    platform[42].setScale(1.4, 1.5); platform[42].setPosition(402 + 1280, 210 + 720);
    platform[43].setScale(1.4, 1.5); platform[43].setPosition(585 + 1280, 246 + 720);
    platform[44].setScale(1.4, 1.5); platform[44].setPosition(307 + 1280, 573 + 720);
    platform[45].setScale(1.4, 1.5); platform[45].setPosition(764 + 1280, 206 + 720);
    platform[46].setScale(1.4, 1.5); platform[46].setPosition(931 + 1280, 257 + 720);
    platform[47].setScale(1.4, 1.5); platform[47].setPosition(1101 + 1280, 345 + 720);
    platform[48].setScale(1.4, 1.5); platform[48].setPosition(803 + 1280, 443 + 720);
    platform[49].setScale(1.4, 1.5); platform[49].setPosition(648 + 1280, 479 + 720);
    platform[50].setScale(1.4, 1.5); platform[50].setPosition(483 + 1280, 523 + 720);
    platform[51].setScale(1.4, 1.5); platform[51].setPosition(307 + 1280, 573 + 720);
    platform[52].setScale(1.4, 1.5); platform[52].setPosition(126 + 1280, 619 + 720);
    platform[53].setScale(1.4, 1.5); platform[53].setPosition(1272, 166 + 720);
    platform[54].setScale(1.4, 1.5); platform[54].setPosition(965 + 1280, 407 + 720);

    Tex& t1 = assets.texture("platform1.png");
    for (int i = 0; i < 60; i++) { platform1[i].setTextureRect(IntRect(0, 0, 88, 5)); platform1[i].setTexture(t1); }
    platform1[0].setScale(11.1, 2);   platform1[0].setPosition(70, 275);
    platform1[1].setScale(12.4, 2);   platform1[1].setPosition(345, 443);
    platform1[2].setScale(1.3, 2);    platform1[2].setPosition(1520, 540);
    platform1[3].setScale(1.3, 2);    platform1[3].setPosition(1600, 375);
    platform1[4].setScale(1.3, 2);    platform1[4].setPosition(1825, 305);
    platform1[5].setScale(1.3, 2);    platform1[5].setPosition(2075, 260);
    platform1[6].setScale(1.7, 2);    platform1[6].setPosition(2343, 205);
    platform1[7].setScale(6.7, 2);    platform1[7].setPosition(1900, 420);
    platform1[8].setScale(9.4, 2);    platform1[8].setPosition(1260, 1010);
    platform1[9].setScale(10.4, 2);   platform1[9].setPosition(68, 1090);
    platform1[10].setScale(0.5, 2);   platform1[10].setPosition(1170, 1090);
    platform1[11].setScale(0.5, 2);   platform1[11].setPosition(1216, 80);
    platform1[12].setScale(0.5, 2);   platform1[12].setPosition(1216, 800);
    platform1[13].setScale(30, 1);    platform1[13].setPosition(0, 700);
    platform1[14].setScale(30, 1);    platform1[14].setPosition(0, 1400);
    platform1[15].setScale(1.3, 1);   platform1[15].setPosition(1340, 640);
    platform1[21].setScale(1.8, 1.5); platform1[21].setPosition(67, 345);
    platform1[22].setScale(0.8, 1.5); platform1[22].setPosition(350, 350);
    platform1[23].setScale(0.8, 1.5); platform1[23].setPosition(535, 355);
    platform1[24].setScale(0.8, 1.5); platform1[24].setPosition(715, 355);
    platform1[25].setScale(0.8, 1.5); platform1[25].setPosition(880, 355);
    platform1[26].setScale(10.8, 1.5);platform1[26].setPosition(260, 525);
    platform1[27].setScale(28.35, 1.5);platform1[27].setPosition(67, 710);
    platform1[28].setScale(1.5, 1.5); platform1[28].setPosition(1260, 240);
    platform1[29].setScale(1.4, 1.5); platform1[29].setPosition(1540, 250);
    platform1[30].setScale(1.4, 1.5); platform1[30].setPosition(1780, 250);
    platform1[31].setScale(1.4, 1.5); platform1[31].setPosition(2050, 250);
    platform1[32].setScale(1.4, 1.5); platform1[32].setPosition(2300, 250);
    platform1[33].setScale(1.3, 1.5); platform1[33].setPosition(1465, 520);
    platform1[34].setScale(1.3, 1.5); platform1[34].setPosition(1865, 520);
    platform1[35].setScale(1.3, 1.5); platform1[35].setPosition(2200, 520);
    platform1[36].setScale(11.5, 0.5);platform1[36].setPosition(84, 1060);
    platform1[37].setScale(10.5, 0.5);platform1[37].setPosition(316, 1200);
    platform1[38].setScale(31, 1.5);  platform1[38].setPosition(68, 1430);
    platform1[39].setScale(1.4, 1.5); platform1[39].setPosition(402 + 1280, 220 + 720);
    platform1[40].setScale(1.4, 1.5); platform1[40].setPosition(585 + 1280, 256 + 720);
    platform1[41].setScale(1.4, 1.5); platform1[41].setPosition(307 + 1280, 583 + 720);
    platform1[42].setScale(1.4, 1.5); platform1[42].setPosition(764 + 1280, 215 + 720);
    platform1[43].setScale(1.4, 1.5); platform1[43].setPosition(931 + 1280, 265 + 720);
    platform1[44].setScale(1.4, 1.5); platform1[44].setPosition(1101 + 1280, 355 + 720);
    platform1[45].setScale(1.4, 1.5); platform1[45].setPosition(803 + 1280, 453 + 720);
    platform1[46].setScale(1.4, 1.5); platform1[46].setPosition(648 + 1280, 489 + 720);
    platform1[47].setScale(1.4, 1.5); platform1[47].setPosition(483 + 1280, 533 + 720);
    platform1[48].setScale(1.4, 1.5); platform1[48].setPosition(307 + 1280, 583 + 720);
    platform1[49].setScale(1.4, 1.5); platform1[49].setPosition(126 + 1280, 629 + 720);
    platform1[50].setScale(1.4, 1.5); platform1[50].setPosition(1272, 166 + 730);
    platform1[51].setScale(1.4, 1.5); platform1[51].setPosition(965 + 1280, 420 + 720);
    platform1[52].setScale(1.4, 1.5); platform1[52].setPosition(212 + 1280, 208 + 720);

    Tex& t2 = assets.texture("platform2.png");
    for (int i = 0; i < 60; i++) { platform2[i].setTextureRect(IntRect(0, 0, 88, 5)); platform2[i].setTexture(t2); }
    platform2[0].setScale(0.05, 5);   platform2[0].setPosition(1046.8, 264);
    platform2[1].setScale(0.05, 5);   platform2[1].setPosition(1436.2, 437);
    platform2[2].setScale(0.09, 5);   platform2[2].setPosition(1634.4, 530);
    platform2[3].setScale(0.05, 5);   platform2[3].setPosition(1714.4, 369);
    platform2[4].setScale(0.07, 5);   platform2[4].setPosition(1939.4, 285);
    platform2[5].setScale(0.07, 5);   platform2[5].setPosition(2189.4, 240);
    platform2[6].setScale(0.05, 5);   platform2[6].setPosition(3000, 185);
    platform2[7].setScale(0.05, 5);   platform2[7].setPosition(3000, 400);
    platform2[8].setScale(0.05, 5);   platform2[8].setPosition(2087.2, 990);
    platform2[9].setScale(0.05, 5);   platform2[9].setPosition(983.2, 1070);
    platform2[10].setScale(0.05, 5);  platform2[10].setPosition(1214, 1070);
    platform2[11].setScale(0.05, 100);platform2[11].setPosition(1260, 60);
    platform2[12].setScale(0.05, 100);platform2[12].setPosition(1250, 780);
    platform2[13].setScale(0.05, 100);platform2[13].setPosition(2640, 680);
    platform2[14].setScale(0.05, 5);  platform2[14].setPosition(2640, 1380);
    platform2[15].setScale(0.1, 9);   platform2[15].setPosition(1460, 600);
    platform2[21].setScale(0.1, 6);   platform2[21].setPosition(225, 325);
    platform2[22].setScale(0.1, 5.5); platform2[22].setPosition(420, 330);
    platform2[23].setScale(0.1, 5.5); platform2[23].setPosition(600, 335);
    platform2[24].setScale(0.1, 5.5); platform2[24].setPosition(780, 335);
    platform2[25].setScale(0.1, 5.5); platform2[25].setPosition(950, 335);
    platform2[26].setScale(0.1, 100); platform2[26].setPosition(1255, 60);
    platform2[27].setScale(0.1, 5.5); platform2[27].setPosition(1395, 230);
    platform2[28].setScale(0.1, 5.5); platform2[28].setPosition(1665, 230);
    platform2[29].setScale(0.1, 5.5); platform2[29].setPosition(1905, 230);
    platform2[30].setScale(0.1, 5.5); platform2[30].setPosition(2175, 230);
    platform2[31].setScale(0.1, 5.5); platform2[31].setPosition(2420, 230);
    platform2[32].setScale(0.05, 8);  platform2[32].setPosition(1145, 1015);
    platform2[33].setScale(0.05, 8);  platform2[33].setPosition(312, 1158);
    platform2[46].setScale(0.1, 100); platform2[46].setPosition(1260, 60 + 720);

    Tex& t3 = assets.texture("platform3.png");
    for (int i = 0; i < 60; i++) { platform3[i].setTextureRect(IntRect(0, 0, 88, 5)); platform3[i].setTexture(t3); }
    platform3[0].setScale(0.05, 5);   platform3[0].setPosition(65, 265);
    platform3[1].setScale(0.05, 5);   platform3[1].setPosition(340, 433);
    platform3[2].setScale(0.09, 5);   platform3[2].setPosition(1515, 530);
    platform3[3].setScale(0.05, 5);   platform3[3].setPosition(1595, 365);
    platform3[4].setScale(0.05, 5);   platform3[4].setPosition(1820, 285);
    platform3[5].setScale(0.05, 5);   platform3[5].setPosition(2070, 240);
    platform3[6].setScale(0.05, 5);   platform3[6].setPosition(2340, 185);
    platform3[7].setScale(0.05, 5);   platform3[7].setPosition(1895, 410);
    platform3[8].setScale(0.05, 5);   platform3[8].setPosition(1258, 990);
    platform3[9].setScale(0.05, 5);   platform3[9].setPosition(65, 1070);
    platform3[10].setScale(0.05, 5);  platform3[10].setPosition(1165, 1070);
    platform3[11].setScale(0.05, 100);platform3[11].setPosition(1216, 60);
    platform3[12].setScale(0.05, 100);platform3[12].setPosition(1216, 780);
    platform3[13].setScale(0.05, 2);  platform3[13].setPosition(0, 680);
    platform3[14].setScale(0.05, 2);  platform3[14].setPosition(0, 1380);
    platform3[15].setScale(0.1, 9);   platform3[15].setPosition(1330, 600);
    platform3[21].setScale(0.07, 5.5);platform3[21].setPosition(345, 330);
    platform3[22].setScale(0.07, 5.5);platform3[22].setPosition(530, 335);
    platform3[23].setScale(0.07, 5.5);platform3[23].setPosition(705, 335);
    platform3[24].setScale(0.07, 5.5);platform3[24].setPosition(870, 335);
    platform3[25].setScale(0.07, 100);platform3[25].setPosition(1210, 60);
    platform3[26].setScale(0.07, 5.5);platform3[26].setPosition(1535, 230);
    platform3[27].setScale(0.07, 5.5);platform3[27].setPosition(1770, 230);
    platform3[28].setScale(0.07, 5.5);platform3[28].setPosition(2045, 230);
    platform3[29].setScale(0.07, 5.5);platform3[29].setPosition(2295, 230);
    platform3[30].setScale(0.05, 8);  platform3[30].setPosition(1085, 1011);
    platform3[31].setScale(0.05, 8);  platform3[31].setPosition(259, 1158);
    platform3[46].setScale(0.1, 100); platform3[46].setPosition(1220, 60 + 720);
}

void Game::buildCoins() {
    Tex& coinTex = assets.texture("coin.png");
    for (int i = 0; i < 41; i++) {
        coin[i].setTexture(coinTex);
        coin[i].setTextureRect(IntRect(0, 0, 1800, 1900));
        coin[i].setScale(0.014, 0.014);
        if (i == 26) { coinPos = 0; }
        if (i >= 0 && i < 7) { coinn(300, 235, coinPos, i); }
        else if (i >= 5 && i < 14) { coinn(300, 400, coinPos, i); }
        else if (i >= 14 && i < 41) {
            if (i == 14)       { coinn(1000, 500, coinPos, i); }
            else if (i == 15)  { coinn(730, 405, coinPos, i); }
            else if (i == 16)  { coinn(1010, 333, coinPos, i); }
            else if (i == 17)  { coinn(1185, 255, coinPos, i); }
            else if (i == 18)  { coinn(1400, 210, coinPos, i); }
            else if (i > 18 && i <= 20)  { coinn(10000000, 1000000, coinPos, i); }
            else if (i > 20 && i <= 22)  { coinn(1310, 382, coinPos, i); }
            else if (i > 22 && i <= 25)  { coinn(1415, 382, coinPos, i); }
            else if (i > 25 && i <= 31)  { coinn(179, 339 + 705, coinPos, i); }
            else if (i > 31 && i <= 34)  { coinn(1110, 964.5, coinPos, i); }
            else if (i > 34 && i <= 37)  { coinn(1245, 964.5, coinPos, i); }
            else if (i > 37 && i <= 40)  { coinn(1400, 964.5, coinPos, i); }
        }
    }
    for (int i = 41; i < 60; i++) {
        coin[i].setTexture(coinTex);
        coin[i].setTextureRect(IntRect(0, 0, 1800, 1900));
        coin[i].setScale(0.014, 0.014);
        if (i == 50) { coinPos2 = 0; }
        if (i == 41)       { coinn(375, 300, 0, i); }
        else if (i == 42)  { coinn(560, 302, 0, i); }
        else if (i == 43)  { coinn(738, 304, 0, i); }
        else if (i == 44)  { coinn(904, 305, 0, i); }
        else if (i > 44 && i <= 49) { coinn(240, 470, coinPos2, i); coinPos2 += 100; }
        else if (i > 49 && i <= 53) { coinn(1450, 177 - 50, coinPos2, i); coinPos2 += 220; }
        else if (i == 54)  { coinn(1630, 1263 + 3, 0, i); }
        else if (i == 55)  { coinn(1936 + 35, 1166 + 3, 0, i); }
        else if (i == 56)  { coinn(2251 + 35, 1092 + 3, 0, i); }
        else if (i == 57)  { coinn(2220 + 35, 944 + 3, 0, i); }
        else if (i == 58)  { coinn(1903, 933 + 3, 0, i); }
        else if (i == 59)  { coinn(1539, 877 + 3, 0, i); }
    }
}

void Game::poison(int x, int y, int i) {
    if (i == 8) { diff = 0; }
    p1[i].setPosition(x + diff, y);
    diff += 128;
}

void Game::move(int x, int y) {
    phase1.move(x, y);
    phase2.move(x, y);
    phase3.move(x, y);
    phase4.move(x, y);
    spider.move(x, y);
    for (int i = 0; i < 20; i++) {
        platform[i].move(x, y);
        platform1[i].move(x, y);
        platform2[i].move(x, y);
        platform3[i].move(x, y);
    }
    portalg1.move(x, y);
    portalg2.move(x, y);
    portalp1.move(x, y);
    for (int i = 0; i < 41; i++) { coin[i].move(x, y); }
    for (int i = 1; i < 28; i++) { spike[i].move(x, y); }
    for (int i = 0; i < 3; i++)  { brick[i].move(x, y); }
    archer.move(x, y);
    arrow.move(x, y);
    key.move(x, y);
    keyi.move(x, y);
    for (int i = 0; i < 2; i++) { potion[i].move(x, y); }
}

void Game::move2(int x, int y) {
    phase5.move(x, y);
    phase6.move(x, y);
    phase7.move(x, y);
    phase8.move(x, y);
    portalg3.move(x, y);
    portalp2.move(x, y);
    portalr1.move(x, y);
    portalr2.move(x, y);
    fireball1.move(x, y);
    fireball2.move(x, y);
    finalDoor.move(x, y);
    for (int i = 41; i < 60; i++) { coin[i].move(x, y); }
    wizard.move(x, y);
    for (int i = 0; i < 5; i++)  { fire[i].move(x, y); }
    for (int i = 20; i < 60; i++) {
        platform[i].move(x, y);
        platform1[i].move(x, y);
        platform2[i].move(x, y);
        platform3[i].move(x, y);
    }
    for (int i = 0; i < 5; i++)  { up2[i].move(x, y); }
    for (int i = 0; i < 15; i++) { p1[i].move(x, y); }
    for (int i = 0; i < 20; i++) { hidden[i].move(x, y); }
    for (int i = 0; i < 4; i++)  { box[i].move(x, y); }
}
