#pragma once
#pragma once
#include <iostream>
#include <vector>
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
				cout << "without space !! .." << endl;
				return false;
			}
		}
		return true;
	}
	static bool validatBalance(double balance) {
		if (balance < 1500) {
			cout << "min balance 1500" << endl;
			return false;
		}
		return true;
	}
	static bool validatSalary(double salary) {
		if (salary < 1500) {
			cout << "min salary 1500 !!" << endl;
			return false;
		}
		return true;
	}


};
