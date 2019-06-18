#pragma once
#include "teacherwage.h"
using namespace std;
class Operate {
public:
	Operate();
	//析构函数将对象里的数据释放
	~Operate();
	//嵌套类提供链表的功能
	class node {
	public:
		node() {
			last = NULL;
			next = NULL;
		}
		TeacherWage T;
		//上一个链表的指针
		node* last;
		//下一个链表的指针
		node* next;
	};
	//添加教师信息及工资
	void add(const TeacherWage& f_t);
	//删除教师信息
	bool teacherdelete(string f_info, bool sign);//当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。
	bool sort(bool sign);//当sign为0时，按教师号排序；当sign为1时，按姓名排序。
	node* find(string f_info, bool sign);//当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。
	bool changeinfo(string f_info, bool sign, string change, int choose);/*当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。当choose为1时，change是教师号；当choose为2、3、4、5、6时，change分别是姓名、性别、单位名称、家庭住址、联系电话。 */
	bool changewage(string f_info, bool sign, int change, int choose);/*当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。当choose为1、2、3、4、5、6、7、8、9时，change为基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金*/
	//显示所有教师的简要工资信息
	void show(void);
	void display(string f_info, bool sign);//当sign为0时，f_info为教师号；当sign为1时，f_info为姓名。
	size_t getlength(void) const { return length; }


	friend void tofile(void);
	node* head;
private:
	size_t length;
	node* f;
	node* l;
};