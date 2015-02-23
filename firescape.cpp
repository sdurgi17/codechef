#include <iostream>
#include <vector>
#include <cstdio>
#define MOD 1000000007

using namespace std;

struct node {
	vector<long long int> v;
	bool visited;

	node() {
		visited = false;
	}
};

class graph {

	public :
	
	vector<node> G;
	vector<long long int> g_size;

	void divide_groups() {
		for ( long long int i = 0; i < G.size(); i++ ) {
			if ( !G[i].visited ) {
				long long int s = dfs(i);

				if ( s ) {
					g_size.push_back(s);
				}
			}
		}
		
		cout << g_size.size() << " ";
		no_ways();
		cout << endl;
	}
	
	void no_ways() {
		long long int sol = 1;
	
		for ( long long int i = 0; i < g_size.size(); i++ ) {
			sol *= g_size[i];
			sol = sol % MOD;
		}
	
		cout << sol;
	}

	long long int dfs(long long int n ) {
		if ( G[n].visited ) {
			return 0;
		} 

		G[n].visited = true;
		
		long long int sol = 1;
		for ( long long int i = 0; i < G[n].v.size(); i++ ) {
			long long int d = dfs(G[n].v[i]);
			sol += d;
		}

		return sol;
	}

	
	void insert( long long int v1, long long int v2 ) {
		G[v1].v.push_back(v2);
	}
/*	
	void print_graph() {
		for ( long long int i = 0; i < G.size(); i++ ) {
			cout << " node " << i << " :::  ";
			print(G[i]);
		}
	}

	void print(node n) {
		for ( long long int i = 0; i < n.v.size(); i++ ) {
			cout << n.v[i] <<  "   ";
		}

		cout << endl;
	}
*/

	graph(long long int v, long long int e ) {
		
		node tmp;	
		for ( long long int i = 0; i < v; i++ ) {
			G.push_back(tmp);
		}

		for ( long long int i = 0; i < e; i++ ) {
			long long int v1;
			long long int v2;

			cin >> v1;
			cin >> v2;
	
			insert(v1 - 1, v2 - 1);
			insert(v2 - 1, v1 - 1);
		}
	}
};


int main()
{
	long long int t;
	cin >> t;

	for ( long long int i = 0; i < t; i++ ) {
		long long int n;
		long long int e;

		cin >> n;
		cin >> e;
	
		graph g(n, e);
		g.divide_groups();
		
	}
	
	return 0;
}
