#pragma once
#include "Product.h"
#include <iostream>
#include <vector>
using namespace std;

class Food: public Product {
public:
	Food(int Barcode, double Price, string Name, string dateProduced, int nbrDays);		//declaring constructors and functions
	Food();
	bool ReadData(istream &in_file);
	void update(ofstream &out_file);

	void setdate(string date);		//declaring getters and setters
	string getdate();
	void setdays(int days);
	int getdays();

protected:
	string date_produced;		//declaring all variables and vectors specific to food
	int number_of_days;
	vector<Food> my_food;
};