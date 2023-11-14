#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

typedef struct Conference {
    char date[10];
    char title[100];
    char speaker[100];
    struct Conference *next;
} Conference;

typedef struct Subscriber {
    char name[100];
    int age;
    int level;
    struct Subscriber *next;
    struct Subscriber *prev;
} Subscriber;

Conference *head_conference = NULL;
Subscriber *head_subscriber = NULL;

void add_conference(char *date, char *title, char *speaker) {
    Conference *new_conference = (Conference*) malloc(sizeof(Conference));
    strcpy(new_conference->date, date);
    strcpy(new_conference->title, title);
    strcpy(new_conference->speaker, speaker);
    new_conference->next = head_conference;
    head_conference = new_conference;
}

void delete_conferences(char *date) {
    Conference *temp = head_conference, *prev;
    while (temp != NULL && strcmp(temp->date, date) < 0) {
        head_conference = temp->next;
        free(temp);
        temp = head_conference;
    }
    while (temp != NULL) {
        while (temp != NULL && strcmp(temp->date, date) >= 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

void add_subscriber(char *name, int age, int level) {
    Subscriber *new_subscriber = (Subscriber*) malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    new_subscriber->age = age;
    new_subscriber->level = level;
    new_subscriber->next = head_subscriber;
    if (head_subscriber != NULL) head_subscriber->prev = new_subscriber;
    head_subscriber = new_subscriber;
}

void delete_subscriber(char *name) {
    Subscriber *temp = head_subscriber;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp->next != NULL) temp->next->prev = temp->prev;
            if (temp->prev != NULL) temp->prev->next = temp->next;
            else head_subscriber = temp->next;
            free(temp);
            return;
        }
        temp = temp->next;
    }
}
}
