#pragma once
#include <iostream>
#include <string>
using namespace std;

class PIB {
public:
	string Fname;
	string Lname;
	string Sname;
};

class Student : private PIB
{
public:
	Student() : Student("", "", "", 0, "", "") {}
	Student(string Fname, string Lname, string Sname, int age, string birthday, string group) : age(age), birthday(birthday), group(group) { 
		this->Fname = Fname; 
		this->Lname = Lname;
		this->Sname = Sname;
	}

	void setAge(size_t age) { this->age = age; }
	size_t getAge() const { return age; }
	void setFname(string Fname) { this->Fname = Fname; }
	string getFname() const { return Fname; }
	void setLname(string Lname) { this->Lname = Lname; }
	string getLname() const { return Lname; }
	void setSname(string Sname) { this->Sname = Sname; }
	string getSname() const { return Sname; }
	void setBirthday(string birthday) { this->birthday = birthday; }
	string getBirthday() const { return birthday; }
	void setGroup(string group) { this->group = group; }
	string getGroup() const { return group; }

	size_t getHash() const;

	bool operator==(const Student& other) const;
	bool operator!=(const Student& other) const;
private:
	size_t age;
	string birthday;
	string group;
};

inline ostream& operator<<(ostream& out, const Student& student) {
	out << "PIB: " << student.getFname() << ' ' << student.getLname() << ' ' << student.getSname() << " |\t";
	out << "Age: " << student.getAge() << " |\t" << "Birthday: " << student.getBirthday() << " |\t" << "Group: " << student.getGroup() << endl;
	return out;
}

inline istream& operator>>(istream& in, Student& student) {
	string txt;
	cout << "Enter PIB: ";
	in >> txt;
	student.setFname(txt);
	in >> txt;
	student.setLname(txt);
	in >> txt;
	student.setSname(txt);
	size_t num;
	cout << "Enter age: ";
	in >> num;
	student.setAge(num);
	cout << "Enter birthday(dd.mm.yyyy): ";
	in >> txt;
	student.setBirthday(txt);
	cout << "Enter group: ";
	in >> txt;
	student.setGroup(txt);
	return in;
}
