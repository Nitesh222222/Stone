//ROUND ROBIN

#include<iostream>
using namespace std;
int main()
{
    
    cout<<"Enter NO of Process : ";
    int n;
    cin>>n;
    int process[n],bt[n],wt[n],tat[n];
    int remain_bt[n];
    
    for(int i=0;i<n;i++)
    {
        process[i]=i+1;
        cout<<"Enter Brust Time for Process P"<<process[i]<<" = ";
        cin>>bt[i];
        remain_bt[i]=bt[i];
    }
    
    int quantum;
    cout<<"Enter Time Quantum = ";
    cin>>quantum;
    
    int tot_time=0;
    int flag=false;
    
    while(!flag)
    {
        flag=true;
        for(int i=0;i<n;i++)
        {
            if(remain_bt[i]>0)
            {
                flag=false;
                if(remain_bt[i]>quantum)
                {
                    tot_time=tot_time+quantum;
                    remain_bt[i]=remain_bt[i]-quantum;
                }
                else
                {
                    tot_time=tot_time+remain_bt[i];
                    wt[i]=tot_time-bt[i];
                    remain_bt[i]=0;
                }
            }
        }
    }
    
    //TurnAround time-bt
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
    
    cout<<"Process\t\tBrust Time\tWaiting time\tTurnAround Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<process[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
}