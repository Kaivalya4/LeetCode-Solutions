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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        vector<ListNode*> vec;
        ListNode* ptr = head;
        while(ptr){
            vec.push_back(ptr);
            ptr = ptr -> next;
        }
        int n =vec.size();
        int curr = vec.size()-1;
        k = k % n;
        for(int i=0;i<k;i++){
            int next = (curr + 1)%n;
            vec[curr] -> next = vec[next];
            curr--;
            if(curr <0)
                curr = n-1;
            vec[curr] -> next = NULL;
        }
        return vec[ (curr+1)%n];
    }
};