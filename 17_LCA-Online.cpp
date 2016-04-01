#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<string.h>
#include<vector> 
#include<map>
#define MAX 100005

std::map<string,int> name;
string seekName[MAX];
std::vector<int> tree[MAX];
int minValue[20][2*MAX];
int minPos[20][2*MAX];

int fakeindex = 1, arrow = 1, n, d = 1;
int st[2*MAX];
int deep[2*MAX];
int pos[MAX];
void buildTree(){
	
	cin >> n;
	for(int i=0;i<n;i++){
		string a,b;
		cin >> a;
		cin >> b;
		std::map<string,int>::iterator itA;
		std::map<string,int>::iterator itB;
		itA = name.find(a);
		if(itA == name.end()) {
			seekName[fakeindex] = a;
			name[a] = fakeindex++;
			itA = name.find(a);
		}
		itB = name.find(b);
		if(itB == name.end()) {
			seekName[fakeindex] = b;
			name[b] = fakeindex++;
			itB = name.find(b);
		}
		tree[itA->second].push_back(itB->second);
	}
}
void DFS(int x){
	deep[arrow] = d++;
	pos[x] = arrow;
	st[arrow++] = x;	
	for(int i=0;i<tree[x].size();i++){
		DFS(tree[x][i]);
		deep[arrow] = d-1;
		st[arrow++] = x;
	}
	d--;
}

void initST(){
	for(int i=1;i<arrow;i++){
		minValue[0][i] = deep[i];
		minPos[0][i] = st[i];
	}
	int f = 1;
	for(int i=1;;i++)	{
		f = 1<<(i - 1);
		int len = arrow - (1<<i) + 1;
		if(len < 0) break;
		for(int j=1;j<=len;j++){
			if(minValue[i-1][j]<minValue[i-1][j + f]){
				minValue[i][j] = minValue[i-1][j];
				minPos[i][j] = minPos[i-1][j];
			}else{
				minValue[i][j] = minValue[i-1][j + f];
				minPos[i][j] = minPos[i-1][j + f];
			}			
		}
	}
}
void output(){
	int m;
	cin >> m;
	for(int k=0;k<m;k++){
		string a;
		string b;
		cin >> a;
		cin >> b;
		std::map<string,int>::iterator itA;
		std::map<string,int>::iterator itB;
		itA = name.find(a);
		itB = name.find(b);
		int l,r;
		l = pos[itA->second];
		r = pos[itB->second];
		if (l>r) swap(l,r);
		int len = r - l + 1;
		int j=0;while((1<<j)<=len)j++;j--;
		r = r - (1 << j) + 1; 
		int ans;
		if(minValue[j][l]<minValue[j][r]){
			 ans = minPos[j][l];
		}else{
			 ans = minPos[j][r];
		}
		cout << seekName[ans]<<endl;
	}
}
int main(){
    buildTree();
    //for(int i=1;i<fakeindex;i++) cout << i<<": "<<seekName[i]<<"   ";
	//cout << endl; 
    DFS(1);
	//for (int i=1;i<arrow;i++) cout<<st[i]<<" ";
	//cout <<endl;
	//for (int i=1;i<arrow;i++) cout<<deep[i]<<" ";
	//cout << endl;
	initST();
	output();
    return 0;
    }
