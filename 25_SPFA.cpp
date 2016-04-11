#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define infinity 10000000

int main(){
	int n,m,s,t,x,y,v;
	n = infinity;
	cin >> n >>m >> s >>t;
	std::vector<vector<pair<int,int> > > tree(n+1);
	std::vector<int> dis(n+1,infinity);
	std::vector<int> flag(n+1,true);
	std::queue<int> que;
	while(m--){
		cin >> x >> y >> v;
		tree[x].push_back(pair<int,int>(y,v));
		tree[y].push_back(pair<int,int>(x,v));
	} 
	dis[s] = 0;
	que.push(s);
	flag[s] = false;
	while(!que.empty()){
		int top = que.front();
		que.pop();
		for(int i=0;i<tree[top].size();i++){
			int temp = tree[top][i].first;
			if(dis[temp]>(dis[top]+tree[top][i].second)){
				dis[temp]=(dis[top]+tree[top][i].second);
				if(flag[temp]){
					que.push(temp);
					flag[temp] = false;
				}
			}			
		}
		flag[top] = true;
	}
	cout<< dis[t];
	return 0;
}
