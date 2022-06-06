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
    
    int length(ListNode *head){
        int len = 0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int len1 = length(head1);
        int len2 = length(head2);
        
        if(len1>len2){
            while(len1>len2){
                head1 = head1->next;
                len1--;
            }            
        }
        else if(len2>len1){
            while(len1<len2){
                head2 = head2->next;
                len2--;
            }             
        }            
        
        while(head1!=NULL){
            if(head1==head2){
                return head1;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return NULL;
    }
};