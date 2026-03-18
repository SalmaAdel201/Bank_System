#pragma once
#include "Employee.h"


class Admin : public Employee {
public:
	Admin() :Employee() {
	}
	Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {
	}
	void Displayinfo() {

		Employee::Displayinfo();
	}
	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (EIt = allEmployees.begin(); EIt != allEmployees.end(); EIt++ ) {
			if (EIt->getId() == id) {
				return &(*EIt);
			}
		}
		return nullptr;
	}
	void editEmployee(int id, string name, string password, double salary) {
		Employee* e = searchEmployee(id);
		if (e != nullptr) {
			e->setId(id);
			e->setName(name);
			e->setPassword(password);
			e->setSalary(salary);

		}


	}
	void listEmployee() {
		for (EIt = allEmployees.begin(); EIt != allEmployees.end(); EIt++) {
			EIt->displayinfo();
		}
	}

};
static vector <Admin> allAdmins;
static vector<Admin>::iterator AIt;
