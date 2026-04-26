#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    try
    {
        if(x%2!=0)
        {
          throw -1;
        }
        cout<<"Even number!";
    }
    catch(int e)
    {
        cout<<"Odd number caught!";
    }
    return 0;
}
/*
Output:
7
Odd number caught!
4
Even number!
*/
