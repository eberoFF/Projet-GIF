#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�finition des structures pour les conf�rences et les abonn�s
typedef struct Conference {
    char titre[100];
    char intervenant[100];
    int date;
    struct Conference *suivant;
} Conference;

typedef struct Abonne {
    char nom[100];
    int age;
    int niveau_etude;
    struct Abonne *suivant;
    struct Abonne *precedent;
} Abonne;

// D�finition des fonctions pour les conf�rences
void ajouter_conference(Conference **liste, char *titre, char *intervenant, int date) {
    Conference *nouveau = (Conference *)malloc(sizeof(Conference));
    strcpy(nouveau->titre, titre);
    strcpy(nouveau->intervenant, intervenant);
    nouveau->date = date;
    nouveau->suivant = *liste;
    *liste = nouveau;
}

void supprimer_conferences_avant(Conference **liste, int date) {
    Conference *parcours = *liste;
    Conference *precedent = NULL;
    while (parcours != NULL && parcours->date < date) {
        precedent = parcours;
        parcours = parcours->suivant;
    }
    if (precedent != NULL) {
        precedent->suivant = parcours;
    } else {
        *liste = parcours;
    }
}

// D�finition des fonctions pour les abonn�s
void ajouter_abonne(Abonne **liste, char *nom, int age, int niveau_etude) {
    Abonne *nouveau = (Abonne *)malloc(sizeof(Abonne));
    strcpy(nouveau->nom, nom);
    nouveau->age = age;
    nouveau->niveau_etude = niveau_etude;
    nouveau->suivant = *liste;
    nouveau->precedent = NULL;
    if (*liste != NULL) {
        (*liste)->precedent = nouveau;
    }
    *liste = nouveau;
}

void supprimer_abonne(Abonne **liste, char *nom) {
    Abonne *parcours = *liste;
    while (parcours != NULL && strcmp(parcours->nom, nom) != 0) {
        parcours = parcours->suivant;
    }
    if (parcours != NULL) {
        if (parcours->precedent != NULL) {
            parcours->precedent->suivant = parcours->suivant;
        } else {
            *liste = parcours->suivant;
        }
        if (parcours->suivant != NULL) {
            parcours->suivant->precedent = parcours->precedent;
        }
        free(parcours);
    }
}

int main() {
    // Code principal pour g�rer les conf�rences et les abonn�s
    return 0;
}

///////Ce code permet de g�rer les conf�rences et les abonn�s. Vous pouvez adapter ce code pour r�pondre aux autres besoins tels que la sauvegarde et le chargement des donn�es, la recherche de la conf�rence la mieux not�e ou de lister tous les participants � une conf�rence, etc.
