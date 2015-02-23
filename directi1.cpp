#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b) {
	if (abs(a) == abs(b)) {
		return a < b; 
	}
	return abs(a) < abs(b);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int arr[2 * n];
		for (int i = 0; i < n; ++i) {
			int entry;
			int ext;

			cin >> entry >> ext;
			
			arr[i] = entry;
			arr[i + n] = -1 * ext;
		}

		sort(arr, arr + 2*n, comp);


		int ctr = 0;
		int mx = 0;
		for (int i = 0; i < 2*n; i++) {
			if (arr[i] > 0 ) {
				ctr++;
				if (ctr > mx) {
					mx = ctr;
				}
			} else {
				ctr--;
			}
		}

		cout << mx << endl;
	}
}