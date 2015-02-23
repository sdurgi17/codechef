#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;
int A = 103993;
int B = 33102;

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
		

int main() 
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		int n;
		cin >> n;

		print_pi(n);
	}

	return 0;
}
