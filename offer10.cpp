//斐波那契数列
//求斐波那契数列的第n项
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>


long long Fibonacci(unsigned int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

long long Fibonacci_Recurrently(unsigned int n)
{
    int result[2]={0,1};
    if(n <= 1)
        return result[n];
    long long fibNMinusOne=1;
    long long fibNMinusTwo=0;
    long long fibN=0;
    int i=0;
    for(i=2;i<=n;i++)
    {
        fibN=fibNMinusOne+fibNMinusTwo;
        fibNMinusTwo=fibNMinusOne;
        fibNMinusOne=fibN;
    }
    return fibN;
}

int main(int argc,char* argv[])
{
    int x=50;

    //long long yInteratively=Fibonacci(x);
    long long yRecurrently=Fibonacci_Recurrently(x);
    //cout<<yInteratively<<endl;
    cout<<yRecurrently<<endl;


}
