#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des structures pour les conférences et les abonnés
typedef struct Feedback {
    struct Conference *conference;
    int note;
    struct Feedback *suivant;
} Feedback;

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
    struct Feedback *feedback; // Liste des feedbacks pour cet abonné
} Abonne;

// Définition des fonctions pour les conférences
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

// Définition des fonctions pour les abonnés
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
        free(parcours); (à éviter free)
    }
}

int main() {
    // Code principal pour gérer les conférences et les abonnés
    return 0;
}

///////Ce code permet de gérer les conférences et les abonnés. Vous pouvez adapter ce code pour répondre aux autres besoins tels que la sauvegarde et le chargement des données, la recherche de la conférence la mieux notée ou de lister tous les participants à une conférence, etc.
