#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 105
#define infinity 1000000
int map[MAX][MAX];
bool isSame(int x, int y, int z){
	if((x!=y)&&(y!=z)&&(x!=z)) return false;
		else return true;
}
int main(){
	int n,m,x,y,v;
	cin >> n >>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			if(i==j) map[i][j] = 0;
			else map[i][j] = infinity;
		}
		while(m--){
			cin >>x>>y>>v;
			 if(map[x][y] > v){
			 map[x][y] = v;
			 map[y][x] = v;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(!isSame(i,j,k))
						map[i][j] = min(map[i][j],map[i][k]+map[k][j]);
				}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cout <<map[i][j] << " ";
			cout <<endl;
		}
	return 0;
}
