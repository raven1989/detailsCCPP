#include<iostream>
#include<cmath>
using namespace std;

double NewtonSqrt(double n){
	double x = n/2;
	double tmp = x;
	do{
		tmp = x;
		x = x - (x*x-n)/(2*x);
	}while(fabs(x-tmp)>1e-5);
	return x;
}

int main(){
	cout << NewtonSqrt(3.0) << endl;
	return 0;
}
