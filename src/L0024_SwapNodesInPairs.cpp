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
    ListNode* swapPairs(ListNode* head) {
        if (head== NULL || head->next == NULL) return head;
        ListNode* t = head->next;
        head->next = swapPairs(head->next->next);
        t->next = head;
        return t;
    }
    
    ListNode* swapPairsNoRecursion(ListNode* head) {
        ListNode* dummy = new ListNode(-1),*pre = dummy;
        dummy->next = head;
        while(pre->next && pre->next->next)
        {
            ListNode* t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};

int main(int argc,char* argv[])
{
    return 0;
}