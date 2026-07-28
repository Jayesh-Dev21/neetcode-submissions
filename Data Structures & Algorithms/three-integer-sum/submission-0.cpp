class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        int s = n.size();
        sort(n.begin(), n.end());
        vector<vector<int>> res;
        for(int i{0}; i<s; i++){
            if(i>0 && n[i]==n[i-1]) continue;
            int l = i+1;
            int r =s-1;
            while(l<r){
                int sum = n[i] + n[l] + n[r];
                if(sum>0) r--;else if(sum<0) l++; else{
                    res.push_back({n[i], n[l], n[r]});
                    l++; r--;
                    while(l<r && n[l]==n[l-1]) l++;
                    while(l<r && n[r]==n[r+1]) r--;
                }

            }
        }
        return res;
    }
};
