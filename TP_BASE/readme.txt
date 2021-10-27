--------------------------------------TP1--------------------------------

COMPILACIÓN : 
g++ obra.cpp interfaz.cpp datos.cpp interaccion.cpp main.cpp -o tp -Werror -Wall -Wconversion

VALGRING :
valgrind --tool=memcheck --leak-check=yes ./tp

EJECUTABLE :
./tp

CONEXIONES :
obra.h-->datos.h-->interfaz.h-->interaccion.h-->main

INFORME BÁSICO
	-Se implementó con el uso de memoria dinámica para la creacion de edificios como los materiales
	-Edificios y Materiales se guardaron en una estructura llamada Obra
	-No pierde memoria
	-Interación con el usuario se probó en ubuntu(no cuento con una pc con windows)

DATOS DEL ALUMNO:
	-Erik FLores
	-104478

DATO PECULIAR:
	-El código se hizo PURAMENTE en VIM!
	- ---> ^ↀᴥↀ^ ---> (＾• ω •＾) ---> =ටᆼට=


