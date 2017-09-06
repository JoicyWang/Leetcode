class Solution {
public:
    int magicalString(int n) {
        
        if(n<=0) return 0;
        if(n<=3) return 1;
        
        vector<int> nums={1,2,2}; nums.resize(n);
        int i=2, j=3, pre=2,count=1;
        
        while(j<n)
        {
            if(pre==2)
            {
                nums[j++]=1; count++;
                if(nums[i]==2 && j<n)  {   nums[j++]=1; count++;  }
                pre=1;i++;
            }
            else
            {
                nums[j++]=2; 
                if(nums[i]==2 && j<n)  nums[j++]=2;  
                pre=2;i++;
            }
        }
        
        return count;
    }
};