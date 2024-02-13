class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m1;
        for(char i : p){
            m1[i]++;
        }
        int count = m1.size();
        int i = 0, j = 0;
        vector<int> ans;
        
        while(j < s.size()){
            if(m1.find(s[j]) != m1.end()){
                m1[s[j]]--;
                if(m1[s[j]] == 0){
                  count--;  
                }
            }
            if((j-i+1) < p.size()){
                j++;
            }
            else if((j-i+1) == p.size()){
                if(count == 0){
                    ans.push_back(i);
                }
                if(m1.find(s[i]) != m1.end()){
                    m1[s[i]]++;
                    if(m1[s[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};