// 5/3/2016 10£º06 https://www.zybuluo.com/lunar/note/303320
#include<iostream> 
using namespace std;

using namespace std;

int max(int a,int b){
	if(a>b) return a;
	else return b;
}

int main()
{
	int n,m,i,j;
	int need;
	int value;
	int ans[100002]={0};
	cin >> n >>m;
	
	for (i=0;i<n;i++){
	cin >> need>>value;
	for(int j=need;j<=m;j++)
		ans[j]= max(ans[j],ans[j-need]+value);
	}
		
		cout <<ans[m];	
	
	return 0;
}
