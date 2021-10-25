#include "Electronics.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

void Electronics::setwarranty(int Warranty) { warranty = Warranty; }		//definitions for getters and setters
int Electronics::getwarranty() { return warranty; }

Electronics::Electronics(int Barcode, double Price, string Name, int Warranty) : Product(Barcode, Price, Name) {		//constructor for electronics, creates object in product as
	warranty = Warranty;																								//well to store those common variables
}

Electronics::Electronics() : Product(0, 0, ""){		//default constructor, sets all values to 0 or blank
	warranty = 0;
}
bool Electronics::ReadData(istream &in_file) {		//reads data from input file, creates an object for it based off the data, and stores object in electronics vector
	int Barcode, Price;
	string Name;

	try {		//try and catch in case something goes wrong
		while (in_file.good()) {
			in_file >> Barcode >> Name >> Price;		//reading data
			Electronics Items(Barcode, Price, Name);	//creating object
			my_electronics.push_back(Items);			//putting object in vector
		}
	}
	catch (...) {
		return false;
	}

	my_electronics.pop_back();		//popping the last element, same behavior as explained in food.cpp
	return true;
}
void Electronics::update(ofstream &out_file) {		//outputting all data to the output file
	int months;
	double monthly_payment;
	out_file << "---------------Electronics Inventory---------------" << endl;
	for (unsigned i = 0; i < my_electronics.size(); i++) {
		my_electronics.at(i).Product::update(out_file);		//outputting common information

		my_electronics.at(i).settax(0.09);		//calculating tax
		my_electronics.at(i).setprice(my_electronics.at(i).getprice() + (my_electronics.at(i).getprice() * my_electronics.at(i).gettax()));
		out_file << "Price after taxes: " << my_electronics.at(i).getprice() << endl;

		if (my_electronics.at(i).getprice() < 200) {		//setting warranty and months for financing information
			my_electronics.at(i).setwarranty(1);
			out_file << "Warranty: " << my_electronics.at(i).getwarranty() << " years" << endl;
			out_file << "Financing unavailable due to low price. Cash only." << endl;
			continue;
		}
		else if (my_electronics.at(i).getprice() >= 200 && my_electronics.at(i).getprice() <= 1000) {
			months = 12;
			my_electronics.at(i).setwarranty(3);
			out_file << "Warranty: " << my_electronics.at(i).getwarranty() << " years" << endl;
		}
		else {
			months = 24;
			my_electronics.at(i).setwarranty(5);
			out_file << "Warranty: " << my_electronics.at(i).getwarranty() << " years" << endl;
		}
		monthly_payment = (my_electronics.at(i).getprice() * pow(1.01, (months / 12))) / months;		//calculating monthly payment

		out_file << endl << my_electronics.at(i).getname() << " has 2 options for payment:" << endl;		//outputting monthly payment with interest rate and time period
		out_file << "1-Cash full price" << endl;
		out_file << "2-Pay over " << months << " months with a 1% interest rate." << endl;
		out_file << "  You would need to pay " << monthly_payment << " monthly." << endl;
		out_file << "------------------------------------------------------------" << endl;
	}
}