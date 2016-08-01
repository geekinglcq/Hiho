//  3/3/2016 2016 https://www.zybuluo.com/lunar/note/301812
#include <iostream>
using namespace std;

int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	int maze[102][102]= {0};
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)	
		for(int j=0;j<i;j++)			
			cin >> maze[i][j];
	if(n==1)cout << maze[1][0];
	else{
	for (int i=2;i<=n;i++)	
		for(int j=0;j<i;j++){
			if(j==0)maze[i][j]=maze[i][j]+maze[i-1][j];
			else{
				if(j==(i-1))maze[i][j]=maze[i][j]+maze[i-1][j-1];
				else maze[i][j]=max(maze[i-1][j],maze[i-1][j-1])+maze[i][j];
			}			
		}	
	int ans=-1;
	for(int i=0;i<n;i++){
		if(maze[n][i]>ans) ans = maze[n][i];
	}
	cout << ans;
	}
	
	return 0;
}
