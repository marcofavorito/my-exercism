square(1, 1) :- !.

square(SquareNumber, Value) :-
	SquareNumber > 1, not(SquareNumber > 64),
	PreviousSquare is SquareNumber - 1,
	square(PreviousSquare, PreviousValue),
	Value is 2 * PreviousValue,
	!.

total(Value) :- subtotal(Value, 64).

subtotal(0, 0) :- !.
subtotal(Subtotal, SquareNumber) :-
	PreviousSquare is SquareNumber - 1,
	subtotal(PreviousSubtotal, PreviousSquare), 
	square(SquareNumber, PreviousValue),
	Subtotal is PreviousSubtotal + PreviousValue.

