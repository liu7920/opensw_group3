void menu(){

	int input;

	while(1){
		printf("1.로그인 2.회원가입 3.종료\n");
		printf("입력 : ");
		scanf("%d",&input);

		if(input==1){
			printf(">>로그인<<\n");
		}
		else if(input==2){
			printf(">>회원가입<<\n");
		}
		else if(input==3){
			printf(">>종료<<\n");
			break;
		}
		else{
			printf(">>잘못된 입력<<");
		}
	}
}
