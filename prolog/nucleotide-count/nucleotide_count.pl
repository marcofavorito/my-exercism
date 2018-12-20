
nucleotide_count('', [('A', 0), ('C', 0), ('G', 0), ('T', 0)]).

nucleotide_count(Dna, Counts) :-
    atom_chars(Dna, DnaChars),
    count_nucleotides(DnaChars, [('A', 0), ('C', 0), ('G', 0), ('T', 0)], Counts).

count_nucleotides([], Counts, Counts).
count_nucleotides([Nucleotide | Rest], CurrentCounts, Counts) :-
    count_single_nucleotide(Nucleotide, CurrentCounts, NewCounts),
    count_nucleotides(Rest, NewCounts, Counts).

count_single_nucleotide(Nucleotide, [(OtherNucleotide, OtherCount) | Rest ], NewCounts) :-
    count_single_nucleotide(Nucleotide, Rest, RestCounts),
    append([(OtherNucleotide, OtherCount)], RestCounts, NewCounts).
    
count_single_nucleotide(Nucleotide, [(Nucleotide, Count) | Rest], NewCounts) :-
   NewCount is Count + 1,
   append([(Nucleotide, NewCount)], Rest, NewCounts).

