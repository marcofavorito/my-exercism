real((R, _), R).
imaginary((_, I), I).

conjugate((R, I), (R, In)) :-
  In is 0 - I.

abs((R, I), AbsR) :-
   AbsR is (R^2 + I^2)^(1/2).

add((Ra, Ia), (Rb, Ib), (Rc, Ic)) :-
  Rc is Ra + Rb,
  Ic is Ia + Ib.

sub((Ra, Ia), (Rb, Ib), (Rc, Ic)) :-
  Rc is Ra - Rb,
  Ic is Ia - Ib.


mul((Ra, Ia), (Rb, Ib), (Rc, Ic)) :-
  Rc is Ra * Rb - Ia *Ib,
  Ic is Ra * Ib + Rb * Ia.

div((Ra, Ia), (Rb, Ib), (Rc, Ic)) :-
  Rc is (Ra * Rb + Ia * Ib)/(Rb * Rb + Ib * Ib),
  Ic is (Ia * Rb - Ra * Ib)/(Rb * Rb + Ib * Ib).


