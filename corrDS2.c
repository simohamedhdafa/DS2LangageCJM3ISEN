#include <stdio.h>
#include <stdbool.h>

// une taille maximale statique (reelle) de tableaux
#define MAX 100

// les déclarations de fonctions
bool estSousTableau(int [], int [], int, int);
void afficherTableau(int [], int, char *);
void saisirTableau(int [], int, char *);

// programme principal
void main(){
    // dclaration de variables
    int A[MAX], a[MAX], Na, NA;
    bool sousTableau = true;

    // saisie de Na et NA 
    do{
        printf("Entrer NA et Na (entre 1 et 100):\n");
        scanf("%d %d", &NA, &Na);
    }while(Na>NA || Na<0 || NA<0 || Na>MAX || NA>MAX);

    // saisie de A et a
    saisirTableau(A, NA, "A");
    saisirTableau(a, Na, "a");

    // affichage de A et a
    afficherTableau(A, NA, "A");
    afficherTableau(a, Na, "a");

    sousTableau = estSousTableau(A, a, NA, Na);

    if(sousTableau) printf("a est sous tab de A.\n");
    else printf("a n'est pas sous tab de A.\n");

    printf("Fin du programme.\n");
}

// implémntation de fonctions
bool estSousTableau(int A[], int a[], int NA, int Na){
    int i=0, j=NA-1, p, q;

    // tester si a est sous tab de A
    for(p=0, q=Na-1; p<=q; p++, q--){
        // idntifier la 1ere occ de a[p] dans A
        while(i<=j){
            if(A[i]==a[p]) break;
            i++;
        } // i pointe sur a[p] dans A ou i>j
        // identifier la premiere occ de droite a gauche de a[q] dans A
        while(j>=i){
            if(A[j]==a[q]) break;
            j--;
        } // j pointe sur a[q] dans A ou j<i
        // si i>j ou j-i<q-p rnvoyer false
        if(i>j || j-i<q-p)
            return false;
    }
    return true;
}

void afficherTableau(int t[], int n, char * nomTab){
    int i;
    printf("Vous avez saisi le tableau %s suivant:\n", nomTab);
    for(i=0; i<n; i++) printf("\t%d", t[i]);
    printf("\n");
}

void saisirTableau(int t[], int n, char * nomTab){
    int i;
    for(i=0; i<n; i++){
        printf("votre tableau %s [%d]=", nomTab, i);
        scanf("%d", &t[i]);
    }
}