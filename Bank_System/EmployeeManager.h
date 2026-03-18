#pragma once
#pragma once
#include "FileManager.h"
#include "ClientManager.h"
#include "Client.h"
class EmployeeManager
{
	static vector<Employee> allemployee;
	static vector<Employee>::iterator eIt;

	static void printEmployeeMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new Client" << endl;
		cout << "(4) search for Client" << endl;
		cout << "(5) List all Clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;
	}
	static void back_exit(Employee* employee) {
		int c;
		do {
			cout << "\n\n(1) Options\t\t(0) Exit\n";
			c = Validation::getIntNumber("..::Enter Choice: ");

			switch (c)
			{
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				employeeOptions(employee);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:
	static void newclient(Employee* employee) {
		Client client;

		int id = FilesHelper::getLast("last_emp.txt") + 1;

		client.setId(id);

		client.setName(Validation::enterName("Client name: "));
		client.setPassword(Validation::enterPassword("Client password: "));
		client.setBalance(Validation::enterBalance("Client balance: "));

		employee->addClient(client);

		FileManager::addClient(client);
		cout << "Client added successfully";
	}


	static void ListALlClient(Employee* employee) {
		cout << "All Clients: \n" << endl;
		employee->listClient();
	}
	static void searchforClient(Employee* employee) {
		int id;

		id = Validation::getIntNumber("Enter clinet id: ");
		Client* client = employee->searchClient(id);
		if (client == nullptr) cout << "Client Not Founded" << endl;
		else client->Displayinfo();
	}



	static void editclientinfo(Employee* employee) {
		int id = Validation::getIntNumber("Enter client id: ");
		Client* client = employee->searchClient(id);
		if (client != nullptr) {
			cout << "===== Update data =====" << endl;
			string name = Validation::enterName("Client name: ");
			string pass = Validation::enterPassword("Client password: ");
			double balance = Validation::enterBalance("Client balance: ");
			employee->editClient(client, name, pass, balance);

			FileManager::updateClients();
			cout << "Client data updated successfully" << endl;
		}
		else {
			cout << "Client not found" << endl;
		}
	}
	static Employee* login(int id, string pass) {

		for (eIt = allemployee.begin(); eIt != allemployee.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == pass) return eIt._Ptr;
		}
		return nullptr;

	}

	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		int choice;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			system("cls");
			employee->Displayinfo();
			break;
		case 2:
			system("cls");
			ClientManager::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:
			system("cls");
			newclient(employee);
			break;
		case 4:
			system("cls");
			searchforClient(employee);
			break;
		case 5:
			system("cls");
			ListALlClient(employee);
			break;
		case 6:
			system("cls");
			editclientinfo(employee);
			break;
		case 7:
			return false;
			break;
		default:

			system("cls");

			employeeOptions(employee);
			return true;
		}

		back_exit(employee);
		return true;
	}
};
