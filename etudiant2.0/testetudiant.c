#include "etudiant.h"

/* Charge le fichier et affiche les 2 premiers étudiants.*/
void etudiant1 (void)
{
	Etudiant e;
	FILE *flot;
	flot=fopen("etudiant.txt", "r");
	if (flot==NULL) {
		printf("Un problème d'ouverture du fichier en lecture est survenu.\n");
		exit(1);
	}
	e=lireEtu(flot);
	afficherEtu(e);
	e=lireEtu(flot);
	afficherEtu(e);
	fclose(flot);
}

/* Créer un tableau où y'a tous les étudiants + affiche ce tableau */
void etudiant2 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,i;
	char nomFichier[30];
	printf("Veuillez entrer le nom du fichier étudiant que vous souhaitez utiliser : \n");
	scanf("%s",nomFichier);
	tab=chargeEtu(nomFichier,&nbEtu,&tailleMax);
	afficherToutEtu(tab,nbEtu);
	printf("Le nombre d'étudiant inscrit est de : %d.\n", nbEtu);
	printf("La taille maximale du tableau est de : %d.\n", tailleMax);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}

/* Le tableau va être trié par l'échelon boursier des étudiants */
void etudiant3 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,val,i;
	char id[6];
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	afficherToutEtu(tab,nbEtu);
	printf("\n");
	triDichEtu(tab,nbEtu);
	afficherToutEtu(tab,nbEtu);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}

/* Une fois trié, nous pouvons faire une recherche dichotomique*/
void etudiant4 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,val,l,i;
	char id[6];
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	triDichEtu(tab,nbEtu);
	afficherToutEtu(tab,nbEtu);
	printf("\n");
	printf("Veuillez indiquer l'indentifiant de l'étudiant à rechercher : \n");
	scanf("%s",id);
	l=strlen(id);
	while(l!=5) {
		printf("L'identifiant a 5 caractères maximum. Réessayez :\n");
		scanf("%s%*c",id);
		l=strlen(id);
	}
	val=rechDichEtu(id,tab,nbEtu);
	if (val==nbEtu)
		printf("L'étudiant avec l'id %s n'existe pas... \n",id);
	else if (strcmp(tab[val]->idetud,id)==0)
			printf("L'étudiant ayant pour id : %s existe. Il s'appelle %s %s et a pour indice %d dans le tableau.\n",id,tab[val]->prenom,tab[val]->nom,val);
		else printf("L'étudiant ayant pour id : %s n'existe pas... \n",id);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}

/*Inscription d'un étudiant*/
void etudiant5 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,val,i;
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	triDichEtu(tab,nbEtu);
	afficherToutEtu(tab,nbEtu);
	tab=ajoutEtu(tab,&nbEtu,&tailleMax);
	printf("\n");
	afficherToutEtu(tab,nbEtu);
	printf("\n");
	printf("Le nombre d'étudiant inscrit est de : %d.\n", nbEtu);
	printf("La taille maximale du tableau est de : %d.\n", tailleMax);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}
/*Suppression d'un étudiant);*/
void etudiant6 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,val,i;
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	triDichEtu(tab,nbEtu);
	afficherToutEtu(tab,nbEtu);
	tab=supEtu(tab,&nbEtu);
	printf("\n");
	afficherToutEtu(tab,nbEtu);
	printf("\n");
	printf("Le nombre d'étudiant inscrit est de : %d.\n", nbEtu);
	for (i=0;i<nbEtu;i++) 
		free(tab[i]);
}

/*Sauvegarder dans un fichier binaire le tableau trié*/
void etudiant7 (void)
{
	Etudiant **tab;
	int nbEtu,tailleMax,i;
	tab=chargeEtu("etudiant.txt",&nbEtu,&tailleMax);
	triDichEtu(tab,nbEtu);
	sauvEtu(tab,nbEtu);
	printf("Le nombre d'étudiant sauvegardé dans le fichier est de : %d.\n", nbEtu);
	for (i=0;i<tailleMax;i++) 
		free(tab[i]);
}

/*Lire dans un fichier binaire le tableau*/
void etudiant8 (void)
{
	Etudiant **tab;
	int nb,i;
	tab=restEtu(&nb);
	afficherToutEtu(tab,nb);
	for (i=0;i<nb;i++) 
		free(tab[i]);
}

/* Modification d'un étudiant*/
void etudiant9 (void)
{
	Etudiant **tab;
	int nbEtu,taillemax,i,val;
	tab=chargeEtu("etudiant.txt",&nbEtu, &taillemax);  
	triDichEtu(tab,nbEtu);
	tab=modifEtu(tab,&nbEtu);
	printf("\n");
	afficherToutEtu(tab,nbEtu);
	for (i=0;i<nbEtu;i++)
		free(tab[i]);
}


int main (void)
{
	//etudiant1();
	//etudiant2();
	//etudiant3();
	//etudiant4();
	//etudiant5();
	//etudiant6();
	//etudiant7();
	//etudiant8();
	//etudiant9();
	return 0;
}	
