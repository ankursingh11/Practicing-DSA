
#include <string>
using namespace std;

int keypad(int num, string output[], string options[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }

    string x[500];
    int count = keypad(num/10, x, options);
    string option = options[num%10];

    int k = 0;
    for(int i = 0; i < option.length(); i++){
        for(int j = 0; j < count; j++){
            output[k++] = x[j] + option[i];
        }
    }

    return k;
}

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return keypad(num, output, options);
}
