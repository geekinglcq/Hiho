#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

long count=0;

vector<unsigned int> a;
//int a[7] = {0,6,4,1,2,5,2};
vector<unsigned int> b;
int merge(int bg, int ed){

	int mi = ((bg + ed) >> 1 )+ 1;
	if(bg == ed) return 0;
	int v1=bg,v2=mi,temp = 0, rcount = 0,flag = bg;
	while((v1<mi)&&(v2<ed+1)){
		if(a[v1]<=a[v2]){
			b[flag++] = a[v1++];
			temp += rcount;
		}else{
			b[flag++] = a[v2++];
			rcount++;
		}
	}
	if(v1 == mi)
		for(;flag<=ed;)
			b[flag++] = a[v2++];
		else{
			for(;flag<=ed;){
				b[flag++] = a[v1++];
				temp += rcount;
			}
		}
	for(int i = bg;i <= ed;i++)
		a[i] = b[i];
//	cout << bg<<"--"<<ed<<":"<<temp<<endl;
//		for(int i=1;i<=5;i++) cout << a[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=5;i++) cout << b[i]<<" ";
//	cout<<endl;
	return temp;
}

void divide(int bg, int ed){
	if(bg == ed){
		count += merge(bg,ed);
		return;
	}
	int mi = ((bg + ed) >> 1) + 1;
	divide(bg,mi-1);
	divide(mi,ed);
	count += merge(bg,ed);
}
int main(){
	int n,i,j;
	
	cin >> n;
	a.reserve(n+3);
	b.reserve(n+3);

	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	//cout << merge(1,n);
	divide(1,n);
	cout << count;
	return 0;
}
