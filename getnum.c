//Eva Fineberg 

#include "getnum.h"
#include <ctype.h>

int negFlag=1;
int isValid=0;
int isEOF=1;

void scoot(){
    int ch = getchar();
    while(!isspace(ch)){
	ch = getchar();
    }

}



long getnum(){
	negFlag=1;
	isValid=0;	
	int ch = getchar();
	while(isspace(ch)){
	    ch=getchar();
	}
	long num = 0; 
	if(ch==EOF){
	    return ch;
	}
	if(ch=='-'){
		negFlag=-1;
		ch = getchar();
	}
	if(isdigit(ch)){
		if(ch=='0'){	
			ch = getchar();
			if((!isdigit(ch) && !isalpha(ch)) || isspace(ch)){
				return 0;
			}
			if(ch=='b'){
				while(!isspace(ch=getchar())){
					//binary to decimal.
					if(ch=='0'){
						num=num*2;
					}
					else if(ch=='1'){
						num=num*2+1;
					}
					else{
						if(isspace(ch=getchar())){
							isValid=1;}
						else{
						isValid=1;}
					}	

				}

				return num; 
			} //Octal conversion to decimal

			else if(ch!='8' && ch!='9' && isdigit(ch)){

				num=ch-'0';
				while(!(isspace(ch=getchar()))){
					if(ch != '8' && ch!= '9' && isdigit(ch)){
						num=num*8;
						num=num+(ch-'0');
					}
					else{	
						isValid=1;



					}
				}
				return num;
			} //Hex conversion to decmial
			else if(ch=='x'){
				while(!isspace(ch=getchar())){
					if(isdigit(ch)){
						num=num*16;
						num=num+(ch-'0');
					}
					else if((ch >= 'A' && ch <='F')){
						num=num*16;
						num=num+(ch-'A');
						num=num+10;
					}

					else if((ch >= 'a' && ch <='f')){
						num=num*16;
						num=num+(ch-'a');
						num=num+10;
					}
					else{
						isValid=1;
					}

				}
				return num;
			}
			else{
				isValid=1;
			}
		}

		//Decimal conversion
		//at this poin we have the first char after the - if there is one
		else{
			num=(ch-'0');
			while(!isspace(ch=getchar())){
				if(isdigit(ch)){
					num=num*10;
					num=num+(ch-'0');
				}
				else{
					isValid=1;

				}
			}
			return num;
		}
	}
	else{
		isValid=1;
	}
	return num;
}
    

    
