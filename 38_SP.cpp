#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int d;
	int w;
};
	struct pn{
		int at;
		int cost;
		int k;
	};
map <int,int> nodes[10005];

void addEdge(int a, int b, int v){
	std::map<int,int>::iterator it;
	it = nodes[a].find(b);
	if(it == nodes[a].end()){
		nodes[a][b] = v;
		nodes[b][a] = v;
	}else if(it->second > v){
		nodes[a][b] = v;
		nodes[b][a] = v;
	}
}
int main(){
	int n,m,k,t;
	int a,b,c;
	scanf("%d%d%d%d",&n,&m,&k,&t);
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
	}	
	std::vector<int> l(n+10);	
	
	queue<pn> q;
	q.push((pn){1,0,0});
	
	while(!q.empty()){
		pn temp = q.front();
		q.pop();
		if(l[temp.at] && l[temp.at] < temp.cost)
		continue;
		l[temp.at] = temp.cost;
		if(temp.k == k) continue;
		for(map<int,int>::iterator it = nodes[temp.at].begin();it != nodes[temp.at].end();it++){
			int New = l[temp.at] > it->second? l[temp.at] : it->second;
			if(!l[it->first] || l[it->first] > New)
				q.push((pn){it->first,New,temp.k+1});
			
		}		
	}
	cout << l[t];

	return 0;
}


