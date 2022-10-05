#include<stdio.h>
#include<limits.h>
#define v 4

void Floyd_Warshall(int D[][v+1],int P[][v+1])
{
    for(int k=1;k<=v;k++)
    {
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                if(k!=i && k!=j && D[i][k]!=INT_MAX && D[k][j]!=INT_MAX && D[i][j]>D[i][k]+D[k][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                }
            }
        }
    }
}
void APSP(int i,int j,int P[][v+1])
{
    if(i==j)
    {
        printf("%d ",i);
    }
    else if(P[i][j]!=INT_MIN)
    {
        APSP(i,P[i][j],P);
        printf("-> %d ",j);
    }
}
int main()
{
    int r;
    printf("\n\n---------- : FLOYD-WARSHALL ALGORITHM : ----------\n\n");
    FILE *fp;
    fp=fopen("floyd_graph.txt","r");
    if(fp==NULL)
    {
        printf("\nFile not open\n");
    }
    else
    {
        fscanf(fp,"%d",&r);
        int D[v+1][v+1];
        int P[v+1][v+1];
        for(int i=1;i<=v;i++)
        {
            for(int j=1;j<=v;j++)
            {
                fscanf(fp,"%d",&r);
                if(i==j)
                {
                    D[i][j]=0;
                    P[i][j]=INT_MIN;
                }
                else if(r==0)
                {
                    D[i][j]=INT_MAX;
                    P[i][j]=INT_MIN;
                }
                else
                {
                    D[i][j]=r;
                    P[i][j]=i;
                }
            }
        }
        fclose(fp);

        Floyd_Warshall(D,P);
        
        printf("\nThe All Possible Shortest Paths are :- \n\n\n");
        for(int i=1;i<=v;i++)
        {
            printf("Considering vertex %d as the source vertex :-\n\n",i);
            for(int j=1;j<=v;j++)
            {
                if(P[i][j]!=INT_MIN)
                {
                    printf("Path to vertex %d is :  ",j);
                    APSP(i,j,P);
                    printf("The cost of the path is: %d",D[i][j]);
                    printf("\n");
                }
            }
            printf("\n\n");
        }
    }
}
