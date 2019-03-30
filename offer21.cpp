//调整数组顺序使得奇数位于偶数前面
//常规方法：遍历偶数+向前移动+末尾放置偶数。时间复杂度O（n）
//特殊算法：设置两个指针
#include <iostream>
using namespace std;
#include <cstring>

void ReorderOddEven(int* pData ,int length)
{
    if(pData == nullptr || length < 0 )
        return;
    int* pHead = pData;
    int* pEnd = pData+length-1;

    while(pHead < pEnd)
    {
        while((*pHead) %2 != 0 && pHead < pEnd)
            pHead++;
        while((*pEnd) %2 == 0 && pHead < pEnd)
            pEnd--;
        if(pHead < pEnd)
        {
            int temp = *pHead;
            *pHead = *pEnd;
            *pEnd = temp;
        }
    }
    cout<<"end"<<endl;
}


int main()
{
    int a[7]={1,3,4,5,3,1,3};
    ReorderOddEven(a ,7);
    for(int i=0;i<7;i++)
        cout<<a[i]<<endl;
}
