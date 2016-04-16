#include<iostream>
#include<cstdlib>
#include<ctime> 
#include<fstream>
using namespace std;
int map[15][15];
	int a[200];
	int x[200];
int main(){
	fstream out ("ss.txt",ios::out);
	srand((unsigned)time(0));
	int n = 105;
	int m =2;
	while(m--){
	
	for(int i=1;i<=n;i++) x[i] = rand()%2;
	x[0] =0;x[n+1]=0;
	for(int i=1;i<=n;i++) a[i] = x[i-1] + x[i] + x[i+1];
	out << n <<endl;
	for(int i=1;i<=n;i++) out << a[i] <<" ";
	out <<endl;
	}
	out.close();
	return 0;
}
