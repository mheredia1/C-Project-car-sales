
#include <iostream>
#include "vehicle.h"
#include "Functions.h"
#include <fstream>
#include<vector>
using namespace std;
int main()
{
	vector<Vehicle> vList;
	int ch;
	while (true)
	{
		cout << "***Menu***" << endl;
		cout << "1.Display Inventory" << endl << "2.Add a vehicle" << endl << "3.Update a vehicle" << endl;
		cout << "4.Sell or lease a car" << endl << "5.Search inventory by Make and model and category" << endl;

		cout << "6.Read catalog from file" << endl << "7.Write catalog to file" << endl<< "8.Display Vehicles in Price Range" << endl << "9.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			display(vList);
			break;

		case 2:
			addVehicle(vList);
			break;

		case 3:
			updateVehicle(vList);
			break;
		case 4:
			deleteVehicle(vList);
			break;
		case 5:
			searchInventory(vList);
			break;
		case 6:
			readInventory(vList);
			break;
		case 7:
			writeInventory(vList);
			break;
		case 8:
			displayPriceRange(vList);
			break;
		case 9:exit(0);
		default:
			cout << "Enter correct choice" << endl;
		}
	}
	system("pause");
	return 0;
}