#include<iostream>
using namespace std;
void towerofHanoi(int n,char source,char helper,char destination) {
	if (n==1) {
		cout<<"move disk 1 from "<<source<<" to "<<destination<<endl;
		return ;
	}
	towerofHanoi( n-1,source,destination,helper);
	cout<<"move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	towerofHanoi(n-1,helper,source,destination);
} 
int main() {
	int n;
	cout<<"Enter number of disks:";
	cin>>n;
	cout<<"Steps to solve tower of Hanoi:"<<endl;
	towerofHanoi(n,'A','B','C');
	return 0;
}
