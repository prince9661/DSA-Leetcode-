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
    ListNode* oddEvenList(ListNode* head) {
        if(head== nullptr)return head;
        ListNode * odd = new ListNode(0);
        ListNode * temp1= odd;
        ListNode * even = new ListNode(0);
        ListNode * temp2 = even;
        int isOdd = true;
        while(head!= nullptr){
            if(isOdd){
                odd->next = head;
                head= head->next;
                odd= odd->next;
                isOdd = false;
            }else{
                even->next = head;
                head = head ->next;
                even = even->next;
                isOdd = true;
            }
        }
        even->next = nullptr;
        odd->next = temp2->next;
        return temp1 ->next;
    }
};