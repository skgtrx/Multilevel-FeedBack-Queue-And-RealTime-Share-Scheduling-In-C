#include <stdio.h>
#define QUANTA 3
int main()
{
	int snum,fnum,i,k;
	printf("\nEnter Number Of Students : ");
	scanf("%d",&snum);
	int sid[snum],sarr[snum],sbur[snum];
	for(i=0;i<snum;i++)
	{
		sid[i]=i+1;
		printf("\nEnter Student %d Arrival Time : ",i+1);
		scanf("%d",&sarr[i]);
		printf("\nEnter Student %d Burst Time : ",i+1);
		scanf("%d",&sbur[i]);
		k=i+1;
	}
	printf("\nEnter Number Of Faculty : ");
	scanf("%d",&fnum);
	int fid[fnum],farr[fnum],fbur[fnum];
	for(i=0;i<fnum;i++)
	{
		k=k+1;
		fid[i]=k;
		printf("\n%d\n",fid[i]);
		printf("\nEnter Faculty %d Arrival Time : ",i+1);
		scanf("%d",&farr[i]);
		printf("\nEnter Faculty %d Burst Time : ",i+1);
		scanf("%d",&fbur[i]);
	}
	int pos,j,temp;
	for(i=0;i<snum;i++)
    {
        pos=i;
        for(j=i+1;j<snum;j++)
        {
            if(sarr[j]<sarr[pos])
                pos=j;
        }
        
        temp=sarr[i];
        sarr[i]=sarr[pos];
        sarr[pos]=temp;
 
        temp=sid[i];
        sid[i]=sid[pos];
        sid[pos]=temp;
 
        temp=sbur[i];
        sbur[i]=sbur[pos];
        sbur[pos]=temp;
    }
    for(i=0;i<fnum;i++)
    {
        pos=i;
        for(j=i+1;j<fnum;j++)
        {
            if(farr[j]<farr[pos])
                pos=j;
        }
        temp=farr[i];
        farr[i]=farr[pos];
        farr[pos]=temp;
 
        temp=fid[i];
        fid[i]=fid[pos];
        fid[pos]=temp;
 
        temp=fbur[i];
        fbur[i]=fbur[pos];
        fbur[pos]=temp;
    }
    /*for(i=0;i<fnum;i++)
    {
    	printf("%d	",fid[i]);
	}*/
    // Final Array
    int n=snum+fnum;
	int arr[n],bur[n],id[n];
	//
	i = 0;
 	j = 0;
 	k = 0;
	while (i < snum && j < fnum) 
	{
		if (sarr[i] <= farr[j]) 
		{
			arr[k] = sarr[i];
			bur[k] = sbur[i];
			id[k]  = sid[i];
			i++;
			k++;
		} 
		else 
		{
			arr[k] = farr[j];
			bur[k] = fbur[j];
			id[k]  = fid[j];
			k++;
			j++;
		}
	}
	while (i < snum)
	{
		arr[k] = sarr[i];
		bur[k] = sbur[i];
		id[k]  = sid[i];
		i++;
		k++;
	}
	while (j < fnum) 
	{
		arr[k] = farr[j];
		bur[k] = fbur[j];
		id[k]  = fid[j];
		k++;
		j++;
	}
 	printf("\n\n\n");
	for(i=0;i<n;i++)
 	{
 		printf("\n%d  %d  %d",id[i],arr[i],bur[i]);	
	}
	return 0;
}
