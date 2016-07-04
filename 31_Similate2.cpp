#include<iostream>
using namespace std;

int map[205][205];
int pre[205][205];
int cou[205][205];
int n,m;
void zero(int x,int y){
	if(map[x][y]==0){
		for (int i=x-1;i<=x+1;i++)
			for (int j=y-1;j<=y+1;j++){
				if (!((x==i)&&(y==j))&&(map[i][j]==-1))
					pre[i][j]=9;
			}
	}
}
int count(int x,int y){
	int temp=0;
	for (int i=x-1;i<=x+1;i++)
		for (int j=y-1;j<=y+1;j++)
			if (map[i][j]==-1) temp++;
		
	return temp;
}
void all(int x,int y){
	if(cou[x][y]==map[x][y]){
		for (int i=x-1;i<=x+1;i++)
		for (int j=y-1;j<=y+1;j++)
			if (map[i][j]==-1) pre[i][j]=10;
	}
}
void solve(){
	int i,j;

	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(map[i][j]!=-1)cou[i][j]=count(i,j);
		}
				
//		for(i=1;i<=n;i++){		
//		for(j=1;j<=m;j++)
//		{	cout<<cou[i][j]<<" ";
//		}
//		cout<<endl;
//		}
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(map[i][j]!=-1){
				zero(i,j);
				all(i,j);

				for(int a=i-2;a<=i+2;a++)
				for(int b=j-2;b<=j+2;b++){
					if((a>=1)&&(a<=n)&&(b>=1)&&(b<=m)&&(map[a][b]!=-1)&&(map[i][j]>map[a][b])&&((map[i][j]-map[a][b])==(cou[i][j]-cou[a][b]))){
						bool flag = true;
						for(int t1=a-1;t1<=a+1;t1++)
						for(int t2=b-1;t2<=b+1;t2++){
							if((map[t1][t2]==-1)&&(!((t1>=i-1)&&(t1<=i+1)&&(t2>=j-1)&&(t2<=j+1))))
								flag = false;
						}
						if(flag){
	 						for(int t3=i-1;t3<=i+1;t3++)
							for(int t4=j-1;t4<=j+1;t4++){
								if((map[t3][t4]==-1)&&(!((t3>=a-1)&&(t3<=a+1)&&(t4>=b-1)&&(t4<=b+1))))
									pre[t3][t4]=10;
							}
						}
					}
				}
			}
		}
		int count1=0,count2=0;
		for(i=1;i<=n;i++){		
		for(j=1;j<=m;j++)
		{	//cout<<pre[i][j]<<" ";
			if(pre[i][j]==9) count1++;
			if(pre[i][j]==10) count2++;
		} 
		//cout<<endl;
		}
		cout<<count2<<" "<<count1<<endl;
			
}
void init(){
	cin >> n;
	cin >> m;
	int i,j;
	for(i=0;i<=m+1;i++){
		map[0][i]=0;
		map[n+1][i]=0;
	}
	for(i=0;i<=n+1;i++){
		map[i][0]=0;
		map[i][m+1]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin >> map[i][j];
			pre[i][j]=0;
		}
	solve();
	
}


int main(){
	int iter;
	cin >> iter;
	while(iter--) init();
}
