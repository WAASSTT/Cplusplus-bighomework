#pragma once
#include "teacherwage.h"
using namespace std;
class Operate {
public:
	Operate();
	//����������������������ͷ�
	~Operate();
	//Ƕ�����ṩ����Ĺ���
	class node {
	public:
		node() {
			last = NULL;
			next = NULL;
		}
		TeacherWage T;
		//��һ�������ָ��
		node* last;
		//��һ�������ָ��
		node* next;
	};
	//��ӽ�ʦ��Ϣ������
	void add(const TeacherWage& f_t);
	//ɾ����ʦ��Ϣ
	bool teacherdelete(string f_info, bool sign);//��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ������
	bool sort(bool sign);//��signΪ0ʱ������ʦ�����򣻵�signΪ1ʱ������������
	node* find(string f_info, bool sign);//��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ������
	bool changeinfo(string f_info, bool sign, string change, int choose);/*��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ��������chooseΪ1ʱ��change�ǽ�ʦ�ţ���chooseΪ2��3��4��5��6ʱ��change�ֱ����������Ա𡢵�λ���ơ���ͥסַ����ϵ�绰�� */
	bool changewage(string f_info, bool sign, int change, int choose);/*��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ��������chooseΪ1��2��3��4��5��6��7��8��9ʱ��changeΪ�������ʡ���������������绰�ѡ�ˮ��ѡ����⡢����˰�������ѡ�������*/
	//��ʾ���н�ʦ�ļ�Ҫ������Ϣ
	void show(void);
	void display(string f_info, bool sign);//��signΪ0ʱ��f_infoΪ��ʦ�ţ���signΪ1ʱ��f_infoΪ������
	size_t getlength(void) const { return length; }


	friend void tofile(void);
	node* head;
private:
	size_t length;
	node* f;
	node* l;
};