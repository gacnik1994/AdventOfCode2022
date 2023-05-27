#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
        
       string abc {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
       ifstream file;
       file.open("input.txt");
       if(file.fail()){
           cout << "File not found."<< endl;
           return 1;
           }
        string line;
        int total {0};
        //going through file
        while(!file.eof()){
            //get line from file
            getline(file,line);
            //get number of characters in line
            int line_size {line.length()};
            
            //go through first half of the line
            for(int i{0}; i < line_size/2 ; i++){
                //go through second half of the line
                for(int j{line_size/2}; j < line_size ; j++){
                    //compare characters from both lines
                    if(line.at(i) == line.at(j)){
                        //loop for alphaet to get values for mathing characters
                        for(int k{1}; k <= abc.length() ; k++){
                            if (line.at(i) == abc.at(k-1)){
                                cout << line_size << " " << k << endl;
                                //ass value of the matching character to  the total
                                total += k;
                                //set i to max to end loop for first half of the line
                                i = line_size/2;
                                //set j to max to end the loop for the second half of the line
                                j = line_size;
                                break;
                                }
                            }
                        }
                    }
                }
            }   
        //final result
        cout << total << endl;
        
        return 0;
}