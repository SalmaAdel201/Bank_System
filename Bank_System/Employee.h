#pragma once
#include "Person.h"

class Employee :public Person {
protected:
	double salary;
public:
	Employee() :Person() {
		this->salary = 5000;

	}
	Employee(string name, string password, double salary) :Person(name, password) {
		this->salary = salary;


	}
	void setSalary(double salary) {
		if (salary >= 5000) {
			this->salary = salary;
		}
		else {
			cout << "Minimum salary should equal 5000 !...\n\n";
		}
	}
	double getSalary() {
		return this->salary;
	}
	void Displayinfo() {

		Person::Displayinfo();

		cout << "Salary : " << salary << endl;
	}

};

