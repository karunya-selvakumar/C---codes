#include<iostream>
using namespace std;
class HouseFullException
{
public:
    void message()
    {
        cout<<"Exception : House is FULL!"<<endl;
    }
};
class NoBookingException
{
public:
    void message()
    {
        cout<<"Exception : No tickets booked!"<<endl;
    }
};
class MovieTicket
{
    int capacity;
    int booked;
public:
    MovieTicket(int cap)
    {
        capacity=cap;
        booked=0;
    }
    void bookTicket()
    {
        if(booked==capacity)
            throw HouseFullException();
        booked++;
        cout<<"Ticket Booked.Total Booked : "<<booked<<endl;
    }
    void cancelTicket()
    {
        if(booked==0)
            throw NoBookingException();
        booked--;
        cout<<"Ticket Cancelled.Total Booked : "<<booked<<endl;
    }
    void display()
    {
        cout<<"Available Seats : "<<(capacity - booked)<<endl;
    }
};
int main()
{
    MovieTicket m(5);
    int choice;
    while(true)
    {
        cout<<"\n1.Book Ticket\n2.Cancel Ticket\n3.Display\n4.Exit\n";
        cout<<"Enter choice : ";
        cin>>choice;
        try
        {
            switch(choice)
            {
            case 1:
                m.bookTicket();
                break;
            case 2:
                m.cancelTicket();
                break;
            case 3:
                m.display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice!"<<endl;
            }
        }
        catch(HouseFullException e)
        {
            e.message();
        }
        catch(NoBookingException e)
        {
            e.message();
        }
    }
}
/*
Output:
1.Book Ticket
2.Cancel Ticket
3.Display
4.Exit
Enter choice : 1
Ticket Booked.Total Booked : 1

1.Book Ticket
2.Cancel Ticket
3.Display
4.Exit
Enter choice : 2
Ticket Cancelled.Total Booked : 0

1.Book Ticket
2.Cancel Ticket
3.Display
4.Exit
Enter choice : 3
Available Seats : 5

1.Book Ticket
2.Cancel Ticket
3.Display
4.Exit
Enter choice : 4
*/


