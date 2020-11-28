//
//  Priority.cpp
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
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main() {

    int n;
    struct process p[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    std::cout << setprecision(2) << fixed;

    std::cout<<"Enter the number of processes: ";
    std::cin>>n;

    for(int i = 0; i < n; i++) {
        std::cout<<"Enter arrival time of process "<<i+1<<": ";
        std::cin>>p[i].arrival;
        std::cout<<"Enter burst time of process "<<i+1<<": ";
        std::cin>>p[i].burst;
        std::cout<<"Enter priority of the process "<<i+1<<": ";
        std::cin>>p[i].priority;
        p[i].pid = i+1;
        std::cout<<endl;
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
            p[idx].st = current_time;
            p[idx].ct = p[idx].st + p[idx].burst;
            p[idx].tat = p[idx].ct - p[idx].arrival;
            p[idx].wt = p[idx].tat - p[idx].burst;
            p[idx].rt = p[idx].st - p[idx].arrival;
            

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].ct;
    }

    std::cout<<endl<<endl;

    std::cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        std::cout<<p[i].pid<<"\t"<<p[i].arrival<<"\t"<<p[i].burst<<"\t"<<p[i].priority<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }


}
