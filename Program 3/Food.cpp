#include "Food.h"
#include <iostream>
#include <fstream>
using namespace std;

void Food::setdate(string date) { date_produced = date; }		//defining getters and setters
string Food::getdate() { return date_produced; }
void Food::setdays(int days) { number_of_days = days; }
int Food::getdays() { return number_of_days; }

Food::Food(int Barcode, double Price, string Name, string dateProduced, int nbrDays) : Product (Barcode, Price, Name) {		//creating overloaded constructor
	date_produced = dateProduced;		//Setting values
	number_of_days = nbrDays;
}

Food::Food() : Product(0, 0, "") {		//default constructor, even creates appropriate variables in product class
	date_produced = "";
	number_of_days = 0;
}

bool Food::ReadData(istream &in_file) {		//taking all data from the input file (food.txt), creating an object for each new entry, and storing that object in a vector
	int Barcode, Days;
	string Name, Date;
	double Price;

	try {		//try and catch in case something reads incorrectly or something goes wrong
		while (in_file.good()) {
			in_file >> Barcode >> Name >> Price >> Date >> Days;		//inputing all data
			Food Items(Barcode, Price, Name, Date, Days);				//creating an object for each new entry
			my_food.push_back(Items);									//storing object in vector
		}
	}
	catch (...) {
		return false;
	}

	my_food.pop_back();		//I observed weird behavior where it counted the last new line as a new object, just deleting that unneeded object
	return true;
}
void Food::update(ofstream &out_file) {		//outputting all information to output.txt
	out_file << "---------------Food Inventory--------------" << endl;
	for (unsigned i = 0; i < my_food.size(); i++) {

		my_food.at(i).Product::update(out_file);		//displaying name, barcode, price, and date for each object
		out_file << "Date Produced: " << my_food.at(i).getdate() << endl;

		if (my_food.at(i).number_of_days < 10) {		//Based on the discount, adjusts price for the object
			my_food.at(i).price = my_food.at(i).price;
			out_file << my_food.at(i).getname() << " is not on sale." << endl;
		}
		else if (my_food.at(i).number_of_days >= 10 && my_food.at(i).number_of_days <= 14) {
			my_food.at(i).price *= 0.80;
			out_file << my_food.at(i).getname() << " is 20% off. Final price is now " << my_food.at(i).getprice() << endl;
		}
		else if (my_food.at(i).number_of_days >= 15 && my_food.at(i).number_of_days < 30) {
			my_food.at(i).price *= 0.50;
			out_file << my_food.at(i).getname() << " is 50% off. Final price is now " << my_food.at(i).getprice() << endl;
		}
		else {
			my_food.at(i).price *= 0.20;
			out_file << my_food.at(i).getname() << " is 80% off. Final price is now " << my_food.at(i).getprice() << endl;
		}
		out_file << "------------------------------------------------------------" << endl;
	}
}