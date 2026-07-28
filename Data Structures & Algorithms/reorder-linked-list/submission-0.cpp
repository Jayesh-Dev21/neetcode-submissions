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
    void reorderList(ListNode* head) {
        ListNode * f = head;
        ListNode * s = head;
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        // s is the mid; we can treat it as the head and reverse the list
        ListNode * second = s->next;
        ListNode * prev = s->next = nullptr;
        while(second){
            ListNode * temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        } 

        ListNode* first = head;
        second = prev;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};