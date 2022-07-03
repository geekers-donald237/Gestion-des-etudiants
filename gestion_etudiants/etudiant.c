//made by Geekers-donald237
#include"etudiant.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

etudiant_t* cree_tab_Etudiant(int n){
	etudiant_t* tab=(etudiant_t*)malloc(sizeof(etudiant_t)*n);
	return tab;
}
etudiant_t*stock_etudiant(int n,etudiant_t*tabEtudiant){
	int i;
	tabEtudiant=cree_tab_Etudiant(n);
	for(i=0;i<n;i++){
		printf("entrer le nom de l'etudiant %d\n",i+1);
		scanf("%s",tabEtudiant[i].nom);
		printf("entrer le matricule de l'etudiant %d\n",i+1);
		scanf("%s",tabEtudiant[i].matricule);
		printf("entrer le sexe de l'etudiant %d\n",i+1);
		scanf("%s",tabEtudiant[i].sexe);
		printf("entrer l'age de l'etudiant %d\n",i+1);
		scanf("%d",&tabEtudiant[i].age);
		printf("entrer la filiere de l'etudiant %d\n",i+1);
		scanf("%s",tabEtudiant[i].filiere);
		printf("entrer la moyenne de l'etudiant%d\n",i+1);
		scanf("%f",&tabEtudiant[i].moyenne);
	}
	return tabEtudiant;
}

void affiche_etudiant(int n,etudiant_t*tabEtudiant){
	int i;
	printf("nom\tmatricule\tsexe\tage\tfiliere\t\tmoyenne\n\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t",tabEtudiant[i].nom);
		printf("%s\t\t",tabEtudiant[i].matricule);
		printf("%s\t",tabEtudiant[i].sexe);
		printf("%d\t",tabEtudiant[i].age);
		printf("%s\t\t",tabEtudiant[i].filiere);
		printf("%.2f\n",tabEtudiant[i].moyenne);
	}
	printf("\n");
}

void trie_etudiant(int n,etudiant_t*tabEtudiant){
    etudiant_t tmp;
    int i,j;
	for(i=1;i<n;i++){
		j=i-1;
		while(j>=0 && strcmp(tabEtudiant[j].matricule,tabEtudiant[i].matricule)>0){
			tmp=tabEtudiant[j+1];
			tabEtudiant[j+1]=tabEtudiant[j];
			tabEtudiant[j]=tmp;
			j=j-1;
		}
	}
}

etudiant_t* recherche_dicho(int n,etudiant_t* tabEtudiant,char* matricule){
	int inf,sup,pos,mil;
	inf=0;
	sup=n-1;
	pos=-1;
	while(inf<= sup && pos == -1){
		mil=(sup+inf)/2;
		if(strcmp(tabEtudiant[mil].matricule,matricule)>0){
			sup=mil-1;
		}else if(strcmp(tabEtudiant[mil].matricule,matricule)<0){ 
			inf=mil-1;
		}else { 
			pos=mil;
		}
	}
	if(pos == -1){
		printf("la valeur recherche est inexistante dans le tableau !!\n");
	}else {
		printf("il s'agit de :\n\n");
		printf("nom\tmatricule\tsexe\tage\tfiliere\tmoyenne\n");
		printf("%s\t",tabEtudiant[pos].nom);
		printf("%s\t\t",tabEtudiant[pos].matricule);
		printf("%s\t",tabEtudiant[pos].sexe);
		printf("%d\t",tabEtudiant[pos].age);
		printf("%s\t\t",tabEtudiant[pos].filiere);
		printf("%.2f\n",tabEtudiant[pos].moyenne);
	}
	printf("\n");
	return tabEtudiant;
}

etudiant_t* recherche_etudiant(int n,etudiant_t* tabEtudiant,char* matricule){
	int i=1;
	for(i=0;i<n;i++){
		if(strcmp(tabEtudiant[i].matricule,matricule)==0){ 
			printf("etudiant trouve\n");
			printf("il s'agit de l'etudiant:\n");
			printf("nom\tmatricule\tsexe\tage\tfiliere\tmoyenne\n");
			printf("%s\t",tabEtudiant[i].nom);
			printf("%s\t\t",tabEtudiant[i].matricule);
			printf("%s\t",tabEtudiant[i].sexe);
			printf("%d\t",tabEtudiant[i].age);
			printf("%s\t",tabEtudiant[i].filiere);
			printf("%.2f\n",tabEtudiant[i].moyenne);
			break;
		}	

		printf("\n\n");
	}
	if(strcmp(tabEtudiant[i].matricule,matricule)!=0){ 
		printf("etudiant  pas trouve\n");
	}	
    return tabEtudiant;
}  


etudiant_t* AjoutEtudiant(int n,etudiant_t*tabEtudiant,int pos){
	int i;
	etudiant_t *temp;
	temp=cree_tab_Etudiant(n+1);
	etudiant_t po;
	// pos=pos-1;
	printf("entrer le nom \n");
	scanf("%s",po.nom);
	printf("entrer le matricule\n");
	scanf("%s",po.matricule);
	printf("entrer le sexe \n");
	scanf("%s",po.sexe);
	printf("entrer l'age \n");
	scanf("%d",&po.age);
	printf("entrer la filiere\n");
	scanf("%s",po.filiere);
	printf("entrer la moyenne\n");
	scanf("%f",&po.moyenne);
	printf("nom\tmatricule\tsexe\tage\tfiliere\t\tmoyenne\n");
	for(i=0;i<=n;i++){
		if(i<pos){
			temp[i]=tabEtudiant[i];
		}
		if(i>pos){
			temp[i]=tabEtudiant[i-1];
		}
		if(i==pos){
			temp[i]=po;
		}
		printf("%s\t",temp[i].nom);
		printf("%s\t\t",temp[i].matricule);
		printf("%s\t",temp[i].sexe);
		printf("%d\t",temp[i].age);
		printf("%s\t\t",temp[i].filiere);
		printf("%.2f\n",temp[i].moyenne);
	}
}
int meilleure_moyenne(int n,etudiant_t*tabEtudiant){
	int i,min,moy;
	min=0;
	for(i=0;i<n;i++){
		if(tabEtudiant[i].moyenne>tabEtudiant[min].moyenne)
		min=i;
		// printf("nom\tmatricule\tsexe\tage\tfiliere\t\tmoyenne\n");
		// printf("%s\t",tabEtudiant[min].nom);
		// printf("%s\t\t",tabEtudiant[min].matricule);
		// printf("%s\t",tabEtudiant[min].sexe);
		// printf("%d\t",tabEtudiant[min].age);
		// printf("%s\t",tabEtudiant[min].filiere);
		// printf("%.2f\n",tabEtudiant[min].moyenne);
		// break;
	}
	moy=tabEtudiant[min].moyenne;
	return moy;
}

etudiant_t* DeleteEtudiant(int n,etudiant_t*tabEtudiant,int pos){
	int i,flag=0,moy;
	etudiant_t *temp;
	temp=cree_tab_Etudiant(n);
	tabEtudiant=cree_tab_Etudiant(n);
	for(i=0;i<n;i++){
		if(tabEtudiant[i].moyenne < 10)
		pos=i;
		flag=1;
		n=n-1;
	}	
	if(flag == 1){
		for(i=0;i<n;i++){
			if(i<pos){
				temp[i]=tabEtudiant[i];
			}
			if(i>=pos){
				temp[i]=tabEtudiant[i+1];
			}
			// printf("%s\t",temp[i].nom);
			// printf("%s\t\t",temp[i].matricule);
			// printf("%s\t",temp[i].sexe);
			// printf("%d\t",temp[i].age);
			// printf("%s\t\t",temp[i].filiere);
			// printf("%.2f\n",temp[i].moyenne);
		}
		// for(i=0;i<n-1;i++){
		// }
	}else ("l'element est introuvable\n");	

	return temp;
}

