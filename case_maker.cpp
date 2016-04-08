#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;

int main(){
	srand((unsigned)time(0));
	int n = 80000;
	cout << n <<" 1000"<<endl;
	for(int i = 0;i<= n;i++) {
	cout <<rand()%1000<<" ";
	if (i%500 == 0) cout <<endl;
	}
	cout << endl;
	for(int i= 0;i<20;i++){
		int t = rand()%(n+1);
		cout << rand()%2 << " "<<t<<" "<<t+rand()%(n-t+1) <<" " <<rand()%100<<endl;
	}
	return 0;
}
