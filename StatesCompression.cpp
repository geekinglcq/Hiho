#include<iostream>
using namespace std;

int main(){
	const int max=1000000007;
	int n,m;
	int dp[2][1<<6]={0};
	int i,j,x;	
	cin >> n >> m;
	int s = 1 << m;
	bool k=true;
	for(i=0;i<n;i++){
		for(j=0;j<s;j++){
			for(x=0;x<m;x++){
				if((j>>x)&0x1) continue;
				dp[!k][]=dp[!k][]+dp[k][j];
				if(!(j>>(x+1)&0x1)) dp[k][]=dp[k][]+dp[k][j];
			}
		}
	}
	cout << ((5>>1)&0x1);
	return 0;
}
