/*
 * A = Rock
 * B = Paper
 * C = Scissors
 * 
 * X = rock
 * Y = Paper
 * Z = Scissors
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    //opening file
    ifstream file;
    file.open("input.txt");
    int total_score {0};
    string line;
    
    int i {0};
    //file search
   while(!file.eof()){
       cout << i << endl;
       i++;
       getline(file, line);
       //loking for what oppenent did
        switch(line.at(0)){
            case 'A': //rock
                //looking what I would do and for the end result
                switch(line.at(2)){
                    case 'X':
                        total_score += 4;
                        break;
                    case 'Y':
                        total_score += 8;
                        break;
                    case 'Z':
                        total_score += 3;
                        break;    
                    default:
                        cout << "Napaka" << endl;
                        return 1;
                    }
                break;
            case 'B'://paper
                switch(line.at(2)){
                    case 'X'://rock 1
                        total_score += 1;
                        break;
                    case 'Y'://paper 2 
                        total_score += 5;
                        break;
                    case 'Z'://scissors 3
                        total_score += 9;
                        break; 
                    default:
                        cout << "Napaka" << endl;
                        return 1;
                    }
                break;
            case 'C'://scissors
                    switch(line.at(2)){
                    case 'X'://rock 1
                        total_score += 7;
                        break;
                    case 'Y'://paper 2 
                        total_score += 2;
                        break;
                    case 'Z'://scissors 3
                        total_score += 6;
                        break; 
                    default:
                        cout << "Napaka" << endl;
                        return 1;
                    }
                break;
            default:
                break;
            }
        }
        //total score at the end
        cout << total_score << endl;
        file.close();
       
        return 0;
}