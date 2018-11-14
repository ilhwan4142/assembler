#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	int i = 0;
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}

	if(args[0] == '%'){
		while (args[i] != ',') i++;
		i++;
		if(args[i] == '%') strcpy(mcode, "89");
		else strcpy(mcode, "a3");
		i=0;
	}
	else if(args[0] == '('||args[0] == '-') strcpy(mcode, "8b");
	else if(args[0] == '0')	strcpy(mcode, "a1");
	else if(args[0] == '$'){
		while(args[i] != ',') i++;
		i++;
		while(args[i] != '\0'){
			if(args[i] == 'a'){
				strcpy(mcode, "b8");
				i=0;
				break;
			}
			else if(args[i] == 'b'){
				i++;
				if(args[i] == 'p'){
					strcpy(mcode, "bd");
					i=0;
					break;
				}
				strcpy(mcode, "bb");
				i=0;
				break;
			}
			else if(args[i] == 'c'){
				strcpy(mcode, "b9");
				i=0;
				break;
			}
			else if(args[i] == 'd'){
				i++;
				if(args[i] == 'i'){
					strcpy(mcode, "bf");
					i=0;
					break;
				}
				strcpy(mcode, "ba");
				i=0;
				break;
			}
			else if(args[i] == 's'){
				i++;
				if(args[i] == 'p'){
					strcpy(mcode, "bc");
					i=0;
					break;
				}
				strcpy(mcode, "be");
				i=0;
				break;
			}
				
		i++;
	}
	
	return 1;	
}
