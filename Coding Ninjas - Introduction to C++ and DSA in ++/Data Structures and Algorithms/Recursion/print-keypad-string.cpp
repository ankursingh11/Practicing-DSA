
#include <iostream>
#include <string>
using namespace std;

int keypad(int n, string output[], string options[]){
    if(n == 0){
        output[0] = "";
        return 1;
    }
    int LD = n%10;
    n = n/10;
    string x[500];
    
    int count = keypad(n, x, options);
    
    string op = options[LD];
    int k = 0;
    for(int i = 0; i < op.length(); i++){
        for(int j = 0; j < count; j++){
            output[k] = x[j] + op[i];
            k++;
        }
    }
    return k;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    if(num == 0) return;
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output[100000];
    
    int count = keypad(num, output, options);
    for(int i = 0; i < count; i++) cout<<output[i]<<endl;
}
