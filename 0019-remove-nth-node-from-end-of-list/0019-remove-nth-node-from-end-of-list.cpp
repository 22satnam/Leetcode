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
class Solution {   //bruteforce
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0;
        int res = 0;
        while(temp != NULL){   //counting the size of ll
            count++;
            temp = temp -> next;
        }
        if(count == n){
            ListNode* newhead = head -> next;   // edge case if n ==  size of ll
            delete(head);
            return newhead;
        }
        temp = head;
        res = count - n;
        while(temp != NULL){
            res--;               // traversing to prev node of the deleting nth node
            
            if(res == 0){
                break;
            }
            temp = temp -> next;
            
        }
        ListNode* deleteNode = temp -> next;
        temp -> next = temp -> next -> next;// making conn bw prev of deleting node and next of deleting node
        delete(deleteNode);
        
        return head;
    }
};