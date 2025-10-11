#include "list.h"

int grow(List* l){
	size_t newSize;
	if(l->max_count == 0){
		newSize = sizeof(int);
		l->array = malloc(newSize);
		l->max_count ++;
		return 0;
	}
	else if(l->curr_count == l->max_count){
		int newSize = 2* l->max_count * sizeof(int);
		int* newArray = realloc(l->array, newSize);
		if(newArray == NULL){
			return 1;
		}
		l->array = newArray;
		l->max_count = l->max_count * 2;
	}
	return 0;
}

int shrink(List* l){


	if(l->curr_count < l->max_count/2){
		int *newArray = realloc(l->array, sizeof(int)*l->max_count/2);
		if(newArray == NULL){
			return 1;
		}
		l->max_count = l->max_count/2;
		l->array = newArray;
	}
	return 0;
}

int update(List* l, int loc, int data){
	
	
	if(l->curr_count < loc + 1){
		return 1;
	}
	
	l->array[loc] = data;
	return 0;
}

int delete(List* s, int loc){
	if(loc < s->curr_count){
		for(int k = loc; k < s->curr_count -1; k ++){
			s->array[k] = s->array[k+1];
		}
	}
		s->curr_count --;
		if (shrink(s)){
			return 1;
		}

		if(s->curr_count == 0){
			free(s->array);
			s->array = NULL;
			s->max_count = 0;
		}
		return 0;
	
}

int append(List* s, int data){

	
	if(grow(s)){
		return 1;
	}

	s->array[s->curr_count] = data;
	s->curr_count ++;
	return 0;
}

int insert(List* s, int loc, int data){
	if(grow(s)){
		return 1;
	}

	for(int k = s->curr_count; k >= loc; k --){
		s->array[k] = s->array[k-1];
	}
	s->curr_count ++;
	return update(s, loc, data);

}


