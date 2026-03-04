#pragma once
#include "Person.h"


class Client :public Person {
private:
	double balance;
public:
	Client() :Person() {
		this->balance = 0;


	}
	Client(string name, string password, double balance) :Person(name, password) {
		this->balance = balance;


	}
	void setBalance(double balance) {
		if (balance >= 1500) {
			this->balance = balance;
		}
		else {
			cout << "Minimum balance should equal 1500 !...\n";
		}
	}
	double getBalance() {
		return this->balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Balance with the Deposit : " << balance << endl;
		}
		else {
			cout << "Invalid amount \n" << endl;
		}
	}

	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			balance -= amount;
			cout << "Balance after withdraw : " << balance << endl;
		}
		else {
			cout << "Invalid amount \n" << endl;
		}
	}

	void transferTo(double amount, Client& recipient) {
		if (amount > 0 && amount <= balance) {
			withdraw(amount);
			cout << endl;
			recipient.deposit(amount);
			cout << endl;
			cout << "Transfering  " << amount << " to " << recipient.name << " is successful" << endl;
		}
		else {
			cout << "Transfer failed ! \n" << endl;
		}
	}

	void checkBalance() {
		cout << "Your Balance = " << balance << endl;
	}
	void Displayinfo() {

		Person::Displayinfo();
		cout << "Balance : " << balance << endl;
	}

};
