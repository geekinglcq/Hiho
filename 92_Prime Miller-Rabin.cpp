#include <iostream>
#include<cstdlib>
using namespace std;

int test[12] ={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
//求(x*y)%n
long long mod_pro(long long x,long long y,long long n)
{
    long long ret=0,tmp=x%n;
    while(y)
    {
        if(y&0x1)if((ret+=tmp)>n)ret-=n;
        if((tmp<<=1)>n)tmp-=n;
        y>>=1;
    }
    return ret;
}

//快速幂，求(a^b) % c
long long mod(long long a,long long b,long long c)
{
    long long ret=1;
    while(b)
    {
        if(b&0x1)ret=mod_pro(ret,a,c);
        a=mod_pro(a,a,c);
        b>>=1;
    }
    return ret;
}

long long ran()
{
    long long ret=rand();
    return ret*rand();
}

bool is_prime(long long n,int t)
{
    if(n<2)return false;
    if(n==2)return true;
    if(!(n&0x1))return false;
    long long k=0,m,a,i;
    for(m=n-1;!(m&1);m>>=1,k++);
    while(t--)
    {
        a=mod(ran()%(n-2)+2,m,n);
        if(a!=1)
        {
            for(i=0;i<k&&a!=n-1;i++)
                a=mod_pro(a,a,n);

            if(i>=k)return false;
        }
    }
    return true;
}
int main(){

	int amount ;
	long long i;
	cin >>amount;
	while(amount--){

		cin >>i;
		if(is_prime(i,1)) cout <<"Yes"<<endl;
		else cout << "No"<<endl;
	}
	return 0;
}
