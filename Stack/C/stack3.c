/*program to create stack data structure, inert, delete, check empty, check full, get value, change value*/

#include <stdio.h>
#include <conio.h>

#define MAX 50

struct stack{
    int st[MAX];
    int top;
    int *top_add;
};

int is_empty(struct stack s){
    if(s.top <= 0){
        printf("e 1");
        return 1;
    }
    else{
        printf("e 0");
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
        printf("p 0");
        return 0;
    }
    else{
        printf("p 1");
        (s.top)--;
        return 1;
    }
}

int peep(struct stack s){
    if(is_empty(s)){
        return NULL;
    }
    else{
        return s.st[s.top];
    }
}

int peep_any(struct stack s, int index){
    if(is_empty(s)){
        return NULL;
    }
    else if(index <= 0){
        return NULL;
    }
    else if(index >= s.top + 1){
        return NULL;
    }
    else{
        return s.st[index];
    }
}

int peep_all(struct stack s){
    if(is_empty(s)){
        return NULL;
    }
    for(int i = 1; i <= s.top; i++){
        printf("\n %d",s.st[i]);
    }
    return 1;
}

int change(struct stack s, int index, int value){
    if(is_empty(s)){
        return NULL;
    }
    else if(index <= 0){
        return NULL;
    }
    else if(index >= s.top + 1){
        return NULL;
    }
    else if(sizeof(int) != sizeof(value)){
        return NULL;
    }
    else{
        return s.st[index];
    }
}

//to avoid using do...while use while loop with always true condition

int main(){
    struct stack s1;
    struct stack s2;
    struct stack s3;

    s1.top = 0;

    int option = 1;
    int completed;
    int index;
    int value;
//    int push_element; //value to be pushed
//    int peep_value; //top element value
//    int peep_any_index; //which index to fetch value of
//    int peep_any_value; //value of element at that index
//    int change_index;
//    int change_value; //value to replace

    while(option != 6){
        printf("\n 1 push \n 2 pop \n 3 peep \n 4 peep_any \n 5 peep_all \n 6 change \n 7 exit \n enter option : ");
        scanf("%d",&option);

        //switch case can also be used here instead of else if statements
        //but i prefer else if statements over switch case's complicates and rarely used syntax
        //kinda like how i prefer while and for instead of do...while

        if(option == 1){
            printf("\n enter the new element to insert : ");
            scanf("%d",&value);

            completed = push(s1, value);
            if(completed){
                printf("push was done!");
                printf("%d",s1.top);
            }
            else{
                printf("push was not done. stack is full!");
            }
        }
        else if(option == 2){
            printf("1");
            completed = pop(s1);
            printf("%d",completed);
            if(completed){
                printf("pop was done!");
            }
            else{
                printf("pop was not done. stack is empty!");
            }
        }
        else if(option == 3){
            completed = peep(s1);
            if(completed){
                printf("peep was done! value is %d",completed);
            }
            else{
                printf("peep was not done. stack is empty!");
            }
        }
        else if(option == 4){
            printf("\n enter the index of the element to peep : ");
            scanf("%d",&index);

            completed = peep_any(s1, index);
            if(completed){
                printf("peep_any was done!");
            }
            else{
                printf("peep_any was not done. stack is empty or index was not in range!");
            }
        }
        else if(option == 5){
            completed = peep_all(s1);
            if(completed){
                printf("peep_all was done!");
            }
            else{
                printf("peep_all was not done. stack is empty!");
            }
        }
        else if(option == 6){
            printf("\n enter the index of the element to change : ");
            scanf("%d",&index);

            printf("\n enter the new value : ");
            scanf("%d",&value);

            completed = change(s1, index, value);
            if(completed){
                printf("change was done!");
            }
            else{
                printf("change was not done. stack is empty or index was not in range or data type did not match!");
            }
        }
        else if(option == 7){
            break;
        }
        else{
            printf("wrong input!");
        }
    }

    getch();
    return 1;
}