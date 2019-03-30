//打印从1到最大的 n 位十进制数
//例如： 输入 3 ，打印： 1 ，2 ，3 ..., 999
//要点：用字符串模拟数字上的 加法 和 输出

#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>

void PrintNumberWithoutUnusefulZero(const char* number)
{
    bool isBeginning = true;
    int nlength=strlen(number);
    for(int i=0;i<nlength;i++)
    {
        if(number[i]!='0')
        {
            isBeginning=false;
        }
        if(isBeginning ==false)
            cout<<number[i];
    }
    cout<<endl;
}

void PrintOneToMaxNDigital_Recurrently(char* number,int length,int index)
{
    if(index == length)
    {
        PrintNumberWithoutUnusefulZero(number);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index]=i+'0';
        PrintOneToMaxNDigital_Recurrently(number,length,index+1);
    }
}


void PrintOneToMaxNDigital(int n)
{
    if(n <= 0)
        return;
    char* number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    PrintOneToMaxNDigital_Recurrently(number,n,0);
    delete[] number;
}


int main()
{
    PrintOneToMaxNDigital(3);
}
