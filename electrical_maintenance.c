#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define maxsize 10
 
int main()
{
    int n, m; //村莊大小 n->row
    int range[maxsize][maxsize]={0}; //村莊
    int a, b; //發電所位置
    int x, y; //住家位置
    int total=0;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &a, &b);
    range[a][b]=2;
    //確認可維修位置
    while(scanf("%d%d", &x, &y)!=EOF)
    {
        range[x][y]=9;
        for(int dx=-2; dx<=2; dx++)
        {
            for(int dy=-2; dy<=2; dy++)
            {
                if(!(dx==0 && dy==0))
                {
                    int k = a + dx;
                    int l = b + dy;
                    if( x==k && y==l && k>=0 && k<m && l>=0 && l<n )
                    {
                        range[x][y]=1;
                    }
                }
            }
        }
        //確認住家附近有無維修好的
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(range[i][j]!=0)
                {
                    for(int dx=-2; dx<=2; dx++)
                    {
                        for(int dy=-2; dy<=2; dy++)
                        {
                            if(!(dx==0 && dy==0))
                            {
                                int k = i + dx;
                                int l = j + dy;
                                if( range[k][l]==1 && k>=0 && k<m && l>=0 && l<n )
                                {
                                    range[i][j]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(range[i][j]==9)
            {
                total++;
            }
        }
    }
    range[a][b]=2;
    // 輸出村莊現況
    printf("%d\n", total);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(j!=m-1)
            {
                printf("%d ", range[i][j]);
            }
            else
            {
                printf("%d", range[i][j]);
            }
        }
        if(i!=n-1)
        {
            printf("\n");
        }
    }
}
