#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	int ch1;
	while(1){
	printf("\nselect the choice 1.encrypt 2.decrypt 3.exit");
	scanf("%d",&ch1);
	char text[500],ch;
	int key,i,k;
	char text1[500],ch2;
	switch(ch1){
		case 1:
				printf("enter the text message:");
				scanf("%s",text);
				printf("enter the key:");
				scanf("%d",&key);
				for(i=0;text[i]!='\0';++i){
				ch=text[i];
				if(isalnum(ch)){
				if(islower(ch)){
				ch=(ch-'a'+key)%26+'a';
				}
				if(isupper(ch)){
				ch=(ch-'A'+key)%26+'A';
				}
				if(isdigit(ch)){
				ch=(ch-'0'+key)%10+'0';
				}
				}
				else{
				printf("enter valid message");
				}
				text[i]=ch;
				}
				printf("encrypted message is:%s",text);
				break;
		case 2:
		printf("enter the enncrypted message:");
		scanf("%s",text1);
		printf("enter the key:");
		scanf("%d",&k);
		for(i=0;text1[i]!='\0';++i){
			ch2=text1[i];
			if(isalnum(ch2)){
				if(islower(ch2)){
					ch2=(ch2-'a'-k+26)%26+'a';
				}
				if(isupper(ch2)){
					ch2=(ch2-'A'-k+26)%26+'A';
				}
				if(isdigit(ch2)){
					ch2=(ch2-'0'-k+10)%26+'0';
				}
			}
			else{
				printf("enter valid message");
			}
			text1[i]=ch2;
		}
		printf("decrypted message: %s",text1);
		break;
		case 3:
			exit(1);
		default:
			printf("select correct choice");
			break;
			
	}
}

}