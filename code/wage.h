#pragma once
class Wage {
protected:
	Wage() {
		basicwage=0;//基本工资
		allowance=0;//津贴
		livingallowance=0;//生活补贴
		theoreticalwage=0;//应发工资
		telephonefee=0;//电话费
		utilityfee=0;//水电费
		rent=0;//房租
		incometax=0;//所得税
		hygienefee=0;//卫生费
		providentfund=0;//公积金
		totaldeduction=0;//合计扣款
		realwage=0;//实发工资

	}
	void writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund);

	//基本工资
	const int& getbasicwage(void) const { return basicwage; }
	//应发工资
	const int& gettheoreticalwage(void) const { return theoreticalwage; }
	//合计扣款
	const int& gettotaldeduction(void) const { return totaldeduction; }
	//实发工资
	const int& getrealwage(void) const { return realwage; }
	//津贴
	const int& getallowance(void) const { return allowance; }
	//生活补贴
	const int& getlivingallowance(void) const { return livingallowance; }
	//电话费
	const int& gettelephonefee(void) const { return telephonefee; }
	//水电费
	const int& getutilityfee(void) const { return utilityfee; }
	//房租
	const int& getrent(void) const { return rent; }
	//所得税
	const int& getincometax(void) const { return incometax; }
	//卫生费
	const int& gethygienefee(void) const { return hygienefee; }
	//公积金
	const int& getprovidentfund(void) const { return providentfund; }


private:
	int basicwage;//基本工资
	int allowance;//津贴
	int livingallowance;//生活补贴
	int theoreticalwage;//应发工资
	int telephonefee;//电话费
	int utilityfee;//水电费
	int rent;//房租
	int incometax;//所得税
	int hygienefee;//卫生费
	int providentfund;//公积金
	int totaldeduction;//合计扣款
	int realwage;//实发工资
};