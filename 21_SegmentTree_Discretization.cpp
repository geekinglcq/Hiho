#include<iostream> 
#include<map>
#include<algorithm> 
#include<set>
#include"math.h">
using namespace std;
#define MAX 100005
#define lchild p<<1
#define rchild p<<1|1
int tree[2*MAX];
int flag[2*MAX];
int s[2*MAX];
int a[MAX];
int b[MAX];
// Map the real coordinate and discrect coordinate
std::map<int,int> distrete;

//Set used to count the amount of post alive finally
std::set<int> v;
void buildTree(int l,int r,int p){
	if(l+1==r){
		tree[p] = 0;
		flag[p] = -1;
		return ;
	}
	tree[p] = 0;
	flag[p] = -1;
	int m = round((l+r)/2.0);
	buildTree(l,m,lchild);
	buildTree(m,r,rchild);
}
void update(int l, int r, int L, int R,int v, int p){
	if(l<=L&&r>=R){
		tree[p] = v;
		flag[p] = 1;
		return ;
	}
	if(flag[p] == 1){
		tree[lchild] = tree[p];
		tree[rchild] = tree[p];
		flag[lchild] = 1;
		flag[rchild] = 1;
		flag[p] = -1;
	}
	int M = round((L+R)/2.0);
	if(l<M) update(l,r,L,M,v,lchild);
	if(r>M) update(l,r,M,R,v,rchild);
	if((tree[lchild] == tree[rchild]) && (tree[lchild]!=-1)) tree[p] = tree[lchild];
		else tree[p] = -1;
}
void stick(int n,int tn){
	for(int i = 1;i<=n;i++){
		int ta,tb;
		std::map<int,int>::iterator it;
		it = distrete.find(a[i]);
		ta = it->second;
		it = distrete.find(b[i]);
		tb = it->second;
		update(ta,tb,1,tn,i,1);		 
//		for(int i=1;i<=2*tn-3;i++){
//			cout << i<<": " << tree[i]<<"  "<<flag[i]<<endl;
//		}
//		cout << "-----------------------------------------------"<<endl;
	}
}

void cnt(int l,int r, int p){
	if((l+1==r) || (tree[p]!=-1)){
		if(tree[p]!=0)v.insert(tree[p]);
	}else{
		int m = round((l+r));
		cnt(l,m,lchild);
		cnt(m,r,rchild);
	}
}
int main(){
	int n,l,ind=1,tn;
	cin >> n >> l;

	for(int i=1;i<=n;i++){
		cin >> a[i] >>b[i];
		s[ind++] = a[i];
		s[ind++] = b[i];
	}
	tn = 2*n+1;
	//Sort the coordinate
	sort(s+1,s+tn);	
	//Remove the duplication
	tn = unique(s+1,s+tn) - (s+1);
	for(int i = 1;i<=tn;i++){
		distrete[s[i]] = i;
	}
	//Build segment tree	
	buildTree(1,tn,1);
	//Stick the post
	stick(n,tn);		
	cnt(1,tn,1);	
	cout << v.size();
	return 0;
}
