#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

typedef vector<int> vint;
int check[1005];
vector <vint> G(1005);
vector <int> link(1005);

bool findPath(int p){
	check[p] = 1;
	for(int i=0;i<G[p].size();i++)
	if(check[G[p][i]]==0)
	{
		check[G[p][i]] = 1;
		if((link[G[p][i]]==0)||(findPath(link[G[p][i]]))){
			link[p] = G[p][i];
			link[G[p][i]] = p;
			return 1;
		}
	}
	return 0;
}

void solve() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	int ans = 0;
	
	for(int i=1;i<=n;i++) link[i] = 0;
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(link[i]==0){
			memset(check,0,sizeof(check));
			ans += findPath(i);			
		}
	}
	cout << ans;
}
int main()
{
	solve();
	return 0;
}

