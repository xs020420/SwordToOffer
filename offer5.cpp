//实现函数，把字符串中的每个空格换成 %20
//O(n^2)方法: 检测到空格，将所有后面的字符串向后移动。每个字符都移动多次
//O(n)方法：先遍历空格数，找到替换后的最后一个字符位置。向前遍历空格，将遍历到的目标后的
#include <cstring>
#include <iostream>

using namespace std;

void ReplaceBlank(char string[],int length)
{
    if(string == nullptr||length<=0)
        return;
    int originalLength=0;
    int numberOfBlank=0;
    int i=0;

    while(string[i]!='\0')
    {
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBlank;
        ++i;
    }

    int newLength=numberOfBlank*2 + originalLength;

    if(newLength>length)
        return;

    int indexOfOriginal=originalLength;
    int indexOfNew=newLength;
    while(indexOfNew!=indexOfOriginal)
    {
        if(string[indexOfOriginal]!=' ')
            {
                string[indexOfNew]=string[indexOfOriginal];
                indexOfNew--;
            }
        else
            {
                string[indexOfNew--]='0';
                string[indexOfNew--]='2';
                string[indexOfNew--]='%';

            }
        --indexOfOriginal;
    }

}


int main(int argc,char* argv[])
{
    int length=15;
    char str[10]="    ";
    cout<<str<<endl;
    ReplaceBlank(str,length);
    cout<<str<<endl;

}
