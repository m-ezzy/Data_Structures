/*program to create stack data structure, inert, delete, check empty, check full, get value, change value*/

#include <stdio.h>
#include <conio.h>

#define MAX 50

struct stack{
    int st[MAX];
    int top;
};

int is_empty(struct stack s){
    if(s.top <= 0){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct stack s){
    if(s.top >= MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack s, int new_element){
    if(is_full(s)){
        return 0;
    }
    else{
        s.top++;
        s.st[s.top] = new_element;
        return 1;
    }
}

int pop(struct stack s){
    if(is_empty(s)){
        return 0;
    }
    else{
        s.top--;
        return 1;
    }
}

void main(){
    struct stack s1;
    struct stack s2;
    struct stack s3;

    int new_element;
    int option;

    int completed;

    printf("\n 1 push \n 2 pop");
    scanf("%d",&option);

    if(option == 1){
        printf("enter the new element to be entered: ");
        scanf("%d",&new_element);

        completed = push(s1, new_element);
        if(completed){
            printf("push was done!");
        }
        else{
            printf("push was not done. stack is full");
        }
    }
    else{
        completed = pop(s1);
        if(completed){
            printf("pop was done!");
        }
        else{
            printf("pop was not done. stack is empty");
        }
    }

    getch();
}