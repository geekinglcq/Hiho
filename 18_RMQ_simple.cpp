
#include<iostream> 
using namespace std;
#define MAX 10005
#define MAXW 10002
int items[MAX];

void query(int l,int r){
	int min = MAXW;
	for(int i=l;i<=r;i++)if(min>items[i])min = items[i];
	cout << min << endl;
}

void change(int index, int weight){
	items[index] = weight;
}

int main()
{
	int n,q,f,a,b;
	cin >> n;
	for(int i = 1;i<=n;i++)  cin >> items[i];
	cin >> q;
	while(q--){
		cin >> f >> a >> b;
		if(f) change(a,b);
		else query(a,b);
	}
	return 0;
}

