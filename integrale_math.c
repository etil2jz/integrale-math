/**
 * @file integrale_math.c
 * @author Arthur Blanchot (arthur.blanchot@etu.unilasalle.fr)
 * @brief Programme pour calculer par approximation l'encadrement
 *        d'une intégrale selon les méthodes rectangles, trapèzes.
 * @version 1.0
 * @date 2022-03-06
 */

#include <math.h>
#include <stdio.h>
#include <windows.h>

// On utilise des 'long double' au lieu de 'float'
// afin de pouvoir entrer de plus grands nombres.

// Déclaration de la fonction à intégrer
long double f(long double x) {
    return sqrt(exp(x)); // Remplacez par la fonction que vous souhaitez
}

void rectangle(long double a, long double b) {
    int n; // Combien de sous-intervalles
    printf("Combien de rectangles faut-il utiliser ? : ");
    scanf("%i", &n);
    long double h = (b-a)/n; // Sous-intervalles
    long double aire_inf = 0, aire_sup = 0, x; // Variables pour pouvoir faire ∑aire(rectangle)
    // Boucle pour la somme de 1 à n-1
    for (int i = 1; i < n; i++) {
        aire_inf += h*f(a+i*h);
        aire_sup += h*f(a+(i+1)*h);
    }
    printf("\nL'int%cgrale de %Lf %c %Lf avec la m%cthode des rectangles\nest comprise entre %Lf et %Lf", 130, a, 133, b, 130, aire_inf, aire_sup); // Résultat
}

void trapeze(long double a, long double b) {
    int n; // Combien de sous-intervalles
    printf("Combien de trap%czes faut-il utiliser ? : ", 138);
    scanf("%i", &n);
    long double h = (b-a)/n; // Sous-intervalles
    long double aire_inf = f(a)+f(b), aire_sup = f(a)+f(b), x; // Variables pour pouvoir faire ∑aire(trapèze)
    // Boucle pour la somme de 1 à n-1
    for (int i = 1; i < n; i++) {
        aire_inf += 2*f(a+i*h);
        aire_sup += 2*f(a+(i+1)*h);
    }
    printf("\nL'int%cgrale de %Lf %c %Lf avec la m%cthode des trap%czes\nest comprise entre %Lf et %Lf", 130, a, 133, b, 130, 138, aire_inf*h/2, aire_sup*h/2); // Résultat
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
