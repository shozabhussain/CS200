#include <iostream>
using namespace std;

struct fibonacci
{
    int a=0;

int fib(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        return ( fib(num-1) + fib(num-2) );
    }
}

};


int main()
{
    int i= 0;
    int digits=0;

    cout << "Please enter the number of digits: ";
    cin >> digits;
    fibonacci b;
    
    while (digits > i)
    {
        cout << b.fib(i) << "  " ;
        i++;
    }
}