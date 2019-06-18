#include "teacherwage.h"
using namespace std;
void TeacherWage::writein(string f_id, string f_name, string f_sex, string f_unitname, string f_address, string f_telephone){
	TeacherInformation::writein(f_id, f_name, f_sex, f_unitname, f_address, f_telephone);
}
void TeacherWage::writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund){
	Wage::writein(f_basicwage, f_allowance, f_livingallowance, f_telephonefee, f_utilityfee, f_rent, f_incometax, f_hygienefee, f_providentfund);
}