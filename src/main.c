#include "tustring.h"

int main(int argc, char* argv){

	tustring* tustr = new_tustring(); 
	tustr->set_tustring(tustr, "Hello World"); 
	printf("%s %ld\n", tustr->str, tustr->get_index(tustr, 'l'));	
	tustr->add_tustring(tustr, " Good!"); 
	printf("%ld\n", tustr->count(tustr));
	tustr->delete_tustring(tustr);
	free(tustr);
	return 0;
}
