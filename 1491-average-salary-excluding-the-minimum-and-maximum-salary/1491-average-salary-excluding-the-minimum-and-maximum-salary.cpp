class Solution {
    public: double average(vector<int> salary) {
        // Sort the salary array in ascending order
        sort(salary.begin(), salary.end());
        
        // Compute the sum of all salaries
        double sum = 0;
        for(int i = 0; i < salary.size(); i++) {
            sum = sum + salary[i];
        }
        
        // Return the average of salaries excluding the minimum and maximum
        // by subtracting the two extreme salaries from the sum and dividing
        // by the count of salaries minus two
        return (sum - (salary[0] + salary[salary.size() - 1])) / (salary.size() - 2);
    }
};