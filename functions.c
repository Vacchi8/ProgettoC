#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct.h"

void NewClass(void){ //completa
    FILE *cl;
    FILE *vt;
    char sl, sezione;
    int  n_alunni=0, n_classe=0, i=0;
    char nome[50][400];
    char cognome[50][400];

    //creazione del file(classe e del file dei voti)
    printf("Creare il file(sovrascrive nel caso esista)?\n");
    scanf(" %c", &sl);
    if(sl=='y'){
        cl = fopen("class.txt", "w+");
        vt = fopen("voti_classi.txt", "w+");
        if ((cl == NULL&&vt == NULL)) {
        printf("Errore nella creazione del file.\n");
        }else{
        printf("File delle classi creato.\n");
        printf("File dei voti creato.\n");
        }
     }
    else{ //apertura dei file class e voti
        cl=fopen("class.txt", "a+");
        vt = fopen("voti_classi.txt", "a+");
        if ((cl == NULL && vt == NULL)) {
        printf("Errore nell'apertura del file.\n");
        }else{
        printf("File della classe aperto.\n");
        printf("File dei voti aperto.\n");
        }
     }

    //inizio dell'aquisizione delle informazioni sulla classe 
    printf("Inserire il numero di alunni\n");
    scanf(" %d", &n_alunni);
    printf("Inserire la classe n° e la sezione\n");
    scanf(" %d%c", &n_classe, &sezione);
    for(i=0; i<n_alunni; i++){
        printf("Inserire il nome del %d° alunno\n", i+1);
        scanf("%s", nome[i]);
        printf("Inserire il cognome del %d° alunno\n", i+1);
        scanf("%s", cognome[i]);
    }    

    //scrittura delle informazioni sul file
    fprintf(cl, "Classe:%d%c\n", n_classe, sezione);
    for (i = 0; i < n_alunni; i++)
    {
        fprintf(cl, "%d) %s %s\n", i+1, nome[i], cognome[i]);
    }
    fprintf(cl, "\n");

    fclose(cl);
    fclose(vt);
}

void Insvoto(void) {//completa
    FILE *vt;
    FILE *cl;
    int voto, conf = 0;
    char materia[30], classe[30], classe_src[30], info_stud[100];
    data data_voto;
    
    // Apertura del file in modalità "lettura/scrittura"
    vt = fopen("voti_classi.txt", "a+");
    if (vt == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }
    printf("File dei voti aperto.\n");

    // Apertura del file in modalità "lettura/scrittura"
    cl = fopen("class.txt", "r+");
    if (cl == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }
    printf("File delle classi aperto.\n");

    //cerca la classe
    do{  
    printf("A che classe appartiene l'alunno valutato?\n");
    scanf("%s", classe_src);
    while(fgets(classe, sizeof(classe_src), cl)){
        if (strstr(classe, classe_src)) {
            printf("Classe trovata\n");
            conf=1+1;
        }
    }
    //dice se non è stata trovata la classe
    if(conf  ==0){
            printf("Classe non trovata\n");
            conf=1;
        }
    }while(conf == 1);
    
    // Inserimento voto, materia e nome dell'alunno
    printf("Inserisci il Cognome dell'alunno:\n");
    scanf("%s", info_stud);
    printf("Inserisci il nome della materia:\n");
    scanf("%s", materia);
    printf("Inserisci il voto:\n");
    scanf("%d", &voto);
    printf("Inserire il mese e l'anno di assegnazione\n");
    scanf("%d", &data_voto.mese);
    scanf("%d", &data_voto.anno);
    // Scrittura del voto nel file
    fprintf(vt, "%d;%s;%s;%s;%d;%d\n", voto, materia, info_stud, classe_src, data_voto.mese, data_voto.anno);
    printf("Voto inserito correttamente.\n");
    fclose(vt);
}

void Cancvoto(){
    FILE *vt;
    char materia[30];
    char cognome[30];
    char cognome_src[30];
    char info_stud[200];
    int conf=0;
    
    //verifica degli errori nell'apertura
    vt=fopen("voti_classi.txt", "a+");
        if (vt == NULL) {
        printf("Errore nell'apertura del file.\n");
        }else{
        printf("File dei voti aperto.\n");
        }

    //cerca il cognome
    do{  
    printf("Il cognome dell'alunno?\n");
    scanf(" %s", cognome_src);
    while(fgets(cognome, sizeof(cognome_src), vt)){
        if (strstr(cognome, cognome_src)) {
            printf("Cognome trovato\n");
            conf=1+1;
        }
    }
    //dice se non è stato trovato il cognome
    if(conf  ==0){
            printf("Cognome non registrato\n");
            conf=1;
        }
    }while(conf == 1);




    printf("Porcodio\n");
    fclose(vt);
}
void VotoClasse(){
    printf("VotoClasse\n");
  
}
void VotoMat(){
    printf("Votomat\n");
  
}
void VotoStudente(){
    printf("Votostud\n");
   
}
void VotiMagg(){
    printf("Votimgg\n");
   
}