//
//  RR(Non-Preemtive).cpp
//  Operating System
//
//  Created by Hansika Saxena on 09/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ program for implementation of RR scheduling
#include<iostream>
using namespace std;
struct Queue
{

    int r, f;
    int size;
    int *arr;
  
    Queue(int s)
    {
       f = r = -1;
       size = s;
       arr = new int[s];
    }
    int found(int e);
    void enter(int value);
    void delete_ele();
    void displayQueue();
};
  void Queue::enter(int value)
{
    if ((f == 0 && r == size-1) ||
            (r == (f-1)%(size-1)))
    {
        std::cout<<"\nQueue is Full";
    }
  
    else if (f == -1) /* Insert First Element */
    {
        f = r = 0;
        arr[r] = value;
    }
  
    else if (r == size-1 && f != 0)
    {
        r = 0;
        arr[r] = value;
    }
  
    else
    {
        r++;
        arr[r] = value;
    }
}
  
// Function to delete element from Circular Queue
void Queue::delete_ele()
{
    if (f == -1)
    {
        printf("\nQueue is Empty");
    }
    else if (f == r)
    {
        f = -1;
        r = -1;
    }
    else if (f == size-1)
    {
        f = 0;
    }
    else{
        f++;
    }
  
}

// Function returns whether an element is present in queue or not
int Queue::found(int e)
{
    int flag=0;
    if (r>=f)
    {
        for (int i = f; i <= r; i++)
        {
            if(arr[i]==e)
            {
                flag++;
                break;
            }
        }
    }
    else{
        for (int i = f; i <size; i++)
        {
            if(arr[i]==e)
            {
                flag++;
                break;
            }
        }
       for (int i = 0; i <=r; i++)
       {
           if(arr[i]==e)
           {
               flag++;
               break;
           }
       }
    }
    return flag;
}

void completionTime(int n,int p[], float bt[], float wt[],float ct[],float at[], int quantum)
{
    Queue rq(n);
    float rem_bt[n],timeline[100];
    int completed=0,temp;
    for (int i = 0 ; i < n ; i++)
    {
        rem_bt[i] = bt[i];
        ct[i]=0;
    }
    float t = 0;
    int i,k=0;
    rq.enter(p[0]);
    std::cout<<"\nTimeLine\n Process ID - |";
    timeline[0]=0;k++;
    while (completed != n)
    {
        
        if (rem_bt[rq.arr[rq.f]-1] > 0)
                            {
                                
                                if (rem_bt[rq.arr[rq.f]-1] > quantum)
                                {
                                    t += quantum;
                                    rem_bt[rq.arr[rq.f]-1] -= quantum;
                                    std::cout<<rq.arr[rq.f]<<"\t|";
                                    timeline[k]=t;
                                }
                                else
                                {
                                    t = t + rem_bt[rq.arr[rq.f]-1];
                                    rem_bt[rq.arr[rq.f]-1] = 0;
                                    completed ++;
                                    ct[rq.arr[rq.f]-1]=t;
                                    std::cout<<rq.arr[rq.f]<<"\t|";
                                    timeline[k]=t;
                                }
                            }
        k++;
        if(t <= at[n-1])
        {
            i=rq.arr[rq.f];
            
            while(at[i]<=t && i<n)
            {
                if(!rq.found(p[i]))
                {
                    rq.enter(p[i]);
                }
                i++;
            }
            if(ct[rq.arr[rq.f]-1] == 0){
                temp = rq.arr[rq.f];
                rq.delete_ele();
                rq.enter(temp);
           }
            else{
                       rq.delete_ele();
                   }
        }
        else if(ct[rq.arr[rq.f]-1] == 0){
            temp = rq.arr[rq.f];
            rq.delete_ele();
            rq.enter(temp);

        }
        else{
            rq.delete_ele();
        }
    }
   
    std::cout<<"\n       Time - ";
    for(i=0;i<k;i++){
    std::cout<<"|"<<timeline[i]<<"\t";
    }
}

void calculate( int n,float bt[], float wt[], float tat[],float ct[],float at[])
{
    for (int i = 0; i < n ; i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
}

int main()
{
    int n,i,j,quantum;
    std::cout<<"Enter no. of p.";
    std::cin>>n;
    int p[n],tp;
    float burst[n],arrival[n],wt[n],tat[n],t,compl_time[n];
     std::cout<<"\n Enter process no. burst time arrival time \n";
    for(i=0;i<n;i++)
    {
        std::cin>>p[i];
        std::cin>>burst[i];
        std::cin>>arrival[i];
    }
    std::cout<<"\n Enter process quantum time.";
           std::cin>>quantum;
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
      std::cout<<"Before Arrange...\n";
      std::cout<<"Process ID\tBurst Time\tArrival Time\n";
      for(int i=0; i<n; i++)
      {
          std::cout<<p[i]<<"\t\t"<<burst[i]<<"\t\t"<<arrival[i]<<"\n";
      }
    completionTime(n,p, burst, wt,compl_time,arrival,quantum);
    calculate(n,burst,wt,tat,compl_time,arrival);
   std::cout << "\n Processes " << " Burst Time " << " Arrival Time "
           << " Waiting Time " << " Turn-Around Time "
           << " Completion Time \n";
      for (int i = 0 ; i < n ; i++)
      {
              std::cout << " " << p[i] << "\t\t" << burst[i] << "\t\t"
               << arrival[i] << "\t\t" << wt[i] << "\t\t "
               << tat[i]  <<  "\t\t " << compl_time[i] << "\n";
      }
    return 0;
}
