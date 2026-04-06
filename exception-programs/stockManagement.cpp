#include<iostream>
using namespace std;
class OutofStockException
{
public:
    void displayMessage()
    {
        cout<<"Error : Requested quantity exceeds available stock!"<<endl;
    }
};
class Product
{
private:
    int stock;
public:
    Product(int s)
    {
        stock=s;
    }
    void purchase(int quantity)
    {
        if(quantity>stock)
        {
            throw OutofStockException();
        }
        else
        {
            stock-=quantity;
            cout<<"Purchase successful!";
            cout<<"Remaining stock : "<<stock<<endl;
        }
    }
};
int main()
{
    int availableStock,requestedQty;
    cout<<"Enter available stock : ";
    cin>>availableStock;
    cout<<"Enter requested quantity : ";
    cin>>requestedQty;
    Product p(availableStock);
    try
    {
        p.purchase(requestedQty);
    }
    catch(OutofStockException e)
    {
        e.displayMessage();
    }
}
