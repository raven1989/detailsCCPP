#include<iostream>
#include<map>

using namespace std;

class M{
public:
  static M& instance(){
    if(instance_==NULL){
      instance_ = new M;
    }
    return *instance_;
  }
  long findWord(string word){
    map<string, long>::iterator it = m.find(word);
    if(it != m.end()){
      return it->second;
    }
    return -1L;
  }
private:
  M(){
    m["ok"] = 1;
    m["no"] = 2;
    m["omg"] = 3;
  }
private:
  static M * instance_;
  map<string, long> m;
};

M* M::instance_ = NULL;

int main(){
  long res = M::instance().findWord("ok");
  cout << "ok" << " : " << res << endl;
  return 0;
}
