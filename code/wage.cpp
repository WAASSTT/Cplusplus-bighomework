#include"wage.h"
void Wage::writein(int f_basicwage, int f_allowance, int f_livingallowance, int f_telephonefee, int f_utilityfee, int f_rent, int f_incometax, int f_hygienefee, int f_providentfund){
	basicwage=f_basicwage;//��������
	allowance= f_allowance;//����
	livingallowance= f_livingallowance;//�����
	theoreticalwage= basicwage+ allowance + livingallowance;//Ӧ������
	telephonefee= f_telephonefee;//�绰��
	utilityfee= f_utilityfee;//ˮ���
	rent= f_rent;//����
	incometax= f_incometax;//����˰
	hygienefee= f_hygienefee;//������
	providentfund= f_providentfund;//������
	totaldeduction= telephonefee+ utilityfee+ rent+ incometax+ hygienefee + providentfund;//�ϼƿۿ�
	realwage= theoreticalwage - totaldeduction;//ʵ������
}