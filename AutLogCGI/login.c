#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertMessage(char *message);

int main(){
    char *session = getenv("HTTP_COOKIE");
    char *messageError = getenv("QUERY_STRING");
    if(strcmp(session,"none")!=0 || session==NULL)
        printf("Location: http://www.tahina.com/Log.cgi\n");
    if(messageError)
        messageError = convertMessage(messageError);
    printf("Cache-Control: no-cache, no-store, must-revalidate\n");
    printf("Pragma: no-cache\n");
    printf("Expires: 0\n");
    printf("Content-Type: text/html\n\n");

    printf(
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
            "<meta charset=\"UTF-8\">"
            "<title>login</title>"
            "<link rel=\"stylesheet\" href=\"loginAndSignUp.css\">"
        "</head>"
        "<body>"
            "<div class=\"form-box\">"
                "<h1>LOGIN</h1>"
                "<form action=\"http://www.tahina.com/verificationLogin.cgi\" method=\"post\">"
                    "<div class=\"input-box\">"
                        "<input name=\"username\" type=\"text\" id=\"username\" required/>"
                        "<label htmlFor=\"username\">username</label>"
                        "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1em\" viewBox=\"0 0 448 512\"><path d=\"M224 256A128 128 0 1 0 224 0a128 128 0 1 0 0 256zm-45.7 48C79.8 304 0 383.8 0 482.3C0 498.7 13.3 512 29.7 512H418.3c16.4 0 29.7-13.3 29.7-29.7C448 383.8 368.2 304 269.7 304H178.3z\"/></svg>"
                    "</div>"
                    "<div class=\"input-box\">"
                        "<input name=\"password\" type=\"password\" id=\"password\" required/>"
                        "<label htmlFor=\"password\">password</label>"
                        "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1em\" viewBox=\"0 0 448 512\"><path d=\"M144 144v48H304V144c0-44.2-35.8-80-80-80s-80 35.8-80 80zM80 192V144C80 64.5 144.5 0 224 0s144 64.5 144 144v48h16c35.3 0 64 28.7 64 64V448c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V256c0-35.3 28.7-64 64-64H80z\"/></svg>"
                    "</div>"
    );
                    if(messageError)
                        printf("<p class=\"error\">%s</p>",messageError);
    printf(
                    "<button type=\"submit\" class=\"btn\">Login</button>"
                    "<div class=\"signup-link\">"
                        "<p class=\"paragraphe\">Don't have an account? <a href=\"http://www.tahina.com/signUp.cgi\">Sign up</a></p>"
                        "<p class=\"paragraphe\">%s</p>"
                    "</div>"
                "</form>"
            "</div>"
        "</body>"
        "</html>"
    ,session);
    return 0;
}
char *convertMessage(char *message){
    char *result = malloc(255);
    int j=0;
    int i=0;
    while(i<strlen(message)){
        if(message[i]=='%'){
            int tmp;
            sscanf(&message[i+1], "%x", &tmp);
            result[j] = tmp;
            j++;
            i+=3;
        }
        else{
            result[j]=message[i];
            j++;
            i++;
        }
    }
    return result;
}
/*
    Manoratra anaty : printf("Set-Cookie: %s; expires:%s; path:%s",zavatra_soratana,date,chemin);
                     
    Mamaky an ilay cookie : getenv("HTTP_COOKIE");
*/