#include<iostream>
using namespace std;
/*
 * 1.引用不能为null
 * 2.指针可以重新被赋值
 * 3.operator[]操作符必须使用引用做返回值
 * 4.引用没有const
 * 5.sizeof，引用返回指向对象的大小
 * 6.作为成员变量，只占指针的大小
 * 7.指针和引用的自增操作意义不一样
 * */
class A{
  int *b;
  int & d;
  int a;
  int c;
};
int main(){
  int a = 1.0;
  int & ra = a;
  int * pa = &a;
  int * p = NULL;
  cout<<"sizeof reference:"<<sizeof(ra)<<endl;
  cout<<"sizeof pointer:"<<sizeof(pa)<<endl;
  cout<<"sizeof pointer:"<<sizeof(p)<<endl;
  cout<<"sizeof A:"<<sizeof(A)<<endl;
  return 0;
}
