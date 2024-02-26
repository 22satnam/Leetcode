/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *Fast = head;
      ListNode *Slow = head;
        
        while(Fast != NULL && Fast-> next != NULL ){
            Fast = Fast->next->next;
            Slow = Slow->next;
            if(Fast == Slow){
            return true;
        }
        }
        
        return false;
    }
};