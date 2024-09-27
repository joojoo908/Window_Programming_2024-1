#include<iostream>
#include <time.h>
#include<string>
#include<Windows.h>
#include<conio.h>
using namespace std;

struct player {
	
	int color; 
	int x;
	int y;
	int movcnt;
};

int printmap(int map[7][7]);
int yut(int& i, int& turn, int i2[10], int& yutcnt);
int player1move(int map[7][7], player& a,  player& b ,int& m, int &turn, int i2[10], int& yutcnt);


int main() {
	char g;
	while (1) {
		cout << "게임을 시작하시겠습니까? (시작 s , 종료 q)" << endl;
		re:
		g = _getch();
		if (g == 's') {
			cout << "게임을 시작합니다." << endl;
		}
		else if (g == 'q') {
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else {
			cout << "없는 명령어 입니다." << endl;
			goto re;
		}

		int map[7][7];
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {

				map[i][j] = 1;
			}
		}
		for (int i = 0; i < 7; i++) {
			map[3][i] = 0;
			map[i][3] = 0;
		}
		for (int i = 2; i < 5; i += 2) {
			map[1][i] = 0;
			map[i][1] = 0;
			map[5][i] = 0;
			map[i][5] = 0;
		}
		map[3][3] = 1;

		printmap(map);
		int m; //윷 값
		int ms[10] = { 0,0,0,0,0,0,0,0,0,0 };
		int yutcount = 0;

		player a = { 2,6,0,0 };
		player b = { 3,6,0,0 };
		int turn = 0;

		while (1) {
			yut(m, turn, ms, yutcount);
			player1move(map, a, b, m, turn, ms, yutcount);
			yut(m, turn, ms, yutcount);
			player1move(map, b, a, m, turn, ms, yutcount);
			if (turn == -1) {
				break;
			}
		}

	}

}
//맵 출력 
int printmap(int map[7][7]) {
	system("cls");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (map[i][j] == 0) {
				cout.width(2);
				cout << "  ";
			}
			else if (map[i][j] == 1) {
				cout.width(2);
				cout << "□";
			}
			else if (map[i][j] == 2) {
				cout.width(2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
				cout << "■";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (map[i][j] == 3) {
				cout.width(2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << "■";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
		}
		cout << endl;
	}
	//Sleep(2000);
	return 0;
}
//윷 굴리기
int yut(int& i , int & turn, int i2[10], int &yutcnt) {
	srand(time(NULL));
	/*
	if (yutcnt >= 0) {
		if (turn % 2 == 0) {
			cout << "플레이어 1의 차례" << endl;
			char cmd;
			cout << "윳 굴리기" << endl;
			p1:
			cmd = _getch();
			if (cmd == '1') {
				i2[yutcnt] = (rand() % 5) + 1;
				yutcnt++;
			}
			else {
				cout << "다시 굴리세요" << endl;
				goto p1;
			}

			if (i2[yutcnt-1] == 1) {
				cout << "도" << endl;
			}
			else if (i2[yutcnt-1] == 2) {
				cout << "개" << endl;
			}
			else if (i2[yutcnt-1] == 3) {
				cout << "걸" << endl;
			}
			else if (i2[yutcnt-1] == 4) {
				cout << "윷" << endl;
				cout << "다시 굴리세요" << endl;
				yut(i2[yutcnt], turn, i2, yutcnt);
				//yutcnt++;
			}
			else if (i2[yutcnt-1] == 5) {
				cout << "모" << endl;
				cout << "다시 굴리세요" << endl;
				yut(i2[yutcnt], turn, i2, yutcnt);
				
			}
			Sleep(1000);
		}

		else if (turn % 2 == 1) {
			cout << "플레이어 2의 차례" << endl;
			char cmd;
			cout << "윳 굴리기" << endl;
		p2:
			cmd = _getch();
			if (cmd == '2') {
				i2[yutcnt] = (rand() % 5) + 1;
				yutcnt++;
			}
			else {
				cout << "다시 굴리세요" << endl;
				goto p2;
			}

			if (i2[yutcnt-1] == 1) {
				cout << "도" << endl;
			}
			else if (i2[yutcnt-1] == 2) {
				cout << "개" << endl;
			}
			else if (i2[yutcnt-1] == 3) {
				cout << "걸" << endl;
			}
			else if (i2[yutcnt-1] == 4) {
				cout << "윷" << endl;
				cout << "다시 굴리세요" << endl;
				yut(i2[yutcnt], turn, i2, yutcnt);
				//yutcnt++;
			}
			else if (i2[yutcnt-1] == 5) {
				cout << "모" << endl;
				cout << "다시 굴리세요" << endl;
				yut(i2[yutcnt], turn, i2, yutcnt);
				
			}
			Sleep(1000);
		}
	}
	*/
	
	if (turn%2 == 0) {
		cout << "플레이어 1의 차례" << endl;
		char cmd;
		cout << "윳 굴리기" << endl;
		p3:
		cmd = _getch();
		if (cmd == '1') {
			i = (rand() % 5) + 1;
			//yutcnt++;
		}
		else {
			cout << "다시 굴리세요" << endl;
			goto p3;
		}

		if (i == 1) {
			cout << "도" << endl;
		}
		else if (i == 2) {
			cout << "개" << endl;
		}
		else if (i == 3) {
			cout << "걸" << endl;
		}
		else if (i == 4) {
			cout << "윷" << endl;
			cout << "다시 굴리세요" << endl;
			yut(i2[yutcnt], turn, i2,yutcnt);
			yutcnt++;
		}
		else if (i == 5) {
			cout << "모" << endl;
			cout << "다시 굴리세요" << endl;
			yut(i2[yutcnt], turn, i2, yutcnt);
			yutcnt++;
		}
		Sleep(1000);
	}

	else if (turn%2 == 1) {
		cout << "플레이어 2의 차례" << endl;
		char cmd;
		cout << "윳 굴리기" << endl;
	    p4:
		cmd = _getch();
		if (cmd == '2') {
			i = (rand() % 5) + 1;
			//yutcnt++;
		}
		else {
			cout << "다시 굴리세요" << endl;
			goto p4;
		}

		if (i == 1) {
			cout << "도" << endl;
		}
		else if (i == 2) {
			cout << "개" << endl;
		}
		else if (i == 3) {
			cout << "걸" << endl;
		}
		else if (i == 4) {
			cout << "윷" << endl;
			cout << "다시 굴리세요" << endl;
			yut(i2[yutcnt], turn, i2, yutcnt);
			yutcnt++;
		}
		else if (i == 5) {
			cout << "모" << endl;
			cout << "다시 굴리세요" << endl;
			yut(i2[yutcnt], turn, i2, yutcnt);
			yutcnt++;
		}
		Sleep(1000);
	}
	
	

	return 0;
}


//플레이어 1 움직임
int player1move(int map[7][7], player& a,  player& b, int & m ,int &turn, int i2[10], int& yutcnt) {
	int cnt = m;
	//int cnt = i2[0];
	//m = i2[0];
	int clor=0;
	int eat=0;
	int live = 0;
	
	if (a.color == 2) {
		map[a.x][a.y] = 2;
		clor = 2;
		eat = 3;
	}
	else if (a.color == 3) {
		map[a.x][a.y] = 3;
		clor = 3;
		eat = 2;
	}
	////////////////////////////////////////////////////////////////////
	
	char move;
	printmap(map);
	remove2:
	for (int i = 0; i < m; i++) {
		remove:
		cout << "남은 움직임" << cnt << endl;
		
		move = _getch();
		
		// ->
		if (move=='d') {
			if (a.x == 6) {
				if (a.y == 0 || a.y == 1 || a.y == 2 || a.y == 4 || a.y == 5) {
					if (a.y == 0 && a.movcnt > 1) {
						cout << "승자는 플레이어" << a.color - 1 << endl;
						turn = -1;
						return 0;
					}


					if (live == 1) {
						map[a.x][a.y] = eat;
						live--;
					}
					else {
						map[a.x][a.y] = 1;
					}

					a.y += 1;
					if (a.y == 3) {
						a.y += 1;
					}
					a.movcnt += 1;
					cnt--;

					if (map[a.x][a.y] == eat) {
						if (cnt == 0) {
							
							map[b.x][b.y] = 1;
							printmap(map);
							cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
							b.movcnt = 0;
							b.x = 6;
							b.y = 0;
							yut(i2[yutcnt], turn, i2, yutcnt);
							yutcnt++;
						}
						else {
							live++;
						}
					}
					map[a.x][a.y] = clor;
					printmap(map);
				}
				else {
					cout << "불가능한 움직임 입니다." << endl;
					
					goto remove;
				}

			}
			
			
			

		}
		// ↑
		else if (move == 'w') {
			if (a.y == 6) {
				if (a.x == 6 || a.x == 1 || a.x == 2 || a.x == 4 || a.x == 5) {

					if (live == 1) {
						map[a.x][a.y] = eat;
						live--;
					}
					
					else {
						map[a.x][a.y] = 1;
					}

					a.x -= 1;
					if (a.x == 3) {
						a.x -= 1;
					}
					a.movcnt++;
					cnt--;

					if (map[a.x][a.y] == eat) {
						if (cnt == 0) {
							map[b.x][b.y] = 1;
							printmap(map);
							cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
							b.movcnt = 0;
							b.x = 6;
							b.y = 0;
							yut(i2[yutcnt], turn, i2, yutcnt);
							yutcnt++;
						}
						else {
							live++;
						}
					}
					map[a.x][a.y] = clor;
					printmap(map);
				}
				else {
					cout << "불가능한 움직임 입니다." << endl;
					
					goto remove;
				}

			}



		}
		// <-
		else if (move == 'a') {
			if (a.x == 0) {
				if (a.y == 6 || a.y == 1 || a.y == 2 || a.y == 4 || a.y == 5) {

					if (live == 1) {
						map[a.x][a.y] = eat;
						live--;
					}

					else {
						map[a.x][a.y] = 1;
					}

					a.y -= 1;
					if (a.y == 3) {
						a.y -= 1;
					}
					a.movcnt++;
					cnt--;

					if (map[a.x][a.y] == eat) {
						if (cnt == 0) {
							map[b.x][b.y] = 1;
							printmap(map);
							cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
							b.movcnt = 0;
							b.x = 6;
							b.y = 0;
							yut(i2[yutcnt], turn, i2, yutcnt);
							yutcnt++;
						}
						else {
							live++;
						}


					}
					map[a.x][a.y] = clor;
					printmap(map);
				}
				else {
					cout << "불가능한 움직임 입니다." << endl;
					
					goto remove;
				}

			}



		}
		// ↓
		else if (move == 's') {
			if (a.y == 0) {
				if (a.x == 0 || a.x == 1 || a.x == 2 || a.x == 4 || a.x == 5) {

					if (live == 1) {
						map[a.x][a.y] = eat;
						live--;
					}

					else {
						map[a.x][a.y] = 1;
					}

					a.x += 1;
					if (a.x == 3) {
						a.x += 1;
					}
					a.movcnt++;
					cnt--;

					if (map[a.x][a.y] == eat) {
						if (cnt == 0) {
							map[b.x][b.y] = 1;
							printmap(map);
							cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
							b.movcnt = 0;
							b.x = 6;
							b.y = 0;
							yut(i2[yutcnt], turn, i2, yutcnt);
							yutcnt++;
						}
						else {
							live++;
						}


					}
					map[a.x][a.y] = clor;
					printmap(map);
				}
				else {
					cout << "불가능한 움직임 입니다." << endl;
					
					goto remove;
				}

			}



			}
		// ↖
		else if (move == 'q') {
			for (int j = 1; j < 7;j++) {
				if (a.y == j) {
					if (a.x == j) {
						if (a.x == 6 && a.y == 6) {
							if (cnt != m) {
								cout << "불가능한 움직임 입니다." << endl;
								
								goto remove;
							}
						}
						if (a.x == 3 && a.y == 3) {
							if (cnt != m) {
								cout << "불가능한 움직임 입니다." << endl;
								
								goto remove;
							}
						}

						if (live == 1) {
							map[a.x][a.y] = eat;
							live--;
						}

						else {
							map[a.x][a.y] = 1;
						}

						a.x -= 1;
						a.y -= 1;
						
						a.movcnt++;
						cnt--;

						if (map[a.x][a.y] == eat) {
							if (cnt == 0) {
								map[b.x][b.y] = 1;
								printmap(map);
								cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
								b.movcnt = 0;
								b.x = 6;
								b.y = 0;
								yut(i2[yutcnt], turn, i2, yutcnt);
								yutcnt++;
							}
							else {
								live++;
							}


						}
						map[a.x][a.y] = clor;
						printmap(map);
					}
					else {
						cout << "불가능한 움직임 입니다." << endl;
						
						goto remove;
					}

				}

			}
		}
		// ↙
		else if (move == 'z') {
			for (int j = 1; j<7 ; j++) {
				if (a.y == j) {
					if (a.x == 6-j) {
						if (a.y == 6 && a.x == 0) {
							if (cnt != m) {
								cout << "불가능한 움직임 입니다." << endl;
								
								goto remove;
							}
						}

						if (live == 1) {
							map[a.x][a.y] = eat;
							live--;
						}

						else {
							map[a.x][a.y] = 1;
						}

						a.x += 1;
						a.y -= 1;

						a.movcnt++;
						cnt--;

						if (map[a.x][a.y] == eat) {
							if (cnt == 0) {
								map[b.x][b.y] = 1;
								printmap(map);
								cout << "잡았습니다! 윷을 다시 굴리세요." << endl;
								b.movcnt = 0;
								b.x = 6;
								b.y = 0;
								yut(i2[yutcnt], turn, i2, yutcnt);
								yutcnt++;
							}
							else {
								live++;
							}


						}
						map[a.x][a.y] = clor;
						printmap(map);
					}
					else {
						cout << "불가능한 움직임 입니다." << endl;
						
						goto remove;
					}

				}

			}
			}
		///////////////
		if (cnt == 0) {
			if (yutcnt>0) {
				m = i2[0];
				for (int k = 0; k < 9; k++) {
					i2[k] = i2[k + 1];
				}
				i2[10] = 0;
				yutcnt--;
				cout << "ㅁㅁㅁㅁ" << yutcnt << endl;
				cnt = m;
				goto remove2;
			}
			else {
				turn++;
			}
		}

		

		//


	}

	return 0;

}

