#pragma once
#include<string>
using namespace std;
class TeacherInformation {
protected:
	TeacherInformation(){}
	//����ʦ��Ϣд�����
	void writein(string f_id, string f_name, string f_sex, string f_unitname, string f_address, string f_telephone);
	const string& getid(void) const { return id; }
	const string& getname(void) const { return name; }
	const string& getsex(void) const { return sex; }
	const string& getunitname(void)const { return unitname; }
	const string& getaddress(void)const { return address; }
	const string& gettelephone(void)const { return telephone; }
private:
	//��ʦ��
	string id;
	//��ʦ����
	string name;
	//��ʦ�Ա�
	string sex;
	//��λ����
	string unitname;
	//��ʦסַ
	string address;
	//��ϵ�绰
	string telephone;
};