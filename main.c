#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MaxE 100

typedef struct cellule
{
char nomC[20];
struct cellule * suivant;
}cellule;
typedef cellule * List_Cellule;
typedef struct etudiant
{
int id;
char nom[20];
char prenom[20];
List_Cellule LC;
}etudiant;
struct universite
{
etudiant TE[MaxE];
int NbE;
};
typedef struct universite Univ;

void AjoutEtud(Univ *uv, etudiant e)
{
    if(uv->NbE<MaxE)
    {
        uv->TE[uv->NbE]=e;
        uv->NbE++;
    }else
    {
        printf("l'universite est complet");
    }
}
void AjoutCours(Univ *uv, int idE, char * nomC)
{
    List_Cellule p;
    for(int i=0;i<uv->NbE;i++)
    {
        if(uv->TE[i].id==idE)
        {
            List_Cellule nv=malloc(sizeof(cellule));
            strcpy(nv->nomC,nomC);
            nv->suivant=NULL;
            p=uv->TE[i].LC;
            if(p!=NULL)
            {
                 while(p->suivant!=NULL)
                {
                    p=p->suivant;
                }
                p->suivant=nv;

            }else
            {
                 p=nv;
            }

        }else
        {
            printf("l'etudiant n'existe pas");
        }
    }
}
void afficheCours(etudiant e)
{
    List_Cellule p=e.LC;
   while(p!=NULL)
   {
       printf("%s",p->nomC);
       p=p->suivant;
   }
}
void afficheEtudiants(Univ uv)
{
    for(int i=0;i<uv.NbE;i++)
    {
        printf("%d",uv.TE[i].id);
        printf("%s",uv.TE[i].nom);
        printf("%s",uv.TE[i].prenom);
        afficheCours(uv.TE[i]);
    }
}
int nombreCoursE(etudiant e)
{
    int n=0;
    List_Cellule p=e.LC;
    while(p!=NULL)
    {
            n++;
        p=p->suivant;
    }
    return n;
}
etudiant MaxCoursSuivis(Univ uv)
{
    int maxc=0;
    int maxe=0;
    for(int i=0;i<uv.NbE;i++)
    {
        int n=nombreCoursE(uv.TE[i]);
        if(n>maxc)
        {
            maxc=n;
            maxe=i;
        }
    }
    return uv.TE[maxe];
}
int main()
{
    etudiant e1;
    etudiant e2;
    e1.id=1;
    e2.id=2;
    Univ  uv;
    int idE;
    char nomC[20];
    AjoutEtud(&uv,e1);
    AjoutEtud(&uv,e2);
    afficheEtudiants(uv);
    printf("donner l 'ide de l etudiant pour l'ajout de cours");
    scanf("%d",&idE);
    printf("donner le nom de cours a ajoutee");
    scanf("%s",nomC);
    AjoutCours(&uv,idE,&nomC);
    afficheEtudiants(uv);

}
