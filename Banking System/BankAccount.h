#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
    protected:
        string AccountType = "Basic";
        string ID;
        double balance;

    public:
        static int counter;
        BankAccount();
        BankAccount(double bal);
        virtual bool deposit(double amount);
        virtual bool withdraw(double amount);
        string getID(){
            return ID;
        }
        double getBalance(){
            return balance;
        }

        void setBalance(double bal){
            balance = bal;
        }
        void getAccountInfo(){
            cout << " Account ID: " << getID()<< " Account Type: " << AccountType<<endl;
            cout << " Balance: " << getBalance() << endl;
        }
        void setID(string s){
            ID = s;
        }
};

int BankAccount::counter = 0;

BankAccount::BankAccount()
{
    counter++;
    ID = "FCAI-00"+to_string(counter);
    balance = 0.0;
}

BankAccount::BankAccount(double bal)
{
    counter++;
    ID = "FCAI-00"+to_string(counter);
    balance = bal;
}

bool BankAccount::deposit(double amount) {
    setBalance(balance+amount);
    return true;
}
bool BankAccount::withdraw(double amount) {

    if (balance >= amount){
        setBalance(balance - amount) ;
        return true;
    }else{
        cout << "Sorry. This is more than what you can withdraw. " <<endl;
        return false;
    }
}
#endif // BANKACCOUNT_H
