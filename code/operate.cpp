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
//当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。
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

//当sign为0时，按教师号排序；当sign为1时，按姓名排序。
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
//当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。
Operate::node* Operate::find(string f_info, bool sign) {
	head = f;
	for (size_t i = 0; i < length; i++) {
		if (sign && head->T.getname() == f_info) {
			return head;
		}
		else if (!sign && head->T.getid() == f_info) {
			return head;
		}
		else throw"查无此人！";
		head = head->next;
	}
	return NULL;
}
/*当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。当choose为1时，change是教师号；当choose为2、3、4、5、6时，change分别是姓名、性别、单位名称、家庭住址、联系电话。 */
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
/*当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。当choose为1、2、3、4、5、6、7、8、9时，change为基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金*/
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
//显示所有教师的简要工资信息
void Operate::show(void) {
	head = f;
	cout << "教师号     姓名     性别 单位名称     联系电话     基本工资  应发工资  合计扣款  实发工资" << endl;
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
	cout << "教师号:" << head->T.getid() << endl;
	cout << "姓名：" << head->T.getname() << endl;
	cout << "性别：" << head->T.getsex() << endl;
	cout << "单位名称：" << head->T.getunitname() << endl;
	cout << "家庭住址：" << head->T.getaddress() << endl;
	cout << "联系电话：" << head->T.gettelephone() << endl;
	cout << "基本工资：" << head->T.getbasicwage() << endl;
	cout << "津贴：" << head->T.getallowance() << endl;
	cout << "生活补贴：" << head->T.getlivingallowance() << endl;
	cout << "应发工资：" << head->T.gettheoreticalwage() << endl;
	cout << "电话费：" << head->T.gettelephonefee() << endl;
	cout << "水电费：" << head->T.getutilityfee() << endl;
	cout << "房租：" << head->T.getrent() << endl;
	cout << "所得税：" << head->T.getincometax() << endl;
	cout << "卫生费：" << head->T.gethygienefee() << endl;
	cout << "公积金：" << head->T.getprovidentfund() << endl;
	cout << "合计扣款：" << head->T.gettotaldeduction() << endl;
	cout << "实发工资：" << head->T.getrealwage() << endl;
}