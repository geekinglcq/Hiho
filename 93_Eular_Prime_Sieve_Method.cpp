#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	std::vector<bool> isPrime(n+1,true);
	std::vector<int> primeList;
	int primeCount = 0;
	for(int i=2;i<=n;i++){
		if (isPrime[i]){			
			primeList[primeCount++] = i;
			primeList.push_back(i);
		}
		for(int j=0;j<primeCount;j++){
			if(i*primeList[j] > n) break;
			isPrime[i*primeList[j]] = false;
			if(i%primeList[j]==0) break;
		}
	}
	cout << primeCount;
	return 0;
}
