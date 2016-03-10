
#include<iostream>
#include<math.h>
using namespace std;

int bitcount(int x){
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	//cout<<x<<endl;cout<<(x & 0x3333)<<endl;
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	//cout<<x<<endl;
	x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
	//cout<<x<<endl;
	x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
	//cout<<x<<endl;
}
int main()
{ 


    int n,m,q;
    cin >> n>> m >>q;
	int i,j;
    int amount=1<<(m-1);
    int w[1002];
    for(i=0;i<n;i++){
        cin >>w[i];
    }
    int score[1025][2]={0};

	j=0;
	if(q>=m){
		int t=0;
		for(i=0;i<n;i++) t+=w[i];
		cout <<t;
	}
	else{
		int k=0;
	
    for(i=0;i<n;i++){
    	 k=!k; 
    	if(i<m)amount=1<<(i+1);else amount = 1<<(m-1);
   		for(j=0;j<amount;j++){		   		
			int count=bitcount(j);
			cout<<score[j][!k]<<" ";
			if(count<q&&(score[j/2+(1<<(m-2))][k]<score[j][!k]+w[i]))score[j/2+(1<<(m-2))][k]=score[j][!k]+w[i];
			
			if(score[j/2][k]<score[j][!k])score[j/2][k]=score[j][!k];			
		}
	cout <<endl;
    }    
    int max =-1;
    for(j=0;j<amount;j++){
    	{
		 if(score[0][j]>max) max = score[0][j];
		 if(score[1][j]>max) max = score[1][j];
		}
	}
	cout << max;
}
    return 0;
}
