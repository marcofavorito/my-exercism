binary(Str, Dec) :-
  atom_chars(Str, Digits),
  [H|T] = Digits,
  atom_length(Digits, Length),
  ( H\='1', H\='0' -> fail; true), 
  atom_number(H, MSB),
  string_chars(TailStr, T),
  binary(TailStr, Num),
  Dec is MSB * 2 ** (Length - 1) + Num.

  
binary("0", 0).
binary("1", 1).


