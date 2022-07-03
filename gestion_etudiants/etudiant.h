#ifndef __ETUDIANT_H
#define __ETUDIANT_H

struct 	etudiant_t
{ 
	char nom[50];
	char matricule[50];
	char sexe[1];
	int age;
	char filiere[50];
	float moyenne;
};
typedef struct etudiant_t etudiant_t;

etudiant_t* cree_tab_Etudiant(int n);

etudiant_t* stock_etudiant(int n,etudiant_t*tab_etudiant);

void affiche_etudiant(int n,etudiant_t*tabEtudiant);

etudiant_t* recher_dicho(char* matricule,etudiant_t*T,int n);

etudiant_t* recherche_etudiant(int n,etudiant_t* tabEtudiant,char* matricule);


void trie_etudiant(int n,etudiant_t*tabEtudiant);

etudiant_t* AjoutEtudiant(int n,etudiant_t*tabEtudiant,int pos);

int meilleure_moyenne(int n,etudiant_t*tabEtudiant);

etudiant_t* DeleteEtudiant(int n,etudiant_t*tabEtudiant,int pos);

etudiant_t* recherche_dicho(int n,etudiant_t* tabEtudiant,char* matricule);

#endif 
