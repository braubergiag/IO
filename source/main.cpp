#include <iostream>
#include "../include/DataFrame.h"
#include "../include/FileReader.h"

void Run(DataFrame & dataFrame,FileReader & fileReader){
    char DELIM = '\t';
    try {
        if (fileReader.Init()) {
            fileReader.ParseFile(dataFrame, DELIM);
            dataFrame.PrintDataFrame();
        };
    }
    catch (std::exception & ex){
       std::cerr << ex.what() << std::endl;
    }
}


int main() {
    // std::string filePath = "test_er.txt"; Parsing error
    std::string filePath = "test.txt";
    DataFrame dataFrame;
    FileReader fileReader(filePath);
    Run(dataFrame,fileReader);
    return 0;
}

