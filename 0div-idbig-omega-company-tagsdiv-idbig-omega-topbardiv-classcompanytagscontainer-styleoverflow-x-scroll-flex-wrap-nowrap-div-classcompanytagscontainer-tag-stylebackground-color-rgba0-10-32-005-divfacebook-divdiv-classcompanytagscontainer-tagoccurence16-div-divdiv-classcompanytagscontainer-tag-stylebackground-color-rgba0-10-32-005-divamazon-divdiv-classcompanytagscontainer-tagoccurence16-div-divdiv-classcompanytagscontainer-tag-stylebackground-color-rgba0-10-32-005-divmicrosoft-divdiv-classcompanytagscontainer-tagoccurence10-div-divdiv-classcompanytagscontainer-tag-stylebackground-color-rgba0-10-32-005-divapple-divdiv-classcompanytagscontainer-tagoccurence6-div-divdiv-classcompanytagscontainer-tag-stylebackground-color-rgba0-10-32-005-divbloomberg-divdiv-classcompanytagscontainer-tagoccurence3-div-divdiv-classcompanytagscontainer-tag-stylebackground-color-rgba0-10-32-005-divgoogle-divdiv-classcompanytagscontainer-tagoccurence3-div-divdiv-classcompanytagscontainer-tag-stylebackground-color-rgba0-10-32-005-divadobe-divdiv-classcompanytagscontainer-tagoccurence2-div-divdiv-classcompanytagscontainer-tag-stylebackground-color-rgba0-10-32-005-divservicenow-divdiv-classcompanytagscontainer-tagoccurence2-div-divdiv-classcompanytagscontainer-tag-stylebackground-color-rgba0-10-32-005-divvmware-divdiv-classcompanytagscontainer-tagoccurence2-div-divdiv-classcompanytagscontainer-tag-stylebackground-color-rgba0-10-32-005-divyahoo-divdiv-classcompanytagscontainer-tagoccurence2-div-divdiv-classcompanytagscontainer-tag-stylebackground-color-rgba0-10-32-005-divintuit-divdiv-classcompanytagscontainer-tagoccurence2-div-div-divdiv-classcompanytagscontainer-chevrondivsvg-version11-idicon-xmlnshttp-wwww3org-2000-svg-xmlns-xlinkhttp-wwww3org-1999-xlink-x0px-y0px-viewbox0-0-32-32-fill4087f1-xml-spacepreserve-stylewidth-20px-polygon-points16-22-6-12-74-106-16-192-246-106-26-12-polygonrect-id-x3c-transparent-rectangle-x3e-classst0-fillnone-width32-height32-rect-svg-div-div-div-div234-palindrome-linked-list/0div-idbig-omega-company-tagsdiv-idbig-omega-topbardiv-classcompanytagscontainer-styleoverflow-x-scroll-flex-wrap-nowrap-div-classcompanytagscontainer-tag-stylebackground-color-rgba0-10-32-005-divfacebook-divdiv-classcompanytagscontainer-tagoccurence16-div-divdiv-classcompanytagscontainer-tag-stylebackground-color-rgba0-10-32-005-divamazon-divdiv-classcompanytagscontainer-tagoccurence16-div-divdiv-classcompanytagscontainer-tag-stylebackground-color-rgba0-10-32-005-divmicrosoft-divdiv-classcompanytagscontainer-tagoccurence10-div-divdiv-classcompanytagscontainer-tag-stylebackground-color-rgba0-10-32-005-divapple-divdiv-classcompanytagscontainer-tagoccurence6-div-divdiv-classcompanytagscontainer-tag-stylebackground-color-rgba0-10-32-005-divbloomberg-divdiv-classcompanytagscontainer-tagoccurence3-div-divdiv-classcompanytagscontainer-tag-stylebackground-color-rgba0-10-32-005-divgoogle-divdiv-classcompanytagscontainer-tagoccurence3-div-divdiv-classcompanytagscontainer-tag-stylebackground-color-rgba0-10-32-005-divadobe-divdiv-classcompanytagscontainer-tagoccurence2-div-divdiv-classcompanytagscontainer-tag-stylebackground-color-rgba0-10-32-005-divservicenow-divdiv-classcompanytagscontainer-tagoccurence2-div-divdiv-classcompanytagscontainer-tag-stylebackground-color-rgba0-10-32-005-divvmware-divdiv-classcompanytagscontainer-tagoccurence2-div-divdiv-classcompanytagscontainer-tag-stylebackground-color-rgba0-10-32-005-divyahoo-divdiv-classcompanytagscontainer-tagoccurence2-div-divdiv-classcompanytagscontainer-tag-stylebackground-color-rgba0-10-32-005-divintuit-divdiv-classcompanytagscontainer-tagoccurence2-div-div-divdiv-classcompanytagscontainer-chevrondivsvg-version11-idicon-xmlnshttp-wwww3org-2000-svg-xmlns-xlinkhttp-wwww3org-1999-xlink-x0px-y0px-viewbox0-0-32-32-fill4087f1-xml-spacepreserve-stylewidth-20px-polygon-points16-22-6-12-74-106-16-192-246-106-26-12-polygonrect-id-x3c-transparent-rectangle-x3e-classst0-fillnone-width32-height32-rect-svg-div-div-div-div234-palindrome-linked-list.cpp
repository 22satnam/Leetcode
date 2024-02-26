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
    
    ListNode* doreverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        
        while(curr != NULL){
            forw  = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
     ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast-> next -> next;
            slow = slow -> next;
        }
        if(fast)slow = slow -> next;
        slow = doreverse(slow);
        
   
//         while(slow != NULL && (slow.val == head.val)){
//             head = head-> next;
//             slow = slow -> next;
            
//         }
//         return slow == NULL;     
        
//     }
         fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;

    }
    
    
};