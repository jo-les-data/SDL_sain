#include "menuPrincipal.h"


//void creerBoutons(SDL_Renderer *renderer) {
///* creation d'un bouton de demarrage
//En parametre:
//- position relative sur l'axe des x
//- position relative sur l'axe des y
//- longueur de la fenetre
//- hauteur de la fenetre
//*/
//	SDL_Rect boutonContainer = { SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,500 };
//	SDL_Texture *boutonDemarrerFont = SDL_CreateTextureFromSurface(renderer, "demarrer.png");
//	Button boutonDemarrer = { 0, &boutonContainer, &boutonDemarrerFont};
//}

void creerFenetrePrincipale(SDL_Renderer *renderer) {
	/* creation de la fenetre du menu principal.
	En parametre :
	-titre de la fenetre 
	-position relative sur x  
	-position relative sur y
	-longueur de la fenetre
	-hauteur de la fenetre
	-flag(definis le type de fenetre)
	*/
    SDL_Window *fenetreMenuPrincipal = SDL_CreateWindow("Hello Platformer!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1000,1000,0);
	if (!fenetreMenuPrincipal) {
		SDL_Quit();
	}
	//creerBoutons(renderer);
}

//void gererClicBoutonDemarrer() {
//	//coordonnees du clic
//	int mouseX;
//	int mouseY;
//	if(mouseX >)
//		SDL_bu
//}

