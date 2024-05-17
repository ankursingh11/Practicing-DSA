
#include <string.h>
using namespace std;

void helper(string input, string output){
    if(input.size() == 0){
        cout<<output<<endl;
        return;
    }

    int num = input[0]-48;
    char ch = num-1+'a';
    helper(input.substr(1), output+ch);
    if(input.size() > 1){
        num = num*10 + input[1] - 48;
        ch = num-1+'a';
        if(num >= 10 && num <= 26){
            helper(input.substr(2), output+ch);
        }
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    if(input.size() == 0) return;
    string output = "";
    helper(input, output);
}

