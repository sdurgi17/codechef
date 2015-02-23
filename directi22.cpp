#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;
struct cell
{
	int val;
	int parent;
	int sub_tree_val;

	cell() {
		val = 0;
		parent = 0;
		sub_tree_val = 0;
	}
};

void changeParentVals(cell arr[], int n, int x, int y) {
	if (x == 0) {
		return;
	}

	arr[x-1].sub_tree_val += y;
	arr[x-1].sub_tree_val %= mod;
	changeParentVals(arr, n, arr[x-1].parent, y);
}

void changeAllVals(cell arr[], int n, int x, int v, int sv) {
	if (x == 0) {
		return;
	}

	arr[x-1].val += v;
	arr[x-1].val %= mod;
	arr[x-1].sub_tree_val += sv;

	changeAllVals(arr, n, arr[x-1].parent, v, (sv + v) %  mod);

}

int main()
{
	int t;
	cin >> t;

	while(t--) {
		int n, m, q;
		cin >> n >> m >> q;

		cell arr[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].parent;
		}

		for (int i = 0; i < m; i++ ) {
			string str;
			cin >> str;

			int x;
			int y;

			cin >> x >> y;

			if (str == "ADD") {
				arr[x-1].val += y;
				arr[x-1].val %= mod;
				arr[x-1].sub_tree_val += y;
				arr[x-1].sub_tree_val %= mod;
				changeParentVals(arr, n, arr[x-1].parent, y);
			}

			if (str == "ADDUP") {
				arr[x-1].val += y;
				arr[x-1].val %= mod;
				arr[x-1].sub_tree_val += y;
				arr[x-1].sub_tree_val %= mod;
				changeAllVals(arr, n, arr[x-1].parent, y, y);
			}
		}

		for (int i = 0; i < q; ++i) {
			string str;
			cin >> str;
			int x;
			cin >> x;

			if (str == "VAL") {
				cout << arr[x-1].val << endl;
			} else {
				cout << arr[x-1].sub_tree_val << endl;
			}
		}
	}

	return 0;
}