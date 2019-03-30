//输入一个整数，输出该数二进制表示中 1 的个数。例如 输入 9，输出 2
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>
int iter=0;

int NumberOfOne(int number)
{
    int count=0;
    int flag=1;
    while(flag!=0)
    {
        iter++;

        if((number&flag))
            count++;
        flag=flag<<1;

    }
    return count;
}


int main()
{
    int a=1;
    cout<<NumberOfOne(255)<<endl;


}
