#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
        ifstream file;
        file.open("calories.txt");
        if(file.fail()){
            cout << "File failed to open." << endl;
            return 1;
            }
        vector <int> all_elfs;
        int max_calories {0};
        int calories {0};
        int elf_number {1};
        int max_elf {1};
        string line;
        while(!file.eof()){
            
            getline(file, line);
            if(line.empty()){
                all_elfs.push_back(calories);
                elf_number++;
                if(max_calories < calories){
                    max_calories = calories;
                    max_elf = elf_number;
                    }
                calories = 0;
            }else{
                calories = calories + stoi(line);
            }
            
        }
        
        cout << all_elfs.at(0) << endl;
        cout << all_elfs.at(1) << endl;
        cout << all_elfs.at(all_elfs.size()-2) << endl;
        cout << max_calories << endl;
        cout << max_elf << endl;
        
       
        return 0;
}