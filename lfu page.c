/*
ALGORITHM
1. Start
2. Declare f,p indicating no of frames and no of pages
3. Declare pages[50],frame[10],count[50],time[50]
4. Declare hit and initialise as 0
5. Declare page,flag,least,minTime,temp
6. Read no of pages and frames in p and f
7. Input all entries of the frame[] as -1 indicating initially all frames are free
8. Set all entries of count[] as 0 indicating all request page initially has 0 frequency
9.Read each page no request on page[i]
10.Now for each page no , set its count++ ,time =i where i is its arrival ,flag to 0 and
least as first frame and do the following
10.1 For each of the frame check if page already there or any free frame is
there then

If page present then
Set hit++
Set flag=0,frame[j]=page[i] and break
If count of least frame is greater than current one then set least to

current frame
10.2 if flag==1 indicating replacement needed then
Set minTime=50
For each frame
If count of frame == count of least and frame’s time < minTime
Then set temp=current frame j and minTime =its time

Set count of temp frame as 0 and frame[temp]=page[i]
10.3 for each frame j if it is not -1 print it
11. Display page fault as p-hit,hit as hit, hit ratio as hit/p
12. Stop
*/
