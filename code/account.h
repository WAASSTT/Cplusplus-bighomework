#pragma once
class Account {
public:
	Account();
	//�˺�ע�����
	bool signin(void);
	//�˺ŵ�¼����
	bool login(void) const;
private:
	//�˺�
	char accountnum[8];
	//����
	char password[8];
};