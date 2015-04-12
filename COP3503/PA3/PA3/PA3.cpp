//
//  main.cpp
//  PA3
//
//  Created by Hugh A. Miles on 11/5/14.
//  Copyright (c) 2014 HAMtech. All rights reserved.
//

#include <cstring>
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <stdio.h>
#include <cmath>

#define PI 3.14159265

using namespace std;

///////stateMethods///////////////////////////////
void printStack(stack<string> looking);
void clearStringBuffer(stringstream toClear);
bool checkExpression(string check);
string doMath(stack<string> expStack);
stack<string> parseExpression(string expression);
stack<string> flipStack(stack<string> toFlip);
////////////////////////////////////////////////

bool goodToGo = false;  // global varies

int main()
{
    string expression;
    stack<string> readingStack;
    
    cout << "Please enter expression:" << endl;
    
    getline(cin,expression); // read input
    
    bool goodToGo = checkExpression(expression);  // check if expression can be evaluated
    
    readingStack = parseExpression(expression); // create the stack with correct data nodes
   
    if (goodToGo) // check if user give good inputs
    {
       string finalAnswer = doMath(readingStack); // implementing math algorithm
        
        if (finalAnswer == "XXX")  // division by 0 case
        {
            cout << "Error: Division by 0!!";
        }
        
        else if(finalAnswer == "SSS") // root of a number
        {
            cout << "Error: Square root of (-) number!!";
        }
        
        else if(finalAnswer == "LLL")
        {
            cout << "Error: Log of (-) number";
        }
        
        else
        {
            cout << "The result is: " << finalAnswer << endl;
        }
        
    }
    
    else
    {
        cout << "Error: Unbalanced Parenthesis" << endl;
    }
}

void printStack(stack<string> myStack)
{
    cout << "|t|";
    
    while (!myStack.empty()) {
        
        if (myStack.top()== "")
        {
            cout << "NULL";
        }
        else
        {
           cout << " " << myStack.top() << " &|&";
        }
        
        myStack.pop();
    }
    
    cout << "|b|";
    
}

stack<string> parseExpression(string expression)
{
    stack<string> myStack;
    stringstream numberBuffer;
    stringstream tempString;
    
    for (int i = 0; i < expression.length() ; i++)  //build intial value stack
    {
        char temp = expression.at(i);
        tempString << temp;
        
        if (temp >= '0' && temp <= '9')  //parse number inputs
        {
            numberBuffer << temp;
        }
    
        else if(temp == '-' && numberBuffer.str() == "")
        {
            numberBuffer << temp; // put - in numberBuffer
            i++;      // move to next char
            while (expression.at(i) != ')') {
                numberBuffer << expression.at(i);
                i++;
            }
        }
        
        else if (temp == 's' || temp == 'c' || temp == 'l')
        {
            stringstream functionCalc;
        /// write catch exception here to catch error ///////////////////////////////////////
            try 
            {
                while(expression.at(i) != '(')
                 {
                    temp = expression.at(i);
                    functionCalc << expression.at(i);   // get the number value from the function
                    i++;
                 }
                
                functionCalc << '('; // add opening parenthesis
                
                string test = functionCalc.str();
                myStack.push(functionCalc.str());
                
            } 
            
            catch (out_of_range) {
                
                cout << "Error: Bad Expression";
            }
          
        }
        
        
        else if(temp == '*' || temp == '+' || temp == '-' || temp == '/' || temp == ')' || temp == '^')
        {
            if (numberBuffer.str() != "") {
                string number = numberBuffer.str();
                myStack.push(number);               // pass last number in buffer
            }
            
            string oper = tempString.str();
            
            myStack.push(tempString.str()); // pass operators and parentheisis
            
            numberBuffer.str(string());
            numberBuffer.clear();           // clear number buffer
        }
        
        tempString.str(string()); // temp string buffer
        tempString.clear();
        
    }
    
    myStack.push(numberBuffer.str());    //last number in buffer
    
    myStack = flipStack(myStack);
    
    return myStack;
}


stack<string> flipStack(stack<string> toFlip)
{
    stack<string> flipped;
    
    while (!toFlip.empty()) {
        string pass = toFlip.top(); // Pop&Push >> newStack
        flipped.push(pass);
        toFlip.pop();
    }
    
    return flipped;
}

string doMath(stack<string> expStack)
{
    stack<string> tempStack;
    
    while (!expStack.empty()) // go through whole stack till empty
    {
        string index = expStack.top(); // look at top of stack
        
        if (index == ")") // find closing bracket
        {
            string x;
            string y;
            string z;
            bool isFunction = false;
            
            for (int i = 0; i < 3; i++)
            {
                string test = tempStack.top();
                
                if (tempStack.top() == "sin(" || tempStack.top() == "cos(" || tempStack.top() == "sqrt(" || tempStack.top() == "log(")
                {
                    y = tempStack.top();
                    tempStack.pop();
                    isFunction = true;
                    break; // break loop if function type
                }
                
                else
                {
                    switch (i) // pop tempStack >> to variables
                    {
                        case 0:
                            x = tempStack.top();
                            break;
                        case 1:
                            y = tempStack.top();
                            break;
                        case 2:
                            z = tempStack.top();
                            break;
                    }
                    tempStack.pop();
                }
        
            }
            
            // change strings to intgers and use switch todo operations
            std::string::size_type sz;
            float num1 = std::stof (x,&sz);
            const char *myOperator = y.c_str();
            string myFunction = y;
            double math;

            if(myFunction == "sqrt(" && num1 < 0)
            {
                return "SSS";
            }
            
            if(myFunction == "log(" && num1 < 0)
            {
                return "LLL";
            }
            
            
            if(isFunction)
            {   // function
                if(myFunction == "sin(")
                {   
                    double degrees = (num1*PI)/180;
                    math = sin(degrees);
                }

                else if(myFunction == "cos(")
                {
                    double degrees = (num1*PI)/180;
                    math = cos(degrees);
                }

                else if(myFunction == "log(")
                {
                    math = log2(num1);
                }

                else if (myFunction == "sqrt(")
                {
                    math = sqrt(num1);
                }
            }

            else
            {   // normal operator
                double num2 = std::stof (z,&sz);
                
                if (*myOperator == '/' && num1 == 0) {
                    return "XXX";
                }
                
                switch(*myOperator)
                {
                    case '*':
                        math = num1 * num2;
                        break;
                    case '+':
                        math = num1 + num2;
                        break;
                    case '-':
                        math = num2 - num1;
                        break;
                     case '/':
                        math = num2 / num1;
                        break;
                    case '^':
                        math = pow(num2, num1);
                        break;   
                }
            }
           
            expStack.pop();             // take off ')'
           
            stringstream mathString;    // put math back on stack
            mathString << math;
            tempStack.push(mathString.str());
            mathString.str(string());   // top string buffer
            mathString.clear();

            
            /*///////DEBUGGGING///////////////////////////////////
            cout << "math:" << math << endl;
            cout << "tempStack:" << endl;
            printStack(tempStack);
            cout << endl;
            cout << "expStack:" << endl;
            cout << endl;
            printStack(expStack);
            //break;
            ///////////////////////////////////////////////////*/

        }
        
        else
        {
            tempStack.push(index); // expStack >> tempStack
            expStack.pop();
        }
  
    }
    
    tempStack.pop(); // pop empty space from top of stack
    
    return tempStack.top();
}

bool checkExpression(string check)
{
    int leftParas = 0;
    int rightParas = 0;
    int numberOfOps = 0;
    
    for(int i = 0; i < check.length() ; i++)
    {
        if(check.at(i) == 's' || check.at(i) == 'l' || check.at(i) == 'c') {
            numberOfOps++;
            while(check.at(i) != '(')
            {
                i++; //find next parenthesis
            }
        }
        
        if(check.at(i) == '(')
        {
            leftParas++;  // count right paras
        }
        
        if(check.at(i) == ')')
        {
            rightParas++; // count left paras
        }
        
        else if(check.at(i) == '*' || check.at(i) == '+' || check.at(i) == '-' || check.at(i) == '/' || check.at(i) == '^')
        {
            numberOfOps++; // count left paras
        }
        
    }
    
    int matchParas = (leftParas+rightParas) / 2;
    
    if(leftParas == rightParas && numberOfOps == matchParas)
    {
        return true;  // if they equal expression can be calculated
    }
    
    
    
    
    return false;  // cannot be calculated
}

