#include <iostream>

using namespace std;

bool is_prime( int n ) {
	int ctr = 0;
	for ( int i = 1; i <= n; i++ ) {
		if ( n%i == 0 ) {
			ctr++;
		}
	}

	if ( ctr == 2 ) {
		return true;
	} else {
		return false;
	}
}

int next_prime( int n ) {

	while ( !is_prime(n) ) {
		n++;
	}

	return n;
}

int main()
{
	int t;

	cin >> t;

	while (t--) {
		int x;
		int y;

		cin >> x >> y;

		int z = next_prime(x + y + 1);

		cout << z - ( x + y ) << endl;
	}

	return 0;
}
