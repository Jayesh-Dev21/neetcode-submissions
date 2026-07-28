class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int>res;
        int s = n.size();
        int l = 0;
        int r = s-1;
        while(l<r){
            int sum = n[l] + n[r];

            if(sum<t){
                l++;
            }
            else if(sum>t) r--;
            else{return {l+1, r+1};}
        }
        return {};
    }
};