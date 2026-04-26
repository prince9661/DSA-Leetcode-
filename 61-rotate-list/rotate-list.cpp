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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr ||head->next==nullptr|| k==0)return head;
        ListNode* temp=head;

        int n=0;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        // cout<<n;
        k=k%n;
        if(k==0)return head;
        head=reverse(head);
        ListNode* curr=head;
        for(int i=1;i<k;i++){
            curr=curr->next;
        }
        ListNode* end=curr->next;
        curr->next=nullptr;
        ListNode* rev1=reverse(head);
        ListNode* rev2=reverse(end);
        head->next=rev2;
        return rev1;

    }
};