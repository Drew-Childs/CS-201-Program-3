#include "Product.h"
#include "Electronics.h"
#include "Food.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int option;		//declaring variables
	char keep_going;
	bool read1, read2;
	ifstream Electric("Electronics.txt");		//opening necessary files
	ifstream Donuts("Food.txt");
	ofstream output("output.txt");
	Electronics Ele;		//creating appropriate objects for classes
	Food Don;

	read1 = Ele.ReadData(Electric);		//sending approprate input file to the appropriate class
	read2 = Don.ReadData(Donuts);

	if (read1 && read2) {
		do {
			cout << "Welcome to our supermarket" << endl;		//printing out the menu
			cout << "Which department do you want to check?" << endl;
			cout << "1- Food" << endl;
			cout << "2- Electronics" << endl;
			cout << "3- Both" << endl;
			cout << "4- Exit" << endl;

			try {
				cout << "Enter your choice: ";		//gathering user input and ensuring they enter something valid
				cin >> option;
			}
			catch (...) {
				cout << "Invalid choice. Please try again." << endl;
			}

			switch (option) {		//depending on the choice of the user, it will call the appropriate function to output to the output file.
			case 1:					//I also made it so you could output the information to the output file as many times as you'd like
				Don.update(output);
				break;
			case 2:
				Ele.update(output);
				break;
			case 3:
				Don.update(output);
				Ele.update(output);
				break;
			case 4:
				exit(3);
				break;
			default:
				cout << "Please enter an integer between 1 and 4." << endl;
				break;
			}

			cout << "------------------------------------------------------------" << endl;		//Asks the user if they want to return to the main menu
			cout << "Press any key to return to the main menu. Press N to exit: ";
			cin >> keep_going;
		} while (toupper(keep_going) != 'N');
	}

	Electric.close();		//closing all files
	Donuts.close();
	output.close();
	return 0;
}