#include<iostream>
using namespace std;
#define MAX 100005
int x[2][MAX];
int a[MAX];

int main(){
	int n,m;
	cin >>m;
	while(m--){
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++) x[0][i] = -1;
		bool flag[2];
		int count[2][2]={0,0,0,0};
		for(int i=0;i<2;i++)
		{	flag[i] =true;
			x[i][1] = i;
			count[i][i]++;
			x[i][2] = a[1] - x[i][1];
			count[i][x[i][2]] ++;
			if((x[i][2]!=0)&&(x[i][2]!=1)){
				flag[i] = false;
				continue;
			}
			for(int j=3;j<=n;j++){
				x[i][j] = a[j-1] - x[i][j-1] - x[i][j-2];
				if((x[i][j]!=0)&&(x[i][j]!=1)) {
					flag[i] = false;
					break;
				}
				count[i][x[i][j]]++;
			}
			if((flag[i])&&(x[i][n]!=(a[n] - x[i][n-1]))) flag[i] = false;
		}
		if((flag[0]||flag[1])==0) cout <<"0"<<endl<<"0"<<endl;
		else{
			if((flag[0]&&flag[1])==1){
				int countt[2]={0,0};
				for(int k=1;k<=n;k++){
					if(x[0][k]==x[1][k])countt[x[0][k]]++;
						else x[0][k] = -1;
				}
				cout <<countt[1]<<" ";
				for(int k=1;k<=n;k++) if (x[0][k]==1) cout <<k<<" ";
				cout <<endl<<countt[0]<<" ";
				for(int k=1;k<=n;k++) if (x[0][k]==0) cout <<k<<" ";
				cout << endl;
			}else{
				int win;
				if(flag[0]) win = 0;
					else win = 1;
				cout << count[win][1] <<" ";
				for(int k=1;k<=n;k++) if(x[win][k]==1) cout << k <<" ";
				cout <<endl<< count[win][0] <<" ";
				for(int k=1;k<=n;k++) if(x[win][k]==0) cout << k <<" ";
				cout << endl;
			}
		}
	}
	return 0;
}
