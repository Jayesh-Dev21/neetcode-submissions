class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       long long p{1};
        int o{0};
       for(int i{0}; i<nums.size(); i++){
        if(nums[i] == 0){ o++; continue;}
        p *= nums[i];
       }
       vector <int> small_dick(nums.size(),0);
        if (o > 1) {
            return small_dick;
        }
       for(int i{0}; i<nums.size(); i++){
        if(!o){
            int big_dick = static_cast<int>(p / nums[i]);
            small_dick[i] = big_dick;
        }
        else if(o == 1 && nums[i] == 0){
            small_dick[i] = static_cast<int>(p);
        }
       }
       return small_dick;
    }
};