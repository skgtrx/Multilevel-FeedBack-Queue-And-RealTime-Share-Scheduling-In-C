#include <stdio.h>

int main()
{
	printf("\nOnline Query Handeler : \n=========================================\n\n");
	int snum,fnum,i,k;
	printf("Query Timing : 10 am to 12 am\nInstruction : Total Time : 14 Hrs\n\t      Consider 10 am as 0 Hrs\n\n=========================================\n");
	printf("\nEnter Number Of Students : ");
	scanf("%d",&snum);
	printf("\n=========================================");
	int sid[snum],sarr[snum],sbur[snum];
	for(i=0;i<snum;i++)
	{
		printf("\n------------------------------------------------");
		sid[i]=i+1;
		printf("\nEnter Student %d Arrival Time : ",i+1);
		scanf("%d",&sarr[i]);
		printf("Enter Student %d Burst Time   : ",i+1);
		scanf("%d",&sbur[i]);
		k=i+1;
		printf("------------------------------------------------");
	}
	
	printf("\n\n=========================================\n\nEnter Number Of Faculty : ");
	scanf("%d",&fnum);
	printf("\n=========================================");
	int fid[fnum],farr[fnum],fbur[fnum];
	for(i=0;i<fnum;i++)
	{
		printf("\n------------------------------------------------");
		k=k+1;
		fid[i]=k;
		printf("\nEnter Faculty %d Arrival Time : ",i+1);
		scanf("%d",&farr[i]);
		printf("Enter Faculty %d Burst Time   : ",i+1);
		scanf("%d",&fbur[i]);
		printf("------------------------------------------------");
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
    int n=snum+fnum;
	int arr[n],bur[n],id[n],rt[n];
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
	for(i=0;i<n;i++) 
	{  
		rt[i]=bur[i]; 
	}
	// Round Robin
	int clock=0;
	int time_quantum=1;
	int count; 
	int uid[14];
	int uid_c=0;
  	int time,flag=0,remain=n; 
  	int wait_time=0,turnaround_time=0; 
  	printf("\n\nQuery Taken In Order( 1 Hr each )\n");
  	for(time=0,count=0;remain!=0;) // remain==pro_left
  	{ 
    	if(rt[count]<=time_quantum && rt[count]>0) 
    	{ 
    		clock=clock+1;
      		time+=rt[count]; 
      		rt[count]=0; 
      		flag=1; 
      		if(clock<=14)
			{
      			if(id[count]>snum){
      				uid[uid_c]=id[count];
      				uid_c++;
      				printf("Faculty with id : %d\n",id[count]);
				  }
      				
      			else{
      				uid[uid_c]=id[count];
      				uid_c++;
      				printf("Student with id : %d\n",id[count]);	
				  }
      				
			}
			else
			break;
			  
    	} 
    	else if(rt[count]>0) 
    	{ 
    		clock+=1;
      		rt[count]-=time_quantum; 
      		time+=time_quantum; 
      		if(clock<=14)
			{
      			if(id[count]>snum){
      				uid[uid_c]=id[count];
      				uid_c++;
      				printf("Faculty with id : %d\n",id[count]);
				  }
      				
      			else{
      				uid[uid_c]=id[count];
      				uid_c++;
      				printf("Student with id : %d\n",id[count]);	
				  }
      				
			}
			else
			break;
    	} 
    	if(rt[count]==0 && flag==1) 
    	{ 
      		remain--; 
      		wait_time+=time-arr[count]-bur[count]; 
      		turnaround_time+=time-arr[count]; 
      		flag=0; 
    	} 
    	if(count==n-1) 
      		count=0; 
    	else if(arr[count+1]<=time) 
      		count++; 
    	else 
      		count=0; 
  	}
  	n=14;
  	for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; )
        {
            if(uid[j] == uid[i])
            {
                for(k = j; k < n; k++)
                {
                    uid[k] = uid[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }

    int final_pro=n;
    printf("%d",final_pro);
    float avg_qt= ((clock-1)*1.0)/n;
  	printf("\n\nSUMMARY : \n\n");
  	printf("Total spent time : %d\n",clock-1);
  	printf("Average query time : %f\n",avg_qt);
	return 0;
}
