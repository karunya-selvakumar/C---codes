#include<iostream>
using namespace std;
int main()
{
    int age;
    cin>>age;
    try
    {
        if(age<18)
        {
            throw "Not eligible to vote!";
        }
        cout<<"Eligible to vote!";
    }
    catch(const char* msg)
    {
        cout<<"Exception : "<<msg<<endl;
    }
    return 0;
}
/*
Output:
20
Eligible to vote!
15
Exception : Not eligible to vote!
*/
