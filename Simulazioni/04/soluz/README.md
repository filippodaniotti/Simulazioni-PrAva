## Domanda 1
La keyword `virtual` ha principalmente 2 significati, in `C++`.

Il primo è di forzare il late binding dei metodi che la vedono anteposta nella dichiarazione; per late binding intendiamo che, quando abbiamo un metodo di una classe base che viene overridato in una classe figlia e nel main chiamiamo il suddetto metodo da un'istanza (allocata dinamicamente, importante) della classe figlia, il binding del metodo non viene risolto a compile time, bensì a runtime.
```cpp
class Pasta
{
  ...
  virtual void manteca() { ... }
  ...
}

class Amatriciana
  : public Pasta
{
  ...
  void manteca() { ... }
}

int main () {
  Pasta* p = new Amatriciana();
  p.manteca() // se non avessimo dichiarato manteca() come virtual avremmo errore
}
```
Inoltre, con una precisa sintassi, `virtual` va a indicare che un certo metodo è _puramente virtuale_, ossia che è una firma senza implementazione. La presenza di un metodo puramente virtuale rende la classe stessa puramente virtuale, vale a dire non istanziabile e utilizzabile esclusivamente come classe base da cui derivare altre classi.
```cpp
class Pasticcio
{
  ...
  virtual void sistemaPasticcio() = 0;
  ...
}
```
In ultimo, `virtual` è utilizzata nell'ereditarietà virtuale, un meccanismo che si rende necessario nel momento in cui andiamo a trattare un caso di ereditarietà multipla. Ereditare virtualmente, come nell'esempio qui sotto, previene la doppia chiamata del costruttore della classe base da cui ereditano i due padri della nostra classe figlia.
```cpp
class Persona
{
  ...
}

class Studente
  : virtual public Persona
{
  ...
}

class Faculty
  : virtual public Persona
{
  ...
}

class TA
  : public Faculty
  , public Studente 
{
  ...
}
```
## Domanda 2
Gli iteratori sono delle classi template che fanno l'overloading di alcuni operatori secondo il comportamento che questi hanno nell'aritmetica dei puntatori, di fatto surrogandone il funzionamento e rendendolo conveniente all'uso delle classi della STL. Sono organizzati secondo una particolare gerarchia: _Random access > Bidirectional > Forfard > Input | Output_; inoltre, possono avere l'ulteriore qualificazione di `reverse`, per attraversare il contenitore al contrario, `const`, per prevenire la modifica degli elementi del contenitore durante l'attraversamento, e ovviamente la combinazione di questi ultimi due.

## Domanda 3
Un costruttore implicito è un costuttore a un parametro che viene chiamato automaticamente nel caso in cui a una funzione che accetta un'istanza della classe del costruttore si passi un oggetto del tipo accettato dal costruttore stesso; questo processo è detto _conversione implicita di tipo_.

Supponiamo ad esempio di avere una classe `A` simile a
```cpp
class A {
  private:
    int n;
  public:
    A(int _n) {
        n = _n;
    }
};
```
e inoltre una certa funzione `foo()` che riceve un'istanza di `A`
```cpp
void foo(A a) {
    // do something idk
}
```
La conversione implicita di tipo avviene quando chiamiamo la funzione `foo()` passandole un intero come input:
```cpp
int main() {
    foo(A(5));  // tutto a posto
    foo(5);     // OK: conversione implicita di tipo
}
```
È senza dubbio un comportamento peculiare che può risultare comodo in alcune circostanze, ma confusionario e poco desiderabile in altre. Dovesse rendersi necessario, possiamo impedire al compilatore di accettare la conversione implicita anteponendo la keyword `explicit` nella dichiarazione del costruttore incriminato.
```cpp
...
  public:
    explicit A(int _n) { ... };
...
...
int main() {
    foo(A(5));  // tutto a posto, come prima
    foo(5);     // NON COMPILA, abbiamo usato explicit
}
```

## Domanda 4
miao