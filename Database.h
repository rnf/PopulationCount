// Database.h - R. Freedman
#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <ostream>
#include <utility>
#include <string>
#include <queue>
#include <vector>

class PersonRecord;

class Database
{
public:
    Database();
    ~Database();
    
    void Initialize(std::ifstream& file);
    std::pair<int,int> FindMaxCohort();
    friend std::ostream& operator<<(std::ostream& os, Database& database);

private:
    void ParseLine(std::string& line, std::string& name, int* born, int* died);
    void AddRecord(PersonRecord* newRecord);

    std::vector<PersonRecord> DateList;
};

#endif // DATABASE_H
