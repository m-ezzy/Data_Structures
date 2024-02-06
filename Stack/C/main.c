#include <stdio.h>
#include <conio.h>

#include "stack_def.h"

int is_empty(struct stack *s);
int is_full(struct stack *s);
int push(struct stack *s);
int pop(struct stack *s);
int peep(struct stack *s);
int peep_any(struct stack *s);
int peep_all(struct stack *s);
int change(struct stack *s);

int main(){
    struct stack s;
    s.top_index = -1;
    
    struct stack *p_s;

    p_s = &s;

    int option = 1;
    int completed;

    while(option != 7){
        printf("\n 1 push \n 2 pop \n 3 peep \n 4 peep_any \n 5 peep_all \n 6 change \n 7 exit \n enter your option : ");
        scanf("%d",&option);

        if(option == 1){
            completed = push(p_s);
        }
        else if(option == 2){
            completed = pop(p_s);
        }
        else if(option == 3){
            completed = peep(p_s);
        }
        else if(option == 4){
            completed = peep_any(p_s);
        }
        else if(option == 5){
            completed = peep_all(p_s);
        }
        else if(option == 6){
            completed = change(p_s);
        }
        else if(option == 7){
            break;
        }
        else{
            printf("\n wrong choice number!");
        }
    }

    getch();
    return 1;
}