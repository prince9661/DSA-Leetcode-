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
        if(head==nullptr ||head->next==nullptr|| k==0)return head;
        ListNode* temp=head;

        int n=0;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        k=k%n;
        if(k==0)return head;

        int x = n-k;
        temp = head;
        while(x>1){
            temp = temp->next;
            x--;
        }
        ListNode * sec = temp->next;
        temp->next = nullptr;
        temp = sec;
        while(sec->next!=nullptr){
            sec= sec->next;
        }
        sec->next =head;
        return temp;
        

    }
};