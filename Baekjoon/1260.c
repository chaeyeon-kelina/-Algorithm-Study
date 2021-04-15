#include <stdio.h>
#include <stdlib.h>

int graph[1001][1001]={0, };
    int Dvisit[1001]={0, };
    int Bvisit[1001]={0, };
    int queue[1001];

void dfs(int v, int n){

    Dvisit[v]=1;
    printf("%d ", v);
    for(int i=1; i<=n; i++){
        if(graph[v][i]==1 && Dvisit[i]==0)
            dfs(i,n);
    }
    return;

}

void bfs(int v, int n){
    int front=0;
    int rear=0;
    int pop;

    printf("%d",v);
    queue[0]=v;
    rear++;
    Bvisit[v]=1;

    while(front < rear){
        pop=queue[front];
        front++;

        for(int i=1; i<=n; i++){
            if(graph[pop][i]==1 && Bvisit[i]==0){
                printf(" %d", i);
                queue[rear]=i;
                rear++;
                Bvisit[i]=1;
            }
        }
    }
    return;

}
int main()
{
    int n,m,v;
    int x,y;

    scanf("%d %d %d", &n, &m, &v);

    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        graph[x][y]=1;
        graph[y][x]=1;
    }
    dfs(v,n);
    printf("\n");
    bfs(v,n);

    return 0;


}
