#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int next[26];
    int sum;
    void init()
    {
        sum=0;
        memset(next,-1,sizeof(next));
    }
}T[1000000];
int sp=1;

void insert(char* s)
{
	int i=0,p=0;
	while(s[i])
	{
		int t=s[i]-'a';
		if(T[p].next[t]==-1)
		{
			T[sp].init();
			T[p].next[t]=sp++;			
		}
			p=T[p].next[t];
			T[p].sum++;
		i++;
	}
}
void query(char* s)
{
	int i=0,p=0;
	while(s[i])
	{
		int t=s[i]-'a';
		if(T[p].next[t]==-1)
		{
			puts("0");
			return;
		}
		p=T[p].next[t];
		i++;
	}
	printf("%d\n",T[p].sum);
}
int main()
{
	
	int m,n;
	T[0].init();
	scanf("%d",&m);
	while(m--)
	{
		char s[20];
		scanf("%s",s);
		insert(s);
	}
	scanf("%d",&n);
	while(n--)
	{
		char s[20];
		scanf("%s",s);
		query(s);
	}
	return 0;
}
