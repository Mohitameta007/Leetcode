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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listsize = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            temp = temp->next;
            listsize++;
        }

        listsize = listsize-n;
        if(listsize == 0 )
        {
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }

        temp = head;
        while(listsize-1 > 0)
        {
            temp = temp->next;
            listsize--;
        }
        ListNode* next = temp->next;
        
        if(next->next == nullptr)
        {
            temp->next = nullptr;
            delete next;
            return head;
        }
        else{
            temp->next = next->next;
            delete next;
            return head;
        }

        return head;
    }
};