#include <bits/stdc++.h>

using namespace std;

struct cell {
	int h;
	int d;


	cell () {
		d = -1;
	}
};

struct qCell 
{
	int x;
	int y;

	qCell() {

	}

	qCell(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool operator== (qCell a, qCell b) {
	return a.x == b.x && a.y == b.y;
}


int main()
{
	int t;
	cin >> t;

	while (t--) {
		int m, n, x, y, d;

		cin >> m >> n >> x >> y >> d;

		cell arr[m][n];

		for (int i = 0; i < m; i++ ) {
			for (int j = 0; j < n; j++ ) {
				cin >> arr[i][j].h;
			}
		}

		qCell tmp;
		tmp.x = 0;
		tmp.y = 0;
		arr[tmp.x][tmp.y].d = 0;

		queue<qCell> q;

		q.push(tmp);

		qCell target;
		target.x = x - 1;
		target.y = y - 1;

		int result = -1;

		while(q.size()) {

			qCell f = q.front();
			q.pop();
			if (f == target) {
				result = arr[f.x][f.y].d;
			}

			if (f.x + 1 < m && arr[f.x + 1][f.y].d == -1 && abs(arr[f.x][f.y].h - arr[f.x + 1][f.y].h) <= d ) {
				q.push(qCell(f.x + 1, f.y));
				arr[f.x + 1][f.y].d = arr[f.x][f.y].d + 1;
			} 

			if (f.x - 1 >= 0 && arr[f.x - 1][f.y].d == -1 && abs(arr[f.x][f.y].h - arr[f.x - 1][f.y].h) <= d ) {
				q.push(qCell(f.x - 1, f.y));
				arr[f.x - 1][f.y].d = arr[f.x][f.y].d + 1;
			} 

			if (f.y + 1 < n && arr[f.x][f.y + 1].d == -1 && abs(arr[f.x][f.y].h - arr[f.x][f.y + 1].h) <= d ) {
				q.push(qCell(f.x, f.y + 1));
				arr[f.x][f.y + 1].d = arr[f.x][f.y].d + 1;
			} 

			if (f.y - 1 >= 0 && arr[f.x][f.y - 1].d == -1 && abs(arr[f.x][f.y].h - arr[f.x][f.y - 1].h) <= d ) {
				q.push(qCell(f.x, f.y - 1));
				arr[f.x][f.y - 1].d = arr[f.x][f.y].d + 1;
			}

		}


		cout << (result == -1 || result == 0 ? result : result - 1) << endl;
 	}

 	return 0;
}