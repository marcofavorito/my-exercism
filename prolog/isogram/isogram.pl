

isogram("").

isogram(Str) :-
    atom_chars(Str, Chars),
    build_counts(Chars, [], Counts).
    check_counts(Counts).

build_counts([], Counts, Counts).
build_counts([H | T], CurrentCounts, Counts):-
    count_single_character(H, CurrentCounts, NewCounts),
    build_counts(T, NewCounts, Counts).

count_single_character(Char, [(Char, Count) | Rest], NewCounts) :-
    NewCount is Count + 1,
    append([(Char, NewCount)], Rest, NewCounts).

count_single_character(Char, [(OtherChar, OtherCount) | Rest], NewCounts) :-
    count_single_character(Char, Rest, RestCounts),
    append([(OtherChar, OtherCount)], RestCounts, NewCounts).

count_single_character(Char, [], NewCounts) :-
    append([(Char, 1)], [], NewCounts).

check_counts([]).
check_counts([(Char, Count) | Rest]):-
   check_counts_helper(Rest, Count). 

check_counts_helper([], N).
check_counts_helper([(Char, N) | Rest], N) :-
   check_counts_helper(Rest, N).

check_counts_helper([(Char, OtherN) | Rest], N) :-
   fail.
