#include<iostream>
#include<map>
using namespace std;
int n;
std::map<string,int>peopleList;

int cla[100005];
int count=0;
int findCla(int a){
	int t=a;
	while(a!=cla[a]) a =cla[a];
	while(t!=cla[t]) {
		cla[t]=a;
		t=cla[t];
	}
	return a;
}
void unio(int a,int b){
	int aa = findCla(a);
	int bb = findCla(b);
	if(aa<bb)
		cla[bb]=aa;
	else 
		cla[aa]=bb;
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int model;
		string jia;
		string yi;
		cin >> model;
		cin >>jia;
		cin >>yi;
		if(!model){
			map<string,int>::iterator lIt1;
			lIt1 = peopleList.find(jia);
			map<string,int>::iterator lIt2;
			lIt2 = peopleList.find(yi);
			int x,y;
			if(lIt1 == peopleList.end()) {
				peopleList[jia] = count;
				x = count++;
				cla[x] = x;
			}else x = lIt1 -> second;
			if(lIt2 == peopleList.end()) {
				peopleList[yi] = count;
				y = count++;
				cla[y] = y;
			}else y = lIt2 -> second;
			unio(x,y);
		}else{
			map<string,int>::iterator lIt1;
			lIt1 = peopleList.find(jia);
			map<string,int>::iterator lIt2;
			lIt2 = peopleList.find(yi);
			int x,y;
			if(lIt1 == peopleList.end()) {
				peopleList[jia] = count;
				x = count++;
				cla[x] = x;
			}else x = lIt1 -> second;
			if(lIt2 == peopleList.end()) {
				peopleList[yi] = count;
				y = count++;
				cla[y] = y;
			}else y = lIt2 -> second;
			if(findCla(x)==findCla(y)) cout << "yes"<<endl;
				else cout << "no" << endl;
		}
	}
	return 0;
}
