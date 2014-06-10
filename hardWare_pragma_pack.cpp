/*
 * 字节对齐：
 * struct,class,union都会进行字节对齐，决定对齐的方法：
 * 取变量列表中最大基本类型的字节m，大于4字节的如double仍按4字节对齐
 * d是默认的对齐字节（通常是8）或者由#pragma pack(d)定义
 * 取m和d中较小者作为对齐标准
 * */
#include<iostream>
using namespace std;
//自定义对齐字节数
//#pragma pack(1)
//char为1,double为8字节但按4字节对齐,取4和默认的8中较小的，所以还是按4对齐
struct s{
	char c;
	int i;
	double d;
};
class a{
	char c;
	long double d;
};
union w{
	char c[11];
	short j;
};

int main(){
	cout<<"float: "<<sizeof(float)<<" bytes"<<endl;
	cout<<"double: "<<sizeof(double)<<" bytes"<<endl;
	cout<<"long: "<<sizeof(long)<<" bytes"<<endl;
	cout<<"long double: "<<sizeof(long double)<<" bytes"<<endl;
	cout<<"struct s{char c; int i; double d;}; "<<sizeof(s)<<" bytes"<<endl;
	cout<<"class a{char c; long double d;}; "<<sizeof(a)<<" bytes"<<endl;
	cout<<"union w{char c[13]; short d;}; "<<sizeof(w)<<" bytes"<<endl;
	return 0;
}
