#include<iostream>
using namespace std;

int main(){
	unsigned short x = 0xf;
	unsigned short f = ~0;
	cout << hex << (x^f) << endl;
	return 0;
}
