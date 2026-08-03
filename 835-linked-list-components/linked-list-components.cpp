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
    int numComponents(ListNode* head, vector<int>& nums) {
        // unordered_map<int,vector<int>>m;
        // ListNode*temp = head;
        // ListNode*prev = NULL;
        // while(temp){
        //     if(prev){
        //     m[temp->val].push_back(prev->val);
        //     }
        //   if(temp->next){
        //     m[temp->val].push_back(temp->next->val); 
        //   }
        //   prev  = temp;
        //   temp = temp->next;

   
        // }
        int ans  = 0;
        unordered_set<int>visited;
         for(int i = 0; i<nums.size(); i++){
            visited.insert(nums[i]);
         }
       ListNode*temp = head;
       while(temp){
            if(visited.find(temp->val)==visited.end()){
                temp = temp->next;
                continue;
            }

           while(temp && visited.find(temp->val)!=visited.end()){
              temp = temp->next;
          }

          ans++;
       }
       return ans ;
        
        
    }
};