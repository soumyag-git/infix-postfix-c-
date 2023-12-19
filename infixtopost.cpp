#include <iostream> 


using namespace std;

class node{
    public:
    char data;
    node *next;
}*top=NULL;

class stack{
    public:
    stack(){
        top=NULL;
    }
    void push(char c);
    char pop();
    int isoperand(char c);
    int prece(char c);
    char *intopst(char *infix);
};

void stack::push(char c){
    node *p =new node;
    if(p==NULL){
        cout<<"stack overflow";
    }
    else{
        p->data=c;
        p->next=top;
        top=p;
    }
}

char stack::pop(){
    char c=-1;
    if(top==NULL){
        cout<<"Stack underflow";
    }

    else{
        node *p=top;
        c=p->data;
        top=top->next;
    }
    return c;
}

int stack::isoperand(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return 0;
    }
    else{
        return 1;
    }
}

int stack::prece(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else{
        return 0;
    }
}

char * stack::intopst(char *infix){
    int i=0,j=0;
    char *postfix=new  char[strlen(infix)+2];
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(prece(infix[i])>prece(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top->data!='@'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}


int main(){
    stack st;
    st.push('@');
    char *infix="a+b*c";
    char *postfix=st.intopst(infix);
    cout<<postfix;

}