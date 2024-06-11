#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<ctime>
#include<fstream>
using namespace std;
using namespace sf;
bool coin_toss() {
	int random;
	cout << "Heads is for Blue & Tails is for Red" << endl;
	srand(static_cast<unsigned int>(time(NULL)));
	random = rand() % 100 + 1;
	cout << "Toss Result : ";
	if (random % 2 == 0) {
		cout << "\t --> Tails Win! <--" << "\n";
		cout << "Red will play first!" << endl;
		return 0;
	}
	else {
		cout << "\t --> Heads Win! <--" << "\n";
		cout << "Blue will play first!" << endl;
		return 1;
	}
}
int chk_win(int& p1_pieces, int& p2_pieces) {
	if (p1_pieces == 1 && p2_pieces == 1) {
		cout << "Its a Draw!";
		return 0;
	}
	if (p1_pieces >= 1 && p2_pieces == 0) {
		cout << "\t\t    _*_" << endl;
		cout << "\t\t  _/\\|/\\_" << endl;
		cout << "\t\t_/P1 Wins\\_" << endl;
		return 1;
	}
	if (p2_pieces >= 1 && p1_pieces == 0) {
		cout << "\t\t    _*_" << endl;
		cout << "\t\t  _/\\|/\\_" << endl;
		cout << "\t\t_/P2 Wins\\_" << endl;
		return 2;
	}
	else
		return 3;
}
bool chk_elimination_p2(int& p1_pieces, int n1, int m1, int n2, int m2, Sprite z[12],bool chek) {
	int a = 0, b = 0;
	a = n2 - n1;
	b = m2 - m1;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if ((a == 1 || b == 1) && chek == 1) return 1;
	else if ((a == 2 || b == 2)&&chek==1) {
		int x = 0, y = 0;
		int n = (n2 + n1) / 2;
		int m = (m2 + m1) / 2;
		if (m == 0)x = 5;
		if (m == 1)x = 180;
		if (m == 2)x = 360;
		if (m == 3)x = 535;
		if (m == 4)x = 720;
		if (n == 0)y = 55;
		if (n == 1)y = 223;
		if (n == 2)y = 393;
		if (n == 3)y = 560;
		if (n == 4)y = 740;
		for (int i = 0; i < 12; i++) {
			if (x == z[i].getPosition().x && y == z[i].getPosition().y) {
				cout << "Bead eliminated at : " << x << " , " << y << endl;
				z[i].setPosition(1000, 1000);
				p1_pieces--;
				return 1;
			}
		}
	}
	return 0;
}
bool chk_elimination_p1(int& p2_pieces, int n1, int m1, int n2, int m2, Sprite z[12],bool chek) {
	int a = 0, b = 0;
	a = n2 - n1;
	b = m2 - m1;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if ((a == 1 || b == 1)&&chek==1) return 1;
	else if ((a == 2 || b == 2)&&chek==1) {
		int x = 0, y = 0;
		int n = (n2 + n1) / 2;
		int m = (m2 + m1) / 2;
		if (m == 0)x = 5;
		if (m == 1)x = 180;
		if (m == 2)x = 360;
		if (m == 3)x = 535;
		if (m == 4)x = 720;
		if (n == 0)y = 55;
		if (n == 1)y = 223;
		if (n == 2)y = 393;
		if (n == 3)y = 560;
		if (n == 4)y = 740;
		for (int i = 0; i < 12; ++i) {
			if (x == z[i].getPosition().x && y == z[i].getPosition().y) {
				cout << "Bead eliminated at : " << x << " , " << y << endl;
				z[i].setPosition(1000, 1000);
				p2_pieces--;
				return 1;
			}
		}
	}
	return 0;
}
bool chk_move(Sprite x[12], Sprite y[12], int n1, int m1, int n2, int m2, int x2, int y2) {
	for (int i = 0; i < 12; i++) {
		if ((x2 == x[i].getPosition().x && y2 == x[i].getPosition().y) || (x2 == y[i].getPosition().x && y2 == y[i].getPosition().y))
			return 0;
	}
	int u = 0, v = 0;
	u = n2 - n1;
	v = m2 - m1;
	if (u < 0)
		u *= -1;
	if (v < 0)
		v *= -1;
	if (u > 2)
		return 0;
	if (v > 2)
		return 0;
	if ((n1 == 1 && m1 == 2) || (n1 == 2 && m1 == 1) || (n1 == 3 && m1 == 2) || (n1 == 2 && m1 == 3) || (n1 == 0 && m1 == 1) || (n1 == 0 && m1 == 3) || (n1 == 1 && m1 == 0) || (n1 == 3 && m1 == 0) || (n1 == 4 && m1 == 1) || (n1 == 4 && m1 == 3) || (n1 == 3 && m1 == 4) || (n1 == 1 && m1 == 4)) {
		if (n1 != n2 && m1 != m2)
			return 0;
	}
	else {
		if (n1 != n2 && m1 != m2) {
			int i = n2 - n1;
			int j = m2 - m1;
			if (i < 0)
				i *= -1;
			if (j < 0)
				j *= -1;
			if (i != j)
				return 0;
		}
	}
	if (n1 > 4 || n1 < 0 || m1>4 || m1 < 0 || n2>4 || n2 < 0 || m2>4 || m2 < 0)
		return 0;
	else
		return 1;
}
int main() {
playagain:
	RenderWindow window(VideoMode(934, 897), "12 Bead Game");
	window.setFramerateLimit(60);
	CircleShape t1(33), t2(33), t3(33), t4(33), t5(33), t6(33), t7(33), t8(33), t9(33), t10(33), t11(33), t12(33), t13(33), t14(33), t15(33), t16(33), t17(33), t18(33), t19(33), t20(33), t21(33), t22(33), t23(33), t24(33), t25(33);
	t1.setPosition(80, 74);
	t1.setFillColor(Color::Transparent);
	t2.setPosition(255, 74);
	t2.setFillColor(Color::Transparent);
	t3.setPosition(435, 74);
	t3.setFillColor(Color::Transparent);
	t4.setPosition(610, 74);
	t4.setFillColor(Color::Transparent);
	t5.setPosition(795, 74);
	t5.setFillColor(Color::Transparent);
	t6.setPosition(80, 243);
	t6.setFillColor(Color::Transparent);
	t7.setPosition(255, 243);
	t7.setFillColor(Color::Transparent);
	t8.setPosition(435, 243);
	t8.setFillColor(Color::Transparent);
	t9.setPosition(610, 243);
	t9.setFillColor(Color::Transparent);
	t10.setPosition(795, 243);
	t10.setFillColor(Color::Transparent);
	t11.setPosition(80, 412);
	t11.setFillColor(Color::Transparent);
	t12.setPosition(255, 412);
	t12.setFillColor(Color::Transparent);
	t13.setPosition(435, 412);
	t13.setFillColor(Color::Transparent);
	t14.setPosition(610, 412);
	t14.setFillColor(Color::Transparent);
	t15.setPosition(795, 412);
	t15.setFillColor(Color::Transparent);
	t16.setPosition(80, 579);
	t16.setFillColor(Color::Transparent);
	t17.setPosition(255, 579);
	t17.setFillColor(Color::Transparent);
	t18.setPosition(435, 579);
	t18.setFillColor(Color::Transparent);
	t19.setPosition(610, 579);
	t19.setFillColor(Color::Transparent);
	t20.setPosition(795, 579);
	t20.setFillColor(Color::Transparent);
	t21.setPosition(80, 760);
	t21.setFillColor(Color::Transparent);
	t22.setPosition(255, 760);
	t22.setFillColor(Color::Transparent);
	t23.setPosition(435, 760);
	t23.setFillColor(Color::Transparent);
	t24.setPosition(610, 760);
	t24.setFillColor(Color::Transparent);
	t25.setPosition(795, 760);
	t25.setFillColor(Color::Transparent);
	CircleShape p1bead(20), p2bead(20);
	p1bead.setFillColor(Color::Cyan);
	p2bead.setFillColor(Color::Red);
	p1bead.setPosition(430, 18);
	p2bead.setPosition(475, 18);
	Texture text, BeadP1, BeadP2, bckgrnd, button, menu, p2chkwin, p1chkwin, draw, again, exit, movecounter, rbutton, bgfollowup;
	bgfollowup.loadFromFile("bgsnow.jpg");
	bckgrnd.loadFromFile("./bgsnow.jpg");
	rbutton.loadFromFile("./resumebutton.png");
	text.loadFromFile("./board.png");
	BeadP1.loadFromFile("./beadP1.png");
	BeadP2.loadFromFile("./beadP2.png");
	button.loadFromFile("./startbutton3.png");
	menu.loadFromFile("./logo.png");
	p1chkwin.loadFromFile("./p1winlogo.png");
	p2chkwin.loadFromFile("./p2winlogo.png");
	draw.loadFromFile("./drawlogo.png");
	again.loadFromFile("./playagainbutton.png");
	exit.loadFromFile("./exitbutton2.png");
	movecounter.loadFromFile("./movecounter.png");
	Texture p1bead0, p1bead1, p1bead2, p1bead3, p1bead4, p1bead5, p1bead6, p1bead7, p1bead8, p1bead9, p1bead10, p1bead11, p1bead12, p2bead0, p2bead1, p2bead2, p2bead3, p2bead4, p2bead5, p2bead6, p2bead7, p2bead8, p2bead9, p2bead10, p2bead11, p2bead12;
	p1bead0.loadFromFile("./p1bead0.png");
	p1bead1.loadFromFile("./p1bead1.png");
	p1bead2.loadFromFile("./p1bead2.png");
	p1bead3.loadFromFile("./p1bead3.png");
	p1bead4.loadFromFile("./p1bead4.png");
	p1bead5.loadFromFile("./p1bead5.png");
	p1bead6.loadFromFile("./p1bead6.png");
	p1bead7.loadFromFile("./p1bead7.png");
	p1bead8.loadFromFile("./p1bead8.png");
	p1bead9.loadFromFile("./p1bead9.png");
	p1bead10.loadFromFile("./p1bead10.png");
	p1bead11.loadFromFile("./p1bead11.png");
	p1bead12.loadFromFile("./p1bead12.png");
	p2bead0.loadFromFile("./p2bead0.png");
	p2bead1.loadFromFile("./p2bead1.png");
	p2bead2.loadFromFile("./p2bead2.png");
	p2bead3.loadFromFile("./p2bead3.png");
	p2bead4.loadFromFile("./p2bead4.png");
	p2bead5.loadFromFile("./p2bead5.png");
	p2bead6.loadFromFile("./p2bead6.png");
	p2bead7.loadFromFile("./p2bead7.png");
	p2bead8.loadFromFile("./p2bead8.png");
	p2bead9.loadFromFile("./p2bead9.png");
	p2bead10.loadFromFile("./p2bead10.png");
	p2bead11.loadFromFile("./p2bead11.png");
	p2bead12.loadFromFile("./p2bead12.png");
	Sprite bead0p1(p1bead0), bead1p1(p1bead1), bead2p1(p1bead2), bead3p1(p1bead3), bead4p1(p1bead4), bead5p1(p1bead5), bead6p1(p1bead6), bead7p1(p1bead7), bead8p1(p1bead8), bead9p1(p1bead9), bead10p1(p1bead10), bead11p1(p1bead11), bead12p1(p1bead12);
	bead0p1.setPosition(-20, -5);
	bead1p1.setPosition(-20, -5);
	bead2p1.setPosition(-20, -5);
	bead3p1.setPosition(-20, -5);
	bead4p1.setPosition(-20, -5);
	bead5p1.setPosition(-50, -5);
	bead6p1.setPosition(-20, -5);
	bead7p1.setPosition(0, 0);
	bead8p1.setPosition(-20, -5);
	bead9p1.setPosition(-20, -5);
	bead10p1.setPosition(-20, -5);
	bead11p1.setPosition(-20, -5);
	bead12p1.setPosition(-20, -5);
	Sprite bead0p2(p2bead0), bead1p2(p2bead1), bead2p2(p2bead2), bead3p2(p2bead3), bead4p2(p2bead4), bead5p2(p2bead5), bead6p2(p2bead6), bead7p2(p2bead7), bead8p2(p2bead8), bead9p2(p2bead9), bead10p2(p2bead10), bead11p2(p2bead11), bead12p2(p2bead12);
	bead0p2.setPosition(800, -2);
	bead1p2.setPosition(825, -30);
	bead2p2.setPosition(800, -20);
	bead3p2.setPosition(800, -20);
	bead4p2.setPosition(800, -20);
	bead5p2.setPosition(800, -20);
	bead6p2.setPosition(800, -20);
	bead7p2.setPosition(800, -20);
	bead8p2.setPosition(800, -2);
	bead9p2.setPosition(800, -10);
	bead10p2.setPosition(800, 0);
	bead11p2.setPosition(800, -10);
	bead12p2.setPosition(800, -10);
	Sprite board_(text), background(bckgrnd), follow(bgfollowup), start(button), main(menu), win1(p1chkwin), win2(p2chkwin), chkdraw(draw), play(again), buttonexit(exit), displayer(movecounter), resume(rbutton);
	resume.setScale(0.7, 0.7);
	resume.setPosition(325, 300);
	main.setPosition(150, 75);
	start.setPosition(350, 450);
	background.setScale(0.5, 0.5);
	background.setPosition(0, -905);
	follow.setScale(0.5, 0.5);
	follow.setPosition(0, 0);
	board_.setPosition(100, 100);
	win1.setScale(1.5, 1.5);
	win1.setPosition(200, 150);
	win2.setScale(1.5, 1.5);
	win2.setPosition(200, 150);
	chkdraw.setPosition(250, 200);
	play.setScale(0.7, 0.7);
	play.setPosition(350, 450);
	buttonexit.setPosition(350, 600);
	displayer.setPosition(400, 0);
	displayer.setScale(0.2, 0.2);
	Sprite beadp1[12], beadp2[12];
	SoundBuffer effect, starteffect, wineffect, action, music, effecteliminate;
	effecteliminate.loadFromFile("eliminationsound.mp3");
	music.loadFromFile("./backgroundmusic.mp3");
	wineffect.loadFromFile("./wineffect.mp3");
	effect.loadFromFile("./beadmovefast.mp3");
	starteffect.loadFromFile("./starteffect2.mp3");
	action.loadFromFile("./invalidaction.mp3");
	Sound sound, soundstart, winningeffect, invalid, bkgrnd, elimination;
	elimination.setBuffer(effecteliminate);
	bkgrnd.setBuffer(music);
	sound.setBuffer(effect);
	soundstart.setBuffer(starteffect);
	winningeffect.setBuffer(wineffect);
	invalid.setBuffer(action);
	for (int i = 0; i < 12; ++i) {
		beadp1[i].setTexture(BeadP1);
		beadp1[i].setScale(0.30, 0.30);
		beadp2[i].setTexture(BeadP2);
		beadp2[i].setScale(0.30, 0.30);
	}
	Vector2f positionsP1[] = {
		{5, 55}, {180, 55}, {360, 55}, {535, 55}, {720, 55},
		{5, 223}, {180, 223}, {360, 223}, {535, 223}, {720, 223},
		{5, 393}, {180, 393}
	};
	Vector2f positionsP2[] = {
		{720, 740}, {535, 740}, {360, 740}, {180, 740}, {5, 740},
		{720, 560}, {535, 560}, {360, 560}, {180, 560}, {5, 560},
		{720, 393}, {535, 393}
	};
	for (int i = 0; i < 12; ++i) {
		beadp1[i].setPosition(positionsP1[i]);
		beadp2[i].setPosition(positionsP2[i]);
	}
	bool isbeadselected = false, p1 = true, p2 = false, click2 = false, musicbg = false, toss = true;
	float bx = 0, by = 0;
	int x = 0, y = 0, x2 = 0, y2 = 0, n1 = 0, m1 = 0, n2 = 0, m2 = 0, posp1 = 0, posp2 = 0, p1_pieces = 12, p2_pieces = 12, winchk = 3, starting = 0, tem1 = -905, tem2 = 0;
	while (window.isOpen()) {
		Event evnt;
		if (starting == 1 && toss == 1) {
			if (coin_toss() == 1) {
				p1 = true;
				p2 = false;
			}
			else {
				p2 = true;
				p1 = false;
			}
			toss = 0;
		}
		if (starting == 1) {
			background.setPosition(0, tem1);
			tem1 += 0.01;
			if (tem1 == 0)
				tem1 = -905;
		}
		if (starting == 1) {
			follow.setPosition(0, tem2);
			tem2 += 1;
			if (tem2 == 905)
				tem2 = 0;
		}
		while (window.pollEvent(evnt)) {
			if (evnt.type == Event::Closed) {
				int storex = 0, storey = 0;
				ofstream p1pos, p2pos, beads_info, turn_info;
				p1pos.open("p1positions.txt");
				p2pos.open("p2positions.txt");
				beads_info.open("p1beads&p2beads.txt");
				turn_info.open("turn.txt");
				beads_info << p1_pieces << endl;
				beads_info << p2_pieces;
				turn_info << p1 << endl;
				turn_info << p2;
				for (int i = 0; i < 12; i++) {
					storex = beadp1[i].getPosition().x;
					storey = beadp1[i].getPosition().y;
					p1pos << storex << endl;
					p1pos << storey << endl;
				}
				for (int i = 0; i < 12; i++) {
					storex = beadp2[i].getPosition().x;
					storey = beadp2[i].getPosition().y;
					p2pos << storex << endl;
					p2pos << storey << endl;
				}
				p1pos.close();
				p2pos.close();
				beads_info.close();
				turn_info.close();
				window.close();
			}
			if (starting == 1 && musicbg == false) {
				bkgrnd.play();
				bkgrnd.setLoop(true);
				musicbg = true;
			}
			if (evnt.type == Event::MouseButtonPressed) {
				if (evnt.mouseButton.button == Mouse::Left) {
					Vector2f mpos = window.mapPixelToCoords({ evnt.mouseButton.x,evnt.mouseButton.y });
					if (play.getGlobalBounds().contains(mpos) && winchk != 3) {
						soundstart.play();
						winchk = 3;
						goto playagain;
					}
					if (buttonexit.getGlobalBounds().contains(mpos) && starting == 0) {
						soundstart.play();
						return 0;
					}
					if (resume.getGlobalBounds().contains(mpos) && starting == 0) {
						int setx = 0, sety = 0;
						ifstream setp1, setp2, beadsno, turns;
						setp1.open("p1positions.txt");
						setp2.open("p2positions.txt");
						beadsno.open("p1beads&p2beads.txt");
						turns.open("turn.txt");
						beadsno >> p1_pieces;
						beadsno >> p2_pieces;
						turns >> p1;
						turns >> p2;
						for (int i = 0; i < 12; i++) {
							setp1 >> setx;
							setp1 >> sety;
							beadp1[i].setPosition(setx, sety);
						}
						for (int i = 0; i < 12; i++) {
							setp2 >> setx;
							setp2 >> sety;
							beadp2[i].setPosition(setx, sety);
						}
						soundstart.play();
						starting = 1;
						goto start;
					}
					if (start.getGlobalBounds().contains(mpos) && starting == 0) {
						soundstart.play();
						starting = 1;
						goto start;
					}
					if (p1 == 1 && starting == 1) {
						Vector2f mousePos = window.mapPixelToCoords({ evnt.mouseButton.x, evnt.mouseButton.y });
						for (int i = 0; i < 12; i++) {
							if (beadp2[i].getGlobalBounds().contains(mousePos)) {
								invalid.play();
								cout << "Select Your Own Bead!" << endl;
								goto start;
							}
						}
						for (int i = 0; i < 12; i++) {
							if (beadp1[i].getGlobalBounds().contains(mousePos)) {
								isbeadselected = true;
								cout << "BeadSelected at: ";
								x = beadp1[i].getPosition().x;
								y = beadp1[i].getPosition().y;
								cout << x << " , " << y << endl;
								posp1 = i;
								goto start;
							}
						}
					}
					if (p2 == 1 && starting == 1) {
						Vector2f mousePosition = window.mapPixelToCoords({ evnt.mouseButton.x, evnt.mouseButton.y });
						for (int i = 0; i < 12; i++) {
							if (beadp1[i].getGlobalBounds().contains(mousePosition)) {
								invalid.play();
								cout << "Select Your Own Bead!" << endl;
								goto start;
							}
						}
						for (int i = 0; i < 12; i++) {
							if (beadp2[i].getGlobalBounds().contains(mousePosition)) {
								isbeadselected = true;
								cout << "BeadSelected at :";
								x = beadp2[i].getPosition().x;
								y = beadp2[i].getPosition().y;
								cout << x << " , " << y << endl;;
								posp2 = i;
								goto start;
							}
						}
					}
					click2 = true;
					if (p1 == 1) {
						if (click2 == true && isbeadselected == 1 && (t1.getGlobalBounds().contains(mpos) || t2.getGlobalBounds().contains(mpos) || t3.getGlobalBounds().contains(mpos) || t4.getGlobalBounds().contains(mpos) || t5.getGlobalBounds().contains(mpos) || t6.getGlobalBounds().contains(mpos) || t7.getGlobalBounds().contains(mpos) || t8.getGlobalBounds().contains(mpos) || t9.getGlobalBounds().contains(mpos) || t10.getGlobalBounds().contains(mpos) || t11.getGlobalBounds().contains(mpos) || t12.getGlobalBounds().contains(mpos) || t13.getGlobalBounds().contains(mpos) || t14.getGlobalBounds().contains(mpos) || t15.getGlobalBounds().contains(mpos) || t16.getGlobalBounds().contains(mpos) || t17.getGlobalBounds().contains(mpos) || t18.getGlobalBounds().contains(mpos) || t19.getGlobalBounds().contains(mpos) || t20.getGlobalBounds().contains(mpos) || t21.getGlobalBounds().contains(mpos) || t22.getGlobalBounds().contains(mpos) || t23.getGlobalBounds().contains(mpos) || t24.getGlobalBounds().contains(mpos) || t25.getGlobalBounds().contains(mpos))) {
							int tx = 0, ty = 0;
							if (t1.getGlobalBounds().contains(mpos)) {
								tx = t1.getPosition().x;
								ty = t1.getPosition().y;
							}
							if (t2.getGlobalBounds().contains(mpos)) {
								tx = t2.getPosition().x;
								ty = t2.getPosition().y;
							}
							if (t3.getGlobalBounds().contains(mpos)) {
								tx = t3.getPosition().x;
								ty = t3.getPosition().y;
							}
							if (t4.getGlobalBounds().contains(mpos)) {
								tx = t4.getPosition().x;
								ty = t4.getPosition().y;
							}
							if (t5.getGlobalBounds().contains(mpos)) {
								tx = t5.getPosition().x;
								ty = t5.getPosition().y;
							}
							if (t6.getGlobalBounds().contains(mpos)) {
								tx = t6.getPosition().x;
								ty = t6.getPosition().y;
							}
							if (t7.getGlobalBounds().contains(mpos)) {
								tx = t7.getPosition().x;
								ty = t7.getPosition().y;
							}
							if (t8.getGlobalBounds().contains(mpos)) {
								tx = t8.getPosition().x;
								ty = t8.getPosition().y;
							}
							if (t9.getGlobalBounds().contains(mpos)) {
								tx = t9.getPosition().x;
								ty = t9.getPosition().y;
							}
							if (t10.getGlobalBounds().contains(mpos)) {
								tx = t10.getPosition().x;
								ty = t10.getPosition().y;
							}
							if (t11.getGlobalBounds().contains(mpos)) {
								tx = t11.getPosition().x;
								ty = t11.getPosition().y;
							}
							if (t12.getGlobalBounds().contains(mpos)) {
								tx = t12.getPosition().x;
								ty = t12.getPosition().y;
							}
							if (t13.getGlobalBounds().contains(mpos)) {
								tx = t13.getPosition().x;
								ty = t13.getPosition().y;
							}
							if (t14.getGlobalBounds().contains(mpos)) {
								tx = t14.getPosition().x;
								ty = t14.getPosition().y;
							}
							if (t15.getGlobalBounds().contains(mpos)) {
								tx = t15.getPosition().x;
								ty = t15.getPosition().y;
							}
							if (t16.getGlobalBounds().contains(mpos)) {
								tx = t16.getPosition().x;
								ty = t16.getPosition().y;
							}
							if (t17.getGlobalBounds().contains(mpos)) {
								tx = t17.getPosition().x;
								ty = t17.getPosition().y;
							}
							if (t18.getGlobalBounds().contains(mpos)) {
								tx = t18.getPosition().x;
								ty = t18.getPosition().y;
							}
							if (t19.getGlobalBounds().contains(mpos)) {
								tx = t19.getPosition().x;
								ty = t19.getPosition().y;
							}
							if (t20.getGlobalBounds().contains(mpos)) {
								tx = t20.getPosition().x;
								ty = t20.getPosition().y;
							}
							if (t21.getGlobalBounds().contains(mpos)) {
								tx = t21.getPosition().x;
								ty = t21.getPosition().y;
							}
							if (t22.getGlobalBounds().contains(mpos)) {
								tx = t22.getPosition().x;
								ty = t22.getPosition().y;
							}
							if (t23.getGlobalBounds().contains(mpos)) {
								tx = t23.getPosition().x;
								ty = t23.getPosition().y;
							}
							if (t24.getGlobalBounds().contains(mpos)) {
								tx = t24.getPosition().x;
								ty = t24.getPosition().y;
							}
							if (t25.getGlobalBounds().contains(mpos)) {
								tx = t25.getPosition().x;
								ty = t25.getPosition().y;
							}
							if (x == 5)m1 = 0;
							if (x == 180)m1 = 1;
							if (x == 360)m1 = 2;
							if (x == 535)m1 = 3;
							if (x == 720)m1 = 4;
							if (y == 55)n1 = 0;
							if (y == 223)n1 = 1;
							if (y == 393)n1 = 2;
							if (y == 560)n1 = 3;
							if (y == 740)n1 = 4;
							if (tx == 80)m2 = 0;
							if (tx == 255)m2 = 1;
							if (tx == 435)m2 = 2;
							if (tx == 610)m2 = 3;
							if (tx == 795)m2 = 4;
							if (ty == 74)n2 = 0;
							if (ty == 243)n2 = 1;
							if (ty == 412)n2 = 2;
							if (ty == 579)n2 = 3;
							if (ty == 760)n2 = 4;
							if (m2 == 0)x2 = 5;
							if (m2 == 1)x2 = 180;
							if (m2 == 2)x2 = 360;
							if (m2 == 3)x2 = 535;
							if (m2 == 4)x2 = 720;
							if (n2 == 0)y2 = 55;
							if (n2 == 1)y2 = 223;
							if (n2 == 2)y2 = 393;
							if (n2 == 3)y2 = 560;
							if (n2 == 4)y2 = 740;
							bool chk_p1 = chk_move(beadp2, beadp1, n1, m1, n2, m2, x2, y2);
							if (chk_elimination_p1(p2_pieces, n1, m1, n2, m2, beadp2,chk_p1) == 0)
								chk_p1 = 0;
							if (chk_p1 == 0) {
								invalid.play();
								cout << "Move not possible!" << endl;
								isbeadselected = 0;
								goto start;
							}
							if (chk_elimination_p1(p2_pieces, n1, m1, n2, m2, beadp2,chk_p1) == 1)
								sound.play();
							else elimination.play();
							beadp1[posp1].setPosition(x2, y2);
							cout << "Bead Moved to : " << x2 << " , " << y2 << endl;
							winchk = chk_win(p1_pieces, p2_pieces);
							if (winchk != 3) {
								bkgrnd.stop();
								winningeffect.play();
								starting == 0;
							}
							p1 = 0;
							p2 = 1;
							isbeadselected = 0;
						}
					}
					if (p2 == 1) {
						if (click2 == true && isbeadselected == 1 && (t1.getGlobalBounds().contains(mpos) || t2.getGlobalBounds().contains(mpos) || t3.getGlobalBounds().contains(mpos) || t4.getGlobalBounds().contains(mpos) || t5.getGlobalBounds().contains(mpos) || t6.getGlobalBounds().contains(mpos) || t7.getGlobalBounds().contains(mpos) || t8.getGlobalBounds().contains(mpos) || t9.getGlobalBounds().contains(mpos) || t10.getGlobalBounds().contains(mpos) || t11.getGlobalBounds().contains(mpos) || t12.getGlobalBounds().contains(mpos) || t13.getGlobalBounds().contains(mpos) || t14.getGlobalBounds().contains(mpos) || t15.getGlobalBounds().contains(mpos) || t16.getGlobalBounds().contains(mpos) || t17.getGlobalBounds().contains(mpos) || t18.getGlobalBounds().contains(mpos) || t19.getGlobalBounds().contains(mpos) || t20.getGlobalBounds().contains(mpos) || t21.getGlobalBounds().contains(mpos) || t22.getGlobalBounds().contains(mpos) || t23.getGlobalBounds().contains(mpos) || t24.getGlobalBounds().contains(mpos) || t25.getGlobalBounds().contains(mpos))) {
							int tx = 0, ty = 0;
							if (t1.getGlobalBounds().contains(mpos)) {
								tx = t1.getPosition().x;
								ty = t1.getPosition().y;
							}
							if (t2.getGlobalBounds().contains(mpos)) {
								tx = t2.getPosition().x;
								ty = t2.getPosition().y;
							}
							if (t3.getGlobalBounds().contains(mpos)) {
								tx = t3.getPosition().x;
								ty = t3.getPosition().y;
							}
							if (t4.getGlobalBounds().contains(mpos)) {
								tx = t4.getPosition().x;
								ty = t4.getPosition().y;
							}
							if (t5.getGlobalBounds().contains(mpos)) {
								tx = t5.getPosition().x;
								ty = t5.getPosition().y;
							}
							if (t6.getGlobalBounds().contains(mpos)) {
								tx = t6.getPosition().x;
								ty = t6.getPosition().y;
							}
							if (t7.getGlobalBounds().contains(mpos)) {
								tx = t7.getPosition().x;
								ty = t7.getPosition().y;
							}
							if (t8.getGlobalBounds().contains(mpos)) {
								tx = t8.getPosition().x;
								ty = t8.getPosition().y;
							}
							if (t9.getGlobalBounds().contains(mpos)) {
								tx = t9.getPosition().x;
								ty = t9.getPosition().y;
							}
							if (t10.getGlobalBounds().contains(mpos)) {
								tx = t10.getPosition().x;
								ty = t10.getPosition().y;
							}
							if (t11.getGlobalBounds().contains(mpos)) {
								tx = t11.getPosition().x;
								ty = t11.getPosition().y;
							}
							if (t12.getGlobalBounds().contains(mpos)) {
								tx = t12.getPosition().x;
								ty = t12.getPosition().y;
							}
							if (t13.getGlobalBounds().contains(mpos)) {
								tx = t13.getPosition().x;
								ty = t13.getPosition().y;
							}
							if (t14.getGlobalBounds().contains(mpos)) {
								tx = t14.getPosition().x;
								ty = t14.getPosition().y;
							}
							if (t15.getGlobalBounds().contains(mpos)) {
								tx = t15.getPosition().x;
								ty = t15.getPosition().y;
							}
							if (t16.getGlobalBounds().contains(mpos)) {
								tx = t16.getPosition().x;
								ty = t16.getPosition().y;
							}
							if (t17.getGlobalBounds().contains(mpos)) {
								tx = t17.getPosition().x;
								ty = t17.getPosition().y;
							}
							if (t18.getGlobalBounds().contains(mpos)) {
								tx = t18.getPosition().x;
								ty = t18.getPosition().y;
							}
							if (t19.getGlobalBounds().contains(mpos)) {
								tx = t19.getPosition().x;
								ty = t19.getPosition().y;
							}
							if (t20.getGlobalBounds().contains(mpos)) {
								tx = t20.getPosition().x;
								ty = t20.getPosition().y;
							}
							if (t21.getGlobalBounds().contains(mpos)) {
								tx = t21.getPosition().x;
								ty = t21.getPosition().y;
							}
							if (t22.getGlobalBounds().contains(mpos)) {
								tx = t22.getPosition().x;
								ty = t22.getPosition().y;
							}
							if (t23.getGlobalBounds().contains(mpos)) {
								tx = t23.getPosition().x;
								ty = t23.getPosition().y;
							}
							if (t24.getGlobalBounds().contains(mpos)) {
								tx = t24.getPosition().x;
								ty = t24.getPosition().y;
							}
							if (t25.getGlobalBounds().contains(mpos)) {
								tx = t25.getPosition().x;
								ty = t25.getPosition().y;
							}
							if (x == 5)m1 = 0;
							if (x == 180)m1 = 1;
							if (x == 360)m1 = 2;
							if (x == 535)m1 = 3;
							if (x == 720)m1 = 4;
							if (y == 55)n1 = 0;
							if (y == 223)n1 = 1;
							if (y == 393)n1 = 2;
							if (y == 560)n1 = 3;
							if (y == 740)n1 = 4;
							if (tx == 80)m2 = 0;
							if (tx == 255)m2 = 1;
							if (tx == 435)m2 = 2;
							if (tx == 610)m2 = 3;
							if (tx == 795)m2 = 4;
							if (ty == 74)n2 = 0;
							if (ty == 243)n2 = 1;
							if (ty == 412)n2 = 2;
							if (ty == 579)n2 = 3;
							if (ty == 760)n2 = 4;
							if (m2 == 0)x2 = 5;
							if (m2 == 1)x2 = 180;
							if (m2 == 2)x2 = 360;
							if (m2 == 3)x2 = 535;
							if (m2 == 4)x2 = 720;
							if (n2 == 0)y2 = 55;
							if (n2 == 1)y2 = 223;
							if (n2 == 2)y2 = 393;
							if (n2 == 3)y2 = 560;
							if (n2 == 4)y2 = 740;
							bool chk_p2 = chk_move(beadp1, beadp2, n1, m1, n2, m2, x2, y2);
							if (chk_elimination_p2(p1_pieces, n1, m1, n2, m2, beadp1, chk_p2) == 0)
								chk_p2 = 0;
							if (chk_p2 == 0) {
								invalid.play();
								cout << "Move not possible!" << endl;
								isbeadselected = 0;
								goto start;
							}
							if (chk_elimination_p2(p1_pieces, n1, m1, n2, m2, beadp1, chk_p2) == 1)
								sound.play();
							else elimination.play();
							beadp2[posp2].setPosition(x2, y2);
							cout << "Bead Moved to : " << x2 << " , " << y2 << endl;
							winchk = chk_win(p1_pieces, p2_pieces);
							if (winchk != 3) {
								bkgrnd.stop();
								winningeffect.play();
								starting == 0;
							}
							p2 = false;
							p1 = true;
							isbeadselected = false;
						}
					}
				}
			}
		}
	start:
		if (starting == 0) {
			window.clear(Color::White);
			window.draw(resume);
			window.draw(main);
			window.draw(start);
			window.draw(buttonexit);
			window.display();
		}
		else {
			if (winchk == 1) {
				window.clear(Color::White);
				window.draw(win1);
				window.draw(play);
			}
			else if (winchk == 2) {
				window.clear(Color::White);
				window.draw(win2);
				window.draw(play);
			}
			else if (winchk == 0) {
				window.clear(Color::White);
				window.draw(chkdraw);
				window.draw(play);
			}
			else {
				window.clear();
				window.draw(background);
				window.draw(follow);
				window.draw(board_);
				if (p1 == true)
					window.draw(p1bead);
				if (p2 == true)
					window.draw(p2bead);
				window.draw(displayer);
				if (p1_pieces == 12)
					window.draw(bead12p1);
				if (p1_pieces == 11)
					window.draw(bead11p1);
				if (p1_pieces == 10)
					window.draw(bead10p1);
				if (p1_pieces == 9)
					window.draw(bead9p1);
				if (p1_pieces == 8)
					window.draw(bead8p1);
				if (p1_pieces == 7)
					window.draw(bead7p1);
				if (p1_pieces == 6)
					window.draw(bead6p1);
				if (p1_pieces == 5)
					window.draw(bead5p1);
				if (p1_pieces == 4)
					window.draw(bead4p1);
				if (p1_pieces == 3)
					window.draw(bead3p1);
				if (p1_pieces == 2)
					window.draw(bead2p1);
				if (p1_pieces == 1)
					window.draw(bead1p1);
				if (p1_pieces == 0)
					window.draw(bead0p1);
				if (p2_pieces == 12)
					window.draw(bead12p2);
				if (p2_pieces == 11)
					window.draw(bead11p2);
				if (p2_pieces == 10)
					window.draw(bead10p2);
				if (p2_pieces == 9)
					window.draw(bead9p2);
				if (p2_pieces == 8)
					window.draw(bead8p2);
				if (p2_pieces == 7)
					window.draw(bead7p2);
				if (p2_pieces == 6)
					window.draw(bead6p2);
				if (p2_pieces == 5)
					window.draw(bead5p2);
				if (p2_pieces == 4)
					window.draw(bead4p2);
				if (p2_pieces == 3)
					window.draw(bead3p2);
				if (p2_pieces == 2)
					window.draw(bead2p2);
				if (p2_pieces == 1)
					window.draw(bead1p2);
				if (p2_pieces == 0)
					window.draw(bead0p2);
				for (int i = 0; i < 12; ++i) {
					window.draw(beadp1[i]);
					window.draw(beadp2[i]);
				}
				window.draw(t1);
				window.draw(t2);
				window.draw(t3);
				window.draw(t4);
				window.draw(t5);
				window.draw(t6);
				window.draw(t7);
				window.draw(t8);
				window.draw(t9);
				window.draw(t10);
				window.draw(t11);
				window.draw(t12);
				window.draw(t13);
				window.draw(t14);
				window.draw(t15);
				window.draw(t16);
				window.draw(t17);
				window.draw(t18);
				window.draw(t19);
				window.draw(t19);
				window.draw(t20);
				window.draw(t21);
				window.draw(t22);
				window.draw(t23);
				window.draw(t24);
				window.draw(t25);
			}
			window.display();
		}
	}
}