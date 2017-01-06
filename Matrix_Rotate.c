//Author:Shubharthi Dey

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int m,n,r,i,j;
    scanf("%d%d%d",&m,&n,&r);
    int a[m][n];
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                {
                    scanf("%d",a[i][j]);
                }
        }
    
    while(r>=1)
        {
            int row=0,col=0,prev,curr;
            while(row<m&&col<n)
                {
                    while(row+1==m||col+1==n)
                        break;
                    prev=a[row+1][n-1];
                    for(i=n-1;i>=0;i--)
                        {
                                curr=a[row][i];
                                a[row][i]=prev;
                                prev=curr;
                        }
                        row++;
                    for(i=row;i<m;i++)
                        {
                                curr=a[i][col];
                                a[i][col]=prev;
                                prev=curr;
                        }
                        col++;
                    if(row<m)
                        {
                            for(i=col;i<n;i++)
                                {
                                    curr=a[m-1][i];
                                    a[i][m-1]=prev;
                                    prev=curr;
                                }
                        }
                        m--;
                        if(col<n)
                            {
                                for(i=m-1;i>=row;i--)
                                    {
                                        curr=a[i][n-1];
                                        a[i][n-1]=prev;
                                        prev=curr;
                                    }
                            }
                            n--;
                }
            r--;
        }
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                {
                    printf("%d",a[i][j]);
                }
        }
    return 0;
}
