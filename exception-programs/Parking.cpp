#include<iostream>
using namespace std;
class ParkingFullException
{
public:
    void message()
    {
        cout<<"Exception : Parking is FULL!"<<endl;
    }
};
class ParkingEmptyException
{
public:
    void message()
    {
        cout<<"Exception : Parking is EMPTY!"<<endl;
    }
};
class ParkingLot
{
    int capacity;
    int vehicles;
public:
    ParkingLot(int cap)
    {
        capacity=cap;
        vehicles=0;
    }
    void parkVehicle()
    {
        if(vehicles==capacity)
            throw ParkingFullException();
        vehicles++;
        cout<<"Vehicle Parked.Total Vehicles : "<<vehicles<<endl;
    }
    void removeVehicle()
    {
        if(vehicles==0)
            throw ParkingEmptyException();
        vehicles--;
        cout<<"Vehicle Removed.Total Vehicles : "<<vehicles<<endl;
    }
    void display()
    {
        cout<<"Available Slots : "<<(capacity - vehicles)<<endl;
    }
};
int main()
{
    ParkingLot p(5);
    int choice;
    while(true)
    {
        cout<<"\n1.Park Vehicle\n2.Remove Vehicle\n3.Display\n4.Exit\n";
        cout<<"Enter choice : ";
        cin>>choice;
        try
        {
            switch(choice)
            {
            case 1:
                p.parkVehicle();
                break;
            case 2:
                p.removeVehicle();
                break;
            case 3:
                p.display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice!"<<endl;
            }
        }
        catch(ParkingFullException e)
        {
            e.message();
        }
        catch(ParkingEmptyException e)
        {
            e.message();
        }
    }
}
/*
Output:
1.Park Vehicle
2.Remove Vehicle
3.Display
4.Exit
Enter choice : 1
Vehicle Parked.Total Vehicles : 1

1.Park Vehicle
2.Remove Vehicle
3.Display
4.Exit
Enter choice : 2
Vehicle Removed.Total Vehicles : 0

1.Park Vehicle
2.Remove Vehicle
3.Display
4.Exit
Enter choice : 3
Available Slots : 5

1.Park Vehicle
2.Remove Vehicle
3.Display
4.Exit
Enter choice : 4
*/


