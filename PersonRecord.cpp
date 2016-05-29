//PersonRecord.cpp

#include "PersonRecord.h"

PersonRecord::PersonRecord(int born, int died)
   : BirthYear(born)
   , DeathYear(died)
{
}

PersonRecord::~PersonRecord()
{
}

int PersonRecord::GetBirthYear() const
{
    return BirthYear;
}

int PersonRecord::GetDeathYear() const
{
    return DeathYear;
}

bool PersonRecord::operator==(const PersonRecord& other) const
{
     return ((BirthYear == other.BirthYear) && (DeathYear == other.DeathYear));
}
     
bool PersonRecord::operator<(const PersonRecord& other) const
{
     return ((BirthYear < other.BirthYear) ||
            ((BirthYear == other.BirthYear) && (DeathYear < other.DeathYear)));
}

std::ostream& operator<<(std::ostream& os, PersonRecord record)
{
    os << record.BirthYear << "-" << record.DeathYear;
    return os;
}
