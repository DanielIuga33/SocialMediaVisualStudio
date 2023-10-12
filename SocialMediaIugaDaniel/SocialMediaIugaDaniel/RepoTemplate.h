#pragma once
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class RepoTemplate {
private:
	vector<T> temp;
	char* fileName;
public:
	RepoTemplate();
	RepoTemplate(const char* fileName);
	~RepoTemplate() = default;

	vector<T> getAll();
	int getLength();

	void addElem(const T& st);
	void updateElem(const T& oldSt, const T& newSt);
	void deleteElem(const T& st);
private:
	void loadFromFile();
	void saveToFile();
};

template <class T>
RepoTemplate<T>::RepoTemplate()
{
	this->fileName = NULL;
}

template <class T>
RepoTemplate<T>::RepoTemplate(const char* fileName)
{
	if (fileName != NULL)
	{
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	}
	else
	{
		this->fileName = NULL;
	}
	this->loadFromFile();
}


template <class T>
vector<T> RepoTemplate<T>::getAll()
{
	return this->temp;
}

template <class T>
int RepoTemplate<T>::getLength()
{
	return this->temp.size();
}

template <class T>
void RepoTemplate<T>::addElem(const T& st)
{
	this->temp.push_back(st);
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::updateElem(const T& oldSt, const T& newSt)
{
	// modalitatea 1
	//for (int i = 0; i < this->studenti.size(); i++)
	//{
	//	if (this->studenti[i] == oldSt)
	//	{
	//		this->studenti[i] = newSt;
	//	}
	//}

	typename vector<T>::iterator it;
	// modalitatea 2
	/*for (it = this->studenti.begin(); it != this->studenti.end(); it++)
	{
		if (*it == oldSt)
		{
			*it = newSt;
		}
	}*/

	// modalitatea 3
	it = find(this->temp.begin(), this->temp.end(), oldSt);
	// nu s-a gasit niciun student egal cu oldSt
	if (it != this->temp.end())
	{
		*it = newSt;
	}
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::deleteElem(const T& st)
{
	typename vector<T>::iterator it = find(this->temp.begin(), this->temp.end(), st);
	if (it != this->temp.end())
	{
		this->temp.erase(it);
	}
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::loadFromFile()
{
	std::string line;
	ifstream f(fileName);
	while (getline(f, line)) {
		T e(line, ',');
		this->temp.push_back(e);
	}
}

template <class T>
void RepoTemplate<T>::saveToFile()
{
	ofstream f(fileName);
	if (f.is_open()) {
		for (auto e : this->temp) {
			f << e.toString() << std::endl;
		}
	}
}