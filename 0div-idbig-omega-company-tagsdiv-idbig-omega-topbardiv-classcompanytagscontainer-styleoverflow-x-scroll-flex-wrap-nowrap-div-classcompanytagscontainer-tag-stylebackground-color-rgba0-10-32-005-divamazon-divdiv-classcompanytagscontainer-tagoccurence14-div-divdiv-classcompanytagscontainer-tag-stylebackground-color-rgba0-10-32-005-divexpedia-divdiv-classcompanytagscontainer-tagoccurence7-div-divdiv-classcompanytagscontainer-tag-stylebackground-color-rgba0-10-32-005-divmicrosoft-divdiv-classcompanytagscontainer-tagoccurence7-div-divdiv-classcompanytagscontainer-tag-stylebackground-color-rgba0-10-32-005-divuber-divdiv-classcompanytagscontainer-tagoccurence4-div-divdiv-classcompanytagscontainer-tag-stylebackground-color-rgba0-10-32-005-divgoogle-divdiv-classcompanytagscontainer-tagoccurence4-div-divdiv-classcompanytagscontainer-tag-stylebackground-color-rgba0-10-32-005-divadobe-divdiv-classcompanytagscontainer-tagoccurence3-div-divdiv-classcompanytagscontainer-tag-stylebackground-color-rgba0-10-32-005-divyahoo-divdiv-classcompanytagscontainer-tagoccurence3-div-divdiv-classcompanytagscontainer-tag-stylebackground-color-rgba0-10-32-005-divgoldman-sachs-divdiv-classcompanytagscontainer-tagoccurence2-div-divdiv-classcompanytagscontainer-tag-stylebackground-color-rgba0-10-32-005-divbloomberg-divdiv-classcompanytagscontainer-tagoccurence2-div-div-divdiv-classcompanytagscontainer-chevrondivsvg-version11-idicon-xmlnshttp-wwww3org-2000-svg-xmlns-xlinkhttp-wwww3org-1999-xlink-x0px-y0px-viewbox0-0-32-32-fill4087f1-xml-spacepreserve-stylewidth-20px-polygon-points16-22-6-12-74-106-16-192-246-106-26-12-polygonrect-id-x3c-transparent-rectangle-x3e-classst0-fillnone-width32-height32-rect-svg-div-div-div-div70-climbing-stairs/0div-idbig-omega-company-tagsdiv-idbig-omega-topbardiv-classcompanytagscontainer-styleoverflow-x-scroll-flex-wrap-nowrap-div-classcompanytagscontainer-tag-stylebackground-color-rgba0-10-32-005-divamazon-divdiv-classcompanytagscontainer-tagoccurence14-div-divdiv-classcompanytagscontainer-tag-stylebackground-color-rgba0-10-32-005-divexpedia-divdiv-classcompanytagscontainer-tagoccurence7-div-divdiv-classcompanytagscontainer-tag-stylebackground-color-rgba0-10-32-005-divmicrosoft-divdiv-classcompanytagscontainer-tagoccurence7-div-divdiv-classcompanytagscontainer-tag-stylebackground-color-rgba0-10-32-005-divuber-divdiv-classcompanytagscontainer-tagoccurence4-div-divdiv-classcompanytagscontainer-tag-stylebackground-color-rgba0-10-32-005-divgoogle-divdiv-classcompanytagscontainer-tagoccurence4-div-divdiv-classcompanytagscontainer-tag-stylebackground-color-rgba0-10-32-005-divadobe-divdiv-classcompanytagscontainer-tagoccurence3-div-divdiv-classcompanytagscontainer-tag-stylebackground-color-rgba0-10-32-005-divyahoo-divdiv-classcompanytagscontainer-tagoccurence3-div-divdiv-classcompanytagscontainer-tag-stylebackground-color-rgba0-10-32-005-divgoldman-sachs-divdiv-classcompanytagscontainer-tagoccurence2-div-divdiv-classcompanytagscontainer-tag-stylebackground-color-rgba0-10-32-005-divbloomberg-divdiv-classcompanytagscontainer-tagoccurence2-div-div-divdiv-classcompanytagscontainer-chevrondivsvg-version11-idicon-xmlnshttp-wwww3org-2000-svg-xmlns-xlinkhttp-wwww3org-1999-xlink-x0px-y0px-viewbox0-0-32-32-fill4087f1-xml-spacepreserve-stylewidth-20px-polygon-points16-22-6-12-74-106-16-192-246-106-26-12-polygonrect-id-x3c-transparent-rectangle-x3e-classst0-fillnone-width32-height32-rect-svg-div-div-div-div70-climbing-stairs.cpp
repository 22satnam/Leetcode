class Solution {
public:
    int climbStairs(int n) {
       
       if(n <=2)return n;
        
        int prev2 = 1;
        int prev = 2;
        int ans = 0;
        
        for(int i = 2; i < n; i++){
            ans = prev2 + prev;
            prev2 = prev;
            prev = ans;
        }
        return ans;
        
//          vector<int> dp(n+1);
//         dp[0] = 1; dp[1] = 1;
        
//         for(int i = 2; i <= n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
    }
};