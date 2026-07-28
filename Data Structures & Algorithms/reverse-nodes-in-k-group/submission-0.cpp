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
private: 
    ListNode * getkth(ListNode* curr, int k){
        while(curr && k>0){
            k--;
            curr = curr->next;
        }
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* Res = new ListNode(0, head);
        ListNode* Gprev = Res;
        while(true){
            ListNode* kth = getkth(Gprev, k);
            if(!kth) break;
            ListNode* Gnext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = Gprev->next;
            while(curr != Gnext){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* tmp = Gprev->next;
            Gprev->next = kth;
            Gprev = tmp;
        }
        return Res->next;
    }
};
