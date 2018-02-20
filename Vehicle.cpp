#include "vehicle.h"
Vehicle::Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice, string icategory)
{
	VIN = iVIN;
	make = iMake;
	model = iModel;
	year = iYear;
	price = iPrice;
	category=icategory;
}
Vehicle::Vehicle()
{
	VIN = "";
	make = "";
	model = "";
	year = 0;
	price = 0.0;
	category = "";
}
string Vehicle::getCategory()
{
	return category;
}
string Vehicle::getVIN()
{
	return VIN;
}
string Vehicle::getMake()
{
	return make;
}
string Vehicle::getModel()
{
	return model;
}
int Vehicle::getYear()
{
	return year;
}
double Vehicle::getPrice()
{
	return price;
}
void Vehicle::setCategory(string input)
{
	category = input;
}
void Vehicle::setVIN(string input)
{
	VIN = input;
}
void Vehicle::setMake(string input)
{
	make = input;
}
void Vehicle::setModel(string input)
{
	model = input;
}
void Vehicle::setYear(int input)
{
	year = input;
}
void Vehicle::setPrice(double input)
{
	price = input;
}