#include<iostream>
#include<string>
using namespace std;

string name[203];
int peopleCount=1;
int fa[203];

bool flag[203]={0};


int seekName(string sb){
	for(int i=1;i<peopleCount;i++){
		if (!name[i].compare(sb)) return i;
	}
	name[peopleCount]= string(sb);
	return peopleCount++;
}
void insertRelation(string fat,string son){
	int father = seekName(fat);
	int mySon = seekName(son);
	fa[mySon] = father;
}
void seekPublicAncestor(string jia,string yi){
	int jiaN=seekName(jia);
	int yiN=seekName(yi);
	int i=jiaN;
	if(jiaN==yiN){
		cout<<jia<<endl;
		return;
	}
	while(i!=0){
		flag[i]=1;
		i=fa[i];
	}
	i = yiN;
	while(i!=0){
		if(flag[i]) 
		{
			cout<<name[i]<<endl;
			for(int kk=0;kk<104;kk++) flag[kk]=0;
			return;
		}
		i = fa[i];
	}
	cout <<"-1"<<endl;
	for(int kk=0;kk<104;kk++) flag[kk]=0;
	return ;
}
int main(){
	
	for(int kk=0;kk<104;kk++) flag[kk]=0;
	int n,m;
	string a ,b ;
	
	cin >>n;	
	for(int i=0;i<n;i++){
		cin >> a;
		cin >> b;
		insertRelation(a,b);
	}
	cin >>m;
	for(int i=0;i<m;i++){
		cin >> a;
		cin >> b;
		seekPublicAncestor(a,b);
	}
	return 0;
}
