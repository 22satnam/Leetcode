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
        ListNode *fast = head;
        int count = n;
        
        while(count != 0 && fast != nullptr){
            fast = fast->next;
            count--;
        }
        
         if(fast == nullptr){
            ListNode* newHead = head -> next;
            delete head;
            return newHead;
        }
        
        ListNode *slow = head;
        
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
       
        ListNode* deleteNode = slow->next;
        slow->next = slow->next->next;
        delete deleteNode;
        
        return head;
        
    }
};