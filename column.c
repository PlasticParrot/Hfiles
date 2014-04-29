#include <stdio.h>
#include <stdlib.h>
#include <math.h.>

typedef struct column{
	char** strings;
	double* doubles;
	int* values;
	char type[2];
	double size;
}Column;

Column *make_double_column(double *fields, unsigned int *classes, unsigned int n){
	Column* c = (Column*)malloc(sizeof(column));
	c->doubles = (doubles*)malloc(sizeof(double));
	c->values = (int*)malloc(sizeof(int));
	c->type[0] = 'D';
	c->type[1] = '\0';
	c->size = n;
	for (int i = 0; i < n; i++){
		c->doubles[i] = fields[i];
		c->values[i] = classes[i];
	}
}

Column *make_string_column(char **fields, unsigned int *classes, unsigned int n){
	Column* c = (Column*)malloc(sizeof(column));
	c->strings = (char**)malloc(sizeof(char));
	c->values = (int*)malloc(sizeof(int));
	c->type[0] = 'S';
	c->type[1] = '\0';
	c->size = n;
	for (int i = 0; i < n; i++){
		c->strings[i] = fields[i];
		c->values[i] = classes[i];
	}
}

void free_column(Column *column){

}

int has_single_value(Column *column){
	if (strcmp(column->type,"S") == 0){
		for (int i = 0; i < column->size; i++){
			for (int j = 0; j < column->size; j++){
				if (strcmp(column->strings[i],column->strings[j]) != 0){
					return 0;
				}
			}
		}
	}
	if (strcmp(column->type, "D") == 0){
		for (int i = 0; i < column->size; i++){
			for (int j = 0; j < column->size; j++){
				if (column->doubles[i] != column->doubles[j]){
					return 0;
				}
			}
		}
	}
	return 1;
}

int is_impossible_split(Column *column){
	for (int i = 0; i < column->size; i++){
		for (int j = 0; j < column->size; j++){
			if (column->values[i] != column->values[j]){
				return 0;
			}
		}
	}
	return 1;
}

double calc_Pi(Column *column, int m, int pos){
	double final = 0;
	double ni = 0;
	for (int i = 0; i < m; ++i){
		if (column->values[i] == pos){
			ni++;
		}
	}
	if (ni == 0){
		return 0;
	}
	int pi = 0;
	else { 
		pi = (ni/column->size);
	}
	final = pi * (log(pi)/log(2));
	return final;
}

double calc_entropy(Column *column){
	double entropy = 0;
	int m = 0;
	for (int c = 0; c < column->size; c++){
		if (column->values[c] > m){
			m = column->values[c];
		}
	}
	for (int p = 0; p < column->size; p++){
		entropy += calc_Pi(column, m, p);
	}
	entropy = entropy * -1;
	return entropy;
}

double find_double_split_value(Column *column){

}

char *find_string_split_value(Column *column){

}