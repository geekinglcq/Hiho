#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long counts=0;

int a[105];
int b[105];
//归并
int merge(int bg, int ed){

	int mi = ((bg + ed) >> 1 )+ 1;
	if(bg == ed) return 0;
	int v1=bg,v2=mi,temp = 0, rcount = 0,flag = bg;
	while((v1<mi)&&(v2<ed+1)){
		if(a[v1]>=a[v2]){
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
	return temp;
}
//分治
void divide(int bg, int ed){
	if(bg == ed){
		counts += merge(bg,ed);
		return;
	}
	int mi = ((bg + ed) >> 1) + 1;
	divide(bg,mi-1);
	divide(mi,ed);
	counts += merge(bg,ed);
}
int main(){
	int n,lostc = 0;
	long k;
	int data[103];
	cin >> n >> k;
	bool lostFlag[101];
	int lost[12];
	int lostPoi[12];

	for(int i=1;i<=n;i++) lostFlag[i] = 0;
	for(int i=1;i<=n;i++){
		cin >> data[i];
		if(data[i] != 0) lostFlag[data[i]] = 1;
		if(data[i] == 0) lostPoi[lostc++] = i;
		a[i] = data[i];
	}
	int j = 0;
	for(int i=1;i<=n;i++) if(lostFlag[i] == 0)
		lost[j++] = i;

	sort(lost,lost + lostc);


	int ans = 0;

	do{

		for(int i=0;i < lostc;i++){
			a[lostPoi[i]] = lost[i];
		}

		divide(1,n);

		if(counts == k) ans++;
		counts = 0;
	}while( next_permutation(lost,lost + lostc));//全排列

	cout << ans;



	return 0;
}
