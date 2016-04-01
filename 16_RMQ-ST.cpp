
#include<cstdio>
#include <algorithm>
using namespace std;
#define MAX 10000010
int item[20][MAX];


int main(){
	int n,q;
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&item[0][i]);
	
	for(i=1;;i++){	
		int kk = 1<<(i-1);
		int it = n - (1<<i) +1;
		if(it < 0) break;

		for(j=1;j<=it;j++){
			item[i][j] = min(item[i-1][j],item[i-1][j+kk]);
			//	cout << item[i][j] <<" ";
		}
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		int len = r - l + 1;
		int j=0;while((1<<j)<=len)j++;j--;
		printf("%d\n",min(item[j][l],item[j][r+1-(1<<j)]));
	}
	return 0;
}
