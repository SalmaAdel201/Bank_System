#pragma once
#include "Validation.h"

int idHelper = 0;

class Person : Validation {
protected:

	int id;
	string name;
	string password;
public:
	Person() {

		idHelper++;
		id = idHelper;
	}
	Person(string name, string password) {
		idHelper++;
		id = idHelper;
		this->name = name;
		this->password = password;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (name.length() >= 4 && name.length() <= 20) {
			this->name = name;
		}
		else {
			cout << "Invalid Name !....\n";
		}
	}
	void setPassword(string password) {
		if (password.length() >= 8 && password.length() <= 20)
		{
			this->password = password;
		}
		else {
			cout << "Invalid Password !...\n";
		}
	}
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;

	}
	string getPassword() {
		return this->password;
	}
	void Displayinfo() {
		cout << "Name : " << name << endl;
		cout << "Id  : " << id << endl;
		cout << "Password :" << password << endl;
	}


};

