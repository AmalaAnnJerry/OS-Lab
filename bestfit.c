#include<stdio.h>
void main()
{
int np,nb,i,j,diff=-1,c;
printf("Enter no of block and process =");
scanf("%d%d",&nb,&np);
int block[nb],p[np],a[np],f[nb];
printf("Enter %d blocks:", nb);
for(i=0;i<nb;i++)
scanf("%d",&block[i]);
printf("Enter %d process: ",np);
for(i=0;i<np;i++)
scanf("%d",&p[i]);
for(i=0;i<np;i++)
a[i]=-1;
for(i=0;i<nb;i++)
f[i]=0;
for(i=0;i<np;i++)
{
for(j=0;j<nb;j++)
{
if(block[j]>=p[i])
{
if(f[j]==0)
{
if(diff==-1)
{
diff=block[j]-p[i];
c=j;
}
else
if((block[j]-p[i])<diff)
{
diff=block[j]-p[i];
c=j;
}
}
}
}
if(diff!=-1)
{
a[i]=c+1;
f[c]=1;
diff=-1;
}
}
printf("Process name \t\t Process \t\t\t Block No\n");
for(i=0;i<np;i++)
{
if(a[i]==-1)
printf("%d\t\t\t%d\t\t\t Not Allocated\n",i+1,p[i]);
else
printf("%d\t\t\t%d\t\t\t%d\n",i+1,p[i],a[i]);
}
}



