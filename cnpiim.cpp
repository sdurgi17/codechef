#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	
	int t;
	cin >> t;

	int max = 1250 * 1250 + 1;
	long int arr[max];
	
	for ( int i = 0; i <= max; i++ ) {
		arr[i] = 0;
	}
	
	for ( int i = 1; i <= max; i++ ) {
		for ( int j = 1; j <= max; j++ ) {
			if ( i * j > max ) {
				break;
			}
			arr[i * j]++;
		}
	}
	
	
	for ( int i = 1; i <= max; i++ ) {
		arr[i] = arr[i - 1] + arr[i];
	}
	

	while(t--) {
		int n;
		cin >> n;
/*		
		for ( int i = 0; i < n; i++ ) {
			cout << arr[i] << " ";
		}
		cout << endl;
*/

	 	long long int t_sum = 0;
		for ( int i = 1; i <= n - 1; i++ ) {
			t_sum += arr[i * (n - i) - 1];
		}

		printf("%lld\n", t_sum);
		
		t_sum = 0;
	}

	return 0;
}


