#include<iostream>
#include<cstdio>
#include<vector>  
#include<queue> 

using namespace std;
typedef vector<int> vint;
int n,m;

 
void solve(){
	cin >> n >> m;
	vector <vint> G(n+1);
	short color[10001];
	for(int i=0;i<=n+1;i++) color[i] = 2;
	queue <int> q;
	int a,b;
	while(m--){
		scanf("%d%d",&a,&b); 
		G[a].push_back(b);
		G[b].push_back(a);
	}
	color[1]=0;
	q.push(1);
	bool flag = true;  
	while(flag){
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for (int i=0;i<G[t].size();i++){
			if(color[G[t][i]]==2){
				q.push(G[t][i]);
				color[G[t][i]] = !color[t];
			}else {
				if(color[G[t][i]]==color[t]){
					cout << "Wrong"<<endl;
					return;
				}
			}
		}
	}
	flag = false;
	for(int i=1;i<=n;i++)
		if(color[i]==2){
			color[i] = 0;
			q.push(i);
			flag = true;
			break;
		}
	}
	cout<< "Correct"<<endl;
	return;
}
int main(){
	int iter;
	cin >> iter;
	while(iter--)solve();
	
	return 0;
}
