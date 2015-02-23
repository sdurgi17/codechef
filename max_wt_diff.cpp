#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int max_diff(long long int arr[], int n, int k ) {
	
	sort(arr, arr + n);
	reverse(arr, arr + n);

	long long int sum1 = 0;
	long long int sum2 = 0;
	if ( k >= n - k ) {
		for ( int i = 0; i < k; i++ )  {
			sum1 += arr[i];
		}

		for ( int i = k; i < n; i++ ) {
			sum2 += arr[i];
		}
	} else {
		for ( int i = 0; i < n - k; i++ ) {
			sum1 += arr[i];
		}
		
		for ( int i = n - k; i < n; i++ ) {
			sum2 += arr[i];
		}
	}
			
	return sum1 - sum2;
}

int main()
{

	int t;
	cin >> t;
	
	for ( int i = 0; i < t; i++ ) {
		
		int n;
		int k;
		
		cin >> n;
		cin >> k;
		
		long long int arr[n];
		
		for ( int j = 0; j < n; j++ ) {
			cin >> arr[j];
		}
		
		cout << max_diff(arr, n, k) << endl;
	}

	return 0;
}

			 
