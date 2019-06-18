#pragma once
class Account {
public:
	Account();
	//ÕËºÅ×¢²á½çÃæ
	bool signin(void);
	//ÕËºÅµÇÂ¼½çÃæ
	bool login(void) const;
private:
	//ÕËºÅ
	char accountnum[8];
	//ÃÜÂë
	char password[8];
};