//减绳子。长度为 n 的绳子减成 m 段。
//
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>

int MaxProductAfterCutting_Dp(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;
    int* products=new int[length+1];
    products[0]=0;
    products[1]=1;
    products[2]=2;
    products[3]=3;
    int max=0;

    for(int i=4;i<=length;i++)
    {
        max=0;

        for(int j=1;j<=i/2;j++)
        {
            int product=products[j]*products[i-j];
            if(max<product)
                max=product;

            products[i]=max;
        }

    }

    max=products[length];
    delete[] products;
    return max;

}

int MaxProductAfterCutting_IterativelyCore(int length)
{
    if(length == 1)
        return 1;
    if(length == 2)
        return 2;
    if(length == 3)
        return 3;
    int max=0;
    for(int j=1;j<=length/2;j++)
        {

            int present =MaxProductAfterCutting_IterativelyCore(j)*MaxProductAfterCutting_IterativelyCore(length-j);
            if(max<present)
                max=present;
            //cout<<present<<endl;
        }
    return max;
}

//以下为迭代写法
int MaxProductAfterCutting_Iteratively(int length)
{
    if(length < 2)
        return 0;
    if(length == 2 )
        return 1;
    if(length == 3)
        return 2;
    int max=MaxProductAfterCutting_IterativelyCore(length);
    return max;
}


int main(int argc,char* argv[])
{
    int result=MaxProductAfterCutting_Iteratively(6);
    cout<<result<<endl;
}
