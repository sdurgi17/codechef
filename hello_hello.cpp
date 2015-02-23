#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct plan
{
	float m;	// no of months
	float r; // call rate (rod/min)
	float c;  // cost 
};

int best_plan( float d, int u, plan plan_arr[], int n) {
	float best = d * (float)u;
	int best_indx = -1;

	for ( int i = 0; i < n; i++ ) {
		float cost = (plan_arr[i].c / plan_arr[i].m) + plan_arr[i].r * u;
		if (best > cost) {
			best = cost;
			best_indx = i;
		}
	}

	return best_indx + 1;
}

int main() 
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++ ) {
		float d;  	// default rate
		int u;		// mins talked last month

		cin >> d;	
		cin >> u;

		int n; 		// no of plans
		cin >> n;

		plan plan_arr[n];

		for ( int j = 0; j < n; j++ ) {
			cin >> plan_arr[j].m;
			cin >> plan_arr[j].r;
			cin >> plan_arr[j].c;
		}

		cout << best_plan(d, u, plan_arr, n) << endl;
	}

	return 0;
}
