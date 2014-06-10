/*
 * 指针加减
 * */

#include<iostream>
using namespace std;

int main(){
	int a[]={1,2,3,4,5};
	/* &a==a==&a[0]
	 * &a和a的值的内容相同，但表示的含义不同：
	 * &a表示整个数组的地址，所以&a+1=a+sizeof(a)=a+5，数组越界
	 * a表示数组的首个元素地址，即a=&a[0]，所以a+1=&a[1]
	 * */
	cout<<"&a=   "<<hex<<&a<<endl;
	cout<<"a=    "<<hex<<a<<endl;
	cout<<"&a[0]="<<hex<<&a[0]<<endl;
	cout<<"&a==a==&a[0]"<<endl;
	int* p=(int*)(&a+1);cout<<"*(&a+1)="<<(*p)<<endl;
	cout<<"*(a+1)="<<*(a+1)<<endl;
	return 0;
}
