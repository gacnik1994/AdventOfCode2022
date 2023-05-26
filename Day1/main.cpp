#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
        //opening file
        ifstream file;
        file.open("input.txt");
        //check if file was opened
        if(file.fail()){
            cout << "File failed to open." << endl;
            return 1;
            }
        //int for storing highest number
        int max_calories {0};
        //int for storing sum for elfs
        int calories {0};
        //buffer for string
        string line;
        //file line loop
        while(!file.eof()){
            //get line from file
            getline(file, line);
            //find empty space in file = end of sum
            if(line.empty()){
                //compare sum with currently stored highest number
                if(max_calories < calories){
                    max_calories = calories;
                    }
                //prepare calories for another sum
                calories = 0;
            }else{
                //calories sum
                calories = calories + stoi(line);
            }
        }
        //print the highest calorie ammount
        cout << max_calories << endl;
        //close file
        file.close();
        return 0;
}