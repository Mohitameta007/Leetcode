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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return {-1 , -1};

        int mindistance = -1;
        int maxdistance = -1;
        bool found = false;
        int mincount = 0;
        int maxcount = 0;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        while(next != nullptr)
        {
            if(found == true)
            {
                mincount++;
                maxcount++;
            } 
            if(prev->val < curr->val && next->val < curr->val || prev->val > curr->val && next->val > curr->val) 
            {
                if(found == true)
                {
                    if(mindistance == -1 && maxdistance == -1)
                    {
                        mindistance = mincount;
                        maxdistance = maxcount;
                    }
                    if(mincount < mindistance) mindistance = mincount;
                    if(maxcount > maxdistance) maxdistance = maxcount;
                    mincount = 0;
                }
                found = true;
            }
            prev = prev->next;
            curr = curr->next;
            next = next->next;
        }

        return {mindistance , maxdistance};
    }
};