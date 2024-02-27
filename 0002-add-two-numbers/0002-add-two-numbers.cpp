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
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        
        while(t1 != NULL || t2 != NULL){
            
            int sum = carry;
            if(t1)sum += t1->val;
            if(t2)sum += t2->val;    // adding t1+t2
            
            ListNode* newNode = new ListNode(sum % 10);   //storing in newnode
            carry = sum/10;                               //making carry
            
            curr -> next = newNode;
            curr = curr->next;                              // traversing curr
            
            if(t1) t1 = t1 -> next;
            if(t2) t2 = t2 -> next;                         // travesing t1 and t2
                 
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            curr -> next = newNode;                          //edge case
        }
        
        return dummyHead->next;
    }
};