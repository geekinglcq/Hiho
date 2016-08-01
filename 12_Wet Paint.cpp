#include<iostream>
using namespace std;
int n,m;
int value[102];
int ans[102][102]={0};
int h[102]={0};
int p=1;

struct tree_node{
	int next;
	int to;
}node[204];

int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int ergodic(int point,int former){
	if(h[point]==0||node[h[point]].to==former) {
		for (int b=1;b<=m;b++) ans[point][b] = value[point];
		return value[point];
	}	
	ans[point][1]=value[point];
		
	int i=h[point];
	while(node[i].to){
		if(node[i].to!=former){
			ergodic(node[i].to,point);
			for(int t=m;t>=2;t--){
				for(int kk=1;kk<=t-1;kk++)
				ans[point][t]=max(ans[point][t],ans[point][t-kk]+ans[node[i].to][kk]);
			}
		}
		i = node[i].next;
	}
}
void build(int from,int to){
	node[p].to = to; node[p].next = h[from];
	h[from] = p++;
	node[p].to = from; node[p].next = h[to];
	h[to]=p++;
}
int main(){
	
	int i,j,k;
	cin >> n >> m;
	for (i=1;i<=n;i++)cin >> value[i];
	for(i=1;i<n;i++){
		cin >> j >> k;
		build(j,k);
	}
	ergodic(1,0);
	cout << ans[1][m];
	return 0;
}
