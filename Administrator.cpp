#include "Administrator.h"

string Administrator::getUsername() {
	return this->sUsername;
}

string Administrator::getPassword() {
	return this->sPassword;
}

void Administrator::setUsername(string sUsername) {
	this->sUsername = sUsername;
}

void Administrator::getPassword(string sPassword) {
	this->sPassword = sPassword;
}

