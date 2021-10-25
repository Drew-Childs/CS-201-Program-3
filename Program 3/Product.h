#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product {
public:
	Product (int Barcode, double Price, string Name, double Tax = 0, double Discount = 0);		//function/constructor declarations
	Product();
	void update(ofstream &out_file);

	void setprice(double Price);		//getter and setter declarations
	double getprice();
	void setbarcode(int Barcode);
	int getbarcode();
	void settax(double Tax);
	double gettax();
	void setdiscount(double Discount);
	double getdiscount();
	void setname(string Name);
	string getname();

protected:		//declaring variables
	int barcode;
	double price, tax, discount;
	string name;
};