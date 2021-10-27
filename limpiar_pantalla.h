//***********************************************
//  Algoritmos y Programación II
//  TP-1 ANDYPOLIS
//  limpiar_pantalla.h
//  108400 - Espeche, Victoria
//***********************************************


//detecta el sistema operativo en uso y elige el comando a usar para limpiar la pantalla
#ifdef __linux__
#define LIMPIAR_PANTALLA "clear"
#endif // __MINGW32__

#ifdef __MINGW32__
#define LIMPIAR_PANTALLA "CLS"
#endif // __MINGW32__