#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verification(char *username,char *password1,char *password2);

int main(){
    FILE *f = fopen("dataBase.txt","a");
    if(f==NULL){
        printf("Erreur lors de l'ouverture du fichiers\n");
        exit(1);
    }
    char data[1000]="";
    char username[255],password1[255],password2[255];
    int v=0;
    fgets(data,1000,stdin);
    sscanf(data,"username=%[^&]&password1=%[^&]&password2=%s",username,password1,password2);
    v = verification(username,password1,password2);
    if(v)
        printf("Location: http://www.tahina.com/signUp.cgi?%d\n\n",v-1);
    else{
        fprintf(f,"username=%s&password=%s\n",username,password1);
        printf("Location: http://www.tahina.com/login.cgi\n\n");
    }
    fclose(f);
    return 0;
}

int verification(char *username,char *password1,char *password2){
    FILE *file = fopen("dataBase.txt","r");
    char data[255];
    if(strlen(username)<3)
        return 1;
    if(strcmp(password1,password2)!=0)
        return 2;
    if(strlen(password1)<6)
        return 3;
    while(fgets(data,255,file) != NULL){
        char usernameTmp[255];
        sscanf(data,"username=%[^&]",usernameTmp);
        if(strcmp(username,usernameTmp) == 0)
            return 4;
    }
    fclose(file);
    return 0;
}