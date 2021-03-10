# Simulazione Prog. avanzata - 04
## Teoria
1. Spiega approfonditamente quali sono le funzioni della keyword `virtual`, dove possibile produci anche dei semplici esempi significativi. 
2. Con’è un iteratore? Da dove arriva il concetto? Dove viene usato e perché? Quali tipi di iteratori conosci?
3. Come si definisce un convertitore implicito di tipo? Perché si dice implicito? Che utilizzi può avere e, soprattutto, come puoi fare in modo che non venga utilizzato erroneamente?
4. Come si può introdurre la metaprogrammazione in `C++`? Fai un esempio di utilizzo di un template per impelmentare metaprogrammazione. Perché il metaprogramming può essere utile? 

## Pratica
5. Crea una classe `Ciabatta{}` e fa in modo che sia stampabile tramite `cout`. Sappi che la ciabatta non per forza ha dei piedi al suo interno, ma spesso li ha, crea quindi una lista di piedi nella ciabatta, ma creala nell’heap. Implementa quindi tutti i metodi che servono per le occasioni come queste (quando vai a mettere piede nell’heap).
6. Crea due classi `A` e `B` diverse tra loro, entrambe hanno un attributo privato `n`, implementa quindi l’operatore `<` per confrontare due istanze delle tali classi e fallo senza dichiarare metodi d’appoggio come `get_n()`; Inoltre sappi che l’operatore deve funzionare sia per `A < B` che `B < A`.
7. Dichiara un enum (so che sembra troppo semplice, tuttavia questo esercizio è stato scritto appositamente per uno dei due autori [che tuttora non sa risolverlo])
8. Crea una classe `Alpaca`. Un Alpaca ha un nome, no? Ed ha anche un’età e una razza. Tuttavia, gli alpaca sono animali riservati e quindi certe informazioni le vogliono tenere private. 
   
   Bene, ora che hai una classe per gli alpaca creane una per gli `Allevamenti`; un allevamento deve avere una lista di alpaca, ma gli alpaca possono vievere anche senza allevamento, quindi facciamo che si tratta di aggregazione. Creati un costruttore per gli alpaca a cui passi tutto il necessario. Crea una classe allevatore, non ci frega degli allevatori quindi lasciala pure vuota.  
   
   Nel main crea una `mappa<Allevatore, Allevamento>`, in questa devi inserire due allevatori e due allevamenti (uno a testa). Infine crea una lista di alpaca, devono essere 7, dalle migliori fattezze, più i loro nomi sono buffi più sarà alta la mia valutazione. Con una lambda selvaggia cattura la lista di alpaca e assegna quelli in posizione pari ad un allevatore e quelli in posizione dispari all’altro; per fare questo devi accedere al record della mappa e da lì devi aggiungere l’alpaca alla lista dell’allevamento dell’allevatore. 