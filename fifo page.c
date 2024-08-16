#include <stdio.h>
void FIFO(int pg[], int n, int frame)
{
int pagefault = 0, hit = 0, k = 0, flag;
int temp[frame];
printf("\nValues\t");
for (int i = 1; i <= frame; i++)
printf("Frame%d\t", i);
printf("\n");
for (int i = 0; i < frame; i++)
{
temp[i] = -1;
}
for (int i = 0; i < n; i++)
{
flag= 0;
printf("\n%d =>\t", pg[i]);
for (int j = 0; j < frame; j++)
{
if (temp[j] == pg[i])
{ flag= 1;
hit++;
printf("\tHit!!!");
}
}
if (flag == 0)
{
temp[k] = pg[i];
k = (k + 1) % frame;
pagefault++;
for (int j = 0; j < frame; j++)
{
if (temp[j] != -1)
printf("%d\t", temp[j]);
}
}
}
printf("\nTotal Page Faults: %d\n", pagefault);
printf("\nTotal Page hits = %d\n", hit);
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
FIFO(pg,n,frame);
}
/* ALGORITHM
1. Start
2. Declare n, frame
3. Read no of sequences in n and no of frames in frame
4.Declare pg[n]
5. Read each request and store it in pg[i]
6. Use another function FIFO and pass pg[],n,frame as argument
//Inside FIFO function
7.Declare pagefault,hit,k,flag,temp[frame]
8. Initialise pagefault=0,hit=0,k=0
9. Add -1 to all entries in temp[] indicating initially all frames are free
10. Now take each request ie pg[i] then set flag=0 then check if pg[i] is already
present in temp if yes set flag to 1 , hit++ and print “Hit” otherwise set temp[k] to pg[i]
where k denotes the frame in which oldest request is present and set k to
k+1%frame and pagefault++ and then print all entries of temp which are not -1
10.1 for i from 0 to n-1
10.1.1 Set flag=0 and print pg[i]
10.1.2 for j from 0 to frame-1
If temp[j]==pg[i] then set hit++,flag=1 and print hit
10.1.3 if flag==0 then
Set temp[k]=pg[i] and k=(k+1)%frame
For j from 0 to frame-1
If temp[j]!=-1 then print temp[j]

11. Display Total page fault =pagefault
12. Display total page hit as hit
13. Display hit ratio as hit/n
14. Stop
*/
