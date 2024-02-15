class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
       vector<int> result;
        priority_queue<pair<int, int>> pq;
        int i = 0, j = 0, size = nums.size();

        while (j < size) {
            // push element and its index as well
            pq.push({nums[j], j});
            if ((j - i + 1) < k) {
                j++;
            } else if ((j - i + 1) == k) {

            // only this step is important, before calculating answer just check if top element of heap is in the window or not
                while (pq.top().second < i) {
                    pq.pop();
                }
                result.push_back(pq.top().first);
                i++;
                j++;
            }
        }

        return result;
    }
};