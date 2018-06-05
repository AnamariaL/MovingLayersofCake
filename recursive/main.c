#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;//layers
    printf("How many layers of cake  : ");
    scanf("%d",&n);
//call the function and return the values
    moveLayer(n,'S','G','B');  //S=silver, G=golden, B=bronze.
    return 0;
}
