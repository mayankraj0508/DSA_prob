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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(int i =0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        while(head && s.find(head->val)!=s.end()){
            head = head->next;
        }
        ListNode*temp1= head;
        ListNode*temp2 = temp1->next;
        while(temp1){
            while(temp2 && s.find(temp2->val)!=s.end()){
                temp2 = temp2->next;
            }
            temp1->next = temp2;
            temp1 = temp2;
            if(temp2)
            temp2 = temp2->next;
        }
        return head;
        
        
    }
};