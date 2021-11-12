#include <stdio.h>
#include <stdbool.h>

// une taille maximale statique (reelle) de tableaux
#define MAX 100
#define MAX_TEST 50

// les déclarations de fonctions
bool estSousTableau(int [], int [], int, int);

// fonctions de tests
bool estSousTableau_test(int [], int [], int, int, bool);
//bool estSousTableau_AllTests(int (*inputs) [], int, bool outputs[]);
//void saisirAllTests(int inputs[][], int nbr_test, bool outputs[]);

// programme principal
void main(){
    //int inputes [MAX_TEST][2*MAX+2];

    int A2 [] = {1, -1, 0, 10, 2, -7, 25};
    int a2 [] = {1, -1, 0, 10, 2, -7};
    
    int A1 [] = {3, 11, 2, 8};
    int a1 [] = {11, 11, 2};

    int A3 [] = {0};
    int a3 [] = {0};

    int A4 [] = {1};
    int a4 [] = {0};

    int A5 [] = {1, 2, -7, 0, 5, -6, 10, 12};
    int a5 [] = {-7, 0, 8, 5, -6};

    // premier test
    if(estSousTableau_test(A1, a1, 4, 3, false)){
        printf("test reussi\n");
    }else{
        printf("le test ne passe pas\n");
    }

    // 2me test
   if(estSousTableau_test(A2, a2, 7, 6, true)){
       printf("test reussi\n");
    }else{
        printf("le test ne passe pas\n");
    }

    // 3me test
   if(estSousTableau_test(A3, a3, 1, 1, true)){
       printf("test reussi\n");
    }else{
        printf("le test ne passe pas\n");
    }

    // 4me test
   if(estSousTableau_test(A4, a4, 1, 1, false)){
       printf("test reussi\n");
    }else{
        printf("le test ne passe pas\n");
    }

    // 5me test
   if(estSousTableau_test(A5, a5, 8, 5, false)){
       printf("test reussi\n");
    }else{
        printf("le test ne passe pas\n");
    }

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

bool estSousTableau_test(int T[], int t[], int longueurT, int longueurt, bool output){
        return estSousTableau(T, t, longueurT, longueurt) == output;
}
/*
bool estSousTableau_AllTests(int (*inputs) [], int max, int nbr_test, bool outputs[]){
    int (*p) [2*max+2];
    for(p=inputs; p<(inputs+nbr_test); p++){

    }
    return true;
}
*/

/*
void saisirAllTests(int inputs[][], int nbr_test, bool outputs[]){
    int i, j;
    int * p = inputs;
    printf("Vous allez saisir %d test:\n");
    for(i=0; i<nbr_test; i++){
        printf("saisie du tst numero %d:\n");
        printf("\tentrer la taille de A et a:");
        scanf("%d %d", p+ i*(2*MAX+2)+2*MAX-2, p+i*(2*MAX+2)+2*MAX-1);
        for(j=0; j<inputs[i][2*MAX+1])
        printf("\tentrer A[%d]: ");

    }
}
*/
