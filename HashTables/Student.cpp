#include "Student.h"

size_t Student::getHash() const
{
	size_t hash = 1354;
	for (size_t i = 0; i < group.size(); i++)
	{
		hash += (size_t)group[i];
	}
	return hash;
}
bool Student::operator==(const Student& other) const
{
    return ((Fname == other.Fname) && (Lname == other.Lname) && (Sname == other.Sname));
}

bool Student::operator!=(const Student& other) const
{
    return ((Fname != other.Fname) || (Lname != other.Lname) || (Sname != other.Sname));
}

