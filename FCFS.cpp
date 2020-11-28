//
//  FCFS.cpp
//  Operating System
//
//  Created by Hansika Saxena on 01/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
#include <unistd.h>
// C++ program for implementation of FCFS scheduling

  
// Function to calculate the waiting time

void waitingTime(int n,float bt[], float wt[],float at[])
{
    // waiting time for first process is 0 in FCFS
    float sum[n];
    wt[0] = 0;
    sum[0] = 0;

    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        sum[i] = sum[i-1] + bt[i-1];
  
        wt[i] = sum[i] - at[i];
  
        if (wt[i] < 0)
            wt[i] = 0;
    }
}
  
// Function to calculate turn around time
void turnAroundTime( int n, float bt[], float wt[], float tat[])
{
    
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
  

int main()
{
    int n,i,j,compl_time;
    std::cout<<"Enter no. of p.";
    std::cin>>n;
    int p[n],tp;
    float burst[n],arrival[n],wt[n],tat[n],t;
    for(i=0;i<n;i++)
    {
        std::cout<<"\n Enter process no.";
        std::cin>>p[i];
        std::cout<<"\n Enter process burst time.";
        std::cin>>burst[i];
        std::cout<<"\n Enter process arrival time.";
        std::cin>>arrival[i];
    }
    
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
            
        {
            if (arrival[j] > arrival[j+1])
            {
                t=arrival[j];
                arrival[j]=arrival[j+1];
                arrival[j+1]=t;
                
                tp=p[j];
                p[j]=p[j+1];
                p[j+1]=tp;
                
                t=burst[j];
                burst[j]=burst[j+1];
                burst[j+1]=t;
             }
        }
    }
      
    waitingTime(n, burst, wt, arrival);
    turnAroundTime(n, burst, wt, tat);
    
    std::cout << "\n Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";
    for (int i = 0 ; i < n ; i++)
    {
            compl_time = tat[i] + arrival[i];
            std::cout << " " << p[i] << "\t\t" << burst[i] << "\t\t"
             << arrival[i] << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << compl_time << "\n";
    }

    return 0;
}
