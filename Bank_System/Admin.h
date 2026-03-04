#pragma once
#include "Employee.h"

class Admin : public Employee {
public:
	Admin() :Employee() {
	}
	Admin(string name, string password, double salary) :Employee(name, password, salary) {
	}
	void Displayinfo() {

		Employee::Displayinfo();
	}

};

