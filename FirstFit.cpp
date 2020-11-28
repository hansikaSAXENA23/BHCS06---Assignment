//
//  FirstFit.cpp
//  Operating System
//
//  Created by Shreya Saxena on 07/10/20.
//  Copyright © 2020 Shreya Saxena. All rights reserved.
//

// C++ implementation of First - Fit algorithm
#include<iostream>
using namespace std;

void firstFit(int hole[], int m,
            int process[], int n)
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (hole[j] >= process[i])
            {
                // allocate block j to p[i] process
                allocation[i] = j;

                // Reduce available memory in this block.
                hole[j] -= process[i];
               
                break;
            }
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
        std::cout << " " << i+1 << "\t\t"
            << process[i] << "\t\t";
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
    firstFit(hSize, m, pSize, n);

    return 0 ;
}
