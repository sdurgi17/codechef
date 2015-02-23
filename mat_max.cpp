#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long int n;
	long long int q;

	cin >> n;
	cin >> q;
	
	long long int row[n];
	long long int col[n];

	for ( int i = 0; i < n; i++ ) {
		row[i] = 0;
		col[i] = 0;
	}

	for ( int i = 0; i < q; i++ ) {
		string s;
		cin >> s;

		if ( s == "RowAdd" ) {
			long long int r;
			long long int mod;

			cin >> r;
			cin >> mod;
			
			row[r] += mod;
		} else if ( s == "ColAdd" ) {
			long long int c;
			long long int mod;

			cin >> c;
			cin >> mod;
			col[c] += mod;
		}
	}
	
	long long int maxr = 0;
	for ( long long int i = 0; i < n; i++ ) {
		if ( row[i] > maxr ) {
			maxr = row[i];
		}
	}

	long long int maxc = 0;
	for ( long long int i = 0; i < n; i++ ) {
		if ( col[i] > maxc ) {
			maxc = col[i];
		}
	}

	cout << maxr + maxc << endl;

	return 0;
}
