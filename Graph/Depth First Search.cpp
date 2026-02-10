Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.
class Solution {
  public:
  void dfs(int node,vector<vector<int>> &adj,vector<int>&vis,vector<int>&res){
      res.push_back(node);
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it]) dfs(it,adj,vis,res);
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> vis(n,0),res;
        dfs(0,adj,vis,res);
        return res;
    }
};
