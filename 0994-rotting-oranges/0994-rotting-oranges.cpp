class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        int count=-1;
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                   q.push({i,j});
                }

                if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        while(!q.empty())
       {
           int sz=q.size();
           while(sz--){
           pair<int,int>temp=q.front();
           q.pop();
           int i=temp.first;
           int j=temp.second;
           if(grid[i][j]==2)
           {
               if(i<grid.size()-1&&grid[i+1][j]==1)
               { 
                   fresh--;
                   grid[i+1][j]=2;
                    q.push({i+1,j});
               }
               if(i>0&&grid[i-1][j]==1)
               {
                   fresh--;
                    grid[i-1][j]=2;
                    q.push({i-1,j});
               }
               if(j>0&&grid[i][j-1]==1)
               {
                   fresh--;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
               }
               if(j<grid[0].size()-1&&grid[i][j+1]==1)
               {
                   fresh--;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
               }
             }
           }
           count++;
           }
           if(fresh>0)
           return -1;
           if(count==-1)
           return 0;
           return count;
        // return -1;
    }
};