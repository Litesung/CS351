(DEFINE (deleteall atm lst)
 (COND
  (NULL? lst) '())
  ((EQ? atm (CAR lst)) (deleteall atm (CDR lst)))
  ((ELSE (CONS (CAR lst) (deleteall atm (CDR lst)))
))


