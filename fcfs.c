#include<stdio.h>
void main()
{
float avgwt,avgtt;
int twt=0,tat=0;
int i;
int A[]={1,2,3};
int n=sizeof A/sizeof A[0];
int AT[]={1,2,3};
int BT[]={10,5,8};
int Wt[n];
Wt[0]=0;
for(i=1;i<n;i++)
{
Wt[i]=Wt[i-1]+BT[i-1];
}
printf("Process\t   ArrivalTime\t   BurstTime\t  WT\t  TAT\n");
for(i=0;i<n;i++)
{
printf("%d\t\t",A[i]);
printf("%d\t\t",AT[i]);
printf("%d\t\t",BT[i]);
printf("%d\t\t",Wt[i]);
printf("%d\t\t",Wt[i]+BT[i]);
printf("\n");
twt=twt+Wt[i];
tat=tat+(Wt[i]+BT[i]);
}
avgwt=(float)twt/n;
avgtt=(float)tat/n;
printf("Average waiting time: %f\n",avgwt);
printf("Average turn around time: %f",avgtt);
}



