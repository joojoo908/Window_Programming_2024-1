#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<string>
using namespace std;

int inputnum(int pnum[5]);
int randmath(int math[4]);
int printord(int pnum[5], int math[4]);
int printmath(int math[4],int &i);
int cmd1(int pnum[5], int math[4]);
int cmd2(int pnum[5], int math[4]);
int cmd3(int pnum[5], int math[4]);

int main() {


	int pnum[5] = {5,5,5,5,5};
	int math[4];
	char a = 0;

	inputnum(pnum);
	randmath(math);
	printord(pnum, math);
	cout << endl;

	while (1) {
		cin >> a;
		if (a == '1') {
			cout << "명령어 1: ";
			printord(pnum, math);
			cmd1(pnum, math);
		}
		else if (a == '2') {
			cout << "명령어 2: ";
			printord(pnum, math);
			cmd2(pnum, math);
		}
		else if (a == '3') {
			cout << "명령어 3: ";
			printord(pnum, math);
			cmd3(pnum, math);
		}
		else if (a == '4') {
			cout << "명령어 4: ";
			inputnum(pnum);
			randmath(math);
			printord(pnum, math);
			cout << endl;
		}
		else if (a == 'q') {
			cout << "종료합니다. ";
			break;
		}
		else {
			cout << "없는 명령어 입니다." << endl;
		}
	}

	


}
//숫자 5개 입력
int inputnum(int pnum[5]) {
	cout << " 한자리에서 두자리 사이의 정수 5개를 입력하세요." << endl;
	int in;
	
	for (int i = 0; i < 5; i++) {
		while (1) {
			cin >> in;
			if (in > (-100) && in<100) {
				break;
			}
			else {
				cout << "다시 입력해 주세요" << endl;
			}
		}
		pnum[i] = in;
	}
	/*
	for (int i = 0; i < 5; i++) {
		cout << pnum[i];
	}
	*/

	return 0;
}
//연산자 출력
int printmath(int math[4], int& i) {
	if (math[i] == 0) {
		cout << "+";
	}
	else if (math[i] == 1) {
		cout << "-";
	}
	else if (math[i] == 2) {
		cout << "*";
	}
	else if (math[i] == 3) {
		cout << "/";
	}

	return 0;
	
}
//연산자 4개 뽑기 ( + - * / )
int randmath(int math[4]) {
	srand(time(NULL));
	
	for (int i = 0; i < 4; i++) {
		int m = (rand() % 4);
		math[i] = m;
	}

	for (int i = 0; i < 4; i++) {
		printmath(math, i);
	}
	cout<<endl;
	return 0;
}
//식 출력
int printord(int pnum[5], int math[4]) {
	cout << "식: ";
	for (int i = 0; i < 4;i++) {
		cout << pnum[i]<<" ";
		printmath(math,i);
		cout << " ";
	}
	cout << pnum[4];
	return 0;
}
// 우선순위대로 계산
int cmd1(int pnum[5], int math[4]) {
	int ans = 0;
	int mans[5] = { pnum[0],pnum[1], pnum[2], pnum[3], pnum[4] };
	int cmath[4] = {3, 3, 3, 3};
	int j = 0;
	int t = 0;
	//  1*2+3*4+5  >  mans 1+6    j2 i3   mans 2+12+5
	for (int i = 0; i < 4; i++) {
		if (math[i] == 0 || math[i] == 1) {
			
			cmath[t] = math[i];
			t++;
			j++;
			mans[j] = pnum[i+1];
		}
		else if (math[i] == 2 || math[i] == 3) {
			if (math[i] == 2) {
				ans = mans[j] * pnum[i + 1];
				mans[j] = ans;
				
			}
			else if (math[i] == 3) {
				ans = mans[j] / pnum[i + 1];
				mans[j] = ans;
			}
		}

	}
	//
	//cout << "ㅅㅂ" ;
	//printord(mans, cmath);
	ans = mans[0];
	for (int i = 0; i < j+1; i++) {
		if (cmath[i] == 0) {
			ans += mans[i + 1];
		}
		else if (cmath[i] == 1) {
			ans -= mans[i + 1];
		}
	}

	cout << " = " << ans << endl;
	return 0;
}
//순서대로 계산
int cmd2(int pnum[5], int math[4]) {
	int ans = pnum[0];
	for (int i = 0; i < 4; i++) {
		if (math[i] == 0) {
			ans += pnum[i + 1];
		}
		else if (math[i] == 1) {
			ans -= pnum[i + 1];
		}
		else if (math[i] == 2) {
			ans *= pnum[i + 1];
		}
		else if (math[i] == 3) {
			ans /= pnum[i + 1];
		}
	}
	cout << " = " << ans << endl;
	return 0;
}
// 역 순서대로 계산
int cmd3(int pnum[5], int math[4]) {
	int ans = pnum[4];
	for (int i = 0; i <4; i++) {
		if (math[3-i] == 0) {
			ans += pnum[3-i];
		}
		else if (math[3-i] == 1) {
			ans = pnum[3-i] - ans;
		}
		else if (math[3-i] == 2) {
			ans *= pnum[3-i];
		}
		else if (math[3-i] == 3) {
			ans = pnum[3-i] / ans;
		}
	}
	cout << " = " << ans << endl;
	return 0;
}