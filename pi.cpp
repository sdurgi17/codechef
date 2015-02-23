#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;
int A = 103993;
int B = 33102;
string str = "415926530119026040722614947737296840070086399613316";

void print_pi(long long int n ) {
	long long int ctr = 0;
	int a = A;
	int b = B;
		
	while(ctr < n + 1) {
		cout << (a/b);
		a = a%b;
	
		int rem = 0;	
		while ( a < b ) {
			a = a * 10;
			if ( ctr == 0 && rem == 0 ) {
				if ( n == 0 ) {
					return;
				}

				cout <<".";
			} else if ( rem ) {
				cout << 0;
				ctr++;
			}

			rem++;
		}
		
		ctr++;
	}
				
}			
		
void print(long long int n ) {
	long long int ctr = 0;
	if ( n == 0 ) {
		cout << 3 << endl;
	} else if ( n == 1 ) {
		cout << "3.1" << endl;
	} else {
		int q = (n - 1)/51;
		int rem = (n -1) % 51;

		cout << "3.1";
		for ( int i = 0; i < q; i++ ) {
			cout << str;
		}

		for ( int i = 0; i< rem; i++ ) {
			cout<< str[i];
		}
		
		cout << endl;
	}
	
	return;
}

int main() 
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		int n;
		cin >> n;

		print(n);
	}

	return 0;
}
