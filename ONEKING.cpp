#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii reverse(pii a) {
	pii b;
	b.second = a.first;
	b.first = a.second;

	return b;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		pii strt_end[n];
		pii end_strt[n];
		map<pii, bool> hash;

		for (int i = 0; i < n; ++i) {
			
			cin >> strt_end[i].first;
			cin >> strt_end[i].second;

			end_strt[i].first = strt_end[i].second;
			end_strt[i].second = strt_end[i].first;

			hash[end_strt[i]] = false;
		}

		sort(end_strt, end_strt + n);
		sort(strt_end, strt_end + n);

		int bomb_ctr = 0;
		int ite2 = 0;
		for (int i = 0; i < n; i++ ) {
			int end = end_strt[i].first;

			if ( !hash[end_strt[i]] ) {
				hash[end_strt[i]] = true;
				while (ite2 < n && strt_end[ite2].first <= end ) {
					hash[reverse(strt_end[ite2])] = true;
					ite2++;
				}

				bomb_ctr++;
			}
		}

		cout << bomb_ctr << endl;
	}	

	return 0;
}
