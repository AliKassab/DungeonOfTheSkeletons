// Level1.cpp -- see Level1.h.

#include "Level1.h"

void Level1::coinn(int x, int y, int co, int i) {
    coin[i].setPosition(x + co, y);
    coinPos += 40;
    coinbool[i] = 1;
}

void Level1::build(AssetManager& assets) {
    // backgrounds
    phase1.setTexture(assets.texture("phase1.png"));
    phase1.setTextureRect(IntRect(0, 0, 1280, 720)); phase1.setPosition(0, 0);
    phase2.setTexture(assets.texture("phase2.png"));
    phase2.setTextureRect(IntRect(0, 0, 1280, 720)); phase2.setPosition(1280, 0);
    phase3.setTexture(assets.texture("phase3.png"));
    phase3.setTextureRect(IntRect(0, 0, 1280, 720)); phase3.setPosition(0, 720);
    phase4.setTexture(assets.texture("phase4.png"));
    phase4.setTextureRect(IntRect(0, 0, 1280, 720)); phase4.setPosition(1280, 720);

    // platforms (collide-from-below, from-above, push-left, push-right)
    Tex& t0 = assets.texture("platform.png");
    for (int i = 0; i < 20; i++) { platform[i].setTextureRect(IntRect(0, 0, 88, 5)); platform[i].setTexture(t0); }
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

    Tex& t1 = assets.texture("platform1.png");
    for (int i = 0; i < 20; i++) { platform1[i].setTextureRect(IntRect(0, 0, 88, 5)); platform1[i].setTexture(t1); }
    platform1[0].setScale(11.1, 2);  platform1[0].setPosition(70, 275);
    platform1[1].setScale(12.4, 2);  platform1[1].setPosition(345, 443);
    platform1[2].setScale(1.3, 2);   platform1[2].setPosition(1520, 540);
    platform1[3].setScale(1.3, 2);   platform1[3].setPosition(1600, 375);
    platform1[4].setScale(1.3, 2);   platform1[4].setPosition(1825, 305);
    platform1[5].setScale(1.3, 2);   platform1[5].setPosition(2075, 260);
    platform1[6].setScale(1.7, 2);   platform1[6].setPosition(2343, 205);
    platform1[7].setScale(6.7, 2);   platform1[7].setPosition(1900, 420);
    platform1[8].setScale(9.4, 2);   platform1[8].setPosition(1260, 1010);
    platform1[9].setScale(10.4, 2);  platform1[9].setPosition(68, 1090);
    platform1[10].setScale(0.5, 2);  platform1[10].setPosition(1170, 1090);
    platform1[11].setScale(0.5, 2);  platform1[11].setPosition(1216, 80);
    platform1[12].setScale(0.5, 2);  platform1[12].setPosition(1216, 800);
    platform1[13].setScale(30, 1);   platform1[13].setPosition(0, 700);
    platform1[14].setScale(30, 1);   platform1[14].setPosition(0, 1400);
    platform1[15].setScale(1.3, 1);  platform1[15].setPosition(1340, 640);

    Tex& t2 = assets.texture("platform2.png");
    for (int i = 0; i < 20; i++) { platform2[i].setTextureRect(IntRect(0, 0, 88, 5)); platform2[i].setTexture(t2); }
    platform2[0].setScale(0.05, 5);  platform2[0].setPosition(1046.8, 264);
    platform2[1].setScale(0.05, 5);  platform2[1].setPosition(1436.2, 437);
    platform2[2].setScale(0.09, 5);  platform2[2].setPosition(1634.4, 530);
    platform2[3].setScale(0.05, 5);  platform2[3].setPosition(1714.4, 369);
    platform2[4].setScale(0.07, 5);  platform2[4].setPosition(1939.4, 285);
    platform2[5].setScale(0.07, 5);  platform2[5].setPosition(2189.4, 240);
    platform2[6].setScale(0.05, 5);  platform2[6].setPosition(3000, 185);
    platform2[7].setScale(0.05, 5);  platform2[7].setPosition(3000, 400);
    platform2[8].setScale(0.05, 5);  platform2[8].setPosition(2087.2, 990);
    platform2[9].setScale(0.05, 5);  platform2[9].setPosition(983.2, 1070);
    platform2[10].setScale(0.05, 5); platform2[10].setPosition(1214, 1070);
    platform2[11].setScale(0.05, 100);platform2[11].setPosition(1260, 60);
    platform2[12].setScale(0.05, 100);platform2[12].setPosition(1250, 780);
    platform2[13].setScale(0.05, 100);platform2[13].setPosition(2640, 680);
    platform2[14].setScale(0.05, 5); platform2[14].setPosition(2640, 1380);
    platform2[15].setScale(0.1, 9);  platform2[15].setPosition(1460, 600);

    Tex& t3 = assets.texture("platform3.png");
    for (int i = 0; i < 20; i++) { platform3[i].setTextureRect(IntRect(0, 0, 88, 5)); platform3[i].setTexture(t3); }
    platform3[0].setScale(0.05, 5);  platform3[0].setPosition(65, 265);
    platform3[1].setScale(0.05, 5);  platform3[1].setPosition(340, 433);
    platform3[2].setScale(0.09, 5);  platform3[2].setPosition(1515, 530);
    platform3[3].setScale(0.05, 5);  platform3[3].setPosition(1595, 365);
    platform3[4].setScale(0.05, 5);  platform3[4].setPosition(1820, 285);
    platform3[5].setScale(0.05, 5);  platform3[5].setPosition(2070, 240);
    platform3[6].setScale(0.05, 5);  platform3[6].setPosition(2340, 185);
    platform3[7].setScale(0.05, 5);  platform3[7].setPosition(1895, 410);
    platform3[8].setScale(0.05, 5);  platform3[8].setPosition(1258, 990);
    platform3[9].setScale(0.05, 5);  platform3[9].setPosition(65, 1070);
    platform3[10].setScale(0.05, 5); platform3[10].setPosition(1165, 1070);
    platform3[11].setScale(0.05, 100);platform3[11].setPosition(1216, 60);
    platform3[12].setScale(0.05, 100);platform3[12].setPosition(1216, 780);
    platform3[13].setScale(0.05, 2); platform3[13].setPosition(0, 680);
    platform3[14].setScale(0.05, 2); platform3[14].setPosition(0, 1380);
    platform3[15].setScale(0.1, 9);  platform3[15].setPosition(1330, 600);

    // coins
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

    // spikes
    int pos = 0;
    Tex& spikeTex = assets.texture("spike.png");
    for (int i = 1; i < 28; i++) {
        spike[i].setTextureRect(IntRect(0, 0, 556, 259));
        spike[i].setTexture(spikeTex);
        spike[i].setScale(0.1, 0.1);
    }
    for (int i = 4; i < 25; i++) { spike[i].setPosition(1290 + pos, 1350); pos += 59; }
    int space = 0;
    for (int i = 25; i < 28; i++) { spike[i].setPosition(300 + space, 652); space += 300; }
    spike[1].setPosition(2250, 385);
    spike[2].setPosition(1750, 961);
    spike[3].setPosition(1500, 961);

    // portals
    Tex& portalTex = assets.texture("portal.png");
    portalg1.setTexture(portalTex); portalg1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg1.setScale(0.2, 0.2); portalg1.setPosition(2500, 575);
    portalg2.setTexture(portalTex); portalg2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg2.setScale(0.2, 0.2); portalg2.setPosition(100, 1000); portalg2.rotate(180);
    Tex& portalPTex = assets.texture("portalp.png");
    portalp1.setTexture(portalPTex); portalp1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalp1.setScale(0.2, 0.2); portalp1.setPosition(2480, 950);

    // enemies / projectile
    archer.init(assets);
    arrow.setTexture(assets.texture("arrow1.png"));
    arrow.setPosition(1100, 1030);
    arrow.setTextureRect(IntRect(0, 0, 32, 12));
    arrow.rotate(180);
    spider.init(assets);

    // keys
    key.setTexture(assets.texture("key.png"));
    key.setPosition(2400, 120); key.setTextureRect(IntRect(0, 0, 318, 222)); key.setScale(0.13, 0.13);
    keyi.setTexture(assets.texture("key.png"));
    keyi.setPosition(63, 1333); keyi.setTextureRect(IntRect(0, 0, 318, 222)); keyi.setScale(0.13, 0.13);

    // moving bricks
    Tex& brickTex = assets.texture("up.png");
    for (int i = 0; i < 3; i++) {
        brick[i].setTexture(brickTex);
        brick[i].setTextureRect(IntRect(0, 0, 207, 74));
        brick[i].setScale(0.7, 0.7);
    }
    brick[0].setPosition(1380, 1285);
    brick[1].setPosition(2000, 1285);
    brick[2].setPosition(2150, 1310);

    // potions
    Tex& potionTex = assets.texture("heal.png");
    for (int i = 0; i < 2; i++) {
        potion[i].setTexture(potionTex);
        potion[i].setTextureRect(IntRect(0, 0, 40, 47));
        potionbool[i] = 1;
    }
    potion[0].setPosition(1100, 1345);
    potion[1].setPosition(2050, 251 + 690);
}

void Level1::scroll(int x, int y) {
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

void Level1::update(PlayContext& ctx) {
    Sprite& skeleton = ctx.player.sprite;
    int& jump = ctx.player.jump;
    bool& jumping = ctx.player.jumping;

    // animate this level's portals
    pr++;
    pr %= 100000;
    if (pr % 10 == 0) {
        cnterPr++;
        cnterPr %= 4;
        portalg1.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
        portalg2.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
        portalp1.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
    }

    spider.update();

    if (skeleton.getGlobalBounds().intersects(portalg1.getGlobalBounds()) && keyopen == true) {
        ctx.telep.play();
        skeleton.setPosition(150, 200);
        scroll(1300, -720);
    } else if (skeleton.getGlobalBounds().intersects(portalg2.getGlobalBounds())) {
        ctx.telep.play();
        skeleton.setPosition(1150, 600);
        scroll(-1300, 720);
    }
    if (skeleton.getGlobalBounds().intersects(portalp1.getGlobalBounds())) {
        ctx.telep.play();
        ctx.level = 2;
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
        if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) { scroll(-8, 0); }
        if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) { scroll(8, 0); }
    }

    if (skeleton.getGlobalBounds().intersects(key.getGlobalBounds()) && keyopen == false) {
        keyopen = true; ctx.eat.play();
    }
    if (skeleton.getGlobalBounds().intersects(keyi.getGlobalBounds()) && keyis == false) {
        keyis = true; ctx.eat.play();
    }
}

void Level1::render(PlayContext& ctx, Window& window) {
    Sprite& skeleton = ctx.player.sprite;
    int& HP = ctx.player.hp;
    int& damage = ctx.player.damage;

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
            potionbool[i] = 0; HP += 30; ctx.drink.play();
        } else if (skeleton.getGlobalBounds().intersects(potion[i].getGlobalBounds()) && HP > 70 && potionbool[i] == 1) {
            potionbool[i] = 0; ctx.drink.play(); HP = 100;
        }
    }

    for (int i = 1; i < 28; i++) {
        if (i == 4 || i == 24) { continue; }
        if (skeleton.getGlobalBounds().intersects(spike[i].getGlobalBounds())) { HP -= 1; }
        window.draw(spike[i]);
    }

    for (int i = 0; i < 41; i++) {
        if (skeleton.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && coinbool[i] == 1) {
            coinbool[i] = 0; ctx.eat.play(); ctx.score += 10;
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
        HP -= 30; damage = 1; ctx.spiderS.play();
    } else if (skeleton.getGlobalBounds().intersects(arrow.getGlobalBounds()) && damage == 1) {
        damage = 1;
    } else if (skeleton.getGlobalBounds().intersects(spider.getGlobalBounds()) && damage == 1) {
        damage = 1;
    } else {
        damage = 0;
    }
}
