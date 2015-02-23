#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;
int arr[26];

void increment(string &a) {
	for (int i = 0; i < a.size(); ++i) {
		arr[a[i] - 97]++;
	}
}

void decrement(string &a) {
	for (int i = 0; i < a.size(); ++i) {
		arr[a[i] - 97]--;
	}
}

int main(int argc, char const *argv[])
{

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		for (int i = 0; i < 26; ++i) {
			arr[i] = 0;
		}
		
		string a;
		cin >> a;
		string b;
		cin >> b;

		increment(a);
		increment(b);

		int c;
		
		cin >> c;
		for (int j = 0; j < c; ++j) {
			string child;
			cin >> child;

			decrement(child);
		}

		bool flag = true;
		for (int j = 0; j < 26; ++j) {
			if ( arr[j] < 0) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "YES" << endl;
		}

	}

	return 0;
}
