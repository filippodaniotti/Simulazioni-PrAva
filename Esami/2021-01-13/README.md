# Esame Prog. Avanzata - 13/01/2021

## Teoria
1. Spiegare nel dettaglio cosa si intende per _metodo astratto_ e fare degli esempi di implementazione.
2. Spiega la differenza tra *copy constructor* e *move constructor* e fai degli esempi di implementazione e uso di copia profonda.
3. Spiega la differenza tra _overload_ ed *override* dei metodi; fornisci degli esempi.
4. Cosa sono i puntatori a funzione? Spiega nel dettaglio, con esempi.

## Pratica
5. Data una lista di interi sia negativi che positivi (inventala) devi costruire una funzione `positivizza` che prende come input la lista suddetta; all’interno della funzione devi creare una lambda che catturi la lista e che metta a 0 tutti i valori negativi nella lista; infine, stampa nel `main` la lista.
6.  * Costruire una classe `Persona` contente i campi `nome`, `cognome` ed `età`; 
    * creare una mappa con chiave stringa e valore lista di `Persona` (`map<string, list<Persona>>`), e questa mappa dovrà contenere 3 valori diversi (con chiavi `“a”`, `“b”`, `“c”`) ed ogni lista dovrà contenere 2 persone diverse; 
    * la mappa sarà istanziata nel main e sarà l’unica variabile nel `main`;
    * iterare su tutti gli elementi della mappa e stampare tutte le persone di ogni lista (non puoi usare un metodo `stampa()` in `Persona`);
    * alla fine itera su tutti gli elementi e rimuovi tutte le persone con età maggiore di 30. 
7. Crea una tal funzione `esponenteKu` che prenda due interi `(exp, x)` e ritorni `x^exp`. La funzione deve gestire varie eccezioni: se l’esponente è negativo fai una stampa, se l’esponente è 0 fanne un’altra, se la base è negativa fa' una giravolta. Lancia un’eccezione diversa per ogni caso; scegli tu la priorità, l'importante è che il programma non deve morire.
8. Crea una `multimap,<string,int>` e inseriscici 10 elementi (dati sotto); crea una multimappa “inversa” che mappa `<int,string>` gli stessi elementi con valori e chiavi scambiati.

    Ecco i 10 elementi:
    `(“A”,3)`
    `(“A”,4) `
    `(“C”, 3) `
    `(“W”, 12) `
    `(“Fsad”, 12) `
    `(“CCC”, 13) `
    `(“A”, 13) `
    `(“NN”, 33) `
    `(“B”, 3) `
    `(“A”, 16)`
