#include<bits/stdc++.h>
using namespace std ;
#define inf INT_MAX
struct edge{
	int u , v , w ;
};
void solve( )
{
	int n , m , src ;
	cout << "Enter number of nodes:\n" ;
	cin >> n ;
	cout << "Enter number of edges:\n" ;
	cin >> m ;
	cout << "Enter source node:\n" ;
	cin >> src ;
	vector<edge> e(m + 1) ;
        vector<int> dist(n + 1 , inf) ;
	for(int i = 0 ; i < m ; i++)
	{
		cout << "Enter starting node:\n" ;
		cin >> e[i].u ;
		cout << "Enter ending node:\n" ;
		cin >> e[i].v ;
		cout << "Enter weight of edge:\n" ;
		cin >> e[i].w ;
	}
	dist[src] = 0 ;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(dist[e[j].u] < inf)
			{
				dist[e[j].v] = min(dist[e[j].v] , dist[e[j].u] + e[j].w) ;
			}
		}
		cout << "On the iteration " << i << " \n" ;
		for(int j = 1 ; j <= n ; j++)
		{
			cout << j << " --> " << dist[j] << "\n" ;
		}
		cout << "\n" ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cout << i << " --> " << dist[i] << "\n" ;
	}
}
signed main( )
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int testcases = 1 ;		
    // cin >> testcases ;
    while( testcases -- )	
    {
    	solve( ) ;
    	cout << "\n" ;
    }
    return 0 ;
}      
