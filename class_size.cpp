/*
 * 类的size
 * */
#include<iostream>
using namespace std;
//空类         1 byte
class Empty{};   //编译器为空类申请一个char以标记它的每一个对象
//继承空类的空类  1 byte
class DerivedEmpty:public Empty{};
//非空类       4 bytes
class Three{
	char c;      //字节对齐，所以是4字节
	short i;
};
//继承非空类的空类       4 bytes
class DerivedThreeEmpty:public Three{}; //与父类大小相同
//继承非空类的非空类     6 bytes
class DerivedThreeOne:public Three{
	char k;        //父类中有short，这里也要对齐
};
//有虚函数的类      8 bytes
//虚函数利用函数指针指向一个虚函数表实现，故无论多少虚函数，都只有一个
class VirtualMethod{
	char c;          //与函数指针对齐 +4 bytes
	virtual void nothing(){};    // +4 bytes
	virtual void lazy(){};      // +0 bytes
};
//继承了有虚函数的类的类        8 bytes
//无论是否重写，继承父类的所有虚函数指针
class DerivedVirtualMethod:public VirtualMethod{
	virtual void nothing(){}; //重写父类的虚函数，已经继承了 +4 bytes
	virtual void myOwn(){}; //自己的虚函数 +0 bytes
};
//虚拟继承的类       4 bytes
//虚拟继承通过指针实现，无论几个都是一个指针
class AnotherEmpty{};
class VirtualDerived:virtual public Empty,virtual public AnotherEmpty{};
//含有静态成员的类     1 byte
class StaticMember{
	static int s; //静态成员在数据区，不在栈或者堆中，所以不属于类
	char c;
};
int main(){
	cout<<"expect 1 byte, class Empty: "<<sizeof(Empty)<<endl;
	cout<<"expect 1 byte, class DerivedEmpty: "<<sizeof(DerivedEmpty)<<endl;
	cout<<"expect 4 bytes, class Three: "<<sizeof(Three)<<endl;
	cout<<"expect 4 bytes, class DerivedThreeEmpty: "<<sizeof(DerivedThreeEmpty)<<endl;
	cout<<"expect 6 bytes, class DerivedThreeOne: "<<sizeof(DerivedThreeOne)<<endl;
	cout<<"expect 8 bytes, class VirtualMethod: "<<sizeof(VirtualMethod)<<endl;
	cout<<"expect 8 bytes, class DerivedVirtualMethod: "<<sizeof(DerivedVirtualMethod)<<endl;
	cout<<"expect 4 bytes, class VirtualDerived: "<<sizeof(VirtualDerived)<<endl;
	cout<<"expect 1 byte, class StaticMember: "<<sizeof(StaticMember)<<endl;
	return 0;
}
