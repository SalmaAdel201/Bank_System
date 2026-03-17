#pragma once
#pragma once
#include "Parser.h"
#include <vector>
#include <string>

class ClientManager
{
private:

    static vector<Client> allClients;
    static vector<Client>::iterator cIt;

public:
    static void printClientMenu() {
        system("cls");
        cout << "(1) Display my info" << endl;
        cout << "(2) Check balance" << endl;
        cout << "(3) Update Password" << endl;
        cout << "(4) Withdraw" << endl;
        cout << "(5) Deposit" << endl;
        cout << "(6) Transfer amount" << endl;
        cout << "(7) Logout\n" << endl;
    }

    static void updatePassword(Person* person) {
        string newPass;
        do {
            cout << "New password: ";
            cin >> newPass;
        } while (!Validation::validatpass(newPass));

        person->setPassword(newPass);
        cout << "Password updated" << endl;
    }

    static Client* login(int id, string password) {
        for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
            if (cIt->getId() == id && cIt->getPassword() == password) {
                return &(*cIt);
            }
        }
        return nullptr;
    }
    static void back_exit(Client* client) {
        int c;
        do
        {
            cout << "Press (1) to back to menu or (0) to exit : ";
            c = Validation::getIntNumber("Enter your choice: ");
            switch (c) {
            case 0:
                cout << "Thank you for your business with our bank !... \n";
                exit(0);
                break;
            case 1:
                system("cls");
                ClientOptions(client);
                break;
            default:
                cout << "Invalid choice !\n";
            }
        } while (c < 0 || c > 1);

    }
    static bool ClientOptions(Client* client) {
        printClientMenu();
        int choice{};
        double amount{};
        int id{};
        Client* recipient{};
        Employee e;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            client->Displayinfo();
            break;
        case 2:
            system("cls");
            client->checkBalance();
            break;
        case 3:
            system("cls");
            updatePassword(client);
            /*	FileManager :: updateClients();*/
            break;
        case 4: {
            system("cls");
            amount = Validation::getDoubleNumber("Amount to withdraw: ");
            client->withdraw(amount);
            /*	FileManager :: updateClients();*/
            break;
        }
        case 5: {
            system("cls");
            amount = Validation::getDoubleNumber("Amount to deposite: ");
            client->deposit(amount);
            /*	FileManager :: updateClients();*/
            break;
        }
        case 6: {
            system("cls");
            id = Validation::getIntNumber("Recipient ID: ");
            recipient = e.searchClient(id);
            if (recipient) {
                amount = Validation::getDoubleNumber("Amount to transfer: ");
                client->transferTo(amount, *recipient);
            }
            else {
                cout << "Account not founded !" << endl;
            }
            break;
        }

            break;

        case 7:
            return false;
        default:
            system("cls");
            ClientOptions(client);
            return true;

        }
        back_exit(client);
        return true;
    }




};
