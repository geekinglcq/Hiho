#include<iostream> 
using namespace std;
int main(){
	int t,n,k,p,i;
	cin>>t;
	while(t--){
		cin>>n>>k;
		p=0;
		if(n==1)cout<<"0"<<endl;
		else{
		if(n<k)
		for(i=2;i<=n;i++)p=(p+k)%i;
		cout<<p<<endl;
		}
	}	
	return 0;
}
