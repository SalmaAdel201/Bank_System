#pragma once
#include "Client.h"
#include "Admin.h"
#include <fstream>
#include <vector>


class ParserClass
{
	static vector<string> split(string line) {

		vector<string> alldata;
		alldata.push_back(line);
		return alldata;
		
	}
	static Client parseToClient(string line) {
		ofstream save("Client Data");
		save << line << endl;
		save.close();

		ifstream read("Client Data");
		while (!read.eof()) {
			read.get();
			cout << line;
		}
		read.close();
		

	}
	static Employee parseToEmployee(string line) {
		ofstream save("Employee Data");
		save << line << endl;
		save.close();

		ifstream read("Employee Data");
		while (!read.eof()) {
			read.get();
			cout << line;
		}
		read.close();

	}
	static Admin parseToAdmin(string line) {
		ofstream save("Admin Data");
		save << line << endl;
		save.close();

		ifstream read("Admin Data");
		while (!read.eof()) {
			read.get();
			cout << line;
		}
		read.close();

	}

};

