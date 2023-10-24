#include "Log.h"

int main(){
    int lenghtSession = 0;
    Session *s = getAuthlog(&lenghtSession);
    char *session = getenv("HTTP_COOKIE");
    char *recherche = getenv("QUERY_STRING");
    //char recherche[] = "recherche=&page=1";
    if(!recherche[0]){
        recherche = malloc(100);
        strcpy(recherche,"recherche=&page=1");
    }
    if(strcmp(session,"none")==0 || session==NULL)
        printf("Location: http://www.tahina.com/login.cgi\n");
    printf("Cache-Control: no-cache, no-store, must-revalidate\n");
    printf("Pragma: no-cache\n");
    printf("Expires: 0\n");
    printf("Content-Type: text/html\n\n");

    printf(
        "<html>"
        "<head>"
            "<meta charset=\"UTF-8\">"
            "<title>Auth.log</title>"
            "<link rel=\"stylesheet\" href=\"Log1.css\">"
        "</head>"
        "<body>"
            "<div class=\"container\">"
                "<div class=\"head\">"
                    "<div class=\"title\"><svg xmlns=\"http://www.w3.org/2000/svg\" height=\"3em\" viewBox=\"0 0 448 512\"><path d=\"M224 256A128 128 0 1 0 224 0a128 128 0 1 0 0 256zm-45.7 48C79.8 304 0 383.8 0 482.3C0 498.7 13.3 512 29.7 512H418.3c16.4 0 29.7-13.3 29.7-29.7C448 383.8 368.2 304 269.7 304H178.3z\"/></svg><h2> %s </h2></div>"
                    "<form action=\"Log.cgi\" method=\"get\">"
                        "<div class=\"search\">"
                            "<input type=\"text\" name=\"recherche\" placeholder=\"search\" required>"
                            "<input type=\"hidden\" name=\"page\" value=\"1\">"
                            "<button type=\"submit\"><svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1.5em\" viewBox=\"0 0 512 512\"><path d=\"M416 208c0 45.9-14.9 88.3-40 122.7L502.6 457.4c12.5 12.5 12.5 32.8 0 45.3s-32.8 12.5-45.3 0L330.7 376c-34.4 25.2-76.8 40-122.7 40C93.1 416 0 322.9 0 208S93.1 0 208 0S416 93.1 416 208zM208 352a144 144 0 1 0 0-288 144 144 0 1 0 0 288z\"/></svg></button>"
                        "</div>"
                    "</form>"
                    "<a href=\"http://www.tahina.com/logOut.cgi\"><svg xmlns=\"http://www.w3.org/2000/svg\" height=\"1.5em\" viewBox=\"0 0 512 512\"><path d=\"M377.9 105.9L500.7 228.7c7.2 7.2 11.3 17.1 11.3 27.3s-4.1 20.1-11.3 27.3L377.9 406.1c-6.4 6.4-15 9.9-24 9.9c-18.7 0-33.9-15.2-33.9-33.9l0-62.1-128 0c-17.7 0-32-14.3-32-32l0-64c0-17.7 14.3-32 32-32l128 0 0-62.1c0-18.7 15.2-33.9 33.9-33.9c9 0 17.6 3.6 24 9.9zM160 96L96 96c-17.7 0-32 14.3-32 32l0 256c0 17.7 14.3 32 32 32l64 0c17.7 0 32 14.3 32 32s-14.3 32-32 32l-64 0c-53 0-96-43-96-96L0 128C0 75 43 32 96 32l64 0c17.7 0 32 14.3 32 32s-14.3 32-32 32z\"/></svg></a>"
                "</div>"
                "<table>"
                    "<tr class=\"title\">"
                        "<td width=\"10%%\"><h2>id</h2></td>"
                        "<td width=\"30%%\"><h2>User</h2></td>"
                        "<td width=\"20%%\"><h2>Type of session</h2></td>"
                        "<td width=\"40%%\"><h2>Time</h2></td>"
                    "</tr>"
    ,session);
                    printTableAuthlog(s,recherche,&lenghtSession);
    printf(
                "</table>"
    );
                printPagination(recherche,lenghtSession);
    printf(
            "<div>"
        "</body>"
        "</html>"
    );
    free(s);
    return 0;
}