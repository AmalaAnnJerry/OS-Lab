#include <stdio.h>
int findLRU(int time[], int n)
{
int minimum = time[0], pos = 0;
for (int i = 1; i < n; i++) {
if (time[i] < minimum)
{
minimum = time[i];
pos = i;
}
}
return pos;
}
void LRU(int pg[], int n, int frame)
{
int temp[frame], counter = 0, time[10], flag1, flag2,pos;
int hit=0, pagefault = 0;
printf("\nValues\t");
for (int i = 1; i <= frame; i++)
printf("Frame%d\t", i);
printf("\n");
for (int i = 0; i < frame; i++)
temp[i] = -1;
for (int i = 0; i < n; i++)
{
flag1 = flag2 = 0;
printf("%d =>\t", pg[i]);
for (int j = 0; j < frame; j++)
{
if (temp[j] == pg[i])
{
counter++;
time[j] = counter;
flag1 = flag2 = 1;
hit++;
printf("\tHit!!!\n");
break;
}
}
if (flag1 == 0)
{
for (int j = 0; j < frame; j++)
{
if (temp[j] == -1)
{
counter++;
pagefault++;
temp[j] = pg[i];
time[j] = counter;
flag2 = 1;
for (int k = 0; k < frame; k++)
{
if (temp[k] != -1)
printf("%d\t", temp[k]);
}
printf("\n");
break;
}
}
}
if (flag2 == 0)
{
pos = findLRU(time, frame);
counter++;
pagefault++;
temp[pos] = pg[i];
time[pos] = counter;
for (int j = 0; j < frame; j++)
{
if (temp[j] != -1)
printf("%d\t", temp[j]);
}
printf("\n");
}
}
printf("\nTotal Page Faults = %d\n", pagefault);
printf("Total Page hits = %d\n", hit);
printf("Hit ratio = %f",hit/(float)n);
}
void main()
{
int n, frame;
printf("Enter the Length of sequence: ");
scanf("%d", &n);
int pg[n];
printf("Enter the Sequence: ");
for (int i = 0; i < n; i++)
scanf("%d", &pg[i]);
printf("Enter the number of frames: ");
scanf("%d", &frame);
LRU(pg,n,frame);
}
/* ALGORITHM
1. Start
2. Declare n, frame
3. Read no of sequences in n and no of frames in frame
4.Declare pg[n]
5. Read each request and store it in pg[i]
6. Use another function LRU and pass pg[],n,frame as argument
//Inside LRU function
7.Declare pagefault,hit, temp[frame],counter,time[frame],flag1.flag2,pos
8. Initialise pagefault=0,hit=0,counter=0
9. Add -1 to all entries in temp[] indicating initially all frames are free
10. Now take each request as pg[i] and set flage1=flage2=0 and check if pg[i]
already in temp if yes set counter++,time[j]=counter,flag1=flag2=1,hit++ and break
Otherwise there are 2 options
If flag1==0 and free frame exist then set temp[j]=pg[i]
counter++,time[j]=counter , flag2=1 ,pagefault++ and print each temp[k] which is not
-1 and break
If flag2 still 0 means no free frame then first find least recently used frame
using a function findLRU and store it in pos and set temp[pos]=pg[i], counter++,
time[pos]=counter, pagefault++ and print each temp[k] which is not -1
10.1 for i from 0 to n-1
10.1.1 Set flag1=flag2=0 and print pg[i]
10.1.2 for j from 0 to frame-1
If temp[j]==pg[i] then set counter++ ,time[j]=counter hit++

,flag1=flag2=1 and break

10.1.3 if flag1==0 then
For j from 0 to frame-1
If temp[j]==-1 then set counter++ ,time[j]=counter pagefault++
,flag2=1 and print temp[k] where k=0 to frame-1 and temp[k]!=-1 and break
10.1.4 if flag2==0 then find LRU frame using findLRU()
//inside findLRU()
For i from 0 to n-1
If time[i]<minimum set minimum=time[i] and pos=i
Set temp[pos]=pg[i] , counter++,pagefault++,time[pos]=counter
Print each temp[k] where k =0 to frame-1 and temp[k]!=-1

11. Display Total page fault =pagefault
12. Display total page hit as hit
13. Display hit ratio as hit/n
14. Stop
  */
