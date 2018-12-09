leap(N) :-
  N mod 4 =:= 0, ( not(N mod 100 =:= 0) ; N mod 400 =:= 0 ).

