



#include "../include/DataFrame.h"

void DataFrame::PrintDataFrame() {

    const uint8_t COL_WIDTH = 10;
    for (const auto & colName  : columnNames) {
        std::cout << std::setw(COL_WIDTH) << colName << "\t";
    }
    std::cout << std::endl;


    for (uint32_t rowNumber = 0;rowNumber < dataTable.at(0).size(); ++rowNumber) {
        for (const auto & column : dataTable) {
            std::cout << std::setw(COL_WIDTH) << column.at(rowNumber) ;
        }
        std::cout << std::endl;

    }
}


