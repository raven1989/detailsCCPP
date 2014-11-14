#include<iostream>
#include<cstdlib>
using namespace std;


void* operator new(size_t size){
	std::cout<<"call new"<<std::endl;
	return malloc(size);
}

void operator delete(void* p){
	free(p); //不用担心,调用这个函数的delete运算符会判断p是否为空，
	//可以通过注释掉new函数中的malloc证明，注释掉以后即使用运算符delete a也调用不到delete函数
	cout<<"call delete"<<endl;
}


class A{
public:
	A(){
		cout<<"call constructor A"<<endl;
	}
	~A(){
		cout<<"call destructor A"<<endl;
	}

	/*
	void* operator new(size_t size){
		cout<<"call new A"<<endl;
		return malloc(size);
	}
	*/

	void operator delete(void* p){
	  free(p); //不用担心,调用这个函数的delete运算符会判断p是否为空
		cout<<"call delete A"<<endl;
	}
};

int main(int argc, char* argv[]){
	int status = 1;
	cout<<"new运算符调用全局的void* new(size_t size)申请内存，再调用构造函数；如果类内重载了new则调用重载的："<<endl;
	A* a = new A;
	cout<<a<<endl;
	delete a;

	return status;
}
