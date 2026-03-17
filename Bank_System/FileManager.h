#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
public:

    //add

    void addClient(Client obj) {
        FilesHelper::saveClient(obj);
    }

    void addEmployee(Employee obj) {
        FilesHelper::saveEmployee(obj);
    }

    void addAdmin(Admin obj) {
        FilesHelper::saveAdmin(obj);
    }

    //return

    vector<Client> getAllClients() {
        return FilesHelper::getClients();
    }

    vector<Employee> getAllEmployees() {
        return FilesHelper::getEmployees();
    }

    vector<Admin> getAllAdmins() {
        return FilesHelper::getAdmins();
    }

    //remove

    void removeAllClients() override {
        FilesHelper::clearFile(C_File_Path, C_Last_Id_Path, 0);
    }

    void removeAllEmployees() override {
        FilesHelper::clearFile(E_File_Path, E_Last_Id_Path, 100);
    }

    void removeAllAdmins() override {
        FilesHelper::clearFile(A_File_Path, A_Last_Id_Path, 1000);
    }
};
