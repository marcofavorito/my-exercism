# Pascal's triangle solution in Prolog

```
pascal(0, []).

pascal(N, P):-
    numlist(1, N, Range),
    maplist(pascalH, Range, P).


pascalH(1, [1]).
pascalH(N, [X|L]) :-
    succ(N1, N),
    pascalH(N1, [X|L1]),
    build([X|L1], L).

build([X], [X]).
build([X,Y|Z], [H|R]):-
    H is X+Y,
    build([Y|Z], R).
    


```

## How does it work?

- `pascal` is the main function and, given a number, return the list of numbers that constitute the triangle pascal. E.g.:

```
pascal(1, L).
L = [[1]]

pascal(2, L).
L = [[1], [1, 1]]

pascal(3, L).
L = [[1], [1, 2, 1]]

```

- `pascal` generates a list of numbers from `N` with `numlist`: `[1]`, `[1,2]`, `[1,2,3]`. Every element of this list will be mapped into a row of the pascal triangle.

- some examples of `pascalH` traces (informally):

```
pascalH(1, [1]).
pascalH(2, [X | L]) :-
  pascalH(1, [X|L1]), %(gives [X | L1] = [1])
  build([X|L1], L).   %(gives L = [1]).
  ; hence: [X | L] = [1, 1]
```

- `build` just build the tail of the row.

E.g. consider the row number 3 `[1,2,3]`. And give it as input of `build`. With `trace` enabled, it gives:

```

[trace]  ?- build([1, 2|[1]], L).
   Call: (8) build([1, 2, 1], _10916) ? creep
   Call: (9) _11142 is 1+2 ? creep
   Exit: (9) 3 is 1+2 ? creep
   Call: (9) build([2, 1], _11144) ? creep
   Call: (10) _11160 is 2+1 ? creep
   Exit: (10) 3 is 2+1 ? creep
   Call: (10) build([1], _11162) ? creep
   Exit: (10) build([1], [1]) ? creep
   Exit: (9) build([2, 1], [3, 1]) ? creep
   Exit: (8) build([1, 2, 1], [3, 3, 1]) ? creep
L = [3, 3, 1] 

```

That is, the tail of row number 4.
