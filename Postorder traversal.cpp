#include<iostream> 
#include "string.h"
using namespace std;
char pre[26],in[26];
void p(int l,int r,int i){
	if(l==r) cout<<in[l];
	else{
		int m;
		for(int j=l;j<=r;j++)if(pre[i]==in[j])m=j;
		if(m>l)p(l,m-1,i+1);
		if(m<r)p(m+1,r,i+m-l+1);
		cout<<in[m];
	}
}
int main(){
	cin >>pre>>in;
	p(0,strlen(in)-1,0);	
	return 0;
}
