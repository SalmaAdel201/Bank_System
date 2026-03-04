#pragma once
#include "Person.h"

class Employee :public Person {
protected:
	double salary;
public:
	Employee() :Person() {
		this->salary = 5000;
	}
	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		this->salary = salary;

	}
	void setSalary(double salary) {
		if (salary >= 5000) {
			this->salary = salary;
		}
		else {
			cout << "Minimum salary should equal 5000 !...\n";
		}
	}
	double getSalary() {
		return this->salary;
	}
	void Displayinfo() {

		cout << "Name : " << name << endl;
		cout << "Id  = " << id << endl;
		cout << "Password :" << password << endl;
		cout << "Salary = " << salary << endl;
	}

};
