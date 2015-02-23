#include <iostream>
#include <vector>

using namespace std;

long double expectation(long double n, long double k, long double r ) {
	
	if ( k == 0 ) {
		return  n * r * n;
	}

	long double sol = 0;
	for ( long long int i = n - k - 1; i <= n - 1; i++ ) {
		if ( i > 0 )
			sol += expectation(i, k - 1, (r/i));

	}

	return sol;
}


int main()
{
	long long int t;
	cin >> t;

	for ( long long int i = 0; i < t; i++ ) {
		long double  n;
		long long int k;

		cin >> n;
		cin >> k;

		cout << expectation(n, k, (long double)(1/n)) << endl;
	}

	return 0;
}

