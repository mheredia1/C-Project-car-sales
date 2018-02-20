
#ifndef functionsH
#define functinosH
#include "vehicle.h"
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void addVehicle(vector<Vehicle>& list)
{
	string vin, make, model,category;
	int year;
	double price;
	cout << "Enter VIN: ";
	cin >> vin;
	cout << "Enter make: ";
	cin >> make;
	cout << "Enter model: ";
	cin >> model;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter Category: ";
	cin >> category;

	Vehicle *car;
	for (int i = 0; i < list.size(); ++i) 
	{ 
		car = &(list[i]);
		
		if (car->getVIN() == vin && car->getMake() == make && car->getModel() == model && car->getYear() == year && car->getCategory()== category) 
		{  
			cout << "The same vehicle has been entered twice please enter the correct values" << endl;
			return;   
		}
	}
	car = new Vehicle(vin, make, model, year, price,category);
	list.push_back(*car);
	cout << "New vehicle information added successfully" << endl;
}

void deleteVehicle(vector<Vehicle> &list)
{
	bool flag = false;
	string tVin;
	cout << "Enter vehicle VIN to delete vehicle info: ";
	cin >> tVin;
	for (int i = 0; i<list.size(); i++)
	{
		if (tVin == list[i].getVIN())
		{
			list.erase(list.begin() + i);
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << "Sorry vehicle not found" << endl;
	cout << "Vehicle info deleted sucessfully" << endl;
}

void updateVehicle(vector<Vehicle> &list)
{
	bool flag = false;
	string tVin;
	string make, model,category; 
	int year; double price;
	cout << "Enter vehicle VIN to update data:";
	cin >> tVin;
	for (int i = 0; i<list.size(); i++)
	{
		if (tVin == list[i].getVIN())
		{
			cout << "Enter new make: ";
			cin >> make;
			list[i].setMake(make);
			cout << "Enter new model: ";
			cin >> model;
			list[i].setModel(model);
			cout << "Enter new year: ";
			cin >> year;
			list[i].setYear(year);
			cout << "Enter new price: ";
			cin >> price;
			list[i].setPrice(price);
			cout << "Enter new or old: ";
			cin >> category;
			list[i].setCategory(category);
			cout << "Vehicle data updated successfully" << endl;
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << "Sorry vehicle not found" << endl;
}
void display(vector<Vehicle> &list)
{
	if (list.size() == 0)
	{
		cout << "Sorry! there are no records" << endl;
		return;
	}
	cout << endl << "***Vehicle Inventory***" << endl;
	for (int i = 0; i <list.size(); i++)
	{
		cout << "Vehicle:" << i + 1 << endl;
		cout << "VIN:" << list[i].getVIN() << endl;
		cout << "Make: " << list[i].getMake() << endl;
		cout << "Model: " << list[i].getModel() << endl;
		cout << "year: " << list[i].getYear() << endl;
		cout << "Price: " << std::setprecision(0) << list[i].getPrice() << endl;
		cout << "Category: " << list[i].getCategory() << endl;
	}
	cout << endl;
}

void displayPriceRange(vector<Vehicle> &list)
{
	cout << "Enter Lowest Price" << endl;
	double low = 0;
	cin >> low;
	cout << "Enter Highest Price" << endl;
	double high;
	cin >> high;
	if (list.size() == 0)
	{
		cout << "Sorry! there are no records" << endl;
		return;
	}
	cout << endl << "***Vehicle Inventory within price range***:" <<low <<"-"<< high << endl;
	for (int i = 0; i <list.size(); i++)
	{
		double price = list[i].getPrice();
		if (price >= low && price <= high)
		{
			cout << "Vehicle:" << i + 1 << endl;
			cout << "VIN:" << list[i].getVIN() << endl;
			cout << "Make: " << list[i].getMake() << endl;
			cout << "Model: " << list[i].getModel() << endl;
			cout << "year: " << list[i].getYear() << endl;
			cout << "Price: " << std::setprecision(0) << list[i].getPrice() << endl;
			cout << "Category: " << list[i].getCategory() << endl;
		}
	}
	cout << endl;
}




void searchInventory(vector<Vehicle> &list)
{
	bool flag = false;
	string tMake,tModel,tCat;
	cout << "Enter Make, Model or Category to search a vehicle info: " << endl;
	cin >> tMake;
	cin >> tModel;
	cin >> tCat;
	for (int i = 0; i<list.size(); i++)
	{
		if (tMake == list[i].getMake()||tModel==list[i].getModel()||tCat==list[i].getCategory())
		{
			cout << "**Vehicle found**" << endl;
			cout << "VIN:" << list[i].getVIN() << endl;
			cout << "Make: " << list[i].getMake() << endl;
			cout << "Model: " << list[i].getModel() << endl;
			cout << "year: " << list[i].getYear() << endl;
			cout << "Price: " << std::setprecision(0) << list[i].getPrice() << endl;
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << "Sorry vehicle not found" << endl;
}
void readInventory(vector<Vehicle> &list)
{
	string temp;
	ifstream infilestream;
	infilestream.open("C:/Users/michael/Desktop/New folder/cars.txt");
	Vehicle v;
	string line;
		while (infilestream)
		{
			getline(infilestream, line);
			infilestream>> temp;
			cout << "VIN:";
			cout << temp << endl;
			v.setVIN(temp);
			infilestream >> temp;
			cout << "Make:";
			cout << temp << endl;
			v.setMake(temp);
			infilestream >> temp;
			cout << "Model:";
			cout << temp << endl;
			v.setModel(temp);
			infilestream >> temp;
			cout << "Year:";
			cout << temp << endl;
			v.setYear(atoi(temp.c_str()));
			infilestream >> temp;
			cout << "Price:";
			cout << temp << endl;
			v.setPrice(atof(temp.c_str()));
			infilestream >> temp;
			cout << "Category: ";
			v.setCategory(temp);
			cout << temp << "\n";

			list.push_back(v);
		}
		infilestream.close();
		
}

void writeInventory(vector<Vehicle> &list)
{
	ofstream oFile;
	oFile.open("C:/Users/michael/Desktop/New folder/cars.txt", fstream::app);
	cout << endl << "***Vehicle Inventory***" << endl;
	for (int i = 0; i < list.size(); i++)
	{
		oFile << list[i].getVIN() << " ";
		oFile << list[i].getMake() << " ";
		oFile << list[i].getModel() << " ";
		oFile << list[i].getYear() << " ";
		oFile << list[i].getPrice() << std::setprecision(0) << " ";
		oFile << list[i].getCategory() << " ";
		oFile << "\n";
	}
	cout << endl;
	oFile.close();
	cout << "Successfully written to file" << endl;
}
#endif