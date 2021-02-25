## Domanda 1
<!-- TBD -->

## Domanda 2
Un _copy constructor_ è un costruttore che effettua la copia profonda di un'istanza di una certa classe a partire da un lvalue reference passato.

Per copia profonda intendiamo un meccanismo di copia in cui si a a creare una nuova istanza di una certa classe del tutto indipendente da quella passata per effettuare la copia; questo vuol dire che, se la classe presenta degli attributi di tipo puntatore, la copia profonda non copierà semplicemente il valore del puntatore (facendo sì che sia l'istanza passata che quella nuova puntino allo stesso oggetto, con grandi problemi di inconsistenza e deallocazione), andrà ad allocare della nuova memoria e ne copiarà il buffer puntato dal puntatore dell'istanza passata.
```cpp
class A
{
private:
    int a;
    B* pb;
public:
    ...
    A(const A& _a)
    {
        i = _a.i;
        if (_a.pb != NULL){
            pb = new B(*(_a.pb));
        } else {
            pb = NULL;
        }
    }
    ...
}
```

Un _move contructor_ è un costruttore che "trasferisce" i campi valorizzati dell'istanza di una certa classe, passata come rvalue reference, a una nuova istanza, lasciando l'istanza di partenza in uno stato valido. Questo meccanismo è utile quando si vogliono evitare la creazione di innumerevoli oggetti temporanei che vengono distrutti subito nei passaggi per copia. 

Il funzionamento è che i campi statici vedono il loro valore copiato e, nell'istanza passata, "consumato" (settato a $0$, o a una stringa vuota), mentre invece per i campi allocati dinamicamente si copia il valore del puntatore dell'istanza passata a al puntatore di quella nuova, e quindi si assegna il puntatore dell'istanza passata a `nullptr`.
```cpp
class A
{
private:
    int a;
    B* pb;
public:
    ...
    A(A&& _a)
    {
        a = _a.i;
        _a.i = 0; // consumo il parametro statico

        pb = _a.pb; // rubo il puntatore dell'istanza passata
        _a.pb = nullptr; // lascio il puntatore in uno stato valido, per evitare
                         // che la memoria sia cancellata da delle delete
    }
    ...
}
```

## Domanda 3
<!-- TBD -->

## Domanda 4
Un puntatore a funzione è, come espresso dal nome stesso, un puntatore che referenzia una funzione. Nella dichiarazione bisogna specificare tipo di ritorno e tipo dei parametri, ovviamente. La sintassi per la dichiarazione e l'assegnamento a una funzione è questa:
```cpp
// le parentesi attorno a *pfunz sono importanti:
// la loro assenza farebbe sì che l'operatore
// di deferenziazione venga associato al tipo di ritorno, e non a pfunz
int (*pfunz)(double, int);
int f1(double, int);
int f2(double, int);
...
pfunz = f1; // o pfunz = f2, come preferite
```
Quando viene chiamato, l'uso dell'operatore di referenziazione è opzionale:
```cpp
cout << (*pfunz)(2.0, 1) << endl; // ok
cout << pfunz(2.0, 1) << endl; // va bene uguale
```
Dal momento che quello di _puntatore a funzione_ è effettivamente un tipo di dato possiamo farci un certo numero di operazioni potenzialmente interessanti. Ad esempio, possiamo utilizzare l'operatore `typedef`:
```cpp
typedef double (*P)(double);
```
Posso anche realizzare array (o qualsiasi tipo di struttura dati) di puntatori a funzione:
```cpp
map<P, double> m;
m[f1] = 2;
m[f2] = 4;
```
Oppure ancora posso utilizzare un puntatore a funzione come parametro passato a un'altra funzione, aprendo la strada a numerose possibilità di aumento di modularità e astrazione; si pensi, ad esempio, a un uso congiunto con le _lambda expressions_.