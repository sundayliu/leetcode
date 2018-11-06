#include <iostream>
using namespace std;

/* singly-linked list */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* result = NULL;
        ListNode* cur = NULL;
        int cflag = 0;
        while(l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + cflag;
            int remainder = sum % 10;
            cflag = sum / 10;
            
            ListNode* node = new ListNode(remainder);
            if (cur == NULL)
            {
                result = node;
            }
            else
            {
                cur->next = node;
            }
            cur = node;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL)
        {
            int sum = l1->val + cflag;
            int remainder = sum % 10;
            cflag = sum / 10;
            ListNode* node = new ListNode(remainder);
            cur->next = node;
            cur = node;
            l1 = l1->next;
        }
        
        while (l2 != NULL)
        {
            int sum = l2->val + cflag;
            int remainder = sum % 10;
            cflag = sum / 10;
            ListNode* node = new ListNode(remainder);
            cur->next = node;
            cur = node;
            l2 = l2->next;
        }
        
        if (cflag != 0)
        {
            ListNode* node = new ListNode(cflag);
            cur->next = node;
            cur = node;
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


int main(int argc, char* argv[])
{
    int a[] = {2,4,9};
    int b[] = {5,6,4};
    ListNode* La = NULL;
    ListNode* Lb = NULL;
    InitListNode(&La,a,sizeof(a)/sizeof(a[0]));
    InitListNode(&Lb,b,sizeof(b)/sizeof(b[0]));
    DumpListNode(La);
    DumpListNode(Lb);
    
    Solution sln;
    ListNode* Lc = sln.addTwoNumbers(La,Lb);
    DumpListNode(Lc);
    return 0;
}