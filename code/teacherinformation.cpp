#include"teacherinformation.h"
using namespace std;
void TeacherInformation::writein(string f_id, string f_name, string f_sex, string f_unitname, string f_address, string f_telephone){
	id = f_id;
	name = f_name;
	sex = f_sex;
	unitname = f_unitname;
	address = f_address;
	telephone = f_telephone;
}