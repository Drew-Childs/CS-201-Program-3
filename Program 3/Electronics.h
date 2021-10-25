#pragma once
#include "Product.h"
#include <iostream>
#include <vector>
using namespace std;

class Electronics: public Product {
public:
	Electronics(int Barcode, double price, string Name, int Warranty = 0);		//declaring constructors and functions
	Electronics();
	bool ReadData(istream &in_file);
	void update(ofstream &out_file);

	void setwarranty(int Warranty);		//declaring getters and setters
	int getwarranty();

protected:
	int warranty;		//declaring variables and vector
	vector<Electronics> my_electronics;
};