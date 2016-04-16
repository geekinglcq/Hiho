#include<iostream>
#define N 100000
using namespace std;
char a[N],b[N],c[N];

int go(int x,int n) {
	int f = 1;
	b[1] = x; b[2] = a[1] - b[1]; if(b[2]<0||b[2]>1) f = 0;
	for(int i = 3;f && i <= n+1; i++) {
		b[i] = a[i-1] - b[i-1] - b[i-2];
		if(b[i]<0||b[i]>1) f = 0;
	}
	if(f && (b[n+1]!=0)) f = 0;
	return f;
}
int main()
{
	int n,t,x,y,z,f,r;
	cin >> t;
	for(;t--;) {
		cin >> n;
		for(int i=1;i<=n;i++) {
			cin >> x;
			a[i] = x; b[i] = 0; c[i] = 0;
		}
		char mask = 0;
		if(go(0,n)) {
			mask ++;
			for(int i=1;i<=n;i++) c[i] += b[i];
		}
		if(go(1,n)) {
			mask ++;
			for(int i=1;i<=n;i++) c[i] += b[i];
		}
		r = 0;
		for(int i=1;i<=n;i++) if(c[i]==mask) r++;
		cout<<r; for(int i=1;i<=n;i++) if(c[i]==mask) cout<<" "<<i;cout<<endl;
		r = 0;
		for(int i=1;i<=n;i++) if(c[i]==0) r++;
		cout<<r; for(int i=1;i<=n;i++) if(c[i]==0) cout<<" "<<i; cout<<endl;
	}
	return 0;
}

