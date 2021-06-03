#include"list.h"


muzei* List::Search(int index) {
	muzei* finded = NULL, * tmp = head;
	int i = 0;
	while (tmp != NULL) {
		if (i == index) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return finded;
}

void List::Add(string exponat, string author, int Age) {

	muzei* tmp = new muzei(exponat, author, Age);
	tmp->next = head;
	tmp->prev = NULL;
	head->prev = tmp;

	head = tmp;
}

void List::Print() {
	muzei* tmp = head;
	while (tmp != NULL) {
		cout << "Exponat: " << tmp->GetExponat() << '\n';
		cout << "Author: "<< tmp->GetAuthor() << '\n';
		cout << "Age: "<< tmp->GetAge() << '\n';
		tmp = tmp->next;
	}
}

void  List::PrintFile(string file) {
	ofstream out(file);
	if (out.is_open())
	{
		muzei* tmp = head;
		while (tmp != NULL) {
			out << tmp->GetExponat() << '\n' << tmp->GetAuthor() << '\n' << tmp->GetAge() << '\n';
			tmp = tmp->next;
		}
	}
	else {
		cout << "Can't open file " << file << '\n';
	}
	out.close();
}

void List::LoadFile(string file) {
	ifstream in(file);
	string _exponat, _author, _age;
	if (in.is_open())
	{
		while (1)
		{
			if (getline(in, _exponat) && getline(in, _author) && getline(in, _age)) {
				int iage = stoi(_age);
				this->Add(_exponat, _author, iage);
			}
			else {
				break;
			}
		}
		in.close();
	}
	else {
		cout << "Can't open file " << file << '\n';
	}

}

void List::Del(int index) {

	muzei* finded = Search(index);
	if (!finded)
		return;

	if (index == 0) {
		this->head = this->head->next;
		this->head->next->prev = NULL;
	}
	else {
		if (finded->prev) {
			finded->prev->next = finded->next;
		}
		if (finded->next) {
			finded->next->prev = finded->prev;
		}
	}
	

	delete finded;

}

void List::Free() {
	muzei* tmp = head;
	while (tmp != NULL) {
		muzei* p = tmp;
		tmp = tmp->next;
		delete p;
	}
}

void List::ChangeAuthor(int index, string newauthor) {
	muzei* finded = Search(index);
	if (!finded) {
		cout << "can't find index: " << index << '\n';
		return;
	}
	finded->SetAuthor(newauthor);
	
}
muzei* List::SearchExponatByAuthor(string author) {
	muzei* finded = NULL, * tmp = head;
	while (tmp != NULL) {
		if (tmp->GetAuthor() == author) {
			finded = tmp;
			break;
		}
		tmp = tmp->next;
	}
	return finded;
}





void Menu::Cls(void)
{
	system("cls");
}
void Menu::Print(void) {
	list.Print();
}
void Menu::Add(void) {
	string exponat, author;
	int age;
	cout << "Enter item: " << endl;
	cout << "Exponat: ";
	cin >> exponat;
	cout << "Age: ";
	cin >> age;
	cout << "Author: ";
	cin >> author;
	list.Add(exponat, author, age);
}
void Menu::Del(void) {
	int index;
	cout << "enter index: " << '\n';
	cin >> index;
	list.Del(index);
}
void Menu::Search(void) {
	string author;
	cout << "Enter author: " << '\n';
	cin >> author;
	muzei* tmp = list.SearchExponatByAuthor(author);
	if (tmp)
		cout << *tmp << '\n';
	else
		cout << "Can't find exponat" << '\n';
}
void Menu::Change(void) {
	int index;
	cin >> index;
	string author;
	cout << "Enter new author: " << '\n';
	cin >> author;
	list.ChangeAuthor(index, author);
}