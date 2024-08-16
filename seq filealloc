#include<stdio.h>
#define FALSE 0
#define TRUE 1

int allocateSequentially(int startingPosition, int allocationLength, int maximumSize, int block[])
{
	int isPossible = TRUE;
	int i; 
    if(startingPosition + allocationLength > maximumSize + 1)
    {
        return FALSE;
    }
for(i=startingPosition-1; i<startingPosition+allocationLength-1; i++)
    {
    	if(block[i] == TRUE)
    	{
    		isPossible = FALSE;
return FALSE;
    	}
    }
    for(i=startingPosition-1; i<startingPosition+allocationLength-1; i++)
    {
    	block[i] = TRUE;
    }
    return TRUE;
}

int main()
{
    int allocationLength, startingPosition, maximumSize;
    int i, j;
    int inputChoice;
    printf("Enter the maximum size available : ");
    scanf("%d", &maximumSize);
    int block[maximumSize];
    for(i=0; i<maximumSize; i++)
    {
    	block[i] = FALSE;
    }
    while(1)
    {
    	printf("\n\n\t\t MENU : \n\n\t\t 1. Allocate \n\n\t\t 2. Exit \n\n\t\t Choice : ");
    	scanf("%d", &inputChoice);
    	if(inputChoice == 2)
    	{
    		return 0;
    	}
    	printf("\n\n\t Enter the starting address : ");
    	scanf("%d", &startingPosition);
    	printf("\n\n\t Enter the length of the block : ");
    	scanf("%d", &allocationLength);
    	if(allocateSequentially(startingPosition, allocationLength, maximumSize, block) == TRUE)
    	{
    		printf("\n\n\t Successfully Allocated!");
    	}
    	else
    	{
    		printf("\n\n\t Space cannot be allocated!");
    	}
 }
}
