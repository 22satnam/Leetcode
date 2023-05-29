class Solution {
public:
    int addDigits(int num) {
        long long sum=0;
        while(num>=10)
        { int temp=num;
            sum=0;
            while(temp!=0)
            {
                int x=temp%10;
                sum+=x;
                temp=temp/10;
            }
            num=sum;
        }
        return num;
    }
};
