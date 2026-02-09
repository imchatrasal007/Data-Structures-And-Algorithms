Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.
A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:
All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set
class Solution {
public:
   bool isCheck(int start,int V,vector<int>adj[],int color[])
   {
       queue<int> q;
       q.push(start);
       color[start]=0;
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           for(auto it:adj[node])
           {
               if(color[it]==-1)
               {
                   color[it]=!color[node];
                 q.push(it);   
               }
               else if(color[it]==color[node])
               {
                   return false;
               }
           }
       }
       return true;
   }
	bool isBipartite(int V, vector<int>adj[])
	{
	    int color[V];
	    for(int i=0;i<V;i++)
	    color[i]=-1;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)
	        {
	           if(isCheck(i,V,adj,color)==false)
	           return false;
	        }
	    }
	    return true;
	}
};
