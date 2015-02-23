#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

bool check( int l[], int r[], int a[], int b[], int k, int p ) {
	for ( int i = 0; i < p; i++ ) {
		if ( !( binary_search(l, l + k, a[i]) && binary_search(r, r + k, b[i]) ) ) {
			return false;
		}
	}

	return true;
}
			
int main()
{
	int t;
	cin >> t;

	while(t--) {
		int n;
		int k;
		int p;

		cin >> n >> k >> p;
		int l[k];
		int r[k];
		
		int a[p];
		int b[p];

		for ( int i = 0; i < k; i++ ) {
			cin >> l[i];
			cin >> r[i];
		}

		for ( int i = 0; i < p; i++ ) {
			cin >> a[i];
			cin >> b[i];
		}

		sort(l, l + k);
		sort(r, r + k);

		if ( check(l, r, a, b, k, p) ) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

	}
	
	return 0;
}
