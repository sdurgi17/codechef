#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>

typedef long long int lli;

using namespace std;

lli minPlates(lli arr[], int n, lli m) {
	if ( m == 0 ) {
		return 0;
	}
	sort(arr, arr + n);

	lli t = 0;


	for ( int i = n - 1; i >= 0; i-- ) {

		t += arr[i];

		if ( t >= m ) {
			return n - i;
		}

	}

	return -1;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		lli m;
		cin >> m;

		lli p[n];

		for (int j = 0; j < n; j++ ) {
			cin >> p[j];	
		}

		cout << minPlates(p, n, m) << endl;
	}
	return 0;
}