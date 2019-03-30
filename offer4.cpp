//二维数组的查找（从左到右，自上至下递增排序）

#include <iostream>
using namespace std;

bool find(int* matrix,int rows,int columns,int number)
{
    if(matrix == nullptr||rows<0||columns<0)
        return false;
    int row=0;
    int column=columns-1;
    int n=0;
    while(row<rows&&column>=0)
    {
        n++;
        cout<<matrix[row*columns+column]<<endl;

        if(matrix[row*columns+column] == number)
        {
            return true;
        }

        else if(matrix[row*columns+column] > number)
            --column;
        else
            ++row;

    }


    return false;
}

int main(int argc,char* argv[])
{
    int a[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    cout<<find(&a[0][0],4,4,6)<<endl;

}
