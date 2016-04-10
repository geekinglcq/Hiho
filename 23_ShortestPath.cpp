#include<iostream> 
using namespace std;
#define infinity 10000000
#define make_pair(y,w) pair<int,int>(y,w)
#include<vector>
#include<queue>

std::priority_queue <pair<int,int> > nP;  	// Using priority queue to provide the nearest point

int main(){
	int n,m,s,d,x,y,w,i,ty,tw;
	cin >>n >>m >> s >>d;
	std::vector<vector<pair<int,int> > > tree(n+1);	
	while(m--){
		cin >> x >> y >> w;
		tree[x].push_back(pair<int,int>(y,w));
		tree[y].push_back(pair<int,int>(x,w));
	}
	std::vector<int> flag(n+1,false);	// denote which set this node belongs to
	std::vector<int> dis(n+1,infinity); // represent the distance node s and certain node
	dis[s] = 0;
	for(nP.push(make_pair(0,s));!nP.empty();){
		int t = nP.top().second;
		nP.pop();
		if(flag[t]) continue;
		flag[t] = true;
		if(t == d) break;
		//Core part 
		for(i=0;i<tree[t].size();i++){
			ty = tree[t][i].first;
			tw = tree[t][i].second;
			if(dis[ty]>dis[t]+tw){
				dis[ty] = dis[t] + tw;
				nP.push(make_pair(-dis[ty],ty));
			}
		}
	}
	cout << dis[d];
	return 0;
}
