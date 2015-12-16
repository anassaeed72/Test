//
//  main.cpp
//  Google_3
//
//  Created by Anas Saeed on 12/04/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
std::vector<std::string> string_split(std::string input, char breaker);
std::vector<std::string> string_split(std::string input, char breaker){
    std::vector<std::string> output;
    unsigned int vec_size = 0;
    std::string result;
    for(auto x :input){
        if (x == breaker) {
            std::string intial = "";
            output.push_back(result);
            result = "";
            continue;
        }
        result = result + x;
    }
    output.push_back(result);
    return output;
}
int main(int argc, const char * argv[])
{
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::string dummy;
    std::getline(read,dummy);
    int total;
    total = atoi(dummy.c_str());
    for (int  k = 1; k < total+1; k++) {
        
        std::string temp;
        std::getline(read,temp);
        std::vector<std::string> v = string_split(temp, ' ');
        int rows = atoi(v[0].c_str());
        int columns = atoi(v[1].c_str());
        int mines = atoi(v[2].c_str());
        int minecount = 0;
        int A[rows+2][columns+2];
        int last_row = 0;
        int last_col = 0;
        for (int  i = 1; i <=rows; i++) {
            for (int j = 1; j <= columns; j++) {
                A[i][j] = 0;
            }
        }
        for (int  i = 1; i<=rows; i++) {
            for (int j = 1; j<=columns; j++) {
                if (minecount == mines) {
                    continue;
                }
                if (rows-i <2) {
                    if (columns-j<2) {
                        continue;
                    }
                }
                minecount++;
                A[i][j] = -1;
            }
        }
        if (minecount!=mines) {
            myfile<<"Case #"<<k<<":"<<std::endl <<"Impossible" << std::endl;
            continue;
        }
        A[rows][columns] = 1;
        //<<rows <<" " << columns << " "<<mines
        myfile<<"Case #"<<k<<":" << std::endl;

        for (int i = 1; i<=rows; i++) {
            for (int j = 1; j<=columns; j++) {
                if (A[i][j] == -1) {
                    myfile <<"*";
                }
                if (A[i][j] == 0) {
                    myfile<<".";
                }
                if (A[i][j] == 1) {
                    myfile <<"c";
                }
            }
            myfile<<std::endl;
        }
        
    }
    myfile.close();
    return 0;
}

