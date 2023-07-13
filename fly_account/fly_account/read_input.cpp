#include "common.h"

//��ȡ��������Ĳ˵�ѡ����кϷ���У��
char readMenuSelection(int options) {
	string str;
	//���кϷ���У��
	while (true) {
		getline(cin, str);
		if (str.size() != 1 || str[0] - '0' > options || str[0] - '0' <= 0) {
			cout << "�������������ѡ��";
		}
		else
			break;
	}
	return str[0];
	
}

char readQuitConfirm() {
	string str;
	//���кϷ���У��
	while (true) {
		getline(cin, str);
		if (str.size() != 1 || toupper(str[0]) !='Y' && toupper(str[0]) != 'N') {
			cout << "����������������� (Y/N)��";
		}
		else
			break;
	}
	return toupper(str[0]);
}

//��ȡ��������Ľ�����������Ϸ���У��
int readAmount() {
	int amount;
	string str;
	//���кϷ���У��
	while (true) {
		getline(cin, str);
		try {
			amount = stoi(str);
			break;
		}
		catch (invalid_argument e) {
			cout<<"�����������ȷ�����";
		}
	}
	return amount;
}