#include <iostream>
#define mod 1000000007; 


using namespace std;

void power_n( long long int arr[][2], long long int sol[][2], long long int n );

void multiply( long long int a[][2], long long int b[][2], long long int c[][2] ) {

	long long int d[2][2], e[2][2];
	
	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			
			e[i][j] = b[i][j];
			d[i][j] = a[i][j];
		}
	}

	for ( int i = 0; i < 2; i++ ) {
		for ( int j = 0; j < 2; j++ ) {
			int sum = 0;
		
			for ( int k = 0; k < 2; k++ ) {
				sum =  sum % mod ;
				sum = sum + ( d[i][k] * e[k][j] ) % mod ;
			} 
		
			
			c[i][j] = sum % mod ;
		}
	}
}


long long int fib( long long int n ) {

	long long int a[2][2] = { 1, 1, 1, 0 };
	long long int c[2][2];
	
	power_n(a, c, n );
	
	return c[0][0];
}

/*	long long int a = 1;
	long long int b = 2;
	long long int k = 3;
	long long int c = a + b;
	
	if ( n == 1) 
		return a;

	if ( n == 2 ) 
		return b;
	
	while ( k <= n ) {
		c = a + b;
		a = b;
		b = c;

		k++;
	}
	
	return c % mod;
*/

void power_n( long long int arr[][2], long long int sol[][2], long long int n ) {
	
	if ( n == 1 ) {
		sol[0][0] = arr[0][0];
		sol[0][1] = arr[0][1];
		sol[1][0] = arr[1][0];
		sol[1][1] = arr[1][1];

		return;
	}

	if ( n == 2 ) {
		multiply( arr, arr, sol );
		return;
	}
	else if ( n % 2 == 0 ) {
		power_n( arr, sol, n/2 );
		multiply( sol, sol, sol);
	} else {
		power_n(arr, sol, n - 1);
		multiply(arr, sol, sol );
	}

	return;
}

long long int no_of_ones( long long int n ) {
	long long int sol = 0;

	while ( n > 1 ) {
		if ( n % 2 == 1 ) {
			sol++;
		}

		n = n / 2;
	}

	if ( n == 1 ) {
		sol++;
	}

	return sol;
}

int main()
{
	int t;
	cin >> t;

	for ( int i = 0; i < t; i++ ) {
		long long int k;
		cin >> k;

		long long int g;
		cin >> g;

		if ( g == no_of_ones( fib(k) ) ) {
			cout << "CORRECT" << endl;				
		} else {
			cout << "INCORRECT" << endl;				
		}
	}

	return 0;
}
