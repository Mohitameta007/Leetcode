/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* head1 = headA;
        ListNode* head2 = headB;
        int len1 = 0;
        int len2 = 0;

        while(head1 != nullptr || head2 != nullptr)
        {
            if(head1 != nullptr)
            {
                len1++;
                head1 = head1->next;
            }
            if(head2 != nullptr)
            {
                len2++;
                head2 = head2->next;
            }
        }

        head1 = headA;
        head2 = headB;
        int gap = abs(len1-len2);

        if(len1 < len2)
        {
            while(gap > 0)
            {
                head2 = head2->next;
                gap--;
            } 
        }
        else{
            while(gap > 0)
            {
                head1 = head1->next;
                gap--;
            } 
        }

        while(head1 != nullptr && head2 != nullptr)
        {
            if(head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }

        return nullptr;

    }
};