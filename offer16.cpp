//数值的整数次方
//要考虑功能 边界 特殊值
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>
#include <algorithm>

const double eps =1e-6;
bool InvalidInput = false;

double Power(double base,int exponent)
{
    double result=1.0;
    InvalidInput = false;
    if(fabs(base-0.0)<eps && exponent < 0)
    {
        InvalidInput=true;
        return 0.0;
    }

    if(exponent > 0)
    {
        for(int i=1;i<=exponent;i++)
        {
            result*=base;
        }
    return result;
    }

    if(exponent == 0)
    {
        return 1.0;
    }

    if(exponent < 0)
    {
        int absexponent=abs(exponent);
        for(int i=1;i<=absexponent;i++)
        {
            result*=base;
        }
        return 1.0/result;
    }
}
int main()
{
    double result=Power(0,-3);
    cout<<result<<endl;
    if(InvalidInput == false)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}
