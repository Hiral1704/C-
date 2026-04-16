#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int y)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = y;
        totalVehicles++;
    }

    virtual ~Vehicle()
    {
        cout << "Vehicle Destroyed\n";
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    virtual void display()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car(int id, string manu, string mod, int y, string fuel)
        : Vehicle(id, manu, mod, y)
    {
        fuelType = fuel;
    }

    void display()
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


class ElectricCar : public Car
{
protected:
    int batteryCapacity;

public:
    ElectricCar(int id, string manu, string mod, int y, string fuel, int battery)
        : Car(id, manu, mod, y, fuel)
    {
        batteryCapacity = battery;
    }

    void display()
    {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};


class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft(int range)
    {
        flightRange = range;
    }

    void showRange()
    {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};


class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string manu, string mod, int y, string fuel, int range)
        : Car(id, manu, mod, y, fuel), Aircraft(range)
    {
    }

    void display()
    {
        Car::display();
        showRange();
    }
};


class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    SportsCar(int id, string manu, string mod, int y, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, y, fuel, battery)
    {
        topSpeed = speed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


class Sedan : public Car
{
public:
    Sedan(int id, string manu, string mod, int y, string fuel)
        : Car(id, manu, mod, y, fuel)
    {
    }
};


class SUV : public Car
{
public:
    SUV(int id, string manu, string mod, int y, string fuel)
        : Car(id, manu, mod, y, fuel)
    {
    }
};


class VehicleRegistry
{
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle* v)
    {
        vehicles[count++] = v;
    }

    void displayVehicles()
    {
        if (count == 0)
        {
            cout << "No Vehicles Registered\n";
            return;
        }

        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << "----------------------" << endl;
        }
    }

    void searchVehicle(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                vehicles[i]->display();
                return;
            }
        }

        cout << "Vehicle Not Found\n";
    }
};


int main()
{
    VehicleRegistry registry;
    int choice;

    while (true)
    {
        cout << "\n===== Vehicle Registry Menu =====\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. View All Vehicles\n";
        cout << "4. Search Vehicle by ID\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, year;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            cout << "Manufacturer: ";
            cin >> manu;

            cout << "Model: ";
            cin >> model;

            cout << "Year: ";
            cin >> year;

            cout << "Fuel Type: ";
            cin >> fuel;

            Car* c = new Car(id, manu, model, year, fuel);
            registry.addVehicle(c);
        }

        else if (choice == 2)
        {
            int id, year, battery;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            cout << "Manufacturer: ";
            cin >> manu;

            cout << "Model: ";
            cin >> model;

            cout << "Year: ";
            cin >> year;

            cout << "Fuel Type: ";
            cin >> fuel;

            cout << "Battery Capacity: ";
            cin >> battery;

            ElectricCar* ec = new ElectricCar(id, manu, model, year, fuel, battery);
            registry.addVehicle(ec);
        }

        else if (choice == 3)
        {
            registry.displayVehicles();
        }

        else if (choice == 4)
        {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;

            registry.searchVehicle(id);
        }

        else if (choice == 5)
        {
            cout << "Exiting Program...\n";
            break;
        }

        else
        {
            cout << "Invalid Choice\n";
        }
    }

    return 0;
}