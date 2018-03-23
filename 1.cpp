#include<stdio.h>
#include<queue>

using namespace std;

#define MAX 1000
#define QUANTA 4

int flag[MAX],at[MAX],bt[MAX],pt[MAX],rt[MAX],ft[MAX],fe[MAX],fe_flag[MAX],pid[MAX],tms,qt[MAX];

//at arrival time
//bt burst time
//rt Response Time
//pt priority
//pid process id

queue<int> q;  //RR queue

void RR()
{
      if(!q.empty())
      {
      	if(rt[q.front()]>0 && qt[q.front()]<4)
      	{
          		qt[q.front()]++;
          		rt[q.front()]--;
          		if(rt[q.front()]==0)
          		{
            	ft[q.front()]=tms+1;
            	q.pop();
          		}
          		if(rt[q.front()]!=0 && qt[q.front()]==4)
          		{
				qt[q.front()]=0;
				q.push(q.front());
				q.pop();
          		}
        	}
      }
}

int main()
{
    int i=0,n=0,smallest=0,last_smallest=-1,min,sum=0,large=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    		scanf("%d %d %d %d",&pid[i],&at[i],&bt[i],&pt[i]);
    		if(at[i]>large)
    		  	large=at[i];
    		  sum+=bt[i];
    		  rt[i]=bt[i];
    }
    min=MAX;
    for(tms=0;!q.empty() || tms<=sum+large ;tms++)
    {
      min=MAX;
      smallest=-1;
      for(i=0;i<n;i++)
      {
      	if(at[i]<=tms && pt[i]<min && rt[i]>0 && !flag[i])
      	{
      		min=pt[i];
          		smallest=i;
        	}
      }
      if(smallest==-1 && !q.empty())
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
      else if(smallest!=-1 && !q.empty() && last_smallest==-1)
      {
      	if(qt[q.front()]<=4 && qt[q.front()]>0)
      	{
      		q.push(q.front());
      		q.pop();
        	}
      }
      if(smallest!=-1 && !fe_flag[smallest])
      {
      	fe[smallest]=tms-at[smallest];
      	fe_flag[smallest]=1;
      }
      if( smallest!=last_smallest && last_smallest!=-1 && !flag[last_smallest])
      {
      	q.push(last_smallest);
      	flag[last_smallest]=1;
      }
      if(smallest !=-1)
      	rt[smallest]--;
      
      if((smallest !=-1) && ((rt[smallest]==0) ||(bt[smallest]-rt[smallest])==QUANTA))
      {
      	if((bt[smallest]-rt[smallest])==QUANTA && rt[smallest]!=0)
      	{
      		flag[smallest]=1;
      		q.push(smallest);
        	}
       	else if(smallest!=-1)
       	{
          		ft[smallest]=tms+1;
          		flag[smallest]=1;
        	}
      }
      last_smallest=smallest;
    }
   for(int i=0;i<n;i++)
      cout<<pid[i]<<" "<<fe[i]<<" "<<ft[i]<<" "<<ft[i]-bt[i]-at[i]<<endl;
    return 0;
}
