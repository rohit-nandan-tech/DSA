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
    bool f=1;
    ListNode *ptr;
    void check(ListNode *copy){
        if(copy==nullptr) return;
        check(copy->next);
        // cout<<ptr->val<<" "<<copy->val<<endl;
        if(ptr->val!=copy->val){
            f=0;
            return ;
            // cout<<ptr->val<<" "<<
        }
        ptr=ptr->next;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ptr=head;
        check(head);
        
        return f;
    }
};