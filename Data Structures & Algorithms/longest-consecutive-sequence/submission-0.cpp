class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        // [0],[3],[7],[2],[5],[8],[4],[6],[0],[1]
        // 0, 0, 1, 2, 3, 4, 5, 6, 7, 8
        int s = n.size();
        sort(n.begin(), n.end());
        // 1 2 3 4 100 200
        int l{1};
        int j{1};
        if(!s){return 0;}
        for(int i{1}; i<s; i++){
            if((n[i]-n[i-1])==1){
                j++;
            }
            else if(n[i]==n[i-1]){continue;}
            else { l = max(j,l); j = 1; }
        }

        return max(j,l);
    }
};