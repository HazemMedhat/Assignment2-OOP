#include "BigRealInt.h"
#include<bits/stdc++.h>
//BigRealInt::BigRealInt()
//{
//
//
//}

BigRealInt::BigRealInt(string number_)
{
    int x;
    cin >> number_;
    for(int i = 0; i<= number.size();i++)
    {
        if(number[i]=='.')
        {
            x=number[i];
        }
    }
    cout << x;

    number = number;
}



