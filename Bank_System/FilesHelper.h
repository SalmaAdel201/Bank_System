#pragma once
#include "Parser.h"

#define C_FILE_PATH "Data/ClientData.txt"
#define E_FILE_PATH "Data/EmployeeData.txt"
#define A_FILE_PATH "Data/AdminData.txt"

/// file for id
#define CID_FILE_PATH "Data/LastClient'sID.txt"
#define EID_FILE_PATH "Data/LastEmployee'sID.txt"
#define AID_FILE_PATH "Data/LastAdmin'sID.txt"

class FilesHelper {
private:
    static void saveLastID(string fname, int id) {
        ofstream file(fname);
        if (file.is_open()) {
            file << id;
            file.close();
        }
        else {
            cout << "Can't open " << fname << endl;
        }
    }
    static int getLastID(string fname) {
        ifstream file(fname);
        int id = 0;

        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }
public:
    static void saveClient(Client c) {
        ofstream out(C_FILE_PATH, ios::app);

        if (out.is_open()) {
            out << c.getId() << ","
                << c.getName() << ","
                << c.getPassword() << ","
                << c.getBalance() << endl;
            out.close();

            saveLastID(CID_FILE_PATH, c.getId());

            cout << "Client saved successfully :)" << endl;
        }
        else {
            cout << "Failed to open clients file !" << endl;
        }
    }
    static void saveEmployee(Employee e) {
        ofstream out(E_FILE_PATH, ios::app);

        if (out.is_open()) {
            out << e.getId() << ","
                << e.getName() << ","
                << e.getPassword() << ","
                << e.getSalary() << endl;
            out.close();

            saveLastID(EID_FILE_PATH, e.getId());
        }
    }
    static void saveAdmin(Admin a) {
        ofstream out(A_FILE_PATH, ios::app);

        if (out.is_open()) {
            out << a.getId() << ","
                << a.getName() << ","
                << a.getPassword() << ","
                << a.getSalary() << endl;
            out.close();

            saveLastID(AID_FILE_PATH, a.getId());
        }
    }

    static void getClients() {
        ifstream in(C_FILE_PATH);
        string line;

        cout << "\n========== All Clients ==========\n";

        if (in.is_open()) {
            while (getline(in, line)) {
                if (!line.empty()) {
                    Client c = Parser::parseToClient(line);
                    c.Displayinfo();
                    cout << "------------------------\n";
                }
            }
            in.close();
        }
        else {
            cout << "No clients yet !\n";
        }
    }
    static void getEmployees() {
        ifstream in(E_FILE_PATH);
        string line;

        cout << "\n========== All Employees ==========\n";

        if (in.is_open()) {
            while (getline(in, line)) {
                if (!line.empty()) {
                    Employee e = Parser::parseToEmployee(line);
                    e.Displayinfo();
                    cout << "------------------------\n";
                }
            }
            in.close();
        }
    }
    static void getAdmins() {
        ifstream in(A_FILE_PATH);
        string line;

        cout << "\n========== All Admins ==========\n";

        if (in.is_open()) {
            while (getline(in, line)) {
                if (!line.empty()) {
                    Admin a = Parser::parseToAdmin(line);
                    a.Displayinfo();
                    cout << "------------------------\n";
                }
            }
            in.close();
        }
    }
    static void clearFile(string fileName, string lastIdFile) {
        ofstream out(fileName, ios::trunc);
        if (out.is_open()) {
            out.close();
            saveLastID(lastIdFile, 0);
            cout << "File cleared: " << fileName << endl;
        }
    }
    static void saveLast(string fname, int id) {
        saveLastID(fname, id);
    }
    static int getLast(string fname) {
        return getLastID(fname);
    }
};
