#include<iostream>
#include "BigReal.hpp"
#include "BigDecimalIntClass.h"
using namespace std ;


int main(){
	BigDecimalInt rr("-5643564");
	BigReal x("-34245343.45543545454")  , e  ,a(rr);
	BigReal g(x);
	e =x;
	cout<<e.str() << "\n" <<  a.str() ;
	
	return 0 ;
}