#include<iostream>
using namespace std;


int main()
{
	int ms[8][9]={{8,1,6,3,5,7,4,9,2},{6,1,8,7,5,3,2,9,4},{4,9,2,3,5,7,8,1,6},{2,9,4,7,5,3,6,1,8},{6,7,2,1,5,9,8,3,4},{8,3,4,1,5,9,6,7,2},{2,7,6,9,5,1,4,3,8},{4,3,8,9,5,1,2,7,6}};
	int ex[9];
	for(int i=0;i<9;i++) cin >>ex[i];
	int  count=0;
	int tmp=0;
	for(int i=0;i<8;i++){
		bool flag=true;
		for(int j=0;j<9;j++){
			if(ms[i][j]!=ex[j]&&ex[j]!=0) flag=false;
		}
		if (flag) {
			count++;
			tmp=i;
		}
	}
	if(count>1) cout<<"Too Many";
	else{
		for(int j=0;j<9;j++){
			cout <<ms[tmp][j]<<" ";
			if(!((j+1)%3))cout <<endl;
		}
	}
	 
	return 0;
}
