# Emulador de Máquinas de Turing
Feito por Eduardo Espadeiro e Guilherme Salvador, com ajuda de João Rui Matos.

### Como instalar?
- Clonem este repositório
- Corram `make` na pasta onde está o Makefile

### Como correr?
```
./emulador exemplos/inverte.txt 110100
```

O executável recebe pelo menos dois argumentos:
- O ficheiro de texto que contém o código da máquina de turing
- A fita inicial (caso seja mais do que uma fita é mais do que um argumento)

### Linguagem
Linguagem para descrever máquinas de turing semelhante à deste [emulador](https://github.com/kiriloman/Multitape-Non-Deterministic-Turing-Machine).
```
<estado atual> <caracteres lidos> <caracteres escritos> <direção> <novo estado>
```

Comentários podem ser escritos em linhas a começar por `;` e há instruções para modificar o comportamento do emulador em si.
```
; Rejeitar em vez de abortar
#reject_on_abort
; Personalizar mensagens de aceitação e de rejeitação
#messages ACEITE!!!! :(
; Importar código de outro ficheiro
; Utilizar caminhos relativos ao executável ou absolutos
#import exemplos/imports/carry.txt
```

### Exemplos
- [/exemplos/abcs.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/abcs.txt) - Aceita palavras com o um número de a's, seguido do mesmo número de b's e seguido do mesmo número de c's.
- [/exemplos/somador.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/somador.txt) - Aceita dois números em binário e devolve a soma dos dois.
- [/exemplos/inverte.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/inverte.txt) - Aceita palavra composta por uns e zeros, troca os uns por zeros e vice-versa.
- [/exemplos/inverte_dois_sentidos.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/inverte.txt) - O mesmo que `/exemplos/inverte.txt`, mas utilizando uma máquina infinita para a direita e para a esquerda.
- [/exemplos/inverte_multifita.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/inverte_multifita.txt) - O mesmo que `/exemplos/inverte.txt`, mas utilizando uma máquina multifita.
- [/exemplos/tres_uns_consecutivos.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/tres_uns_consecutivos.txt) - Aceita palavras que contenham 3 uns consecutivos.
- [/exemplos/unario_binario.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/unario_binario.txt) - Aceita palavras que contenham 3 uns consecutivos, rejeita as outras.
- [/exemplos/universal.txt](https://github.com/EdSwordsmith/emulador-maquinas-turing/tree/master/exemplos/universal.txt) - Máquina de turing universal.
