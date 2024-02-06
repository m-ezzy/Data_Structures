// 1 array, 1 stack
// as opposed to 1 array, many stacks
// program to create stack data structure
// and perform operations on that stack like inert, delete, check empty, check full, get value, change value
// pointers everywhere

#include <stdio.h>
#include <conio.h>

struct stack{
    int arr[50];
    int top_index;

    int lower_bound_index;
    int upper_bound_index;

    int top_address;
    int lower_bound_address;
    int upper_bound_address;
};

int is_empty(struct stack *s){
    if(s->top_index == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct stack *s){
    if(s->top_index == 50-1){
        return 1;
    }
    else{
        return 0;
    }
}

int get_index(){
    
}

int is_index_in_bound(){
    
}

int push(struct stack *s){ //used pointer here and it just worked!
    if(is_full(&s)){
        printf("\n push was not done. stack is full!");
        return 0;
    }
    else{
        int value;
        printf("\n enter the new element to insert : ");
        scanf("%d",&value);
        (*s).top_index++;
        (*s).arr[(*s).top_index] = value;
        printf("\n push was done!");
        return 1;
    }
}

int pop(struct stack *s){
    if(is_empty(&s)){
        printf("\n pop was not done. stack is empty!");
        return 0;
    }
    else{
        (s->top_index)--;
        printf("\n pop was done!");
        return 1;
    }
}

int peep(struct stack *s){
    if(is_empty(&s)){
        printf("\n peep was not done. stack is empty!");
        return 0;
    }
    else{
        printf("\n peep was done! %d %d",s->top_index,s->arr[s->top_index]);
        return 1;
    }
}

int peep_any(struct stack *s){
    if(is_empty(&s)){
        printf("\n peep_any was not done. stack is empty!");
        return NULL;
    }

    int index;
    printf("\n enter the index of the element to peep : ");
    scanf("%d",&index);

    if(index < 0){
        printf("\n peep_any was not done. index is less than 0!");
        return NULL;
    }
    else if(index > s->top_index){
        printf("\n peep_any was not done. index is more than top index!");
        return NULL;
    }
    else{
        printf("\n peep_any was done! %d %d",index,s->arr[index]);
        return 1;
    }
}

int peep_all(struct stack *s){
    if(is_empty(&s)){
        printf("\n peep_all was not done. stack is empty!");
        return 0;
    }
    for(int i = 0; i <= s->top_index; i++){
        printf("\n %d %d",i,s->arr[i]);
    }
    printf("\n peep_all was done!");
    return 1;
}

int change(struct stack *s){
    if(is_empty(&s)){
        printf("\n change was not done. stack is empty!");
        return NULL;
    }

    int index;
    printf("\n enter the index of the element to change : ");
    scanf("%d",&index);
    
    if(index < 0){
        printf("\n change was not done. index is less than 0!");
        return NULL;
    }
    else if(index > s->top_index){
        printf("\n change was not done. index is more than top index!");
        return NULL;
    }

    int value;
    printf("\n enter the new value : ");
    scanf("%d",&value);
    
    if(sizeof(int) != sizeof(value)){
        printf("\n change was not done. value type is different than array data type!");
        return NULL;
    }
    
    s->arr[index] = value;
    printf("change was done!");
    return 1;
}

/*
//to avoid using do...while use while loop with always true condition

//when we pass structure to a function it just gives access to it's values. raed-only or it creats a copy and sends it
//in any case thre original structure variables(object) values are not changed
//to overcome this use pointers. pointers point to the memory address of the original structure
//go pointer!!!

int main(){
    struct stack s1;
    struct stack s2;
    struct stack s3;

//there is no need to create pointer structures
//just pass normal structures in functions with & operator

    struct stack *p_s1;
    struct stack *p_s2;
    struct stack *p_s3;

    p_s1 = &s1;
    p_s2 = &s2;
    p_s3 = &s3;

    s1.top_index = -1;
    s2.top_index = -1;
    s3.top_index = -1;

//    struct stack *p_s1 = (struct stack *)malloc(sizeof(int)*51);

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

    while(option != 7){
        printf("\n 1 push \n 2 pop \n 3 peep \n 4 peep_any \n 5 peep_all \n 6 change \n 7 exit \n enter your option : ");
        scanf("%d",&option);

        //switch case can also be used here instead of else if statements
        //but i prefer else if statements over switch case's complicates and rarely used syntax
        //kinda like how i prefer while and for instead of do...while

        //i was putting & before all p_s1  when passing them to function
        //that was wrong. don't write & before structure pointer
        if(option == 1){
            completed = push(&s1);
        }
        else if(option == 2){
            completed = pop(p_s1);
        }
        else if(option == 3){
            completed = peep(p_s1);
        }
        else if(option == 4){
            completed = peep_any(p_s1);
        }
        else if(option == 5){
            completed = peep_all(p_s1);
        }
        else if(option == 6){
            completed = change(p_s1);
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
*/