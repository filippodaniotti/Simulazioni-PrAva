## Domanda 1
<!-- TBD -->

## Domanda 2
<!-- TBD -->

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
<!-- TBD -->
