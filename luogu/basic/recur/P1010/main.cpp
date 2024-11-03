#include <iostream>
#include <string>
using namespace std;
// str p2(int)
string p2(int x) {
	string result;
	for (int i=14;i>=2;--i) {
		if (x&(1<<i)) {
			result+="2(";
			result+=p2(i);
			result+=")+";
		}
	}
	if (x&2) result+="2+";
	if (x&1) result+="2(0)+";
	result.pop_back();
	return result;
}
int main(){
	int x;
	cin>>x;
	cout<<p2(x);
}