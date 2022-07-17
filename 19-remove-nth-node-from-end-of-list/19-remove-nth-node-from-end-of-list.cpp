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
        int ctr =0;
        ListNode* ptr = head;
        while(ptr != NULL){
            ctr++;
            ptr = ptr -> next;
        }
        ptr = head;
        n = ctr - n;
        ctr =0;
        if(n == 0){
            head = head -> next;
            delete ptr;
            return head;
        }
        ListNode* prev = NULL;
        while(ctr<n){
            prev = ptr;
            ptr = ptr -> next;
            ctr++;
        }
        prev -> next = ptr -> next;
        delete ptr;
        return head;
    }
};