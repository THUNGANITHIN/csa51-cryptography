#include<stdio.h>
#include<string.h>
char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
	    'y', 'e' }, { 'z', 'h' } };

char monoalphabetic(char a);

int main()
{
	char str1[10],str[10];
	printf("Enter the string:");
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
		str1[i]=monoalphabetic(str[i]);
	}
	printf("After Decryption:%s",str1);
}

char monoalphabetic(char a)
{
	int i;
	for(i=0;i<27;i++)
	{
		if(a==alpha[i][0])
		{
			break;
		}
	}
	return alpha[i][1];
}