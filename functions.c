#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#define MAX_MATERIE 50
#define MAX_LUNGHEZZA 200

struct dati
{
    char nome[30];
    char cognome[30];
    char classe[5];
    int voto;
    char materia[30];
};

struct Data
{
    int mese;
    int anno;
};

void Insvoto(void)// funonzia
{ 
    FILE *vt;
    struct dati alunno;
    struct Data d_valutazione;

    vt = fopen("valutazione.txt", "a+");
    if (vt == NULL)
    {
        printf("Errore nell'apertura del file valutazione.txt\n");
    }
    // chiede e memorizza i dati dello studente
    printf("Inserire il voto\n");
    scanf("%d", &alunno.voto);
    printf("Inserire nome e congnome\n");
    printf("Nome:\n");
    scanf("%s", alunno.nome);
    printf("Cognome:\n");
    scanf("%s", alunno.cognome);
    printf("Inserire la classe\n");
    scanf("%s", alunno.classe);
    printf("Inserire la materia\n");
    scanf("%s", alunno.materia);
    printf("Inserire il mese e l'anno(xx/xxxx) \n");
    printf("Mese:\n");
    scanf("%d", &d_valutazione.mese);
    printf("Anno:\n");
    scanf("%d", &d_valutazione.anno);

    fprintf(vt, "\nStudente:%s %s;Voto:%d;Materia:%s;Classe:%s;Data:%d/%d;", alunno.nome, alunno.cognome, alunno.voto, alunno.materia, alunno.classe, d_valutazione.mese, d_valutazione.anno);
    fclose(vt);
}

void Cancvoto()// non funonzia
{ 
    FILE *vt, *temp;
char nome[30], cognome[30], classe[5], materia[30], buffer[100];
double voto;
int mese, anno;
char stud_nome[30], stud_cognome[30], temp_nome[30], temp_cognome[30], temp_classe[5], temp_materia[30];
double temp_voto;
int temp_mese, temp_anno;
temp = fopen("temp.txt", "w");

// chiede i dati dello studente e del voto da eliminare
printf("Inserire il voto da eliminare:\n");
scanf("%lf", &voto);
printf("Inserire nome e cognome dello studente:\n");
printf("Nome:\n");
scanf("%s", nome);
printf("Cognome:\n");
scanf("%s", cognome);
printf("Inserire la classe:\n");
scanf("%s", classe);
printf("Inserire la materia:\n");
scanf("%s", materia);
printf("Inserire il mese e l'anno(xx/xxxx):\n");
printf("Mese:\n");
scanf("%d", &mese);
printf("Anno:\n");
scanf("%d", &anno);

vt = fopen("valutazione.txt", "r");

if (vt == NULL || temp == NULL)
{
    printf("Errore nell'apertura dei file\n");
    return;
}

int voto_trovato = 0;
while (fgets(buffer, 100, vt) != NULL)
{
    // legge i dati dal file
    sscanf(buffer, "Studente:%s %s;Voto:%lf;Materia:%s;Classe:%s;Data:%*d/%d;%*s", stud_nome, stud_cognome, &temp_voto, temp_materia, temp_classe, &temp_anno);
    sscanf(buffer, "Studente:%*s %*s;Voto:%*lf;Materia:%*s;Classe:%*s;Data:%d/%*d;%*s", &temp_mese);

    // controlla se i dati corrispondono a quelli cercati
    if (strcmp(stud_nome, nome) == 0 && strcmp(stud_cognome, cognome) == 0 && strcmp(temp_classe, classe) == 0 && strcmp(temp_materia, materia) == 0 && temp_voto == voto && temp_anno == anno && temp_mese == mese)
    {
        printf("Il voto è stato eliminato:\n%s", buffer);
        voto_trovato = 1;
    }
    else
    {
        fprintf(temp, "%s", buffer);
    }
}

fclose(vt);
fclose(temp);

if (!voto_trovato) {
    printf("Voto non trovato\n");
    remove("temp.txt");
} else {
    remove("valutazione.txt");
    rename("temp.txt", "valutazione.txt");
}
}

void VotoClasse()//funziona
{
    FILE *vt;
    char classe[5], buffer[100];
    int found = 0;

    printf("Inserisci la classe di cui vuoi visualizzare i voti: ");
    scanf("%s", classe);

    vt = fopen("valutazione.txt", "r");
    if (vt == NULL)
    {
        printf("Errore nell'apertura del file valutazione.txt\n");
        return;
    }

    printf("Voti della classe %s:\n", classe);
    while (fgets(buffer, 100, vt) != NULL)
    {
        if (strstr(buffer, classe) != NULL)
        {
            printf("%s", buffer);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Non ci sono voti per la classe %s.\n", classe);
    }

    fclose(vt);
}

void VotoMat()//funziona
{
    FILE *vt;
    char materia[10], buffer[100];
    int found = 0;

    printf("Inserisci la materia di cui vuoi visualizzare i voti: ");
    scanf("%s", materia);

    vt = fopen("valutazione.txt", "r");
    if (vt == NULL)
    {
        printf("Errore nell'apertura del file valutazione.txt\n");
        return;
    }

    printf("Voti della materia: %s\n", materia);
    while (fgets(buffer, 100, vt) != NULL)
    {
        if (strstr(buffer, materia) != NULL)
        {
            printf("%s", buffer);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Non ci sono voti per la materia %s.\n", materia);
    }

    fclose(vt);
}

void VotoStudente()//funonzia
{
   FILE *vt;
    char cognome[15], buffer[100];
    int found = 0;

    printf("Inserisci il cognome dello studente di cui vuoi visualizzare i voti: ");
    scanf("%s", cognome);

    vt = fopen("valutazione.txt", "r");
    if (vt == NULL)
    {
        printf("Errore nell'apertura del file valutazione.txt\n");
        return;
    }

    printf("Voti di: %s\n", cognome);
    while (fgets(buffer, 100, vt) != NULL)
    {
        if (strstr(buffer, cognome) != NULL)
        {
            printf("%s", buffer);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Non ci sono anocora voti per %s.\n", cognome);
    }

    fclose(vt);
}

void VotiMagg()// funonzia
{
FILE *fp = fopen("valutazione.txt", "r");
if (fp == NULL) {
    printf("Errore nell'apertura del file\n");
    return;
}

// Inizializza un array per memorizzare i voti delle materie
int voti[MAX_MATERIE] = {0};

// Inizializza un array di stringhe per memorizzare i nomi delle materie
char materie[MAX_MATERIE][MAX_LUNGHEZZA];
int num_materie = 0;

// Leggi il file riga per riga
char line[MAX_LUNGHEZZA];
while (fgets(line, MAX_LUNGHEZZA, fp)) {
    // Cerca la materia nella riga
    char *materia_start = strstr(line, "Materia:");
    if (materia_start != NULL) {
        // Estrai il nome della materia
        char materia[MAX_LUNGHEZZA];
        sscanf(materia_start, "Materia:%s", materia);

        // Cerca il voto nella riga
        char *voto_start = strstr(line, "Voto:");
        if (voto_start != NULL) {
            int voto;
            sscanf(voto_start, "Voto:%d", &voto);

            // Cerca la posizione della materia nell'array
            int pos = -1;
            for (int i = 0; i < num_materie; i++) {
                if (strcmp(materie[i], materia) == 0) {
                    pos = i;
                    break;
                }
            }
            // Se la materia non è presente nell'array, aggiungila
            if (pos == -1) {
                if (num_materie >= MAX_MATERIE) {
                    printf("Troppi nomi di materia nel file\n");
                    return;
                }
                pos = num_materie;
                strcpy(materie[num_materie], materia);
                num_materie++;
            }

            // Aggiorna il voto più alto della materia
            if (voto > voti[pos]) {
                voti[pos] = voto;
            }
        }
    }
}

// Chiudi il file
fclose(fp);

// Stampa i voti più alti delle materie
printf("Voti piu' alti per materia:\n");
for (int i = 0; i < num_materie; i++) {
    if (voti[i] > 0) {
        printf("%s: %d\n", materie[i], voti[i]);
    }
}
}


    
