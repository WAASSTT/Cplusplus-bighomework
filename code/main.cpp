/*8-27 ��ʦ���ʹ���ϵͳ
ÿ����ʦ����ϢΪ����ʦ�š��������Ա𡢵�λ���ơ���ͥסַ����ϵ�绰���������ʡ��������������Ӧ�����ʡ��绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ������𡢺ϼƿۿʵ�����ʡ�ע��Ӧ������ = �������� + ���� + ��������ϼƿۿ� = �绰�� + ˮ��� + ���� + ����˰ + ������ + ������ʵ������ = Ӧ������ �� �ϼƿۿ
A����ʦ��Ϣ����
(1) �����ʦ��Ϣ(2) ���루�޸ģ���ʦ��Ϣ��(3) ɾ����ʦ��Ϣ��(4) �����ʦ��Ϣ��
��ʾ�����幦�ܼ������ο���1�� ��5�����򡢲�ѯ���� ��6���˳�ϵͳ����
B��������Ϣ����
(1) ����ʦ��¼���ʦ�������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������Ȼ������ݡ�
(2) ��ʦʵ�����ʡ�Ӧ�����ʡ��ϼƿۿ���㡣��ʾ�������������������
(3) ��ʦ�������ݹ���
��ʾ�������ʦ�ţ���������ʾ�ý�ʦ��Ϣ�����������ݣ����ĺ���Ϣд���ļ�
(4) ��ʦ�������ݲ�ѯ��
��ʾ�������ʦ�Ż�������Ϣ������������������Ϣ������ʾ������
(5) ��ʦ�����ۺ���Ϣ���
��ʾ�������ʦ��Ϣ����Ļ��*/
#include "operate.h"
#include "account.h"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
Operate op;
Account acc;

//��ȡ��ʦ�š��������Ա𡢵�λ���ơ���ַ����ϵ�绰���������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������
void fileto(void);
//�����ʦ�š��������Ա𡢵�λ���ơ���ַ����ϵ�绰���������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������
void tofile(void);
//��ʼ����
void startUI(void);
//����ѡ�����
void functionUI(void);
//��ʦ��Ϣ�������
void teacherinfoUI(void);
//��ʦ���ʴ������
void teacherwageUI(void);
//��ʾ���н�ʦ��Ϣ�͹��ʽ���
void infoUI(void);

//������
int main(void) {
	system("cls");
	system("color 06");
	fileto();
	startUI();
	tofile();
	return 0;
}
//�����ݴ�data.txt�ļ��������
void fileto(void) {
	ifstream f1;
	f1.open("data.txt", ios::in);
	if (f1.is_open()) {
		while (f1.good()) {
			string s1, s2, s3, s4, s5, s6;
			int i1, i2, i3, i4, i5, i6, i7, i8, i9;
			f1 >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7 >> i8 >> i9;
			TeacherWage temp;
			temp.writein(s1, s2, s3, s4, s5, s6);
			temp.writein(i1, i2, i3, i4, i5, i6, i7, i8, i9);
			op.add(temp);
		}
		op.sort(0);
		f1.close();
	}
	else {
		system("cls");
		cout << "�Ҳ����ļ������ֶ������ļ�";
		_getch();
		return;
	}
}
//�����ݴӶ��󵼳���data.txt�ļ�
void tofile(void) {
	ofstream fo;
	fo.open("data.txt", ios::out |ios::trunc);
	if (fo.is_open()) {
		op.head = op.f;
		for (size_t i = 0; i < op.getlength(); i++) {
			fo << op.head->T.getid() << ' ';
			fo << op.head->T.getname() << ' ';
			fo << op.head->T.getsex() << ' ';
			fo << op.head->T.getunitname() << ' ';
			fo << op.head->T.getaddress() << ' ';
			fo << op.head->T.gettelephone() << ' ';
			fo << op.head->T.getbasicwage() << ' ';
			fo << op.head->T.getallowance() << ' ';
			fo << op.head->T.getlivingallowance() << ' ';
			fo << op.head->T.gettelephonefee() << ' ';
			fo << op.head->T.getutilityfee() << ' ';
			fo << op.head->T.getrent() << ' ';
			fo << op.head->T.getincometax() << ' ';
			fo << op.head->T.gethygienefee() << ' ';
			fo << op.head->T.getprovidentfund() << endl;
		}
		fo.close();
	}
	else {
		cout << "���ݵ���ʧ�ܣ�����" << endl;
		_getch();
	}
	return;
}
//��ʼ����
void startUI(void) {
	system("cls");
	system("mode con cols=58 lines=24");
	system("title ��ʦ���ʹ���ϵͳ");
	system("color 06");
	cout << "��������������������������������������������������������\n";
	cout << "����              ���ʦ���ʹ���ϵͳ��              ����\n";
	cout << "����                                                ����\n";
	cout << "����                   ����������                   ����\n";
	cout << "����                                                ����\n";
	cout << "����                  ��ʼ�����                  ����\n";
	cout << "����                                                ����\n";
	cout << "����                    ���¼��             1      ����\n";
	cout << "����                                                ����\n";
	cout << "����                    ��ע���             2      ����\n";
	cout << "����                                                ����\n";
	cout << "����                  ����ڳ����           3      ����\n";
	cout << "����                                                ����\n";
	cout << "����                  ���˳������           0      ����\n";
	cout << "��������������������������������������������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		system("cls");
		if (acc.login()) {
			functionUI();
		}
		else startUI();
		break;
	}
	case '2': {
		system("cls");
		acc.signin();
		startUI();
		break;
	}
	case '3': {
		system("cls");
		system("mode con cols=58 lines=26");
		cout << "��������������������������������������������������������\n";
		cout << endl;
		cout << "��              ��ʦ���ʹ���ϵͳ       tags:1.00      ��\n";
		cout << endl;
		cout << "��������������������������������������������������������\n";
		cout << endl;
		cout << "��     Achieve at  2019/6/18                          ��\n";
		cout << endl;
		cout << "��������������������������������������������������������\n";
		cout << "��       ������              �������1805��           ��\n";
		cout << "��       ѧ�ţ�8002118127                             ��\n";
		cout << "��������������������������������������������������������\n";
		_getch();
		startUI();
		break;
	}
	case '0': {
		tofile();
		exit(0);
		break;
	}
	default: {
		cout << "����������󣡣���" << endl;
		_getch();
		startUI();
		break;
	}
	}
}
//����ѡ�����
void functionUI(void){
	system("cls");
	system("color 06");
	system("mode con cols=50 lines=25");
	cout << "������������������������������������������������\n";
	cout << "����                                        ����\n";
	cout << "����          ����ʦ���ʹ���ϵͳ��          ����\n";
	cout << "����                                        ����\n";
	cout << "����               ����������               ����\n";
	cout << "����                                        ����\n";
	cout << "����              ������ѡ���              ����\n";
	cout << "����                                        ����\n";
	cout << "������������������������������������������������\n";
	cout << "����                                        ����\n";
	cout << "����            ����ʦ��Ϣ�����     1      ����\n";
	cout << "����                                        ����\n";
	cout << "����            ����ʦ���ʴ����     2      ����\n";
	cout << "����                                        ����\n";
	cout << "����            �����ؿ�ʼ�����     3      ����\n";
	cout << "����                                        ����\n";
	cout << "����              ���˳������       0      ����\n";
	cout << "����                                        ����\n";
	cout << "������������������������������������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1':teacherinfoUI(); break;
	case '2':teacherwageUI(); break;
	case '3':startUI(); break;
	case '0': {
		tofile();
		exit(0);
		break;
	}
	default: {
		cout << "�����������!!!" << endl;
		_getch();
		functionUI();
		break;
	}
	}
}
//��ʦ��Ϣ�������
void teacherinfoUI(void){
	system("cls");
	system("mode con cols=66 lines=33");
	cout << "����������������������������������������������������������������\n";
	cout << "����                                                        ����\n";
	cout << "����                  ����ʦ���ʹ���ϵͳ��                  ����\n";
	cout << "����                                                        ����\n";
	cout << "����                       ����������                       ����\n";
	cout << "����                                                        ����\n";
	cout << "����                    ����ʦ��Ϣ�����                    ����\n";
	cout << "����                                                        ����\n";
	cout << "����������������������������������������������������������������\n";
	cout << "����                                                        ����\n";
	cout << "����                    �������ʦ��Ϣ��          1         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                    ���޸Ľ�ʦ��Ϣ��          2         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                    ��ɾ����ʦ��Ϣ��          3         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                    �������ʦ��Ϣ��          4         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                      ����ѯ��ʦ��            5         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                  �����ع���ѡ������        6         ����\n";
	cout << "����                                                        ����\n";
	cout << "����                      ���˳������            0         ����\n";
	cout << "����                                                        ����\n";
	cout << "����������������������������������������������������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "�������ʦ�Ľ�ʦ�š��������Ա𡢵�λ���ơ���ͥסַ����ϵ�绰��" << endl;
		string s1, s2, s3, s4, s5, s6;
		cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
		TeacherWage temp;
		temp.writein(s1, s2, s3, s4, s5, s6);
		op.add(temp);
		cout << "��Ϣ����ɹ���" << endl;
		_getch();
		teacherinfoUI();
	}
	case '2': {
		cout << "������ 0+(�ո�)+��ʦ��+�޸ĺ����Ϣ+��Ϣ��Ӧ�ı�� ��1+(�ո�)+����+�޸ĺ����Ϣ+��Ϣ��Ӧ�ı��/n ��ʦ��(1)������(2)���Ա�(3)����λ����(4)����ͥסַ(5)����ϵ�绰(6)��" << endl;
		bool s;
		int c;
		string info,change;
		cin >> s >> info>>change>>c;
		try {
			if (op.changeinfo(info, s, change, c)) cout << "��ʦ��Ϣ�޸ĳɹ���" << endl;
			else cout << "��ʦ��Ϣ�޸�ʧ�ܣ�" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherinfoUI();
		break;
	}
	case '3': {
		cout << "������ 0+(�ո�)+��ʦ�� �� 1+(�ո�)+������" << endl;
		bool s;
		string info;
		cin >> s >> info;
		try {
			if (op.teacherdelete(info, s)) cout << "��ʦ��Ϣɾ���ɹ�!" << endl;
			else cout << "��ʦ��Ϣɾ��ʧ��(���޴���)!" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		teacherinfoUI();
		break;
	}
	case '4': {
		infoUI();
		teacherinfoUI();
		break;
	}
	case '5': {
		cout << "������ 0+(�ո�)+��ʦ�� �� 1+(�ո�)+������" << endl;
		bool s;
		string info;
		cin >> s >> info;
		system("cls");
		try {
			op.display(info, s);
		}
		catch(const char *s){
			cout << s << endl;
		}
		_getch();
		teacherinfoUI();
		break;
	}
	case '6':functionUI(); break;
	case '0': {
		tofile();
		exit(0);
		break;
	}
	default: {
		cout << "�����������!" << endl;
		_getch();
		teacherinfoUI();
		break;
	}
	}
}
//��ʦ���ʴ������
void teacherwageUI(void){
	system("cls");
	system("mode con cols=62 lines=31");
	cout << "������������������������������������������������������������\n";
	cout << "����                                                    ����\n";
	cout << "����                ����ʦ���ʹ���ϵͳ��                ����\n";
	cout << "����                                                    ����\n";
	cout << "����                     ����������                     ����\n";
	cout << "����                                                    ����\n";
	cout << "����                  ����ʦ���ʴ����                  ����\n";
	cout << "����                                                    ����\n";
	cout << "������������������������������������������������������������\n";
	cout << "����                                                    ����\n";
	cout << "����                �������ʦ������Ϣ��       1        ����\n";
	cout << "����                                                    ����\n";
	cout << "����                ����ѯ��ʦ������Ϣ��       2        ����\n";
	cout << "����                                                    ����\n";
	cout << "����                ���޸Ľ�ʦ������Ϣ��       3        ����\n";
	cout << "����                                                    ����\n";
	cout << "����                ��������н�ʦ��Ϣ��       4        ����\n";
	cout << "����                                                    ����\n";
	cout << "����                �����ع���ѡ������       5        ����\n";
	cout << "����                                                    ����\n";
	cout << "����                    ���˳������           0        ����\n";
	cout << "����                                                    ����\n";
	cout << "������������������������������������������������������������\n";
	cout << "���������ֽ��в�����";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "������ 0+(�ո�)+��ʦ�� �� 1+(�ո�)+������" << endl;
		bool s;
		string info;
		cin >> s >> info;
		system("cls");
		try {
			op.display(info, s);
			cout << endl << "������ �������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������" << endl;
			int i1, i2, i3, i4, i5, i6, i7, i8, i9;
			cin >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7 >> i8 >> i9;
			op.head->T.writein(i1, i2, i3, i4, i5, i6, i7, i8, i9);
			system("cls");
			op.display(info, s);
			op.sort(0);
			cout << "�����޸ĳɹ���" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherwageUI();
		break;
	}
	case '2': {
		cout << "������ 0+(�ո�)+��ʦ�� �� 1+(�ո�)+������" << endl;
		bool s;
		string info;
		cin >> s >> info;
		system("cls");
		try {
			op.display(info, s);
			cout << "����������ء�" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherwageUI();
	}
	case '3': {
		cout << "������ 0+(�ո�)+��ʦ��+�޸ĺ����Ϣ+��Ϣ��Ӧ�ı�� ��1+(�ո�)+����+�޸ĺ����Ϣ+��Ϣ��Ӧ�ı��/n ��ʦ��(1)������(2)���Ա�(3)����λ����(4)����ͥסַ(5)����ϵ�绰(6)��" << endl;
		try {
			bool s;
			int c, change;
			string info;
			cin >> s >> info >> change >> c;
			if (op.changewage(info, s, change, c)) cout << "��ʦ�����޸ĳɹ���" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherwageUI();
		break;
	}
	case '4': {
		infoUI();
		teacherwageUI();
		break;
	}
	case '5':functionUI(); break;
	case '0': {
		tofile();
		exit(0);
		break;
	}
	default: {
		cout << "�����������!" << endl;
		_getch();
		teacherwageUI();
		break;
	}
	}
}
//��ʾ���н�ʦ��Ϣ�͹��ʽ���
void infoUI(void){
	system("cls");
	system("mode con cols=102 lines=999");
	system("color 06");
	cout << "����������أ�" << endl;
	op.show();
	_getch();
}