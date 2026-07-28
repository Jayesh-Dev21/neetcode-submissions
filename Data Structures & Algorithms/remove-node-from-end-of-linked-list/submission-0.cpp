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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * nxt = head;
        ListNode * curr = head;
        int size{0};
        while(nxt){
            size++;
            nxt = nxt->next;
        }
        // Remove head
        if (n == size) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        n = size - n; // size - n + 1
        while(--n){
            curr = curr->next;
        }
        ListNode * ToDel = curr->next;
        curr->next = curr->next->next;
        delete ToDel;
        return head;
    }
};