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

	void operator delete(void* p){
	  free(p); //不用担心,调用这个函数的delete运算符会判断p是否为空
		cout<<"call delete A"<<endl;
	}
	*/
};

int main(int argc, char* argv[]){
	int status = 1;
	cout<<"operator new第二种形式void* operator new(std::size+t size, const std::nothrow_t& nothrow_value) throw()"<<endl;
	cout<<"两种形式的区别是第二种不会抛出异常."<<endl;
	A* a1 = new(nothrow) A;
	delete a1;

	cout<<"operator new第三种形式void* operator new(std::size_t, void* ptr) throw()"<<endl;
	cout<<"第三种形式仅仅返回ptr,不申请空间."<<endl;
	A* a2 = new(NULL) A;
	delete a2;//这里不会调用operator delete,运算符delete回去判断参数a2是否为NULL
	cout<<"我们这样做的效果相当于使用运算符new和delete"<<endl;
	A* a3 = (A*)operator new(sizeof(A));//分配空间
	new(a3) A; //调用构造
	a3->~A(); //调用析构
	operator delete(a3);//释放空间
	return status;
}
