#include<iostream>
using namespace std;


class Item
{
private:
    int id;
    string name;
    double price;
    int quantity;

public:

    Item()
    {
        this->setId(0);
        this->setName("name" );
        this->setPricw(0);
        this->setQuantity(0);
    }

    int getId () {
        return this->id;
    }
    string getName () {
        return this->name;
    }
    double getPrice () {
        return this->price;
    }
    int getQuantity () {
        return this->quantity;
    }

    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPricw(double price) {
        this->price = price;
    }
    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
    
    void print() {
        cout << endl;
        cout << "id: " << id << endl;
        cout << "name: " << name << endl;
        cout << "price: " << price << endl;
        cout << "quantity: " << quantity << endl;
        cout << endl;
    }
};

class Store
{

private:
    Item** items = new Item* [1000];
    int capacity;

public:

    Store()
    {
        this->capacity = 0;
    }
    
    ~Store()
    {
        delete[] this->items;
    }
    
    bool isEmpty() {
        if(capacity == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(capacity == 1000) return true;
        return false;
    }
    
    void addItem( Item* newItem)
    {
        if(!isFull())
        {
        this->items[capacity] = newItem;
        capacity++;
        }
    }
    
    void deleteItem(int id)
    {
        if(!isEmpty()) 
        {
        int itemDel = this->searchIndex(id);
        
        for(int i = itemDel+1; i < capacity; i++)
            this->items[i-1] = this->items[i];
        capacity--;   
        }
            
    }
    
    void updateItemQuantity(int id, int quantity)
    {
        int itemDel = this->searchIndex(id);
        this->items[itemDel]->setQuantity(quantity);
    }
    
    double returnValue()
    {
        double total = 0;
        for(int i=0; i<capacity; i++)
        {
            total += (this->items[i]->getQuantity() * this->items[i]->getPrice());
        }
        return total;
    }
    
    
    Item searchItem(int id) {
        for(int i = 0; i < capacity; i++) {
            if(this->items[i]->getId() == id)
                return *(this->items[i]);
        }
    }
    
    int searchIndex(int id) {
        for(int i = 0; i < capacity; i++) {
            if(this->items[i]->getId() == id)
                return i;
        }
    }
    
    void printItems () {
        for(int i = 0; i < capacity; i++) {
            this->items[i]->print();
        }
    }


};


int main()
{

    Item item1, item2;
    item1.setId(1);
    item2.setId(2);
    
    item1.setPricw(1.20);
    item2.setPricw(2.80);
    
    item1.setQuantity(3);
    item2.setQuantity(5);
    
    Store store;
    store.addItem(&item1);
    store.addItem(&item2);
    store.printItems();
    
    cout << "Total Value: " << store.returnValue() << endl;
    
    
    cout << "Searching item" << endl;
    Item item3 = store.searchItem(1);
    item3.print();
    
    store.updateItemQuantity(1, 5);

    store.printItems();
    cout << "Total Value: " << store.returnValue() << endl;
    
    return 0;
}