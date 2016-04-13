#include<iostream>
using namespace std;
#define MAX 100005
int heap[MAX];
int amount = 1;
void show(){
	for(int i =1;i<amount;i++)
		cout << heap[i] << " ";
		cout<<endl;
}
void insert(int x){
	int p = amount;
	heap[amount++] = x;
	while((heap[p>>1]<x)&&(p>>1>=1)){
		heap[p] = heap[p>>1];
		p = p>>1;
	}
	heap[p] = x;
	//show();
}
void down(int p){
	if((p<<1)>amount) return;
	if(heap[p<<1]>heap[p<<1|1]){
		if(heap[p<<1]<heap[p]) return;
			else {
				int t = heap[p];
				heap[p] = heap[p<<1];
				heap[p<<1] = t;
				p = p <<1;
				if((p<<1)<amount) down(p);
			}
	}else{
		if(heap[p<<1|1]<heap[p]) return;
			else {
				int t = heap[p];
				heap[p] = heap[p<<1|1];
				heap[p<<1|1] = t;
				p = p <<1|1;
				if((p<<1)<amount) down(p);
			}
	}
}
void pop(){
	cout <<heap[1]<<endl;
	heap[1] = heap[--amount];
	int p = 1;
	down(p);
	//show();
}

int main(){
//	int a[10] = {2,5,4,3,7,1,2,4,6};
//	for(int i =0;i<9;i++) 
//		insert(a[i]);
//
//	pop();
//	insert(1);
//	pop();
//	insert(11);
//	pop();
	int n,w;
	char a;
	cin >> n;
	while(n--){
		cin >> a;
		if(a=='A') {
			cin >> w;
			insert(w);
		}
		if(a=='T') pop();
	}
	return 0;
}
