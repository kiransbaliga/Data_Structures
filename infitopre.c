#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void push(long int symbol);
long int pop();
void convtopost();

int prio(char symbol);
int isnull();
void revinfi();
void revpost();

char infix[50], postfix[50];
long int stack[50];
int top;

int main()
{
        long int value;
        top=-1;
        printf("Enter infix : ");
        gets(infix);
        revinfi();
        convtopost();
        revpost();
        printf("Prefix : %s\n",postfix);
        
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


void revinfi()
{
    strcpy(infix,strrev(infix));
    for(int j=0;j<strlen(infix);j++)
    {
        if(infix[j]=='(')
        infix[j]=')';
        else if (infix[j]==')')
        infix[j]='(';
    }
}
void revpost()
{
    strcpy(postfix,strrev(postfix));
    for(int j=0;j<strlen(postfix);j++)
    {
        if(postfix[j]=='(')
        postfix[j]=')';
        else if (postfix[j]==')')
        postfix[j]='(';
    }
}