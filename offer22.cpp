//输入一个链表，输出链表中倒数第 k 个节点
//方法O（2n）：遍历一遍得到链表大小 n ，再取 第 n+1-k 个
//方法O（n）：定义两个指针，遍历一次
//鲁棒性分析：用户输入是否合法。包括表头指针是否为空，k的范围是否是1~n

#include <iostream>
using namespace std;
#include <cstring>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};


void AddToTail(ListNode** pHead,int value)
{
    ListNode* pNew=new ListNode;
    pNew->m_nValue=value;
    pNew->m_pNext=nullptr;

    if(*pHead == nullptr)
        *pHead=pNew;
    else
    {
        ListNode* pNode =*pHead;
        while(pNode->m_pNext != nullptr)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=pNew;
    }
}

ListNode* FindKthToTail(ListNode* pHead,unsigned int k)
{
    if(pHead == nullptr || k == 0 )
        return nullptr;
    ListNode* pAhead = pHead;
    ListNode* pAfter = pHead;

    for(int i=0;i<k-1;i++)
        {
            if(pAhead->m_pNext != nullptr)
                pAhead=pAhead->m_pNext;
            else
                return nullptr;
        }

    while(pAhead->m_pNext != nullptr)
    {
        pAhead=pAhead->m_pNext;
        pAfter=pAfter->m_pNext;
    }

    return pAfter;
}

void PrintListReversingly_Recurrently(ListNode* pHead)
{
    if( pHead != nullptr)
    {
        if(pHead->m_pNext != nullptr)
        {
            PrintListReversingly_Recurrently(pHead->m_pNext);
        }
        cout<<pHead->m_nValue<<endl;
    }
}

int main()
{
    ListNode head{1,nullptr};//需初始化
    ListNode* pHead = &head;
    AddToTail(&pHead, 1);
    AddToTail(&pHead, 2);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    PrintListReversingly_Recurrently(pHead);
    ListNode* kth=FindKthToTail(pHead,2);
    cout<<kth->m_nValue<<endl;
}
