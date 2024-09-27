#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define cnt 50

int ch2d(int num20[20], int nums[4][5]);
int ch1d(int num20[20], int nums[4][5]);
int inputnum(int nums[4][5]);
int printnum(int nums[4][5]);
int savenum(int mnums[4][5], int snums[4][5]);
int cmda(int nums[4][5], int snums[4][5],int &ck);
int cmdd(int nums[4][5], int snums[4][5],int &ck);
int cmde(int nums[4][5], int snums[4][5],int &ck);
int cmdo(int nums[4][5], int snums[4][5],int &ck);
int cmdm(int nums[4][5], int snums[4][5],int &ck);
int cmdn(int nums[4][5], int snums[4][5],int &ck);
int cmdp(int nums[4][5], int snums[4][5],int &ck);
int cmdu(int nums[4][5], int snums[4][5],int &ck);
int cmdr(int nums[4][5], int snums[4][5],int &ck);
int clearnum(int num[9], char &a);

int main() {
	int mnum[4][5];
	int snum[4][5];
	int rnum[9] = {0,0,0,0,0,0,0,0,0};

	char cmd;

	inputnum(mnum);
	cout << "행렬값:" << endl;
	printnum(mnum);

	while (1) {
		cin >> cmd;
		if (cmd == 'a') {
			cmda(mnum, snum, rnum[0]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'd') {
			cmdd(mnum, snum, rnum[1]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'e') {
			cmde(mnum, snum, rnum[2]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'o') {
			cmdo(mnum, snum, rnum[3]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'm') {
			cmdm(mnum, snum, rnum[4]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'n') {
			cmdn(mnum, snum, rnum[5]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'p') {
			cmdp(mnum, snum, rnum[6]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'u') {
			cmdu(mnum, snum, rnum[7]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 'r') {
			cmdr(mnum, snum, rnum[8]);
			clearnum(rnum, cmd);
		}
		else if (cmd == 's') {
			inputnum(mnum);
			cout << "행렬값:" << endl;
			printnum(mnum);
		}
		else if (cmd == 'q') {
			cout << "종료합니다." << endl;
			break;
		}
	}

	
}

//2차원 배열 1차원으로
int ch1d(int num20[20],int nums[4][5]) {
	
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			num20[k]=nums[i][j];
			k++;
			
		}
	}
	return 0;
}
//1차원 배열 2차원으로
int ch2d(int num20[20], int nums[4][5]) {

	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			nums[i][j] = num20[k];
			k++;
		}
	}
	return 0;
}
//랜덤숫자배정
int inputnum(int nums[4][5]) {
	srand(time(NULL));

	int num20[20];
	for (int i = 0; i < 20; i++) {
		num20[i] = (rand() % 49) + 1;
		for (int j = 0; j < i; j++) {
			if (num20[i] == num20[j]) {
				i--;
			}
		}
	}
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			nums[i][j] = num20[k];
			k++;
			
		}
	}
	return 0;
}
// 배열 출력
int printnum(int nums[4][5]) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			
			cout.width(15);
			cout<< nums[i][j];
		}
		cout << endl;
	}
	return 0;
}
//배열 세이브
int savenum(int mnums[4][5], int snums[4][5]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			snums[i][j] = mnums[i][j];
		}
		
	}
	return 0;
}
//오름차순 정렬
int cmda(int nums[4][5], int snums[4][5], int &ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;

		int ch;
		int num20[20];
		ch1d(num20, nums);

		for (int i = 0; i < 20; i++) {
			for (int j = i + 1; j < 20; j++) {
				if (num20[i] > num20[j]) {
					ch = num20[i];
					num20[i] = num20[j];
					num20[j] = ch;
				}
			}
		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout <<"명령어 a:"<< endl;
	printnum(nums);
	return 0;
}
//내림차순 정렬
int cmdd(int nums[4][5], int snums[4][5], int &ck) {
	
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		int ch;
		int num20[20];
		ch1d(num20, nums);

		for (int i = 0; i < 20; i++) {
			for (int j = i + 1; j < 20; j++) {
				if (num20[i] > num20[j]) {
					ch = num20[i];
					num20[i] = num20[j];
					num20[j] = ch;
				}
			}
		}

		int k = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 3; j >= 0; j--) {
				nums[j][i] = num20[k];
				k++;
			}
		}
	}

	else {
		savenum(snums, nums);
		ck--;
	}
	cout << "명령어 d:" << endl;
	printnum(nums);
	return 0;
}
//짝수만 출력
int cmde(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		int ch;
		int num20[20];
		ch1d(num20, nums);

		for (int i = 0; i < 20; i++) {
			
			if (num20[i] %2== 1) {	
				num20[i] = 0;		
			}
			
		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 e:" << endl;
	printnum(nums);
	return 0;
}
//홀수만 출력
int cmdo(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		int ch;
		int num20[20];
		ch1d(num20, nums);

		for (int i = 0; i < 20; i++) {

			if (num20[i] % 2 == 0) {
				num20[i] = 0;
			}

		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 o:" << endl;
	printnum(nums);
	return 0;
}
//최댓값++
int cmdm(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		int ch;
		int num20[20];
		int max;

		//cmda(nums, snums, ck);
		
		//cmda(nums, snums, ck);

		ch1d(num20, nums);

		max = num20[0];
		for (int i = 1; i < 20; i++) {
			if (num20[i] > max) {
				max = num20[i];
			}
		}
		cout << max << endl;
		for (int i = 0; i < 20; i++) {
			num20[i] += max;
			
		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 m:" << endl;
	printnum(nums);
	return 0;
}
//최솟값--
int cmdn(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		int ch;
		int num20[20];
		int min;
		//cmda(nums, snums, ck);
		//min = nums[0][0];
		//cmda(nums, snums, ck);



		ch1d(num20, nums);

		min = num20[0];
		for (int i = 1; i < 20; i++) {
			if (num20[i] < min) {
				min = num20[i];
			}
		}
		cout << min << endl;

		for (int i = 0; i < 20; i++) {
			num20[i] -= min;

		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 n:" << endl;
	printnum(nums);
	return 0;
}
//1열에 한 행의 합 저장
int cmdp(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;
		


		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 5; j++) {
				nums[i][0] += nums[i][j];
			}

		}

	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 p:" << endl;
	printnum(nums);
	return 0;
}
// 4행에 한 열의 곱 저장
int cmdu(int nums[4][5], int snums[4][5], int& ck) {
	if (ck == 0) {
		savenum(nums, snums);
		ck++;



		for (int i = 0; i < 5; i++) {
			for (int j = 1; j < 4; j++) {
				nums[3][i] *= nums[j][i];
			}

		}

	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 p:" << endl;
	printnum(nums);
	return 0;
}
//재배치
int cmdr(int nums[4][5], int snums[4][5], int& ck) {
	srand(time(NULL));
	if (ck == 0) {
		savenum(nums, snums);
		ck++;

		int ch;
		int num20[20];
		ch1d(num20, nums);

		for (int i = 0; i < 20; i++) {
			int ran=(rand() % 19);
			ch = num20[i];
			num20[i] = num20[ran];
			num20[ran] = ch;
				
			
		}

		ch2d(num20, nums);
	}
	else {
		savenum(snums, nums);
		ck--;
	}

	cout << "명령어 r:" << endl;
	printnum(nums);
	return 0;
}

int clearnum(int num[9], char& cmd) {
	if (cmd == 'a') {
		if (num[0] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[0] = 1;
		}
	}
	else if (cmd == 'd') {
		if (num[1] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[1] = 1;
		}
	}
	else if (cmd == 'e') {
		if (num[2] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[2] = 1;
		}
	}
	else if (cmd == 'o') {
		if (num[3] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[3] = 1;
		}
	}
	else if (cmd == 'm') {
		if (num[4] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[4] = 1;
		}

	}
	else if (cmd == 'n') {
		if (num[5] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[5] = 1;
		}

	}
	else if (cmd == 'p') {
		if (num[6] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[6] = 1;
		}
	}
	else if (cmd == 'u') {
		if (num[7] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[7] = 1;
		}
	}
	else if (cmd == 'r') {
		if (num[8] == 0) {
			for (int i = 0; i < 9; i++) {
				num[i] = 0;
			}
			num[8] = 1;
		}
	}
	return 0;
}

