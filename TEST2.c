#include <stdio.h>
#include <stdlib.h>

// Structure pour Feedback
typedef struct Feedback {
    struct Conference *conference;
    int note;
    struct Feedback *suivant;
} Feedback;

// Structure pour Conference
typedef struct Conference {
    char titre[100];
    char intervenant[100];
    int date;
    struct Conference *suivant;
} Conference;

// Structure pour Abonne
typedef struct Abonne {
    char nom[100];
    int age;
    int niveau_etude;
    struct Abonne *suivant;
    struct Abonne *precedent;
    struct Feedback *feedback; // Liste des feedbacks pour cet abonné
} Abonne;

// Fonction pour charger la liste des conférences depuis le fichier
void chargerConferences(Conference **listeConferences, const char *nomFichierConferences) {
    FILE *fichier = fopen(nomFichierConferences, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier des conférences");
        exit(EXIT_FAILURE);
    }

    // Lire les conférences depuis le fichier
    while (fscanf(fichier, "%99s %99s %d", (*listeConferences)->titre, (*listeConferences)->intervenant, &(*listeConferences)->date) == 3) {
        // Ajouter le code pour créer une nouvelle conférence et l'ajouter à la liste
        // Vous devrez peut-être utiliser malloc pour allouer dynamiquement de la mémoire pour chaque nouvelle conférence
    }

    fclose(fichier);
}


// Fonction pour charger la liste des abonnés et des feedbacks depuis le fichier
void chargerAbonnesEtFeedbacks(Abonne **listeAbonnes, const char *nomFichierAbonnes) {
    FILE *fichier = fopen(nomFichierAbonnes, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier des abonnés");
        exit(EXIT_FAILURE);
    }

    // Lire les abonnés et les feedbacks depuis le fichier
    while (fscanf(fichier, "%99s %d %d %99s %d", (*listeAbonnes)->nom, &(*listeAbonnes)->age, &(*listeAbonnes)->niveau_etude,
                  (*listeAbonnes)->feedback->conference->titre, &(*listeAbonnes)->feedback->note) == 5) {
        // Ajouter le code pour créer un nouvel abonné, un nouveau feedback et les ajouter à la liste
        // Vous devrez peut-être utiliser malloc pour allouer dynamiquement de la mémoire pour chaque nouvel abonné et feedback
    }

    fclose(fichier);
}

int main() {
    // Initialisez vos listes à NULL
    Abonne *listeAbonnes = NULL;
    Conference *listeConferences = NULL;

    // Chargez les abonnés et les feedbacks depuis le fichier
    chargerAbonnesEtFeedbacks(&listeAbonnes, "abonne.txt");

    // Ajoutez le reste de votre code pour manipuler les listes comme nécessaire

    chargerConferences(&listeConferences, "conference.txt");

    return 0;
}

//Alice 25 3 Title1 4
//Bob 30 2 Title2 3
//Charlie 22 1 Title3 5
