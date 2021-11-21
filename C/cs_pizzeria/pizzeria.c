//
// Assignment 2 21T3 COMP1511: CS Pizzeria
// pizzeria.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// TODO: INSERT-DESCRIPTION-HERE
//
// Version 1.0.0: Release

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: add any extra #includes your code needs here.

#include "pizzeria.h"
#include "save_string.h"

// TODO: add your own #defines here.

struct ingredient {
    // TODO: add your own fields in Stage 2.
    char ingredient_name[MAX_STR_LENGTH];
    int amount;
    double price;
    struct ingredient *next;
};

struct order {
    // TODO: add your own fields in Stage 1.
    // Looking to store a price field? Try putting in "double price;" here!
    char customer[MAX_STR_LENGTH];
    char pizza_name[MAX_STR_LENGTH];
    double price;
    int time_allowed;
    struct order *next;
    struct ingredient *ingredients;
};

struct pizzeria {
    // TODO: add your own fields if required.
    struct ingredient *stock;
    struct order *selected;
    struct order *orders;
};

// TODO: add any other structs you define here.

//////////////////////////////////////////////////////////////////////

// TODO: add prototypes for any helper functions you create here.

// Prints a single order
void print_order(
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
);

// Prints an ingredient given the name, amount and price in the required format.
// This will be needed for stage 2.
void print_ingredient(char *name, int amount, double price);

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////


struct pizzeria *create_pizzeria() {
    // Allocates memory to store a `struct pizzeria` and returns a pointer to
    // it. The variable `new` holds this pointer!
    struct pizzeria *new = malloc(sizeof(struct pizzeria));

    new->orders = NULL;
    new->selected = NULL;
    new->stock = NULL;
    // TODO: this function has already been implemented for the current
    // struct pizzeria. When you decide to change struct pizzeria, change
    // this function as well.

    return new;
}

int add_order(
    struct pizzeria *pizzeria,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
) {
    // TODO: fill in the rest of this function
    if(price < 0.0){
        return INVALID_PRICE;
    }else if(time_allowed <= 0){
        return INVALID_TIME;
    }
    struct order *p = pizzeria->orders;
    if(pizzeria->orders == NULL){
        pizzeria->orders = malloc(sizeof(struct order));
        strcpy(pizzeria->orders->customer, customer);
        strcpy(pizzeria->orders->pizza_name, pizza_name);
        pizzeria->orders->price = price;
        pizzeria->orders->time_allowed = time_allowed;
        pizzeria->orders->next = NULL;
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = malloc(sizeof(struct order));
        p = p->next;
        strcpy(p->customer, customer);
        strcpy(p->pizza_name, pizza_name);
        p->price = price;
        p->time_allowed = time_allowed;
        p->next = NULL;
    }
    return SUCCESS;
}

void print_all_orders(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function
    struct order *p = pizzeria->orders;
    unsigned int cnt = 1;
    while(p != NULL){
        printf("%02d: %s ordered a %s pizza ($%.2lf) due in %d minutes.\n",cnt, p->customer,p->pizza_name,p->price,p->time_allowed);
        cnt++;
        p = p->next;
    }
    // Do not change this part of the function
    print_selected_order(pizzeria);
    return;
}

int next_deadline(struct pizzeria *pizzeria) {
    
    // TODO: fill in the rest of this function
    unsigned int min;
    struct order *p = pizzeria->orders;
    if(pizzeria->orders != NULL){
        min = pizzeria->orders->time_allowed;
        while(p->next != NULL){
            p = p->next;
            if(p->time_allowed < min)
                min = p->time_allowed;
        }
    }

    return min;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////


void select_next_order(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function
    if(pizzeria->selected == NULL){
        pizzeria->selected = pizzeria->orders;
    }else{
        if(pizzeria->selected->next != NULL){
            pizzeria->selected = pizzeria->selected->next;
        }else{
            pizzeria->selected = NULL;
        }
    }
    return;
}

void select_previous_order(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function
    struct order *p = pizzeria->orders;
    if(pizzeria->selected == NULL && pizzeria->orders != NULL){
        pizzeria->selected = pizzeria->orders;
        while(pizzeria->selected->next != NULL){
            pizzeria->selected = pizzeria->selected->next;
        }
    }else{
        if(p == NULL){
            pizzeria->selected = NULL;
        }else{
            if(pizzeria->selected == pizzeria->orders){
                pizzeria->selected = NULL;
            }else{
                while(p->next != pizzeria->selected){
                    p = p->next;
                }
                pizzeria->selected = p;
            }
        }
    }
    return;
}

void print_selected_order(struct pizzeria *pizzeria) {

    // TODO: Change this once you have implemented the selected order
    // functionality.
    
    if(pizzeria->selected != NULL){
        printf("\nThe selected order is %s's %s pizza ($%.2lf) due in %d minutes.\n", pizzeria->selected->customer, pizzeria->selected->pizza_name, pizzeria->selected->price, pizzeria->selected->time_allowed);
        if(pizzeria->selected->ingredients != NULL){
            struct ingredient *p = pizzeria->selected->ingredients;
            while(p != NULL){
                print_ingredient(p->ingredient_name,p->amount,p->price);
                p = p->next;
            }
        }
    }else{
        printf("\nNo selected order.\n");
    }
}

int add_ingredient(
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price
) {
    int flag = 0;
    if(pizzeria->selected == NULL){
        return INVALID_ORDER;
    }else if(price < 0.0){
        return INVALID_PRICE;
    }else if(amount <= 0){
        return INVALID_AMOUNT;
    }
    // struct pizzeria
    if(pizzeria->selected->ingredients == NULL){
        pizzeria->selected->ingredients = malloc(sizeof(struct ingredient));
        strcpy(pizzeria->selected->ingredients->ingredient_name,ingredient_name);
        pizzeria->selected->ingredients->amount = amount;
        pizzeria->selected->ingredients->price = price;
        pizzeria->selected->ingredients->next = NULL;
    }else{
        struct ingredient *p1 = pizzeria->selected->ingredients;
        if(!strcmp(pizzeria->selected->ingredients->ingredient_name, ingredient_name)){
            p1->amount += amount;
            flag = 1;
        }
        while(p1->next != NULL){
            p1 = p1->next;
            if(!strcmp(p1->ingredient_name, ingredient_name)){
                p1->amount += amount;
                flag = 1;
                break;
            }
        }
        if(!flag){
            p1->next = malloc(sizeof(struct ingredient));
            p1 = p1->next;
            strcpy(p1->ingredient_name, ingredient_name);
            p1->amount = amount;
            p1->price = price;
            p1->next = NULL;
        }
    }
    struct ingredient *tmp = malloc(sizeof(struct ingredient));
    for(struct ingredient *i = pizzeria->selected->ingredients; i!=NULL; i=i->next){
        for(struct ingredient *j = i->next; j!=NULL; j=j->next){
            if(strcmp(i->ingredient_name, j->ingredient_name)>0){
                tmp->amount = j->amount;
                tmp->price = j->price;
                strcpy(tmp->ingredient_name, j->ingredient_name);
                j->amount = i->amount;
                j->price = i->price;
                strcpy(j->ingredient_name, i->ingredient_name);
                i->amount = tmp->amount;
                i->price = tmp->price;
                strcpy(i->ingredient_name, tmp->ingredient_name);
            }
        }
    }

    return SUCCESS;
}

double calculate_total_profit(struct pizzeria *pizzeria) {
    // TODO: fill in the rest of this function
    double sum = 0.0;
    if(pizzeria->selected == NULL || pizzeria->selected->ingredients == NULL)
        return INVALID_ORDER;
    struct ingredient *p = pizzeria->selected->ingredients;
    while(p != NULL){
        sum +=  (p->amount * p->price);
        p = p->next;
    }
    
    return pizzeria->selected->price - sum;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////


int cancel_order(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function

    struct ingredient *p;
    struct order *prev;
    struct order *tmp;

    if(pizzeria->selected == NULL || pizzeria->orders == NULL){
        return INVALID_ORDER;
    }
    p = pizzeria->selected->ingredients;
    prev = pizzeria->orders;
    while(p != NULL){
        free(p);
        p = p->next;
    }
    if(pizzeria->orders == pizzeria->selected){
        tmp = pizzeria->selected;
        pizzeria->orders = pizzeria->selected->next;
        pizzeria->selected = pizzeria->selected->next;
        free(tmp);
    }else{
        while(prev != NULL){
            if(prev->next == pizzeria->selected){
                if(pizzeria->selected->next == NULL){
                    tmp = pizzeria->selected;
                    pizzeria->selected = NULL;
                    prev->next = NULL;
                    free(tmp);
                    break;
                }else{
                    tmp = pizzeria->selected;
                    prev->next = pizzeria->selected->next;
                    pizzeria->selected = pizzeria->selected->next;
                    free(tmp);
                    break;
                }
            }
            prev = prev->next;
        }
    }

    return SUCCESS;
}

void free_pizzeria(struct pizzeria *pizzeria) {
    // TODO: fill in the rest of this function
    struct order *p;
    struct order *p_tmp;
    struct ingredient *p1;
    struct ingredient *p1_tmp;
    struct ingredient *p2;
    struct ingredient *p2_tmp;

    if(pizzeria->orders != NULL){
        p = pizzeria->orders;
        while(p != NULL){
            if(p->ingredients != NULL){
                p1 = p->ingredients;
                while(p1 != NULL){
                    p1_tmp = p1;
                    p1 = p1->next;
                    free(p1_tmp);
                }
            }
            p_tmp = p;
            p = p->next;
            free(p_tmp);
        }
    }
    if(pizzeria->stock != NULL){
        p2 = pizzeria->stock;
        while(p2 != NULL){
            p2_tmp = p2;
            p2 = p2->next;
            free(p2_tmp);
        }
    }

    free(pizzeria);

    return;
}

int refill_stock(
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price
) {

    // TODO: fill in the rest of this function

    struct ingredient *p;
    int flag = 0;

    if(price < 0.0){
        return INVALID_PRICE;
    }else if(amount <= 0){
        return INVALID_AMOUNT;
    }
    if(pizzeria->stock == NULL){
        pizzeria->stock = (struct ingredient *)malloc(sizeof(struct ingredient));
        strcpy(pizzeria->stock->ingredient_name, ingredient_name);
        pizzeria->stock->amount = amount;
        pizzeria->stock->price = price;
        pizzeria->stock->next = NULL;
    }else{
        p = pizzeria->stock;
        if(!strcmp(pizzeria->stock->ingredient_name, ingredient_name)){
            pizzeria->stock->amount += amount;
        }
        while(p->next != NULL){
            p = p->next;
            if(!strcmp(p->ingredient_name, ingredient_name)){
                p->amount += amount;
                flag = 1;
                break;
            }
        }
        if(!flag){
            p->next = (struct ingredient *)malloc(sizeof(struct ingredient));
            p = p->next;
            strcpy(p->ingredient_name, ingredient_name);
            p->amount = amount;
            p->price = price;
            p->next = NULL;
        }
    }

    struct ingredient *tmp = malloc(sizeof(struct ingredient));
    for(struct ingredient *i = pizzeria->stock; i!=NULL; i=i->next){
        for(struct ingredient *j = i->next; j!=NULL; j=j->next){
            if(strcmp(i->ingredient_name, j->ingredient_name)>0){
                tmp->amount = j->amount;
                tmp->price = j->price;
                strcpy(tmp->ingredient_name, j->ingredient_name);
                j->amount = i->amount;
                j->price = i->price;
                strcpy(j->ingredient_name, i->ingredient_name);
                i->amount = tmp->amount;
                i->price = tmp->price;
                strcpy(i->ingredient_name, tmp->ingredient_name);
            }
        }
    }

    return SUCCESS;
}

void print_stock(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function
    struct ingredient *p;
    if(pizzeria->stock != NULL){
        p = pizzeria->stock;
        printf("The stock contains:\n");
        while(p != NULL){
            print_ingredient(p->ingredient_name,p->amount,p->price);
            p = p->next;
        }
    }else{
        printf("\nNo selected stock.\n");
    }

    return;
}

int can_complete_order(struct pizzeria *pizzeria) {

    // TODO: fill in the rest of this function
    if(pizzeria->selected == NULL || pizzeria->selected->ingredients == NULL){ // pizzeria->stock == NULL?
        return INVALID_ORDER;
    }

    int flag = 0;
    for(struct ingredient *i = pizzeria->selected->ingredients; i!=NULL; i=i->next){
        for(struct ingredient *j = pizzeria->stock; j!=NULL; j=j->next){
            if(!strcmp(i->ingredient_name,j->ingredient_name)){
                if(j->amount - i->amount >= 0){
                    break;
                }else{
                    flag = 1;
                }
            }
        }
    }
    if(flag){
        return INSUFFICIENT_STOCK;
    }

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

int complete_order(struct pizzeria *pizzeria) {
    int can_complete_result = can_complete_order(pizzeria);
    if(can_complete_result == INVALID_ORDER){
        return INVALID_ORDER;
    }else if(can_complete_result == INSUFFICIENT_STOCK){
        return INSUFFICIENT_STOCK;
    }

    for(struct ingredient *i = pizzeria->selected->ingredients; i!=NULL; i=i->next){
        for(struct ingredient *j = pizzeria->stock; j!=NULL; j=j->next){
            if(!strcmp(i->ingredient_name,j->ingredient_name)){
                j->amount -= i->amount;
                break;
            }
        }
    }
    cancel_order(pizzeria);

    struct ingredient *p = pizzeria->stock;
    struct ingredient *prev;
    struct ingredient *tmp;
    if(pizzeria->stock->amount == 0){
        tmp = pizzeria->stock;
        pizzeria->stock = pizzeria->stock->next;
        free(tmp);
    }else{
        while(p != NULL){
            if(p->amount == 0){
                if(p->next == NULL){
                    tmp = p;
                    prev->next = NULL;
                    free(tmp);
                }else{
                    tmp = p;
                    prev->next = p->next;
                    free(tmp);
                }
            }
            prev = p;
            p = p->next;
        }
    }

    return SUCCESS;
}

int save_ingredients(struct pizzeria *pizzeria, char *file_name) {
    // sprintf
    if(pizzeria->selected == NULL){
        return INVALID_ORDER;
    }
    return SUCCESS;
}

int load_ingredients(struct pizzeria *pizzeria, char *file_name) {
    // sscanf
    if(pizzeria->selected == NULL){
        return INVALID_ORDER;
    }
    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
//               HELPER FUNCTIONS - Add your own here                 //
////////////////////////////////////////////////////////////////////////

// Prints a single order
//
// `print_order` will be given the parameters:
// - `num` -- the integer that represents which order it is sequentially.
// - `customer` -- the name of the customer for that order.
// - `pizza_name` -- the pizza the customer ordered.
// - `price` -- the price the customer is paying for the pizza.
// - `time_allowed` -- the time the customer will wait for the order.
//
// `print_order` assumes all parameters are valid.
//
// `print_order` returns nothing.
//
// This will be needed for Stage 1.
void print_order(
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed
) {

    printf("%02d: %s ordered a %s pizza ($%.2lf) due in %d minutes.\n",
        num, customer, pizza_name, price, time_allowed);

    return;
}

// Prints a single ingredient
//
// `print_ingredient` will be given the parameters:
// - `name` -- the string which contains the ingredient's name.
// - `amount` -- how many of the ingredient we either need or have.
// - `price` -- the price the ingredient costs.
//
// `print_ingredient` assumes all parameters are valid.
//
// `print_ingredient` returns nothing.
//
// This will be needed for Stage 2.
void print_ingredient(char *name, int amount, double price) {
    printf("    %s: %d @ $%.2lf\n", name, amount, price);
}
