#include <iostream>
#include <string>
#include <vector>

using namespace std;

//For Option 1
//Changes the string passed in parameter to reverse of itself
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

//For Option 1
//Returns true if the strings match, false if they do not
bool isPalindrome(string one, string two){
    if(one == two){
        cout << "\"" + one + "\" is a palindrome!";
        return true;
    }
    cout << "\"" + one + "\" is not a palindrome!";
    return false;
}

//For Option 2
//Prints a line of Stars
void printLineOfStars(int length){
    for(int i = 0; i < length; i++){
        cout << "*";
    }
    cout<<"\n";
}

//For Option 2
//Prints the list in a box
void printInBox(vector<string> list){
    int indexOfLongestString = 0;
    int maxLength = 0;
    int counter = 0;

    for (auto line : list) {
        if (line.length() > list.at(indexOfLongestString).length()) {
            indexOfLongestString = counter;
            maxLength = line.length();
        }
        counter+=1;
    }

    //prints the top line
    printLineOfStars(maxLength+2);
    //prints the body
    for(int i =0; i < list.size();i++){
        cout << "*" + list.at(i);

        for(int j=list.at(i).length(); j<maxLength; j++){
            cout << " ";
        }

        cout << "*\n";
    }
    //prints the last line
    printLineOfStars(maxLength+2);
}


int main()
{
    cout << "What do you want to do?\n";
    cout << "1. Check for palindrome\n";
    cout << "2. Boxed string\n";
    string choice;
    cin >> choice;

    if(choice == "1") {
        //User input
        cout << "Please enter a string:";
        string rev;
        cin >> rev;

        //Making a copy that isn't going to get reversed
        string input = rev;

        //Calls the 2 functions
        reverseStr(rev);
        isPalindrome(input, rev);
    }
    else if(choice == "2"){
        vector<string> list;
        list.push_back("TAMID");
        list.push_back("IS");
        list.push_back("THE");
        list.push_back("COOLEST");
        printInBox(list);
    }
    return 0;
}