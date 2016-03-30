#include<iostream>
#include<string>
#include<map>
#include<vector> 
#define max 100005
using namespace std;


std::map<string,int> header;
std::vector<int> tree[max];
int index=0;
string name[max];

std::map<std::pair<int,int>,string> l;
int set[max];
int ancestor[max];
void buildTree(){
	int n;
	string a,b;
	std::map<string,int>::iterator idIta;
	std::map<string,int>::iterator idItb;
	cin >>n;
	while(n--){
		cin >> a;
		cin >> b;
		idIta = header.find(a);
		if(idIta == header.end()) {
			name[index] = a;
			header[a] = index++;
			idIta = header.find(a);
		}
		idItb = header.find(b);
		if(idItb == header.end()) {
			name[index] = b;
			header[b] = index++;
			idItb = header.find(b);
		}
		tree[idIta->second].push_back(idItb->second);
		
	}
}
struct point{
	int x;
	int y;
}temp;
std::vector<int> query[max];
std::vector<point> q;
void readQuery()
{
	int n;
	string a,b;
	cin >> n;
	std::map<string,int>::iterator idIta;
	std::map<string,int>::iterator idItb;

	for(int i=0;i<n;i++){
		cin >> a;
		cin >> b;
		idIta = header.find(a);
		idItb = header.find(b);
		query[idIta->second].push_back(idItb->second);
		query[idItb->second].push_back(idIta->second);
		if(idIta->second<idItb->second)
			{temp.x = idIta->second;temp.y = idItb->second;}			
		else {temp.x = idItb->second;temp.y = idIta->second;}
		
		q.push_back(temp);
	}
}

void initSet(){
	for (int i=0;i<index;i++)
		{
			set[i] = i;
			ancestor[i] = i;
		}
}
int findSet(int x){
	if(x != set[x]) set[x] = findSet(set[x]);
	return set[x]; 
}
void unionSet(int x,int y){
	int xF = findSet(x);
	int yF = findSet(y);
	if(xF == yF) return;
	else set[yF] = xF;
}


bool flag[max];
void DFS(int x){
	for (int i=0;i<tree[x].size();i++){
		DFS(tree[x][i]);
		unionSet(x,tree[x][i]);
		ancestor[findSet(x)] = x;
	}
	flag[x] = 1;
	for (int i=0;i<query[x].size();i++){
		if(flag[query[x][i]]){
			
			string t = name[ancestor[findSet(query[x][i])]];
			if(x<query[x][i]){
				l[pair<int,int>(x,query[x][i])] = t;
			}else{
				l[pair<int,int>(query[x][i],x)] = t;
			}
		}
	}
}
void output(){
	for(int i=0;i<q.size();i++){
		std::map<pair<int,int>,string>::iterator itt;
		itt = l.find(pair<int,int>(q[i].x,q[i].y));
		cout <<itt->second<<endl;
	}
}
int main(){
	buildTree();
	//memset(flag, 0, sizeof(flag));
	initSet();
	readQuery();

	DFS(0);
	output();
	return 0;
}
