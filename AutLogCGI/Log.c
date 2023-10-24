#include "./Log.h"

Session *getAuthlog(int *n){
    Session *s = calloc(sizeof(Session),1000);
    FILE *file = fopen("/var/log/auth.log","r");
    char *ligne=malloc(1000);
    int i=0;
    if(file == NULL){
        printf("erreur lors de l'ouverture du fichier");
        exit(1);
    }
    while(fgets(ligne,1000,file)!=NULL){
        if(strstr(ligne,"for user")){
            sscanf(ligne,"%[^ ] %[^ ] %[^ ] %*s %*s %*s %*s %[^ ] %*s %*s %s\n",s[i].mois,s[i].jour,s[i].heure,s[i].decri,s[i].user);
            i++;
        }
    }
    *n=i;
    free(ligne);
    fclose(file);
    return s;
}
void printTableAuthlog(Session *s, char *recherche, int *nb){ 
    char user[100],value[10];
    int imp=1,imp2=1,j=0;
    sscanf(recherche,"recherche=%[^&]",user);
    sscanf(recherche,"%*[^=]=%*[^=]=%s",value);
	for(int i=0;i<*nb;i++){
		if(strstr(s[i].user,user)){
            if(imp2){
                if((j<nbPagin*atoi(value) && j>=nbPagin*(atoi(value)-1))){
                    char *date = transformDate(s[i].jour,s[i].mois,2023);
                    printf(
                        "<tr class=\"%s\">"
                            "<td width=\"10%%\">%d</td>"
                            "<td width=\"30%%\"><a class=\"user-link\" href=""http://www.tahina.com/Log.cgi?recherche=%s&page=1"">%s</a></td>"
                            "<td width=\"20%%\" class=\"%s\"><p>%s</p></td>"		
                            "<td width=\"40%%\">%s %s</td>"
                        "</tr>"
                    ,j%2?"paire":"impaire",j+1,s[i].user,s[i].user,strstr(s[i].decri,"opened")?"opened":"closed",s[i].decri,date,s[i].heure);
                }
                j++;
            }
            imp = 0;
            if(i==*nb-1)
                imp2=0;
		}
    }
    if(imp)
        printf(
            "<tr>"
                "<td>none</td>"
                "<td>none</td>"		
                "<td>none</td>"
                "<td>none</td>"
            "</tr>"
        );
    *nb = j;
}
void printPagination(char *recherche, int n){
    char user[100]="";
    char page[10];
    sscanf(recherche,"recherche=%[^&]",user);
    sscanf(recherche,"%*[^=]=%*[^=]=%s",page);
    printf("<div class=\"Pagin\"><div class=""pagin"">");
        if(atoi(page)<=5){
            for (int i = 0; i < 10; i++){
                printf(
                    "<a class=\"%s\" href=""http://www.tahina.com/Log.cgi?recherche=%s&page=%d"">%d</a>"
                ,atoi(page)==i+1?"active":"desactive",user,i+1,i+1);
                if(i == n/nbPagin+(n%nbPagin?1:0) - 1)
                    break;
            }
        }
        else{
            for (int i = atoi(page)-5; i < atoi(page)+5; i++){
                printf(
                    "<a class=\"%s\" href=""http://www.tahina.com/Log.cgi?recherche=%s&page=%d"">%d</a>"
                ,atoi(page)==i+1?"active":"desactive",user,i+1,i+1);
                if(i == n/nbPagin+(n%nbPagin?1:0) - 1)
                    break;
            }
        }
    printf("</div></div>");
}

char *transformDate(char *jour,char *mois,int annee){
    char *date = malloc(1000);
    char *Andro[] = {"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
    char *MoisParDef[] = {"Mar","Avr","Mai","Jun","Jui","Aug","Sep","Oct","Nov","Dec","Jan","Fev"};
    char *Volana[] = {"Martsa","Aprily","May","Jona","Jolay","Aogostra","Septambra","Oktobra","Novambra","Desambra","Janoary","Febroary"};
    int Jour = atoi(jour);
    int m = 0;
    char Mois[100];
    int Annee = annee;
    char andro[100];
    int n=0;
    for(int i = 0; i < 12; i++){
        if(!(strcmp(MoisParDef[i],mois))){
            m = i+3;
            strcpy(Mois,Volana[i]);
        }
    }
    n = (Jour + (26*(m + 1))/10 + (Annee%100) + ((Annee%100)/4) + ((Annee/100)/4) + ((Annee/100)*5))%7;
    strcpy(andro,Andro[n]);
    sprintf(date,"%s %d %s %d",andro,Jour,Mois,Annee);
    return date;
}