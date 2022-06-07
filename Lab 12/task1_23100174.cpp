#include <iostream>
using namespace std;

struct node
{
	node *next ;
	int value ;

	node()
	{
		next = NULL ;
		value = 0 ;
	}
};

class Stack
{
private:

	node *top = NULL ;

public:
	
	void push(int data)
	{
		node *temp = new node ;
		temp -> value = data ;
		temp -> next = top ;
		top = temp ;
	}

	int pop()
	{
		node *temp = new node ;
		temp = top ;
		top = top -> next ;
		int ret = temp -> value ;
		delete temp ;
		return ret ;
	}

	int peek()
	{
		return top -> value ;
	}

	void print()
	{
		node *temp = new node ;
		temp = top ;
		while(temp != NULL)
		{
			cout << temp -> value ;
			temp = temp -> next ;
		}
	}

	int length()
	{

		node *temp = new node ;
		temp = top ;
		int len = 0 ;
		while(temp != NULL)
		{
			temp = temp -> next ;
			len++ ;
		}

		return len;
	}

};

bool checkOperator(char op)
{
	if(op == '+' || op == '-' || op == '*' || op == '/')
	{
		return true;
	}
	else 
	{
		return false ;
	}
}

bool checkOperand(char operand)
{
	if(operand == '0' || operand == '1' || operand == '2' || operand == '3' || operand == '4' || operand == '5' || operand == '6' || operand == '7' || operand == '8' || operand == '9' )
	{
		return true;
	}
	else
	{
		return false ;
	}
} 

int precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }

    else if(op == '*' || op == '/')
    {
        return 2;
    } 
}

int operation(char op, int op1, int op2)
{
	int operand1 = op1 ;
	int operand2 = op2 ;

	if(op == '+') 
	{
		return operand1 + operand2;
	}
	else if(op == '-') 
	{
		return operand1 - operand2;
	}
	else if(op == '*') 
	{
		return operand1 * operand2;
	}
	else if(op == '/')
	{
		return operand1 / operand2;
	}
}

int main()
{
	node *top = new node ;
	Stack stackOperators ;
	Stack stackOperands ;
	
	string exp ;
	cout << "Enter the expression you want to calculate: " << endl;
	cin >> exp ;

	string s1;
    int length = s1.length();
    int op1 = 0 ;
    int op2 = 0;

    for(int i = 0; i < length; i++)
    {
        if(checkOperand(exp[i]))
        {
            s1 = exp[i];

            i++;

            while(i < length && checkOperand(exp[i]))
            {
                s1 = s1 + exp[i];

                i++;
            }

            stackOperands.push(stoi(s1));

            i--;
        }

        else if(!checkOperand(exp[i]))
        {
            while( ( stackOperators.length() ) != 0 && ( precedence( stackOperators.peek() ) >= precedence(exp[i])) )
            {
                int op2 = stackOperands.pop();

               
                int op1 =  stackOperands.pop();

                char oper = stackOperators.pop();

                int result = operation(oper, op1, op2);

                string s_result = to_string(result);

                stackOperands.push(stoi(s_result));
            }

            stackOperators.push(exp[i]);
        }
    }

    while(stackOperators.length() != 0)
    {
        int op2 = stackOperands.pop();
               
        int op1 =  stackOperands.pop();

        char oper = stackOperators.pop();

		int result = operation(oper, op1, op2);

        string s_result = to_string(result);

        stackOperands.push(stoi(s_result));
    }

    cout << stackOperands.peek();
    return stackOperands.peek();
}
