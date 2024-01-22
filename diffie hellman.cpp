#include<stdio.h>
#include<math.h>
long long int power(int a,int b,int q){
	if(b==1){
		return a;
	}
	else{
		return ((long long int)pow(a,b)%q);
	}
}
int main(){
	int q,g,x,y,a,b;
	printf("enter the value of q:");
	scanf("%d",&q);
	printf("enter the value of alpha:");
	scanf("%d",&g);
	printf("enter the value x for first person:");
	scanf("%d",&x);
	a=power(g,x,q);
	printf("enter the value y for second person:");
	scanf("%d",&y);
	b=power(g,y,q);
	long long int k1,k2;
	k1=power(b,x,q);
	k2=power(a,y,q);
	printf("key of first person is:%lld",k1);
	printf("\nkey of second person is:%lld",k2);
	
}