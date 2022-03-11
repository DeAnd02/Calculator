#include <iostream>
#include <cmath>

using namespace std;

struct expressionNotSupported{

};

bool isNotaDigit(char a){
    return a < '0' || a > '9';
}

int extractNumber(string str){
    /* Implementation left to right
    int result = 0;
    for(int i = 0; i < str.size(); i++){

        // char del numero con str.at(i) - il char dello '0' restituisce il numero giusto
        result = result * 10 + str.at(i) - '0';
    }*/

    /* Implementation right to left
    int result = 0;
    for(int i = 0; i < str.size(); i++){
        int index = str.size() - i - 1;
        // char del numero con str.at(i) - il char dello '0' restituisce il numero giusto
        result = result + (str.at(index) - '0') * std::pow(10,i);
    }*/

    // string to int
    int result = stoi(str);
    return result;
}

//return the index of the first non-digit char
int indexAfterNumber(string str){

    for(int i = 0; i < str.size(); i++){
        if(isNotaDigit(str.at(i)))
            return i;
    }
    return str.length();
}

int performOperation(char op, int left, int right){
    switch(op){
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            throw expressionNotSupported();
    }
}

int computeResult(string input){
    string left = input.substr(0, indexAfterNumber(input));
    char op = input.at(indexAfterNumber(input));
    string right = input.substr(indexAfterNumber(input) + 1, input.size() - indexAfterNumber(input));

    int leftNumber = extractNumber(left), rightNumber = extractNumber(right);

    return performOperation(op, leftNumber, rightNumber);
}

int main() {
    string input;



    // todo crea funzione per tutto il codice seguente con string in input
    //da 0 a n, con n non incluso
    int result;
    bool corretto = false;
    while(!corretto) {
        cout << "type the expression: " << endl;
        cin >> input;

        try{
            result = computeResult(input);
            corretto = true;
        }
        catch (expressionNotSupported) {
            std::cout << "the  expression you typed is not correct" << endl;
        }
    }
    cout<<result;
    return 0;
}