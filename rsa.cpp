#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a,int b){
	while(a!=b){
		if(a>b){
			a-=b;
		}
		else{
			b-=a;
		}
	}
	return a;
}
int main(){
	int p,q,e=2;
	printf("enter the value of prime number p :");
	scanf("%d",&p);
	printf("enter the value of prime number q:");
	scanf("%d",&q);
	int n=p*q;
	int phi=(p-1)*(q-1);
	while(e<phi){
		if(gcd(e,phi)==1){
			break;
		}
		else{
			e++;
		}
	}
	int d=(1+(2*phi))/e;
	int msg;
	printf("enter the number to be encrypted:");
	scanf("%d",&msg);
	int power=pow(msg,e);
	int c=power%n;
	printf("encrypted message:%d",c);
	int power2=pow(c,d);
	int m=(power2)%n;
	printf("\ndecrypted messsage:%d",m);
}