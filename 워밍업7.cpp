#include<iostream>
//#include <stdlib.h>
#include <time.h>
#include<string>
#include<Windows.h>
//#include<conio.h>
using namespace std;

struct ball
{
	string name;
	double size;
	int subball;
	int spin1;
	double spin2; //일 기준

	double spin1speed; //km/s
	double pi;
	double km; //만 km

};

int cmdp(ball space[8]);
int cmda(ball space[8]);
int cmdb(ball space[8]);
int cmdc(ball space[8]);
int cmdc2(ball space[8]);
int cmdd(ball space[8]);
int cmde(ball space[8]);

int main() {

	// 0 수성,  1 금성,  2 지구, 3 화성, 4 목성, 5 토성, 6 천왕성, 7 해왕성
	// 0 이름 1 반지름, 2 위성의 개수, 3 공전 주기, 4 자전 주기, 5 공전 속도, 6 기울기, 7 태양과의 거리

	ball a0 = { "수성",3.83, 0, 88 ,58.66 , 47.36, 0.04, 5790};
	ball a1 = { "금성", 9.5, 0, 225 , -243 , 35.02, 177, 10827};
	ball a2 = { "지구", 10, 1, 365, 1, 29.76, 23.5, 14960};
	ball a3 = { "화성",5.32, 2, 687 , 1.02 , 24.077, 25, 22739};
	ball a4 = { "목성",109.7, 95 , 4015, 0.41 , 13.056, 3, 77792};
	ball a5 = { "토성",91.4, 145 , 10585, 0.43 , 9.639, 26.7, 143018};
	ball a6 = { "천왕성",39.8 , 27, 30660, -0.71, 6.795, 98, 286933};
	ball a7 = { "해왕성",38.7, 16, 60225, 0.67, 5.43, 28, 450745};

	ball space[8] = { a0,a1,a2,a3,a4,a5,a6,a7 };
	

	
	char a;
	while (1) {
		cout << "명령어를 입력하세요." << endl;
		cin >> a;
		if (a == 'p') {
			cmdp(space);
		}
		else if (a == 'a') {
			cmda(space);
		}
		else if (a == 'b') {
			cmdb(space);
		}
		else if (a == 'c') {
			cmdc2(space);
		}
		else if (a == 'd') {
			cmdd(space);
		}
		else if (a == 'e') {
			cmde(space);
		}
		else if (a == 'q') {
			break;
		}
		else {
			cout << "없는 명령어 입니다." << endl;
		}
	}

}
// 행성 데이터 출력
int cmdp(ball space[8]) {
	cout << "명령어 p :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << space[i].name << endl;
		cout << "반지름 : " << space[i].size << endl;
		cout << "위성의 갯수 : " << space[i].subball << "개" << endl;
		cout << "공전 주기 : " << space[i].spin1 << "일" << endl;
		cout << "자전 주기 : " << space[i].spin2 << "일" << endl;
		cout << "공전 속도 : " << space[i].spin1speed << "km/s" << endl;
		cout << "기울기 : " << space[i].pi << "도" << endl; 
		cout << "태양과의 거리 : " << space[i].km << "만km" << endl;
		cout << endl;
	}

	return 0;
}
//공전속도 오름차
int cmda(ball space[8]) {
	ball copy[8];
	for (int i = 0; i < 8; i++) {
		copy[i]=space[i];
	}
	ball ch;
	for (int i=0; i < 8; i++) {
		for (int j = i+1; j < 8; j++) {
			if (copy[i].spin1speed > copy[j].spin1speed) {
				ch.name = copy[i].name;
				copy[i].name = copy[j].name;
				copy[j].name = ch.name;

				ch.spin1speed = copy[i].spin1speed;
				copy[i].spin1speed = copy[j].spin1speed;
				copy[j].spin1speed = ch.spin1speed;
			}
		}
	}

	cout << "명령어 a :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << endl;
		
	}

	return 0;
}
//행성크기 내림차
int cmdb(ball space[8]) {
	ball copy[8];
	for (int i = 0; i < 8; i++) {
		copy[i] = space[i];
	}
	ball ch;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (copy[i].size < copy[j].size) {
				ch.name = copy[i].name;
				copy[i].name = copy[j].name;
				copy[j].name = ch.name;

				ch.size = copy[i].size;
				copy[i].size = copy[j].size;
				copy[j].size = ch.size;
			}
		}
	}

	cout << "명령어 b :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << endl;

	}

	return 0;
}
// 행성간 거리 출력
int cmdc(ball space[8]) {
	

	//string ballkm1[36];
	//int ballkm2[36];

	//for(int i=0;i<8;i++)

	cout << "명령어 c :" << endl;

	cout <<  "태양 ~ " << space[0].name << ":" << space[0].km  << "만km" << endl;
	for (int i = 0; i < 7; i++) {
		cout << space[i].name<< " ~ " << space[i+1].name << ": " << space[i+1].km - space[i].km <<"만km" << endl;
		
	}

	return 0;
}
int cmdc2(ball space[8]) {

	string s1[8];
	int s2[8];
	string ch1;
	int ch2;

	s1[0] = "태양 ~ " + space[0].name;
	s2[0] = space[0].km;
	for (int i = 1; i < 8; i++) {
		s1[i] = space[i - 1].name + "~" + space[i].name;
		s2[i] = space[i ].km - space[i-1].km;

	}
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 8; j++) {
			if (s2[i] < s2[j]) {
				ch2 = s2[i];
				s2[i] = s2[j];
				s2[j] = ch2;

				ch1 = s1[i];
				s1[i] = s1[j];
				s1[j] = ch1;

			}
		}
	}


	cout << "명령어 c :" << endl;

	
	for (int i = 0; i < 8; i++) {
		cout << s1[i] << ": " << s2[i] << "만km" << endl;

	}

	return 0;
}
// 자전 주기 시간화
int cmdd(ball space[8]) {
	

	cout << "명령어 d :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << space[i].name << " 의 자전 주기는  " << space[i].spin2 * 24 << "시간" << endl;

	}

	return 0;
}
//기울기 오름차
int cmde(ball space[8]) {
	ball copy[8];
	for (int i = 0; i < 8; i++) {
		copy[i] = space[i];
	}
	ball ch;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (copy[i].pi > copy[j].pi) {
				ch.name = copy[i].name;
				copy[i].name = copy[j].name;
				copy[j].name = ch.name;

				ch.pi = copy[i].pi;
				copy[i].pi = copy[j].pi;
				copy[j].pi = ch.pi;
			}
		}
	}

	cout << "명령어 e :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << " 기울기: " << copy[i].pi << endl;

	}

	return 0;
}
