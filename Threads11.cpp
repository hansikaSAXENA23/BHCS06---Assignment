//
//  Threads11.cpp
//  Operating System
//
//  Created by Hansika Saxena on 25/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
#include<pthread.h>
using namespace std;

int global[2];

void *sum_thread(void *arg)
{
    int *args_array;
    args_array = (int*)arg;

    int n1,n2,sum;
    n1=global[0];
    n2=global[1];
    sum = n1+n2;

    cout<<"\n Sum = "<<sum;

    return NULL;;
}

int main()
{
    cout<<"\n First number: ";
    cin>>global[0];

    cout<<"\n Second number: ";
    cin>>global[1];

    pthread_t tid_sum;
    pthread_create(&tid_sum,NULL,sum_thread,(void*)&global);
    pthread_join(tid_sum,NULL);

    return 0;
}
