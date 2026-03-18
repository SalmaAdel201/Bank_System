#pragma once
#include "EmployeeManager.h"

class AdminManager
{
private:
	static void printAdminMenu() {
		system("cls");
		cout << "1-  Display my information .\n";
		cout << "2-  Update Password .\n";
		cout << "3-  Add new Client .\n";
		cout << "4-  Search for Client .\n";
		cout << "5-  List all Clients .\n";
		cout << "6-  Edit Client's information .\n";
		cout << "7-  Add new Employee .\n";
		cout << "8-  Search for Employee .\n";
		cout << "9-  List all Employee .\n";
		cout << "10- Edit Employee's information .\n";
		cout << "11- Logout.\n\n";
	}
	 static void back_exit(Admin* admin) {
		int c;
		do
		{
			cout << "Press (1) to back to menu or (0) to exit : ";
			c = Validation::getIntNumber("Enter your choice: ");
			switch (c) {
			case 0:
				cout << "Thank you for your business with our bank !... \n";
				exit(0);
				break;
			case 1:
				system("cls");
				AdminOptions(admin);
				break;
			default:
				cout << "Invalid choice !\n";
			}
		} while (c < 0 || c > 1);
	}
public :
	static Admin* login(int id, string password) {
		for (AIt = allAdmins.begin(); AIt != allAdmins.end() ; AIt++) {
			if (AIt->getId() == id && AIt->getPassword() == password)
				return &(*AIt);
		}
		return nullptr;

	}
	static void newEmployee(Admin* admin) {
		Employee e;
		int id = FilesHelper::getLast("last_emp.txt") + 1;
		e.setId(id);
		e.setName(Validation ::enterName("Employee Name : "));
		e.setPassword(Validation::enterPassword("Employee Password : "));
		e.setSalary(Validation::enterSalary("Employee Salary : "));

		admin->addEmployee(e);
		FileManager::addEmployee(e);

		cout << "Employee added successfully . \n";
		 
	}
	static void searchForEmployee(Admin* admin) {
		int id = Validation::getIntNumber("Enter Employee id : ");

		Employee* emp = admin->searchEmployee(id);
		if (emp != nullptr) {
			emp->Displayinfo();
		}
		else {
			cout << "Employee isn't founded ! \n";
		}
	}
	static void listAllEmployee(Admin* admin) {
		cout << "All Employees : " << endl;
		admin->listEmployee();

	}
	static void EditEmployeeInfo(Admin* admin) {
		int id = Validation::getIntNumber("Enter Employee id : ");

		Employee* emp = admin->searchEmployee(id);

		if (emp != nullptr) {
			string name =Validation::enterName("Employee Name : ");
			string password = Validation::enterPassword("Employee Password : ");
			double salary = Validation::enterSalary("Employee Salary : ");

			admin->editEmployee(id, name, password, salary);

			FileManager::updateEmployees();
			cout << "Employee isn't founded . \n";

		}
		else {
			cout << "Employee isn't founded ! \n";
		}	
	}
	static bool AdminOptions(Admin* admin) {
		printAdminMenu();
		int choice;
		cout << "Enter a choice : ";
		cin >> choice;

		switch (choice) {
		case 1: 
			system("cls");
			admin->Displayinfo();
			break;
		case 2:
			system("cls");
			ClientManager::updatePassword(admin);

			FileManager::updateAdmins();
			break;
		case 3:
			system("cls");
			EmployeeManager::newclient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManager::searchforClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManager::ListALlClient(admin);
			break;
		case 6:
			system("cls");
			EmployeeManager::editclientinfo(admin);
			break;
		case 7: 
			system("cls");
			newEmployee(admin);
			break;
		case 8: 
			system("cls");
			searchForEmployee(admin);
			break;
		case 9: 
			system("cls");
			listAllEmployee(admin);
			break;
		case 10: 
			system("cls");
			EditEmployeeInfo(admin);
			break;
		case 11:
			system("cls");
			return false;
			break;
		default:
			system("cls");
			AdminOptions(admin);
			return true;
		}
		back_exit(admin);
		return true;

	}
};

