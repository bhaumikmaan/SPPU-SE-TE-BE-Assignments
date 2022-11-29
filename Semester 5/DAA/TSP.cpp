#include<bits/stdc++.h>
using namespace std;
const int N=5;
#define inf INT_MAX
struct Node{
	vector<int> path;
	vector<vector<int>> matrix;
	int cost;
};
int reduceMatrix(vector<vector<int>>& arr){
	int cost=0;
	for(int i=0;i<N;i++){
		int mn=*min_element(arr[i].begin(),arr[i].end());
		mn=(mn==inf?0:mn);
		cost+=mn;
		for(int j=0;j<N;j++)
			if(arr[i][j]!=inf)
				arr[i][j]-=(mn==inf?0:mn);
	}
	for(int i=0;i<N;i++){
		int mn=INT_MAX;
		for(int j=0;j<N;j++)mn=min(mn,arr[j][i]);
		for(int j=0;j<N;j++)
			if(arr[j][i]!=inf)
				arr[j][i]-=(mn==inf?0:mn);
		cost+=(mn==inf?0:mn);
	}
	return cost;
}
Node* createNode(vector<vector<int>> costMatrix,vector<int> prevPath,int vertex){
	Node* node=new Node();
	node->path=prevPath;
	node->path.push_back(vertex);
	node->matrix=costMatrix;
	node->matrix[vertex][0]=inf;
	if(node->path.size()>1){
		for(int i=0;i<N;i++)
		{
			node->matrix[prevPath.back()][i]=inf;
			node->matrix[i][vertex]=inf;
		}
	}
	return node;
}
void printPath(vector<int> path){
	for(int i=1;i<path.size();i++)
		cout<<path[i-1]+1<<" -------> "<<path[i]+1<<"\n";
}
struct cmp{
	bool operator()(Node* a, Node* b){
 		return a->cost > b->cost;
	}
};
int solve(vector<vector<int>> costMatrix)
{
	priority_queue<Node*,vector<Node*>,cmp> pq;
	vector<int> path;
	Node* root=createNode(costMatrix,path,0);
	root->cost=reduceMatrix(root->matrix);
	pq.push(root);
	while(pq.size()){
		Node* curr=pq.top();pq.pop();
		if(curr->path.size()==N){
			curr->path.push_back(0);
			printPath(curr->path);
			return curr->cost;
		}
		int ver=curr->path.back();
		for(int i=0;i<N;i++)
			if(curr->matrix[ver][i]!=inf){
				Node* child=createNode(curr->matrix,curr->path,i);
				child->cost=curr->cost+curr->matrix[ver][i]+reduceMatrix(child->matrix);
				pq.push(child);
		}
	}
}
int main()
{
    vector<vector<int>> costMatrix={{inf, 10, 8, 9, 7},
 									{10, inf, 10, 5, 6},
									{8, 10, inf, 8, 9},
 									{9, 5, 8, inf, 6},
 									{7, 6, 9, 6, inf}};;
    cout<<"The least cost is "<<solve(costMatrix);
}
