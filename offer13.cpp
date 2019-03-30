//m行，n列的格子。从（0，0）出发，每次移动一个格子。不能进入坐标的数位之和大于k的格子。
//问能到达多少个格子
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>
int iter=0;
int GetDigitSum(int number)
{
    int sum=0;
    while(number>0)
    {
        sum+=number%10;
        number=number/10;
    }
    return sum;
}

bool check(const int threhold,const int rows,const int columns,
     int row, int column, bool* visited)
{
    if(row >= 0 && row < rows && column >= 0 && column < columns
        && visited[row*columns+column] == false && GetDigitSum(row)+GetDigitSum(column) <= threhold)
        return true;
    else
        return false;
}


int MovingCountCore(const int threhold,const int rows,const int columns,int row,int column,bool* visited)
{
    iter++;
    int count=0;
    if(check(threhold,rows,columns,row,column,visited) == true)
    {
        visited[row*columns+column]=true;
        count = 1 +MovingCountCore(threhold,rows,columns,row-1,column,visited)
            +MovingCountCore(threhold,rows,columns,row,column-1,visited)
            +MovingCountCore(threhold,rows,columns,row+1,column,visited)
            +MovingCountCore(threhold,rows,columns,row,column+1,visited);
    }
    return count;
}




int MovingCount(const int threhold,const int rows,const int columns)
{
    if(threhold < 0 || rows <= 0 || columns <= 0)
        return 0;
    bool* visited= new bool[rows*columns];
    memset(visited,0,rows*columns);
    int count=MovingCountCore(threhold,rows,columns,0,0,visited);

    delete[] visited;
    return count;

}


// ====================测试代码====================
void test(char* testName, int threshold, int rows, int cols, int expected)
{

    if(testName != nullptr)
        printf("%s begins: ", testName);
    int count=MovingCount(threshold, rows, cols);
    if(count == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
    cout<<count<<endl;
}


void test1()
{
    test("Test1", 3,3, 5, 10);
}

int main(int argc,char* argv[])
{
    test1();
    cout<<iter<<endl;
}
