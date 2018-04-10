#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[150]={0};
int len=0;
void push (char a){
    s[len]=a;
    len++;
}

char pop(){
    if (len<=0){
        return -10;
    }
    len--;
    return s[len];
}


int main(){
    int i=0;
    int flag=0;
    while (scanf("%s",s)!=EOF){
        while (s[i]!='\0'){
            switch(s[i]){
                case '{':
                case '[':
                case '(':
                       push(s[i]);
                       break;
                case '}':
                       if(pop()=='{'){
                           flag=1;
                       }else{
                           flag=0;
                       }
                       break;
                case ']':
                       if(pop()=='['){
                        flag=1;
                       }else{
                        flag=0;
                       }
                       break;
                case ')':
                       if(pop()=='('){
                        flag=1;
                       }else{
                        flag=0;
                       }
                        break;
            }
            i++;
        }
        while (len!=0){
            flag=0;
            pop();
        }
        if(flag==1){
            printf("True\n");
        }else{
            printf("False\n");
        }

    }
    return 0;
}