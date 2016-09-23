#include<iostream>
#include<vector>

using namespace std;

int main(){
	int src[] = {3,5,6,8}; // must already be sorted
	vector<int> v(src, src+sizeof(src)/sizeof(int));
	// Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
	// 序列中大于等于9的第一个元素，即以9做lower bound的第一个元素，[9, it]
	vector<int>::iterator it = lower_bound(v.begin(), v.end(), 9);
	if(it!=v.end()){
		cout << (*it) << endl;
	}
	// Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
	// [8, it]
	// 两个其实返回的是同一个东西，只是lower_bound包含等于，upper_bound只有大于
	it = upper_bound(v.begin(), v.end(), 8);
	if(it!=v.end()){
		cout << (*it) << endl;
	}
	return 0;
}
