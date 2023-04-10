class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        int idx = 0;
        if(s.size() == 0)return true;
        while(idx < s.size()){
            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '['){
                ans.push(s[idx]);
            }
            else if((s[idx] == ')' && !ans.empty() && ans.top() == '(')
                 ||( s[idx] == '}' && !ans.empty() && ans.top() == '{') 
                 ||( s[idx] == ']' && !ans.empty() && ans.top() == '['))
            {
                ans.pop();
            }
            else return false;
            idx++;
        }
        if(ans.empty())return true;
        else return false;
        
    }
};