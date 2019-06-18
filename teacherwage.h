#pragma once
#include"teacherinformation.h"
#include"wage.h"
using namespace std;
class TeacherWage:public TeacherInformation,public Wage {
public:
	TeacherWage() {}
	void writein(string f_id, string f_name, string f_sex, string f_unitname, string f_address, string f_telephone);
	void writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund);
	friend class Operate;
	friend void tofile(void);
};