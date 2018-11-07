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
 
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* result = NULL;
        ListNode* cur = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            int val = 0;
            if (l1->val > l2->val)
            {
                val = l2->val;
                l2 = l2->next;
            }
            else
            {
                val = l1->val;
                l1 = l1->next;
            }
            ListNode* node = new ListNode(val);
            if (result == NULL)
            {
                result = node;
                cur = node;
            }
            else
            {
                cur->next = node;
                cur = node;
            }
        }
        while(l1 != NULL)
        {
            ListNode* node = new ListNode(l1->val);
            cur->next = node;
            cur = node;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            ListNode* node = new ListNode(l2->val);
            cur->next = node;
            cur = node;
            l2 = l2->next;
        }
        return result;
    }
};

void DumpListNode(ListNode* header)
{
    ListNode* p = header;
    while (p != NULL)
    {
        cout << p->val << " " ;
        p = p->next;
    }
    cout << endl;
}

void InitListNode(ListNode** header,int A[],int length)
{
    ListNode* p = *header;
    for(int i = 0; i < length; i++)
    {
        ListNode* node = new ListNode(A[i]);
        if (p == NULL)
        {
            *header = node;
        }
        else
        {
            p->next = node;
        }
        p = node;
        
    }
}


int main(int argc,char* argv[])
{
    int a[] = {2,4,9};
    int b[] = {1,3,5,10};
    ListNode* La = NULL;
    ListNode* Lb = NULL;
    InitListNode(&La,a,sizeof(a)/sizeof(a[0]));
    InitListNode(&Lb,b,sizeof(b)/sizeof(b[0]));
    
    Solution sln;
    ListNode* c = sln.mergeTwoLists(La,Lb);
    DumpListNode(c);
    return 0;
}