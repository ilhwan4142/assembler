#include "myas.h"

int is_valid(char *op, char *args){
	int i = 0,eval=0;
	if(args[0] == '%'){
		while(args[i] != ',') i++;
		i++;
		if(args[i] == '%') eval = 1;
		else if(args[i] == '0') eval = 1;
		i = 0;
	}
	else if(args[0]=='('||args[0]=='-'||args[0]=='0'||args[0]=='$'){
		while(args[i] != ',') i++;
		i++;
		if(args[i] == '%') eval = 1;
	}
	return eval;
}
