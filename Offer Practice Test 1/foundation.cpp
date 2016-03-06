#include<iostream>
#include<algorithm>
using namespace std;

int min(int a,int b){
	//cout <<endl<<"a "<<a<<",b "<<b<<endl;
	if(a<b||b==0) return a;
	else return b;
}
int main() {
	int q;
	int n,m,k,t;
	int i,j;
	unsigned int a[105],b[105];
	cin >>q;
	while(q--){
		cin >>n>>m>>k>>t;
		
		for(i=0;i<m;i++) cin >> a[i];
		for(i=0;i<m;i++) cin >> b[i];
		//int *ins=new int[10002];
		
		
		for(i=0;i<m;i++)b[i]=b[i]*t;
		long cost=0;
		bool flag2=true;
		for(int tt=0;tt<n;tt++){
		
		long ins[10002]={0};
		bool flag = false; 
		for(i=0;i<m;i++){
		b[i]=b[i]/t;
		if(b[i]) flag=true; 
		}
		if (!flag){
			cout <<"No Answer"<<endl;
			flag2=false;
			break;
		}
		for(i=0;i<m;i++){
			if(b[i]){
			for(j=1;j<b[i];j++)ins[j]=min(a[i],ins[j]);
			for(j=b[i];j<=t;j++)
				{
				ins[j]=min(ins[j-b[i]]+a[i],ins[j]);
			}			
			}
		}
		cost = cost + ins[t];
		
		}
		 if(flag2)cout <<cost<<endl;
	}
	return 0;
}
