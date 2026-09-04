#include <iostream>
using namespace std;

class Product
{
private:
    int code;
    string name;
    double cost;

public:
    Product()
    {
        this->code = 0;
        this->cost = 0.0;
        this->name = "";
    }

    Product(int code, string name, double cost)
    {
        this->code = code;
        this->cost = cost;
        this->name = name;
    }

    Product(Product &other)
    {
        this->code = other.code;
        this->cost = other.cost;
        this->name = other.name;
    }

    ~Product() {}

    void setCode(int code) { this->code = code; }
    void setName(string name) { this->name = name; }
    void setCost(double cost) { this->cost = cost; }

    int getCode() { return this->code; }
    string getName() { return this->name; }
    double getCost() { return this->cost; }
};

class SalesProduct : public Product
{
private:
    double salesPrice;

public:
    SalesProduct()
    {
        this->salesPrice = 0.0;
    };

    SalesProduct(int code, string name, double cost)
    {
        this->setCode(code);
        this->setCost(cost);
        this->setName(name);
        this->setSalesPrice(cost);
    }

    SalesProduct(SalesProduct &other)
    {
        this->setCode(other.getCode());
        this->setCost(other.getCost());
        this->setName(other.getName());
        this->setSalesPrice(other.getCost());
    }

    ~SalesProduct() {}

    void setSalesPrice(double cost) { this->salesPrice = cost * 1.21; }
    double getSalesPrice() { return this->salesPrice; }

    void printProductInfo()
    {
        cout << "Product Code: " << this->getCode() << endl;
        cout << "Product Name: " << this->getName() << endl;
        cout << "Product Cost: " << this->getCost() << endl;
        cout << "Product Sales Price: " << this->getSalesPrice() << endl;
    }
};

class Supplier
{
private:
    string name;
    string company;

public:
    Supplier()
    {
        this->name = "";
        this->company = "";
    }

    Supplier(string name, string company)
    {
        this->name = name;
        this->company = company;
    }

    Supplier(Supplier &other)
    {
        this->name = other.name;
        this->company = other.company;
    }

    ~Supplier() {}

    void setName(string name) { this->name = name; }
    string getName() { return this->name; }

    void setCompany(string company) { this->company = company; }
    string getCompany() { return this->company; }

    void printSupplierInfo()
    {
        cout << "Supplier Name: " << this->getName() << endl;
        cout << "Supplier Company: " << this->getCompany() << endl;
    }
};

class InventoryProduct : public Product
{
private:
    Supplier supplier;
    int quantity;

public:
    InventoryProduct()
    {
        this->quantity = 0;
    }

    InventoryProduct(
        int code,
        string name,
        double cost,
        int quantity,
        string supplierName,
        string supplierCompany)
    {
        this->setCode(code);
        this->setCost(cost);
        this->setName(name);
        this->setProductInfo(supplierName, supplierCompany, quantity);
    }

    InventoryProduct(InventoryProduct &other)
    {
        this->setCode(other.getCode());
        this->setCost(other.getCost());
        this->setName(other.getName());
        this->supplier.setName(other.supplier.getName());
        this->supplier.setCompany(other.supplier.getCompany());
        this->setQuantity(other.quantity);
    }

    ~InventoryProduct() {}

    int getQuantity() { return this->quantity; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    void setProductInfo(string supplierName, string supplierCompany, int quantity)
    {
        this->supplier.setName(supplierName);
        this->supplier.setCompany(supplierCompany);
        this->setQuantity(quantity);
    }

    void printProductInfo()
    {
        this->supplier.printSupplierInfo();
        cout << "Product Code: " << this->getCode() << endl;
        cout << "Product Name: " << this->getName() << endl;
        cout << "Product Cost: " << this->getCost() << endl;
        cout << "Product Quantity: " << this->getQuantity() << endl;
    }
};

int main()
{

    SalesProduct sp1(1, "one", 1.1);
    InventoryProduct ip1(2, "two", 2.2, 2, "Adil", "Nadeem");

    sp1.printProductInfo();
    cout << "------------------" << endl;
    ip1.printProductInfo();

    return 0;
}