#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("dataBase.txt","r");
    char dataFic[255];
    char data[1000]="";
    char username[255],password[255];
    int imp = 1;
    fgets(data,1000,stdin);
    sscanf(data,"username=%[^&]&password=%s",username,password);

    while(fgets(dataFic,255,file) != NULL){
        char usernameTmp[255],passwordTmp[255];
        sscanf(dataFic,"username=%[^&]",usernameTmp);
        sscanf(dataFic,"%*[^=]=%*[^=]=%s",passwordTmp);
        if(strcmp(username,usernameTmp) == 0 && strcmp(password,passwordTmp) == 0){
            printf("Set-Cookie: %s; expires: 0; httpOnly\n",username);
            printf("Location: http://www.tahina.com/Log.cgi\n\n");
            imp=0;
            return 0;
        }
    }
    if(imp)
        printf("Location: http://www.tahina.com/login.cgi?incorrect identification\n\n");
    fclose(file);
    return 0;
}
