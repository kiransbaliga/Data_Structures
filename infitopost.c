#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void push(long int symbol);
long int pop();
void convtopost();
int evalthepost();
int prio(char symbol);
int isnull();


char infix[50], postfix[50];
long int stack[50];
int top;

int main()
{
        long int value;
        top=-1;
        printf("Enter infix : ");
        gets(infix);
        convtopost();
        printf("Postfix : %s\n",postfix);
        value=evalthepost();
        printf("Value of expression : %ld\n",value);

        return 0;

}

void convtopost()
{
        int i,p=0;
        char next;
        char symbol;
        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                if(symbol!=' ')
                {
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        postfix[p++] = next;
                                break;
                        case '+':
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        case '-':   
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        case '*':
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        case '/':
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        case '%':
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        case '^':
                                while( !isnull( ) &&  prio(stack[top])>= prio(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        default: 
                             postfix[p++]=symbol;
                        }
                }
        }
        while(!isnull( ))
                postfix[p++]=pop();
        postfix[p]='\0'; 
}


int prio(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
                return 1;
        case '-':
                return 1;
        case '*':
                return 2;
        case '/':
                return 2;
        case '%':
                return 2;
        case '^':
                return 3;
        default :
                return 0;
        }
}

void push(long int symbol)
{
        if(top>50)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        top++;
        stack[top]=symbol;
}

long int pop()
{
        if( isnull() )
        {
                printf("____Cant continue___\n");
                exit(1);
        }
        return (stack[top--]);
}
int isnull()
{
        if(top==-1)
                return 1;
        else
                return 0;
}

int evalthepost()
{
        int a,b,temp,result;
        int i;

        for(i=0;i<strlen(postfix);i++)
        {
                if(postfix[i]<='9' && postfix[i]>='0')
                        push(postfix[i]-'0');
                else
                {
                        a=pop();
                        b=pop();
                        switch(postfix[i])
                        {
                        case '+':
                                temp=b+a; break;
                        case '-':
                                temp=b-a;break;
                        case '*':
                                temp=b*a;break;
                        case '/':
                                temp=b/a;break;
                        case '%':
                                temp=b%a;break;
                        case '^':
                                temp=pow(b,a);
                        }
                        push(temp);
                }
        }
        result=pop();
        return result;
        
}