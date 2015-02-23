#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mod( int a ) {
	return a > 0 ? a : (-1 * a);
}

int main()
{
	int n;
	cin >> n;
	
	int m;
	cin >> m;

	string nums;
	cin >> nums;

	int arr[n][10];
	char a = '0';
	
	int cur_num = (int)(nums[0] - a);
	for ( int i = 0; i < cur_num; i++ ) {
		arr[0][i] = 0;
	}

	for ( int i = cur_num + 1; i <= 9; i++ ) {
		arr[0][i] = 0;
	}

	arr[0][cur_num] = 1;

	for ( int i= 1; i < n; i++ ) {
		int cur_num = (int)(nums[i] - a);
		arr[i][cur_num] = arr[i - 1][cur_num] + 1;

		for ( int j = 0; j < cur_num; j++ ) {
			arr[i][j] = arr[i - 1][j];
		}

		for ( int j = cur_num + 1; j <= 9; j++ ) {
			arr[i][j] = arr[i - 1][j];
		}
	}
	
/*	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j <= 9; j++ ) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
*/
	int t_sum = 0;

	for ( int i= 0; i < m; i++ ) {
		int x;
		cin >> x;
		
		if ( x == 1 ) {
			cout << 0 << endl;
		} else {
			int x_num = (int)(nums[x - 1] - a);
	
			for ( int i = 0; i <= 9; i++ ) {
				t_sum += arr[x - 1][i] * mod(x_num - i);
			}

			cout << t_sum << endl;

			t_sum = 0;
		}
	}
			

	return 0;
}		
