#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		long long int n;
		long long int m;

		cin >> n;
		cin >> m;
		if ( m == 0 ) {
			cout << 0 << " " << n << endl;
		} else {
			cout << (n / m) << " " << (n % m) << endl;

		}
	}

	return 0;

}
