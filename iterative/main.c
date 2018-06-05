#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct Stack{
   unsigned capacity;
   int top;
   int *array;
};

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity){
    struct Stack* stack =
        (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack){
   return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack){
   return (stack->top == -1);
}

// Function to add an item to stack.  It increases
// top by 1
void push(struct Stack *stack, int item){
    if (isFull(stack))
        return;
    stack -> array[++stack -> top] = item;
}

// Function to remove an item from stack.  It
// decreases top by 1
int pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

// Function to implement legal movement between
// two plates
void moveLayersbetweenPlates(struct Stack *source,
            struct Stack *dest, char s, char d){
    int plate1TopLayer = pop(source);
    int plate2TopLayer = pop(dest);

    // When plate1 is empty
    if (plate1TopLayer == INT_MIN){
        push(source, plate2TopLayer);
        moveLayer(d, s, plate2TopLayer);
    }

    // When plate2 pole is empty
    else if (plate2TopLayer == INT_MIN){
        push(dest, plate1TopLayer);
        moveLayer(s, d, plate1TopLayer);
    }

    // When top layer of plate1 > top layer of plate2
    else if (plate1TopLayer > plate2TopLayer){
        push(source, plate1TopLayer);
        push(source, plate2TopLayer);
        moveLayer(d, s, plate2TopLayer);
    }

    // When top layer of plate1 < top layer of plate2
    else{
        push(dest, plate2TopLayer);
        push(dest, plate1TopLayer);
        moveLayer(s, d, plate1TopLayer);
    }
}

//Function to show the movement 
void moveLayer(char fromPlate, char toPlate, int layer){
    printf("Move the disk %d from \'%c\' to \'%c\'\n",
           layer, fromPlate, toPlate);
}

//Function to implement  puzzle
void movingCakeIterative(int num_of_disks, struct Stack
             *source, struct Stack *aux,
             struct Stack *dest){
    int i, total_num_of_moves;
    char s = 'S', d = 'G', a = 'B';//s-source,d-destination,a-auxiliary; S-silver, G-gold, B-bronze

    //If number of layers is even, then interchange
    //destination pole and auxiliary pole
    if (num_of_stories % 2 == 0){
        char temp = d;
        d = a;
        a  = temp;
    }
    total_num_of_moves = pow(2, num_of_stories) - 1;

    //Larger layer will be pushed first
    for (i = num_of_stories; i >= 1; i--)
        push(source, i);

    for (i = 1; i <= total_num_of_moves; i++){
        if (i % 3 == 1)
          moveLayersbetweenPlates(source, dest, s, d);

        else if (i % 3 == 2)
          moveLayersbetweenPlates(source, aux, s, a);

        else if (i % 3 == 0)
          moveLayersbetweenPlates(aux, dest, a, d);
    }
}

// Driver Program
int main(){
    // Input
    unsigned num_of_stories = 3;

    struct Stack *source, *dest, *aux;

    // Create three stacks of size 'num_of_stories'
    // to hold the layers
    source = createStack(num_of_stories);
    aux = createStack(num_of_stories);
    dest = createStack(num_of_stories);

    movingCakeIterative(num_of_stories, source, aux, dest);
    return 0;
}
