#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <bits/stdc++.h>
#include "BankAccount.h"
#include "SavingBankAccount.h"
using namespace std;

class Client
{
    protected:
        string name;
        string address;
        string phone;
        string ID;
        BankAccount account;
        SavingBankAccount SavingAcc;

    public:

        Client();
        string getName(){
            return name;
        }
        string getAddress(){
            return address;
        }
        string getPhone(){
            return phone;
        }
        BankAccount& getAccount(){
            return account;
        }
        SavingBankAccount& getSavingAcc(){
            return SavingAcc;
        }



};
Client::Client()
{

    int choice;
    cout << "Please Enter Client Name =========> ";
        cin.clear();
        cin.sync();
        getline(cin,name);
    cout << "Please Enter Client Address =======> ";
        cin.clear();
        cin.sync();
        getline(cin, address);
    cout << "Please Enter Client Phone =======> ";
    cin >> phone;

    cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
    cin >> choice;
    if(choice == 1){
        double bal;
        cout << "Please Enter the Starting Balance: ";
        cin >> bal;
        account.setBalance(bal);
        cout << "An account was created with ID " << account.getID()<<" and Starting Balance " << bal <<" L.E. "<<endl;
        cout << "-------------------------------------------------------------------" << endl;
    }else if(choice == 2){
        account.setID("0");
        double bal;
        while(true){
            cout << "Please Enter the Starting Balance: ";
            cin >> bal;
            if(bal < 1000){
                cout << "sorry , SavingAccount starts with 1000 L.E." <<endl;
            }else{
                SavingAcc.setBalance(bal);
                break;
            }
        }

        cout << "An account was created with ID " << SavingAcc.getID()<<" and Starting Balance " << bal <<" L.E. "<<endl;
        cout << "-------------------------------------------------------------------" << endl;
    }
}
#endif // CLIENT_H
