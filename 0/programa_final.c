#include <stdio.h>
char* self = "#include <stdio.h>%cchar* self = %c%s%c;%cint main() { // Hola%c    printf(self, 10, 34, self, 34, 10, 10, 10, 10);%c}%c";
int main() { // Hola
    printf(self, 10, 34, self, 34, 10, 10, 10, 10);
}
