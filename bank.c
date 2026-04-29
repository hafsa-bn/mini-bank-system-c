#include <stdio.h>

// Deposer de l'argent (par adresse)
void deposer(float *solde, float montant) {
    if (montant > 0) {
        *solde = *solde + montant;
        printf("Depot reussi.\n");
    } else {
        printf("Montant invalide.\n");
    }
}

// Retirer de l'argent (par adresse)
void retirer(float *solde, float montant) {
    if (montant <= 0) {
        printf("Montant invalide.\n");
    }
    else if (montant > *solde) {
        printf("Solde insuffisant !\n");
    }
    else {
        *solde = *solde - montant;
        printf("Retrait effectue.\n");
    }
}

// Afficher solde
void afficherSolde(float solde) {
    printf("Solde actuel : %.2f DH\n", solde);
}

int main() {
    float solde = 1000.0; // solde initial
    int choix;
    float montant;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Deposer de l'argent\n");
        printf("2. Retirer de l'argent\n");
        printf("3. Afficher le solde\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Montant a deposer : ");
                scanf("%f", &montant);
                deposer(&solde, montant);
                break;

            case 2:
                printf("Montant a retirer : ");
                scanf("%f", &montant);
                retirer(&solde, montant);
                break;

            case 3:
                afficherSolde(solde);
                break;

            case 4:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 4);

    return 0;
}
