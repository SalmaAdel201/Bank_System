#pragma once
#include "Person.h"


class Client :public Person {
private:
	double balance;
public:
	Client() :Person() {
		this->balance = 0;
	}
	Client(int id, string name, string password, double balance) :Person(id, name, password) {
		this->balance = balance;

	}
	void setBalance(double balance) {

		if (Validation::validatBalance(balance)) {
			this->balance = balance;
		}
	}
	double getBalance() {
		return this->balance;
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Deposit : " << amount << endl;
		}
		else {
			cout << "Invalid amount " << endl;
		}
	}

	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			balance -= amount;
			cout << "Withdraw: " << amount << endl;
		}
		else {
			cout << "Invalid amount" << endl;
		}
	}

	void transferTo(double amount, Client& recipient) {
		if (amount > 0 && amount <= balance) {
			withdraw(amount);
			recipient.deposit(amount);
			cout << "transfer= " << amount << " to " << recipient.name << endl;
		}
		else {
			cout << "transfer failed :" << endl;
		}
	}

	void checkBalance() {
		cout << "Your Balance = " << balance << endl;
	}
	void Displayinfo() {
		cout << "Name : " << name << endl;
		cout << "Id  = " << id << endl;
		cout << "Password :" << password << endl;
		cout << "Balance = " << balance << endl;
	}

};