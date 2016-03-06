#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int i,j;
	long long n,q;
	int *pp=new int[1000002];
	cin >> n>>q;
	for(i=0;i<n;i++) cin >> pp[i];
	long long amount=0;
	bool flag = false;
		for(i=0;i<n-1;i++){
			for(j=0;j<n-1-i;j++)
				if(pp[j]<pp[j+1]) swap(pp[j],pp[j+1]);
			amount = 0;
			for(j=0;j<n;j++)
			amount=pp[j]*(j+1)+amount;

			if (amount<=q) {
				cout <<i+2;
				flag = true;
				break;
			}
		}
	if(!flag)cout <<"-1";
	return 0;
}
