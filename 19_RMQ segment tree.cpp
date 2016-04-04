#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<vector>

using namespace std;

const int MAX=1000005;
std::vector<int> items;
int tree[2*MAX];

int min(int a,int b){
	if (a<b) return a;
	else return b;
}
void read(int &res) {
    res = 0;
    char c = ' ';
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res<<3) + (res<<1) + c - '0', c = getchar();
}
int  buildTree(int l,int r,int p){
	if (l==r) {
		tree[p] = items[l];	
		return tree[p];
	}
	
	int m = (l+r)/2;
	tree[p] = min(buildTree(l,m,p<<1),buildTree(m+1,r,p<<1|1));	
	return tree[p];
}
void update(int x,int y,int l,int r,int t){
	if(l==r) {
		tree[t] = y;return;
	}
	int m = (l+r)/2;
	if(x<=m) {	
	update(x,y,l,m,t<<1);}
	else update(x,y,m+1,r,t<<1|1);
	tree[t] = min(tree[t<<1],tree[t<<1|1]);
}
int query(int x,int y,int l,int r,int t){
	
	if(x<=l&&y>=r) return tree[t];
	int m = (l+r)/2;
	int val = 1e5;
	if(x<=m) val = min(val,query(x,y,l,m,t<<1));
	if(y>m) val = min(val,query(x,y,m+1,r,t<<1|1));	
	return val;
}
int main(){
	int n,q,f,t,a,b;
	scanf("%d",&n);
	items.push_back(-1);
	for(int i=0;i<n;i++) {
		read(t);
		items.push_back(t);
	}	
	buildTree(1,n,1);
	scanf("%d",&q);
	while(q--){
		//scanf("%d%d%d",&f,&a,&b);
		read(f);read(a);read(b);
		if(f) update(a,b,1,n,1);
		else printf("%d\n",query(a,b,1,n,1));
		}	
	return 0;
}
