#include "Student.h"
#include <fstream>
class Node
{
public:
	Node(Student value, Node* next = nullptr) :value(value), next(next) {}
	Student value;
	Node* next;
};

class HashTable
{
public:
	explicit HashTable(size_t n = 100);
	~HashTable();
	size_t size() const;
	void print() const;
	void push(const Student& st);
	void remove(PIB pib, string group);
	Node* find(string Lname, string group) const;
	void load(string filename = "groups.txt");
	void save(string filename = "groups.txt") const;
private:
	Node** table;
	size_t n;


};