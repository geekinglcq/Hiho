#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

//KMP algorithm
int kmp(const char *p,const char  *t) {
	int i = 0;
	int j = 0;
	int count = 0;
	int plen = strlen(p);
	int tlen = strlen(t);
	int next[10000];

	//Calculate the next array.
	next[0] = -1;
	int k = -1;
	j = 0;
	if (plen != 1) {
		
		while (j < plen-1) {
			if(k==-1||p[k]==p[j]) {
				j++;
				k++;
				next[j]=k;
			}else{
				k = next[k];
			}
		}
	}
	for(i=0;i<plen;i++) cout << next[i]<<" ";
	i=0;
	j=0;
	
	while (j < tlen) {

		if (i==-1||p[i] == t[j]) {
			if (i == (plen-1)) {
				count++;
				i = next[i];
			}
			else {
				i++;
				j++;
			}
		}
		else {
			i = next[i];


		}
	}

		return count;
}

	int main()
{
	int n;
	string pattern, text;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pattern;
		cin >> text;
		cout << kmp(pattern.c_str(),text.c_str())<<endl;
	}
	
	return 0;
}
