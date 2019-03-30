//旋转数字的最小数字
//把一个数组的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转的最小元素。
//要求:利用旋转数组的特性，减少时间复杂度。
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>

int binsearch(int * array, int length, int key)
{
    if(!array)
        return -1;
    int left = 0, right = length,mid;
    while(left <= right)
    {
        mid = left + (right-left)/2;
        if(array[mid] < key)
        {
            left = mid + 1;
        }else if(array[mid] > key)
        {
            right = mid - 1;
        }else
            return mid;
    }
    return -1;
}




int Min(int* numbers, int length)
{
    if(numbers == nullptr)
        {
            return 0;
        }

    int indexStart = 0;
    int indexEnd = length-1;
    int indexMid = 0;

    if(numbers[indexStart] >= numbers[indexEnd])
    {
        while(indexEnd-indexStart != 1)
        {
        indexMid=(indexStart+indexEnd)/2;
        if(numbers[indexMid]>numbers[indexStart])
            indexStart=indexMid;
        if(numbers[indexMid]<numbers[indexEnd])
            indexEnd=indexMid;
        }

        return indexEnd;
     }
     else
        return indexMid;


}
int main(int argc,char* argv[])
{
    int length=8;
    //int a[length]={1,2,3,4,5};
    //int searchResult=binsearch(a,length,5);
    //cout<<searchResult<<endl;

    int b[length]={5,6,7,8,1,2,3,4};
    int minResult=Min(b,length);
    cout<<minResult<<endl;

}
