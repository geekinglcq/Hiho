#include<iostream>
#include<queue>
using namespace std;
#define MAX 100005

int flag[MAX];
struct edge{
	int x;
	int y;
	int length;
	bool operator < (const edge &a) const{
		return a.length < length;
	}
};

int seekFa(int i){
	if (flag[i]!=i) flag[i] = seekFa(flag[i]);
	return flag[i];
}
void unionFa(int x,int y){
	int aa = seekFa(x);
	int bb = seekFa(y);
	if(aa>bb) flag[aa] = bb;
	else flag[bb] = aa;
}

std::priority_queue <edge> tree;
int main(){

	int n,m;
	int sum = 0;
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		flag[i] = i;
	}
	while(m--){
		int a, b ,c;
		cin >>a >> b >> c;
		edge temp;
		temp.x = a;
		temp.y = b;
		temp.length = c;
		tree.push(temp);
	}
	for(int i=1;i<n;i++){
		while((seekFa(tree.top().x))==(seekFa(tree.top().y))) 
			tree.pop();
		sum +=tree.top().length;
		unionFa(flag[tree.top().x],flag[tree.top().y]);
		tree.pop();
	}			
	cout << sum;
	return 0;
}
