#pragma once
#include "Client.h"
#include "Admin.h"
#include <fstream>
#include <sstream>
#include "Validation.h"


// classes prototypes
class Client;
class Employee;
class Admin;

class Parser {
public:
    static vector<string> split(string line) {
        vector<string> result;
        stringstream ss(line);
        string part;

        while (getline(ss, part, ',')) {
            if (!part.empty()) {
                result.push_back(part);
            }
        }
        return result;
    }
    static Client parseToClient(string line) {
        vector<string> data = split(line);
        if (data.size() < 4) {
            cout << "ERROR: client data incomplete !!!" << endl;
            return Client();
        }
        try {
            int id = stoi(data[0]);
            string name = data[1];
            string pass = data[2];
            double bal = stod(data[3]);

            //* Validation **

            return Client(id, name, pass, bal);
        }
        catch (exception& e) {
            cout << "Parsing faild: " << e.what() << endl;
            return Client();
        }
    }
    static Employee parseToEmployee(string line) {
        vector<string> data = split(line);

        if (data.size() < 4) {
            cout << "Employee data error !\n";
            return Employee();
        }
        int id = stoi(data[0]);
        string name = data[1];
        string pass = data[2];
        double salary = stod(data[3]);
        return Employee(id, name, pass, salary);
    }
    static Admin parseToAdmin(string line) {
        vector<string> data = split(line);

        if (data.size() < 4) {
            cout << "Admin data error" << endl;
            return Admin();
        }
        return Admin(stoi(data[0]), data[1], data[2], stod(data[3]));
    }
};
