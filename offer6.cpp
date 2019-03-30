//从尾到头打印链表
#include <iostream>
#include<stack>
using namespace std;
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

void PrintList(ListNode* pHead)
{
    if(pHead == nullptr)
    {
        cout<<"no record"<<endl;
        return;
    }
    else
    {
        ListNode* pNode =pHead;//若const变量赋值给非const变量，需要显式转换
        while(pNode != nullptr)
        {
            cout<<pNode->m_nValue<<endl;
            pNode=pNode->m_pNext;
        }
    }
}

void RemoveNode(ListNode** pHead,int value)//删除所有符合输入值的节点
{
    if(pHead == nullptr||*pHead == nullptr)
        return;
    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted=*pHead;
        *pHead=(*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode=*pHead;
        while(pNode->m_pNext != nullptr )
        {

            if(pNode->m_pNext->m_nValue == value)
                {
                        pToBeDeleted=pNode->m_pNext;
                        pNode->m_pNext=pNode->m_pNext->m_pNext;
                        delete pToBeDeleted;
                        pToBeDeleted=nullptr;
                }
            else
                pNode=pNode->m_pNext;
        }

    }
}

//从尾到头打印链表数据
//利用栈模板存储链表节点地址
void PrintListReversingly_Iteratively(ListNode *pHead)
{
    stack<ListNode*>nodes;
    ListNode* pNode=pHead;
    while(pNode!=nullptr)
    {
        nodes.push(pNode);
        pNode=pNode->m_pNext;
    }
    while(!nodes.empty())
    {

        pNode=nodes.top();
        cout<<pNode->m_nValue;
        nodes.pop();

    }
}

//使用递归打印
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

int main(int argc,char* argv[])
{
    ListNode*pHead = nullptr;
    AddToTail(&pHead,5);
    AddToTail(&pHead,8);
    AddToTail(&pHead,8);
    //PrintList(pHead);
    //PrintListReversingly_Iteratively(pHead);
    PrintListReversingly_Recurrently(pHead);

}
