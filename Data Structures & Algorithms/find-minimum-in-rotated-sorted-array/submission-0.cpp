class Solution {
public:
    int findMin(vector<int>& nums) {
        int T = nums[0];
        int n = nums.size()-1;
        int l = 0,  r = n;
        while(l<=r){
            if(nums[l]<nums[r]) T = min(nums[l], T);
            int m = l + (r-l)/2;
            if(nums[m]>T) l = m+1;
            else r = m-1;
        }
        return T;
    }
};