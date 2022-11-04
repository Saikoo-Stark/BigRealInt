#include "BigReal.h"
#include "BigDecimalIntClass.h"
#include<iostream>
#include<algorithm>

bool BigReal::isValid(string num){

    int dot = 0 , i = 0  ;


    if(num[0] == '-')
        i++;

    for(; i < num.length() ; i++){
        if(num[i] == '.')
            dot++;

        if(dot > 1 || ((num[i]-'0' > 9 || num[i]-'0' < 0) && num[i] != '.') ){
            return 0 ;
        }
    }

    return 1 ;
}


string BigReal::str(){
    string fraction = "";
    string all = "";

    if(sign_ == '-')
        all += sign_;

    if(this->frac != "0")
        fraction = '.' + frac;

    all+= dec + fraction;
    return all;
}



BigReal::BigReal(){
    dec = "0";
    frac = "0";
    sign_ = '+';
}

BigReal::BigReal(string realNumber){
    if(!isValid(realNumber)){
        cerr<< realNumber << " is invalid number\n";
        exit(0);
    }

    auto beg = realNumber.begin();

    if(realNumber[0] == '-'){
        sign_= '-';
        beg++;
    }

    auto dot = find(beg  , realNumber.end() , '.');

    if(dot != realNumber.end()){

        int start = beg-realNumber.begin();
        int doted = (dot-beg);
        dec = realNumber.substr(start , doted);
        frac = realNumber.substr(doted+start+1 , start-doted);
    }
    else{
        dec = realNumber;
        frac = "0";
    }
    //cout<< "good number = " << realNumber
//	<< "\nsign = " << sign_
//	 <<"\ndec = " << dec
//	 << "\nfrac = " <<  frac
//	 << "\n" ;
}


BigReal::BigReal(BigDecimalInt bigInteger){
    if(bigInteger.sign())
        this->sign_ = '+';
    else
        this-> sign_ = '-';

    this->dec = bigInteger.getNumber();
    this->frac = "0";
}



BigReal::BigReal(const BigReal &other){
    this->sign_ = other.sign_;
    this->dec = other.dec;
    this->frac = other.frac;
}

BigReal::BigReal(BigReal &&other){
    this->sign_ = other.sign_;
    this->dec = other.dec;
    this->frac = other.frac;
}


BigReal & BigReal::operator=(BigReal &other){
    this->sign_ = other.sign_;
    this->dec = other.dec;
    this->frac = other.frac;
    return *this;
}


BigReal & BigReal::operator=(BigReal &&other){
    this->sign_ = other.sign_;
    this->dec = other.dec;
    this->frac = other.frac;
    return *this;
}

BigReal BigReal::operator+(BigReal &other)
{
    BigReal result(".");

    int decimalSize = max(this->dec.size(), other.dec.size());

    for (int i = this->dec.size(); i < decimalSize; ++i) {
        this->dec = '0' + this->dec;
    }
    for (int i = other.dec.size(); i < decimalSize; ++i) {
        other.dec = '0' + other.dec;
    }

    int fractionSize = max(this->frac.size(), other.frac.size());

    for (int i = this->frac.size(); i < fractionSize; ++i) {
        this->frac += '0';
    }
    for (int i = other.frac.size(); i < fractionSize; ++i) {
        other.frac += '0';
    }

    string n1 = this->dec + this->frac, n2 = other.dec + other.frac;
    char biggerSign = '~';
    BigReal biggerNum, smallerNum;
    for (int i = 0; i < n1.size(); ++i) {
        if(n1[i] > n2[i])
        {
            biggerSign = this->sign_;
            biggerNum = *this;
            break;
        }
        else if(n2[i] > n1[i])
        {
            biggerSign = other.sign_;
            biggerNum = other;
            break;
        }
    }
    if(biggerSign == '~') {
        biggerSign = this->sign_;
        biggerNum = *this;
    }
    if(biggerNum == *this)
        smallerNum = other;
    else
        smallerNum == *this;

    if(this->sign_ == other.sign_)
    {
        int remainder = 0;
        for (int i = this->frac.size() - 1; i >= 0; --i) {
            result.frac = to_string(((this->frac[i] - '0') + (other.frac[i] - '0') + remainder) % 10) + result.frac;
            remainder = ((this->frac[i] - '0') + (other.frac[i] - '0') + remainder) / 10;
        }
        for (int i = 0; i < this->dec.size(); ++i) {
            result.dec = to_string(((this->dec[i] - '0') + (other.dec[i] - '0') + remainder) % 10) + result.dec;
            remainder = ((this->dec[i] - '0') + (other.dec[i] - '0') + remainder) / 10;
        }
        if (remainder)
            result.dec = to_string(remainder) + result.dec;
        result.sign_ = this->sign_;
    }
    else
    {
        for (int i = this->frac.size() - 1; i >= 0; --i) {
            if ((biggerNum.frac[i] - '0') - (smallerNum.frac[i] - '0') >= 0)
            {
                result.frac = to_string((biggerNum.frac[i] - '0') - (smallerNum.frac[i] - '0')) + result.frac;
            }
            else
            {
                result.frac = to_string((biggerNum.frac[i] - '0') - (smallerNum.frac[i] - '0') + 10) + result.frac;
                for (int j = i; j >= 0; --j) {
                    if(biggerNum.frac[j] - '0' > 0)
                    {
                        biggerNum.frac[j] = biggerNum.frac[j] - 1;
                    }
                    else
                    {
                        biggerNum.frac[j] = '9';
                    }
                }
            }
        }

        for (int i = 0; i < this->dec.size(); ++i) {
            if ((biggerNum.dec[i] - '0') - (smallerNum.dec[i] - '0') >= 0)
            {
                result.dec = to_string((biggerNum.dec[i] - '0') - (smallerNum.dec[i] - '0')) + result.dec;
            }
            else
            {
                result.dec = to_string((biggerNum.dec[i] - '0') - (smallerNum.dec[i] - '0') + 10) + result.dec;
                for (int j = i; j < this->dec.size(); ++j) {
                    if(biggerNum.dec[j] - '0' > 0)
                    {
                        biggerNum.dec[j] = biggerNum.dec[j] - 1;
                    }
                    else
                    {
                        biggerNum.dec[j] = '9';
                    }
                }
            }
        }

        result.sign_ = biggerSign;
    }
    return result;
}
