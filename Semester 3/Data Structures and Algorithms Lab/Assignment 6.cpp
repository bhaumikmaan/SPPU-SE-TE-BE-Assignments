/***  KNOWLEDGE IS POWER  ***/

#include<iostream>
#include<queue>
using namespace std;	

class graph
{
    int** gr ;
    int *visited ;
    int size , inf = 10000000 ;
  
//================== Init ==================//
    public:
    graph(int sz)
    {
    	size = sz ;
        visited = new int(sz) ;
        gr = new int*[sz] ;
        for(int i = 0 ; i < sz ; i++)
        {
            visited[i] = 0 ;
            gr[i] = new int[sz] ;
            for(int j = 0 ; j < sz ; j++)
            {
            	gr[i][j] = inf ;
            }
        }
    }
    void add(int start , int end , int weight)
    {
        gr[start][end] = weight ;
        gr[end][start] = weight ;
    }
  
//================== Functions ==================//
  
	void djisktra(int position)
    {
        int dist[size] ;
        
        for(int i = 0 ; i < size ; i++)
        {
            dist[i] = inf ;
            visited[i] = 0 ;
        }
        dist[position] = 0 ;
        for(int i = 0 ; i < size ; i++)
        {
            int mn = inf , ind = -1 ; // Finding node with minimum val
            for(int j = 0 ; j < size ; j++)
            {
                if(visited[j] == 0 && dist[j] < mn)
                {
                    mn = min(mn , dist[j]) ;
                    ind = j ;
                }
            }
            if(ind == -1)
            {
                break ;
            }
            visited[ind] = 1 ;
            
            for(int j = 0 ; j < size ; j++)
            {
                dist[j] = min(dist[j] , dist[ind] + gr[ind][j]) ;
            }
        }
        for(int i = 0 ; i < size ; i++)
        {
            cout << "The distance of "<< i << " from " << position << " is : " << dist[i] << "\n" ;
        }
    }    
    
    void dfs(int node)
    {
        visited[node] = 1 ;
        cout << node << " " ;
        for(int i = 0 ; i < size ; i++)
        {
            if(visited[i] == 0 && gr[node][i] > 0)
            {
                dfs(i) ;
            }
        }
    }
    
    void bfs(int root)
    {
        for(int i = 0 ; i < size ; i++)
        {
            visited[i] = 0 ;
        }
        queue<int> q ;
        q.push(root) ;
        visited[root] = 1 ;
        while(!q.empty())
        {
            int fr = q.front() ;
            q.pop() ;
            cout << fr << " " ;
            for(int i = 0 ; i < size ; i++)
            {
                if(visited[i] == 0 && gr[fr][i] > 0)
                {
                    visited[i] = 1 ;
                    q.push(i) ;
                }
            }
        }
    }
};

int main()
{
    cout << "Enter the size of the graph: " ;
    int size ;
    cin >> size ;
    graph gr(size) ;
    cout << "Enter the number of the edges :";
    int edges ;
    cin >> edges ;
    cout<<"\n";
    for(int i = 0 ; i < edges ; i++)
    {
        cout << "Enter the details of the edge " << i << " : " ;
        int source , destination , weight ;
        cin >> source >> destination >> weight ;
        gr.add(source , destination , weight) ;
    }
    
    cout<<"The DFS order of the tree is: ";
    gr.dfs(0);
    cout<<"\n\n";
    
    cout<<"The BFS order of the tree is: ";
    gr.bfs(0);
    cout<<"\n\n";
    
    gr.djisktra(0);
    return 0 ;
}
/***  END   ***/
