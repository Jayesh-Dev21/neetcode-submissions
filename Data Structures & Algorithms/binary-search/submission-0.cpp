class Solution {
public:
    int search(vector<int>& n, int t) {
        int s = n.size();
        int lo = 0;
        int hi = s-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(t==n[mid]){
                return mid;
            }
            else if(t<n[mid]){
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        return -1;
    }
};