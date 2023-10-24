#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUser(){
    FILE *file;
	char line[1000];
    char user[900];
    char home_directory[100];
    char shell[200];
    int uid, gid ,j=0;
    file = fopen("/etc/passwd", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }
	while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^\n]", user, &uid, &gid, home_directory, shell) ==5) {
            if (uid >= 1000 && gid >= 1000 && gid<2000 && uid<2000) {
                printf(
                        "<tr class=\"%s\">"
                            "<td width=\"10%%\">%s</td>"
                            "<td width=\"30%%\">%s</td>"
                            "<td width=\"20%%\">%s</td>"		
                        "</tr>"
                    ,j%2?"paire":"impaire", user, shell , home_directory);
                j++;
            }
        }
    }
    fclose(file);
}

int main() {
	printf("Content-type:text/html\n\n");
	printf(
        "<html>"
        "<head>"
            "<meta charset=\"UTF-8\">"
            "<title>USER</title>"
            "<link rel=\"stylesheet\" href=\"user.css\">"
        "</head>"
        "<body>"
            "<div class=\"container\">"
                "<table>"
                    "<tr class=\"title\">"
                    "<td><h2>USER</h2></td>"
                    "<td><h2>SHELL</h2></td>"
                    "<td><h2>DIRECTORY</h2></td>"
                    "</tr>"
    );
                    printUser();
    printf(
                "</table>"
            "</div>"
        "</body>"
    );
    return 0;
}
