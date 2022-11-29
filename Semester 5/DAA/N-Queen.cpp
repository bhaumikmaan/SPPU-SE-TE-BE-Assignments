#include<bits/stdc++.h>
using namespace std ;
vector<vector<int>> result ;
bool isSafe(vector<vector<int>> board , int row , int col)
{
    int N = board.size() ;
 
    // row check
    for(int i = 0 ; i < col ; i++)
    {
    	if(board[row][i])
    	{
    		return false ;
    	}
    }
 
    // upper diagonal check
    for(int i = row, j = col ; i >= 0 && j >= 0 ; i-- , j--)
    {
    	if(board[i][j])
    	{
    		return false ;
    	}
    }
    // lower diagonal check
    for(int i = row, j = col ; j >= 0 && i < N ; i++ , j--)
    {
    	if(board[i][j])
    	{
    		return false ;
    	}
    }
    return true;
}
 
bool solveNQUtil(vector<vector<int>> &board , int col)
{
    int N = board.size() ;
    if (col == N) // all placed, store position
    { 
        vector<int> v ;
        for(int i = 0 ; i < N ; i++) 
        {
            for(int j = 0 ; j < N ; j++) 
            {
                if(board[i][j] == 1)
                {
                	v.push_back(j + 1) ;
                }
            }
        }
        result.push_back(v) ;
        return true ;
    }
    bool flag = false ;
    for(int i = 0 ; i < N ; i++) 
    {
        if(isSafe(board , i , col)) 
        {
            board[i][col] = 1 ;
	 		// check for further col
            flag = solveNQUtil(board , col + 1)||flag ;
            board[i][col] = 0 ; // BACKTRACK
        }
    }
    return flag ;
}
vector<vector<int>> nQueen(int n)
{
    result.clear() ;
    vector<vector<int>> board(n, vector<int>(n, 0)) ;
    if(solveNQUtil(board, 0) == false) 
    {
        return {} ;
    }
    sort(result.begin() , result.end()) ;
    return result ;
}
 
void solve( )
{
	int n = 4 ;
	vector<vector<int>> v = nQueen(n) ;
	for(auto i:v)
	{
		for(auto j:i)
		{
			cout << j << " " ;
		}
		cout << "\n" ;
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
