//
//  Priority(Preemtive).cpp
//  Operating System
//
//  Created by Hansika Saxena on 14/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ implementation for Priority Scheduling (NPE)
//Higher priority process will be executed first

#include <iostream>
#include <iomanip>
using namespace std;

struct process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int start_time;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main() {

    int n;
    struct process p[100];
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst;
        cout<<endl;
    }

    int current_time = 0;
    int completed = 0;

    while(completed != n) {
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= current_time && is_completed[i] == 0) {
                if(p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) {
                    if(p[i].arrival < p[idx].arrival) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst) {
                p[idx].start_time = current_time;
                
            }
            burst_remaining[idx] -= 1;
            current_time++;
            if(burst_remaining[idx] == 0) {
                p[idx].ct = current_time;
                p[idx].tat = p[idx].ct - p[idx].arrival;
                p[idx].wt = p[idx].tat - p[idx].burst;
                p[idx].rt = p[idx].start_time - p[idx].arrival;

                is_completed[idx] = 1;
                completed++;
            }
        }
        
    }

    cout<<endl<<endl;

    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].arrival<<"\t"<<p[i].burst<<"\t"<<p[i].priority<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

}

/*

AT - Arrival Time of the process
BT - Burst time of the process
ST - Start time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process
RT - Response time of the process

Formulas used:

TAT = CT - AT
WT = TAT - BT
RT = ST - AT

*/

