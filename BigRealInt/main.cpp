#include "BigDecimalIntClass.h"

int main() {
    BigReal b,d;

    int n;
    while(true)
    {
        cout<<"Welcome to the Calculator\n"
              "----------------------------------------"<<endl;
        cout <<"1- Perform Addition\n"
               "2- Perform Subtraction\n"
               "3- perform Is Equal?\n"
               "4- Know the sign\n"
               "5- Know the size\n"
               "6- Perform Is Smaller?\n"
               "7- perform Is Larger?\n"
               "8- Exit\n"
               "Please enter your choice: ";
        cin >> n ;
        if (n != 1 && n != 3 && n != 2 && n!=4 && n!=5 && n!=6 && n!=7 && n!=8 ){
            cout <<"invalid choice\n"<<endl;
            continue;
        }
        if(n == 1)
        {
            cin >> b;
            cin >> d;
            cout << b+d;

        }

        else if(n == 2)
        {
            cin >> b;
            cin >> d;
        }

        else if(n == 3)
        {
            cin >> b;
            cin >> d;
            if(b==d ==true)
            {
                cout << "They are equal.\n\n";
            }
            else
                cout << "They are not equal.\n\n";
        }
        else if(n == 5)
        {
            cin >> b;
            cout << b.size()<<"\n\n";
        }
        else if(n == 4)
        {
            cin >> b;
            cout << b.Sign()<<"\n\n";
        }
        else if(n == 6)
        {
            cin >> b;
            cin >> d;
            bool x = b<d;
            if(x == 1)
            {
                cout << "First number is smaller.\n\n";
            }
            else
                cout << "Second number is smaller.\n\n";
        }
        else if(n == 7)
        {
            cin >> b;
            cin >> d;
            bool x = b>d;
            if(x == 1)
            {
                cout << "First number is larger.\n\n";
            }
            else
                cout << "Second number is larger.\n\n";
        }
        else if(n == 8)
        {
            cin >> b;
            cin >> d;
            return 0;
        }
    }


    return 0;
}


