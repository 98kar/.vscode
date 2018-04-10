#include"stdio.h"
#include"string.h"
char arry[100]={0};
int len=0;
void push(char m){
	arry[len] = m;
	len++;
}
char pop() {
	if (len == 0) {
		return 0;
	}
	else {
		len--;
		return arry[len];
	}
}
void doit(char a[]) {
	int flag=1;
	for (int i = 0; i < strlen(a); i++){
		if (a[i] == ')') {
			if (pop() != '(') {
				flag = 0;
				
			}
		}
		else if (a[i] == ']') {
			if (pop() != '[') {
				flag=0;
				
				}
			}
		else if (a[i] == '}') {
			if (pop() != '{') {
				flag=0;
			
				}
		}
		else {
			push(a[i]);
		}	
	}
	while (len != 0)
	{
		flag = 0;
		pop();
	}
	if (flag)
		printf("True\n");
	else
		printf("False\n");
}
int main(){
	char b[100] = { 0 };
	while (scanf("%s", b) != EOF)
	{
		doit(b);
	}
	return 0;
}
