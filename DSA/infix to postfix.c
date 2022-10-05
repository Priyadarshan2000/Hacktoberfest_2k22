#include<stdio.h>
#include<string.h>
#define max 100
struct Stack{
    char stack[max];
    int top;
} s = {{0},-1};//designated initialization

int isFull(){
    if(s.top == max - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(s.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char item){
    if(isFull()){
        return;
    }
    else{
        s.stack[++s.top] = item;
    }
}

char pop(){
    if(isEmpty()){
         return 0;
    }
    else{
        char ch = s.stack[s.top];
        s.top--;
        return ch;
    }
}


int inStackPriority(char ch){
    if(ch=='+'|| ch =='-')
        return 2;
    if(ch=='*'|| ch =='/')
        return 4;
    else
        return 5;
}

int inComingkPriority( char ch){
    if(ch=='+'|| ch =='-')
        return 1;
    if(ch=='*'|| ch =='/')
        return 3;
    else
        return 6;
}

void infixTopstfix(char *infix){
    printf("The infix expression: %s\n",infix);
    char symbol, postfix[max], ch;
    int index = 0, pos = 0;
    while(infix[index]!='\0'){
        symbol = infix[index];
        //printf("%c\t",symbol);
        switch (symbol){
            case '(':
                push(symbol);
            	break;

            case ')':
                ch = pop();
                //printf("%c",ch);
                while(ch!= '('){
				
                    postfix[pos++]= ch;
                    
                    //printf("%c", ch);
                    ch = pop();
            }
            
            break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':if(s.stack[s.top] == '+' || s.stack[s.top] == '-' || s.stack[s.top] == '*' || s.stack[s.top] == '/' || s.stack[s.top] == '^')
            		{
			
                while(s.stack[s.top] == '+' || s.stack[s.top] == '-' || s.stack[s.top] == '*' || s.stack[s.top] == '/' || s.stack[s.top] == '^')
				{
                   if(inComingkPriority(symbol) < inStackPriority(s.stack[s.top])){
                        ch = pop();
                        postfix[pos++] = ch;
                       // printf("%c", ch);

                    }
                
                   else
                   {
				    break;
                	}
                }
                push(symbol);
            }
                  else
				 push(symbol);     
            break;
            default:
                postfix[pos++]=symbol;
        }
        index++;
    }
    while(s.top!=-1){
       ch = pop();
       postfix[pos++] = ch;
      // printf("%c", ch);
    }
    postfix[pos] = '\0';
    printf("The postfix expression: %s\n", postfix);
}
int main(void){
    char exp[max];
    printf("Enter the infix expression(<=%d): ", max);
    gets(exp);
    printf("The given expression: %s\n", exp);
    infixTopstfix(exp);
    return 0;
}
