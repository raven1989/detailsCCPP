/*
 * 检查是big endian还是little endian。
 * 利用union始终从低地址开始存储
 * */
#include<iostream>
using namespace std;

#define MY_BIG_ENDIAN 0
#define MY_LITTLE_ENDIAN 1

int check_cpu(){
	union w{
		int a;
		char c;
	} tmp; 
	tmp.a=1;
	return (tmp.c==1? MY_LITTLE_ENDIAN:MY_BIG_ENDIAN);
}

int main(){
	cout<<(check_cpu()==MY_BIG_ENDIAN? "Big endian":"Little endian")<<endl;
	return 0;
}
