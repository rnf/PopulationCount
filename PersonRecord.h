//PersonRecord.h - R. Freedman
#ifndef PERSON_RECORD_H
#define PERSON_RECORD_H

#include <ostream>

class PersonRecord
{
public:
    PersonRecord(int born, int died);
    ~PersonRecord();
       
    int GetBirthYear() const;
    int GetDeathYear() const;
    bool operator==(const PersonRecord& other) const;
    bool operator<(const PersonRecord& other) const;
    friend std::ostream& operator<<(std::ostream& os, PersonRecord record);

private:
    int BirthYear;
    int DeathYear;
};

#endif // PERSON_RECORD_H             
