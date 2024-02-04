#include "HashTable.h"

HashTable::HashTable(size_t n)
{
	this->n = n;
	table = new Node * [n] {};
}

HashTable::~HashTable()
{
	for (size_t i = 0; i < n; ++i)
	{
		while (table[i])
		{
			Node* temp = table[i];
			table[i] = table[i]->next;
			delete temp;
		}
	}
	delete[] table;
}

size_t HashTable::size() const
{
	return n;
}

void HashTable::print() const
{
	for (size_t i = 0; i < n; i++)
	{
		if (table[i]) {
			cout << "=> " << i << endl;
			int k = 1;
			Node* cur = table[i];
			while (cur)
			{
				cout << k << ") ";
				cout << cur->value.getHash() << "\t";
				cout << cur->value;
				cur = cur->next;
				k++;
			}

		}
	}
}

void HashTable::push(const Student& st)
{
	size_t hash = st.getHash() % n;
	table[hash] = new Node(st, table[hash]);
}

void HashTable::remove(PIB pib, string group)
{
	Student st(pib.Fname, pib.Lname, pib.Sname, 0, "", group);
	size_t hash = st.getHash() % n;
	Node* cur = table[hash];
	Node* prev = nullptr;

	while (cur)
	{
		if (cur->value.getFname() == pib.Fname && cur->value.getLname() == pib.Lname && cur->value.getSname() == pib.Sname && cur->value.getGroup() == group)
		{
			if (prev) prev->next = cur->next;
			else table[hash] = cur->next;
			delete cur;
			return;
		}

		prev = cur;
		cur = cur->next;
	}
}

Node* HashTable::find(string Lname, string group) const
{
	Student st("", Lname,"", 0, "", group);
	size_t hash = st.getHash() % n;
	Node* cur = table[hash];
	while (cur)
	{
		if (cur->value.getLname() == Lname) return cur;
		cur = cur->next;
	}
	return nullptr;
}

void HashTable::load(string filename)
{
	ifstream fcin(filename);
	if (!fcin.is_open()) throw exception("file not opened");
	string item;
	int age;
	while (fcin >> item) {
		Student st;
		st.setFname(item);
		fcin >> item;
		st.setLname(item);
		fcin >> item;
		st.setSname(item);
		st.setSname(item);
		fcin >> age;
		st.setAge(age);
		fcin >> item;
		st.setBirthday(item);
		fcin >> item;
		st.setGroup(item);
		this->push(st);
		
	}
	fcin.close();
}

void HashTable::save(string filename) const
{
	ofstream  fcout(filename, ios::out | ios::app);
	if (!fcout.is_open()) throw exception("file not opened");
	for (size_t i = 0; i < n; i++)
	{
		if (table[i]) {
			Node* cur = table[i];
			while (cur)
			{
				fcout << cur->value.getFname() << ' ' << cur->value.getLname() << ' ' << cur->value.getSname() << ' ' << cur->value.getAge() << ' '
					<< cur->value.getBirthday() << ' ' << cur->value.getGroup() << endl;
				cur = cur->next;
			}
		}
	}
	fcout.close();
}

