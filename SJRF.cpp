//
//  SJRF.cpp
//  Operating System
//
//  Created by Hansika Saxena on 25/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ program to implement Shortest Job Remaining Time first with Arrival Time
#include <iostream>
using namespace std;

struct Process {
    int pid; // Process ID
    int bt; // Burst Time
    int art; // Arrival Time
};


void findWaitingTime(Process proc[], int n,
                                int wt[])
{
    int rt[n];

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) &&
            (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
    
        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;

            wt[shortest] = finish_time -
                        proc[shortest].bt -
                        proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int n,
                        int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}



// Driver code
int main()
{
    Process proc[] = { { 1, 6, 1 }, { 2, 8, 1 },
                    { 3, 7, 2 }, { 4, 3, 3 } };
    int n = sizeof(proc) / sizeof(proc[0]);
    int wt[n], tat[n];
    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, wt, tat);
    cout << "Processes "
        << " Burst time "
        << " Waiting time "
        << " Turn around time\n";
    for (int i = 0; i < n; i++) {
        cout << " " << proc[i].pid << "\t\t"
            << proc[i].bt << "\t\t " << wt[i]
            << "\t\t " << tat[i] << endl;
    }
    return 0;
}

