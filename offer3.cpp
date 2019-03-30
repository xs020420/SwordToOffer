//找出数组中重复的数字

#include <iostream>
using namespace std;

//是否包含某数字
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }
    return false;
}

bool duplicate(int numbers[],int length,int* duplication)
{
    if(numbers == nullptr||length <= 0)
    {
            return false;
    }

    for(int i=0;i<length;++i)
    {
        if(numbers[i]<0||numbers[i]>(length-1))
            return false;
    }

    for(int i=0;i<length;i++)
    {
        while(numbers[i] != i)

        {

            if(numbers[i] == numbers[numbers[i]])

            {

                *duplication = numbers[i];

                return true;

            }



    // 交换numbers[i]和numbers[numbers[i]]

            int temp = numbers[i];

            numbers[i] = numbers[temp];

            numbers[temp] = temp;

        }
    }
    return false;
}



int main(int argc,char* argv[])
{
    int b = 0;
    int a[5]={1,2,2,3,3};
    cout<<duplicate(a,5,&b)<<endl;
    cout<<b<<endl;
}
