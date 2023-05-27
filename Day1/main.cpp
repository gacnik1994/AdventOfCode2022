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
        vector <int> store_calories;
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
                //save calories to vector
                store_calories.push_back(calories);
                //prepare calories for another sum
                calories = 0;
            }else{
                //calories sum
                calories = calories + stoi(line);
            }
        }
        //print the highest calorie ammount
        int bubble_loop {0};
        while (bubble_loop < 3){
            bubble_loop++;
            int vector_loop = store_calories.size()-1;
            while(vector_loop >= 0){
                if(vector_loop == 0){
                    break;
                }else if(store_calories.at(vector_loop) > store_calories.at(vector_loop-1)) {
                    int a = store_calories.at(vector_loop);
                    store_calories.at(vector_loop) = store_calories.at(vector_loop-1);
                    store_calories.at(vector_loop-1) = a;
                    }
                vector_loop--;
            }
        }
        int top3 {store_calories.at(0)+store_calories.at(1)+store_calories.at(2)};
        cout << "Max calories   : " << store_calories.at(0) << endl;
        cout << "Second highest : " << store_calories.at(1) << endl;
        cout << "Third highest  : " << store_calories.at(2) << endl;
        cout << "Sum of top 3 most calories: " << top3 << endl;
        file.close();
        return 0;
}