#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<fstream>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1280, 720), "Dungeon of the skeletons");

Texture Archer;
Texture Spider;
Sprite spider(Spider);
Sprite archer(Archer);
Texture Arrow;
Sprite arrow(Arrow);
Texture Skeleton;
Sprite skeleton(Skeleton);
Texture Phase1;
Sprite phase1(Phase1);
Texture Phase2;
Sprite phase2(Phase2);
Texture Phase3;
Sprite phase3(Phase3);
Texture Phase4;
Sprite phase4(Phase4);
Texture Phase5;
Sprite phase5(Phase5);
Texture Phase6;
Sprite phase6(Phase6);
Texture Phase7;
Sprite phase7(Phase7);
Texture Phase8;
Sprite phase8(Phase8);
Texture Coin;
Sprite coin[60];
bool coinbool[60] = {};
int coinPos = 0;
int coinPos2 = 0;
Texture Platform;
Sprite platform[60];
Texture Platform1;
Sprite platform1[60];
Texture Platform2;
Sprite platform2[60];
Texture Platform3;
Sprite platform3[60];
Texture Spike;
Sprite spike[28];
Texture PortalG1;
Sprite portalg1(PortalG1);
Texture PortalG2;
Sprite portalg2(PortalG2);
Texture PortalG3;
Sprite portalg3(PortalG3);
Texture PortalG4;
Sprite portalg4(PortalG4);
Texture PortalP1;
Sprite portalp1(PortalP1);
Texture PortalP2;
Sprite portalp2(PortalP2);
Texture PortalR1;
Sprite portalr1(PortalR1);
Texture PortalR2;
Sprite portalr2(PortalR2);
Texture Brick;
Sprite brick[3];
Texture Key;
Sprite key(Key);
Texture Potion;
Sprite potion[2];
Texture Fire;
Sprite fire[5];
Texture Up2;
Sprite up2[5];
Texture Wizard;
Sprite wizard[2];
Texture Keyi;
Sprite keyi(Keyi);
Texture Fireball1;
Texture Fireball2;
Sprite fireball1(Fireball1);
Sprite fireball2(Fireball2);
Texture P1;
Sprite p1[15];
Texture Hidden;
Sprite hidden[20];
Texture Box;
Sprite box[4];
Texture Final;
Sprite final(Final);
Texture Ameer;
Sprite ameer(Ameer);


int pr1 = 1;
int cnterPr1 = 0;
int diff = 0;
bool potionbool[2] = {};
int pr = 0, cnterPr = 0;
int bricks = 0;
int brickUp = 0;
int level = 1;
bool ending = false;


void coinn(int x, int y, int co, int i);

void poison(int x, int y, int i);

void level1Phase();

void level2Phase();

void Platforms();

void Coins();

void move(int x, int y);

void move2(int x, int y);


int main() {
	//render window 

	window.setFramerateLimit(30);
	window.setMouseCursorVisible(false); // Hide cursor
	View fixed = window.getView(); // Create a fixed view

	Texture Cursorr;
	Cursorr.loadFromFile("cur.png");
	Sprite cursor(Cursorr);


	//menu start

	Texture Black;
	Black.loadFromFile("Black.png");
	Sprite black(Black);
	black.setScale(0.75, 0.65);

	Texture Red;
	Red.loadFromFile("Red.png");
	Sprite red(Red);
	red.setScale(0.75, 0.65);

	Text mainmenu;
	Font MainMenu;
	MainMenu.loadFromFile("OpenSans-Italic.ttf");
	mainmenu.setFont(MainMenu);
	mainmenu.setFillColor(Color::Red);
	mainmenu.setString("Main Menu");
	mainmenu.setPosition(530, 200);
	mainmenu.setScale(1.5, 1.5);

	Text start;
	Font Start;
	Start.loadFromFile("OpenSans-Italic.ttf");
	start.setFont(Start);
	start.setFillColor(Color::Red);
	start.setString("Start");
	start.setPosition(600, 300);
	start.setScale(1, 1);

	Text about;
	Font About;
	About.loadFromFile("OpenSans-Italic.ttf");
	about.setFont(About);
	about.setFillColor(Color::Red);
	about.setString("Controls");
	about.setPosition(595, 360);
	about.setScale(1, 1);

	Text exit;
	Font Exit;
	Exit.loadFromFile("OpenSans-Italic.ttf");
	exit.setFont(Exit);
	exit.setFillColor(Color::Red);
	exit.setString("Exit");
	exit.setCharacterSize(25);
	exit.setPosition(607, 420);
	exit.setScale(1.2, 1.2);

	Text info;
	Font Info;
	Info.loadFromFile("OpenSans-Italic.ttf");
	info.setFont(Info);
	info.setFillColor(Color::Red);
	info.setString("Use 'Left' and 'Right' to move\nPress 'Down' to crouch\nPress 'Up' to Jump\n\n\nBack");
	info.setPosition(500, 200);
	info.setScale(1, 1);

	//menu done


	//player start	
	Skeleton.loadFromFile("Skeleton.png");
	skeleton.setTextureRect(IntRect(0, 0, 16, 27));
	skeleton.setScale(2.5, 2.5);
	skeleton.setPosition(100, 200);   // 100 , 250 
	int cnterX = 0, cnterY = 0;

	//player done

	level1Phase();

	level2Phase();

	Platforms();

	Coins();


	//******************content *************************************** start**************

	Box.loadFromFile("box.png");

	for (int i = 0; i < 4; i++) {
		box[i].setTexture(Box);
		box[i].setTextureRect(IntRect(0, 0, 32, 32));
		box[i].setScale(1, 1);

	}
	box[0].setPosition(154 + 1280, 60 + 720);
	box[1].setPosition(262 + 1280, 229 + 720);
	box[2].setPosition(624 + 1280, 298 + 720);
	box[3].setPosition(710 + 1280, 60 + 720);

	Archer.loadFromFile("archer.png");
	archer.setTextureRect(IntRect(0, 0, 72, 76));
	archer.setScale(-1, 1);
	archer.setPosition(1200, 1000);
	int sp = 1; int cntsp = 0;

	Arrow.loadFromFile("arrow1.png");
	arrow.setPosition(1100, 1030);
	arrow.setTextureRect(IntRect(0, 0, 32, 12));
	arrow.rotate(180);

	Fireball1.loadFromFile("fireball.png");
	fireball1.setPosition(1100, 200);
	fireball1.setTextureRect(IntRect(0, 0, 164, 84));
	fireball1.rotate(180);
	fireball1.setScale(0.4, 0.4);

	Fireball2.loadFromFile("fireball.png");
	fireball2.setPosition(80, 300);
	fireball2.setTextureRect(IntRect(0, 0, 164, 84));
	fireball2.setScale(0.4, 0.4);

	Final.loadFromFile("final.png");
	final.setPosition(1300, 850);
	final.setTextureRect(IntRect(0, 0, 28, 48));
	final.setScale(1, 1);


	Hidden.loadFromFile("hidden.png");
	for (int i = 0; i < 20; i++) {
		hidden[i].setTexture(Hidden);
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
	int hiddenarr[20] = { 0 };
	int Cnthiddenarr[20] = { 0 };
	int hiddenX = 0;
	int Cnthidden = 0;


	P1.loadFromFile("p1.png");
	for (int i = 0; i < 15; i++) {
		p1[i].setTexture(P1);
		p1[i].setScale(1, 1);
		p1[i].setTextureRect(IntRect(0, 0, 128, 50));
		if (i < 8) {
			poison(62, 1000, i);
		}
		else {
			poison(320, 1150, i);
		}
	}


	Potion.loadFromFile("heal.png");
	for (int i = 0; i < 2; i++) {
		potion[i].setTexture(Potion);
		potion[i].setTextureRect(IntRect(0, 0, 40, 47));
		potion[0].setPosition(1100, 1345);
		potion[1].setPosition(2050, 251 + 690);
		potionbool[i] = 1;
	}



	Key.loadFromFile("key.png");
	key.setPosition(2400, 120);
	key.setTextureRect(IntRect(0, 0, 318, 222));
	key.setScale(0.13, 0.13);
	Keyi.loadFromFile("key.png");
	keyi.setPosition(63, 1333);
	bool keyis = false;
	keyi.setTextureRect(IntRect(0, 0, 318, 222));
	keyi.setScale(0.13, 0.13);



	int pos = 0;
	Spike.loadFromFile("spike.png");
	for (int i = 1; i < 28; i++) {
		spike[i].setTextureRect(IntRect(0, 0, 556, 259));
		spike[i].setTexture(Spike);
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

	// portal 
	PortalG1.loadFromFile("portal.png");
	portalg1.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalg1.setScale(0.2, 0.2);
	portalg1.setPosition(2500, 575);

	PortalG2.loadFromFile("portal.png");
	portalg2.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalg2.setScale(0.2, 0.2);
	portalg2.setPosition(100, 1000);
	portalg2.rotate(180);

	PortalG3.loadFromFile("portal.png");
	portalg3.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalg3.setScale(0.2, 0.2);
	portalg3.setPosition(2500, 130);

	PortalG4.loadFromFile("portal.png");
	portalg4.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalg4.setScale(0.2, 0.2);
	portalg4.setPosition(100, 1000);
	portalg4.rotate(180);

	PortalP1.loadFromFile("portalp.png");
	portalp1.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalp1.setScale(0.2, 0.2);
	portalp1.setPosition(2480, 950);


	PortalP2.loadFromFile("portalp.png");
	portalp2.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalp2.setScale(0.2, 0.2);
	portalp2.setPosition(100, 250);
	portalp2.rotate(180);

	PortalR1.loadFromFile("portalr.png");
	portalr1.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalr1.setScale(0.2, 0.2);
	portalr1.setPosition(2500, 590);

	PortalR2.loadFromFile("portalr.png");
	portalr2.setTextureRect(IntRect(0, 0, 297.5, 570));
	portalr2.setScale(-0.2, 0.2);
	portalr2.setPosition(1405, 100);
	portalr2.rotate(90);

	Brick.loadFromFile("up.png");
	for (int i = 0; i < 3; i++) {
		brick[i].setTexture(Brick);
		brick[i].setTextureRect(IntRect(0, 0, 207, 74));
		brick[i].setScale(0.7, 0.7);
		brick[0].setPosition(1380, 1285);
		brick[1].setPosition(2000, 1285);
		brick[2].setPosition(2150, 1310);
	}



	//story*************************

	Texture S1;
	S1.loadFromFile("story1.jpg");
	Sprite s1(S1);

	Texture S2;
	S2.loadFromFile("story2.jpg");
	Sprite s2(S2);

	Texture S3;
	S3.loadFromFile("story3.jpg");
	Sprite s3(S3);

	Texture S4;
	S4.loadFromFile("story4.jpg");
	Sprite s4(S4);

	Texture S5;
	S5.loadFromFile("story5.jpg");
	Sprite s5(S5);

	Texture S6;
	S6.loadFromFile("story6.jpg");
	Sprite s6(S6);

	Texture S7;
	S7.loadFromFile("story7.jpg");
	Sprite s7(S7);

	Texture S8;
	S8.loadFromFile("story8.jpg");
	Sprite s8(S8);

	Texture S9;
	S9.loadFromFile("story1a.jpg");
	Sprite s9(S9);

	Texture S10;
	S10.loadFromFile("story2b.jpg");
	Sprite s10(S10);

	Texture S11;
	S11.loadFromFile("story3c.jpg");
	Sprite s11(S11);

	Texture S12;
	S12.loadFromFile("story4d.jpg");
	Sprite s12(S12);

	Texture S13;
	S13.loadFromFile("story2.1.jpg");
	Sprite s13(S13);

	Texture S14;
	S14.loadFromFile("story2.2.jpg");
	Sprite s14(S14);

	Texture S15;
	S15.loadFromFile("story2.3.jpg");
	Sprite s15(S15);

	Texture S16;
	S16.loadFromFile("story2.4.jpg");
	Sprite s16(S16);

	Texture S17;
	S17.loadFromFile("story2.5.jpg");
	Sprite s17(S17);

	Texture S18;
	S18.loadFromFile("story2.6.jpg");
	Sprite s18(S18);

	Texture S19;
	S19.loadFromFile("story2.7.jpg");
	Sprite s19(S19);

	Texture S20;
	S20.loadFromFile("story3.1.jpg");
	Sprite s20(S20);

	Texture S21;
	S21.loadFromFile("story3.2.jpg");
	Sprite s21(S21);

	Texture S22;
	S22.loadFromFile("story3.3.jpg");
	Sprite s22(S22);

	Texture S23;
	S23.loadFromFile("story3.4.jpg");
	Sprite s23(S23);

	Texture S24;
	S24.loadFromFile("story3.5.jpg");
	Sprite s24(S24);

	Texture S25;
	S25.loadFromFile("story3.6.jpg");
	Sprite s25(S25);

	Texture S26;
	S26.loadFromFile("story3.7.jpg");
	Sprite s26(S26);

	Texture S27;
	S27.loadFromFile("story3.8.jpg");
	Sprite s27(S27);

	Texture S28;
	S28.loadFromFile("story3.9.jpg");
	Sprite s28(S28);


	int story = 0;
	int storyStart = 0;

	//story end*******************************************

	Spider.loadFromFile("spider.png");
	spider.setTextureRect(IntRect(0, 0, 98.66666666666667, 87));
	spider.setPosition(62, 1330);
	spider.setScale(1, 1);
	int spiderX = 0;
	int spiderY = 0;
	int spidy = 0;

	Text MyScore;
	MyScore.setFont(MainMenu);
	MyScore.setFillColor(Color::Red);
	MyScore.setString("Score :");
	MyScore.setPosition(10, 5);
	MyScore.setScale(0.7, 0.7);

	Text Myscore;
	Myscore.setFont(MainMenu);
	Myscore.setFillColor(Color::Red);
	Myscore.setPosition(80, 5);
	Myscore.setScale(0.7, 0.7);

	Text _score;
	_score.setFont(MainMenu);
	_score.setFillColor(Color::Red);
	_score.setStyle(Text::Regular);
	_score.setCharacterSize(25);
	_score.setPosition(250, 5);
	_score.setScale(0.9, 0.9);

	Text Highscore;
	Highscore.setFont(MainMenu);
	Highscore.setFillColor(Color::Red);
	Highscore.setStyle(Text::Regular);
	Highscore.setString("Highscore :");
	Highscore.setCharacterSize(25);
	Highscore.setPosition(130, 5);
	Highscore.setScale(0.9, 0.9);

	//content done


	//audio***********************************************************

	SoundBuffer Eat;
	Eat.loadFromFile("coineat.wav");
	Sound eat;
	eat.setBuffer(Eat);
	eat.setVolume(5);

	SoundBuffer Ost;
	Ost.loadFromFile("Medieval_Music_-_Haunted_Ferryman.wav");
	Sound ost;
	ost.setBuffer(Ost);
	ost.setVolume(50);

	SoundBuffer Telep;
	Telep.loadFromFile("TELEP.wav");
	Sound telep;
	telep.setBuffer(Telep);
	telep.setVolume(50);

	SoundBuffer FireBall;
	FireBall.loadFromFile("fireball.wav");
	Sound fireBall;
	fireBall.setBuffer(FireBall);
	fireBall.setVolume(70);

	SoundBuffer Drink;
	Drink.loadFromFile("drink.wav");
	Sound drink;
	drink.setBuffer(Drink);
	drink.setVolume(100);

	SoundBuffer SpiderS;
	SpiderS.loadFromFile("spider.wav");
	Sound spiderS;
	spiderS.setBuffer(SpiderS);
	spiderS.setVolume(100);

	SoundBuffer Voice1;
	Voice1.loadFromFile("First.wav");
	Sound voice1;
	voice1.setBuffer(Voice1);
	voice1.setVolume(100);

	SoundBuffer Voice2;
	Voice2.loadFromFile("Second_1.wav");
	Sound voice2;
	voice2.setBuffer(Voice2);
	voice2.setVolume(100);

	SoundBuffer Voice3;
	Voice3.loadFromFile("Third.wav");
	Sound voice3;
	voice3.setBuffer(Voice3);
	voice3.setVolume(100);

	SoundBuffer Back1;
	Back1.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme.wav");
	Sound back1;
	back1.setBuffer(Back1);
	back1.setVolume(100);

	SoundBuffer Back2;
	Back2.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_1.wav");
	Sound back2;
	back2.setBuffer(Back2);
	back2.setVolume(100);

	SoundBuffer Back3;
	Back3.loadFromFile("yt1s.com_-_Kingdom_Hearts_OST_Menu_Theme_2.wav");
	Sound back3;
	back3.setBuffer(Back3);
	back3.setVolume(100);

	SoundBuffer MainMenu11;
	MainMenu11.loadFromFile("game.wav");
	Sound mainMenu11;
	mainMenu11.setBuffer(MainMenu11);
	mainMenu11.setVolume(80);

	SoundBuffer LOST;
	LOST.loadFromFile("lost.wav");
	Sound lost;
	lost.setBuffer(LOST);
	lost.setVolume(50);



	//audio done********************************************************

	Texture Heart;
	Heart.loadFromFile("heart.png");
	Sprite heart(Heart);
	heart.setPosition(1050, 10);
	heart.setScale(0.2, 0.2);

	Texture Frame;
	Frame.loadFromFile("frame.png");
	Sprite frame(Frame);
	frame.setPosition(1060, 10);
	frame.setScale(1.03, 0.3);

	Texture Bar;
	Bar.loadFromFile("bar.png");
	Sprite bar(Bar);
	bar.setPosition(1060, 16);
	bar.setScale(100, 0.3);
	bar.setColor(Color::Red);

	Texture LOSE;
	LOSE.loadFromFile("lose.png");
	Sprite lose(LOSE);
	lose.setPosition(400, 150);
	lose.setScale(1, 1);

	Texture WIN;
	WIN.loadFromFile("cong.png");
	Sprite win(WIN);
	win.setPosition(100, -50);
	win.setScale(1, 1);


	Fire.loadFromFile("fireb.png");
	for (int i = 0; i < 3; i++) {
		fire[i].setTexture(Fire);
		fire[i].setTextureRect(IntRect(0, 0, 74, 121));
		fire[0].setPosition(1455, 510);
		fire[1].setPosition(1865, 510);
		fire[2].setPosition(2195, 510);
	}


	Up2.loadFromFile("up2.png");
	for (int i = 0; i < 5; i++) {
		up2[i].setTexture(Up2);
		up2[i].setTextureRect(IntRect(0, 0, 207, 74));
		up2[0].setPosition(1448, 485);
		up2[1].setPosition(1850, 485);
		up2[2].setPosition(2180, 485);
		up2[i].setScale(0.7, 0.7);
	}


	Wizard.loadFromFile("wiz.png");
	for (int i = 0; i < 2; i++) {
		wizard[i].setTexture(Wizard);
		wizard[i].setTextureRect(IntRect(0, 0, 32, 64));
		wizard[0].setPosition(1240, 150);
		wizard[1].setPosition(50, 320);
		wizard[i].setScale(3, 3);
	}
	wizard[0].setScale(-3, 3);
	int wp = 1;
	int cntw = 0;



	int fp = 1;
	int cntfp = 0;
	float fireY = 70;
	int fireScale = 0;
	bool keyopen = false;


	int score = 0;
	int highscore;
	int Cntmainmenubg = 0;
	int Cntgame = 0;
	int jump = 50;
	bool jumping = false;
	int HP = 100;
	int arrowCnt = 0;
	int arrowPosX = 0;
	int arrowPosY = 0;
	int firePosX = 0;
	int firePosY = 0;
	int damage = 0;
	bool boxtrap[4] = {};
	int scene = 1;
	int sec = 0;
	bool die = false;

	if (storyStart == 0) {
		mainMenu11.play();
		mainMenu11.setLoop(true);
	}


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::MouseButtonPressed:
				cout << "Button " << event.mouseButton.button << " @ "
					<< sf::Mouse::getPosition(window).x << ", "
					<< sf::Mouse::getPosition(window).y << "\n";
				break;
			}

			if (event.type == Event::Closed) {
				window.close();
				break;
			}


			if (event.type == Event::KeyReleased && event.key.code == Keyboard::Down && jump >= 50 && ending == false && die == false) {
				if (cnterX == 0) {
					cnterY = 0;
				}
				else if (cnterX == 1) {
					cnterX = 3;
					cnterY = 1;
				}
				skeleton.move(0, -25);
			}
			;
			//menu buttons start
			if (Mouse::isButtonPressed(Mouse::Left) && Cntgame == 0)
			{
				Vector2i mousePos = Mouse::getPosition(window);

				if (mousePos.x > 607 && mousePos.x < 660 && mousePos.y > 425 && mousePos.y < 450) {
					window.close();
				}

				else if (mousePos.x > 600 && mousePos.x < 675 && mousePos.y > 300 && mousePos.y < 340) {
					storyStart = 1;
					mainMenu11.stop();
				}

				else if (mousePos.x > 595 && mousePos.x < 685 && mousePos.y > 365 && mousePos.y < 392) {
					Cntgame = 2;
				}

			}
			//menu buttons done

			//player move start




			if (Keyboard::isKeyPressed(Keyboard::Key::Down) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {

				if (cnterY == 0) {
					cnterY = 2;
					cnterX = 0;
				}
				else if (cnterY == 1) {
					cnterY = 2;
					cnterX = 1;
				}
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
			cnterY = 0;
			cnterX++;
			if (level == 1) {
				if (phase2.getPosition().x < 0) {
					skeleton.move(8, 0);
				}
				else {
					move(-8, 0);
				}
			}
			if (level == 2) {
				if (phase6.getPosition().x < 0) {
					skeleton.move(8, 0);
				}
				else {
					move2(-8, 0);
				}
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && jump >= 50 && Cntgame == 1 && ending == false && die == false) {
			if (level == 1) {
				if (phase1.getPosition().x > 0) {
					skeleton.move(-8, 0);
				}
				else {
					move(8, 0);
				}
			}

			if (level == 2) {
				if (phase5.getPosition().x > 0) {
					skeleton.move(-8, 0);
				}
				else {
					move2(8, 0);
				}
			}
			cnterY = 1;
			cnterX++;

		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Up) && jump >= 50 && Cntgame == 1 && jumping == true && ending == false && die == false) {
			jump = 0;
			jumping = false;
			if (cnterY == 0) {
				cnterX = 2;
			}
			else if (cnterY == 1) {
				cnterX = 1;
			}

		}

		cnterX %= 4;
		skeleton.setTextureRect(IntRect(cnterX * 16, cnterY * 27, 16, 27));

		if (cnterY == 2) {
			skeleton.setTextureRect(IntRect(cnterX * 16, cnterY * 30, 16, 21));
		}

		bar.setScale(HP, 0.3);

		jump++;

		if (jump < 50)
		{
			skeleton.move(0, -8);
			skeleton.move(0, (jump - 25) / 2.7);
			if (Keyboard::isKeyPressed(Keyboard::Key::Right) && ending == false && die == false) {
				cnterY = 0;
				cnterX = 2;
				if (level == 1) {
					if (phase2.getPosition().x < 0) {
						skeleton.move(5, 0);
					}
					else {
						move(-5, 0);
					}
				}
				if (level == 2) {
					if (phase6.getPosition().x < 0) {
						skeleton.move(5, 0);
					}
					else {
						move2(-5, 0);
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Left) && ending == false && die == false) {
				if (level == 1) {
					if (phase1.getPosition().x > 0) {
						skeleton.move(-5, 0);
					}
					else {
						move(5, 0);
					}
				}

				if (level == 2) {
					if (phase5.getPosition().x > 0) {
						skeleton.move(-5, 0);
					}
					else {
						move2(5, 0);
					}
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

		if (skeleton.getPosition().x < 60) {
			skeleton.move(8, 0);
		}
		if (skeleton.getPosition().x > 1190) {
			skeleton.move(-8, 0);
		}


		if (level == 1 && die == false) {
			spidy++;
			if (spidy <= 170) {
				spider.move(5, 0);
				spiderX++;
				spiderY = 1;

			}
			else {
				spider.move(-5, 0);
				spiderX++;
				spiderY = 0;
			}
			if (spidy > 340) {
				spidy = 0;
			}
			spiderX %= 3;
			spider.setTextureRect(IntRect(spiderX * 98.66666666666667, spiderY * 87, 98.66666666666667, 87));

			if (skeleton.getGlobalBounds().intersects(portalg1.getGlobalBounds()) && keyopen == true) {
				telep.play();
				skeleton.setPosition(150, 200);
				move(1300, -720);
			}
			else if (skeleton.getGlobalBounds().intersects(portalg2.getGlobalBounds())) {
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
			if (bricks <= 70) {
				brick[0].move(3, 0);
				brick[1].move(-3, 0);
			}
			else if (bricks > 70 && bricks <= 140) {
				brick[0].move(-3, 0);
				brick[1].move(3, 0);
			}
			else {
				bricks = 0;
			}

			brickUp++;
			if (brickUp <= 100) {
				brick[2].move(0, -4);
			}
			else if (brickUp > 100 && brickUp <= 200) {
				brick[2].move(0, 4);
			}
			else {
				brickUp = 0;
			}

			if (skeleton.getGlobalBounds().intersects(brick[0].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[0].getPosition().y) {
				skeleton.move(0, -8);
				jumping = true;
				if (bricks <= 70) {
					skeleton.move(3, 0);
				}
				else {
					skeleton.move(-3, 0);
				}
			}
			if (skeleton.getGlobalBounds().intersects(brick[1].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[1].getPosition().y) {
				skeleton.move(0, -8);
				jumping = true;
				if (bricks <= 70) {
					skeleton.move(-3, 0);
				}
				else {
					skeleton.move(3, 0);
				}
			}
			if (skeleton.getGlobalBounds().intersects(brick[2].getGlobalBounds()) && keyis == true && skeleton.getPosition().y + (27 * 2.5) > brick[2].getPosition().y) {
				jumping = true;
				if (brickUp <= 100) {
					skeleton.move(0, -12);
				}
				else {
					skeleton.move(0, -8);
				}

			}


			sp++;
			if (sp % 7 == 0) {
				cntsp++;
				cntsp %= 9;
				archer.setTextureRect(IntRect(cntsp * 72, cntsp * 0, 72, 76));

			}

			for (int i = 0; i < 20; i++) {
				if ((skeleton.getGlobalBounds().intersects(platform[i].getGlobalBounds()))) {
					skeleton.move(0, -8);
					jumping = true;
					jump = 51;
				}
				if ((skeleton.getGlobalBounds().intersects(platform1[i].getGlobalBounds()))) {
					jump = 51;
					skeleton.move(0, 8);
				}
				if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) {

					move(-8, 0);
				}
				if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) {

					move(8, 0);
				}
			}

			if (skeleton.getGlobalBounds().intersects(key.getGlobalBounds()) && keyopen == false) {
				keyopen = true;
				eat.play();
			}
			if (skeleton.getGlobalBounds().intersects(keyi.getGlobalBounds()) && keyis == false) {
				keyis = true;
				eat.play();
			}
		}

		if (level == 2 && die == false)
		{
			for (int i = 21; i < 60; i++) {
				if ((skeleton.getGlobalBounds().intersects(platform[i].getGlobalBounds()))) {
					skeleton.move(0, -8);
					jumping = true;
					jump = 51;
				}
				if ((skeleton.getGlobalBounds().intersects(platform1[i].getGlobalBounds()))) {
					jump = 51;
					skeleton.move(0, 8);
				}
				if ((skeleton.getGlobalBounds().intersects(platform2[i].getGlobalBounds()))) {

					move2(-8, 0);
				}
				if ((skeleton.getGlobalBounds().intersects(platform3[i].getGlobalBounds()))) {

					move2(8, 0);
				}
				if (skeleton.getGlobalBounds().intersects(portalp2.getGlobalBounds())) {
					telep.play();
					level = 1;
					skeleton.setPosition(1150, 150);
				}
				if (skeleton.getGlobalBounds().intersects(portalr1.getGlobalBounds())) {
					telep.play();
					skeleton.setPosition(30, 100);
				}
			}
			fp++;
			if (fp % 3 == 0) {
				cntfp++;
				cntfp %= 61;
				for (int i = 0; i < 5; i++) {
					fire[i].setTextureRect(IntRect(cntfp * 74, cntfp * 0, 74, 121));
				}

			}
			fireScale++;
			if (fireScale < 100) {
				fireY++;
				for (int i = 0; i < 5; i++) {
					fire[i].setScale(fireY / 50, fireY / 100);
					fire[i].move(-0.7, 0);
				}
			}
			else if (fireScale < 200) {
				fireY--;
				for (int i = 0; i < 5; i++) {
					fire[i].setScale(fireY / 50, fireY / 100);
					fire[i].move(0.7, 0);
				}

			}
			else {
				fireScale = 0;
				fireY = 70;
			}


			wp++;
			if (wp % 5 == 0) {
				cntw++;
				cntw %= 9;
				for (int i = 0; i < 2; i++) {
					wizard[i].setTextureRect(IntRect(cntw * 32, cntw * 0, 32, 64));
				}
			}

			for (int i = 0; i < 20; i++) {
				if ((skeleton.getGlobalBounds().intersects(hidden[i].getGlobalBounds())) && hiddenarr[i] < 3) {
					Cnthiddenarr[i]++;
					jump = 51;
					jumping = true;
					skeleton.move(0, -8);

				}
				if (Cnthiddenarr[i] > 0) {
					Cnthiddenarr[i]++;
				}
				if (Cnthiddenarr[i] == 0) {
					continue;
				}
				if (Cnthiddenarr[i] % 13 == 0) {
					hiddenarr[i]++;
				}

				hidden[i].setTextureRect(IntRect(hiddenarr[i] * 206.25, hiddenarr[i] * 0, 206.25, 30));
			}

			if (skeleton.getGlobalBounds().intersects(portalg3.getGlobalBounds())) {
				telep.play();
				skeleton.setPosition(70, 100);
				move2(1320, -720);
			}

			pr1++;
			if (pr1 % 7 == 0 && ending == false) {
				cnterPr1++;
				cnterPr1 %= 5;
				for (int i = 0; i < 15; i++) {
					p1[i].setTextureRect(IntRect(cnterPr1 * 128, cnterPr1 * 0, 128, 50));
				}
			}

			for (int i = 0; i < 4; i++) {


				if (skeleton.getPosition().x > box[i].getPosition().x - 25 && skeleton.getPosition().y > box[i].getPosition().y) {
					boxtrap[i] = true;

				}

				if (boxtrap[i] == true) {
					box[i].move(0, 10);
				}

				if (skeleton.getGlobalBounds().intersects(box[i].getGlobalBounds())) {
					HP -= 1;
				}
			}

			if (skeleton.getGlobalBounds().intersects(final.getGlobalBounds()) && ending == false) {
				ending = true;
			}

			if (ending == true) {
				Skeleton.loadFromFile("Ameer.png");
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
			voice1.stop();
			voice2.stop();
			voice3.stop();
			back1.stop();
			back2.stop();
			back3.stop();
			ost.play();
			ost.setLoop(true);
		}

		cursor.setPosition(static_cast<Vector2f>(Mouse::getPosition(window)));




		window.clear();
		Cntmainmenubg++;


		if (Cntgame == 0) {


			if (Cntmainmenubg < 31) {
				window.draw(black);
			}

			else {
				window.draw(red);
			}

			if (Cntmainmenubg == 62) {
				Cntmainmenubg = 0;
			}

			window.draw(mainmenu);
			window.draw(start);
			window.draw(about);
			window.draw(exit);
		}

		if (Cntgame == 2) {
			if (Cntmainmenubg < 31) {
				window.draw(black);
			}

			else {
				window.draw(red);
			}

			if (Cntmainmenubg == 62) {
				Cntmainmenubg = 0;
			}


			window.draw(info);

			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i mousePos = Mouse::getPosition(window);

				if (mousePos.x > 500 && mousePos.x < 570 && mousePos.y > 410 && mousePos.y < 430) {
					Cntgame = 0;
				}
			}
		}

		if (storyStart == 1 && Cntgame == 0) {
			story++;
			sec++;
			if (sec < 750) {
				if (sec == 60) {
					voice1.play();

				}
				if (sec < 5) {
					back1.play();
				}


				if (story < 5) {
					window.draw(s1);
				}
				else if (story < 10) {
					window.draw(s2);
				}
				else if (story < 15) {
					window.draw(s3);
				}
				else if (story < 20) {
					window.draw(s4);
				}
				else if (story < 25) {
					window.draw(s5);
				}
				else if (story < 30) {
					window.draw(s6);
				}
				else if (story < 35) {
					window.draw(s7);
				}
				else if (story < 40) {
					window.draw(s8);
					if (sec < 750 && story == 39) {
						story = 0;
					}
				}
			}

			else if (sec > 750 && sec < 1200) {
				if (sec == 755) {
					voice2.play();
					back2.play();
				}

				if (story < 45) {
					window.draw(s9);
				}
				else if (story < 50) {
					window.draw(s10);
				}
				else if (story < 55) {
					window.draw(s11);
				}
				else if (story < 60) {
					window.draw(s12);
				}
				else if (story < 65) {
					window.draw(s13);
				}
				else if (story < 70) {
					window.draw(s14);
				}
				else if (story < 75) {
					window.draw(s15);
				}
				else if (story < 80) {
					window.draw(s16);
				}
				else if (story < 85) {
					window.draw(s17);
				}
				else if (story < 90) {
					window.draw(s18);
				}
				else if (story < 95) {
					window.draw(s19);
					if (story == 94) {
						story = 40;
					}
				}
			}
			else {
				if (sec == 1200) {
					voice3.play();
					back3.play();
				}

				if (story < 100) {
					window.draw(s20);
				}
				else if (story < 105) {
					window.draw(s21);
				}
				else if (story < 110) {
					window.draw(s22);
				}
				else if (story < 115) {
					window.draw(s23);
				}
				else if (story < 120) {
					window.draw(s24);
				}
				else if (story < 125) {
					window.draw(s25);
				}
				else if (story < 130) {
					window.draw(s26);
				}
				else if (story < 135) {
					window.draw(s27);
				}
				else if (story < 140) {
					window.draw(s28);
				}

				if (story == 139) {
					story = 95;
				}
			}

		}

		if (Cntgame == 1) {
			if (HP <= 0) {
				HP = 0;
				ost.stop();
			}

			firePosX = phase5.getPosition().x;
			firePosY = phase5.getPosition().y;
			if (cntw == 5) {

				fireball1.setPosition(1240 + firePosX, 270 + firePosY);
				fireball2.setPosition(50 + firePosX, 410 + firePosY);
			}
			fireball1.move(-30, 0);
			fireball2.move(30, 0);

			if (HP < 0) {
				cout << " ";
			}

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
				window.draw(archer);
				window.draw(arrow);
				window.draw(spider);

				if (keyopen == 0) {
					window.draw(key);
				}
				if (keyopen) {
					window.draw(portalg1);
				}
				if (keyis == 0) {
					window.draw(keyi);
				}

				for (int i = 0; i < 2; i++) {
					if (potionbool[i] == 1) {
						window.draw(potion[i]);
					}
					if (skeleton.getGlobalBounds().intersects(potion[i].getGlobalBounds()) && HP < 71
						&& potionbool[i] == true) {
						potionbool[i] = 0;
						HP += 30;
						drink.play();
					}
					else if (skeleton.getGlobalBounds().intersects(potion[i].getGlobalBounds()) && HP > 70
						&& potionbool[i] == 1) {
						potionbool[i] = 0;
						drink.play();
						HP = 100;
					}
				}

				for (int i = 1; i < 28; i++) {
					if (i == 4 || i == 24) {
						continue;
					}
					if (skeleton.getGlobalBounds().intersects(spike[i].getGlobalBounds())) {
						HP -= 1;
						cout << i << " ";
					}
					window.draw(spike[i]);
				}

				for (int i = 0; i < 41; i++) {

					if (skeleton.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && coinbool[i] == 1) {
						coinbool[i] = 0;
						eat.play();
						score += 10;
					}
					if (coinbool[i] == 1) {
						window.draw(coin[i]);
					}
				}
				if (keyis) {
					for (int i = 0; i < 3; i++) {
						window.draw(brick[i]);
					}
				}


				arrowPosX = phase1.getPosition().x;
				arrowPosY = phase1.getPosition().y;
				if (cntsp == 6) {
					arrow.setPosition(1170 + arrowPosX, 210 + 835 + arrowPosY);
				}
				arrow.move(-18, 0);


				if (skeleton.getGlobalBounds().intersects(arrow.getGlobalBounds()) && damage == 0) {
					HP -= 30;
					damage = 1;
					cout << HP << " ";
				}
				else if (skeleton.getGlobalBounds().intersects(spider.getGlobalBounds()) && damage == 0) {
					HP -= 30;
					damage = 1;
					spiderS.play();
					cout << HP << " ";
				}
				else if (skeleton.getGlobalBounds().intersects(arrow.getGlobalBounds()) && damage == 1) {
					damage = 1;
				}
				else if (skeleton.getGlobalBounds().intersects(spider.getGlobalBounds()) && damage == 1) {
					damage = 1;
				}
				else {
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


				for (int i = 0; i < 20; i++) {
					window.draw(hidden[i]);
				}
				if (cntw == 3 && phase5.getPosition().x >= -1200 &&
					phase5.getPosition().y >= -10) {
					fireBall.play();
				}

				if ((skeleton.getGlobalBounds().intersects(fireball1.getGlobalBounds()) ||
					skeleton.getGlobalBounds().intersects(fireball2.getGlobalBounds())) &&
					damage == 0) {
					HP -= 30;
					damage = 1;
					cout << HP << " ";
				}
				else if ((skeleton.getGlobalBounds().intersects(fireball1.getGlobalBounds()) ||
					skeleton.getGlobalBounds().intersects(fireball2.getGlobalBounds())) &&
					damage == 1) {
					damage = 1;
				}
				else {
					damage = 0;
				}

				for (int i = 0; i < 15; i++) {
					if (skeleton.getGlobalBounds().intersects(p1[i].getGlobalBounds())) {
						HP -= 10;
					}
				}

				for (int i = 41; i < 60; i++) {

					if (skeleton.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && coinbool[i] == 1) {
						coinbool[i] = 0;
						eat.play();
						score += 10;
					}
					if (coinbool[i] == 1) {
						window.draw(coin[i]);
					}
				}

				for (int i = 0; i < 5; i++) {
					window.draw(fire[i]);
					if (skeleton.getGlobalBounds().intersects(fire[i].getGlobalBounds()) &&
						skeleton.getPosition().x > up2[i].getPosition().x &&
						skeleton.getPosition().x < up2[i].getPosition().x + 145) {
						HP -= 1;
					}
				}
				for (int i = 0; i < 5; i++) {
					window.draw(up2[i]);
				}
				for (int i = 0; i < 2; i++) {
					window.draw(wizard[i]);
				}
				if (ending == false) {
					window.draw(final);
				}

			}

			window.draw(skeleton);
			if (level == 2) {
				for (int i = 0; i < 15; i++) {
					window.draw(p1[i]);
				}

				for (int i = 0; i < 4; i++) {
					window.draw(box[i]);
				}
			}
			ifstream readFile;
			readFile.open("Highscore.txt");
			if (readFile.is_open()) {
				while (!readFile.eof()) {
					readFile >> highscore;
				}
			}
			readFile.close();
			ofstream writeFile("Highscore.txt");
			if (writeFile.is_open()) {
				if (score > highscore) {
					highscore = score;
				}
				writeFile << highscore;
			}
			stringstream theScore;
			stringstream _theScore;
			stringstream thelives;
			theScore << score;
			_theScore << highscore;
			Myscore.setString(theScore.str());
			_score.setString(_theScore.str());
			writeFile.close();
			window.draw(MyScore);
			window.draw(Myscore);
			window.draw(Highscore);
			window.draw(_score);
			window.draw(bar);
			window.draw(frame);
			window.draw(heart);
		}
		if (HP <= 0 && die == false) {
			die = true;
			lost.play();
		}
		if (die) {
			window.draw(lose);
			skeleton.move(0, -8);
		}
		if (ending == true) {
			window.draw(win);
		}
		window.setView(fixed);
		window.draw(cursor);
		window.display();
	}

	return 0;
}

void coinn(int x, int y, int co, int i) {
	coin[i].setPosition(x + co, y);
	coinPos += 40;
	coinbool[i] = 1;
	if (i > 40) {
		coinPos2 += 40;
	}
}

void level1Phase() {
	Phase1.loadFromFile("phase1.png");
	phase1.setTextureRect(IntRect(0, 0, 1280, 720));
	phase1.setPosition(0, 0);
	phase1.setScale(1, 1);

	Phase2.loadFromFile("phase2.png");
	phase2.setTextureRect(IntRect(0, 0, 1280, 720));
	phase2.setPosition(1280, 0);
	phase2.setScale(1, 1);

	Phase3.loadFromFile("phase3.png");
	phase3.setTextureRect(IntRect(0, 0, 1280, 720));
	phase3.setPosition(0, 720);
	phase3.setScale(1, 1);

	Phase4.loadFromFile("phase4.png");
	phase4.setTextureRect(IntRect(0, 0, 1280, 720));
	phase4.setPosition(1280, 720);
	phase4.setScale(1, 1);

}

void level2Phase() {
	Phase5.loadFromFile("phase5.png");
	phase5.setTextureRect(IntRect(0, 0, 1280, 720));
	phase5.setPosition(0, 0);
	phase5.setScale(1, 1);

	Phase6.loadFromFile("phase6.png");
	phase6.setTextureRect(IntRect(0, 0, 1280, 720));
	phase6.setPosition(1280, 0);
	phase6.setScale(1, 1);

	Phase7.loadFromFile("phase7.png");
	phase7.setTextureRect(IntRect(0, 0, 1280, 720));
	phase7.setPosition(0, 720);
	phase7.setScale(1, 1);

	Phase8.loadFromFile("phase8.png");
	phase8.setTextureRect(IntRect(0, 0, 1280, 720));
	phase8.setPosition(1280, 720);
	phase8.setScale(1, 1);
}

void Platforms() {
	Platform.loadFromFile("platform.png");
	for (int i = 0; i < 60; i++) {
		platform[i].setTextureRect(IntRect(0, 0, 88, 5));
		platform[i].setTexture(Platform);
	}

	platform[0].setScale(11.1, 2);
	platform[0].setPosition(70, 265);//

	platform[1].setScale(12.4, 2);
	platform[1].setPosition(345, 433);//

	platform[2].setScale(1.3, 2);
	platform[2].setPosition(1520, 530);//

	platform[3].setScale(1.3, 2);
	platform[3].setPosition(1600, 365);//

	platform[4].setScale(1.3, 2);
	platform[4].setPosition(1825, 285);//

	platform[5].setScale(1.3, 2);
	platform[5].setPosition(2075, 240);//

	platform[6].setScale(1.7, 2);
	platform[6].setPosition(2343, 185);//

	platform[7].setScale(6.7, 2);
	platform[7].setPosition(1900, 410);//

	platform[8].setScale(9.4, 2);
	platform[8].setPosition(1260, 990);

	platform[9].setScale(10.4, 2);
	platform[9].setPosition(68, 1070);

	platform[10].setScale(0.5, 2);
	platform[10].setPosition(1170, 1070);

	platform[11].setScale(0.5, 2);
	platform[11].setPosition(1216, 60);

	platform[12].setScale(0.5, 2);
	platform[12].setPosition(1216, 780);

	platform[13].setScale(30, 1);
	platform[13].setPosition(0, 680);

	platform[14].setScale(30, 1);
	platform[14].setPosition(0, 1380);

	platform[15].setScale(1.2, 1);
	platform[15].setPosition(1345, 605);

	platform[21].setScale(1.8, 1.5);
	platform[21].setPosition(67, 325);

	platform[22].setScale(0.8, 1.5);
	platform[22].setPosition(350, 330);

	platform[23].setScale(0.8, 1.5);
	platform[23].setPosition(535, 335);

	platform[24].setScale(0.8, 1.5);
	platform[24].setPosition(715, 335);

	platform[25].setScale(0.8, 1.5);
	platform[25].setPosition(880, 335);

	platform[26].setScale(10.8, 1.5);
	platform[26].setPosition(260, 505);

	platform[27].setScale(28.35, 1.5);
	platform[27].setPosition(67, 700);

	platform[28].setScale(1.5, 1.5);
	platform[28].setPosition(1260, 230);

	platform[29].setScale(1.4, 1.5);
	platform[29].setPosition(1540, 230);

	platform[30].setScale(1.4, 1.5);
	platform[30].setPosition(1780, 230);

	platform[31].setScale(1.4, 1.5);
	platform[31].setPosition(2050, 230);

	platform[32].setScale(1.4, 1.5);
	platform[32].setPosition(2300, 230);

	platform[33].setScale(1.3, 1.5);
	platform[33].setPosition(1465, 490);

	platform[34].setScale(1.3, 1.5);
	platform[34].setPosition(1865, 490);

	platform[35].setScale(1.3, 1.5);
	platform[35].setPosition(2200, 490);

	platform[36].setScale(11.5, 0.5);
	platform[36].setPosition(84, 1050);

	platform[37].setScale(10.5, 0.5);
	platform[37].setPosition(316, 1192);

	platform[38].setScale(30, 1.5);
	platform[38].setPosition(68, 1415);

	platform[39].setScale(0.7, 1.5);
	platform[39].setPosition(1085, 1011);

	platform[40].setScale(0.7, 1.5);
	platform[40].setPosition(259, 1158);

	platform[41].setScale(1.4, 1.5);
	platform[41].setPosition(212 + 1280, 188 + 720);

	platform[42].setScale(1.4, 1.5);
	platform[42].setPosition(402 + 1280, 210 + 720);

	platform[43].setScale(1.4, 1.5);
	platform[43].setPosition(585 + 1280, 246 + 720);

	platform[44].setScale(1.4, 1.5);
	platform[44].setPosition(307 + 1280, 573 + 720);

	platform[45].setScale(1.4, 1.5);
	platform[45].setPosition(764 + 1280, 206 + 720);

	platform[46].setScale(1.4, 1.5);
	platform[46].setPosition(931 + 1280, 257 + 720);

	platform[47].setScale(1.4, 1.5);
	platform[47].setPosition(1101 + 1280, 345 + 720);

	platform[48].setScale(1.4, 1.5);
	platform[48].setPosition(803 + 1280, 443 + 720);

	platform[49].setScale(1.4, 1.5);
	platform[49].setPosition(648 + 1280, 479 + 720);

	platform[50].setScale(1.4, 1.5);
	platform[50].setPosition(483 + 1280, 523 + 720);

	platform[51].setScale(1.4, 1.5);
	platform[51].setPosition(307 + 1280, 573 + 720);

	platform[52].setScale(1.4, 1.5);
	platform[52].setPosition(126 + 1280, 619 + 720);

	platform[53].setScale(1.4, 1.5);
	platform[53].setPosition(1272, 166 + 720);


	platform[54].setScale(1.4, 1.5);
	platform[54].setPosition(965 + 1280, 407 + 720);


	Platform1.loadFromFile("platform1.png");

	for (int i = 0; i < 60; i++) {
		platform1[i].setTextureRect(IntRect(0, 0, 88, 5));
		platform1[i].setTexture(Platform1);
	}

	platform1[0].setScale(11.1, 2);
	platform1[0].setPosition(70, 275);

	platform1[1].setScale(12.4, 2);
	platform1[1].setPosition(345, 443);

	platform1[2].setScale(1.3, 2);
	platform1[2].setPosition(1520, 540);

	platform1[3].setScale(1.3, 2);
	platform1[3].setPosition(1600, 375);

	platform1[4].setScale(1.3, 2);
	platform1[4].setPosition(1825, 305);

	platform1[5].setScale(1.3, 2);
	platform1[5].setPosition(2075, 260);

	platform1[6].setScale(1.7, 2);
	platform1[6].setPosition(2343, 205);

	platform1[7].setScale(6.7, 2);
	platform1[7].setPosition(1900, 420);

	platform1[8].setScale(9.4, 2);
	platform1[8].setPosition(1260, 1010);

	platform1[9].setScale(10.4, 2);
	platform1[9].setPosition(68, 1090);

	platform1[10].setScale(0.5, 2);
	platform1[10].setPosition(1170, 1090);

	platform1[11].setScale(0.5, 2);
	platform1[11].setPosition(1216, 80);

	platform1[12].setScale(0.5, 2);
	platform1[12].setPosition(1216, 800);

	platform1[13].setScale(30, 1);
	platform1[13].setPosition(0, 700);

	platform1[14].setScale(30, 1);
	platform1[14].setPosition(0, 1400);

	platform1[15].setScale(1.3, 1);
	platform1[15].setPosition(1340, 640);

	platform1[21].setScale(1.8, 1.5);
	platform1[21].setPosition(67, 345);

	platform1[22].setScale(0.8, 1.5);
	platform1[22].setPosition(350, 350);

	platform1[23].setScale(0.8, 1.5);
	platform1[23].setPosition(535, 355);

	platform1[24].setScale(0.8, 1.5);
	platform1[24].setPosition(715, 355);

	platform1[25].setScale(0.8, 1.5);
	platform1[25].setPosition(880, 355);

	platform1[26].setScale(10.8, 1.5);
	platform1[26].setPosition(260, 525);

	platform1[27].setScale(28.35, 1.5);
	platform1[27].setPosition(67, 710);

	platform1[28].setScale(1.5, 1.5);
	platform1[28].setPosition(1260, 240);

	platform1[29].setScale(1.4, 1.5);
	platform1[29].setPosition(1540, 250);

	platform1[30].setScale(1.4, 1.5);
	platform1[30].setPosition(1780, 250);

	platform1[31].setScale(1.4, 1.5);
	platform1[31].setPosition(2050, 250);

	platform1[32].setScale(1.4, 1.5);
	platform1[32].setPosition(2300, 250);

	platform1[33].setScale(1.3, 1.5);
	platform1[33].setPosition(1465, 520);

	platform1[34].setScale(1.3, 1.5);
	platform1[34].setPosition(1865, 520);

	platform1[35].setScale(1.3, 1.5);
	platform1[35].setPosition(2200, 520);
	platform1[36].setScale(11.5, 0.5);
	platform1[36].setPosition(84, 1060);

	platform1[37].setScale(10.5, 0.5);
	platform1[37].setPosition(316, 1200);

	platform1[38].setScale(31, 1.5);
	platform1[38].setPosition(68, 1430);

	platform1[39].setScale(1.4, 1.5);
	platform1[39].setPosition(402 + 1280, 220 + 720);

	platform1[40].setScale(1.4, 1.5);
	platform1[40].setPosition(585 + 1280, 256 + 720);

	platform1[41].setScale(1.4, 1.5);
	platform1[41].setPosition(307 + 1280, 583 + 720);

	platform1[42].setScale(1.4, 1.5);
	platform1[42].setPosition(764 + 1280, 215 + 720);

	platform1[43].setScale(1.4, 1.5);
	platform1[43].setPosition(931 + 1280, 265 + 720);

	platform1[44].setScale(1.4, 1.5);
	platform1[44].setPosition(1101 + 1280, 355 + 720);

	platform1[45].setScale(1.4, 1.5);
	platform1[45].setPosition(803 + 1280, 453 + 720);

	platform1[46].setScale(1.4, 1.5);
	platform1[46].setPosition(648 + 1280, 489 + 720);

	platform1[47].setScale(1.4, 1.5);
	platform1[47].setPosition(483 + 1280, 533 + 720);

	platform1[48].setScale(1.4, 1.5);
	platform1[48].setPosition(307 + 1280, 583 + 720);

	platform1[49].setScale(1.4, 1.5);
	platform1[49].setPosition(126 + 1280, 629 + 720);

	platform1[50].setScale(1.4, 1.5);
	platform1[50].setPosition(1272, 166 + 730);

	platform1[51].setScale(1.4, 1.5);
	platform1[51].setPosition(965 + 1280, 420 + 720);

	platform1[52].setScale(1.4, 1.5);
	platform1[52].setPosition(212 + 1280, 208 + 720);



	Platform2.loadFromFile("platform2.png");
	for (int i = 0; i < 60; i++) {
		platform2[i].setTextureRect(IntRect(0, 0, 88, 5));
		platform2[i].setTexture(Platform2);
	}

	platform2[0].setScale(0.05, 5);
	platform2[0].setPosition(1046.8, 264);//

	platform2[1].setScale(0.05, 5);
	platform2[1].setPosition(1436.2, 437);//

	platform2[2].setScale(0.09, 5);
	platform2[2].setPosition(1634.4, 530);//

	platform2[3].setScale(0.05, 5);
	platform2[3].setPosition(1714.4, 369);//

	platform2[4].setScale(0.07, 5);
	platform2[4].setPosition(1939.4, 285);//

	platform2[5].setScale(0.07, 5);
	platform2[5].setPosition(2189.4, 240);//

	platform2[6].setScale(0.05, 5);
	platform2[6].setPosition(3000, 185);//

	platform2[7].setScale(0.05, 5);
	platform2[7].setPosition(3000, 400);//

	platform2[8].setScale(0.05, 5);
	platform2[8].setPosition(2087.2, 990);

	platform2[9].setScale(0.05, 5);
	platform2[9].setPosition(983.2, 1070);

	platform2[10].setScale(0.05, 5);
	platform2[10].setPosition(1214, 1070);

	platform2[11].setScale(0.05, 100);
	platform2[11].setPosition(1260, 60);

	platform2[12].setScale(0.05, 100);
	platform2[12].setPosition(1250, 780);

	platform2[13].setScale(0.05, 100);
	platform2[13].setPosition(2640, 680);

	platform2[14].setScale(0.05, 5);
	platform2[14].setPosition(2640, 1380);

	platform2[15].setScale(0.1, 9);
	platform2[15].setPosition(1460, 600);

	platform2[21].setScale(0.1, 6);
	platform2[21].setPosition(225, 325);

	platform2[22].setScale(0.1, 5.5);
	platform2[22].setPosition(420, 330);

	platform2[23].setScale(0.1, 5.5);
	platform2[23].setPosition(600, 335);

	platform2[24].setScale(0.1, 5.5);
	platform2[24].setPosition(780, 335);

	platform2[25].setScale(0.1, 5.5);
	platform2[25].setPosition(950, 335);

	platform2[26].setScale(0.1, 100);
	platform2[26].setPosition(1255, 60);

	platform2[27].setScale(0.1, 5.5);
	platform2[27].setPosition(1395, 230);

	platform2[28].setScale(0.1, 5.5);
	platform2[28].setPosition(1665, 230);

	platform2[29].setScale(0.1, 5.5);
	platform2[29].setPosition(1905, 230);

	platform2[30].setScale(0.1, 5.5);
	platform2[30].setPosition(2175, 230);

	platform2[31].setScale(0.1, 5.5);
	platform2[31].setPosition(2420, 230);

	platform2[32].setScale(0.05, 8);
	platform2[32].setPosition(1145, 1015);

	platform2[33].setScale(0.05, 8);
	platform2[33].setPosition(312, 1158);

	platform2[46].setScale(0.1, 100);
	platform2[46].setPosition(1260, 60 + 720);


	Platform3.loadFromFile("platform3.png");
	for (int i = 0; i < 60; i++) {
		platform3[i].setTextureRect(IntRect(0, 0, 88, 5));
		platform3[i].setTexture(Platform3);
	}

	platform3[0].setScale(0.05, 5);
	platform3[0].setPosition(65, 265);

	platform3[1].setScale(0.05, 5);
	platform3[1].setPosition(340, 433);

	platform3[2].setScale(0.09, 5);
	platform3[2].setPosition(1515, 530);

	platform3[3].setScale(0.05, 5);
	platform3[3].setPosition(1595, 365);

	platform3[4].setScale(0.05, 5);
	platform3[4].setPosition(1820, 285);

	platform3[5].setScale(0.05, 5);
	platform3[5].setPosition(2070, 240);

	platform3[6].setScale(0.05, 5);
	platform3[6].setPosition(2340, 185);

	platform3[7].setScale(0.05, 5);
	platform3[7].setPosition(1895, 410);

	platform3[8].setScale(0.05, 5);
	platform3[8].setPosition(1258, 990);

	platform3[9].setScale(0.05, 5);
	platform3[9].setPosition(65, 1070);

	platform3[10].setScale(0.05, 5);
	platform3[10].setPosition(1165, 1070);

	platform3[11].setScale(0.05, 100);
	platform3[11].setPosition(1216, 60);

	platform3[12].setScale(0.05, 100);
	platform3[12].setPosition(1216, 780);

	platform3[13].setScale(0.05, 2);
	platform3[13].setPosition(0, 680);

	platform3[14].setScale(0.05, 2);
	platform3[14].setPosition(0, 1380);

	platform3[15].setScale(0.1, 9);
	platform3[15].setPosition(1330, 600);

	platform3[21].setScale(0.07, 5.5);
	platform3[21].setPosition(345, 330);

	platform3[22].setScale(0.07, 5.5);
	platform3[22].setPosition(530, 335);

	platform3[23].setScale(0.07, 5.5);
	platform3[23].setPosition(705, 335);

	platform3[24].setScale(0.07, 5.5);
	platform3[24].setPosition(870, 335);

	platform3[25].setScale(0.07, 100);
	platform3[25].setPosition(1210, 60);

	platform3[26].setScale(0.07, 5.5);
	platform3[26].setPosition(1535, 230);

	platform3[27].setScale(0.07, 5.5);
	platform3[27].setPosition(1770, 230);

	platform3[28].setScale(0.07, 5.5);
	platform3[28].setPosition(2045, 230);

	platform3[29].setScale(0.07, 5.5);
	platform3[29].setPosition(2295, 230);

	platform3[30].setScale(0.05, 8);
	platform3[30].setPosition(1085, 1011);

	platform3[31].setScale(0.05, 8);
	platform3[31].setPosition(259, 1158);

	platform3[46].setScale(0.1, 100);
	platform3[46].setPosition(1220, 60 + 720);
}

void Coins() {
	Coin.loadFromFile("coin.png");
	// coin parameters (x pos, y poos, coinPos, i)
	for (int i = 0; i < 41; i++) {
		coin[i].setTexture(Coin);
		coin[i].setTextureRect(IntRect(0, 0, 1800, 1900));
		coin[i].setScale(0.014, 0.014);
		if (i == 26) {
			coinPos = 0;
		}
		// first phase

		if (i >= 0 && i < 7) {
			coinn(300, 235, coinPos, i);
		}
		else if (i >= 5 && i < 14) {
			coinn(300, 400, coinPos, i);
		}
		// second phase // +433 -12 
		else if (i >= 14 && i < 41) {
			if (i == 14) {
				coinn(1000, 500, coinPos, i);
			}
			else if (i == 15) {
				coinn(730, 405, coinPos, i);
			}
			else if (i == 16) {
				coinn(1010, 333, coinPos, i);
			}
			else if (i == 17) {
				coinn(1185, 255, coinPos, i);
			}
			else if (i == 18) {
				coinn(1400, 210, coinPos, i);
			}
			else if (i > 18 && i <= 20) {
				coinn(10000000, 1000000, coinPos, i);
			}
			else if (i > 20 && i <= 22) {
				coinn(1310, 382, coinPos, i);
			}
			else if (i > 22 && i <= 25) {
				coinn(1415, 382, coinPos, i);
			}
			// third phase
			else if (i > 25 && i <= 31) {
				coinn(179, 339 + 705, coinPos, i);
			}
			else if (i > 31 && i <= 34) {
				coinn(1110, 964.5, coinPos, i);
			}
			else if (i > 34 && i <= 37) {
				coinn(1245, 964.5, coinPos, i);
			}
			else if (i > 37 && i <= 40) {
				coinn(1400, 964.5, coinPos, i);
			}


		}
	}
	for (int i = 41; i < 60; i++) {
		coin[i].setTexture(Coin);
		coin[i].setTextureRect(IntRect(0, 0, 1800, 1900));
		coin[i].setScale(0.014, 0.014);
		if (i == 50) {
			coinPos2 = 0;
		}
		if (i == 41) {
			coinn(375, 300, 0, i);
		}
		else if (i == 42) {
			coinn(560, 302, 0, i);
		}
		else if (i == 43) {
			coinn(738, 304, 0, i);
		}
		else if (i == 44) {
			coinn(904, 305, 0, i);
		}
		else if (i > 44 && i <= 49) {
			coinn(240, 470, coinPos2, i);
			coinPos2 += 100;
		}
		else if (i > 49 && i <= 53) {
			coinn(1450, 177 - 50, coinPos2, i);
			coinPos2 += 220;
		}
		else if (i == 54) {
			coinn(1630, 1263 + 3, 0, i);
		}
		else if (i == 55) {
			coinn(1936 + 35, 1166 + 3, 0, i);
		}
		else if (i == 56) {
			coinn(2251 + 35, 1092 + 3, 0, i);

		}
		else if (i == 57) {
			coinn(2220 + 35, 944 + 3, 0, i);
		}
		else if (i == 58) {
			coinn(1903, 933 + 3, 0, i);
		}
		else if (i == 59) {
			coinn(1539, 877 + 3, 0, i);
		}

	}
}

void poison(int x, int y, int i) {
	if (i == 8) {
		diff = 0;
	}
	p1[i].setPosition(x + diff, y);
	diff += 128;

}

void move(int x, int y) {

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

	for (int i = 0; i < 41; i++) {
		coin[i].move(x, y);

	}
	for (int i = 1; i < 28; i++) {

		spike[i].move(x, y);
	}
	for (int i = 0; i < 3; i++) {

		brick[i].move(x, y);
	}
	archer.move(x, y);
	arrow.move(x, y);
	key.move(x, y);
	keyi.move(x, y);
	for (int i = 0; i < 2; i++) {
		potion[i].move(x, y);
	}


}

void move2(int x, int y) {

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
	final.move(x, y);
	for (int i = 41; i < 60; i++) {
		coin[i].move(x, y);
	}
	for (int i = 0; i < 2; i++) {
		wizard[i].move(x, y);
	}
	for (int i = 0; i < 5; i++) {
		fire[i].move(x, y);
	}

	for (int i = 20; i < 60; i++) {
		platform[i].move(x, y);
		platform1[i].move(x, y);
		platform2[i].move(x, y);
		platform3[i].move(x, y);
	}

	for (int i = 0; i < 5; i++) {
		up2[i].move(x, y);
	}

	for (int i = 0; i < 15; i++) {
		p1[i].move(x, y);
	}
	for (int i = 0; i < 20; i++) {
		hidden[i].move(x, y);
	}

	for (int i = 0; i < 4; i++) {
		box[i].move(x, y);
	}

}
