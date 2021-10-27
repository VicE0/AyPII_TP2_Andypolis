#include "obra.h"

//PRE: Recibe una obra y  un nombre de archivo vàlido
//POS: Carga los edificios en el archivo
void cargarEdificios(Obra* obra, string nombreArchivoEdificios);

//PRE: Recibe una obra y un nombre de archivo vàlido
//POS: Carga los edificios en el archivo
void cargarMateriales(Obra* obra, string nombreArchivoMateriales);

//PRE: Recibe un vector de edificios con su cantidad y el nombre del archivo(válido) 
//POS: Guarda los edificios en el archivo 
void guardarEdificios(Edificio** edificios, int cantEdificios, string nombreArchivoEdificios);

//PRE: Recibe un vector de materiales con su cantidad y el nombre del archivo(válido) 
//POS: Guarda los materiales en el archivo 
void guardarMateriales(Material** materiales, int cantMateriales, string nombreArchivoMaterial);
