#ifndef _Tu_H_
#define _Tu_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

enum types{
	String,
	Integer, 
	Double, 
	Float, 
	Char,
   	End	
};

#define get_type(x) _Generic((x), \
char: Char, char *: String, int: Integer, double: Double, float: Float )


typedef struct tustring{
	char* str; 
	size_t len; 
	void (*set_tustring)(struct tustring* , char* ); 
	ssize_t (*get_index)(struct tustring*, char ); 
	void (*add_tustring)(struct tustring*, char* );
	ssize_t (*count)(struct tustring* ); 
	char* (*get_tustring)(struct tustring* ); 

}tustring; 

tustring* new_tustring(); 
void fp_set_tustring(struct tustring* this, char* str); 
ssize_t fp_get_index(struct tustring* this, char ch); 
void fp_add_tustring(struct tustring* this, char* str); 
ssize_t fp_count(struct tustring* this); 
char* fp_get_tustring(struct tustring* this); 

char* custom_strdup(char* s); 
char* custom_strdup0(char* s, size_t n); 

#endif 
