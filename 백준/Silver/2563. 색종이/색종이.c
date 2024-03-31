#include <stdio.h> // 첫 번째 코드

int main(void)
{
    int times,count = 0;
    
    int distance_x[100] = {};
    int distance_y[100] = {};
    
    int square[101][101] = {0};
    
    scanf("%d",&times);
    
    for(int i=0;i<times;i++)
    {
        scanf("%d %d",&distance_x[i],&distance_y[i]);
    }
    
    for(int i=0;i<times;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                square[distance_y[i]+1+j][distance_x[i]+1+k] = 1;
            }
        }
    }
    
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(square[i][j] == 1)
            count++;
        }
    }
    
    printf("%d",count);
    
    return 0;
}