class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n : nums){
            m[n]++;
        }
        for(int i=0; i< nums.size() ;i++){
            if(m[i]>1){return true;}
        }
        return false;
    }
};