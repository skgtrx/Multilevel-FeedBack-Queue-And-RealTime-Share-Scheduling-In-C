// C++
#include<queue>
#include<iostream>
// C++
// Rest complete program is in C
#include<stdio.h>
using namespace std;

#define MAX 1000
#define QUANTM 4

int flag[MAX],arr_time[MAX],bur_time[MAX],priority[MAX],rt[MAX],ft[MAX],fe[MAX],fe_flag[MAX],pid[MAX],tms,qt[MAX];

queue<int> rr;  //RR queue

void RR()
{
      if(!rr.empty())
      {
      	if(rt[rr.front()]>0 && qt[rr.front()]<4)
      	{
          		qt[rr.front()]++;
          		rt[rr.front()]--;
          		if(rt[rr.front()]==0)
          		{
            	ft[rr.front()]=tms+1;
            	rr.pop();
          		}
          		if(rt[rr.front()]!=0 && qt[rr.front()]==4)
          		{
				qt[rr.front()]=0;
				rr.push(rr.front());
				rr.pop();
          		}
        	}
      }
}

int main()
{
    int i=0,n=0,smallest=0,last_smallest=-1,min,sum=0,large=0;
    printf("\n\nEnter Number Of Processes : ");
	scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("\n\n********** Process : %d **********\n\n",i+1);
		printf("Enter Process Id : ");
		scanf("%d",&pid[i]);
		printf("Enter Arrival Time : ");
		scanf("%d",&arr_time[i]);
		printf("Enter Burst Time : ");
		scanf("%d",&bur_time[i]);
		printf("Enter Priority : ");
		scanf("%d",&priority[i]);
    		if(arr_time[i]>large)
    		  	large=arr_time[i];
    		  sum+=bur_time[i];
    		  rt[i]=bur_time[i];
    }
    min=MAX;
    for(tms=0;!rr.empty() || tms<=sum+large ;tms++)
    {
      min=MAX;
      smallest=-1;
      for(i=0;i<n;i++)
      {
      	if(arr_time[i]<=tms && priority[i]<min && rt[i]>0 && !flag[i])
      	{
      		min=priority[i];
          		smallest=i;
        	}
      }
      if(smallest==-1 && !rr.empty())
      {
      	if(last_smallest !=-1 && rt[last_smallest]==0)
      	{
      		ft[last_smallest]=tms;
          		flag[last_smallest]=1;
        	}
        	last_smallest=-1;
        	RR();
        	continue;
      }
      else if(smallest!=-1 && !rr.empty() && last_smallest==-1)
      {
      	if(qt[rr.front()]<=4 && qt[rr.front()]>0)
      	{
      		rr.push(rr.front());
      		rr.pop();
        	}
      }
      if(smallest!=-1 && !fe_flag[smallest])
      {
      	fe[smallest]=tms-arr_time[smallest];
      	fe_flag[smallest]=1;
      }
      if( smallest!=last_smallest && last_smallest!=-1 && !flag[last_smallest])
      {
      	rr.push(last_smallest);
      	flag[last_smallest]=1;
      }
      if(smallest !=-1)
      	rt[smallest]--;
      
      if((smallest !=-1) && ((rt[smallest]==0) ||(bur_time[smallest]-rt[smallest])==QUANTM))
      {
      	if((bur_time[smallest]-rt[smallest])==QUANTM && rt[smallest]!=0)
      	{
      		flag[smallest]=1;
      		rr.push(smallest);
        	}
       	else if(smallest!=-1)
       	{
          		ft[smallest]=tms+1;
          		flag[smallest]=1;
        	}
      }
      last_smallest=smallest;
    }
   	printf("\n*********************************************************");
	printf("\nProcess Id | Response_Time | Finish_Time | Waiting_Time \n");
	float avg_waiting=0;
    for(int i=0;i<n;i++)
    {
    	printf("%d		%d		%d		%d\n",pid[i],fe[i],ft[i],ft[i]-bur_time[i]-arr_time[i]);
    	avg_waiting=avg_waiting+(ft[i]-bur_time[i]-arr_time[i]);
	}
	printf("\nAverage Waiting Time : %f",avg_waiting/(n*1.0));
    return 0;
}

