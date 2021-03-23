#include <iostream>
#include "Stringa_4IB.h"

using namespace std;
#define log(x) cout<<x<<endl;


int main() {

	char arr[4] = { "hel" };

	Stringa_4IB a("ciao");
	Stringa_4IB b;
	Stringa_4IB c('c');
	Stringa_4IB d(arr);

	Stringa_4IB e;
	//cin >> e;
	//cout << e << endl;

	cout << "COSTRUTTORI E OPERATORE <<: " << endl;
	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << " e: " << e << endl;
	cout << "LENGTH" << endl;
	cout << "a: " << a.length() << " b: " << b.length() << " c: " << c.length() << " d: " << d.length() <<" e:" << e.length() << endl;

	log("OPERATOR +");
	Stringa_4IB f = a + c;
	Stringa_4IB g = f + "HELLOOO MORE TEXT";
	Stringa_4IB h = f + arr;
	log(f); log(g); log(h);

	log("OPERATOR +=");
	f += " AGAIN AGAIN";
	g += c;
	h += arr;
	log(f);log(g);log(h);

	log("OPERATOR []");
	cout << "g[5]: " << g[5] << endl;
	
	log("OPERATOR = ");
	a = "Nuova parola";
	cout << a << endl;

	log("-------------------------------------------------------");
	log("NUOVI VALORI:");
	a = "ciao"; b = "ciao"; c = "Ciao"; d = "aa"; e = "zz";
	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << " e: " << e << endl;

	log("OPERATORI > < >= <= == !=");
	cout << "a == b: "<< (a == b) << endl; 
	cout << "a != c: "<< (a != c) << endl;
	cout << "d > e: " << (d > e)  << endl;
	cout << "d <= e: "<< (d <= e) << endl;

	log("-------------------------------------------------------");
	log("NUOVI VALORI:");
	a = "Hello world"; b = "world"; c = "l"; d = ""; e = "";
	cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << " e: " << e << endl;
	log("----------------FIND--------------------");
	cout << "find 'a' in a: " << a.find('a',0) <<endl;
	cout << "find 'o' in a: (offset = 0) " << a.find('o') << endl;
	cout << "find 'o' in a: (offset = 5) " << a.find('o', 5) << endl;
	cout << "find c in a: (offset = 0) " << a.find(c) << endl;
	cout << "find c in a: (offset = 5) " << a.find(c,5) << endl;

	
	log("---------------- SUBSTRING --------------------");
	d = a.substring(2, 5);
	e = a.substring(6);
	cout << "substr a da car 2 per 5 valori: " << d << endl;
	cout << "substr a da car 6: " << e << endl;
	
	log("------------------INSERT--------------------------");

	d = a.insert('Z', 6);
	cout << "insert char 'Z' in pos 6 in a: " << d << endl;
	e = a.insert("hello egain ", 6);
	cout << "insert const char* \"hello again \"  in pos 6 in a: " << e << endl;
	f = a.insert(arr, 3);
	cout << "insert char[] arr  in pos 3 in a: " << f << endl;
	g = a.insert(a, a.length()-1);
	cout << "insert a in pos a.length()-1 in a: " << g << endl;
	
	log("-------------------------------------------------------");
	log("NUOVI VALORI:")
	a = "Nel mezzo del cammin di nostra vita mi ritrovai in una selva oscura che la diritta via era smarrita";
	b = "Questa frase verra' separata dalle a quindi non avra' piu' senso";
	cout << "a: " << endl << a << endl << "b: " << endl << b << endl;

	vector<Stringa_4IB>* splitA = a.split();
	vector<Stringa_4IB>* splitB = b.split('a');

	log("-------------------------------------------------------");
	log("cout vettore a splittata:");
	for (vector<Stringa_4IB>::iterator it = splitA->begin(); it != splitA->end(); it++) {
		cout << *it << endl;
	}
	log("-------------------------------------------------------");
	log("cout vettore b splittata:");
	for (vector<Stringa_4IB>::iterator it = splitB->begin(); it != splitB->end(); it++) {
		cout << *it << endl;
	}
	return 0;
}