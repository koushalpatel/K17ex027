#include<stdio.h>
#include<stdlib.h>
int main()
{
	int number=4;
	printf("Enter the number of process  ");//taking number of process
	scanf("%d",&number);
	if(number<=0)
	{
		exit(0);
	}
	float arriv[number];//for arrival time of each process
	float burst[number];//for burst time of each processs
	float prin[number];//variable array for priority calvulation
	float gant;    //variable to store the gantt value 
	float done[number];//the process done at which time
	float wait[number];//variable array for waiting time for each traversal
	float WT[number];   //array to store the final waiting time
              float TA[number];   //array to store the turn arount time
	int  i,l=0;
	//for taking burst and arrival time of each process
	for(i=0;i<number;i++)
	{
		printf("enter the arrival time for process P%d ",i+1);
		scanf("%f",&arriv[i]);
if(arriv[i]<0)
                       {
exit(0);
                       }
		
	}
	for(i=0;i<number;i++)
	{
		printf("enter the burst time for process P%d ",i+1);
		scanf("%f",&burst[i]);
if(burst[i]<0)
                       {
exit(0);
                       }

		
	}
	///////////////////////////////////////////////
	float sum=0;//variable to get the sum of all burst time for running the loop
	for(i=0;i<number;i++)
	{
		sum=sum+burst[i];
		
	}
	float min;
	for(i=0;i<number;i++)
	{
		if(arriv[i]==0)
		{
			min=burst[i];//to know which process arrives at 0
		     l=i;
		
			break;
		}
		
	
	}

	gant=min;//first of all that process will run
	for(i=0;i<number;i++)
	{
		if(arriv[i]==0)
		{
			wait[i]=0;
			
		}
		else
		{
		wait[i]=gant-arriv[i];
	    }
	}
	for(i=0;i<number;i++)
	{
		if(arriv[i]==0)
		{
			prin[i]=0;
		}
		else
		{
		prin[i]=1+(wait[i]/burst[i]);
	    }
		
}
//till here we are calculating priority for first time 
int min_pri;
	int j=0,k=0;
	while(gant<=(sum+min))
	{
		for(i=0;i<number;i++)
		{
			if(prin[i]==0)
			{
				continue;
			}
			else
			{
				if(min_pri<prin[i])
				{
					min_pri=prin[i];
					j=i;
				}
			}
		}
		
		gant=gant+burst[j];
		done[j]=gant;
		for(i=0;i<number;i++)
	{
		if(done[i]>0)
		{
			wait[i]=0;
			continue;
		}
		else
		{
		wait[i]=gant-arriv[i];
	    }
	}
	for(i=0;i<number;i++)
	{
		if(done[i]>0)
		{
			prin[i]=0;
		}
		else
		{
			if(wait[i]!=0)
	      {
			prin[i]=1+(wait[i]/burst[i]);
	      }
	}
	}
	k++;
	j=0;	
	}
	for(i=0;i<number;i++)
	{
		if(arriv[i]==0)
		{
			done[i]=burst[i];
			break;
		}
	}
	for(i=0;i<number;i++)
	{
		if(done[i]<1)
		{
			done[i]=sum;
		}
	}
	

for(i=0;i<number;i++)
    {
	WT[i]=done[i]-burst[i]-arriv[i];
	}
	for(i=0;i<number;i++)
    {
	TA[i]=WT[i]+burst[i];
	}
	printf("\n\tAT\t          \tBT\t          \tWT\t          \tTA\t");
	for(i=0;i<number;i++)
	{
		printf("\n\t%f\t|\t%f\t|\t%f\t|\t%f\t",arriv[i],burst[i],WT[i],TA[i]);
	}
	float avrgW=0;//average waiting time
	float avrgT=0;//average turn around time
	for(i=0;i<number;i++)
	{
		avrgW=avrgW+WT[i];
		avrgT=avrgT+TA[i];
	}
	avrgW=avrgW/number;
	avrgT=avrgT/number;

	printf("\n\n The average waiting time= %f",avrgW);
	printf("\n\n The average turn around time time= %f",avrgT);
	
	return 0;
}
