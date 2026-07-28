/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *>oTc;
        Node * curr = head;
        while(curr){
            Node * copy = new Node(curr->val);
            oTc[curr] = copy;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node * copy = oTc[curr];
            copy->next = oTc[curr->next];
            copy->random = oTc[curr->random];
            curr = curr->next;
        }
        return oTc[head];
    }
};
