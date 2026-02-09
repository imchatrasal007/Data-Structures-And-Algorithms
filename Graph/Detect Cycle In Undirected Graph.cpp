Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
Note: The graph can have multiple component.

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleUtil(int v,vector<vector<int>>&adj,vector<bool>&visited,int parent){
        visited[v]=true;
        for(int i:adj[v]){
            if(!visited[i]){
                if(isCycleUtil(i,adj,visited,v))
                return true;
            }
            else if(i!=parent) return true;
        }
        return false;
    }
   vector<vector<int>> constructadj(int V,vector<vector<int>>&edges){
       vector<vector<int>> adj(V);
       for(auto it:edges){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       return adj;
   }
    bool isCycle(int V,vector<vector<int>>& edges) {
        vector<vector<int>> adj=constructadj(V,edges);
        vector<bool> visited(V,false);
        for(int u=0;u<V;u++){
            if(!visited[u]){
                if(isCycleUtil(u,adj,visited,-1))
                return true;
            }
        }
        return false;
    }
};
  
