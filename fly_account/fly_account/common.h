#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#define INCOME "����"
#define EXPAND "֧��"
#define FILENAME "F:\\ѧϰ\\3c++test\\ʵս��Ŀ\\fly_account\\AccountBook.txt"

using namespace std;

//ͨ�ù����Ժ�������

//���Ʋ˵��ĺ���
void showMainMenu();
void showAccountingMenu();
void showQueryMenu();
//��ȡ����������кϷ���У��ĺ���
char readMenuSelection(int options);
char readQuitConfirm();
int readAmount();