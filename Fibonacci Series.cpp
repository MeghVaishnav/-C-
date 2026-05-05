#include<iostream>
using namespace std;

int main(){
	int n,t1=0,t2=1,nexttearm=0;
	cout<<"Enter numbers of tearms:";
	cin>>n;
	cout<<"Fibonacci Series:";
	for(int i=0;i<=n;++i) {
		if(i==1) {
			cout<<t1<<", ";
			continue;
		} if(i==2){
			cout<<t2<<", ";
			continue;
		}
		nexttearm=t1+t2;
		t1=t2;
		t2=nexttearm;
		cout<<nexttearm<<", ";
			
		
	}
	return 0;
}

