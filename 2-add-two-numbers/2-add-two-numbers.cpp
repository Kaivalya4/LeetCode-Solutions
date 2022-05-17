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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* ptr = NULL;
        ListNode* start ;
        while(l1 != NULL && l2 != NULL){
            int val = l1->val + l2->val + carry;
            if(val>=10){
                ListNode* newnode = new ListNode;
                newnode -> val = val%10;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                val/=10;
                carry = val;
            }
            else{
                ListNode* newnode = new ListNode;
                newnode -> val = val;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                carry =0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL){
            int val = l1->val  + carry;
            if(val>=10){
                ListNode* newnode = new ListNode;
                newnode -> val = val%10;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                val/=10;
                carry = val;
            }
            else{
                ListNode* newnode = new ListNode;
                newnode -> val = val;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                carry =0;
            }
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            int val =  l2->val + carry;
            if(val>=10){
                ListNode* newnode = new ListNode;
                newnode -> val = val%10;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                val/=10;
                carry = val;
            }
            else{
                ListNode* newnode = new ListNode;
                newnode -> val = val;
                if(ptr == NULL){
                    ptr = newnode;
                    start = ptr;
                }
                else{
                    ptr -> next = newnode;
                    newnode -> next = NULL;
                    ptr = newnode;
                }
                carry =0;
            }
            l2 = l2 -> next;
        }
        if(carry != 0){
            ListNode* newnode = new ListNode;
            newnode -> val = carry;
            ptr -> next = newnode;
        }
        return start;
    }
};