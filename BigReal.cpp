#include "BigReal.hpp"
#include "BigDecimalIntClass.h"
#include<iostream>

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

