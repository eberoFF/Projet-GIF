#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Conference {
    char titre [100];
    char intervenant [100];
    int date;
    struct Conference *suivant;
} Conference;

typedef struct Abonne {
    char nom[100];
    int age;
    int niveau etude;
    struct Abonne *suivant;
    struct Abonne *precedent;
} Abonne;

void remplirListeConf(FILE *f, Conference **listeConf) {
    char ligne[1024];
    Conference *nouveau = NULL;
    Conference *temp = *listeConf;

    while (fgets(ligne, sizeof(ligne), f)) {
        nouveau = (Conference *) malloc(sizeof(Conference));
        sscanf(ligne, "%s %s %d", nouveau->titre, nouveau->intervenant, &nouveau->date);
        nouveau->suivant = NULL;

        if (*listeConf == NULL) {
            *listeConf = nouveau;
        } else {
            while (temp->suivant != NULL) {
                temp = temp->suivant;
            }
            temp->suivant = nouveau;
        }
    }
}

void remplirListeAbonne(FILE *f, Abonne **listeAbonne) {
    char ligne[1024];
    Abonne *nouveau = NULL;
    Abonne *temp = *listeAbonne;

    while (fgets(ligne, sizeof(ligne), f)) {
        nouveau = (Abonne *) malloc(sizeof(Abonne));
        sscanf(ligne, "%s %d %d", nouveau->nom, &nouveau->age, &nouveau->niveau etude);
        nouveau->suivant = NULL;
        nouveau->precedent = NULL;

        if (*listeAbonne == NULL) {
            *listeAbonne = nouveau;
        } else {
            while (temp->suivant != NULL) {
                temp = temp->suivant;
            }
            temp->suivant = nouveau;
            nouveau->precedent = temp;
        }
    }
}

int main() {
    Conference *listeConf = NULL;
    Abonne *listeAbonne = NULL;
    FILE *f;

    f = fopen("conferences.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }
    remplirListeConf(f, &listeConf);
    fclose(f);

    f = fopen("abonnes.txt", "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }
    remplirListeAbonne(f, &listeAbonne);
    fclose(f);

    // Ici, vous pouvez utiliser vos listes chainées

    return 0;
}