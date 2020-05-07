
#include <string>       // std::string
#include <iostream>     // std::cout
#include <cstdlib>
#include <math.h>
#include <stack>

using namespace std;


void generateRPN(string line, stack<string> &staK) {
  cout << "this isnt a thing...\n";
}

string evaluateRPN(stack<string> &postfix) {

  // stack <float> stakString;
  stack <string> fixed;

  while (!postfix.empty()) {
    fixed.push(postfix.top());
    postfix.pop();
  }

  stack <string> stakString;

  while(!fixed.empty()) {
    string temp1 = fixed.top();
    fixed.pop();


    int op1;
    int op2;

    if (temp1[0] == '*') {
      op1 = stoi(stakString.top()) ;stakString.pop();
      op2 = stoi(stakString.top()) ;stakString.pop();
      stakString.push(to_string(op2 * op1));
      continue;
    } else if (temp1[0] == '/') {
      op1 = stoi(stakString.top()) ; stakString.pop();
      op2 = stoi(stakString.top()) ; stakString.pop();
      stakString.push(to_string(op2 / op1));
      continue;
    } else if (temp1[0] == '+') {
      op1 = stoi(stakString.top()) ;stakString.pop();
      op2 = stoi(stakString.top()) ;stakString.pop();
      stakString.push(to_string(op2 + op1));
      continue;
    } else if (temp1[0] == '-') {
      op1 = stoi(stakString.top()) ;stakString.pop();
      op2 = stoi(stakString.top()) ;stakString.pop();
      stakString.push(to_string(op2 - op1));
      continue;
    } else {
      stakString.push(temp1);
    }
    //output = output.substr(1, output.size());
  }
  return stakString.top();
}

int main(int argc, char ** argv)
{
    string line;
    cout << "Expression: ";
    while (getline(cin, line)) {
        // skip empty line
        if (line.length() == 0)
            continue;

        stack<string> staK;

        generateRPN(line, staK);

        cout << "Answer: " << evaluateRPN(staK) << endl;
        line.clear();
        cout << "Expression: ";
    }
    return 0;
}



/*
int smain() {

  // string of operators
  string ops = "+-/*^";
  // string of functions
  string func = "(){}[]";
  // line variable
  string line;

  // stack
  stack <char> opStak;

  // output queue
  queue <char> outQ;

  // these are here to check for multiple place numbers
  int lnum = 0;


  while (line != "exit") {
    cout << "Expression: ";
    getline(cin, line);

    if (line == "exit") {
      break;
    }
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    for (int i = 0; i < line.size(); i++) {
      char a = line.at(i);
      lnum = (a - 48);
// ---------------------------------if isdigit----------------------------------------------------------
      if (isdigit(a)) { // if its a number

  // check: if next character number -> cncat into a 2 digit number
        if (i+1 != line.size() && isdigit(line.at(i + 1))) {
          cout << "\t2 digit number found:" << endl;

          // make a 2 digit number

          // Scaffolding
          cout << "\t\tyour number is: " << lnum << "\n";
          cout << "\t\tyour other number is: " << (line.at(i + 1) - 48) << "\n";

          // setting lnum to the 2 digit number
          lnum = lnum*10 + (line.at(i + 1) - 48);

          // scaffolding
          cout << "\t\tyour new number is : " << lnum << endl;
          i++;
          // Scaffolding
          //cout "\t new number: " << lnum;
        }
  // end check if next character is number


        // add to output queue (outQ)

        // Scaffolding
        cout << "\t" <<  lnum << ": is a number\n";
        // lnum++;
        continue;
// ----------------------------if its a function -------------------------------------------------------------
      } else if (func.find(a) != -1) {    // if its a function
        // push onto operator stack

        // scaffolding
        cout << "\t" << a << ": is a function\n";
// -----------------------------if isOperator --------------------------------------------------------
     } else if (ops.find(a) != -1) {    // if its an operator
        // push to operator stack (opStak)

        while (( functionTopOfOperatorStack(opStack, func))
               || (operatorTopOfOperatorStackGreaterPrecedence(opStack, ops, a))
               || (operatorTopOfOperatorStackEqualPrecedenceTokenLeftAssociative(opStack, ops, a)))
               && (opStak.top() != ')'/*the operator at the top of the operator stack is not a left parenthesis* /) {

               }



        // scaffolding
        cout << "\t" << a << ": is an operator\n";
// ---------------------------if invalid --------------------------------------------------------------------
      } else {

        // Scaffolding
        cout << "INVALID INPUT...AHHHH!!!!";
        cout << "\nExiting program...\n";
        exit(1);
      }

      // reset multiple place numbers here
    }


    // Scaffolding
    cout << "\t" << line << endl;
  }
  cout << "\nExiting program...\n";
}
*/
