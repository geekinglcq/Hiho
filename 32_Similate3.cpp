#include<iostream> 
#include<iomanip>
#include<vector>
using namespace std;

int map[12][12];
int remain[12][12];
int n,m,amount;
struct point{
	int x;
	int y;
	int v;
};
vector<point> points;
bool check(int x,int y){
	for(int i=0;i<9;i++)
		if(remain[x+i/3-1][y+i%3-1]==0)
			return false;
	return true;
}
void solve(int k){
	int i,j;
	int x = points[k].x;
	int y = points[k].y;
	if(k<amount){
		if(check(x,y)){
			remain[x][y] = -3;
			for(i=0;i<9;i++)
				if(remain[x+i/3-1][y+i%3-1] > 0)
					remain[x+i/3-1][y+i%3-1]--;
			solve(k+1);
			for(i=0;i<9;i++)
				if(remain[x+i/3-1][y+i%3-1] >=0)
					remain[x+i/3-1][y+i%3-1]++;
			}
		remain[x][y] = -4;
		solve(k+1);
		}else{
			for(j=0;j<amount;j++)
				for(i=0;i<9;i++)
					if(remain[points[j].x+i/3-1][points[j].y+i%3-1]>0)
						return;
				

			
			for(i=0;i<amount;i++){
				if(points[i].v==0) 
					points[i].v = remain[points[i].x][points[i].y];
				else if(points[i].v != remain[points[i].x][points[i].y])
					points[i].v = -1;
			}
		}
	}

int init(){
	cin >> n;
	cin >> m;
	points.clear();
	int i,j;
	for(i=0;i<=n+1;i++){
		map[i][0]=-10;
		map[i][m+1]=-10;
	}
	for(i=0;i<=m+1;i++){
		map[0][i]=-10;
		map[n+1][i]=-10;
	}  
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
				cin >> map[i][j];
				
				if(map[i][j]==-1){
					point temp;
					temp.x = i;
					temp.y = j;
					temp.v = 0;
					points.push_back(temp);
				}
			}  
	for(i=0;i<=n+1;i++)
		for(j=0;j<=m+1;j++)
			remain[i][j] = map[i][j];
	amount = points.size();

	solve(0);
	int t1=0,t2=0;
	for(i=0;i<amount;i++)
		if (points[i].v == -3) t1++;
		else if (points[i].v == -4) t2++;

	
	cout << t1<<" "<<t2<<endl;
	points.clear();
} 
int main(){
	int iter;
	cin >> iter;
	while(iter--) init();
	return 0;
}
