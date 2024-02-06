/*creating program to create stack data structure, inert, delete, check empty, check full, get value, change value*/

#include <stdio.h>
#include <conio.h>

#define MAX 50

//some variables for stack
int max = 50;
int top = 0;
int *top_address = &top;

//creating a stack
int stack[MAX];

void push(int stack[], int new_element){
    top++;
    stack[top] = new_element;
}

int pop(int stack[]){
    top--;
    return stack[top + 1];
}

int is_empty(){
    if(top <= 0){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(){
    if(top >= MAX){
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    int new_element;
    int check;

    printf("enter the new element to be entered: ");
    scanf("%d",&new_element);

    check = is_full();

    if(check == 0){
        push(stack, new_element);
        printf("done!");
    }
    else{
        printf("stack is full");
    }
    getch();
}