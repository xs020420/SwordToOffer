//树的下一个节点
//给定一颗二叉树和其中一个节点，找出中序遍历序列的下一个节点（有指向父节点的指针）
#include <iostream>
#include<stack>
using namespace std;
#include <exception>
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;
    BinaryTreeNode* pNext=nullptr;
    if(pNode->m_pRight != nullptr)
    {
        if(pNode->m_pRight->m_pLeft = nullptr)
        {
            return pNode->m_pRight;
        }
        else
        {
            pNext=pNode->m_pRight;
            while(pNext->m_pLeft!=nullptr)
            {
                pNext=pNext->m_pLeft;
            }
        return pNext;
        }
    }

    else if(pNode->m_pParent != nullptr)
    {
        if(pNode->m_pParent->m_pLeft == pNode)
            return pNode->m_pParent;
        BinaryTreeNode* pCurrent=pNode;
        BinaryTreeNode* pParent=pNode->m_pParent;
        while(pParent->m_pRight ==pCurrent)
        {
            pCurrent=pParent;
            pParent=pParent->m_pParent;

        }

        pNext = pParent;

        return pNext;
    }

}

// ==================== 辅助代码用来构建二叉树 ====================

BinaryTreeNode* CreateBinaryTreeNode(int value)

{

    BinaryTreeNode* pNode = new BinaryTreeNode();

    pNode->m_nValue = value;

    pNode->m_pLeft = nullptr;

    pNode->m_pRight = nullptr;

    pNode->m_pParent = nullptr;



    return pNode;

}



void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)

{

    if(pParent != nullptr)

    {

        pParent->m_pLeft = pLeft;

        pParent->m_pRight = pRight;



        if(pLeft != nullptr)

            pLeft->m_pParent = pParent;

        if(pRight != nullptr)

            pRight->m_pParent = pParent;

    }

}


void Preorder_Recurrently(BinaryTreeNode* root)
{
    if(root != nullptr)
    {
        cout<<root->m_nValue<<endl;
        Preorder_Recurrently(root->m_pLeft);
        Preorder_Recurrently(root->m_pRight);
    }
}


int main()
{
    //简单构建带有父指针的二叉树
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    //Preorder_Recurrently(pNode8);//前序遍历

    BinaryTreeNode* get=GetNext(pNode5);

    cout<<get->m_nValue<<endl;

    return 0;
}
