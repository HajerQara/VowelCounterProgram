/*
Name: Hajer Qara
Date: 6/19/2022
File Name: VowelCounterProgram
Section: ITCS 2530 V0801 2021SS - C++ Programming 1

VowelCounterProgram.cpp:
Create a program that counts the number of vowels in a file:
    1) The user must specify the name of the file (from the command line) to analyze when the program is run. If not, an error should be generated.
    2) Use constants where appropriate.
    3) Use I/O (stream) manipulators to format the output so that it is identical to the example below
    4) Pass the name of the file to read in from the command line.
*/



#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int BORDER_LENGTH = 60;
const string ERROR_MESSAGE = "Error in opening the file";


int main(int argc, char* argv[])
{
    //Declared Variables 
    ifstream dataInput;
    string programMessage;
    int messageLength;
    int borderFill;
    int halfFill;
    char ch;

    int vowelA = 0;
    int vowelE = 0;
    int vowelI = 0;
    int vowelO = 0;
    int vowelU = 0;
    int totalVowels = 0;
    int letterC = 0;
    int letterB = 0;
    int letterD = 0;


    //Opens the file within the command line argument "Constitution_of_the_United_States.html"
    dataInput.open(argv[1]);
    if (!dataInput)
    {   //Outputs error message if not file is found or if file is corrupt
        cout << ERROR_MESSAGE << ':' << endl;
        system("pause");
        return 1;
    }

    //Greets the user when they first run the program 
    programMessage = " Welcome to my Letter Count Program ";
    messageLength = static_cast<int>(programMessage.length()); // find the number of characters in the greeting message

    borderFill = BORDER_LENGTH - messageLength; // calculates how much space the message takes up 
    halfFill = borderFill / 2; // calculates how long the half border will be 
    string asterisk(halfFill, '*'); // repeats the asterisk based on the length of the half border

    //Prints out the bordered message 
    cout << setfill('*') << setw(BORDER_LENGTH) << "*" << endl; // prints out asterisks based on the length of the border
    cout << asterisk << right << programMessage << asterisk << endl; // prints half border with message
    cout << setw(BORDER_LENGTH) << "*" << setfill(' ') << endl; // resets so whitespaces no longer print out asterisks


    //Notifies the user that the file they inputed will be analyzed
    cout << endl << "Analyzing file " << "\'" << argv[1] << "\'..." << endl;

    // A while loop that will analyze the file entered until it has reached the end of the file
    while (!dataInput.eof()) {
        dataInput.get(ch); // reads the characters within the file 
       
        // This multi-if statement checks to see if the character currently selected is a vowel
        if (ch == 'a' || ch == 'A') {
            vowelA++; // if the character is the vowel 'a' it will increment by one
        }
        else if (ch == 'e' || ch == 'E') {
            vowelE++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'i' || ch == 'I') {
            vowelI++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'o' || ch == 'O') {
            vowelO++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'u' || ch == 'U') {
            vowelU++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'c' || ch == 'C') {
            letterC++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'b' || ch == 'B') {
            letterB++; // if the character is the vowel 'e' it will increment by one 
        }
        else if (ch == 'd' || ch == 'D') {
            letterD++; // if the character is the vowel 'e' it will increment by one 
        }
        else {
           
        };
  

    };

    // Calculates the total vowels within the file by adding all the values from the switch statement above
    totalVowels = vowelA + vowelE + vowelI + vowelO + vowelU;

    //Prints the results of the calculation of each vowel
    cout << endl << "The number of A's: " << setfill('.') << setw(45) << vowelA << endl;
    cout << "The number of E's: " << setfill('.') << setw(45) << vowelE << endl;
    cout << "The number of I's: " << setfill('.') << setw(45) << vowelI << endl;
    cout << "The number of O's: " << setfill('.') << setw(45) << vowelO << endl;
    cout << "The number of U's: " << setfill('.') << setw(45) << vowelU << endl;
    cout << "The vowel count is: " << setfill('.') << setw(44) << totalVowels << endl;
    // GitHub Submission Assignment - Added 3 more letters
    cout << "The number of C's: " << setfill('.') << setw(45) << letterC << endl;
    cout << "The number of B's: " << setfill('.') << setw(45) << letterB << endl;
    cout << "The number of D's: " << setfill('.') << setw(45) << letterD << endl;

    dataInput.close(); // Closes the file 
    system("pause");
    return 0;

}

////////////////////////////////////////////////////////////
//////      CODE THAT I TRIED BUT DIDN'T WORK        //////
////////////////////////////////////////////////////////////
 /*
//Disn't allow for the user to input different file names
const string FILE_NAME = "Constitution_of_the_United_States.html";

//Using the ++ format simplefied the code 
vowelA += 1
vowelE += 1
vowelI += 1
vowelO += 1
vowelU +=1

//Initially had difficulty getting the statments to print
// I then realized it was because the file wasn't opened
// and that these statments were not only not need but incorrectly formatted 
    printf("The number of A's: ", vowelA);
    printf("The number of E's: ", vowelE);
    printf("The number of I's: ", vowelI);
    printf("The number of O's: ", vowelO);
    printf("The number of U's: ",  vowelU);
    printf("The vowel count is:", totalVowels);

// I wanted to ensure both capital and lowecase letters were counted 
switch (ch)
{
case 'a':
    vowelA++; // if the character is the vowel 'a' it will increment by one 
   // dataInput.get(ch);
    break;
case 'e':
    vowelE++; // if the character is the vowel 'e' it will increment by one 
   // dataInput.get(ch);
    break;
case 'i':
    vowelI++; // if the character is the vowel 'i' it will increment by one 
   // dataInput.get(ch);
    break;
case 'o':
    vowelO++; // if the character is the vowel 'o' it will increment by one 
   // dataInput.get(ch);
    break;
case 'u':
    vowelU++; // if the character is the vowel 'u' it will increment by one
    //dataInput.get(ch);
    break;
default:
    // dataInput.get(ch);
    break; // if the character is not a vowel it will simply break and check the next character
};
*/

/////////////////////////////////////////////////////////////
