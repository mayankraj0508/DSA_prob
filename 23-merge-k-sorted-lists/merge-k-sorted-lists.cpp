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
    class cmp{
       public:
        bool operator()(ListNode*a,ListNode*b){
            if(a && b){
            return a->val>b->val;
            }
            //just for maintraing the function signature 
            else{
                return false;
            }
        }

    };
    #define pp pair<int,ListNode*>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i = 0; i<lists.size(); i++){
            ListNode*h = lists[i];
            if(h)
            pq.push({h->val,h});
        }
        ListNode*dummy  = new ListNode(-1);
        ListNode*temp = dummy;;
        while(pq.size()){
            ListNode*p = pq.top().second;
            temp->next  = p;
            temp = temp->next;
            pq.pop();
            if(p->next){
                pq.push({p->next->val,p->next});
            }
            
        }
        return dummy->next;
        

    }
};