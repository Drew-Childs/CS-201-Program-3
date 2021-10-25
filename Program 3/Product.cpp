#include "Product.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Product::setprice(double Price) { price = Price; }		//getters and setters for class variables
double Product::getprice() { return price; }
void Product::setbarcode(int Barcode) { barcode = Barcode; }
int Product::getbarcode() { return barcode; }
void Product::settax(double Tax) { tax = Tax; }
double Product::gettax() { return tax; }
void Product::setdiscount(double Discount) { discount = Discount; }
double Product::getdiscount() { return discount; }
void Product::setname(string Name) { name = Name; }
string Product::getname() { return name; }

Product::Product(int Barcode, double Price, string Name, double Tax, double Discount) {		//overloaded constructor
	if (Barcode > 0) {
		barcode = Barcode;		//setting object variable values
	}
	else {
		barcode = 0;
	}
	price = Price;
	name = Name;
	tax = Tax;
	discount = Discount;
}

Product::Product() {		//default constructor
	barcode = 0;		//default values
	price = 0;
	name = "";
	tax = 0;
	discount = 0;
}

void Product::update(ofstream &out_file) {
	out_file << "Item: " << name << endl;		//outputting common information
	out_file << "Barcode: " << barcode << endl;
	out_file << "Price: " << price << endl;
}	