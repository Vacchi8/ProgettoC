#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.c"

int main(int argc, char const *argv[])
{   

    int selett=0;
do{
    printf("\n\n\n\n");
    printf("\t\t\t\t_______________________________________\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t|           LEGENDA AZIONI            |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 1)       Inserire un voto           |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 2)      Cancellare un voto          |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 3)  Visualizzare voti della classe  |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 4)      Voti di una materia         |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 5)     Voti di uno studente         |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t| 6)      I voti piu alti             |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    printf("\t\t\t\t|                                     |\n");
    printf("\t\t\t\t|      [per uscire premere 0]         |\n");
    printf("\t\t\t\t|_____________________________________|\n");
    
    printf("\n\n [Inserire un azione]\n");
    scanf(" %d", &selett);    
    switch(selett){
    case 1:
        printf("\n");
        Insvoto();
        printf("\n");
        break;
    case 2:
        printf("\n");
        Cancvoto();
        printf("\n");
        break;
    case 3:
        printf("\n");
        VotoClasse();
        printf("\n");
        break;
    case 4:
        printf("\n");
        VotoMat();
        printf("\n");
        break;
    case 5:
        printf("\n");
        VotoStudente();
        printf("\n");
        break;
    case 6:
        printf("\n");
        VotiMagg();
        printf("\n");
        break;
    case 0:
        break;
    default:
    printf("Numero inserito non consetito,riprovare\n");
    printf("\n");
    }

}while(selett!=0);

printf("Arresto del programma\n");
return 0;
}
