class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        int sign = 1;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (s[i] == '(') {
                nums.push(res);
                ops.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += sign * num;
                num = 0;
                res = ops.top() * res + nums.top();
                ops.pop();
                nums.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
