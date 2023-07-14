#include"common.h"
#include"account_item.h"

//---------------------1.������Ŀ����------------------
void loadDataFromFile(vector<AccountItem>& items) {
	ifstream input(FILENAME);
	//���ж�ȡÿһ����Ŀ���Ұ�װ��AccountItem
	AccountItem item;
	while (input>>item.itemType>>item.amount>>item.detail) {
		items.push_back(item);
	}
	input.close();
}

//---------------------2.���˲���--------------------
void accounting(vector<AccountItem>& items) {
	//��ȡ����ѡ�񣬲����Ϸ���У��
	char key = readMenuSelection(3);
	switch (key)
	{
	case '1':  //1 - ����
		income(items);
		break;
	case '2':  //2 - ֧��
		expand(items);
		break;
	default:
		break;
	}
}

//��¼һ������
void income(vector<AccountItem>& items) {
	//�¹���һ��AccountItem����
	AccountItem item;
	//�����Ѿ�ȷ����������
	item.itemType = INCOME;
	//���û����н���������������ͱ�ע��Ϣ
	cout << "\n���������";
	item.amount = readAmount();
	cout << "\n��ע��Ϣ��";
	getline(cin, item.detail);
	//��ӵ�vector��
	items.push_back(item);
	//д���ļ����־û�����
	insertIntoFile(item);
	//��ʾ�ɹ���Ϣ
	cout << "\n---------���˳ɹ���-----------\n" << endl;
	cout << "\n�밴�س����������˵�������" << endl;
	string line;
	getline(cin, line);
}

//��¼һ��֧��
void expand(vector<AccountItem>& items) {
	//�¹���һ��AccountItem����
	AccountItem item;
	//�����Ѿ�ȷ������֧��
	item.itemType = EXPAND;
	//���û����н���������������ͱ�ע��Ϣ
	cout << "\n����֧����";
	item.amount = - readAmount();
	cout << "\n��ע��Ϣ��";
	getline(cin, item.detail);
	//��ӵ�vector��
	items.push_back(item);
	//д���ļ����־û�����
	insertIntoFile(item);
	//��ʾ�ɹ���Ϣ
	cout << "\n---------���˳ɹ���-----------\n" << endl;
	cout << "\n�밴�س����������˵�������" << endl;
	string line;
	getline(cin, line);
}

//��һ����Ŀд���ļ���
void insertIntoFile(const AccountItem& item) {
	ofstream output(FILENAME,ios::out | ios::app);
	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
	output.close();
}


//---------------------3.��ѯ����--------------------
void query(const vector<AccountItem>& items) {
	//��ȡ����ѡ�񣬲����Ϸ���У��
	char key = readMenuSelection(4);
	switch (key)
	{
	case '1':  //1 - ��ѯͳ������֧
		queryItems(items);
		break;
	case '2':  //2 - ��ѯͳ������
		queryItems(items,INCOME);
		break;
	case '3':  //3 - ��ѯͳ����֧��
		queryItems(items, EXPAND);
		break;
	default:
		break;
	}
}

//��ѯ��Ŀ���ܺ���
void queryItems(const vector<AccountItem>& items) {
	cout << "----------------��ѯ���----------------" << endl;
	cout << "\n ����\t\t���\t\t��ע\n" << endl;
	//����������Ŀ��ͳ������֧
	int total = 0;
	for (auto item : items) {
		printItem(item);
		total += item.amount;
	}
	//�����Ϣ
	cout << "==============================\n" << endl;
	cout << "����֧��" << total << endl;
	//��ʾ�ɹ���Ϣ
	cout << "\n---------��ѯ��ϣ�-----------\n" << endl;
	cout << "\n�밴�س����������˵�������" << endl;
	string line;
	getline(cin, line);
}

//��������
void queryItems(const vector<AccountItem>& items, const string itemType) {
	cout << "----------------��ѯ���----------------" << endl;
	cout << "\n ����\t\t���\t\t��ע\n" << endl;
	//����������Ŀ��ͳ�����������֧��
	int total = 0;
	for (auto item : items) {
		if (item.itemType == itemType) {
			printItem(item);
			total += item.amount;
		}
	}
	//�����Ϣ
	cout << "==============================\n" << endl;
	cout << ((itemType==INCOME)?"�����룺":"��֧����") << total << endl;
	//��ʾ�ɹ���Ϣ
	cout << "\n---------��ѯ��ϣ�-----------\n" << endl;
	cout << "\n�밴�س����������˵�������" << endl;
	string line;
	getline(cin, line);
}


//��ӡ���һ����Ŀ��Ϣ
void printItem(const AccountItem& item) {
	cout << item.itemType << "\t\t" << item.amount << "\t\t" << item.detail << endl;
}