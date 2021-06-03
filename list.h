#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class muzei {
private:
	string exponat;
	string author;
	int Age;
public:
	muzei* next;
	muzei* prev;
	muzei() {
		next = NULL;
		prev = NULL;
		Age = 0;
	}
	muzei(string exponat, string author, int Age) : exponat(exponat), author(author), Age(Age) {
		next = NULL;
		prev = NULL;
	}
	friend std::ostream& operator<< (std::ostream& out, const muzei& _muzei)
	{
		out << "Exponat: " << _muzei.exponat << '\n';
		out << "Author: " << _muzei.author << '\n';
		out << "Age: " << _muzei.Age << '\n';
		return out;
	}
	friend std::istream& operator>> (std::istream& in, muzei& _muzei)
	{
		in >> _muzei.exponat;
		in >> _muzei.author;
		in >> _muzei.Age;

		return in;
	}
	void SetExponat(string _exponat) {
		this->exponat = _exponat;
	}
	string GetExponat() {
		return this->exponat;
	}

	void SetAuthor(string _author) {
		this->author = _author;
	}
	string GetAuthor() {
		return this->author;
	}
	void SetAge(int _Age) {
		this->Age = _Age;
	}
	int GetAge() {
		return this->Age;
	}

	~muzei() {
	
	}
};

class List {
public:
	muzei* head;
	List() {

	}
	List(muzei ml){
		muzei* tmp = new muzei(ml);
		head = tmp;
	}


	void ChangeAuthor(int index, string newauthor);

	muzei* SearchExponatByAuthor(string name);

	muzei* Search(int index);

	void Add(string exponat, string author, int Age);

	void Print();

	void PrintFile(string file);

	void LoadFile(string file);

	void Del(int index);

	void Free();

	~List() {
	}
};

class Menu {
public:
	List list;
	Menu() {

	}
	Menu(List list) : list(list) {

	}
	void Print(void);
	void Add(void);
	void Del(void);
	void Search(void);
	void Cls(void);
	void Change(void);
};