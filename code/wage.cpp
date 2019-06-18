#include"wage.h"
void Wage::writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund){
	basicwage=f_basicwage;//基本工资
	allowance= f_allowance;//津贴
	livingallowance= f_livingallowance;//生活补贴
	theoreticalwage= basicwage+ allowance + livingallowance;//应发工资
	telephonefee= f_telephonefee;//电话费
	utilityfee= f_utilityfee;//水电费
	rent= f_rent;//房租
	incometax= f_incometax;//所得税
	hygienefee= f_hygienefee;//卫生费
	providentfund= f_providentfund;//公积金
	totaldeduction= telephonefee+ utilityfee+ rent+ incometax+ hygienefee + providentfund;//合计扣款
	realwage= theoreticalwage - totaldeduction;//实发工资
}