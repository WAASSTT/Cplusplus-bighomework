#include "operate.h"
#include<iostream>
using namespace std;
void print(int size) {
	for (int i = 0; i < size; i++)
		cout << ' ';
}
int len(int n) {
	int sum = 1;
	while (n/=10) sum++;
	if (n >= 0)  return sum;
	else return sum + 1;
}

Operate::~Operate(){
	if (length != 0) {
		node* tt = head = f;
		while (head != NULL) {
			head = head->next;
			delete tt;
			tt = head;
		}
	}
}
Operate::Operate() {
	f = l = head = NULL;
	length = 0;
}

void Operate::add(const TeacherWage& f_t) {
	if (length == 0) {
		head = NULL;
		f = l = head = new node;
		head->T = f_t;
		length++;
	}
	else {
		l->next = head = new node;
		head->T = f_t;
		head->last = l;
		l = head;
		length++;
	}
}
//��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ������
bool Operate::teacherdelete(string f_info, bool sign) {
	head = f;
	if (length == 0) return false;
	if (sign) {
		for (size_t i = 0; i < length; i++) {
			if (head->T.getname() == f_info) {
				head->last->next = head->next;
				head->next->last = head->last;
				delete head;
				length--;
				return true;
			}
			else {
				head = head->next;
			}
		}
	}
	else {
		for (size_t i = 0; i < length; i++) {
			if (head->T.getid() == f_info) {
				head->last->next = head->next;
				head->next->last = head->last;
				delete head;
				length--;
				return true;
			}
			else {
				head = head->next;
			}
		}
	}
	return false;
}

//��signΪ0ʱ������ʦ�����򣻵�signΪ1ʱ������������
bool Operate::sort(bool sign) {
	if (length == 0) return false;
	head = f;
	for (size_t i = 0; i < length; i++) {
		for (size_t j = 0; j < length - i - 1; j++) {
			if (sign && head->T.getname() > head->next->T.getname()) {
				TeacherWage temp = head->T;
				head->T = head->next->T;
				head->next->T = temp;
			}
			else if (!sign && head->T.getid() > head->next->T.getid()) {
				TeacherWage temp = head->T;
				head->T = head->next->T;
				head->next->T = temp;
			}
			head = head->next;
		}
	}
	return false;
}
//��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ������
Operate::node* Operate::find(string f_info, bool sign) {
	head = f;
	for (size_t i = 0; i < length; i++) {
		if (sign && head->T.getname() == f_info) {
			return head;
		}
		else if (!sign && head->T.getid() == f_info) {
			return head;
		}
		else throw"���޴��ˣ�";
		head = head->next;
	}
	return NULL;
}
/*��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ��������chooseΪ1ʱ��change�ǽ�ʦ�ţ���chooseΪ2��3��4��5��6ʱ��change�ֱ����������Ա𡢵�λ���ơ���ͥסַ����ϵ�绰�� */
bool Operate::changeinfo(string f_info, bool sign, string change, int choose) {
	head = find(f_info, sign);
	if (head == NULL) return false;
	switch (choose) {
	case 1:
	{
		head->T.writein(change, head->T.getname(), head->T.getsex(), head->T.getunitname(), head->T.getaddress(), head->T.gettelephone());
		return true;
		break;
	}
	case 2:
	{
		head->T.writein(head->T.getid(), change, head->T.getsex(), head->T.getunitname(), head->T.getaddress(), head->T.gettelephone());
		return true;
		break;
	}
	case 3:
	{
		head->T.writein(head->T.getid(), head->T.getname(), change, head->T.getunitname(), head->T.getaddress(), head->T.gettelephone());
		return true;
		break;
	}
	case 4:
	{
		head->T.writein(head->T.getid(), head->T.getname(), head->T.getsex(), change, head->T.getaddress(), head->T.gettelephone());
		return true;
		break;
	}
	case 5:
	{
		head->T.writein(head->T.getid(), head->T.getname(), head->T.getsex(), head->T.getunitname(), change, head->T.gettelephone());
		return true;
		break;
	}
	case 6:
	{
		head->T.writein(head->T.getid(), head->T.getname(), head->T.getsex(), head->T.getunitname(), head->T.getaddress(), change);
		return true;
		break;
	}
	default:return false; break;
	}
}
/*��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ��������chooseΪ1��2��3��4��5��6��7��8��9ʱ��changeΪ�������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������*/
bool Operate::changewage(string f_info, bool sign, int change, int choose){
	head = find(f_info, sign);
	if(head==NULL) return false;
	switch (choose) {
	case 1: {
		head->T.writein(change, head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 2: {
		head->T.writein(head->T.getbasicwage(), change, head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 3: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), change, head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 4: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), change, head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 5: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), change, head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 6: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), change, head->T.getincometax(), head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 7: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), change, head->T.gethygienefee(), head->T.getprovidentfund());
		return true;
		break;
	}
	case 8: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), change, head->T.getprovidentfund());
		return true;
		break;
	}
	case 9: {
		head->T.writein(head->T.getbasicwage(), head->T.getallowance(), head->T.getlivingallowance(), head->T.gettelephonefee(), head->T.getutilityfee(), head->T.getrent(), head->T.getincometax(), head->T.gethygienefee(), change);
		return true;
		break;
	}
	default:return false; break;
	}
}
//��ʾ���н�ʦ�ļ�Ҫ������Ϣ
void Operate::show(void) {
	head = f;
	cout << "��ʦ��     ����     �Ա� ��λ����     ��ϵ�绰     ��������  Ӧ������  �ϼƿۿ�  ʵ������" << endl;
	while (head != NULL) {
		cout << head->T.getid();
		print(11 - head->T.getid().length());
		cout << head->T.getname();
		print(9 - head->T.getname().length());
		cout << head->T.getsex();
		print(3);
		cout << head->T.getunitname();
		string s1 = head->T.getunitname();
		print(13 - s1.length());
		cout << head->T.gettelephone();
		string s2 = head->T.gettelephone();
		print(13 - s2.length());
		cout << head->T.getbasicwage();
		print(10 - len(head->T.getbasicwage()));
		cout << head->T.gettheoreticalwage();
		print(10 - len(head->T.gettheoreticalwage()));
		cout << head->T.gettotaldeduction();
		print(10 - len(head->T.gettotaldeduction()));
		cout << head->T.getrealwage();
		cout << endl;
		head = head->next;
	}
}

void Operate::display(string f_info, bool sign) {
	head = Operate::find(f_info, sign);
	cout << "��ʦ��:" << head->T.getid() << endl;
	cout << "������" << head->T.getname() << endl;
	cout << "�Ա�" << head->T.getsex() << endl;
	cout << "��λ���ƣ�" << head->T.getunitname() << endl;
	cout << "��ͥסַ��" << head->T.getaddress() << endl;
	cout << "��ϵ�绰��" << head->T.gettelephone() << endl;
	cout << "�������ʣ�" << head->T.getbasicwage() << endl;
	cout << "������" << head->T.getallowance() << endl;
	cout << "�������" << head->T.getlivingallowance() << endl;
	cout << "Ӧ�����ʣ�" << head->T.gettheoreticalwage() << endl;
	cout << "�绰�ѣ�" << head->T.gettelephonefee() << endl;
	cout << "ˮ��ѣ�" << head->T.getutilityfee() << endl;
	cout << "���⣺" << head->T.getrent() << endl;
	cout << "����˰��" << head->T.getincometax() << endl;
	cout << "�����ѣ�" << head->T.gethygienefee() << endl;
	cout << "������" << head->T.getprovidentfund() << endl;
	cout << "�ϼƿۿ" << head->T.gettotaldeduction() << endl;
	cout << "ʵ�����ʣ�" << head->T.getrealwage() << endl;
}