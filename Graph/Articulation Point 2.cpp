You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.
Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

class Solution {
  public:
  vector<vector<int>> constructAdj(int V,vector<vector<int>> &edges){
      vector<vector<int>> adj(V);
      for(auto &it:edges){
          adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
      }
      return adj;
  }
  void findPoints(vector<vector<int>>&adj,int u,vector<int>&visited,
  vector<int>&disc,vector<int>&low,int &time,int parent,vector<int>&isAp){
      visited[u]=1;
      disc[u]=low[u]=++time;
      int children=0;
      for(int v:adj[u]){
          if(!visited[v]){
              children++;
              findPoints(adj,v,visited,disc,low,time,u,isAp);
              low[u]=min(low[u],low[v]);
              if(parent!=-1 && low[v]>=disc[u]){
                  isAp[u]=1;
              }
          }
          else if(v!=parent){
              low[u]=min(low[u],disc[v]);
          }
      }
      if(parent==-1 && children>1){
          isAp[u]=1;
      }
  }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj=constructAdj(V,edges);
        vector<int> disc(V,0),low(V,0),visited(V,0),isAp(V,0);
        int time=0;
        for(int u=0;u<V;u++){
            if(!visited[u]){
                findPoints(adj,u,visited,disc,low,time,-1,isAp);
            }
        }
        vector<int> result;
        for(int u=0;u<V;u++){
            if(isAp[u])
            result.push_back(u);
        }
        return result.empty() ? vector<int>{-1}:result;
    }
};
