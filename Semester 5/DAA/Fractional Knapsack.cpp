#include<bits/stdc++.h>
using namespace std ;
void solve( )
{
	int n , w ;
	cout << "Enter number of elements:\n" ;
	cin >> n ;
	cout << "Enter size of sack:\n" ;
	cin >> w ;
	vector<pair<float,pair<int,int>>> v ;
	for(int i = 0 ; i < n ; i++)
	{
		int x , y ;
		cout << "Enter weight of element:\n" ;
		cin >> x ;
		cout << "Enter profit of element:\n" ;
		cin >> y ;
		float t = y/(float)x ;
		v.push_back({t , {x , y}}) ;
	}
	sort(v.begin() , v.end()) ;
	float ans = 0 ;
	int cnt = 1 ;
	for(int i = n - 1 ; i >= 0 ; i--)
	{
		if(v[i].second.first < w)
		{
			ans += v[i].second.second ;
			cout << "Profit after " << cnt << " iteration is: " << ans << "\n" ;
			cnt++ ;
			w -= v[i].second.first ;
		}
		else
		{
			float temp = w/(float)v[i].second.first ;
			ans += v[i].second.second*(temp) ;
			cout << "Profit after " << cnt << " iteration is: " << ans << "\n" ;
			cnt++ ;
			break ;
		}
	}
	cout << "Total Profit: " << ans << "\n" ;
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
