#include<iostream>
//#include <stdlib.h>
#include <time.h>
#include<string>
#include<Windows.h>
//#include<conio.h>
using namespace std;

int shuffle(int cls[14][13]);
int printclass(int cls[14][13]);
int inputclass(int cls[2][250], int n);
int vot(int p1000[1000], int cls[2][250], int n);
int votcount(int p[1000], int cls[2][250],int n );
int votcountd(int p[1000], int cls[2][250],int n );
int cmdn(int p[1000], int cls[2][250], int n);
int cmd1( int mem[2][250], int  cls[14][13] ,int n);
int cmd2( int mem[2][250], int n);

int main() {

	//총 109명 당선자 번호  cls[0][i]==대의원 수  
	int class13[14][13] = {9,12,9,13,10,6,10,6,9,5,6,7,7};
	for (int i = 1; i < 14; i++) {
		for (int j = 0; j < 13; j++) {
			class13[i][j] = 0;
		}

	}

	//후보자 수 150~250  
	int n=200;
	//    0 = 대의원 반 1~13  1 = 투표수 
	int mamber[2][250];	

	// 투표자 투표번호
	int p1000[1000];

	

	while (1) {
		for (int i = 1; i < 14; i++) {
			for (int j = 0; j < 13; j++) {
				class13[i][j] = 0;
			}

		}
		for (int i = 0; i < 250; i++) {
			mamber[0][i] = 0;
			mamber[1][i] = 0;
		}
		cout << "대의원 후보 수 입력(150~250): ";
		ren:
		cin >> n;
		if (n < 150 || n>250) {
			cout << "다시 입력하세요." << endl;
			goto ren;
		}
		string cmd;

		inputclass(mamber, n);

		while (1) {
			cin >> cmd;

			if (cmd == "p") {
				cout << "명령어 p: " <<endl;
				shuffle(class13);
				printclass(class13);
				vot(p1000,mamber, n);
			}
			else if (cmd == "a") {
				votcount(p1000, mamber, n);
			}
			else if (cmd == "d") {
				votcountd(p1000, mamber, n);
			}
			else if (cmd == "m") {

				cmd1(mamber,class13, n);
			}
			else if (cmd == "n") {
				cmd2(mamber, n);
			}

			else if (cmd == "r") {
				break;
			}
			else if (cmd == "q") {
				break;
			}

			else {
				//int num = int(cmd) - '0';
				cmdn(p1000, mamber, stoi(cmd));
			}

		}
		if (cmd == "q") {
			break;
		}

	}
	
}

//대의원 수 분배
int shuffle(int cls[14][13]) {
	for (int i = 0; i < 13; i++) {
		srand(time(NULL));
		int ch;
		int ran = (rand() % 13);
		ch = cls[0][i];
		cls[0][i] = cls[0][ran];
		cls[0][ran] = ch;
	}
	return 0;
}
//대의원 수 출력
int printclass(int cls[14][13]) {
	for (int i = 0; i < 13; i++) {
		cout << i + 1 << "반 대의원 수: ";
		cout << cls[0][i] << endl;
	}
	return 0;
}
//대의원 후보 반 선정
int inputclass(int cls[2][250], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int ran = (rand() % 13);
		cls[0][i] = ran;
		cout << i + 1 << "번 - " << ran + 1 << "반" << endl;
	}
	return 0;
}
//투표
int vot(int p1000[1000], int cls[2][250],int n) {
	srand(time(NULL));
	
	for (int i = 0; i < 1000; i++) {
		
		int ran = (rand() % n);
		p1000[i] = ran;
		
	}
	for (int i = 0; i < 1000; i++) {
		cls[1][p1000[i]]++;
	}

	return 0;
}
//투표수 오름차순
int votcount(int p[1000], int cls[2][250], int n) {

	for (int j = 0; j < 13; j++) {
		cout << j + 1 << "반 후보자" << endl;
		for (int i = 0; i < n; i++) {
			
			//cout.width(3);
			if (cls[0][i] == j) {
				cout << "후보자 " << i + 1 << "번 득표수: " << cls[1][i] << endl;
			}
		}
	}
	return 0;
}
//투표수 내림차순
int votcountd(int p[1000], int cls[2][250], int n) {

	for (int j = 0; j < 13; j++) {
		cout << j+1 << "반 후보자" << endl;
		for (int i = n - 1; i >= 0; i--) {
			//cout.width(3);
			if (cls[0][i] == j) {
				cout << "후보자 " << i + 1 << "번  - 득표수: " << cls[1][i] << endl;
			}
		}
	}
	return 0;
}
//반 별로 당선된 의원 선출
int cmd1(int mem[2][250], int  cls[14][13], int n) {
	// 1 득표수 0 번호
	int win[2][250];
	int t = 0;
	for (int i = 0; i < n; i++) {
		win[1][i] = mem[1][i];
	}
	for (int i = 0; i < n; i++) {
		win[0][i] = i;
	}

	int ch;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (win[1][i] < win[1][j]) {

				ch = win[1][i];
				win[1][i] = win[1][j];
				win[1][j] = ch;

				ch = win[0][i];
				win[0][i] = win[0][j];
				win[0][j] = ch;
			}
		}
	}
	
	int a[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	
	for (int i = 0; i < 13; i++) {
		t = 0;
		for (int j = 1; j < cls[0][i] + 1; j++) {
			//1 2 3 4     6
			if (mem[0][win[0][t]] == i) {
				cls[j][i] = win[0][t];
				win[0][t] = -1;
				win[1][t] = -1;
				a[i]++;

			}
			else {
				j--;
			}
			
			t++;
			if (t == n-1) {
				t = 0;
				cout << i+1<<"버그체크" << a[i] << endl;
				i++;
			}
		}
	}

	t = 0;
	for (int i = 0; i < 13; i++) {
		for (int j = a[i]; j < cls[0][i] + 1; j++) {
			cls[j+1][i] = win[0][t];
			if (win[0][t] == -1) {
				j--;
			}
			t++;
			
		}
	}


	for (int i = 0; i < 13; i++) {
		cout << i + 1 << "반:" << endl;
		for (int j = 1; j < cls[0][i]+1; j++) {
			cout <<j << " : " << cls[j][i] +1 << "번 득표수: " << mem[1][cls[j][i]] << endl;
		}
	}

	return 0;
}
//다득표 순 대의원 뽑기
int cmd2(int mem[2][250], int n) {

	int win[2][250];
	int t = 0;
	for (int i = 0; i < n; i++) {
		win[1][i] = mem[1][i];
	}
	for (int i = 0; i < n; i++) {
		win[0][i] =i;
	}


	int ch;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (win[1][i] < win[1][j]) {
				ch = win[1][i];
				win[1][i] = win[1][j];
				win[1][j] = ch;

				ch = win[0][i];
				win[0][i] = win[0][j];
				win[0][j] = ch;

			}
		}
	}

	for (int i = 0; i < 109; i++) {
		cout << i+1<< ": 후보자 " <<win[0][i]+1<< "번 득표수: " << mem[1][win[0][i]] << endl;
	}

	return 0;
}
//1~1000번이 뽑은 대의원
int cmdn(int p[1000], int cls[2][250], int n) {
	cout << n << "번이 뽑은 대의원은 " << cls[0][p[n]]+1 << "반의" << p[n]+1 << "번 후보자 입니다."<<endl;
	return 0;
}