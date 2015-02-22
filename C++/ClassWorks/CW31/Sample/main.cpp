#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

const int handleExpression(string expression){

	vector <string> exprStrings;

	stack <int> polkaStack;

	for (unsigned int i = 0; i < expression.length(); ++i){

		if (expression[i] != ' '){

			string temp = expression.substr(i, 1);

			exprStrings.push_back(temp);

		}

	}

	for (vector<string>::iterator itr = exprStrings.begin(); itr != exprStrings.end(); ++itr){

		if (*itr != " " && *itr != "+" && *itr != "-" && *itr != "=" && *itr != "*" && *itr != "/"){

			polkaStack.push(std::stoi(*itr));

		}

		else{
      int number2 = polkaStack.pop();
      int number1 = polkaStack.pop();
      switch(*itr){
            case '+':{
                polkaStack.push(number1+number2);
            }
                break;
            case '-':{
                polkaStack.push(number1-number2);
            }
                break;
            case '*':{
                polkaStack.push(number1*number2);
            }
                break;
            case '/':{
                polkaStack.push(number1/number2);
            }
                break;
            default:
                cout << "Wrong operator\n";
                break;
        }

	}
}
	return 10;

}


int main(){

	string str = "8 2 5 * + 1 3 2 * + 4 - /";

	handleExpression(str);

	return 0;

}
