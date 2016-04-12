#include<iostream>
#include<queue>
using namespace std;
#define MAX 1005
struct edge{
	int x;
	int y;
	int length;
	bool operator < (const edge &a) const{
		return a.length < length;
	}
};
int map[MAX][MAX];
std::vector<int> flag(MAX+1,false);
std::priority_queue <edge> tree;
int main(){

	int n;
	int sum = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cin >> map[i][j];
	}
	flag[1] = true;
	int t = 1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++){
			if(t!=j&&!flag[j]){
				edge temp;
				temp.length=map[t][j];
				temp.x = t;
				temp.y = j;
				tree.push(temp);
			}
		}
			while((flag[tree.top().x] xor flag[tree.top().y])==0) tree.pop();
		if(flag[tree.top().x]) t = tree.top().y;
			else t = tree.top().x;
			sum += tree.top().length;
			flag[t] = true;
			tree.pop();
		
	}
	cout << sum;
	return 0;
}
