#include<iostream>
using namespace std;

#define MAX 100005
#define lchild p<<1
#define rchild p<<1|1

int tree[3*MAX];
int cflag[3*MAX];
int sflag[3*MAX];
int price[MAX];
void buildTree(int l, int r, int p){
	if(l==r){
		tree[p] = price[l];
		cflag[p] = 0;
		sflag[p] = -1;	
		return ;
	}
	int m = (l+r)>>1;
	buildTree(l,m,lchild);
	buildTree(m+1,r,rchild);
	tree[p] = tree[lchild] + tree[rchild];
	cflag[p] = 0;
	sflag[p] = -1;
}
void show(int l, int r, int p){
	if(l==r){
		cout << l <<"~"<< r <<"  "<< tree[p] << sflag[p] << " "<<cflag[p]<<endl;
		return ;
	}
	int m = (l+r)>>1;
	show(l,m,lchild);
	show(m+1,r,rchild);
	
	cout << l <<"~"<< r <<"  "<< tree[p] << sflag[p] << " "<<cflag[p]<<endl;
}
void release(int l, int r,int p){
	if(l!=r){
		int m = (l+r)>>1;
		if(sflag[p] != -1){
			sflag[lchild] = sflag[p];
			sflag[rchild] = sflag[p];
			cflag[lchild] = 0;
			cflag[rchild] = 0;
			tree[lchild] = (m-l+1) * sflag[p];
			tree[rchild] = (r-m) * sflag[p];
			sflag[p] = -1;
		}
		if(cflag[p] != 0){
			tree[lchild] += (m-l+1) * cflag[p];
			tree[rchild] += (r-m) * cflag[p];
			cflag[lchild] += cflag[p];
			cflag[rchild] += cflag[p];			
			cflag[p] = 0;
		}
	}
}
void setupdate(int l, int r, int v, int L, int R, int p){
	if(L==R){
		tree[p] = v;
		cflag[p] = 0;
		sflag[p] = -1;
		return;
	}
	if(sflag[p]!=-1||cflag[p]!=0) release(L,R,p);
	if(l<=L&&r>=R){
		tree[p] = (R-L+1) * v;
		sflag[p] = v;
		cflag[p] = 0;
		return;
	}
	int M = (L+R)>>1;
	if(l<=M) setupdate(l,r,v,L,M,lchild);
	if(r>M) setupdate(l,r,v,M+1,R,rchild);
	tree[p] = tree[lchild] + tree[rchild];
	return ;
}
void addupdate(int l, int r, int v, int L, int R, int p){
	if(L==R){
		tree[p] += v;
		cflag[p] = 0;
		sflag[p] = -1;
		return;
	}
	if(sflag[p]!=-1||cflag[p]!=0) release(L,R,p);
	if(l<=L&&r>=R){
		tree[p] += (R-L+1) * v;
		sflag[p] = -1;
		cflag[p] += v;
		return;
	}	
	int M = (L+R)>>1;
	if(l<=M) addupdate(l,r,v,L,M,lchild);
	if(r>M) addupdate(l,r,v,M+1,R,rchild);
	tree[p] = tree[lchild] + tree[rchild];
	return ;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<=n;i++) cin >> price[i];
	buildTree(0,n,1);
	while(m--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a)setupdate(b,c,d,0,n,1);
		else addupdate(b,c,d,0,n,1);
		cout << tree[1]<<endl;
//		cout << endl;
//		show(0,n,1);
//		cout <<endl;
	
	}
	return 0;
}
