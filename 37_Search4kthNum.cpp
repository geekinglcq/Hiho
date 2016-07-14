#include<iostream>  
#include<functional>
#include<vector>
#include<queue>  

using namespace std;

vector<int> number;
void swap(int a, int b){
	int c = number[a];
	number[a] = number[b];
	number[b] = c;
}
int main(){
	int n,k,t,m,l,r;
	cin >> n >> k;
	if(k>n){
		cout << "-1";
		return 0;
	}
	k--;
	for (int i=0;i<n;i++) {
		cin >> t;
		number.push_back(t);
	}
	l = 0;  
	r = n-1;
	m = (l+r)>>1;
	while(l<=r){
		int pole = number[m];
		int ll = l,rr = r;
			while(ll<rr){
				while(number[ll]<pole)ll++;
				while(number[rr]>pole)rr--;
				swap(ll,rr);
			}		
//			for (int p = 0;p<n;p++) cout <<number[p]<<" ";
//			cout <<endl;
			
			if(k<ll) r = ll-1;
				else if(k>rr) l = rr+1;
					else{
						cout << pole;
						return 0;
					}
//			cout <<"l,r"<< l<<" "<< r<<endl;
			m = (l+r) >>1;		
	}
	return 0;
}
