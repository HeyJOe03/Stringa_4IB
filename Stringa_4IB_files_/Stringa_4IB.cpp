#include "Stringa_4IB.h"
#include <string.h>

#define Log(x) std::cout<<x<<std::endl

#pragma warning(disable : 4996) //disabilita la deprecazione di strncat() per un problema di VS

	Stringa_4IB::Stringa_4IB() {
		lettere = new char[1]; lettere[0] = '\0';
	}
	Stringa_4IB::Stringa_4IB(const char* a) {
		int l = strlen(a);
		lettere = new char[l];
		for (int i = 0; i <= l + 1; i++) {
			*(lettere + i) = a[i];
		}
	}
	Stringa_4IB::Stringa_4IB(char a[]) {
		int l = strlen(a);
		lettere = new char[l];
		for (int i = 0; i <= l + 1; i++) {
			*(lettere + i) = a[i];
		}
	}
	Stringa_4IB::Stringa_4IB(char a) {
		lettere = new char[2];
		lettere[0] = a; lettere[1] = '\0';
	}
	Stringa_4IB::Stringa_4IB(int b, const char a[]) {
		lettere = new char[b + 1];
		if (lettere != NULL) {
			for (int i = 0; i <= b; i++) {
				*(lettere + i) = a[i];
			}
		}
	}


	/// FIXME: da chiedere alla profe
	/*Stringa_4IB::~Stringa_4IB() {
		delete [] this->lettere;
	}*/

	int Stringa_4IB::length() {
		int lenght = 0;
		if (lettere == NULL) return 0;
		else {
			for (char* i = lettere; *i != '\0'; i++) lenght++;
			return lenght; //comprende anche il \0
		}
	}

	char Stringa_4IB::operator[] (int pos) {
		if (pos >= 0 && pos < this->length()){
			char output;
			output = *(lettere + pos);
			return output;
		}
		else std::cout << "Error" << std::endl;
	};

	Stringa_4IB Stringa_4IB::operator+(char x[]) {
		int L = strlen(x) + strlen(lettere) + 1;
		Stringa_4IB J(L, "");
		strncat(J.lettere, lettere, L);
		strncat(J.lettere, x, L);
		return J;
	}
	Stringa_4IB Stringa_4IB::operator+(const char x[]) {
		int L = strlen(x) + strlen(lettere) + 1;
		Stringa_4IB J(L, "");
		strncat(J.lettere, lettere, L);
		strncat(J.lettere, x, L);
		return J;
	}
	Stringa_4IB Stringa_4IB::operator+(Stringa_4IB x) {
		int L = strlen(x.lettere) + strlen(lettere) + 1;
		Stringa_4IB J(L, "");
		strncat(J.lettere, lettere, L);
		strncat(J.lettere, x.lettere, L);
		return J;
	}

	void Stringa_4IB::operator+=(char x[]) {
		int L = strlen(x) + strlen(lettere) + 1;
		char* nuova_parola = new char[L];
		strcpy(nuova_parola, this->lettere);
		strncat(nuova_parola, x, strlen(x));
		*this = Stringa_4IB(nuova_parola);
		delete[] nuova_parola;
	}
	void Stringa_4IB::operator+=(const char x[]) {
		int L = strlen(x) + strlen(lettere) + 1;
		char* nuova_parola = new char[L];
		strcpy(nuova_parola, this->lettere);
		strncat(nuova_parola, x, strlen(x));
		*this = Stringa_4IB(nuova_parola);
		delete[] nuova_parola;
	}
	void Stringa_4IB::operator+=(Stringa_4IB x) {
		int L = x.length() + strlen(lettere) + 1;
		char* nuova_parola = new char[L];
		strcpy(nuova_parola, this->lettere);
		strncat(nuova_parola, x.lettere, x.length());
		*this = Stringa_4IB(nuova_parola);
		delete[] nuova_parola;
	}

	bool Stringa_4IB::operator< (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) < 0) return true;
		else return false;
	}
	bool Stringa_4IB::operator> (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) > 0) return true;
		else return false;
	}
	bool Stringa_4IB::operator<= (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) <= 0) return true;
		else return false;
	}
	bool Stringa_4IB::operator>= (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) >= 0) return true;
		else return false;
	}
	bool Stringa_4IB::operator== (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) == 0) return true;
		else return false;
	}
	bool Stringa_4IB::operator!= (Stringa_4IB a) {
		if (strcmp(this->lettere, a.lettere) != 0) return true;
		else return false;
	}

	int Stringa_4IB::find(char a, int offset) {
		if (offset < 0 || offset >= this->length()) {
			std::cout << "errore" << std::endl;
			return -1;
		}
		for (int i = offset; i < length(); i++) {
			if (a == *(lettere + i)) {
				return i;
			}
		}
		return -1;
	}
	int Stringa_4IB::find(char a) {
		for (int i = 0; i < length(); i++) {
			if (a == *(lettere + i)) {
				return i;
			}
		}
		return -1;
	}
	int Stringa_4IB::find(Stringa_4IB search) {
		//std::cout << "lenght: " << this->length() << std::endl;
		//std::cout << "Search lenght: " << search.length() << std::endl;
		for (int i = 0; i < this->length() - search.length() + 1; i++) {
			if (lettere[i] == search.lettere[0]) {
				bool trovata = true;
				for (int g = i + 1, f = 1; g < length() && f < search.length() - 1 && trovata; g++, f++) {
					if (lettere[g] != search.lettere[f]) trovata = false;
				}
				if (trovata)return i;
			}
		}
		return -1;
	}
	int Stringa_4IB::find(Stringa_4IB search, int offset) {
		if (offset < 0 || offset >= this->length()) {
			std::cout << "errore" << std::endl;
			return -1;
		}
		for (int i = offset - 1; i < this->length() - search.length() + 1; i++) {
			if (lettere[i] == search.lettere[0]) {
				bool trovata = true;
				//for (int g = i + 1, f = 1; g < length() && f < search.length() - 1 && trovata; g++, f++) {   //ERRORE
				for (int g = i + 1, f = 1; g < length() && f < search.length() && trovata; g++, f++) {
					if (lettere[g] != search.lettere[f]) trovata = false;
				}
				if (trovata)return i;
			}
		}
		return -1;
	}

	Stringa_4IB Stringa_4IB::substring(int start, int length) {
		if (start<0 || start>this->length() || start + length > this->length()) {
			std::cout << "errore" << std::endl;
			return Stringa_4IB("errore"); //implementare throw
		}
		char* nuova_parola = new char[length + 1];
		for (int i = start; i < start+length; i++) {
			nuova_parola[i - start] = *(this->lettere + i);
		}
		nuova_parola[length] = '\0';
		return Stringa_4IB(nuova_parola);
	}
	Stringa_4IB Stringa_4IB::substring(int start) {
		if (start < 0) {
			std::cout << "errore" << std::endl;
			return Stringa_4IB("errore"); //implementare throw
		}
		std::cout << this->length() - start << std::endl;
		char* nuova_parola = new char[this->length() - start];
		for (int i = start; i < this->length(); i++) {
			*(nuova_parola + i - start) = this->lettere[i];
		}
		nuova_parola[this->length() - start] = '\0';
		return Stringa_4IB(nuova_parola);
	}

	Stringa_4IB Stringa_4IB::insert(char stringa_da_inserire[], int pos) {

		if (pos < 0 || pos > strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		if (pos < 0 || pos >= strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		char* prima_meta = new char[pos];
		char* seconda_meta = new char[this->length() - pos];
		for (int i = 0; i < pos; i++) prima_meta[i] = lettere[i];
		prima_meta[pos] = '\0';
		for (int i = pos; i <= this->length(); i++) *(seconda_meta + i - pos) = lettere[i];
		*this = Stringa_4IB(prima_meta) + Stringa_4IB(stringa_da_inserire) + Stringa_4IB(seconda_meta);
		return *this;
	}
	Stringa_4IB Stringa_4IB::insert(const char* stringa_da_inserire, int pos) {
		if (pos < 0 || pos >= strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		if (pos < 0 || pos >= strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		char* prima_meta = new char[pos];
		char* seconda_meta = new char[this->length() - pos];
		for (int i = 0; i < pos; i++) prima_meta[i] = lettere[i];
		prima_meta[pos] = '\0';
		for (int i = pos; i <= this->length(); i++) *(seconda_meta + i - pos) = lettere[i];
		*this = Stringa_4IB(prima_meta) + Stringa_4IB(stringa_da_inserire) + Stringa_4IB(seconda_meta);
		return *this;
	}
	Stringa_4IB Stringa_4IB::insert(Stringa_4IB stringa_da_inserire, int pos) {
		if (pos < 0 || pos >= strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		char* prima_meta = new char[pos];
		char* seconda_meta = new char[this->length() - pos];
		for (int i = 0; i < pos; i++) prima_meta[i] = lettere[i];
		prima_meta[pos] = '\0';
		for (int i = pos; i <= this->length(); i++) *(seconda_meta + i - pos) = lettere[i];
		*this = Stringa_4IB(prima_meta) + Stringa_4IB(stringa_da_inserire.lettere) + Stringa_4IB(seconda_meta);
		return *this;
	}
	Stringa_4IB Stringa_4IB::insert(char car, int pos) {
		if (pos < 0 || pos >= strlen(this->lettere)) {
			std::cout << "ERRORE NELLA INSERT: index out of range" << std::endl;
			return Stringa_4IB();
		}
		char* prima_meta = new char[pos];
		char* seconda_meta = new char[this->length() - pos];
		for (int i = 0; i < pos; i++) prima_meta[i] = lettere[i];
		prima_meta[pos] = '\0';
		for (int i = pos; i <= this->length(); i++) *(seconda_meta + i - pos) = lettere[i];
		*this = Stringa_4IB(prima_meta) + Stringa_4IB(car) + Stringa_4IB(seconda_meta);
		return *this;
	}

	std::vector<Stringa_4IB>* Stringa_4IB::split() {
		return this->split(' ');
	}
	std::vector<Stringa_4IB>* Stringa_4IB::split(char separator) {
		std::vector<Stringa_4IB>* split = new std::vector<Stringa_4IB>();
		Stringa_4IB out;
		for (int i = 0; i < this->length(); i++) {
			if (this->lettere[i] == separator) {
				split->push_back(out);
				out = "";
			}
			else out += this->lettere[i];
		}
		split->push_back(out);
		return split;
	}


