/*
Author: Tanish Bhongade
Date: 4 Jul 2021
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>

using namespace std;

const int scramLen = 25;//Standard length of scrambles
char mainScramble[scramLen][3];//Main scramble array
string moves="RULFDU";//List of moves
char dir[]={" 2'"};//Direction of moves

int getRand(int upr, int lwr){
    //Gets random integer along with range
    int randNum;
    randNum=(rand() % (upr - lwr + 1)) + lwr;
    return randNum;
}

void initScramble(){
    //Makes scramble like OO OO OO......
    for(int loop=0; loop<scramLen; loop++){
        strcpy(mainScramble[loop],"OO");
    }
}

void scrambleReplace(){
    //Generates scramble with alphabets
    for(int loop=0; loop<scramLen; loop++){
        mainScramble[loop][0]=moves[getRand(5,0)];
        mainScramble[loop][1]=dir[getRand(2,0)];
    }
}

void valid(){
    //Makes scramble valid
    int loopOne, loopTwo;
    
    for(loopOne=1; loopOne<scramLen; loopOne++){
        //Removes stuff like R R L
        while(mainScramble[loopOne][0] == mainScramble[loopOne-1][0]){
            mainScramble[loopOne][0] = moves[getRand(5,0)];
        }
    }
    
    for(loopTwo=2; loopTwo<scramLen; loopTwo++){
        //Removes stuff like R L R'
        while((mainScramble[loopTwo][0] == mainScramble[loopTwo-2][0]) || (mainScramble[loopTwo][0] == mainScramble[loopTwo-1][0])){
            mainScramble[loopTwo][0] = moves[getRand(5,0)];
        }
    }
}

void printData(){
    //Prints the scramble
    int loop=0;
    
    for(loop=0; loop<scramLen; loop++){
        cout << mainScramble [loop] << " ";
    }
}

int main(){
    srand(time(0));//Seeding time to 0
    cout << "3x3 Scramble: \n";
    
    initScramble();//Calling initScramble ()
    scrambleReplace();//Calling scrambleReplace ()
    valid();//Calling valid()
    printData();//Print the data
    
    return 0;
}
