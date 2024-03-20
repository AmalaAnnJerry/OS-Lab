#include<stdio.h>
struct Proc{
char name;
int BT,WT,TAT,priority;
};
int main()
{
int n,total_wt=0,total_tat=0;
float avg_wt,avg_tat;
printf("Enter the no of processes");
scanf("%d",&n);
struct Proc proc[n];
for(int i=0;i<n;i++)
{
proc[i].name='A'+i;
printf("Enter burst time and priority for process%c:",proc[i].name);
scanf("%d%d",&proc[i].BT,&proc[i].priority);
}
for(int i=0;i<n;i++)
{
int pos=i;
for(int j=i+1;j<n;j++)
{
if(proc[j].priority>proc[pos].priority)
pos=j;
}
struct Proc temp=proc[i];
proc[i]=proc[pos];
proc[pos]=temp;
proc[i].WT=i==0?0:proc[i-1].TAT;
proc[i].TAT=proc[i].WT+proc[i].BT;
total_wt+=proc[i].WT;
total_tat+=proc[i].TAT;}
avg_wt=(float)total_wt/n;
avg_tat=(float)total_tat/n;
printf("\n Process\tBurst time\t Waiting time\t Turn around time\n");
for(int i=0;i<n;i++)
{
printf("%c\t%d\t\t%d\t\t%d\n",proc[i].name,proc[i].BT,proc[i].WT,proc[i].TAT);
}
printf("\nAverage waiting time: %f\n",avg_wt);
printf("\nAverage turn around time: %f\n",avg_tat);
return 0;
}



