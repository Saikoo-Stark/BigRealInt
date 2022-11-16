#ifndef BIG_REAL_HPP
#define BIG_REAL_HPP

#include <string>
#include <regex>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal
{
private:
    string dec ;
    string frac ;
    char sign_ = '+' ;
    void zeroRemover(BigReal &num);
    bool isValid(string num);

public:

   
    BigReal(); 
    BigReal(double num ); 
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal &other);
    BigReal setNumber(string other);
    BigReal(BigReal &&other);
    string str();
    BigReal &operator=(BigReal &other);
    BigReal &operator=(BigReal &&other);
    
    BigReal operator+(BigReal other);
    BigReal operator-(BigReal other);

    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    int size();
    int sign();
    friend ostream &operator<<(ostream &out, BigReal num);
    friend istream &operator>>(istream &out, BigReal num);
};

#endif
