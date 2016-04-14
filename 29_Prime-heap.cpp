#include<iostream>
using namespace std;
#define MAXN 100004
#define MAXM 1000005
struct ed{
	int to;
	int weight;
	int next;
};
struct edge{
	int x;
	int y;
	int weight;
};
int header[MAXN];
ed tree[MAXM];
edge heap[MAXM];
bool flag[MAXN];
int edgeAmount=1;
void addEdge(int x,int y,int w){
	if(header[x]==0)
		tree[edgeAmount].next = -1;
		else
		tree[edgeAmount].next = header[x];
		
		tree[edgeAmount].to = y;
		tree[edgeAmount].weight = w;
		header[x] = edgeAmount++;
}
void insert(int x,int y,int weight){
	int p = edgeAmount++;
	heap[p].x = x;
	heap[p].y = y;
	heap[p].weight = weight;
	edge temp = heap[p];
	while((heap[p>>1].weight > temp.weight)&&(p>>1 >=1)){
		heap[p] = heap[p>>1];
		p = p>>1;
	}
	heap[p] = temp;
}
void down(int p){
	int bc=p;
	if(p<<1 > edgeAmount) return ;
	if(heap[p<<1].weight < heap[p<<1|1].weight) 
		bc = p<<1;
	else
		bc = p<<1|1;
	if(heap[bc].weight < heap[p].weight){
		edge tt = heap[p];
		heap[p] = heap[bc];
		heap[bc] = tt;
		down(bc);
	}
}
int pop(){
	int val = heap[1].weight;
	heap[1] = heap[--edgeAmount];
	down(1);
	return val;
}

int main(){
	int n,m,x,y,w;
	scanf("%d%d",&n,&m);
	for(int i =1;i<=n;i++) 	header[i] = 0;
	for(int i =1;i<=n;i++) 	flag[i] = false;
	while(m--){
		scanf("%d%d%d",&x,&y,&w);
		addEdge(x,y,w);
		addEdge(y,x,w);
	}
	int sum =0;
	flag[1] = true;
	int p =1;
	int s = header[p];
	edgeAmount = 1;
	for(int i=1;i<n;){
		while(tree[s].next!=-1){
			if(!flag[tree[s].to]) insert(p,tree[s].to,tree[s].weight);
			s = tree[s].next;
		}
		while(((flag[heap[1].x])xor(flag[heap[1].y]))==0) pop();
		if(flag[heap[1].x]) {
				flag[heap[1].y] = true;
				p = heap[1].y;
				}else {
				flag[heap[1].x] = true;
				p = heap[1].x;
				}
		s = header[p];
		sum +=pop();
		i++;
	}
	cout << sum;
	return 0;
}
