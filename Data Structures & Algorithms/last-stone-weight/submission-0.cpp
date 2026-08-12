class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        if(!stones.size()) return 0;
        for(int s : stones) maxHeap.push(s);

        while(maxHeap.size()>1){
            int x = maxHeap.top(); maxHeap.pop();
            int y = maxHeap.top(); maxHeap.pop();
            if(x!=y) maxHeap.push(abs(x-y)); 
        }
        if(maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};