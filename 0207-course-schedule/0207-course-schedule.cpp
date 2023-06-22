class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //adj list created
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        // indegree array is created with updated values
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
            indegree[it]++;
        }
      }
        // a queue is created to store nodes having indegree 0
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            //node is toposort so remove it from indegree
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
            
        }
        if(topo.size() == numCourses)return true;
        else return false;
        
    }
};