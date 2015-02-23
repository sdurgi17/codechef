#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n ) {
	int count = 0;
	for( int i = 1; i <= sqrt(n) + 1; i++ ) {
		if (n % i == 0 && i != 1 ) {
			count = 2;
			break;
		}
	}
	if ( count == 0 ) {
		return true;
	} 
	return false;
}


void find_primes(int prime[], int n) { 
	prime[0] = 2;
	int  j = 1;
	for ( int i = 2; i < n; i++) {
		if ( isPrime(i)) {
			prime[j] = i;
			j++;
		}
	}
}
void build_factor_arr(int factor_arr[][26], int prime[], int arr[], int n ) {

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < 26; j++ ) {
			factor_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++ ) {
		int num = arr[i];
		int j = 0;
		while ( j < 26 && num != 1 ) {

			if ( num % prime[j] == 0 ) {
				factor_arr[i][j] += 1;
				num = num / prime[j];
			} else {
				j++;
			}
		}

	}
}

void make_sum_arr(int factor_arr[][26], int n ) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 26; ++j){
			factor_arr[i][j] += factor_arr[i - 1][j];
		}
	}
}

long long int pow(int a, int b, long long int m ) {
	if ( b == 0 ) {
		return 1;
	}

	if ( b % 2 == 0 ) {
		long long int prod = pow(a, b/2, m);
		return (prod * prod ) % m;
	} else {
		return (pow(a, b - 1, m) * a) % m;
	}
}

int query(int l, int r, int m, int factor_arr[][26], int n, int prime[] ) {

	int prod[26];

	for (int i = 0; i < 26; i++ ) {
		int diff;

		if ( l != 0 ) {
			diff = factor_arr[r][i] - factor_arr[l - 1][i];
		} else {
			 diff = factor_arr[r][i];
		}

		prod[i] = diff;
	}
	
	long long int product = 1;
	
	for (int i = 0; i < 26; i++ ) { 
		product = (product * pow(prime[i], prod[i], m) ) % m;
	}

	return product;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];

	int prime[26];

	find_primes(prime, 100);


	for (int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
 		// arr[i] = rand() % 100 + 1;
 	}
	int factor_arr[n][26];
	build_factor_arr(factor_arr, prime, arr, n);
	make_sum_arr(factor_arr, n);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i){
		int l;
		int r;
		int m;

		scanf("%d", &l);
		scanf("%d", &r);
		scanf("%d", &m);
		printf("%d\n", query(l-1, r-1, m, factor_arr, n, prime));
	}

	return 0;
}