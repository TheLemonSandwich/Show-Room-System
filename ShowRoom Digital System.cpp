#include <iostream>
#include <string>

using namespace std;

struct Bike
{
	string Registration_City;
	string Colour;
	string Model;
	string Company;
	float Engine_Capacity;
	float Price;
	bool Anti_Theft_Lock;
	bool Disc_Brake;
	bool LED_Light;
	bool WindShield;
	bool Sold = false;
};

struct Car
{
	string Registration_City;
	string Colour;
	string Model;
	string Company;
	float Engine_Capacity;
	float Price;
	bool ABS;
	bool AirBags;
	bool Cruise_Control;
	bool Sold = false;
};

void Clear()
{
	system("pause");
	system("cls");
}

class ShowRoom
{
public:
	int bike_counter;
	int car_counter;

	ShowRoom(int bike, int car)
	{
		bike_size = bike;
		car_size = car;
		this->bike = new Bike[bike];
		this->car = new Car[car];
		bike_counter = car_counter = 0;
	}
	void Purchase(int);
	void Sell(int);
	void Display(int);
private:
	Bike* bike;
	Car* car;
	int bike_size;
	int car_size;
	void Available(int counter, Bike*, Car*);
	void Sold(int counter, Bike*, Car*);
	void DisplayAll(int counter, Bike*, Car*);
	
};

int main()
{
	for (int i = 0; i < 1000; i++)
		cout << ".\n";
	system("cls");


	int Bike_Size,Car_Size;
	cout << "Note: If you choose a Number less than 0, By default Size will be equal to 5\n\n";
	cout << "Select the Number of Bikes you want in your ShowRoom: ";
	cin >> Bike_Size;
	if (Bike_Size < 0)
		Bike_Size = 5;
	cout << "\nSelect the Number of Cars you want in your ShowRoom: ";
	cin >> Car_Size;
	if (Car_Size < 0)
		Car_Size = 5;

	ShowRoom SR(Bike_Size,Car_Size);
	cout << "\nShow Room Created! :)\n\n";
	Clear();

	char op;
	string Type;
	do
	{
		cout << "\t\t\t\t\tSHOW ROOM\n\n"
			<< "1. Purchase A Vehicle\n\n"
			<< "2. Sell A Vehicle\n\n"
			<< "3. Display\n\n"
			<< "Press Any Other Key To Exit\n\n"
			<< "Choose: ";
		cin >> op;
		system("cls");
		switch (op)
		{
		case '1':
			cin.ignore();
			cout << "Vehicle Type (Bike/Car): ";
			getline(cin, Type);
			
			if (Type == "Bike" || "bike" || "BIKE")
			{
				if (SR.bike_counter == Bike_Size)
					cout << "You cannot Purchase More Bikes. Bike Garage has reached it's limit\n";
				else SR.Purchase(0);
			}
			else if (Type == "Car" || "car" || "CAR")
				if (SR.car_counter == Car_Size)
					cout << "You cannot Purchase More Cars. Car Garage has reached it's limit\n";
				else SR.Purchase(1);
			system("pause");
			break;
		case '2':
			cin.ignore();
			cout << "Vehicle Type (Bike/Car): ";
			getline(cin, Type);

			if (Type == "Bike" || "bike" || "BIKE")
				SR.Sell(0);
			else if (Type == "Car" || "car" || "CAR")
				SR.Sell(1);
			system("pause");
			break;
		case '3':
			cin.ignore();
			cout << "Vehicle Type (Bike/Car): ";
			getline(cin, Type);

			if (Type == "Bike" || "bike" || "BIKE")
				SR.Display(0);
			else if (Type == "Car" || "car" || "CAR")
				SR.Display(1);
			system("pause");
			break;
		default:
			cout << "Exiting the Program\n";
			system("pause");
			exit(1);
		}
	} while (true);
}

void ShowRoom::Purchase(int Type)
{
	string exists;
	if (Type)
	{
		cout << "Registration City: ";
		getline(cin,(car + car_counter)->Registration_City);
		cout << "Colour: ";
		getline(cin, (car + car_counter)->Colour);
		cout << "Model: ";
		getline(cin, (car + car_counter)->Model);
		cout << "Company: ";
		getline(cin,(car + car_counter)->Company);
		cout << "Engine Capacity: ";
		cin >> (car + car_counter)->Engine_Capacity;
		cout << "Price: $";
		cin >> (car + car_counter)->Price;
		cout << "\n Type Y or N whether the function exists or not respectively\n\n";
		cout << "ABS (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(car + car_counter)->ABS = true;
		else (car + car_counter)->ABS = false;
		cout << "Air Bags (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(car + car_counter)->AirBags = true;
		else (car + car_counter)->AirBags = false;
		cout << "Cruise Control (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(car + car_counter)->Cruise_Control = true;
		else (car + car_counter)->Cruise_Control = false;

		(car + car_counter)->Sold = false;


		car_counter++;
	}
	else if (!Type)
	{
		cout << "Registration City: ";
		getline(cin, (bike + bike_counter)->Registration_City);
		cout << "Colour: ";
		getline(cin, (bike + bike_counter)->Colour);
		cout << "Model: ";
		getline(cin, (bike + bike_counter)->Model);
		cout << "Company: ";
		getline(cin, (bike+bike_counter)->Company);
		cout << "Engine Capacity : ";
		cin >> (bike + bike_counter)->Engine_Capacity;
		cout << "Price: $";
		cin >> (bike + bike_counter)->Price;
		cout << "\n Type Y or N whether the function exists or not respectively\n\n";
		cout << "Anti-Theft Lock (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(bike + bike_counter)->Anti_Theft_Lock = true;
		else (bike + bike_counter)->Anti_Theft_Lock = false;
		cout << "Disc Brake (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(bike + bike_counter)->Disc_Brake = true;
		else (bike + bike_counter)->Disc_Brake = false;
		cout << "LED Light (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(bike + bike_counter)->LED_Light = true;
		else (bike + bike_counter)->LED_Light = false;
		cout << "Wind Shield (Y/N): ";
		cin >> exists;
		if (exists == "Y" || "Yes" || "YES" || "yes" || "y")
			(bike + bike_counter)->WindShield= true;
		else (bike + bike_counter)->WindShield = false;

		(bike + bike_counter)->Sold = false;

		bike_counter++;
	}
	cout << "Vehile Purchased And Added To The Garage!\n";
}

void ShowRoom::Sell(int Type)
{
	string Model, Company, Registration_City;
	cout << "Model: ";
	getline(cin, Model);
	cout << "Company: ";
	getline(cin, Company);
	cout << "Registration City: ";
	getline(cin, Registration_City);

	bool sold = false;

	if(Type)
	for (int i = 0; i < car_counter; i++)
	{
		if ((car + i)->Model == Model && (car + i)->Company == Company && (car + i)->Registration_City == Registration_City)
		{
			(car + i)->Sold = true;
			cout << "Car Sold!\n";
			sold = true;
		}
	}
	else if (!Type)
	{
		for (int i = 0; i < bike_counter; i++)
		{
			if ((bike + i)->Model == Model && (bike + i)->Company == Company && (bike + i)->Registration_City == Registration_City)
			{
				(bike + i)->Sold = true;
				cout << "Bike Sold!\n";
				sold = true;
			}
		}
	}
	if (!sold)
		cout << "Couldn't Find The Vehile\n\n";
}

void ShowRoom::Display(int Type)
{
	char op;
	system("cls");
	cout << "1. Available\n\n"
		<< "2. Sold\n\n"
		<< "3. All Vehicles\n\n"
		<< "Choose: ";
	cin >> op;
	system("cls");
	if (Type)
	{
		switch (op)
		{
		case '1':
			cout << "Available Cars:- \n\n";
			Available(car_counter, NULL, car);
			break;
		case '2':
			cout << "Sold Cars:-\n\n";
			Sold(car_counter, NULL, car);
			break;
		case '3':
			cout << "All Vehicles:-\n\n";
			DisplayAll(car_counter, NULL, car);
			break;
		default:
			cout << "Invalid Input. Showing All Cars\n";
		}
	}
	else
	{
		switch (op)
		{
		case '1':
			cout << "Available Bikes:- \n\n";
			Available(bike_counter, bike, NULL);
			break;
		case '2':
			cout << "Sold Bikes:-\n\n";
			Sold(bike_counter, bike, NULL);
			break;
		case '3':
			cout << "All Vehicles:-\n\n";
			DisplayAll(bike_counter, bike, NULL);
			system("pause");
			break;
		default:
			cout << "Invalid Input. Showing All Bikes\n";
		}
	}
}

void ShowRoom::Available(int counter, Bike* bike, Car* car)
{
	if(bike != NULL)
		for (int i = 0; i < counter; i++)
		{
			if (!(bike + i)->Sold)
			{
				cout << "Registration City: " << (bike + i)->Registration_City << endl;
				cout << "Model: " <<  (bike + i)->Model << endl;
				cout << "Colour: " << (bike + i)->Colour << endl;
				cout << "Company: " << (bike + i)->Company << endl;
				cout << "Price: $" << (bike + i)->Price << endl;
				cout << "Engine Capacity: " << (bike + i)->Engine_Capacity << "L" << endl;
				if ((bike + i)->Anti_Theft_Lock)
					cout << "Anti-Theft Lock: Exists\n";
				else cout << "Anti-Theft Lock: Does not Exist\n";
				if ((bike + i)->Disc_Brake)
					cout << "Disc Brake: Exists\n";
				else cout << "Disc Brake: Does not Exist\n";
				if ((bike + i)->LED_Light)
					cout << "LED Light: Exists\n";
				else cout << "LED Light: Does not Exist\n";
				if ((bike + i)->WindShield)
					cout << "Wind Shield: Exists\n\n";
				else cout << "Wind Shield: Does not Exist\n\n";
			}
		}
	else
	{
		for (int i = 0; i < counter; i++)
		{
			if (!(car + i)->Sold)
			{
				cout << "Registration City: " << (car + i)->Registration_City << endl;
				cout << "Model: " << (car + i)->Model << endl;
				cout << "Colour: " << (car + i)->Colour << endl;
				cout << "Company: " << (car + i)->Company << endl;
				cout << "Price: $" << (car + i)->Price << endl;
				cout << "Engine Capacity: " << (car + i)->Engine_Capacity << "L" << endl;
				if ((car + i)->ABS)
					cout << "ABS: Exists\n";
				else cout << "ABS: Does not Exist\n";
				if ((car + i)->AirBags)
					cout << "Air Bags: Exists\n";
				else cout << "Air Bags: Do not Exist\n";
				if ((car + i)->Cruise_Control)
					cout << "Cruise Control: Exists\n\n";
				else cout << "Cruise Control: Does not Exist\n\n";
			}
		}
	}
}

void ShowRoom::Sold(int counter, Bike* bike, Car* car)
{
	if (bike != NULL)
		for (int i = 0; i < counter; i++)
		{
			if ((bike + i)->Sold)
			{
				cout << "Registration City: " << (bike + i)->Registration_City << endl;
				cout << "Model: " << (bike + i)->Model << endl;
				cout << "Colour: " << (bike + i)->Colour << endl;
				cout << "Company: " << (bike + i)->Company << endl;
				cout << "Price: " << (bike + i)->Price << endl;
				cout << "Engine Capacity: " << (bike + i)->Engine_Capacity << endl;
				if ((bike + i)->Anti_Theft_Lock)
					cout << "Anti-Theft Lock: Exists\n";
				else cout << "Anti-Theft Lock: Does not Exist\n";
				if ((bike + i)->Disc_Brake)
					cout << "Disc Brake: Exists\n";
				else cout << "Disc Brake: Does not Exist\n";
				if ((bike + i)->LED_Light)
					cout << "LED Light: Exists\n";
				else cout << "LED Light: Does not Exist\n";
				if ((bike + i)->WindShield)
					cout << "Wind Shield: Exists\n\n";
				else cout << "Wind Shield: Does not Exist\n\n";
			}
		}
	else
	{
		for (int i = 0; i < counter; i++)
		{
			if ((car + i)->Sold)
			{
				cout << "Registration City: " << (car + i)->Registration_City << endl;
				cout << "Model: " << (car + i)->Model << endl;
				cout << "Colour: " << (car + i)->Colour << endl;
				cout << "Company: " << (car + i)->Company << endl;
				cout << "Price: " << (car + i)->Price << endl;
				cout << "Engine Capacity: " << (car + i)->Engine_Capacity << endl;
				if ((car + i)->ABS)
					cout << "ABS: Exists\n";
				else cout << "ABS: Does not Exist\n";
				if ((car + i)->AirBags)
					cout << "Air Bags: Exists\n";
				else cout << "Air Bags: Do not Exist\n";
				if ((car + i)->Cruise_Control)
					cout << "Cruise Control: Exists\n\n";
				else cout << "Cruise Control: Does not Exist\n\n";
			}
		}
	}
}

void ShowRoom::DisplayAll(int counter, Bike* bike, Car* car)
{
	if (bike)
		for (int i = 0; i < counter; i++)
		{
			cout << "Registration City: " << (bike + i)->Registration_City << endl;
			cout << "Model: " << (bike + i)->Model << endl;
			cout << "Colour: " << (bike + i)->Colour << endl;
			cout << "Company: " << (bike + i)->Company << endl;
			cout << "Price: " << (bike + i)->Price << endl;
			cout << "Engine Capacity: " << (bike + i)->Engine_Capacity << endl;
			if ((bike + i)->Anti_Theft_Lock)
				cout << "Anti-Theft Lock: Exists\n";
			else cout << "Anti-Theft Lock: Does not Exist\n";
			if ((bike + i)->Disc_Brake)
				cout << "Disc Brake: Exists\n";
			else cout << "Disc Brake: Does not Exist\n";
			if ((bike + i)->LED_Light)
				cout << "LED Light: Exists\n";
			else cout << "LED Light: Does not Exist\n";
			if ((bike + i)->WindShield)
				cout << "Wind Shield: Exists\n\n";
			else cout << "Wind Shield: Does not Exist\n\n";
		}
	else
	{
		for (int i = 0; i < counter; i++)
		{
			cout << "Registration City: " << (car + i)->Registration_City << endl;
			cout << "Model: " << (car + i)->Model << endl;
			cout << "Colour: " << (car + i)->Colour << endl;
			cout << "Company: " << (car + i)->Company << endl;
			cout << "Price: " << (car + i)->Price << endl;
			cout << "Engine Capacity: " << (car + i)->Engine_Capacity << endl;
			if ((car + i)->ABS)
				cout << "ABS: Exists\n";
			else cout << "ABS: Does not Exist\n";
			if ((car + i)->AirBags)
				cout << "Air Bags: Exists\n";
			else cout << "Air Bags: Do not Exist\n";
			if ((car + i)->Cruise_Control)
				cout << "Cruise Control: Exists\n\n";
			else cout << "Cruise Control: Does not Exist\n\n";
		}
	}
}