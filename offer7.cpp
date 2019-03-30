//重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，假设不含重复数字，重建二叉树并输出头节点
#include <iostream>
#include<stack>
using namespace std;
#include <exception>
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pleft;
    BinaryTreeNode* m_pright;
};

BinaryTreeNode* ConstructCore
(
    int*  ,int*,
    int*  ,int*
);

BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
    if(preorder == nullptr || inorder == nullptr || length<0)
        {
            cout<<"invaid input"<<endl;
            return nullptr;
        }

    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);

}

BinaryTreeNode* ConstructCore
(
    int* startPreorder,int* endPreorder,
    int* startInorder, int* endInorder
)
{
    int rootValue=startPreorder[0];
    BinaryTreeNode* root=new BinaryTreeNode();
    root->m_nValue=rootValue;
    root->m_pleft=root->m_pright=nullptr;

    //判断下一个节点的异常
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder==*startInorder )
        {
            return root;
        }
        else
            return nullptr;


    }
    int* rootInorder=startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue )
    {
        rootInorder++;
    }

    if(rootInorder == endInorder && *rootInorder != rootValue )
        {
            cout<<"invalid input of one"<<endl;
            return nullptr;
        }

    int  leftLength=rootInorder-startInorder;
    int* leftEndPreorder=startPreorder+leftLength;
    //以下为递归算法
    if(leftLength>0)
    {
        root->m_pleft=ConstructCore(startPreorder+1,leftEndPreorder,startInorder,rootInorder-1);
    }

    if(endPreorder-startPreorder>leftLength)
    {
        root->m_pright=ConstructCore(leftEndPreorder+1,endPreorder,rootInorder+1,endInorder);
    }

    return root;

}

//简单递归前序遍历
void Preorder_Recurrently(BinaryTreeNode* root)
{
    if(root != nullptr)
    {
        cout<<root->m_nValue<<endl;
        Preorder_Recurrently(root->m_pleft);
        Preorder_Recurrently(root->m_pright);
    }
}

int main(int argc,char* argv[])
{
    int pre[8]={10,6,4,8,14,12,16};
    int in[8]={4,6,8,10,12,14,16};
    BinaryTreeNode* root;
    root=Construct(pre,in,7);
    cout<<root->m_nValue<<endl;
    Preorder_Recurrently(root);
    //test：{1，2，4，7，3，5，6，8}，{4，7，2，1，5，3，8，6}

}
