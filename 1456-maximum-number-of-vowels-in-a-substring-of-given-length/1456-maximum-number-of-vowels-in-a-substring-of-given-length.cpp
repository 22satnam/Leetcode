class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;

        return false;
    }
    int maxVowels(string s, int k) {
        int i=0,j=0;
        int count=0;
        int mx=0;
        while(j<s.length())
        {
            if(isvowel(s[j]))
            {
                count++;
            }
            if((j-i+1)>=k)
            {
                cout<<count;
               mx=max(mx,count);
               if(isvowel(s[i]))
               {
                   count--;
               }
               i++;
            }
            j++;
        }
        return mx;
        
    }
};