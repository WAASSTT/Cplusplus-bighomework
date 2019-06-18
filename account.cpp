#include"account.h"
#include<iostream>
#include<conio.h>
#include<cctype>
using namespace std;
Account::Account() {
	memset(accountnum, 0, 8);
	memset(password, 0, 8);
}
bool Account::signin(void) {
	char ch;
	int i = 0;;
	cout << "ÇëÊäÈëÕËºÅ£º-------\b\b\b\b\b\b\b";
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << ch;
			accountnum[i] = ch;
			i++;
		}
		else;
	}
	cout << endl;
	cout << "ÇëÊäÈëÃÜÂë£º-------\b\b\b\b\b\b\b";
	i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			password[i] = ch;
			i++;
		}
		else;
	}
	cout << endl;
	char p[8];
	memset(p, 0, 8);
	cout << "ÇëÔÙ´ÎÊäÈëÃÜÂë£º-------\b\b\b\b\b\b\b";
	i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			p[i] = ch;
			i++;
		}
	}
	cout << endl;
	if (strcmp(password, p) != 0) {
		cout << "Á½´ÎÊäÈëµÄÃÜÂë²»Ò»ÖÂ£¡" << endl;
		_getch();
		return false;
	}
	else {
		cout << "×¢²á³É¹¦£¡" << endl;
		_getch();
		return true;
	}
}
bool Account::login(void) const {
	char ch, a[8], p[8];
	memset(a, 0, 8);
	memset(p, 0, 8);
	cout << "ÇëÊäÈëÕËºÅ£º-------\b\b\b\b\b\b\b";
	int i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << ch;
			a[i] = ch;
			i++;
		}
	}
	cout << endl;
	cout << "ÇëÊäÈëÃÜÂë£º-------\b\b\b\b\b\b\b";
	i = 0;
	while (i < 7) {
		ch = _getch();
		if (isdigit(ch)) {
			cout << '*';
			p[i] = ch;
			i++;
		}
	}
	cout << endl;
	if (strcmp(accountnum, a) == 0 && strcmp(password, p) == 0) {
		cout << "µÇÂ¼³É¹¦!" << endl;
		_getch();
		return true;
	}
	else {
		cerr << "ÕËºÅ»òÃÜÂëÊäÈë´íÎó£¡" << endl;
		return false;
	}
}