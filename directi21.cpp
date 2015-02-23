#include <bits/stdc++.h>

using namespace std;
int p;
int k;

int getMinPath (int arr[][2], int d[][2], int i, int j, int n ) {
	if (d[i][j] != -1) {
		return d[i][j];
	}
 
	if (i == n -1) {
		return arr[i][j];
	}

	int min = INT_MAX;
	for (int x = i+1; x <= i + k && x < n; x++) {
		int cur = arr[i][j] + getMinPath(arr, d, x, j, n);
		if (min > cur) {
			min = cur;
		}
	}

	for (int x = i+1; x <= i + k && x < n; x++) {
		int cur = arr[i][j] + getMinPath(arr, d, x, (j+1)%2, n) + p;
		if (min > cur) {
			min = cur;
		}
	}

	d[i][j] = min;

	return d[i][j];

}


int main()
{
	int t;
	cin >> t;

	while(t--) {
		int n;

		cin >> n;
		cin >> k;
		cin >> p;
		int arr[n][2];

		for (int i = 0; i < n; ++i) {
			cin >> arr[i][0];
		}

		for (int i = 0; i < n; ++i) {
			cin >> arr[i][1];
		}

		int d[n][2];
		for (int i = 0; i < n; i++ ) {
			d[i][0] = -1;
			d[i][1] = -1;
		}

		cout << min(getMinPath(arr, d, 0, 0, n), getMinPath(arr, d, 0, 1, n)) << endl;
	}

	return 0;
}