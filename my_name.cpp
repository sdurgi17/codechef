#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

bool isSubsequence(string a, string b);

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
			string a;
			string b;

			cin >> a;
			cin >> b;

			if ( a.size() > b.size() ) {
				if ( isSubsequence(a, b) ) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				if (isSubsequence(b, a)) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
	}

	return 0;
}

bool isSubsequence(string a, string b) {
	int i = 0;
	int j = 0;

	while (i < b.size() ) {
		if ( b[i] == a[j]) { 
			j++;
			i++;	
		} else {
			j++;
		}
		
		if ( i == b.size() ) {
			return true;
		}

		if ( j == a.size() ) {
			break;
		}
	}

	return false;
}