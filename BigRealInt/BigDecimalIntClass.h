#ifndef BIGDECIMALINTCLASS_H
#define BIGDECIMALINTCLASS_H


#include <iostream>
#include <deque>
#include <regex>

using namespace std;


class BigDecimalInt{
private:


public:
    char sign;
    bool checkValidInput(string input);
    string number;
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt &anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    int size();
    int Sign();
    string getNumber();
    void setNumber(string num);
    BigDecimalInt(){}
    BigDecimalInt(string num)
    {
        setNumber(num);
    }
};

class BigReal {
private:
    BigDecimalInt rnumber;
    char pnt = '.';
    BigDecimalInt fracnumber;
public:
    char sign = rnumber.sign;
    BigReal();
    BigReal(double RealNumber);
    BigReal(string RealNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal& source);
    BigReal(BigReal&& source);

    BigReal& operator=(BigReal& other);
    BigReal& operator= (BigReal&& other);
    bool operator< (const BigReal &anotherReal);
    bool operator> (const BigReal &anotherReal);
    bool operator== (BigReal anotherReal);
    int Sign();
    int size();
    friend ostream& operator << (ostream& out,const BigReal& num);
    friend istream& operator >> (istream& out,  BigReal& num);
    void setNumber(string realNumber);
    string changeNumSign(BigReal num, int sign);
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);
    long long point_position(string num1,string num2,char sgn1,char sgn2,char operation);
    void equality(string &num1, string &num2);
    bool remove_zeros_from_left(string &num);
};
#endif // BIGDECIMALINTCLASS_H
