#pragma once
#include<string>
using namespace std;
class TeacherInformation {
protected:
	TeacherInformation(){}
	//将教师信息写入对象
	void writein(string f_id, string f_name, string f_sex, string f_unitname, string f_address, string f_telephone);
	const string& getid(void) const { return id; }
	const string& getname(void) const { return name; }
	const string& getsex(void) const { return sex; }
	const string& getunitname(void)const { return unitname; }
	const string& getaddress(void)const { return address; }
	const string& gettelephone(void)const { return telephone; }
private:
	//教师号
	string id;
	//教师姓名
	string name;
	//教师性别
	string sex;
	//单位名称
	string unitname;
	//教师住址
	string address;
	//联系电话
	string telephone;
};