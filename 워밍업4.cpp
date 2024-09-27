#include<iostream>
//#include <stdlib.h>
#include <time.h>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

struct player {
	int color; //o x # $ @
	int x;
	int y;
};

int printmap(int map[10][10]);
int inputstone(int map[10][10], player a);
int changestone(player &a, player &b);
int player1move(int map[10][10],player &a, player& b, char &m);
int player2move(int map[10][10],player &a, player& b, char &m);


int main() {

	int map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
	
	player a = {1,5,5};
	player b = { 2,3,3 };
	char sq;
	goto game;
	while (1) {
		sq = _getch();

		if (sq == 's') {
			cout << "������ ���� �����մϴ�." << endl;
			Sleep(3000);
			game:
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					map[i][j] = 0;
				}
			}
			srand(time(NULL));
			a.x = (rand() % 10);
			a.y = (rand() % 10);
			while (1) {
				b.x = (rand() % 10);
				b.y = (rand() % 10);
				if (b.x == a.x && b.y == a.y) {

				}
				else break;
			}

			char cmd;
			int turn = 0;

			printmap(map);
			inputstone(map, a);
			inputstone(map, b);
			printmap(map);
			cout << "�÷��̾� 1 ����" << endl;

			//���ӽ���
			while (1) {
				cmd = _getch();
				if (turn == 0) {
					player1move(map, a, b, cmd);
					inputstone(map, a);
					printmap(map);
					if (b.x == a.x && b.y == a.y) {
						Beep(750, 300);
						cout << "�ڽ��ڴ� �÷��̾� 1��" << endl;
						break;
					}
					cout << "�÷��̾� 2 ����" << endl;
					turn++;
				}
				else if (turn == 1) {
					player2move(map, b, a, cmd);
					inputstone(map, b);
					printmap(map);
					if (b.x == a.x && b.y == a.y) {
						Beep(750, 300);
						cout << "�ڽ��ڴ� �÷��̾� 2��" << endl;
						break;
					}
					cout << "�÷��̾� 1 ����" << endl;
					turn--;
				}

			}
		}

		else if (sq == 'q') {
			cout << "������ �����մϴ�." << endl;
			break;
		}
		else {
			cout << "���� ��ɾ� �Դϴ�." << endl;
		}
	}
	


}
//�� ��� 
int printmap(int map[10][10]) {
	system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 0) {
				cout.width(2);
				cout << "+";
			}
			else if (map[i][j] == 1) {
				cout.width(2);
				cout << "o";
			}
			else if (map[i][j] == 2) {
				cout.width(2);
				cout << "x";
			}
			else if (map[i][j] == 3) {
				cout.width(2);
				cout << "#";
			}
			else if (map[i][j] == 4) {
				cout.width(2);
				cout << "$";
			}
			else if (map[i][j] == 5) {
				cout.width(2);
				cout << "@";
			}
		}
		cout << endl;
	}
	//Sleep(2000);
	return 0;
}
//�� ����
int inputstone(int map[10][10], player a) {

	map[a.y][a.x] = a.color;

	return 0;
}
//�� �ٲٱ�
int changestone(player& a, player& b) {
	srand(time(NULL));
	char ch = a.color;
	while (1) {
		a.color = (rand() % 5) + 1;
		if (b.color != a.color&&ch!=a.color) {
			break;
		}
	}
	return 0;
}
//�÷��̾� 1 ������
int player1move(int map[10][10], player &a, player& b, char& m) {
	f1:
	switch (m) {
	case 'w':
		map[a.y][a.x] = 0;
		a.y -= 1;
		if (a.y <= -1) {
			a.y = 9;
			changestone(a, b);
		}
		break;
	case 'a':
		map[a.y][a.x] = 0;
		a.x -= 1;
		if (a.x <= -1) {
			a.x = 9;
			changestone(a, b);
		}
		break;
	case 's':
		map[a.y][a.x] = 0;
		a.y += 1;
		if (a.y > 9) {
			a.y = 0;
			changestone(a, b);
		}
		break;
	case 'd':
		map[a.y][a.x] = 0;
		a.x += 1;
		if (a.x > 9) {
			a.x = 0;
			changestone(a, b);
		}
		break;

	default:
		cout << "�ٽ� �Է��ϼ���." << endl;
		m = _getch();
		goto f1;
		break;
	}



	return 0;

}
//�÷��̾� 2 ������
int player2move(int map[10][10], player& a, player& b, char& m) {
	f1:
	switch (m) {
	case 'i':
		map[a.y][a.x] = 0;
		a.y -= 1;
		if (a.y <= -1) {
			a.y = 9;
			changestone(a, b);
		}
		break;
	case 'j':
		map[a.y][a.x] = 0;
		a.x -= 1;
		if (a.x <= -1) {
			a.x = 9;
			changestone(a, b);
		}
		break;
	case 'k':
		map[a.y][a.x] = 0;
		a.y += 1;
		if (a.y > 9) {
			a.y = 0;
			changestone(a, b);
		}
		break;
	case 'l':
		map[a.y][a.x] = 0;
		a.x += 1;
		if (a.x > 9) {
			a.x = 0;
			changestone(a, b);
		}
		break;
	default:
		cout << "�ٽ� �Է��ϼ���." << endl;
		m = _getch();
		goto f1;
		break;
	}


	return 0;

}
