#ifndef _LIB_H_
#define _LIB_H_

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void AddToTail(ListNode** pHead,int value);
void PrintList(ListNode* pHead);
void RemoveNode(ListNode** pHead,int value);//删除所有符合输入值的节点
void PrintListReversingly_Iteratively(ListNode *pHead);
void PrintListReversingly_Recurrently(ListNode* pHead);

#endif
