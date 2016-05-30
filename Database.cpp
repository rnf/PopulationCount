// Database.cpp - R. Freedman

#include "Database.h"
#include "PersonRecord.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>

Database::Database()
   : DateList()
{
}

Database::~Database()
{
}

void Database::Initialize(std::ifstream& ifile)
{
    std::string line;
    while(getline(ifile, line))
    {
        PersonRecord* temp;
        std::string name;
        int born;
        int died;
        ParseLine(line, name, &born, &died);
        if ((born < 1900) || (born > 2000) || (died < 1900) || (died > 2000) || (died < born))
        {
             std::cout << "Invalid entry: " << line << std::endl;
        }
        else
        {
           AddRecord(new PersonRecord(born, died));
        }
    }
    std::sort(DateList.begin(), DateList.end());
}

void Database::ParseLine(std::string& line, std::string& name, int* born, int* died)
{
    std::stringstream ss(line);
    ss >> name;
    ss >> *born;
    ss >> *died;
}

void Database::AddRecord(PersonRecord* newRecord)
{
    DateList.push_back(*newRecord);
}

std::pair<int,int> Database::FindMaxCohort()
{
    std::list<int> alive;
    int stillAlive = 0;
    int startingYear = DateList[0].GetBirthYear();
    int maxYear = startingYear;
    int maxNumber = 0;
    int currentYear = DateList.begin()->GetBirthYear();
    int lastCensus = startingYear - 1;
    std::vector<PersonRecord>::const_iterator birthTraversal;
    for(birthTraversal = DateList.begin(); birthTraversal != DateList.end(); birthTraversal++)
    {
        for(int deathYear = lastCensus; deathYear < currentYear; ++deathYear)
        {
            alive.remove(deathYear);
        }

        if(currentYear == (birthTraversal->GetBirthYear()))
        {
            alive.push_back(birthTraversal->GetDeathYear());
        }
        else
        {
            stillAlive = alive.size();
            if(stillAlive > maxNumber)
            {
                maxNumber = stillAlive;
                maxYear = currentYear;
            }
            lastCensus = currentYear;
            currentYear = (birthTraversal->GetBirthYear());
            alive.push_back(birthTraversal->GetDeathYear());
        }
    }
    stillAlive = alive.size();
    if(stillAlive > maxNumber)
    {
        maxNumber = stillAlive;
        maxYear = currentYear;
    }

   return std::pair<int,int>(maxYear, maxNumber);
}

std::ostream& operator<<(std::ostream& os, Database& database)
{
     std::vector<PersonRecord>::iterator iter;
     for(iter = database.DateList.begin(); iter != database.DateList.end(); ++iter)
     {
         os << *iter << " ";
     }
     os << '\n';
     return os;
}

