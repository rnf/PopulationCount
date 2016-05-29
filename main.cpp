// main.cpp - PopulationCount

#include "Database.h"
#include "PersonRecord.h"
#include <assert.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <utility>

int main(int argc, char *argv[])
{
    Database data;
    assert(argc == 2);
    char* filename = argv[1];
    std::ifstream ifile(filename);
    if(ifile.is_open())
    {
       data.Initialize(ifile);
    }

    std::pair<int, int> answer = data.FindMaxCohort();
    std::cout << "maxYear = " << answer.first << ", maxNumber = " << answer.second << std::endl;
    return EXIT_SUCCESS;
}

