square(X, Y) :-
    X > 0,
    X < 65,
    Y is 2 ** (X - 1).

total(Value) :- subtotal(Value, 64).

subtotal(0, 0) :- !.
subtotal(Subtotal, SquareNumber) :-
	PreviousSquare is SquareNumber - 1,
	subtotal(PreviousSubtotal, PreviousSquare), 
	square(SquareNumber, PreviousValue),
	Subtotal is PreviousSubtotal + PreviousValue.

