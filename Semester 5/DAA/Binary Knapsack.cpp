#include<bits/stdc++.h>
using namespace std ;
void solve( )
{
	int n , w ;
	cout << "Enter number of elements:\n" ;
	cin >> n ;
	cout << "Enter size of sack:\n" ;
	cin >> W ;
	int p[n] , w[n] , dp[n + 1][W + 1] ;
	for(int i = 0 ; i < n ; i++)
	{
		cout << "Enter weight of element:\n" ;
		cin >> w[i] ;
		cout << "Enter profit of element:\n" ;
		cin >> p[i] ;
	}
	memset(dp , 0 , sizeof(dp)) ;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= W ; j++)
		{
			if(w[i - 1] <= j)
			{
				dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]] , dp[i - 1][j]) ;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] ;
			}
		}
	}
	vector<int> v ;
	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= W ; j++)
		{
			cout << dp[i][j] << " " ;
		}
		cout << "\n" ;
	}
	cout << "Max Profit: " << dp[n][W] << "\n" ;
	for(int i = n ; i ; i--)
	{
		if(dp[i][W] != dp[i - 1][W])
		{
			v.push_back(i) ;
		}
	}
	cout << "Selected Items:\n" ;
	for(auto i:v)
	{
		cout << i << " " ;
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
