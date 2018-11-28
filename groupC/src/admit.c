#include "common.h"
#include "dbconn.h"

void admit_menu(){

	int i;
	char str[20],_str[200];

	while(1){
		printf("1.공지사항 수정 2.회원 데이터 초기화 3.관리자 비밀번호 변경 4.로그아웃\n");
		printf("입력 : ");
		scanf("%d",&i);
		if(i==1){
			while(1){
				system("clear");
				printf(">>공지사항 수정<<\n");
				print_Notice_admin();
				printf("1.추가 2.삭제 3.취소\n");
				scanf("%d",&i);
				if(i==1){
					printf("공지사항 추가 할 내용 입력 : ");
					strcpy(_str," ");
					scanf("%s",_str);
					insert_Notice(_str);
				}
				else if(i==2){
					char num[10]="";
					printf("삭제할 공지사항 번호 입력 : ");
					scanf("%s",num);
					delete_Notice(num);
					//번호에 해당하는 게시판 삭제
				}
				else if(i==3){
					printf("취소\n");
					break;
				}
				else{
					printf("잘못된 입력\n");
				}
			}
		}
		else if(i==2){
			system("clear");
			printf(">>회원 랭킹 데이터 초기화<<\n");
			printf("랭킹 초기화 할 아이디 입력 : ");
			strcpy(str," ");
			scanf("%s",str);
			
			if(!str_check(str)){
				user_ClTime_clear(str);
			}
			else{
				printf("일치하는 ID가 없습니다.\n");
			}
			//if(/*str == id(db)*/){
				//랭킹 초기화 
			//}
			/*else{
				printf("아이디 입력 실패 \n");
			}*/
			//랭킹 초기화
		}
		else if(i==3){
			system("clear");
			printf(">>관리자 비밀번호 변경<<\n");
			printf("비밀번호 입력 : ");
			strcpy(str," ");
			scanf("%s",str);
			modifiy_admin(str);
		}
		else if(i==4){
			printf(">>로그아웃<<\n");
			sleep(1);
			system("clear");
			break;
		}
	}
}
