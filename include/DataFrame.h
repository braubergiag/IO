//
// Created by glushkov on 23.12.2021.
//

#ifndef COUSERA_DATAFRAME_H
#define COUSERA_DATAFRAME_H
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using DataTable = std::vector<std::vector<double>>;
using ColumnNames = std::vector<std::string>;

struct DataFrame {

    void PrintDataFrame();

    DataTable   dataTable;
    ColumnNames  columnNames;

};



#endif //COUSERA_DATAFRAME_H
