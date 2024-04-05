//Campo de Dados:

ram 500 0   //Armazena o valor 0 no endereço 500.
ram 501 0   //Armazena o valor 0 no endereço 501.
ram 502 1   //Armazena o valor 1 no endereço 502.
ram 503 60  //Armazena o valor 60 no endereço 503.
ram 504 0   //Armazena o valor 0 no endereço 504.

//Campo de Instruções:

cseg         //Marca o início do segmento de código.
org Inicio 0 //Determina que a instrução após o org está no endereço 0.

lda ac,500   //AC = M[500].
str 4092,ac     
add ac,502
str 500,ac

sub ac,503
je ifInicio
jmp Inicio   //PC=inicio -> PC=0, faz com que retorne para o início do programa.

org ifInicio //
lda ac, 501
add ac,502
str 501,ac
str 4093,ac
lda ac, 504
str 500, ac
jmp Inicio //PC=inicio -> PC=0, faz com que retorne para o início do programa.