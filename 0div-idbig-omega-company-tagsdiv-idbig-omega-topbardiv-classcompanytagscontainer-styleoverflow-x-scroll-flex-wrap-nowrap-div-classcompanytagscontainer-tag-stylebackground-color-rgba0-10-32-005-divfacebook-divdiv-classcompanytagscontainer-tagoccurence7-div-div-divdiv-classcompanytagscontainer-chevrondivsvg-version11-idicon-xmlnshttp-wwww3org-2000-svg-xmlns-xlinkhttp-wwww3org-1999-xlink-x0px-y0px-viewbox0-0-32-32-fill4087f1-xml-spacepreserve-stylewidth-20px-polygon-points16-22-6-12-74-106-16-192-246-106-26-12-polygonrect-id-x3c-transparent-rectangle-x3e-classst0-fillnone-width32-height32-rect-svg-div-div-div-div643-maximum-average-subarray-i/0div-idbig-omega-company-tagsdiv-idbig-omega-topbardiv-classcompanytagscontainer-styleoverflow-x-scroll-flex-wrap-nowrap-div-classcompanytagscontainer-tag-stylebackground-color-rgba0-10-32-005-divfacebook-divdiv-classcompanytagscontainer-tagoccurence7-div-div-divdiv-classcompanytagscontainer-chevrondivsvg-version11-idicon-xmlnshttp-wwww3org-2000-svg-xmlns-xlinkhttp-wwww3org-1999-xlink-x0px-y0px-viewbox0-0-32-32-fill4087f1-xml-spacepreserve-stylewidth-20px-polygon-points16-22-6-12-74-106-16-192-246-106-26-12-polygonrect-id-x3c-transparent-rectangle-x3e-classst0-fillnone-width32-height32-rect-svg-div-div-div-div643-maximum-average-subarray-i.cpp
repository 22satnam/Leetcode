class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int N = nums.size();
         double sum = 0, maxsum = INT_MIN;
        int i = 0, j = 0;
        while(j < N){
            sum = sum + nums[j];
            if((j-i+1) != k){
                j++;
            }
            else if((j-i+1) == k){
                maxsum = max(sum,maxsum);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        
        return maxsum/k;
    }
};