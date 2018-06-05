#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int moveLayer(int n,char source,char destination,char spare){
//set selection to n (i.e) if n is 1
    if(n==1){
        printf("\nMove layer %d from  %c plate to  %c plate",n,source,destination);
    }
    else{
    //call the function moveLayer(recursion) and return value to the function parameters
    //(n will get replaced with value of n-1).
   // Therefore  n-1 over n,source over source,spare over destination,destination over spare
        moveLayer(n-1,source,spare,destination);
        printf("\nMove layer %d from  %c plate to  %c plate",n,source,destination);
        //call the function moveLayer and like the above function return values to function moveLayer
        //as n-1 for n, spare for source, destination for destination,source for spare
         moveLayer(n-1,spare,destination,source);
    }
}


