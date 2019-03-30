//在O（1）时间内删除链表节点
//给定 单向链表 头指针 结点指针。编写函数 在O(1)时间内删除该节点。
//一些特殊情况：待删除的节点在尾部；待删除的节点在头部；只有一个节点；
#include <iostream>
using namespace std;
#include <cstring>
#include "lib.h"

void DeletedNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
    if(pListHead == nullptr || pToBeDeleted == nullptr)
        return;
    if(*pListHead == pToBeDeleted && (*pListHead)->m_pNext == nullptr)
    {
        delete pToBeDeleted;
    }

    else if(pToBeDeleted == *pListHead)
    {
        *pListHead=(*pListHead)->m_pNext;
        delete pToBeDeleted;
    }

    else if(pToBeDeleted->m_pNext == nullptr)
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
    }

    else
    {
        pToBeDeleted->m_nValue=pToBeDeleted->m_pNext->m_nValue;
        pToBeDeleted->m_pNext=pToBeDeleted->m_pNext->m_pNext;
        delete pToBeDeleted->m_pNext;
    }
}



int main()
{
    ListNode*pHead = nullptr;
    AddToTail(&pHead,5);
    AddToTail(&pHead,8);
    AddToTail(&pHead,8);
    PrintListReversingly_Iteratively(pHead);

    ListNode* pToBeDeleted=pHead->m_pNext->m_pNext;

    DeletedNode(&pHead,pToBeDeleted) ;
    PrintListReversingly_Iteratively(pHead);
    cout<<"run compeleted"<<endl;
}
