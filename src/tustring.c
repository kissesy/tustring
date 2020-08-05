#include "tustring.h"

char* custom_strdup(char* s){
	size_t len = strlen(s) + 1;
	char* ret = (char*)malloc(len); 
	if(ret != NULL){
		strcpy(ret, s); 
	}
	return ret; 
}

char* custom_strdup0(char* s, size_t n){
	size_t i; 
	char* p = s;
	char* new; 
	for(i=0;i<n && *p; i++, p++){
		if(new){
			memcpy(new, s, i); 
			new[i] = '\0'; 
		}
	}
	return new; 
}

tustring* new_tustring(){
	
	tustring* tustr = (tustring*)malloc(sizeof(tustring)); 
	if(tustr == NULL) return NULL; 

	tustr->str = NULL; 
	tustr->len = 0; 
	tustr->set_tustring = fp_set_tustring; 
	tustr->get_index = fp_get_index; 
	tustr->add_tustring = fp_add_tustring;
	tustr->count = fp_count;
	tustr->get_tustring = fp_get_tustring; 
	return tustr; 
}


char* fp_get_tustring(struct tustring* this){
	return this->str; 
}

void fp_add_tustring(struct tustring* this, char* str){
	if(this->str == NULL){
		this->set_tustring(this, str); 
		return; 
	}else{
		char* tmp = custom_strdup(this->str); 
		this->str = (char*)realloc(this->str,this->len+strlen(str) + 1); // 1 is null space  
		strncpy(this->str, tmp, this->len);
		strncpy((this->str)+(this->len), str, strlen(str));
		this->len = this->len + strlen(str); 
		this->str[this->len] = '\0';
		free(tmp);
	}
}

void fp_set_tustring(struct tustring* this, char* str){
	if(str == NULL) return; 
	if(this->str != NULL){
		free(this->str); 
		this->str = NULL; 
		this->len = 0; 
	}
	this->len = strlen(str);
	this->str = custom_strdup(str);  
	return; 
}

ssize_t fp_count(struct tustring* this){
	if(this->str == NULL) return -1; 
	return this->len; 
}


ssize_t fp_get_index(struct tustring* this, char ch){
	char* p = this->str; 
	for(int i=0;i<this->len && *p;i++, p++){
		if(*p == ch){
			return i; 
		}
	}
	return -1;
}





































