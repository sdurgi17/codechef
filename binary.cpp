#include <iostream>
#include <vector>

using namespace std;

void get_path(vector<int>& p_a, int a) {
	
	while ( a != 1 ) {
		p_a.push_back(a);

		if ( a % 2 == 0 ) {
			a = a/ 2;
		} else {
			a--;
			a = a/ 2;
		}
	}

	p_a.push_back(a);
/*
	for ( int i = 0; i < p_a.size(); i++ ) {
		cout << p_a[i] << " ";
	} 
	cout << endl << endl;
*/
}

int shortest_path(int a, int b ) {
	vector<int> p_a;
	vector<int> p_b;

	get_path(p_a, a);
	get_path(p_b, b);
	
	int i = p_a.size() - 1;
	int j = p_b.size() - 1;

	while ( (i >= 0 && j >= 0 ) && p_a[i] == p_b[j] ) {
		i--;
		j--;
	}
	
	return i + j + 2;

}

int main()
{
	int t;
	cin >> t;

	while (t-- ) {
		int a;
		int b;

		cin >> a >> b;
		
		if ( a == b ) {
			cout << 0 << endl;
		} else {
			cout << shortest_path(a, b) << endl;
		}
	}

	return 0;
}
