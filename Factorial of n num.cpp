#include<iostream>
using namespace std;
int main () {
	int n;
	long fectorial=1.0;
	cout<<"Enetr an integer:";
	cin>>n;
	if(n==0){
		cout<<"Error"<<endl;
		
	} else{
		for(int i;i<=n;++i) {
			fectorial*=i;
		}
		cout<<"Factorial of"<<n<<"="<<fectorial;
	}
	return 0;
}
