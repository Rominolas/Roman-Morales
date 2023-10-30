#include <windows.h>
#include <process.h>
#include <time.h>
#include <stdio.h>

void task1(void*){
	//Ciclo infinito para utilizar el procesador
	//Termina el programa presionando la tecla Enter
	while(1){
		//Obtenemos el reloj actual + 50
		clock_t wakeup = clock()+50;
		//Hacemos 50 tiicks de reloj que ocupa uso de CPU
		while (clock()<wakeup){}
		//Despues de 50 tiicks, dormimos 50 milisegundos para darle un respiro al procesador y no
		// trabar el equipo
		Sleep(50);
		
		
		}
	
};

int main (int, char**){
	//Variable requerida para la funci[on _beginthread
	int ThreadNr;
	//Coloca la cantidad de nucleos de tu equipo
	// Puedes jugar con valores altos como 10 a 20, y veras que tu equipo usa el 100% del CPU
	int nucleos=40	;
	//Se realiza el separado por hilos de ejecucion por numero de nucles
	for(int i=0; i<nucleos; i++) _beginthread( task1, 0, &ThreadNr);
	// Escribe cualquier tecla para terminar
	(void) getchar();
	return 0;
	
}
