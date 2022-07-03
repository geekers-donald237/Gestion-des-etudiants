//made by MBIADA_21Q2915
#include"etudiant.h"
#include<stdio.h>
#include<stdlib.h>

int main(){ 
	int n,i;
	do
	{
		printf("entrer le nombre d'etudiant\n");
		scanf("%d",&n);
	}while(n<=0);
	etudiant_t* T;
	etudiant_t *temp;                           
	T=cree_tab_Etudiant(n);
	T=stock_etudiant(n,T);
	affiche_etudiant(n,T);
	int pos;
	do{ 
	printf("entrer la position des elmets a inserer\n");
	scanf("%d",&pos);
	}while(pos<=0);
	temp=AjoutEtudiant(n,T,pos);
	int moy;
	moy=meilleure_moyenne(n,T);
	printf("la note max est : %d\n",moy);
	temp=DeleteEtudiant(n,T,pos);
	printf("entrer le matricule de l'etudiant a rechercher\n\n");
	char* a;
	scanf("%s",a);
	T=recherche_etudiant(n,T,a);
	T=recherche_dicho(n,T,a);
	printf("le tableau trie par insertion est le suivant\n");
	trie_etudiant(n,T);
	affiche_etudiant(n,temp);
	free(T);
	// free(temp);
	return 0; 
}

