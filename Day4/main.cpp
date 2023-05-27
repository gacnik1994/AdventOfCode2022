#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
        ifstream file;
        file.open("input.txt");
        if(file.fail()){
            cout << "File not found." << endl;
            return 1;
        }
        string line;
        int count {0};
        while(!file.eof()){
            getline(file, line);
            int sections[2][2] {0};
            int line_length = line.length(); 
            int no_of_found_numbers {0};
            string number;
            for(int i{0} ; i < line_length ; i++){
                if( line.at(i) == '-' || line.at(i) == ',' || (i+1) == line_length) {
                    switch(no_of_found_numbers){
                        case 0:
                            sections[0][0] = stoi(number);
                            no_of_found_numbers++;
                            number = "";
                            break;
                        case 1:
                            sections[0][1] = stoi(number);
                            no_of_found_numbers++;
                            number = "";
                            break;
                        case 2:
                            sections[1][0] = stoi(number);
                            no_of_found_numbers++;
                            number = "";
                            break;
                        case 3:
                            number += line.at(i);
                            sections[1][1] = stoi(number);
                            no_of_found_numbers++;
                            break;
                    }
                }else{
                        number += line.at(i);
                }
                if(no_of_found_numbers == 4){
                    if((sections[0][0] >= sections[1][0] && sections[0][1] <= sections[1][1]) || (sections[1][0] >= sections[0][0] && sections[1][1] <= sections[0][1])){
                        count++;
                    }
                    
                }
            }   
        }
        
        cout << count << endl;
        return 0;
}