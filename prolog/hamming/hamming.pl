

hamming_distance(Str1, Str2, Dist) :-
    atom_chars(Str1, Chars1),
    atom_chars(Str2, Chars2),
    hamming_distance_helper(Chars1, Chars2, Dist).


hamming_distance_helper([], [], 0).

hamming_distance_helper([H1 | T1], [H2 | T2], Dist) :-
    hamming_distance_helper(T1, T2, NewDist),
    (H1 \= H2 -> Dist is NewDist + 1; Dist is NewDist).

