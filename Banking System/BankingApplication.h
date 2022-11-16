#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H
#include <bits/stdc++.h>
#include "Client.h"
#include "BankAccount.h"

class BankingApplication
{
    private:
        vector<Client> Clients;


    public:
        BankingApplication();
        void addClient();
        void printClients();
        void withdraw();
        void deposit();
};

BankingApplication::BankingApplication()
{
    int choice;
    while(true){
        cout << "Welcome to FCAI Banking Application" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. List Clients and Accounts" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "0. exit" << endl;
        cout << endl;
        cout << "Please Enter Choice =========> " ;
        cin >> choice;
        if(choice == 1){
            addClient();
        }else if(choice == 2){
            printClients();
            cout << "-------------------------------------------------------------------" << endl;
        }else if (choice == 3){
            withdraw();
            cout << "-------------------------------------------------------------------" << endl;
        }else if(choice == 4){
            deposit();
            cout << "-------------------------------------------------------------------" << endl;
        }else if(choice == 0){
            _Exit(0);
        }else{
            cout << "Wrong input, plz choose from list" << endl;
            cout << "-------------------------------------------------------------------" << endl;
        }

    }

}


void BankingApplication::addClient()
{
    Client c;
    Clients.push_back(c);

}

void BankingApplication::printClients(){
    if(Clients.size()==0){
        cout << " there is no accounts yet , plz create an account first "<< endl;
    }else{
        for(int i = 0; i < Clients.size(); i++){
            cout << "-------------------------- " << Clients[i].getName() << " ------------------" << endl;
            cout << " Address: " <<  Clients[i].getAddress() << endl;
            cout << " Phone: " <<  Clients[i].getPhone() << endl;
            if(Clients[i].getAccount().getID() == "0"){
                Clients[i].getSavingAcc().getAccountInfo();
            }else{
                Clients[i].getAccount().getAccountInfo();
            }
        }
    }
}
void BankingApplication::withdraw(){
    string ID;
    int amount;
    bool found;
    cout << "please Enter Account ID (e.g., FCAI-015) =========> " ;
    cin >> ID;
    for(int i = 0; i < Clients.size(); i++){
        if(Clients[i].getAccount().getID() == ID){
            found = 1;
            Clients[i].getAccount().getAccountInfo();
            while(true){
                cout << "Please Enter The Amount to Withdraw =========> ";
                cin >> amount;
                if(Clients[i].getAccount().withdraw(amount)){
                    break;
                }
            }
            Clients[i].getAccount().getAccountInfo();
            break;
        }else if(Clients[i].getSavingAcc().getID() == ID){
            found = 1;
            Clients[i].getSavingAcc().getAccountInfo();
            while(true){
                cout << "Please Enter The Amount to Withdraw =========> ";
                cin >> amount;
                if(Clients[i].getSavingAcc().withdraw(amount)){
                    break;
                }
            }
            Clients[i].getSavingAcc().getAccountInfo();
            break;
        }else{
            found = 0;
        }
    }
    if(!found){
        cout << "this ID not found " << endl;
    }
}

void BankingApplication::deposit(){
    string ID;
    int amount;
    bool found;
    cout << "please Enter Account ID (e.g., FCAI-015) =========> " ;
    cin >> ID;
    for(int i = 0; i < Clients.size(); i++){
        if(Clients[i].getAccount().getID() == ID){
            found = 1;
            Clients[i].getAccount().getAccountInfo();
            while(true){
                cout << "Please Enter The Amount to deposit =========> ";
                cin >> amount;
                if(Clients[i].getAccount().deposit(amount)){
                    break;
                }

            }
            Clients[i].getAccount().getAccountInfo();
            break;
        }else if(Clients[i].getSavingAcc().getID() == ID){
            found = 1;
            Clients[i].getSavingAcc().getAccountInfo();
            while(true){
                cout << "Please Enter The Amount to deposit =========> ";
                cin >> amount;
                if(Clients[i].getSavingAcc().deposit(amount)){
                    break;
                }
            }
            Clients[i].getSavingAcc().getAccountInfo();
            break;

        }else{
            found = 0;
        }

    }
    if(!found){
        cout << "this ID not found " << endl;
    }
}
#endif // BANKINGAPPLICATION_H
