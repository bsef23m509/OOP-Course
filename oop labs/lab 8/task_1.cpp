#include <iostream>
using namespace std;

class FeetInches
{
private:
    int feet;
    int inches;

public:
    static FeetInches multiply(FeetInches f1, FeetInches f2)
    {
        int f1Inches = (f1.getFeet() * 12) + f1.getInches();
        int f2Inches = (f2.getFeet() * 12) + f2.getInches();

        // 12 * 12 = 144 + 0 = 144
        // 12 * 10 = 120 + 0 = 120
        // 120 * 144 = 17280 / (12 ) = 120

        int totalAnsInches = f1Inches * f2Inches;
        FeetInches ans;
        ans.setFeet(totalAnsInches / (12));
        ans.setInches(totalAnsInches % 12);
        return ans;
    }

    FeetInches()
    {
        this->feet = 0;
        this->inches = 0;
    }

    FeetInches(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }

    FeetInches(FeetInches &otherFeetInch)
    {
        this->feet = otherFeetInch.getFeet();
        this->inches = otherFeetInch.getInches();
    }

    int getFeet() const
    {
        return this->feet;
    }

    void setFeet(int feet)
    {
        this->feet = feet;
    }

    int getInches() const
    {
        return this->inches;
    }

    void setInches(int inches)
    {
        this->inches = inches;
    }
};

class RoomDimension
{
private:
    FeetInches length;
    FeetInches width;

public:
    RoomDimension()
    {
        this->length = FeetInches();
        this->width = FeetInches();
    }

    RoomDimension(FeetInches length, FeetInches width)
    {
        this->length = length;
        this->width = width;
    }

    RoomDimension(RoomDimension &otherRoomDimension)
    {
        this->length = otherRoomDimension.getLength();
        this->width = otherRoomDimension.getWidth();
    }

    FeetInches getLength()
    {
        return this->length;
    }

    void setLength(FeetInches length)
    {
        this->length = length;
    }

    FeetInches getWidth()
    {
        return this->width;
    }

    void setWidth(FeetInches width)
    {
        this->width = width;
    }

    FeetInches calculateArea()
    {
        return FeetInches::multiply(this->length, this->width);
    }
};

class RoomCarpet
{
private:
    RoomDimension length;
    float cost_per_square_foot;

public:
    RoomCarpet()
    {
        this->length = RoomDimension();
        this->cost_per_square_foot = 0;
    }

    RoomCarpet(RoomDimension length, float cost)
    {
        this->length = length;
        this->cost_per_square_foot = cost;
    }

    RoomCarpet(RoomCarpet &otherRoomCarpet)
    {
        this->length = otherRoomCarpet.getLength();
        this->cost_per_square_foot = otherRoomCarpet.getcost();
    }

    RoomDimension getLength()
    {
        return this->length;
    }

    void setLength(RoomDimension length)
    {
        this->length = length;
    }

    float getcost()
    {
        return this->cost_per_square_foot;
    }

    void setcost(float cost)
    {
        this->cost_per_square_foot = cost;
    }

    float CalculateTotalCost()
    {
        FeetInches floarArea = this->getLength().calculateArea();
        int floarFeets = floarArea.getFeet();
        int floarInches = floarArea.getInches();
        return (floarInches * floarFeets * cost_per_square_foot);
    }
};

int main()
{

    int roomLengthFeet, roomLengthInches;
    int roomWidthFeet, roomWidthInches;
    int costPerSquareFoot;

    cout << "Enter Feet of length of room: ";
    do
    {
        cin >> roomLengthFeet;
    } while (roomLengthFeet < 0);

    cout << "Enter Inches of length of room: ";
    do
    {
        cin >> roomLengthInches;
    } while (roomLengthInches < 0);

    cout << "Enter Feet of width of room: ";
    do
    {
        cin >> roomWidthFeet;
    } while (roomWidthFeet < 0);

    cout << "Enter Inches of width of room: ";
    do
    {
        cin >> roomWidthInches;
    } while (roomWidthInches < 0);

    cout << "Enter Cost per square feet: ";
    do
    {
        cin >> costPerSquareFoot;
    } while (costPerSquareFoot < 0);

    FeetInches length(roomLengthFeet, roomLengthInches), width(roomWidthFeet, roomWidthInches);
    RoomDimension room(length, width);
    RoomCarpet carpet(room, costPerSquareFoot);

    cout << "The Feet of total area of the room is: " << room.calculateArea().getFeet() << " Square Feet." << endl;
    cout << "The Inches of total area of the room is: " << room.calculateArea().getInches() << " Square Inch." << endl;
    cout << "The cost to cover the entire room with carpet will be $" << carpet.CalculateTotalCost() << endl;

    return 0;
}