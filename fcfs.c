#include<stdio.h>

void main()

{

int n;

int twt=0,tat=0;

printf("Enter the number of process : ");

scanf("%d",&n);

int a[n][6];

//0-process id ,1-at,2-bt,3-completion time,4-tat,5-waiting time

for(int i=0;i<n;i++)

{

printf("\nProcess ID :"); scanf("%d",&a[i][0]);

printf("A.T of Process.%d :",a[i][0]); scanf("%d",&a[i][1]);

printf("B.T of Process.%d :",a[i][0]); scanf("%d",&a[i][2]);

}

a[0][3]=a[0][1]+a[0][2]; //completion time of 1st process

a[0][4]=a[0][3]-a[0][1]; //tat of 1st process

a[0][5]=a[0][4]-a[0][2]; //waiting time of 1st process

for(int i=1;i<n;i++)

{

a[i][3]=a[i-1][3]+a[i][2]; //completion time of ith process

a[i][4]=a[i][3]-a[i][1]; //tat of ith process

a[i][5]=a[i][4]-a[i][2]; //waiting time of ith process

}

printf("\nP.No.\tAT\t BT\t TAT\t WT");

for (int i=0; i<n; i++)

{

printf("\n%d\t\t%d\t%d\t%d\t%d", a[i][0], a[i][1], a[i][2], a[i][4], a[i][5]);

tat+=a[i][4];

twt+=a[i][5];

}

printf ("\nAverage Turnaround time = %f", tat/(float)n);

printf ("\nAverage Waiting time = %f", twt/(float)n);

}
