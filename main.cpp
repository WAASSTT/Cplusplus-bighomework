/*8-27 教师工资管理系统
每个教师的信息为：教师号、姓名、性别、单位名称、家庭住址、联系电话、基本工资、津贴、生活补贴、应发工资、电话费、水电费、房租、所得税、卫生费、公积金、合计扣款、实发工资。注：应发工资 = 基本工资 + 津贴 + 生活补贴；合计扣款 = 电话费 + 水电费 + 房租 + 所得税 + 卫生费 + 公积金；实发工资 = 应发工资 － 合计扣款。
A、教师信息处理
(1) 输入教师信息(2) 插入（修改）教师信息：(3) 删除教师信息：(4) 浏览教师信息：
提示：具体功能及操作参考题1。 （5）排序、查询功能 （6）退出系统功能
B、工资信息处理：
(1) 按教师号录入教师基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金等基本数据。
(2) 教师实发工资、应发工资、合计扣款计算。提示：计算规则如上所述。
(3) 教师工资数据管理
提示：输入教师号，读出并显示该教师信息，输入新数据，将改后信息写入文件
(4) 教师工资数据查询：
提示：输入教师号或其他信息，即读出所有数据信息，并显示出来。
(5) 教师工资综合信息输出
提示：输出教师信息到屏幕。*/
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

//读取教师号、姓名、性别、单位名称、地址、联系电话、基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金
void fileto(void);
//保存教师号、姓名、性别、单位名称、地址、联系电话、基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金
void tofile(void);
//开始界面
void startUI(void);
//功能选择界面
void functionUI(void);
//教师信息处理界面
void teacherinfoUI(void);
//教师工资处理界面
void teacherwageUI(void);
//显示所有教师信息和工资界面
void infoUI(void);

//主函数
int main(void) {
	system("cls");
	system("color 06");
	fileto();
	startUI();
	tofile();
	return 0;
}
//将数据从data.txt文件导入对象
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
		cout << "找不到文件，请手动创建文件";
		_getch();
		return;
	}
}
//将数据从对象导出到data.txt文件
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
		cout << "数据导出失败！！！" << endl;
		_getch();
	}
	return;
}
//开始界面
void startUI(void) {
	system("cls");
	system("mode con cols=58 lines=24");
	system("title 教师工资管理系统");
	system("color 06");
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "■□              ◎教师工资管理系统◎              ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                   ◎饶梓阳◎                   ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                  ◎开始界面◎                  ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                    ◎登录◎             1      ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                    ◎注册◎             2      ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                  ◎关于程序◎           3      ■□\n";
	cout << "□■                                                □■\n";
	cout << "■□                  ◎退出程序◎           0      ■□\n";
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "请输入数字进行操作：";
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
		cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
		cout << endl;
		cout << "○              教师工资管理系统       tags:1.00      ○\n";
		cout << endl;
		cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
		cout << endl;
		cout << "○     Achieve at  2019/6/18                          ○\n";
		cout << endl;
		cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
		cout << "○       饶梓阳              软件工程1805班           ○\n";
		cout << "○       学号：8002118127                             ○\n";
		cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
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
		cout << "数字输入错误！！！" << endl;
		_getch();
		startUI();
		break;
	}
	}
}
//功能选择界面
void functionUI(void){
	system("cls");
	system("color 06");
	system("mode con cols=50 lines=25");
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "□■                                        □■\n";
	cout << "■□          ◆教师工资管理系统◆          ■□\n";
	cout << "□■                                        □■\n";
	cout << "■□               ◆饶梓阳◆               ■□\n";
	cout << "□■                                        □■\n";
	cout << "■□              ◆功能选择◆              ■□\n";
	cout << "□■                                        □■\n";
	cout << "□■————————————————————□■\n";
	cout << "□■                                        □■\n";
	cout << "■□            ◆教师信息处理◆     1      ■□\n";
	cout << "□■                                        □■\n";
	cout << "■□            ◆教师工资处理◆     2      ■□\n";
	cout << "□■                                        □■\n";
	cout << "■□            ◆返回开始界面◆     3      ■□\n";
	cout << "□■                                        □■\n";
	cout << "■□              ◆退出程序◆       0      ■□\n";
	cout << "□■                                        □■\n";
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "请输入数字进行操作：";
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
		cout << "数字输入错误!!!" << endl;
		_getch();
		functionUI();
		break;
	}
	}
}
//教师信息处理界面
void teacherinfoUI(void){
	system("cls");
	system("mode con cols=66 lines=33");
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                  ◆教师工资管理系统◆                  □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                       ◆饶梓阳◆                       □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                    ◆教师信息处理◆                    □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■————————————————————————————□■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                    ◆输入教师信息◆          1         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                    ◆修改教师信息◆          2         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                    ◆删除教师信息◆          3         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                    ◆浏览教师信息◆          4         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                      ◆查询教师◆            5         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                  ◆返回功能选择界面◆        6         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■                      ◆退出程序◆            0         □■\n";
	cout << "■□                                                        ■□\n";
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "请输入数字进行操作：";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "请输入教师的教师号、姓名、性别、单位名称、家庭住址、联系电话：" << endl;
		string s1, s2, s3, s4, s5, s6;
		cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
		TeacherWage temp;
		temp.writein(s1, s2, s3, s4, s5, s6);
		op.add(temp);
		cout << "信息输入成功！" << endl;
		_getch();
		teacherinfoUI();
	}
	case '2': {
		cout << "请输入 0+(空格)+教师号+修改后的信息+信息对应的编号 或1+(空格)+姓名+修改后的信息+信息对应的编号/n 教师号(1)、姓名(2)、性别(3)、单位名称(4)、家庭住址(5)、联系电话(6)：" << endl;
		bool s;
		int c;
		string info,change;
		cin >> s >> info>>change>>c;
		try {
			if (op.changeinfo(info, s, change, c)) cout << "教师信息修改成功！" << endl;
			else cout << "教师信息修改失败！" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherinfoUI();
		break;
	}
	case '3': {
		cout << "请输入 0+(空格)+教师号 或 1+(空格)+姓名：" << endl;
		bool s;
		string info;
		cin >> s >> info;
		try {
			if (op.teacherdelete(info, s)) cout << "教师信息删除成功!" << endl;
			else cout << "教师信息删除失败(查无此人)!" << endl;
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
		cout << "请输入 0+(空格)+教师号 或 1+(空格)+姓名：" << endl;
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
		cout << "数字输入错误!" << endl;
		_getch();
		teacherinfoUI();
		break;
	}
	}
}
//教师工资处理界面
void teacherwageUI(void){
	system("cls");
	system("mode con cols=62 lines=31");
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆教师工资管理系统◆                □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                     ◆饶梓阳◆                     □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                  ◆教师工资处理◆                  □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■——————————————————————————□■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆输入教师工资信息◆       1        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆查询教师工资信息◆       2        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆修改教师工资信息◆       3        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆浏览所有教师信息◆       4        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                ◆返回功能选择界面◆       5        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■                    ◆退出程序◆           0        □■\n";
	cout << "■□                                                    ■□\n";
	cout << "□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■\n";
	cout << "请输入数字进行操作：";
	char h = _getche();
	cout << endl;
	switch (h) {
	case '1': {
		cout << "请输入 0+(空格)+教师号 或 1+(空格)+姓名：" << endl;
		bool s;
		string info;
		cin >> s >> info;
		system("cls");
		try {
			op.display(info, s);
			cout << endl << "请输入 基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金：" << endl;
			int i1, i2, i3, i4, i5, i6, i7, i8, i9;
			cin >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7 >> i8 >> i9;
			op.head->T.writein(i1, i2, i3, i4, i5, i6, i7, i8, i9);
			system("cls");
			op.display(info, s);
			op.sort(0);
			cout << "数据修改成功！" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherwageUI();
		break;
	}
	case '2': {
		cout << "请输入 0+(空格)+教师号 或 1+(空格)+姓名：" << endl;
		bool s;
		string info;
		cin >> s >> info;
		system("cls");
		try {
			op.display(info, s);
			cout << "按任意键返回。" << endl;
		}
		catch (const char* s) {
			cout << s << endl;
		}
		_getch();
		teacherwageUI();
	}
	case '3': {
		cout << "请输入 0+(空格)+教师号+修改后的信息+信息对应的编号 或1+(空格)+姓名+修改后的信息+信息对应的编号/n 教师号(1)、姓名(2)、性别(3)、单位名称(4)、家庭住址(5)、联系电话(6)：" << endl;
		try {
			bool s;
			int c, change;
			string info;
			cin >> s >> info >> change >> c;
			if (op.changewage(info, s, change, c)) cout << "教师工资修改成功！" << endl;
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
		cout << "数字输入错误!" << endl;
		_getch();
		teacherwageUI();
		break;
	}
	}
}
//显示所有教师信息和工资界面
void infoUI(void){
	system("cls");
	system("mode con cols=102 lines=999");
	system("color 06");
	cout << "按任意键返回！" << endl;
	op.show();
	_getch();
}