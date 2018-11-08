#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; i++)
        {
            if (cur == NULL) return head;
            cur = cur->next;
        }
        ListNode* new_head = reverse(head,cur);
        head->next = reverseKGroup(cur,k);
        return new_head;
    }
    
    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode* pre = tail;
        while(head != tail)
        {
            ListNode* t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};

int main(int argc,char* argv[])
{
    return 0;
}