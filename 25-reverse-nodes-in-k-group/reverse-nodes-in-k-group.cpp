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
    ListNode* reverse(ListNode* head) {

        if(head==NULL || head->next==NULL)return head;
        ListNode *prev=nullptr;
        ListNode *curr=head;
        while(curr!=nullptr){
            ListNode * temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev= dummy;
        while(true){
            ListNode* curr=prev;
            ListNode* start=prev->next;
            for(int i=0;i<k&&curr!=nullptr;i++){
                curr=curr->next;
            }
            if(curr==nullptr)break ;
            ListNode* end=curr->next;
            curr->next=nullptr;
            prev->next=reverse(start);
            start->next=end;
            prev=start;

        }
        return dummy->next;
    }
};