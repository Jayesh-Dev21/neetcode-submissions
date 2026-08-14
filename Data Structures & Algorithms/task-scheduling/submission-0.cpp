class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        int maxf = *max_element(count.begin(), count.end());
        int mx{0};
        for(int i : count) if(i==maxf) mx++;
        int T = (maxf-1)*(n+1) + mx;
        return max(T, static_cast<int>(tasks.size()));
    }
};
