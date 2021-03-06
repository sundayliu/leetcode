#include <iostream>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return NULL;
        int n = lists.size();
        while ( n > 1)
        {
            int k = (n + 1)/2;  // 3->2  4->2
            for(int i = 0; i < n / 2; i++)
            {
                lists[i] = mergeTwoLists(lists[i],lists[i+k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while(l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};

int main(int argc,char* argv[])
{
    return 0;
}