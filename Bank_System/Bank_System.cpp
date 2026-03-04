#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Client.h"
#include "Admin.h"


using namespace std;

 int main()
   {
	 ofstream c("Client Data");
	 ofstream e("Employee");
	 ofstream a("Admin");

	   cout << "      *       *  *******  *        *******  *******  *       *  *******      \n";
	   cout << "      *       *  *        *        *        *     *  **     **  *             \n";
	   cout << "      *       *  *        *        *        *     *  * *   * *  *              \n";
	   cout << "      *   *   *  *******  *        *        *     *  *   *   *  *******       \n";
	   cout << "      * *   * *  *        *        *        *     *  *       *  *             \n";
	   cout << "      **     **  *        *        *        *     *  *       *  *              \n";
	   cout << "      *       *  *******  *******  *******  *******  *       *  *******         \n\n";

	   cout << "*******  *******      *******  *     *  *******      *******        *        *       *    *      *     \n";
	   cout << "   *     *     *      *     *  *     *  *     *      *     *       * *       **      *    *     *      \n";
	   cout << "   *     *     *      *     *  *     *  *     *      *     *      *   *      * *     *    *    *       \n";
	   cout << "   *     *     *      *     *  *     *  ******       ******      *******     *   *   *    * * *        \n";
	   cout << "   *     *     *      *     *  *     *  *    *       *     *    *       *    *     * *    *    *       \n";
	   cout << "   *     *     *      *     *  *     *  *     *      *     *   *         *   *      **    *     *      \n";
	   cout << "   *     *******      *******  *******  *      *     *******  *           *  *       *    *      *     \n\n";


	  
	   cout << "Who are you ? \n ";
	   cout << "1- Client \n ";
	   cout << "2- Employee \n ";
	   cout << "3- Admin  \n ";
	   cout << "0- Exit \n";

	   int choice;
	   cout << "Enter the choice -> ";
	   cin >> choice;

	   system("cls");

	   do {
		   switch (choice) {
		   case 1: {
			   Client c1( "Mohamed", "12300012", 5000);

			   cout << "Your are in the Client's list :\n\n ";
			   cout << "What do you need ? \n";
			   cout << "1- Deposit an amount of money.\n";
			   cout << "2- Withdraw an amount of money.\n";
			   cout << "3- Check your balance.\n";
			   cout << "4- Transfer money to another client.\n";
			   cout << "5- Display your data.\n";
			   cout << "0- Exit. \n";

			   int option;
			   cout << "Enter a number of your option -> ";
			   cin >> option;

			   system("cls");


			   switch (option) {
			   case 1: {
				   double amount;
				   cout << "Now you can deposit an amount of money , Enter an Amount -> ";
				   cin >> amount;
				   c1.deposit(amount);

				   

				   break;
			   }

			   case 2: {
				   double amount;
				   cout << "Now you can withdraw an amount of money , Enter an Amount -> ";
				   cin >> amount;
				   c1.withdraw(amount);

				   

				   break;
			   }

			   case 3: {
				   c1.checkBalance();

				   

				   break;
			   }

			   case 4: {
				   Client c2( "Ali", "13589700", 6000);
				   double amount;
				   cout << "Now you can transfer an amount of money to another ,Continue .....\n \n";
				   cout << "Notice -> the amount should be positive and less than or equal your balance . \n\n";
				   c1.checkBalance();
				   cout << "Enter the amount -> ";
				   cin >> amount;

				   system("cls");

				   c1.transferTo(amount, c2);

				   

				   break;
			   }
			   case 5:
			   {
				   cout << "Client's data -> \n";
				   c1.Displayinfo();

				   break;
			   }
			   case 0: {
				   break;
			   }
			   default: {
				   cout << "Invalid Option !...\n ";


			   }

			   }


			   break;
		   }
		   case 2: {
			   Employee e1;
			   e1.setId(2);
			   e1.setName("Mariam");
			   e1.setPassword("12345667");
			   e1.setSalary(8000);

			   e1.getId();
			   e1.getName();
			   e1.getPassword();
			   e1.getSalary();

			   cout << "Your are in the Employee's list :\n\n ";
			   cout << "Employees' Information -> \n";
			   e1.Displayinfo();
			   break;
		   }

		   case 3: {
			   Admin a1;
			   a1.setId(1);
			   a1.setName("Salma");
			   a1.setPassword("1010101s");
			   a1.setSalary(8000);

			   a1.getId();
			   a1.getName();
			   a1.getPassword();
			   a1.getSalary();

			   cout << "Your are in the Admin's list :\n\n ";
			   cout << "Admin's Information -> \n";
			   a1.Displayinfo();
			   break;
		   }
		   case 0: {
			   break;
		   }
		   default: {
			   cout << "Invalid Choice !...\n ";
		   }


		   }

		   cout << "\n \nWho are you ? \n ";
		   cout << "1- Client \n ";
		   cout << "2- Employee \n ";
		   cout << "3- Admin  \n ";
		   cout << "0- Exit \n";

		   
		   cout << "Enter the choice -> ";
		   cin >> choice;
		   
		   system("cls");

		  

	   } while (choice != 0);

	   cout << "Thank you for your business with our bank !... \n";


	   

	   c.close();
	   e.close();
	   a.close();



   }


