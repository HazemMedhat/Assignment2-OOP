#include "BigDecimalIntClass.h"




long long pos1 = 0, pos2 = 0, f_pos = 0;
// regex function that checks the validation of the input.
bool BigDecimalInt :: checkValidInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}

// constructor that takes a string as an input.

string BigDecimalInt :: getNumber()
{
    return number;
}

void BigDecimalInt :: setNumber(string num)
{
    bool validNumber = checkValidInput(num);
    if(validNumber)
    {
        number = num;
        if(number[0] == '+')
        {
            number.erase(0,1);
            sign = '+';
        }
        else if (number[0] == '-')
        {
            number.erase(0,1);
            sign = '-';
        }
        else
        {
            sign = '+';
        }
    }
}

// operator < overloading function.
bool BigDecimalInt :: operator < (const BigDecimalInt& anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2)
    {
        comp1 += '0';
        len1++;
    }
    while (len2 < len1)
    {
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 < comp2;
    }
    else
    {
        return comp1 > comp2;
    }
}

// operator > overloading function.
bool BigDecimalInt :: operator > (const BigDecimalInt &anotherDec)
{
    string comp1 = "", comp2 = "";
    long long len1 = number.length(), len2 = anotherDec.number.length();

    while (len1 < len2)
    {
        comp1 += '0';
        len1++;
    }
    while (len2 < len1)
    {
        comp2 += '0';
        len2++;
    }
    comp1 += number;
    comp2 += anotherDec.number;

    if(sign == '-' && anotherDec.sign == '+')
    {
        return false;
    }
    else if(sign == '+' && anotherDec.sign == '-')
    {
        return true;
    }
    else if(sign == '+' && anotherDec.sign == '+')
    {
        return comp1 > comp2;
    }
    else
    {
        return comp1 < comp2;
    }
}

// operator == overloading function.
bool BigDecimalInt :: operator == (const BigDecimalInt anotherDec)
{
    if (sign == anotherDec.sign && number == anotherDec.number)
    {
        return true;

    }
    else
    {
        return false;
    }
}
// operator = overloading function.
BigDecimalInt& BigDecimalInt :: operator = (BigDecimalInt &anotherDec)
{
    sign = anotherDec.sign;
    number = anotherDec.number;
    return *this;
}

// // operator + overloading function.
BigDecimalInt BigDecimalInt :: operator + (BigDecimalInt number2)
{
    BigDecimalInt result;
    char signNumber1 = sign, signNumber2 = number2.sign;

    string num1 = number, num2 = number2.number;
    while (num1.length() < num2.length())
    {
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length())
    {
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2)
    {
        result.sign = signNumber1;

        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;

        while (it1 != num1.rend())
        {
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if(twoDigitsSum >= 10)
            {
                carry = 1;
            }
            result.number = char((twoDigitsSum % 10) + '0') + result.number;
            *(it1 + 1) = char (((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }

        if(carry)
        {
            result.number = char ((carry) + '0') + result.number;
        }

    }
    else
    {
        deque<long long> d;
        string res = "";

        if (num1 < num2)
        {
            swap(num1, num2);
            swap(signNumber1,signNumber2);
        }

        for (long long i = num1.length() - 1; i >= 0; i--)
        {
            if (num1[i] < num2[i])
            {
                num1[i] = char (((num1[i] - '0') + 10) + '0');
                num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
            else
            {
                d.push_front((num1[i] - '0') - (num2[i] - '0'));
            }
        }

        bool right = false;
        for (auto i : d)
        {
            res += to_string(i);
        }

        for (long long i = 0; i < res.length(); i++)
        {
            if (res[i] != '0')
            {
                right = true;
            }
            if (!right && res[i] == '0')
            {
                res.erase(i, 1);
                i--;
            }
        }
        if(res.empty())res="0";
        result.sign = signNumber1;
        result.number = res;
    }
    return result;
}

// operator - overloading function.
BigDecimalInt BigDecimalInt :: operator - (BigDecimalInt anotherDec)
{
    BigDecimalInt obj;
    string strmin = "", res = "";
    deque<long long> d;


    if (number.length() > anotherDec.number.length())
    {
        for (long long i = 0; i < number.length() - anotherDec.number.length(); i++)
        {
            strmin += '0';
        }
        strmin += anotherDec.number;
        anotherDec.number = strmin;
    }
    else if (number.length() < anotherDec.number.length())
    {
        for (long long i = 0; i < anotherDec.number.length() - number.length(); i++)
        {
            strmin += '0';
        }
        strmin += number;
        number = strmin;
    }
    bool ok = false;
    if (number < anotherDec.number)
    {
        swap(number, anotherDec.number);
        ok = true;
    }
    bool nv = true;
    if (sign == '-' && anotherDec.sign == '-')
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        ok = !ok;
    }
    else if ((sign == '-' || anotherDec.sign == '-'))
    {
        string num1 = number, num2 = anotherDec.number;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;

        while (it1 != num1.rend())
        {
            int twoDigitsSum;
            carry = 0;
            twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
            if (twoDigitsSum >= 10)
            {
                carry = 1;
            }
            res = char((twoDigitsSum % 10) + '0') + res;
            *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
            it1++;
            it2++;
        }

        if (carry)
        {
            res = char((carry) + '0') + res;
        }
        if (sign == '-')
        {
            nv = false;
        }
    }
    else
    {
        for (long long i = number.length() - 1; i >= 0; i--)
        {
            if (number[i] < anotherDec.number[i])
            {
                number[i] = char (((number[i] - '0') + 10) + '0');
                number[i - 1] = char (((number[i - 1] - '0') - 1) + '0');
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
            else
            {
                d.push_front((number[i] - '0') - (anotherDec.number[i] - '0'));
            }
        }
        nv = true;
    }
    if (!nv || ok)
    {
        obj.sign = '-';
    }
    else
    {
        obj.sign = '+';
    }
    bool right = false;
    for (auto i : d)
    {
        res += to_string(i);
    }
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }
    if(res.empty())res="0";
    obj.number = res;
    return obj;
}

// function to return the size of number.
int BigDecimalInt :: size()
{
    return number.size();
}

int BigDecimalInt :: Sign()
{
    if (sign == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// operator << overloading function.
ostream &operator << (ostream &out, BigDecimalInt num)
{
    if(num.sign == '+')
    {
        out << num.number;
    }
    else
    {
        out << num.sign << num.number;
    }
    return out;
}

BigReal::BigReal()
{

}

BigReal::BigReal(double RealNumber = 0.0)
{
    rnumber.setNumber("0");
    fracnumber.setNumber("0");
}
BigReal::BigReal(string RealNumber)
{
    int i = RealNumber.find('.');
    rnumber.setNumber(RealNumber.substr(0, i));
    fracnumber.setNumber(RealNumber.substr(i + 1));
}
BigReal::BigReal(BigDecimalInt bigInteger)
{
    rnumber.number = bigInteger.getNumber();
}
BigReal::BigReal(const BigReal& source) : rnumber{ source.rnumber }, fracnumber{ source.fracnumber } {}
BigReal::BigReal(BigReal&& source) : rnumber{ source.rnumber }, fracnumber{ source.fracnumber } {}

BigReal& BigReal:: operator=(BigReal& other)
{
    this->rnumber = other.rnumber;
    this->fracnumber = other.fracnumber;
}
BigReal& BigReal:: operator= (BigReal&& other)
{
    if (this != &other)
    {
        rnumber = other.rnumber;
        fracnumber = other.fracnumber;
    }
    return *this;
}

bool BigReal::operator< (const BigReal &anotherReal)
{
    if(this->rnumber < anotherReal.rnumber)
        return true;
    else if(this->rnumber > anotherReal.rnumber)
        return false;
    else if(this->rnumber == anotherReal.rnumber)
    {
        if(this->fracnumber < anotherReal.fracnumber)
        return true;
        else if(this->fracnumber > anotherReal.fracnumber)
        return false;
    }
}
bool BigReal::operator> (const BigReal &anotherReal)
{
    if(this->rnumber > anotherReal.rnumber)
        return true;
    else if(this->rnumber < anotherReal.rnumber)
        return false;
    else if(this->rnumber == anotherReal.rnumber)
    {
        if(this->fracnumber > anotherReal.fracnumber)
        return true;
        else if(this->fracnumber < anotherReal.fracnumber)
        return false;
    }
}

bool BigReal::operator== (BigReal anotherReal)
{
    if(this->rnumber == anotherReal.rnumber && this->fracnumber == anotherReal.fracnumber)
        return true;
    else
        return false;
}
int BigReal:: Sign()
{
    this->rnumber.Sign();
}


int BigReal:: size()
{
    return this->rnumber.size() + this->fracnumber.size();
}

ostream& operator << (ostream& out,const BigReal& num)
{
    out << num.rnumber << num.pnt<< num.fracnumber;
    return out;
}

istream& operator >> (istream& in, BigReal& num){
    string s;
    cout << "Please enter a big real number: ";
    in >> s;
    num.setNumber(s);
    return in;
};
void BigReal::setNumber(string realNumber){
    string s1 = "";
    string s2 = "";

    for(int i = 0;i < realNumber.length(); i++){
        if(realNumber[i] == '.'){
            break;
        }else{
            s1 += realNumber[i];
        }
    }
    rnumber.setNumber(s1);
    for(int i = s1.length()+1 ;i < realNumber.length();i++){
        s2 += realNumber[i];
    }
    fracnumber.setNumber(s2);
}

// operator +
BigReal BigReal:: operator+(BigReal &anotherBigReal){
    BigReal result("");
    this->equality(rnumber.number,anotherBigReal.rnumber.number);
    this->remove_zeros_from_left(this->rnumber.number);
    this->remove_zeros_from_left(anotherBigReal.rnumber.number);
    long long position = this->point_position(this->rnumber.number,anotherBigReal.rnumber.number,Sign(),anotherBigReal.Sign(),'+');

    // to add sign to the number as Bigdecimal constructor takes only string not object and it checks is the sign of string so i must pass the numbers to it by its sign
    this->rnumber.number.insert(this->rnumber.number.begin(), this->Sign());
    BigDecimalInt num1(this->rnumber.number);
    // erasing the added sign as i already stored it
    this->rnumber.number.erase(this->rnumber.number.begin());

    anotherBigReal.rnumber.number.insert(anotherBigReal.rnumber.number.begin(),anotherBigReal.Sign());
    BigDecimalInt num2(anotherBigReal.rnumber.number);
    anotherBigReal.rnumber.number.erase(anotherBigReal.rnumber.number.begin());


    BigDecimalInt res = num1 + num2;
    result.rnumber.number = res.getNumber();
    char sign_=res.Sign();
    if (sign_)
        result.sign = '+';
    else
        result.sign = '-';




    // to check if carry found then we must shifting the location of point
    long long mx = max(rnumber.number.length(),anotherBigReal.rnumber.number.length());
    long long mn = min(rnumber.number.length(),anotherBigReal.rnumber.number.length());
    if (sign == anotherBigReal.sign)
        if (result.rnumber.number.length() > mx)
            position++;

    if (sign != anotherBigReal.sign)
    {
        if (result.rnumber.number.length() == 1)
            position = 1;
        else
        {
            if (result.rnumber.number.length() > mn)
                position = position + (result.rnumber.number.length()-mn);

            else if (result.rnumber.number.length() < mn)
                position -= (mn-result.rnumber.number.length());
        }

    }


    result.rnumber.number.insert(result.rnumber.number.begin()+position,'.');

    this->remove_zeros_from_left(rnumber.number);
    this->remove_zeros_from_left(anotherBigReal.rnumber.number);
    rnumber.number.insert(rnumber.number.begin()+pos1,'.');
    anotherBigReal.rnumber.number.insert(anotherBigReal.rnumber.number.begin()+pos2,'.');

    return result;


}

// operator -
BigReal BigReal:: operator-(BigReal &anotherBigReal)
{
    BigReal result("");
    equality(rnumber.number,anotherBigReal.rnumber.number);
    this->remove_zeros_from_left(rnumber.number);
    this->remove_zeros_from_left(anotherBigReal.rnumber.number);
    long long position = point_position(this->rnumber.number,anotherBigReal.rnumber.number,sign,anotherBigReal.sign,'-');

    // to add sign to the number as Bigdecimal constructor takes only string not object and it checks is the sign of string so i must pass the numbers to it by its sign
    this->rnumber.number.insert(this->rnumber.number.begin(), this->sign);
    BigDecimalInt num1(this->rnumber.number);
    // erasing the added sign as i already stored it
    this->rnumber.number.erase(this->rnumber.number.begin());

    anotherBigReal.rnumber.number.insert(anotherBigReal.rnumber.number.begin(),anotherBigReal.sign);
    BigDecimalInt num2(anotherBigReal.rnumber.number);
    anotherBigReal.rnumber.number.erase(anotherBigReal.rnumber.number.begin());


    BigDecimalInt res = num1 - num2;

    result.rnumber.number = res.getNumber();
    char sign_=res.sign;
    if (sign_)
        result.sign = '+';
    else
        result.sign = '-';


    // to check if carry found then we must shifting the location of point
    long long mx = max(rnumber.number.length(),anotherBigReal.rnumber.number.length());
    long long mn = min(rnumber.number.length(),anotherBigReal.rnumber.number.length());
    if (sign == anotherBigReal.sign)
    {
        if (result.rnumber.number.length() == 1)
            position = 1;
        else
        {
            if (result.rnumber.number.length() > mn)
                position = position + (result.rnumber.number.length()-mn);

            else if (result.rnumber.number.length() < mn)
                position -= (mn-result.rnumber.number.length());
        }



    }


    if (sign != anotherBigReal.sign)
    {
        if (result.rnumber.number.length() > mx)
            position++;

    }


    result.rnumber.number.insert(result.rnumber.number.begin()+position,'.');

    rnumber.number.insert(rnumber.number.begin()+pos1,'.');
    anotherBigReal.rnumber.number.insert(anotherBigReal.rnumber.number.begin()+pos2,'.');

    return result;


}




void BigReal::equality(string &num1, string &num2)
{
    pos1 = num1.find('.');
    pos2 = num2.find('.');



    string temp1 = num1.substr(pos1+1,num1.length());
    num1.erase(num1.begin()+pos1,num1.end());
    string temp2 = num2.substr(pos2+1,num2.length());
    num2.erase(num2.begin()+pos2,num2.end());

    if (temp1.size() < temp2.size()){
        int x = temp2.size() - temp1.size();
        for (long long i = 0; i < x ; ++i)
        {
            temp1 += '0';
        }

    }

    else if (temp1.size() > temp2.size()){
        int x = temp1.size() - temp2.size();
        for (long long i = 0; i < x ; ++i)
        {
            temp2 += '0';
        }


    }




    num1 += temp1;
    num2 += temp2;
    long long x = num2.length() - num1.length();

    if (x > 0){
        for (int i = 0; i < x; ++i)
        {
            num1 = "0" + num1;
        }
    }

    else if (x < 0){
        x = -x;
        for (int i = 0; i < x; ++i)
        {
            num2 = "0" + num2;
        }
    }



}

long long BigReal::point_position(string num1,string num2,char sgn1,char sgn2,char operation)
{
    if (operation == '+')
    {
        if ((sgn1 == '+' and sgn2 == '+') or (sgn1 == '-' and sgn2 == '-'))
        {
            if (num1.length() > num2.length())
                f_pos = pos1;

            else
                f_pos = pos2;

        }

        else if ((sgn1 == '+' and sgn2 == '-') or (sgn1 == '-' and sgn2 == '+'))
        {
            if (num1.length() < num2.length())
                f_pos = pos1;

            else
                f_pos = pos2;
        }
    }

    else if (operation == '-'){
        if (sgn1 == sgn2){
            if (num1.length() < num2.length())
                f_pos = pos1;

            else
                f_pos = pos2;
        }

        else{
            if (num1.length() > num2.length())
                f_pos = pos1;
            else
                f_pos = pos2;
        }
    }

    return f_pos;
}

bool BigReal::remove_zeros_from_left(string &num)
{
    int i = 0;
    while(num[i] == '0'){
        num.erase(num.begin());
    }
    if (num.empty())
        num = "0";
    return true;

}
