#include <iostream>
#include <string>
#include <queue>

using namespace std;

long long int total_litres(vector<priority_queue<long long int> > &vp, int arr[], int m ) {
	long long int total = 0;
	for ( int i = 0; i < m; i++ ) {
		if ( !vp[arr[i]].empty() ) {
			total += vp[arr[i]].top();
			vp[arr[i]].pop();
		}
	}

	return total;
}

int main()
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		int n;
		int m;

		cin >> n;
		cin >> m;

		int arr[m];

		for ( int j = 0; j < m; j++ ){
			cin >> arr[j];
		}
		
		vector<priority_queue<long long int> > vp;

		for ( int j = 0; j < n; j++ ) {
			int c;
			cin >> c;
			priority_queue<long long int> p;
			for ( int k = 0; k < c; k++ ) {
				long long int lit;
				cin >> lit;
				p.push(lit);
			}

			vp.push_back(p);
		}
		
		cout << total_litres(vp, arr, m) << endl;
	}

	return 0;
}
