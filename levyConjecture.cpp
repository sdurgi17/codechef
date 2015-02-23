#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<bool> prime(10000, false);
vector<int> primeInt;

int levyCondn( long long int n );
void calcPrimes();

bool isPrime(int n );

int main() 
{
	
	calcPrimes();
	long long int t;
	cin >> t;

	for ( long long int i = 0; i < t; i++ ) {
		long long int tmp;
		cin >> tmp;
		printf("%d\n", levyCondn(tmp) );
	}

	return 0;
}

int levyCondn( long long int n ) {
	int ctr = 0;
	for ( int i = 0; i < primeInt.size() && primeInt[i] < n && (n - (2 * primeInt[i])) > 0; i++ ) {
		if ( prime[primeInt[i]] && prime[n - (2 * primeInt[i])]  ) {
			ctr++;
		}
	}

	return ctr;
}


void calcPrimes() {
	for ( int i = 2; i < 10000; i++ ) {
		if ( isPrime(i) ) {
			prime[i] = true;
			primeInt.push_back(i);
		}
	}
	
	prime[2] = true;
}

bool isPrime(int n ) {
	for ( int i = 2; i < (n / 2) + 1; i++ ) {
		if ( n % i == 0 ) {
			return false;
		} 
	}
	
	return true;
}
