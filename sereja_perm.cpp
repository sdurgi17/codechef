#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

struct val {
	int i;
	int r;
};

bool comp(val a, val b ) {
	return a.r < b.r;
}


int main()
{
	int t;
	srand(time(NULL));
	cin >> t;

	while (t--) {
		int n, k, s;
		cin >> n >> k >> s;
		
		vector<val> arr;

		for ( int i = 0; i < n; i++ ) {
			int a;
			cin >> a;
			val tmp;
			tmp.i = i + 1;
			tmp.r = rand();
			arr.push_back(tmp);
		}

		sort(arr.begin(), arr.end(), comp);

		for ( int i = 0; i < n; i++ ) {
			cout << arr[i].i << " ";
		}

		cout << endl;
	}

	return 0;
}
