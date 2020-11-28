//
//  SJF(Non-Preemtive).cpp
//  Operating System
//
//  Created by Hansika Saxena on 03/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ program to implement Shortest Job first with Arrival Time

#include<iostream>
using namespace std;
int process[10][6];
  
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void arrangeArrival(int n, int process[][6])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(process[j][1] > process[j+1][1])
            {
                for(int k=0; k<5; k++)
                {
                    swap(process[j][k], process[j+1][k]);
                }
            }
        }
    }
}
  
void completionTime(int n, int process[][6])
{
    int temp, val;
    process[0][3] = process[0][1] + process[0][2];
    process[0][5] = process[0][3] - process[0][1];
    process[0][4] = process[0][5] - process[0][2];
      
    for(int i=1; i<n; i++)
    {
        temp = process[i-1][3];
        int low = process[i][2];
        for(int j=i; j<n; j++)
        {
            if(temp >= process[j][1] && low >= process[j][2])
            {
                low = process[j][2];
                val = j;
            }
        }
        process[val][3] = temp + process[val][2];
        process[val][5] = process[val][3] - process[val][1];
        process[val][4] = process[val][5] - process[val][2];
        for(int k=0; k<6; k++)
        {
            swap(process[val][k], process[i][k]);
        }
    }
}
  
int main()
{
    int n;
      
    cout<<"Enter number of Process: ";
    cin>>n;
      
    cout<<"...Enter the process ID...\n";
    for(int i=0; i<n; i++)
    {
        cout<<"...Process "<<i+1<<"...\n";
        cout<<"Enter Process Id: ";
        cin>>process[i][0];
        cout<<"Enter Arrival Time: ";
        cin>>process[i][1];
        cout<<"Enter Burst Time: ";
        cin>>process[i][2];
    }
      
    cout<<"Before Arrange...\n";
    cout<<"Process ID\tArrival Time\tBurst Time\n";
    for(int i=0; i<n; i++)
    {
        cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\n";
    }
      
    arrangeArrival(n, process);
    completionTime(n, process);
    cout<<"Final Result...\n";
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0; i<n; i++)
    {
        cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\t\t"<<process[i][4]<<"\t\t"<<process[i][5]<<"\n";
    }
}
