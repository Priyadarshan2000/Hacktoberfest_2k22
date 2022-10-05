/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define size 5
struct stack {
    int s[size];
    int top;
}st;
int stackFull()
{
    if(st.top>=size-1)
    return 1;
    else
    return 0;
}
int stackEmpty()
{
    if(st.top==-1)
    return 1;
    else
    return 0;
}
void push(int item)
{
    st.top++;
    st.s[st.top]=item;
}
int pop()
{
    int item;
    item=st.s[st.top];
    st.top--;
    return(item);
}
void display()
{
    int i;
    if(stackEmpty())
    printf("\nstack is empty!");
    else
    {
        printf("\nElements of stack:");
        for(i=st.top;i>=0;i--)
        printf(" %d",st.s[i]);
    }
}
void main()
{
    int item,ch;
    st.top=-1;
    printf("\n Stack Implementation");
    do 
    {
        printf("\n\n Main Menu");
        printf("\n 1:PUSH");
        printf("\n 2:Pop");
        printf("\n 3:Display");
        printf("n 4:Exit");
        
        printf("\n Select Operation: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n Enter the item to be pushed:");
            scanf("%d",&item);
             if(stackFull())
             printf("\n Stack overflow");
             else
             push(item);
             
            break;
            
            case 2:
            if(stackEmpty())
            printf("\n Stack is Empty");
            else
            {
                item=pop();
                printf("\n The popped element is %d",item);
            }
            break;
            case 3:display();
                    break;
            case 4:
            printf("end of program");
            
        }    
    }while(ch!=4);
}