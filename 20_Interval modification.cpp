#include<iostream> 
using namespace std;
#define max 1000050
int sum[max*2];
int lazy[max*2];
int weight[max];
void buildTree(int l,int r,int p){
	if(l==r){
		sum[p] = weight[l];
		lazy[p] = -1;
		return ;
	}
	int m = (l+r)/2;
	buildTree(l,m,p<<1);
	buildTree(m+1,r,p<<1|1);
	sum[p] = sum[p<<1] + sum[p<<1|1];
	lazy[p] = -1;
}

void update(int l,int r,int v, int L, int R, int p){
	if(l<=L&&r>=R){
		sum[p] = v*(R-L+1);
		lazy[p] = v;
	}else{
		int M = (L+R)/2;
		if(lazy[p]!=-1){		
			//Transfer lazy label
			sum[p<<1] = (M-L+1)*lazy[p];
			lazy[p<<1] = lazy[p];
			sum[p<<1|1] = (R-M)*lazy[p];
			lazy[p<<1|1] = lazy[p];
			
			//Delete its own lazy label
			lazy[p] = -1;
		}
		
		if(l<=M)update(l,r,v,L,M,p<<1);
		if(r>M)update(l,r,v,M+1,R,p<<1|1);
		sum[p] = sum[p<<1] + sum[p<<1|1];
	}
}

int query(int l, int r, int L, int R, int p){
	if(l<=L&&r>=R){
		return sum[p];
	}else{
		int M = (L+R)/2;
		if(lazy[p]!=-1){		
			//Transfer lazy label
			sum[p<<1] = (M-L+1)*lazy[p];
			lazy[p<<1] = lazy[p];
			sum[p<<1|1] = (R-M)*lazy[p];
			lazy[p<<1|1] = lazy[p];
			
			//Delete its own lazy label
			lazy[p] = -1;
		}
		int temp = 0;
		if(l<=M) temp+=query(l,r,L,M,p<<1);
		if(r>M) temp+=query(l,r,M+1,R,p<<1|1);
		return temp;
	}
}
int main(){
	int n,q,a,b,c,f;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> weight[i];
	buildTree(1,n,1);
//	for(int i=1;i<=2*n;i++) cout<<i<<":" <<sum[i]<<"  ";
	cin >> q;
	while(q--){
		cin >> f;
		if(f){
			cin >> a>> b>> c;
			update(a,b,c,1,n,1);
		}else{
			cin >> a>> b;
			cout <<query(a,b,1,n,1)<<endl;
		}
	}
	return 0;
}
