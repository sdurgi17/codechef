#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(int arr[], int n) {
	int count = 0;

	for (int i = 0; i < n; ++i) {
		count += arr[i];
	}

	return count;
}

void print_arr ( float arr[][10100], int n, int m ) {
			cout << endl;
		cout << endl;
		cout << endl;	
	for ( int i = 0; i < n; i++ ) {
		for ( int  j = 0; j < m; j++ ) {
			cout << arr[i][j] << "  ";
		}

		cout << endl;
	}
		cout << endl;
		cout << endl;
		cout << endl;
	
}

void print_arr1(float arr[], int n) {
	for (int i = 0; i < n; ++i){
		cout << arr[i] << "  ";
	}

	cout << endl << endl;
}

float winProbabilty(int n, int flag[], float prob[]) {

	int sum = getSum(flag, n);
	if ( sum % 2 == 0 ) {
		sum = (sum / 2 ) ;
	} else {
		sum = (sum / 2) + 1;
	}

	float arr[n][10100];
	

	for (int i = 0; i < n; i++){
		for (int j = 0; j < sum; j++){
			arr[i][j] = 0;
		}
	}

	arr[0][0] = 1 - prob[0];	
	
	for (int i = 1; i < n; ++i) {
		arr[i][0] = arr[i-1][0] * ( 1 - prob[i]);
	}

	arr[0][flag[0]] = prob[0];

	for (int i = 1; i < n; ++i){
		for (int j = 0; j < sum; ++j){
			arr[i][j] = arr[i - 1][j] * ( 1 - prob[i]);
		}
		for (int j = 0; j < sum; ++j) {
			if (arr[i - 1][j] != 0 ) {
				if ( j + flag[i] < sum) {
			//		arr[i][j + flag[i]] = arr[i - 1][j + flag[i]] * ( prob[i]);
					arr[i][j + flag[i]] += arr[i - 1][j] * (prob[i]);
				}
			}
		}
	}

	float total_prob = 0;
	for ( int i = 0; i < sum; i++ ) {
		total_prob += arr[n-1][i];
	}

	return 1 - total_prob;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		int flags[n];
		for (int j = 0; j < n; ++j) {
			cin >> flags[j];
		}

		float prob[n];
		for (int j = 0; j < n; ++j) {
			cin >> prob[j];
			prob[j] *= 0.01;
		}


		printf("%.7f\n", winProbabilty(n, flags, prob));

	}

	return 0;
}