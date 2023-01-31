:- style_check(-singleton).

% schedule informations
schedule(ankara,istanbul,1).
schedule(istanbul,ankara,1).

schedule(antalya,izmir,2).
schedule(izmir,antalya,2).

schedule(izmir,istanbul,2).
schedule(istanbul,izmir,2).

% here I add extra schedule
schedule(antalya,mersin,2).
schedule(mersin,antalya,2).

schedule(van,gaziantep,3).
schedule(gaziantep,van,3).

schedule(erzincan,antalya,3).
schedule(antalya,erzincan,3).

schedule(istanbul,rize,4).
schedule(rize,istanbul,4).

schedule(ankara,van,4).
schedule(van,ankara,4).

schedule(diyarbakir,antalya,4).
schedule(antalya,diyarbakir,4).

schedule(rize,ankara,5).
schedule(ankara,rize,5).

% here I add extra schedule
schedule(istanbul,giresun,5).
schedule(giresun,istanbul,5).

schedule(canakkale,erzincan,6).
schedule(erzincan,canakkale,6).

schedule(ankara,izmir,6).
schedule(izmir,ankara,6).

schedule(ankara,diyarbakir,8).
schedule(diyarbakir,ankara,8).

% here all process find the cost and schedule
connectionBasis(X,Y,C) :- schedule(X,Y,C).

connection(X,Y,C):-
    connectionCheck(X,Y,[Y|B],C).

connectionCheck(X,Y,Connections,C) :- 
    connectionFind(X,Y,[X],Connections,C).

checkElementInList(Head, [Head|Tail]).
checkElementInList(Head, [Item|Tail]):- checkElementInList(Head, Tail).

connectionFind(X,Y,A,[Y|A],C) :- 
    connectionBasis(X,Y,C).

connectionFind(X,Y,Connections,B,C) :-
    connectionBasis(X, D, C1),
    not(D == X),not(D == Y),
    not(checkElementInList(D, Connections)),           
    connectionFind(D, Y, [D|Connections],B,C2),
    C is C1+C2.
