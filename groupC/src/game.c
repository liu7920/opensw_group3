#include "common.h"

void game(){

	int str[4][4]={0};
	int str_temp[4][4];
	int i,o,q,w,num=0,temp;
	int x,y,_x,_y,_count;
	srand(time(NULL));

	for(i=0;i<4;i++){
		for(o=0;o<4;o++){
			str_temp[i][o]=0;	
		}
	}

	for(i=0;i<4;i++){
		for(o=0;o<4;o++){
			num=0;
			temp=rand()%8+1;
			for(q=0;q<4;q++){
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
				if(o==0){
					o=3;
					i=i-1;
				}
				else{
					o=o-1;
				}
			}
			else{
				str[i][o]=temp;
			}

		}
	}

	for(i=0;i<4;i++){
		for(o=0;o<4;o++){
			printf("%d ",str[i][o]);
		}
		printf("\n");
	}

	while(1){
		_count=0;
		system("clear");
		while(1){
			for(i=0;i<4;i++){
				for(o=0;o<4;o++){
					printf("%d ",str_temp[i][o]);
				}
				printf("\n");
			}
			printf("행 입력 : ");
			scanf("%d",&x);
			printf("열 입력 : ");
			scanf("%d",&y);
			
			if((x>=1&&x<=4)	&& (y>=1&&y<=4)){		
				if(str_temp[x-1][y-1]!=0){
					printf("입력 된 공간\n");
					printf("다시 입력\n");	
					sleep(1);
					system("clear");
				}
				else{
					break;
				}
			}
			else{
				printf("범위를 넘어감\n");
				printf("다시 입력\n");
				sleep(1);
				system("clear");
			}
		}
		str_temp[x-1][y-1]=str[x-1][y-1];

		system("clear");
		while(1){
			for(i=0;i<4;i++){
				for(o=0;o<4;o++){
					printf("%d ",str_temp[i][o]);
				}
				printf("\n");
			}
		
			printf("행 입력 : ");
			scanf("%d",&_x);
			printf("열 입력 : ");
			scanf("%d",&_y);
			if((x>=1&&x<=4)	&& (y>=1&&y<=4)){
				if(str_temp[_x-1][_y-1]!=0){
					printf("입력 된 공간\n");
					printf("다시 입력\n");	
					sleep(1);
				}
				else{
					break;
				}
			}
			else{
				printf("범위를 넘어감\n");
				printf("다시 입력\n");
				sleep(1);
				system("clear");
			}
		}

		str_temp[_x-1][_y-1]=str[_x-1][_y-1];

		system("clear");

		for(i=0;i<4;i++){
			for(o=0;o<4;o++){
				printf("%d ",str_temp[i][o]);
			}
			printf("\n");
		}

		sleep(3);
		system("clear");

		if(str_temp[x-1][y-1] != str_temp[_x-1][_y-1]){
			str_temp[x-1][y-1]=0;
			str_temp[_x-1][_y-1]=0;
		}

		for(i=0;i<4;i++){
			for(o=0;o<4;o++){
				if(str_temp[i][o]==0){
					_count++;
				}
			}
		}
		
		if(_count==0){
			break;
		}
	}


	return ;
}
