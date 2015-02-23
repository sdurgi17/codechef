#define MOD 1000000007
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

long long int noOfPasses(long long int n, long long int k ) {
	if ( n == 2 ) {
		return k;
	}
	
	if ( n == 3 ) {
		return (k * (k - 1));
	}

	long long int a = 0;
	long long int b = 1;
	long long int c = b * (k - 1) + (k * a);

	for ( int i = 2; i < n - 1; i++ ) {
		c = ((b * (k - 1) ) % MOD) + (( k * a ) % MOD);
		c = (c + MOD) % MOD;	
		a = (b + MOD) % MOD;
		b = (c + MOD) % MOD;
	}	
	
	long long int sol = 1;

	for ( int i = 0; i < n -1; i++ ) {
		sol = ((sol * k) % MOD);
	}
	
	return (((sol - ((k * c) % MOD ) ) + MOD) % MOD);
}

int main()
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		long long int n;
		long long int k;

		cin >> n;
		cin >> k;
		
		cout << noOfPasses(n, k) << endl;
	}

	return 0;
}
