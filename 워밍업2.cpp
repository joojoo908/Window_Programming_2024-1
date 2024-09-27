#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define cnt 50

int printnum(int nums[cnt]);
int inputnum(int nums[cnt], int &a);
int cmda(int nums[cnt]);
int cmdd(int nums[cnt]);
int cmde(int nums[cnt]);
int cmdf(int nums[cnt]);
int cmdm(int nums[cnt]);
int cmdn(int nums[cnt]);

int main() {

	char a0;
	int n;
	int n50[cnt];
	int cn50[cnt];

	while (1) {
		cout << "100이상의 수를 입력해 주세요" << endl;
		cin >> n;
		if (n < 100) {
			cout << "다시 입력해 주세요." << endl;
		}
		else
			break;
	}
	inputnum(n50,n);
	printnum(n50);
	for (int i = 0; i < cnt; i++) {
		cn50[i] = n50[i];
	}
	

	while (1) {

		cin >> a0;
		
		if (a0 == 'a') {
			cout << "명령어 a:";
			cmda(n50);
			printnum(n50);
		}
		else if (a0 == 'd') {
			cout << "명령어 d:";
			cmdd(n50);
			printnum(n50);
		}
		else if (a0 == 'e') {
			cout << "명령어 e:";
			cmde(n50);
		}
		else if (a0 == 'f') {
			cout << "명령어 f:";
			cmdf(n50);
		}
		else if (a0 == 'm') {
			cout << "명령어 m:";
			cmdm(n50);
		}
		else if (a0 == 'n') {
			cout << "명령어 n:";
			cmdn(n50);
		}
		else if (a0 == 'r') {
			cout << "명령어 r:";
			
			inputnum(n50, n);
			for (int i = 0; i < cnt; i++) {
				n50[i] = cn50[i];
			}
			printnum(n50);
		}
		else if (a0 == 'p') {
			while (1) {
				cout << "100이상의 수를 입력해 주세요" << endl;
				cin >> n;
				if (n < 100) {
					cout << "다시 입력해 주세요." << endl;
				}
				else
					break;
			}
			
			inputnum(n50, n);
			printnum(n50);
			for (int i = 0; i < cnt; i++) {
				cn50[i] = n50[i];
			}
		}
		else if (a0 == 'q') {
			break;
		}
	
	}

	
}


// 숫자출력
int printnum(int nums[cnt]) {
	for (int i = 0; i < cnt; i++) {
		cout << nums[i] << "/";
	}
	cout << endl;
	return nums[cnt];
}

// 랜덤 수 뽑기
int inputnum(int nums[cnt], int &a) {
	srand(time(NULL));

	for (int i = 0; i < cnt; i++) {
		nums[i] = (rand() % (a-1))+1 ;
		for (int j = 0; j < i; j++) {
			if (nums[i] == nums[j]) {
				i--;
			}
		}
	}
	return nums[cnt];
}


//오른차순 정렬
int cmda(int nums[cnt]) {
	int ch;
	for (int i = 0; i < cnt; i++) {
		for (int j = i+1; j < cnt; j++) {
			if (nums[i] > nums[j]) {
				ch = nums[i];
				nums[i] = nums[j];
				nums[j] = ch;
			}
		}
	}
	

	return nums[cnt];
}

//내림차순 정렬
int cmdd(int nums[cnt]) {
	int ch;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt ; j++) {
			if (nums[i] < nums[j]) {
				ch = nums[i];
				nums[i] = nums[j];
				nums[j] = ch;
			}
		}
	}
	
	return nums[cnt];
}

//3의 배수 출력 후 합
int cmde(int nums[cnt]) {
	int plus=0;
	for (int i = 0; i < cnt; i++) {
		if (nums[i] % 3 == 0) {
			cout << nums[i] << "/";
			plus += nums[i];
		}

	}
	cout << "합" << plus << endl;

	return nums[cnt];
}

//5의배수 출력 후 합
int cmdf(int nums[cnt]) {
	int plus=0;
	for (int i = 0; i < cnt; i++) {
		if (nums[i] % 5 == 0) {
			cout << nums[i] << "/";
			plus += nums[i];
		}
	}
	cout << "합" << plus << endl;

	return nums[cnt];
}

//3의배수와 5의배수 그리고 +1
int cmdm(int nums[cnt]) {
	int plus = 0;
	for (int i = 0; i < cnt; i++) {
		if (nums[i] % 3 == 0 || nums[i] % 5 == 0) {
			cout << nums[i] << "/";
			plus += nums[i];
		}
		
	}
	cout << "->";
	for (int i = 0; i < cnt; i++) {
		
		if (nums[i] % 3 == 0 || nums[i] % 5 == 0) {
			cout << nums[i] + 1 << "/";
			plus += nums[i];
		}
	}

	cout << endl;

	return nums[cnt];
}

//3과5의 배수 그리고 -1
int cmdn(int nums[cnt]) {
	int plus = 0;
	for (int i = 0; i < cnt; i++) {
		if (nums[i] % 3 == 0 && nums[i] % 5 == 0) {
			cout << nums[i] << "/";
			plus += nums[i];
		}
		
	}
	cout << "->";
	for (int i = 0; i < cnt; i++) {
		
		if (nums[i] % 3 == 0 && nums[i] % 5 == 0) {
			cout << nums[i] - 1 << "/";
			plus += nums[i];
		}
	}
	cout << endl;

	return nums[cnt];
}