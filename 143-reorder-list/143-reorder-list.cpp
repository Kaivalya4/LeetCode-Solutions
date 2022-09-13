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
        if(head == NULL && head -> next == NULL)
            return ;
        map<ListNode* , bool> m;
        stack<ListNode*> stk;
        
        ListNode* ptr = head;
        while(ptr){
            stk.push(ptr);
            ptr = ptr -> next;
        }
        
        int turn = 1;
        ptr = head;
        ListNode* ptr1 = head-> next;
        m[head]= true;
        while(true){
            if(turn){
                cout << 1 << endl;
                if(m[stk.top()])
                {
                    break;
                }
                ptr -> next = stk.top();
                m[stk.top()] = true;
                ptr = ptr -> next;
                stk.pop();
                turn ^=1;
            } else{
                if(m[ptr1]){
                    break;
                }
                ptr -> next = ptr1 ;
                m[ptr1] = true;
                ptr1 = ptr1 -> next;
                ptr = ptr -> next;
                turn ^=1;
            }
        }
        
        ptr -> next = NULL;
    }
};