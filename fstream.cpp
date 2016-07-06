#include<iostream>
#include<fstream>
#include<streambuf>
#include<string>

int main(){
  std::ifstream t("hardWare_checkBigLittleEndian.cpp");
  std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
  std::cout<< str << std::endl;
  t.close();
  return 0;
}
