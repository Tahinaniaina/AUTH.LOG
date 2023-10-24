#ifndef __LOG_H__
    #define __LOG_H__
        #include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        typedef struct{
            char mois[256];
            char jour[256];
            char heure[256];
            char decri[256];
            char user[256];
        } Session;
        static int nbPagin = 10;
        Session *getAuthlog(int *n);
        void printTableAuthlog(Session *s, char *recherche, int *nb);
        void printPagination(char *recherche, int n);
        char *transformDate(char *jour,char *mois,int annee);
#endif