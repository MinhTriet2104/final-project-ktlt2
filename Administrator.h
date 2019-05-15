#ifndef Administrator_h
#define Administrator_h

#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Administrator
{
private:
	string sUsername;
	string sPassword;
public:
	Administrator() {
		this->sUsername = "";
		this->sPassword = "";
	}

	Administrator(string sUsername, string sPassword) {
		this->sUsername = sUsername;
		this->sPassword = sPassword;
	}

	string getUsername();
	string getPassword();
	void setUsername(string sUsername);
	void getPassword(string sPassword);

	friend ifstream& operator >> (ifstream &ifs, Administrator &xAdmin) {
		getline(ifs, xAdmin.sUsername, '#');
		getline(ifs, xAdmin.sPassword);
		return ifs;
	}

	friend ostream& operator << (ostream &os, Administrator &xAdmin) {
		os << "Username: " << xAdmin.sUsername << endl;
		os << "Password: " << xAdmin.sPassword << endl;
		return os;
	}

	virtual ~Administrator() {};
};

#endif // !Administrator_h