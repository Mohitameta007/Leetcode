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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        if(head->next->next == nullptr){
            head->next = nullptr;
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }

        temp = head;
        int mid = count/2;
        while(mid-1 > 0)
        {
            temp = temp->next;
            mid--;
        }
        ListNode* next = temp->next;
        temp->next = next->next;
        delete next;
        return head;
    }
};