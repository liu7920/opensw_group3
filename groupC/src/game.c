#include "common.h"

void game(){

	int str[2][4]={0};
	int i,o,q,w,num=0,temp;
	srand(time(NULL));

	for(i=0;i<2;i++){
		for(o=0;o<4;o++){
			num=0;
			temp=rand()%8+1;
			for(q=0;q<2;q++){
				for(w=0;w<4;w++){
					if(temp==str[q][w]){
						num++;
					}
					if(num==2){
						break;
					}
				}
				if(num==2){
					break;
				}
			}
			if(num>=2){

			}
			else{
				str[i][o]=temp;
			}

		}
	}

	return ;
}
