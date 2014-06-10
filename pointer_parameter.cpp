/*
 * 数组作为参数传递后变成了指针（eg: int a[2] --> int*）
 * */
#include<iostream>
using namespace std;

void pass(int a[]){
	int m=a; // cannot convert 'int *' to 'int'
	cout<<"sizeof parameter a: "<<sizeof(a)<<endl;
}
int main(){
	int a[2];
	int (*p)[2];
	p=a;  //cannot convert ‘int [2]’ to ‘int (*)[2]
	p=&a; //correct
	int* q=a; //correct
	cout<<"sizeof a: "<<sizeof(a)<<endl;
	pass(a);
	return 0;
}
