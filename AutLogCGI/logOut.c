#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Set-Cookie: none; expires: 0; httpOnly\n");
    printf("Location: http://www.tahina.com/login.cgi\n\n");
    return 0;
}