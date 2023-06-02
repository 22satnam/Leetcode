class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>&set,int node)
    {
        for(auto it:graph[node])
        {
            if(set[it]==-1)
            {
                set[it]=!set[node];
                if(!dfs(graph,set,it))
                return false;
            }
            else if(set[it]==set[node])
            {
                return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
     int m=graph.size();
     int n=graph[0].size();
     //set a=0, setb=1
     bool ans=true;
     vector<int>set(m,-1);   
     for(int i=0;i<m;i++)
     {
         if(set[i]!=-1)
         {
             continue;

         }
         else
         {
             set[i]=0;
            if(!dfs(graph,set,i))
            {
                return false;
            }

         }
     }
     return ans;
    }
};