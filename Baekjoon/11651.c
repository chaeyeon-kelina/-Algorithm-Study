#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
int N;
pair<int, int> dot[100010];
 
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second < b.second)
        return true;
    else if(a.second == b.second)
    {
        if(a.first < b.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
           return false;
}
 
int main(void)
{    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        scanf("%d %d", &dot[i].first, &dot[i].second);
 
    sort(dot, dot+N, cmp);
    
    for(int i = 0; i < N; i++)
    {
        printf("%d %d\n", dot[i].first, dot[i].second);
    }
    
    return 0;
}
