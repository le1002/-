#include <iostream>
using namespace std;
const int n = 4;
int kol = 0;
int indexI = -1;
//int fl = 1;
int arr[n][n] = {
    { 1, 1,1,1 }, // матрица смежности
{ 1, 0, 0, 0},
{ 1, 0, 0, 1 },
{ 1, 1, 1, 1 } };
/*{ 1, 1, 1, 1, 1, 1, 1 }, // матрица смежности
{ 1, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0 },
{ 1, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 1, 1, 1, 1, 1 } };*/
int nodes[n]; // вершины графа
void Nodes()
{
    for (int i = 0; i < n; i++) // исходно все вершины равны 0
        nodes[i] = 0;
}
/*void search(int st, int n)//поиск пути
{
    
    int r;
    //cout << st + 1 << " ";
    nodes[st] = 1;
    for (r = 0; r < n; r++)
        if ((mas[st][r] != 0) && (nodes[r] == 0))
            search(r, n);
}*/
void search(int st)//поиск пути
{

    int r;
    //cout << st + 1 << " ";
    nodes[st] = 1;
    for (r = 0; r < n; r++)
        if ((arr[st][r] != 0) && (nodes[r] == 0))
            search(r);
}


bool count(int st)//проверка сколько дорог выходит и входит 
{
    int count_st = 0;
    int count_end = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[st][i] == 1)
            count_st++;
        if (arr[n-1][i] == 1)
            count_end++;
    }
    if (count_st <= 3 || count_end <= 3)
            return true;//можно перекрыть
        else
            return false;
            
        //cout << count_st << " end  " << count_end << endl;
    
}
void close(int st,int fl)
{
    int indexSt = st;
    int Start = st;
    if ((count(st)==true )&& fl==1)
    {
        cout<< "you can block 3 roads" << endl;
    }
    else
    {
        
        for (st; st < n; st++)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[st][i] == 1 && kol < 3 && indexI != i)
                {
                    indexI = i;
                    indexSt = st;
                    kol++;
                    arr[st][i] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) // исходно все вершины равны 0
            nodes[i] = 0;
        search(Start);
        //search(Start, n);
        if (nodes[n-1] == 0)
            cout << "you can block 3 roads" << endl;
        else
        {
            //if (indexI != -1 && Start != (n - 1))
            if (indexI != -1)
            {
                arr[indexSt][indexI] = 1;
                kol--;
                int fl = 0;
                close(Start, fl);
            }
           /* else
                if (Start == (n-1))
                    cout << "you can't block 3 roads" << endl;*/
        }
    }
}

int main()
{
    /*or (int i = 0; i < n; i++) // исходно все вершины равны 0
        nodes[i] = 0;
    search(1);
    if (nodes[n-1] == 0)
        cout << "no road" << endl;
    else
        cout << "y" << endl;*/
    //count(0);
    /*if (count(0)==false)
    {
        cout << "you can block 3 roads" << endl;
    }
    else
        cout<< "error" << endl;*/
    close(0,1);
    //cin.get();
    return 0;
}