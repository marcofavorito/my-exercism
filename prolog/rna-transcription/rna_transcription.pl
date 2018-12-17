rna_transcription(Rna, Dna) :-
    atom_chars(Rna, RnaChars),
    maplist(complement, RnaChars, DnaChars),
    string_chars(Dna, DnaChars).

complement('G', 'C').
complement('C', 'G').
complement('T', 'A').
complement('A', 'U').

