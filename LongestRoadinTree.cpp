#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 100002
struct tree_node{
	int to,next;
}node[2*MAXN];
int  header[MAXN]; //header[x] represent Xth node's first child is node[header[x]]
int p=1;

int ans[MAXN+5]={0};
void build(int to, int from){
	node[p].to=from; node[p].next=header[to];
	header[to]=p++;
	node[p].to=to; node[p].next=header[from];
	header[from]=p++;
}

//currP is current node & formerP means the former point
int dfs(int currP,int formerP){
	if(node[header[currP]].to==formerP) {ans[currP]=1;return 1;} 
	int i=header[currP];
	int m=0,mm=0;
	while(node[i].to){
		
		if(node[i].to!=formerP){
		int t=0;
		t=dfs(node[i].to,currP);
		if(t>=m){
			mm=m;m=t;
		}else{
			if(t>=mm){
				mm=t;
			}
		}
		
		}
		i=node[i].next;
	}
	ans[currP]=mm+m+1;
	return m+1;
}
int ct;

int main(){
	int n;
	cin >> n;
	for(int i; i<(n-1); i++){
		int to ,from;
		cin >> to >> from;
		build(to,from);
	}
	dfs(1,-1);
	int out=0;
	for(int i=1;i<n+1;i++)if(ans[i]>out) out =ans[i];
	cout<< (out-1);
	return 0;
}
