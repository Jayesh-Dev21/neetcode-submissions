/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <ListNode*>nodes;
        for(auto node: lists){
            while(node){
                nodes.push_back(node);
                node = node->next;
            }
        }
        sort(nodes.begin(), nodes.end(), [](const ListNode* a, const ListNode* b) { return a->val < b->val; });
        ListNode* Res = new ListNode(0);
        ListNode* curr = Res;
        for(auto node : nodes){
            curr->next = node;
            curr = curr->next;
        }
        return Res->next;
    }
};
