// 4/3/2016 12£º01 https://www.zybuluo.com/lunar/note/302701 
#include<iostream> 
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
	int ans[100005]={0};
	cin >> n >>m;

		
	for (i=0;i<n;i++){
	cin >> need>>value;
	for(int j=m;j>=need;j--)
		ans[j]= max(ans[j],ans[j-need]+value);
	}
		
		cout <<ans[m];	
	
	return 0;
}
