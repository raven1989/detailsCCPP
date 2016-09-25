#include<iostream>

using namespace std;

class Sigleton{
private:
  Sigleton(){cout << "Constructing Sigleton" << endl;}
  Sigleton(const Sigleton&){};
  static Sigleton* instance_;
public:
  static Sigleton* instance(){
    if(instance_==NULL){
      //Lock
      if(instance_==NULL){
        instance_ = &(Instance());
        //与下面这个相比，使用local static对象的好处是，它会在程序结束时调用析构函数；
        //这对于一些打开了文件句柄的单例而言十分有用
        //instance_ = new Sigleton;
      }
    }
    //double check的并非万无一失，比如一个线程进入临界区，正在创建对象
    //另一个线程第一次检查instance_已经不是NULL时，到达return，此时单例未创建完成，有机会出问题
    return instance_;
  }
  static Sigleton& Instance(){
    //local static 对象在未调用当前函数前是不会去构造的，
    //利用这个特性，创造出这个完美的单例，参考Effective C++ 4th decipline
    static Sigleton ins;
    return ins;
  }
  ~Sigleton(){cout << "Deconstructing Sigleton" << endl;}
};
Sigleton* Sigleton::instance_ = NULL;

int main(){
  Sigleton::instance();
  return 0;
}
