#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	int t;
	cin >> t;

	for ( int k = 0; k < t; k++ ) {
		string arr;
		cin >> arr;
		vector<char> brr;
	
		int s = arr.size();
		
		bool flag = true;
	
		for(int i = 0; i < s; i++ ) {
			if ( arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' ||  arr[i] == '7' ) {
				cout << "NO" << endl;	
				flag = false;
				break;
			} else {
				switch (arr[i] ) {
				case '9' :
				 brr.push_back('6');
				 break;
				 
				 case '6' :
				 brr.push_back('9');
			 	 break;
				 
				 case '1' :
				 brr.push_back('1');
				 break;
				 
				 case '0' :
				 brr.push_back('0');
				 break;
				
				case '8':
				brr.push_back('8');
				break;
			}		 
		}
	}

	if ( flag ) {
		cout << "YES" << endl;
		for ( int i = brr.size() - 1; i >= 0; i-- ) {
			cout << brr[i];
		}
		cout << endl;
	}
}
	return 0;
}
