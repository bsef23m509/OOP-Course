#include <iostream>
using namespace std;

class Vehicle
{
private:
    string make;
    string model;

public:
    Vehicle()
    {
        this->make = "";
        this->model = "";
    }

    Vehicle(string make, string model)
    {
        this->make = make;
        this->model = model;
    }

    Vehicle(Vehicle &other)
    {
        this->make = other.make;
        this->model = other.model;
    }

    ~Vehicle() {}

    void setMake(string make) { this->make = make; }
    string getMake() { return this->make; }

    void setModel(string model) { this->model = model; }
    string getModel() { return this->model; }

    virtual void printVehicleInfo() {}
};

class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car()
    {
        this->setFuelType("");
    }
    Car(string make, string model, string fuelType)
    {
        this->setMake(make);
        this->setModel(model);
        this->setFuelType(fuelType);
    }
    Car(Car &other)
    {
        this->setMake(other.getMake());
        this->setModel(other.getModel());
        this->setFuelType(other.fuelType);
    }

    void setFuelType(string fuelType) { this->fuelType = fuelType; }
    string getFuelType() { return this->fuelType; }

    void printVehicleInfo()
    {
        cout << "Car Information: " << endl;
        cout << "Make: " << this->getMake() << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Fuel Type: " << this->getFuelType() << endl;
    }
};

class ElectricCar : public Vehicle
{
private:
    string fuelType;

public:
    ElectricCar()
    {
        this->setFuelType("");
    }
    ElectricCar(string make, string model, string fuelType)
    {
        this->setMake(make);
        this->setModel(model);
        this->setFuelType(fuelType);
    }
    ElectricCar(ElectricCar &other)
    {
        this->setMake(other.getMake());
        this->setModel(other.getModel());
        this->setFuelType(other.fuelType);
    }

    void setFuelType(string fuelType) { this->fuelType = fuelType; }
    string getFuelType() { return this->fuelType; }

    void printVehicleInfo()
    {
        cout << "Electric Car Information: " << endl;
        cout << "Make: " << this->getMake() << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Fuel Type: " << this->getFuelType() << endl;
    }
};

int main()
{
    Vehicle *v1 = new Car("Honda", "2024", "Petrol");
    Vehicle *v2 = new ElectricCar("Tesla", "2024", "Electricity");

    v1->printVehicleInfo();
    cout << "------------------" << endl;
    v2->printVehicleInfo();

    delete v1;
    delete v2;

    return 0;
}