#include "common.h"

//读取键盘输入的菜单选项，进行合法性校验
char readMenuSelection(int options) {
	string str;
	//进行合法性校验
	while (true) {
		getline(cin, str);
		if (str.size() != 1 || str[0] - '0' > options || str[0] - '0' <= 0) {
			cout << "输入错误，请重新选择：";
		}
		else
			break;
	}
	return str[0];
	
}

char readQuitConfirm() {
	string str;
	//进行合法性校验
	while (true) {
		getline(cin, str);
		if (str.size() != 1 || toupper(str[0]) !='Y' && toupper(str[0]) != 'N') {
			cout << "输入错误，请重新输入 (Y/N)：";
		}
		else
			break;
	}
	return toupper(str[0]);
}

//读取键盘输入的金额数，并做合法性校验
int readAmount() {
	int amount;
	string str;
	//进行合法性校验
	while (true) {
		getline(cin, str);
		try {
			amount = stoi(str);
			break;
		}
		catch (invalid_argument e) {
			cout<<"输入错误，请正确输入金额：";
		}
	}
	return amount;
}