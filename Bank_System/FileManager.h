#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:
    static void addClient(Client obj) {
        FilesHelper::saveClient(obj);
    }

    static void addEmployee(Employee obj) {
        FilesHelper::saveEmployee(obj);
    }

   static void addAdmin(Admin obj) {
        FilesHelper::saveAdmin(obj);
    }

   static void getAllClients() {
        FilesHelper::getClients();
    }

   static void getAllEmployees() {
        FilesHelper::getEmployees();
    }

    static void getAllAdmins() {
        FilesHelper::getAdmins();
    }

    static void removeAllClients() {
        FilesHelper::clearFile(C_FILE_PATH, CID_FILE_PATH);
    }

    static void removeAllEmployees() {
        FilesHelper::clearFile(E_FILE_PATH, EID_FILE_PATH);
    }

    static void removeAllAdmins() {
        FilesHelper::clearFile(A_FILE_PATH, AID_FILE_PATH);
    }
    static void updateClients() {
        removeAllClients();
        for (CIt = allClients.begin(); CIt != allClients.end(); CIt++) {
            addClient(*CIt);
        }
    }
    static void updateEmployees() {
        removeAllEmployees();
        for (EIt = allEmployees.begin(); EIt != allEmployees.end(); EIt++) {
            addEmployee(*EIt);
        }
    }
    static void updateAdmins() {
        removeAllAdmins();
        for (AIt = allAdmins.begin(); AIt != allAdmins.end(); AIt++) {
            addAdmin(*AIt);
        }
    }
};
