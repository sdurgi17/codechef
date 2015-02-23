#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
string byte;
string bcaps;

void print_char( char ch ) {
	if ( ch == '.' || ch == '?' || ch == ',' || ch == '!' ) {
		cout << ch;
		return;
	}
	
	if ( ch == '_' ) {
		cout << " ";
		return;
	}

	if ( (int) ch > 96 ) {
		cout << byte[ch - 97];
	} else {
		cout << (char)(byte[ch - 65] - 32);
	}
}

void translate(string s ) {
	for ( int i = 0; i < s.size(); i++ ) {
		print_char(s[i] );
	}
	
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	char ch;

	if ( (ch = getchar()) == ' ' ) {
		cin >> byte;
	}
	
	for ( int i = 0; i < t; i++ ) {
		string s;
		cin >> s;

		translate(s);
	}


	return 0;

}
