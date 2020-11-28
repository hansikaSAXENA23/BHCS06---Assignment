//
//  BestFit.cpp
//  Operating System
//
//  Created by Hansika Saxena on 11/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ implementation of Best - Fit algorithm
#include<iostream>
using namespace std;

void bestFit(int hole[], int m, int process[], int n)
{
    // Stores block id of the block allocated to a process
    int allocation[n];

    for(int i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    std::cout<<"\nStatus of Holes before memory allocation.\n ";
       for (int k = 0; k < m; k++)
       {
           std::cout<<hole[k]<<"\t";
       }
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (hole[j] >= process[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (hole[bestIdx] > hole[j])
                    bestIdx = j;
            }
        }
        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;
            // Reduce available memory in this block.
            hole[bestIdx] -= process[i];
        }
        std::cout<<"\nStatus of Holes after allocation of "<<i+1<<" process.\n";
              for (int k = 0; k < m; k++)
                 {
                     std::cout<<hole[k]<<"\t";
                 }
    }
    std::cout << "\nProcess No.\tProcess Size\tHole no.\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "   " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            std::cout << allocation[i] + 1;
        else
            std::cout << "Not Allocated";
        std::cout << endl;
    }
}
// Driver code
int main()
{
   int m,n;
    std::cout<<"Enter the no of holes.\n";
    std::cin>>m;
    int hSize[m];
    std::cout<<"Enter the size of holes.\n";
    for(int i=0;i<m;i++)
    {
        std::cin>>hSize[i];
    }

    std::cout<<"Enter the no of processes.\n";
    std::cin>>n;
    int pSize[n];
    std::cout<<"Enter the size of processes.\n";
    for(int i=0;i<n;i++)
    {
        std::cin>>pSize[i];
    }
    bestFit(hSize, m, pSize, n);
      return 0 ;
}
