#include "list.h"
#include <stdlib.h>

int grow(List *l){
        if(l->array == NULL || l->max_count == 0){
                int* array = malloc(sizeof(int));
                if(array == NULL){
                        return 1;
                }

                l->curr_count = 0;
                l->max_count ++;
                l->array = array;
        }

        else if(l->max_count == l->curr_count){
                int* array = realloc(l->array , sizeof(int)*(l->max_count*2));
                if(array == NULL){
                        return 1;
                }

                l->array = array;
                l->max_count = l->max_count * 2; 
        }
        return 0;
}

int shrink(List *l){
        if(l -> max_count > 2* l->curr_count && (l->curr_count != 0)){
                int* array = realloc(l->array, sizeof(int)*(l->max_count /2));
                if(array == NULL){
                        return 1;
                } 
                l->array = array;
                l->max_count = l->max_count/2;
        }

        if(l->curr_count == 0){
                l->max_count = 0;
                l->curr_count = 0;
                free(l->array);
                l->array=  NULL;
        }
        return 0;
}

int update(List *l, int loc, int data){
        if(l == NULL || l->array == NULL || loc >= l->curr_count){
                return 1;
        }
        
        l->array[loc] = data;
        return 0;

}

int delete(List* l, int loc){
        if(l == NULL || l->array == NULL || loc >= l->curr_count){
                return 1;
        }

        for(int i = loc; i < l->curr_count - 1; i ++){
                l->array[i] = l->array[i+1];
        }
        l->curr_count -- ;
        return shrink(l);
}

int append(List *s, int data){
        if(grow(s)){
                return 1;
        }
        
        s->array[s->curr_count] = data;
        s->curr_count ++;
        return 0;
}

int insert(List *s, int loc, int data){
        if(loc > s->curr_count){
                return 1;
        }

        if(grow(s)){
                return 1;
        }

        for(int i = s->curr_count - 1; i >= loc; i --){
                s->array[i+1] = s->array[i];
        }

        s->array[loc] = data;
        s->curr_count ++;
        return 0;
}


