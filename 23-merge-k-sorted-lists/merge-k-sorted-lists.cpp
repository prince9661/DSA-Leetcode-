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
    struct compare{
        bool operator()( ListNode * a,ListNode * b){
            return a->val >b->val;

        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        if(lists.size()==0)return nullptr;
        for(int i=0;i<lists.size();i++){
            
            ListNode * temp=lists[i];
            if(temp==nullptr)continue;
            pq.push(temp);
        }
        ListNode * first= new ListNode(-1);
        ListNode * temp= first;
        while(!pq.empty()){
            ListNode * t=pq.top();
            pq.pop();
            if(t->next!=nullptr){
                pq.push(t->next);

            }
            temp->next=t;
            temp=temp->next;
        }
        return first->next;
    }
};