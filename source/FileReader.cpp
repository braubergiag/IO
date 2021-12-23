
#include "../include/FileReader.h"


FileReader::FileReader(const std::string &filePath): _filePath(filePath){}



void FileReader::ParseFile(DataFrame & df,char delimeter) {
    bool isFirstRow = true;
    std::string input_row;

    while( std::getline(*_inputFileStream,input_row)) {
        if (isFirstRow) {
            std::stringstream row(input_row);
            std::string colName;
            while (getline(row,colName,delimeter)) {
                df.columnNames.push_back(colName);
            }
            isFirstRow = false;
            df.dataTable.resize(df.columnNames.size());
            continue;
        }

        std::stringstream row(input_row);
        try {
            ParseRow(df,row,delimeter);
        } catch (std::exception & ) {
            throw;
        }


    }

}
void FileReader::ParseRow(DataFrame & df, std::stringstream & stream,char delimeter) {
    std::string columnData;
    uint32_t columnNumber = 0;
    while (std::getline(stream,columnData,delimeter)) {
        try {
            double data = std::stod(columnData);
            df.dataTable.at(columnNumber++).push_back(data);
        } catch (std::exception & ) {
            throw std::runtime_error(GenerateParseError(df,columnData,columnNumber));
        };


    }

}

FileReader::~FileReader() {

    if (_inputFileStream->is_open()) {
        _inputFileStream->close();
    }
    delete _inputFileStream;

}

bool FileReader::Init() {
    _inputFileStream = new std::ifstream;
    _inputFileStream->open(_filePath);
    if (*_inputFileStream){
        std::cout << "File " << _filePath << " was opened" << std::endl;
    }
    else {
        std::cerr <<"Error while opening file " <<  _filePath << std::endl;
        return false;
    }


    return true;
}

std::string FileReader::GenerateParseError(DataFrame &df,const std::string& columnData,uint32_t columnNumber) {
    std::string error = "Parsing Error: (Column - [" +
    df.columnNames.at(columnNumber) + "]" +
    ", Row - [#" + std::to_string(df.dataTable.at(columnNumber).size() + 1) + "])" +
    ", Entry - [" + columnData   + "] is not a valid";
    return error;
}
