#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Validation
{
public:
	/// <summary>
	/// return true if the name size between 3and 20 and all char are alpha
	/// otherwise returns false
	/// </summary>
	/// <param name="userName">
	/// 
	/// </param>
	/// <returns>
	/// bool
	/// </returns>; 
	static bool validatName(string name) {
		if (name.size() < 3 || name.size() > 20) {
			cout << "min size 3 and max size 20..!!" << endl;
			return false;
		}
		for (int i = 0; i < name.size(); i++)
		{
			if (!isalpha(name[i])) {
				cout << "name must alphabetic chars .." << endl;
				return false;
			}
		}
		return true;
	}
	static bool validatpass(string password) {
		if (password.size() < 8 || password.size() > 20) {
			cout << "min size8 and max size 20..!!" << endl;
			return false;
		}
		for (int i = 0; i < password.size(); i++)
		{
			if (password[i] == ' ') {
				cout << "Without space !! .." << endl;
				return false;
			}
		}
		return true;
	}
	static bool validatBalance(double balance) {
		if (balance < 1500) {
			cout << "Min balance 1500" << endl;
			return false;
		}
		return true;
	}
	static bool validatSalary(double salary) {
		if (salary < 1500) {
			cout << "Min salary 1500 !!" << endl;
			return false;
		}
		return true;
	}
	static double getDoubleNumber(string msg) {
		double value;
		while (true) {
			cout << msg;
			cin >> value;
			if (cin.fail()) {
				cout << "Invalid input. Please enter a valid number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}
	static int getIntNumber(string msg) {
		int value;
		while (true) {
			cout << msg;
			cin >> value;
			if (cin.fail()) {
				cout << "Invalid input. Please enter a valid number." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}
	static string enterName(string msg) {
		string name;
		do {
			cout << msg;
			getline(cin, name);
		} while (!validatName(name));
		return name;
	}
	static string enterPassword(string msg) {
		string pass;
		do {
			cout << msg;
			getline(cin, pass);
		} while (!validatpass(pass));
		return pass;
	}
	static double enterBalance(string msg) {
		double balance;
		do {
			cout << msg;
			cin >> balance;
		} while (!validatBalance(balance));
		return balance;
	}
	static double enterSalary(string msg) {
		double salary;
		do {
			cout << msg;
			cin >> salary;
		} while (!validatSalary(salary));
		return salary;
	}


	static double getDoubleNumber(string msg) {
		double value;
		while (true) {
			cout << msg;
			cin >> value;

			if (cin.fail()) {
				cout << "invalid input please enter valid number!" << endl;


				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}
	static int getIntNumber(string msg) {
		int value;
		while (true) {
			cout << msg;
			cin >> value;
			if (cin.fail()) {
				cout << "invalid input please enter valid number!" << endl;


				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}

};
