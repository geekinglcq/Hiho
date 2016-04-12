#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;
int map[15][15];
int main(){
	srand((unsigned)time(0));
	int n = 4;
	cout << n <<endl;
	for(int i =1;i<=n;i++){
		for(int j =1;j<=i;j++){
			if(i==j) map[i][j] = 0;
			else map[i][j] = rand()%20;
			map[j][i] = map[i][j];
		}
	}
	for(int i = 1 ;i<=n;i++){
		for(int j=1;j<=n;j++) cout <<map[i][j]<<" ";
		cout<<endl;
		
	}
	return 0;
}
