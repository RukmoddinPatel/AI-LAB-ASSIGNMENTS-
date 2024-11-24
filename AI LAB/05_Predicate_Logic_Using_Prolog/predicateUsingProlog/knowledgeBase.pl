% "Hello Rukmoddin Nabab Patel";

love("Rukmoddin", "Coding").
love("Nachiket", "Coding").
love("Sanshodhan", "Coding").

friends(X, Y) :- love(X, Z), love(Y, Z), X \= Y.
