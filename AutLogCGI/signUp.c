#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *messageError[] = { "your username must be greater than three characters","your password does not match","your password must be greater than six characters","the user already exists" };
    char *index = getenv("QUERY_STRING");
    int messageErrorIndex;
    char *session = getenv("HTTP_COOKIE");
    
    if(index[0]){
        messageErrorIndex = atoi(index);
    }

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
                "<h1>Sign Up</h1>"
                "<form action=\"http://www.tahina.com/verificationSignUp.cgi\" method=\"post\">"
                    "<div class=\"input-box\">"
                        "<input name=\"username\" type=\"text\" id=\"username\" required/>"
                        "<label htmlFor=\"username\">username</label>"
                        "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1em\" viewBox=\"0 0 448 512\"><path d=\"M224 256A128 128 0 1 0 224 0a128 128 0 1 0 0 256zm-45.7 48C79.8 304 0 383.8 0 482.3C0 498.7 13.3 512 29.7 512H418.3c16.4 0 29.7-13.3 29.7-29.7C448 383.8 368.2 304 269.7 304H178.3z\"/></svg>"
                    "</div>"
                    "<div class=\"input-box\">"
                        "<input name=\"password1\" type=\"password\" id=\"password\" required/>"
                        "<label htmlFor=\"password\">password</label>"
                        "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1em\" viewBox=\"0 0 448 512\"><path d=\"M144 144v48H304V144c0-44.2-35.8-80-80-80s-80 35.8-80 80zM80 192V144C80 64.5 144.5 0 224 0s144 64.5 144 144v48h16c35.3 0 64 28.7 64 64V448c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V256c0-35.3 28.7-64 64-64H80z\"/></svg>"
                    "</div>"
                    "<div class=\"input-box\">"
                        "<input name=\"password2\" type=\"password\" id=\"password\" required/>"
                        "<label htmlFor=\"password\">confirm your password</label>"
                        "<svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1em\" viewBox=\"0 0 448 512\"><path d=\"M144 144v48H304V144c0-44.2-35.8-80-80-80s-80 35.8-80 80zM80 192V144C80 64.5 144.5 0 224 0s144 64.5 144 144v48h16c35.3 0 64 28.7 64 64V448c0 35.3-28.7 64-64 64H64c-35.3 0-64-28.7-64-64V256c0-35.3 28.7-64 64-64H80z\"/></svg>"
                    "</div>"
    );
                    if(index[0])
                        printf("<p class=\"error\">%s</p>",messageError[messageErrorIndex]);
    printf(
                    "<button type=\"submit\" class=\"btn\">Create</button>"
                    "<div class=\"signup-link\">"
                        "<p class=\"text-center my-[1vw] text-white\">Don't have an account? <a href=\"http://www.tahina.com/login.cgi\">Login</a></p>"
                    "</div>"
                "</form>"
            "</div>"
        "</body>"
        "</html>"
    );
    return 0;
}
