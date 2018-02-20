
#ifndef vehicleH
#define vehicleH
#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
private:
	string VIN;
	string make;
	string model;
	int year;
	double price;
	string category;
public:
	Vehicle();
	string getCategory();
	Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice, string icategory);
	string getVIN();
	string getMake();
	string getModel();
	int getYear();
	double getPrice();
	void setVIN(string input);
	void setMake(string input);
	void setModel(string input);
	void setCategory(string input);
	void setYear(int input);
	void setPrice(double input);
};
#endif
