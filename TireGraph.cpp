// https://www.zybuluo.com/mdeditor#300607 
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 26
struct Trie{
	int cnt;
	Trie *fail;
	Trie *next[MAX];
	Trie(){
		cnt = 0;
		for(int i=0;i<MAX;i++) next[i] = NULL;
	}
}; 
//build Trie Tree
void build(Trie *root,char *c){
	Trie *p=root;
	int pos;
	while(*c){
		pos = *c - 'a';
		if(p->next[pos]==NULL) p->next[pos]= new Trie();
		p = p->next[pos];
		c++;
	}
	p->cnt++;
}

//Swith Trie Tree to Trie Graph
void TrieG(Trie *root){
	queue <Trie *>q;
	root->fail=root;
	for(int i=0;i<MAX;i++){
		if(root->next[i]==NULL) root->next[i] = root;
		else{
			root->next[i]->fail = root;
			q.push(root->next[i]);
		}
		
	}
	while(!q.empty()){
		Trie *temp =q.front();
		q.pop();
		if((temp->fail->cnt >0)&&(temp->cnt==0))temp->cnt++; 
		for(int i=0;i<MAX;i++){
			if(temp->next[i]==NULL) temp->next[i] = temp->fail;
			else{
				temp->next[i]->fail = temp->fail->next[i];
				q.push(temp->next[i]);
			}
		}
	}
}
int main()
{	int n;
	bool flag = false;
	char words[1000000];
	Trie *root = new Trie();
	cin >> n;
	while(n--){
		cin>> words;
		build(root,words);
	}
	TrieG(root);
	char *s;
	cin >> words;
	s = words -1;
	Trie *temp = root;
	while(*++s){		
		temp = temp->next[*s - 'a'];
		if(temp->cnt>0){
			flag = true;
			break;
		}
	}
	string out = flag ? "YES":"NO";
	cout << out;
	
	return 0;
}
