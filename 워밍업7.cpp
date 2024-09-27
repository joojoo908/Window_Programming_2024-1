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
	double spin2; //�� ����

	double spin1speed; //km/s
	double pi;
	double km; //�� km

};

int cmdp(ball space[8]);
int cmda(ball space[8]);
int cmdb(ball space[8]);
int cmdc(ball space[8]);
int cmdc2(ball space[8]);
int cmdd(ball space[8]);
int cmde(ball space[8]);

int main() {

	// 0 ����,  1 �ݼ�,  2 ����, 3 ȭ��, 4 ��, 5 �伺, 6 õ�ռ�, 7 �ؿռ�
	// 0 �̸� 1 ������, 2 ������ ����, 3 ���� �ֱ�, 4 ���� �ֱ�, 5 ���� �ӵ�, 6 ����, 7 �¾���� �Ÿ�

	ball a0 = { "����",3.83, 0, 88 ,58.66 , 47.36, 0.04, 5790};
	ball a1 = { "�ݼ�", 9.5, 0, 225 , -243 , 35.02, 177, 10827};
	ball a2 = { "����", 10, 1, 365, 1, 29.76, 23.5, 14960};
	ball a3 = { "ȭ��",5.32, 2, 687 , 1.02 , 24.077, 25, 22739};
	ball a4 = { "��",109.7, 95 , 4015, 0.41 , 13.056, 3, 77792};
	ball a5 = { "�伺",91.4, 145 , 10585, 0.43 , 9.639, 26.7, 143018};
	ball a6 = { "õ�ռ�",39.8 , 27, 30660, -0.71, 6.795, 98, 286933};
	ball a7 = { "�ؿռ�",38.7, 16, 60225, 0.67, 5.43, 28, 450745};

	ball space[8] = { a0,a1,a2,a3,a4,a5,a6,a7 };
	

	
	char a;
	while (1) {
		cout << "��ɾ �Է��ϼ���." << endl;
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
			cout << "���� ��ɾ� �Դϴ�." << endl;
		}
	}

}
// �༺ ������ ���
int cmdp(ball space[8]) {
	cout << "��ɾ� p :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << space[i].name << endl;
		cout << "������ : " << space[i].size << endl;
		cout << "������ ���� : " << space[i].subball << "��" << endl;
		cout << "���� �ֱ� : " << space[i].spin1 << "��" << endl;
		cout << "���� �ֱ� : " << space[i].spin2 << "��" << endl;
		cout << "���� �ӵ� : " << space[i].spin1speed << "km/s" << endl;
		cout << "���� : " << space[i].pi << "��" << endl; 
		cout << "�¾���� �Ÿ� : " << space[i].km << "��km" << endl;
		cout << endl;
	}

	return 0;
}
//�����ӵ� ������
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

	cout << "��ɾ� a :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << endl;
		
	}

	return 0;
}
//�༺ũ�� ������
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

	cout << "��ɾ� b :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << endl;

	}

	return 0;
}
// �༺�� �Ÿ� ���
int cmdc(ball space[8]) {
	

	//string ballkm1[36];
	//int ballkm2[36];

	//for(int i=0;i<8;i++)

	cout << "��ɾ� c :" << endl;

	cout <<  "�¾� ~ " << space[0].name << ":" << space[0].km  << "��km" << endl;
	for (int i = 0; i < 7; i++) {
		cout << space[i].name<< " ~ " << space[i+1].name << ": " << space[i+1].km - space[i].km <<"��km" << endl;
		
	}

	return 0;
}
int cmdc2(ball space[8]) {

	string s1[8];
	int s2[8];
	string ch1;
	int ch2;

	s1[0] = "�¾� ~ " + space[0].name;
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


	cout << "��ɾ� c :" << endl;

	
	for (int i = 0; i < 8; i++) {
		cout << s1[i] << ": " << s2[i] << "��km" << endl;

	}

	return 0;
}
// ���� �ֱ� �ð�ȭ
int cmdd(ball space[8]) {
	

	cout << "��ɾ� d :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << space[i].name << " �� ���� �ֱ��  " << space[i].spin2 * 24 << "�ð�" << endl;

	}

	return 0;
}
//���� ������
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

	cout << "��ɾ� e :" << endl;
	for (int i = 0; i < 8; i++) {
		cout << copy[i].name << " ����: " << copy[i].pi << endl;

	}

	return 0;
}
