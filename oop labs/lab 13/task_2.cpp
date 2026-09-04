#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle()
    {
        this->make = "";
        this->model = "";
        this->year = 0;
    }

    Vehicle(string make, string model, int year)
    {
        this->make = make;
        this->model = model;
        this->year = year;
    }

    virtual float rentalRate() = 0;
    virtual void display() = 0;
};

class Car : public Vehicle
{
protected:
    float dailyRate;

public:
    Car()
    {
        this->dailyRate = 0;
    }

    Car(string make, string model, int year, float dailyRate) : Vehicle(make, model, year)
    {
        this->dailyRate = dailyRate;
    }

    float rentalRate() { return this->dailyRate; }

    void display()
    {
        cout << "Car Information: " << endl;
        cout << "Make: " << this->make << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Daily Rate: " << this->dailyRate << endl;
    }
};

class Truck : public Vehicle
{
protected:
    float dailyRate;
    int cargoCapacity;

public:
    Truck()
    {
        this->dailyRate = 0;
        this->cargoCapacity = 0;
    }

    Truck(string make, string model, int year, float dailyRate, int cargoCapacity) : Vehicle(make, model, year)
    {
        this->dailyRate = dailyRate;
        this->cargoCapacity = cargoCapacity;
    }

    float rentalRate() { return this->dailyRate; }

    void display()
    {
        cout << "Truck Information: " << endl;
        cout << "Make: " << this->make << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Daily Rate: " << this->dailyRate << endl;
        cout << "Cargo Capacity: " << this->cargoCapacity << endl;
    }
};

class MotorCycle : public Vehicle
{
protected:
    float dailyRate;

public:
    MotorCycle()
    {
        this->dailyRate = 0;
    }

    MotorCycle(string make, string model, int year, float dailyRate) : Vehicle(make, model, year)
    {
        this->dailyRate = dailyRate;
    }

    float rentalRate() { return this->dailyRate; }

    void display()
    {
        cout << "MotorCycle Information: " << endl;
        cout << "Make: " << this->make << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Daily Rate: " << this->dailyRate << endl;
    }
};

class ElectricCar : public Car
{
protected:
    float batteryLife;

public:
    ElectricCar()
    {
        this->batteryLife = 0;
    }

    ElectricCar(string make, string model, int year, float dailyRate, float batteryLife) : Car(make, model, year, dailyRate)
    {
        this->batteryLife = batteryLife;
    }

    float rentalRate() { return this->dailyRate; }

    void display()
    {
        cout << "Truck Information: " << endl;
        cout << "Make: " << this->make << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Daily Rate: " << this->dailyRate << endl;
        cout << "Battery Life: " << this->batteryLife << " Hours" << endl;
    }
};

int main()
{

    Vehicle *vehicles[5];

    vehicles[0] = new Car("one", "Car", 2022, 50.0);

    vehicles[1] = new Truck("one", "Truck", 2019, 20.0, 10);

    vehicles[2] = new MotorCycle("one", "Motor Cycle", 2021, 20.0);

    vehicles[3] = new ElectricCar("one", "Electric Car", 2024, 30.0, 5.5);
    vehicles[4] = new ElectricCar("two", "Electric Car", 2023, 40.0, 4.0);

    for (int i = 0; i < 5; i++)
    {
        vehicles[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        delete vehicles[i];
    }

    return 0;
}