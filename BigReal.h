#ifndef BIG_REAL_HPP
#define BIG_REAL_HPP

#include <string>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal
{
private:
    string dec ;
    string frac ;
    char sign_ = '+' ;
    bool isValid(string num);
    //void strip(string num)
public:

    //saead part
    BigReal(); //Done
    BigReal(string realNumber); //Done
    BigReal(BigDecimalInt bigInteger); //Done
    BigReal(const BigReal &other); //Done
    BigReal(BigReal &&other); //under_test
    string str(); //Done
    BigReal &operator=(BigReal &other); //Done
    BigReal &operator=(BigReal &&other); //under_test

    //kareem part
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);

    //abdelrahman part
    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    int size();
    int sign();

    friend std::ostream& operator<<(std::ostream& output, BigReal& num);
    friend std::istream& operator>>(std::istream& input, BigReal& num);
};

#endif