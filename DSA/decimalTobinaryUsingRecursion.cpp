#include <bits/stdc++.h>
using namespace std;

int makeItBinary(int dec)
{
    if (dec == 0)
        return 0;
    else
        return (dec % 2 + 10 * makeItBinary(dec / 2));
}
 

int main()
{
    int n;
    cout<<"Enter a decimal value: ";
    cin>>n;
    cout << makeItBinary(n);
    return 0;
}
