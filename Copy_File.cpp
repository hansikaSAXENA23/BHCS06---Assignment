//
//  Copy_File.cpp
//  Operating System
//
//  Created by Shreya Saxena on 19/10/20.
//  Copyright © 2020 Shreya Saxena. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
 {
   int f1, f2;
   char buff[50];
   long int n;

 if(((f1 = open(argv[1], O_RDONLY)) == -1 || ((f2=open(argv[2], O_CREAT |
 O_WRONLY | O_TRUNC, 0700))== 1)))
    {
       std::cout<<"problem in file";
       exit(1);
    }

 while((n=read(f1, buff, 50))>0)

     if(write(f2, buff, n)!=n)
        {
          std::cout<<"problem in writing";
           exit(3);
        }

     if(n==-1)
        {
           std::cout<<"problem in reading";
           exit(2);
        }

       close(f2);
       exit(0);
 }
