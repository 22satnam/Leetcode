class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxi = 0, mini = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < mini) mini = prices[i];
            else if (prices[i] > mini) 
                maxi = max(prices[i] - mini, maxi);
        }
        return maxi;
    }
    
};