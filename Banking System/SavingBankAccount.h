#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H
#include "BankAccount.h"

class SavingBankAccount : public BankAccount {
    private:

        double minimumbalance = 1000.0;
    public :
        SavingBankAccount(){
            AccountType = "Saving";
            counter--;
            ID = "FCAI-00"+to_string(counter);

        }
        bool deposit (double amount);
        bool withdraw(double amount);


};

bool SavingBankAccount::deposit(double amount) {
    if (amount<100){
        cout<<"can not do this , please try again with a greater than 100 L.E. "<<endl;
        return false;
    }else{
        setBalance(balance+amount);
        return true ;
    }

}
bool SavingBankAccount::withdraw(double amount) {
    if ((balance-amount)<minimumbalance){
        cout <<"operation failed , Saving account should has 1000 L.E. as minimum balance" << endl;
        cout << "please try again with a smaller amount of money"<<endl;
        return false;
    }else{
        setBalance(balance-amount);
        return true ;
    }

}
#endif // SAVINGBANKACCOUNT_H
