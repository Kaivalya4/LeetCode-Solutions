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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* second = head-> next;
        head = second;
        while(true){
            ListNode* temp = second -> next;
            first ->next = second -> next;
            second -> next = first;
            if(prev == NULL)
                prev = first;
            else{
                prev -> next = second;
                prev = first;
            }
            if(temp == NULL || temp -> next == NULL){
                break;
            }
            first = temp;
            second = temp -> next;
        }
        return head;
    }
};