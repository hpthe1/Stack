#include <iostream>
#include <stack>
#include <string>
using namespace std;

int EvaluatePostfix(string exp);
int PerformOperation(char operation, int op1,int op2);
bool IsOperator(char c);
bool IsNumericDigit(char c);

int main()
{
    string exp;
    cout<<"Enter postfix expression "<<endl;
    getline(cin,exp);
    int result= EvaluatePostfix(exp);
    cout<<"Output is = "<<result<<endl;
    return 0;
}

int EvaluatePostfix(string exp)
{
    stack<int> S;
    for(int i=0;i<exp.length();i++){
        if(exp[i]==' '||exp[i]==',') continue;
        else if(IsOperator(exp[i])){
            int op2=S.top(); S.pop();
            int op1=S.top(); S.pop();
            int result = PerformOperation(exp[i],op1,op2);
            S.push(result);
        }
        else if(IsNumericDigit(exp[i])){
            int op=0;
            while(i<exp.length() && IsNumericDigit(exp[i])){
                op=(op*10)+exp[i]-'0';
                i++;
            }
            i--;
            S.push(op);
        }
    }
    return(S.top());
}

bool IsNumericDigit(char c)
{
    if(c>='0' && c<='9') return true;
    return false;
}

bool IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')return true;
    return false;
}
int PerformOperation(char op,int op1,int op2)
{
    if(op=='+') return op1+op2;
    else if(op=='-') return op1-op2;
    else if(op=='*') return op1*op2;
    else if(op=='/') return op1/op2;
    else return -1;
}
