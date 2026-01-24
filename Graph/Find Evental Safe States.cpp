There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
      int n=graph.size();
       vector<int>adj[n];
       vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            int m=graph[i].size();
            for(int j=0;j<m;j++){
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
  vector<int>ans;
  queue<int>q;

  for(int i=0;i<n;i++){
    if(indegree[i]==0)q.push(i);
  } 

   while(!q.empty()){
    int node=q.front();
    q.pop();
    ans.push_back(node);
    for(auto it:adj[node]){
        indegree[it]--;
        if(indegree[it]==0)q.push(it);
    }
    }
    sort(ans.begin(),ans.end());
    return ans;
    }
};
