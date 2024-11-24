% Facts: Symptoms and their related diseases
symptom(fever, flu).
symptom(cough, flu).
symptom(fever, malaria).
symptom(chills, malaria).
symptom(headache, dengue).
symptom(rash, dengue).



%Rule

disease(Sym1,Sym2,Dis):-
symptom(Sym1,Dis),symptom(Sym2,Dis),Sym1\=Sym2.


%execute

start:- 

write("Welcome to the medical diagnosis system"),nl,
write("please enter the first symptom u have"),
read(Sym1),
write("please enter the seconf symptom u have"),
read(Sym2),

(
    disease(Sym1,Sym2,Dis)->write("you might have "),write(Dis),nl;
    write("you don't have any disease you are healthy chutiya "),nl
).

