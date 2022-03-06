/**
 * @file integrale_math.c
 * @author Arthur Blanchot (arthur.blanchot@etu.unilasalle.fr)
 * @brief Programme pour calculer par approximation l'encadrement
 *        d'une intégrale selon les méthodes rectangles, trapèzes.
 * @version 0.1
 * @date 2022-03-06
 */

#include <math.h>
#include <stdio.h>
#include <windows.h>

// On utilise des 'long double' au lieu de 'float'
// afin de pouvoir entrer de plus grands nombres.

// Déclaration de la fonction à intégrer
long double f(long double x) {
    return 5*pow(x, 3)+7*x-10; // Remplacez par la fonction que vous souhaitez
}

void rectangle(long double a, long double b) {
    int n; // Combien de sous-intervalles
    printf("Combien de rectangles faut-il utiliser ? : ");
    scanf("%i", &n);
    long double h = (b-a)/n; // Sous-intervalles
    long double S = 0, x; // Variables pour les sommes des aires des sous-intervalles
    // Boucle pour la somme de 0 à n-1
    for (int i = 0; i < n; i++) {
        x = a+i*h;
        S += f(x)*h;
    }
    printf("\nL'int%cgrale de %Lf %c %Lf avec la m%cthode des rectangles\nest comprise entre %Lf et %Lf", 130, a, 133, b, 130, S-1, S+1); // Résultat
}

void trapeze(long double a, long double b) {
    int n; // Combien de sous-intervalles
    printf("Combien de trap%czes faut-il utiliser ? : ", 138);
    scanf("%i", &n);
    long double h = (b-a)/n; // Sous-intervalles
    long double S = f(a)+f(b), x; // Variables pour les sommes des aires des sous-intervalles
    // Boucle pour la somme de 0 à n-1
    for (int i = 0; i < n; i++) {
        x = a+i*h;
        S += 2*f(x);
    }
    printf("\nL'int%cgrale de %Lf %c %Lf avec la m%cthode des rectangles\nest comprise entre %Lf et %Lf", 130, a, 133, b, 130, S*h/2-1, S*h/2+1); // Résultat
}


int main() {
    long double a, b;
    int rep;
    system("title Integrale Math");
    // Saisie des bornes a et b
    printf("Entrez la valeur de a : ");
    scanf("%Lf", &a);
    printf("Entrez la valeur de b : ");
    scanf("%Lf", &b);
    printf("\na=%Lf, b=%Lf\n", a, b);
    // Boucle 'Tant que' pour que l'utilisateur soit forcé de répondre 1 ou 2
    do {
        printf("\n\nVeuillez choisir votre m%cthode de calcul\n1. Rectangles\n2. Trap%czes\n : ", 130, 138);
        scanf("%i", &rep);
        // Sélection entre rectangle ou trapèze
        switch (rep) {
            case 1: rectangle(a, b);
                break;
            case 2: trapeze(a, b);
                break;
            default: printf("\nErreur de saisie\n");
        }
    } while (rep < 1 || rep > 3);
}