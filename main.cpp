#include <iostream>
#include "BigReal.hpp"
#include "BigDecimalIntClass.h"

int main()
{
	BigReal x("444.11111"), y("33333.22"), z;
	cout << "x : " << x << " , "
		 << "y : " << y << endl;

	z = x + y;
	cout << "x+y = " << z << " , expected value = 33777.33111\n";

	z = y - x;
	cout << "y-x = " << z << " , expected value = 32889.10889\n";

	z = x - y;
	cout << "x-y = " << z << " , expected value = -32889.10889\n";

	cout << "x<y = " << (x < y) << " , expected value = 1\n";
	cout << "x>y = " << (x > y) << " , expected value = 0\n";
	cout << "x==y = " << (x == y) << " , expected value = 0\n";
	cout << "y>x = " << (y>x) << " , expected value = 1\n";
	cout << "y<x = " << (y<x) << " , expected value = 0\n";
	cout << "\n====================================\n\n";

	x.setNumber("-324.9435"), y.setNumber("435.435456");
	cout << "x : " << x << " , "
		 << "y : " << y << endl;

	z = x + y;
	cout << "x+y = " << z << " , expected value = 110.491956\n";

	z = y - x;
	cout << "y-x = " << z << " , expected value = 760.378956\n";

	z = x - y;
	cout << "x-y = " << z << " , expected value = -760.378956\n";

	cout << "x<y = " << (x < y) << " , expected value = 1\n";
	cout << "x>y = " << (x > y) << " , expected value = 0\n";
	cout << "x==y = " << (x == y) << " , expected value = 0\n";
	cout << "y>x = " << (y>x) << " , expected value = 1\n";
	cout << "y<x = " << (y<x) << " , expected value = 0\n";

cout << "\n====================================\n\n";

	x.setNumber("-324.9435"), y.setNumber("-324.9435");
	cout << "x : " << x << " , "
		 << "y : " << y << endl;

	z = x + y;
	cout << "x+y = " << z << " , expected value = -649.887\n";

	z = y - x;
	cout << "y-x = " << z << " , expected value = 0\n";

	z = x - y;
	cout << "x-y = " << z << " , expected value = 0\n";

	cout << "x<y = " << (x < y) << " , expected value = 0\n";
	cout << "x>y = " << (x > y) << " , expected value = 0\n";
	cout << "x==y = " << (x == y) << " , expected value = 1\n";
	cout << "y>x = " << (y>x) << " , expected value = 0\n";
	cout << "y<x = " << (y<x) << " , expected value = 0\n";
	
cout << "\n====================================\n\n";	
	BigReal g(BigReal("4.5"));
	cout<< g << endl;
	BigReal n1 ("11.9000000000000000000000000000000001"); 
	BigReal n2 ("2333333333339.1134322222222292"); 
	BigReal n3 = n1 + n2;
	n3 = BigReal(0.7); 
	cout << n3 << endl;
	n3 = n3 + BigReal(0.9); 
	cout<< n3 << endl;
	return 0;
}
