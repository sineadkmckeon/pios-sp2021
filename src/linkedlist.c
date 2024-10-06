#include <stdio.h>
struct list_element {
    struct list_element* next;
    int data;
};


struct list_element c = { NULL, 30 } ; // n e x t p t r i s NULL, end o f l i s t
struct list_element b = { &c , 20 } ; // n e x t p t r p o i n t s t o c
struct list_element a = { &b , 10 } ; // n e x t p t r p o i n t s t o a
struct list_element* head = &a ;

void print_list(struct list_element* node) {
//    printf("Start \n");
    while (node!=NULL){
 //       printf("number %d\n", node->data);
        node = node->next;
    }
//    printf("End \n");
}

void list_add(struct list_element** list_head, struct list_element* new_element, int position){
    if (position < 1){
//        printf("less than 1\n");
        return;
    }
    
    struct list_element* current = *list_head;
    struct list_element* previous = NULL;
    int i = 1;
    
    while (i < position && current != NULL){  //keeps going until position is the same as current
        previous = current;
        current = current->next;
        i++;
    }
    
    if(position ==1){ //if position inputted is 1 replace head and push back head to next element in linkedlist
        new_element->next = *list_head;
        *list_head = new_element;
    }
    
    else if (previous != NULL){  //if there's no pointer for the previous element then set current element to the next one
        previous->next = new_element;
        new_element->next = current;
    }
    
}


int main(){
    struct list_element tests = {NULL, 5};
        
    list_add(&head, &tests, 2);
    
    print_list(head);
    return 0;
}
