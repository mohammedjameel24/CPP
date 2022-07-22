/*
Given a string , write a function to replace all spaces in a string with '%20'. it is given that the string has sufficient space .
Input
hello_world,_how_are_you?
Output
hello%20world,%20how%20are%20you?
*/

#include <iostream>
#include <cstring>

using namespace std;

void replace_space(char *str){

    int space = 0;
    for(int i = 0; str[i]!='\0'; i++)
    {
        if(str[i] == ' ')
        {
            space += 1;
        }
    }

    int idx = strlen(str) + 2*space ;
    //str[idx] = '\0'; 

    for(int i = strlen(str)-1; i>=0; i--)
    {
        if(str[i] == ' ')
        {
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';

            idx = idx - 3;
        }
        else{
            str[idx -1] = str[i];
            idx--;
        }
    }

}

int main() {
    char input[10000];
    cin.getline(input,1000);
    replace_space(input);
    cout<< input <<endl;

    return 0;
}