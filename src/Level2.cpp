// Level2.cpp -- see Level2.h.

#include "Level2.h"

void Level2::coinn(int x, int y, int co, int i) {
    coin[i].setPosition(x + co, y);
    coinbool[i] = 1;
    coinPos2 += 40;
}

void Level2::poison(int x, int y, int i) {
    if (i == 8) { diff = 0; }
    p1[i].setPosition(x + diff, y);
    diff += 128;
}

void Level2::build(AssetManager& assets) {
    // backgrounds
    phase5.setTexture(assets.texture("phase5.png"));
    phase5.setTextureRect(IntRect(0, 0, 1280, 720)); phase5.setPosition(0, 0);
    phase6.setTexture(assets.texture("phase6.png"));
    phase6.setTextureRect(IntRect(0, 0, 1280, 720)); phase6.setPosition(1280, 0);
    phase7.setTexture(assets.texture("phase7.png"));
    phase7.setTextureRect(IntRect(0, 0, 1280, 720)); phase7.setPosition(0, 720);
    phase8.setTexture(assets.texture("phase8.png"));
    phase8.setTextureRect(IntRect(0, 0, 1280, 720)); phase8.setPosition(1280, 720);

    Tex& t0 = assets.texture("platform.png");
    for (int i = 0; i < 60; i++) { platform[i].setTextureRect(IntRect(0, 0, 88, 5)); platform[i].setTexture(t0); }
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

    // coins (41..59)
    Tex& coinTex = assets.texture("coin.png");
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

    // portals
    Tex& portalTex = assets.texture("portal.png");
    portalg3.setTexture(portalTex); portalg3.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalg3.setScale(0.2, 0.2); portalg3.setPosition(2500, 130);
    Tex& portalPTex = assets.texture("portalp.png");
    portalp2.setTexture(portalPTex); portalp2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalp2.setScale(0.2, 0.2); portalp2.setPosition(100, 250); portalp2.rotate(180);
    Tex& portalRTex = assets.texture("portalr.png");
    portalr1.setTexture(portalRTex); portalr1.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalr1.setScale(0.2, 0.2); portalr1.setPosition(2500, 590);
    portalr2.setTexture(portalRTex); portalr2.setTextureRect(IntRect(0, 0, 297.5, 570));
    portalr2.setScale(-0.2, 0.2); portalr2.setPosition(1405, 100); portalr2.rotate(90);

    // enemies / projectiles
    wizard.init(assets);
    fireball1.setTexture(assets.texture("fireball.png"));
    fireball1.setPosition(1100, 200); fireball1.setTextureRect(IntRect(0, 0, 164, 84));
    fireball1.rotate(180); fireball1.setScale(0.4, 0.4);
    fireball2.setTexture(assets.texture("fireball.png"));
    fireball2.setPosition(80, 300); fireball2.setTextureRect(IntRect(0, 0, 164, 84));
    fireball2.setScale(0.4, 0.4);

    finalDoor.setTexture(assets.texture("final.png"));
    finalDoor.setPosition(1300, 850); finalDoor.setTextureRect(IntRect(0, 0, 28, 48));

    Tex& fireTex = assets.texture("fireb.png");
    for (int i = 0; i < 3; i++) {
        fire[i].setTexture(fireTex);
        fire[i].setTextureRect(IntRect(0, 0, 74, 121));
    }
    fire[0].setPosition(1455, 510);
    fire[1].setPosition(1865, 510);
    fire[2].setPosition(2195, 510);

    Tex& up2Tex = assets.texture("up2.png");
    for (int i = 0; i < 5; i++) {
        up2[i].setTexture(up2Tex);
        up2[i].setTextureRect(IntRect(0, 0, 207, 74));
        up2[i].setScale(0.7, 0.7);
    }
    up2[0].setPosition(1448, 485);
    up2[1].setPosition(1850, 485);
    up2[2].setPosition(2180, 485);

    // poison
    Tex& p1Tex = assets.texture("p1.png");
    for (int i = 0; i < 15; i++) {
        p1[i].setTexture(p1Tex);
        p1[i].setScale(1, 1);
        p1[i].setTextureRect(IntRect(0, 0, 128, 50));
        if (i < 8) { poison(62, 1000, i); }
        else { poison(320, 1150, i); }
    }

    // hidden collapsing tiles
    Tex& hiddenTex = assets.texture("hidden.png");
    for (int i = 0; i < 20; i++) {
        hidden[i].setTexture(hiddenTex);
        hidden[i].setTextureRect(IntRect(0, 0, 206.25, 30));
        hidden[i].setScale(1, 0.7);
    }
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

    // falling boxes
    Tex& boxTex = assets.texture("box.png");
    for (int i = 0; i < 4; i++) {
        box[i].setTexture(boxTex);
        box[i].setTextureRect(IntRect(0, 0, 32, 32));
    }
    box[0].setPosition(154 + 1280, 60 + 720);
    box[1].setPosition(262 + 1280, 229 + 720);
    box[2].setPosition(624 + 1280, 298 + 720);
    box[3].setPosition(710 + 1280, 60 + 720);
}

void Level2::scroll(int x, int y) {
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

void Level2::update(PlayContext& ctx) {
    Sprite& skeleton = ctx.player.sprite;
    int& jump = ctx.player.jump;
    bool& jumping = ctx.player.jumping;
    int& HP = ctx.player.hp;

    // animate this level's portals
    pr++;
    pr %= 100000;
    if (pr % 10 == 0) {
        cnterPr++;
        cnterPr %= 4;
        portalg3.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
        portalp2.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
        portalr1.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
        portalr2.setTextureRect(IntRect(cnterPr * 297.5, 0, 297.5, 570));
    }

    for (int i = 21; i < 60; i++) {
        if ((skeleton.getGlobalBounds().intersects(platform[i].getGlobalBounds()))) {
            skeleton.move(0, -8); jumping = true; jump = 51;
        }
        if ((skeleton.getGlobalBounds().intersects(platform1[i].getGlobalBounds()))) {
            jump = 51; skeleton.move(0, 8);
        }
        if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) { scroll(-8, 0); }
        if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) { scroll(8, 0); }
        if (skeleton.getGlobalBounds().intersects(portalp2.getGlobalBounds())) {
            ctx.telep.play(); ctx.level = 1; skeleton.setPosition(1150, 150);
        }
        if (skeleton.getGlobalBounds().intersects(portalr1.getGlobalBounds())) {
            ctx.telep.play(); skeleton.setPosition(30, 100);
        }
    }
    fp++;
    if (fp % 3 == 0) {
        cntfp++;
        cntfp %= 61;
        for (int i = 0; i < 5; i++) { fire[i].setTextureRect(IntRect(cntfp * 74, 0, 74, 121)); }
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
        hidden[i].setTextureRect(IntRect(hiddenarr[i] * 206.25, 0, 206.25, 30));
    }

    if (skeleton.getGlobalBounds().intersects(portalg3.getGlobalBounds())) {
        ctx.telep.play(); skeleton.setPosition(70, 100); scroll(1320, -720);
    }

    pr1++;
    if (pr1 % 7 == 0 && ctx.ending == false) {
        cnterPr1++;
        cnterPr1 %= 5;
        for (int i = 0; i < 15; i++) { p1[i].setTextureRect(IntRect(cnterPr1 * 128, 0, 128, 50)); }
    }

    for (int i = 0; i < 4; i++) {
        if (skeleton.getPosition().x > box[i].getPosition().x - 25 && skeleton.getPosition().y > box[i].getPosition().y) {
            boxtrap[i] = true;
        }
        if (boxtrap[i] == true) { box[i].move(0, 10); }
        if (skeleton.getGlobalBounds().intersects(box[i].getGlobalBounds())) { HP -= 1; }
    }

    if (skeleton.getGlobalBounds().intersects(finalDoor.getGlobalBounds()) && ctx.ending == false) {
        ctx.ending = true;
    }

    if (ctx.ending == true) {
        ctx.assets.reload("skeleton.png", "ameer.png");
        skeleton.setTextureRect(IntRect(0, 0, 64, 80));
        skeleton.setScale(-0.8, 1);
        ctx.ost.stop();
    }
}

void Level2::render(PlayContext& ctx, Window& window) {
    Sprite& skeleton = ctx.player.sprite;
    int& HP = ctx.player.hp;
    int& damage = ctx.player.damage;

    // fireballs are spawned/aimed from the wizard's cast frame
    int firePosX = phase5.getPosition().x;
    int firePosY = phase5.getPosition().y;
    if (wizard.getFrame() == 5) {
        fireball1.setPosition(1240 + firePosX, 270 + firePosY);
        fireball2.setPosition(50 + firePosX, 410 + firePosY);
    }
    fireball1.move(-30, 0);
    fireball2.move(30, 0);

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
        ctx.fireBall.play();
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
            coinbool[i] = 0; ctx.eat.play(); ctx.score += 10;
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
    if (ctx.ending == false) { window.draw(finalDoor); }
}

void Level2::drawOverlay(Window& window) {
    for (int i = 0; i < 15; i++) { window.draw(p1[i]); }
    for (int i = 0; i < 4; i++) { window.draw(box[i]); }
}
