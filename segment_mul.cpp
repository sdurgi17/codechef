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


void find_primes(vector<int> &prime, int n) { 
	prime.push_back(2);
	for ( int i = 2; i < n; i++) {
		if ( isPrime(i)) {
			prime.push_back(i);
		}
	}
}

void print_vec(vector<int> &vec ) {
	cout << endl << endl;
	for (int i = 0; i < vec.size(); ++i){
		cout << vec[i] << "  ";
	}

	cout << endl << endl;
}



void build_factor_arr(int factor_arr[][30], vector<int> &prime, int arr[], int n ) {

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < 30; j++ ) {
			factor_arr[i][j] = 0;
		}
	}

	//cout << " done " << endl;
	for (int i = 0; i < n; i++ ) {
		int num = arr[i];
		int j = 0;
	//	cout << "arr[i] is  " << arr[i] << endl;
		while ( j < prime.size() && num != 1 ) {

			if ( num % prime[j] == 0 ) {
				factor_arr[i][j] += 1;
				num = num / prime[j];
			//	getchar();
	//			cout << num << "   ";
			} else {
				j++;
			}
		}

	}
}

void make_sum_arr(int factor_arr[][30], int n ) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 30; ++j){
			factor_arr[i][j] += factor_arr[i - 1][j];
		}
	}
}

void print_2darr(int arr[][30], int n ) {
		cout << endl;
		cout << endl;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 30; ++j){
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

long long int pow(int a, int b, long long int m ) {
	if ( b == 0 ) {
		return 1;
	}

	long long int product = 1;
	for ( int  i = 0; i < b; i++ ) {
		product = ( product * a ) % m;
	}

	return product;
}

int query(int l, int r, int m, int factor_arr[][30], int n, vector<int> &prime ) {

	vector<int> prod;

	for (int i = 0; i < 30; i++ ) {
		int diff;

		if ( l != 0 ) {
			diff = factor_arr[r][i] - factor_arr[l - 1][i];
		} else {
			 diff = factor_arr[r][i];
		}

		prod.push_back(diff);
	}
	
	long long int product = 1;
	
	for (int i = 0; i < prod.size(); i++ ) { 
		product = (product * pow(prime[i], prod[i], m) ) % m;
	}

	return product;
}

int main(int argc, char const *argv[])
{




	int n;
	cin >> n;
	int arr[n];

	vector<int> prime;

	find_primes(prime, 100);


	for (int i = 0; i < n; ++i){
		cin >> arr[i];
 	//	arr[i] = (rand() % 100)+ 1;
 	}
	// getchar();
	// cout << " done " << endl;
	// getchar();

	int factor_arr[n][30];

	// getchar();
	// cout << sizeof(factor_arr) << endl;
	// getchar();

	build_factor_arr(factor_arr, prime, arr, n);
	// getchar();
	// cout << " done " << endl;
	// getchar();

//	print_2darr(factor_arr, n);
	make_sum_arr(factor_arr, n);
//	print_2darr(factor_arr, n);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i){
		int l;
		int r;
		int m;

		// cin >> l;
		// cin >> r;
		// cin >> m;
		l = rand() % 30 + 1;
		r =  l + 20;
		m = 1000000;
		cout << query(l-1, r-1, m, factor_arr, n, prime) << endl;
//		cout << i<< endl;

	}

	return 0;
}