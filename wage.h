#pragma once
class Wage {
protected:
	Wage() {
		basicwage=0;//��������
		allowance=0;//����
		livingallowance=0;//�����
		theoreticalwage=0;//Ӧ������
		telephonefee=0;//�绰��
		utilityfee=0;//ˮ���
		rent=0;//����
		incometax=0;//����˰
		hygienefee=0;//������
		providentfund=0;//������
		totaldeduction=0;//�ϼƿۿ�
		realwage=0;//ʵ������

	}
	void writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund);

	//��������
	const int& getbasicwage(void) const { return basicwage; }
	//Ӧ������
	const int& gettheoreticalwage(void) const { return theoreticalwage; }
	//�ϼƿۿ�
	const int& gettotaldeduction(void) const { return totaldeduction; }
	//ʵ������
	const int& getrealwage(void) const { return realwage; }
	//����
	const int& getallowance(void) const { return allowance; }
	//�����
	const int& getlivingallowance(void) const { return livingallowance; }
	//�绰��
	const int& gettelephonefee(void) const { return telephonefee; }
	//ˮ���
	const int& getutilityfee(void) const { return utilityfee; }
	//����
	const int& getrent(void) const { return rent; }
	//����˰
	const int& getincometax(void) const { return incometax; }
	//������
	const int& gethygienefee(void) const { return hygienefee; }
	//������
	const int& getprovidentfund(void) const { return providentfund; }


private:
	int basicwage;//��������
	int allowance;//����
	int livingallowance;//�����
	int theoreticalwage;//Ӧ������
	int telephonefee;//�绰��
	int utilityfee;//ˮ���
	int rent;//����
	int incometax;//����˰
	int hygienefee;//������
	int providentfund;//������
	int totaldeduction;//�ϼƿۿ�
	int realwage;//ʵ������
};