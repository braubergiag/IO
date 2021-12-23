//
// Created by glushkov on 23.12.2021.
//

#ifndef COUSERA_FILEREADER_H
#define COUSERA_FILEREADER_H


#include <string>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <sstream>

#include "DataFrame.h"
class FileReader {
public:


    FileReader(const std::string & filePath);
    ~FileReader();
    bool Init();
    void ParseFile(DataFrame & dataFrame,char delimeter);
    std::string GenerateParseError(DataFrame & dataFrame,const std::string & columnData, uint32_t colNumber);





private:

    void ParseRow(DataFrame & df, std::stringstream & stream,char delimeter);

    std::string _filePath;
    std::ifstream * _inputFileStream = nullptr;


};


#endif //COUSERA_FILEREADER_H
