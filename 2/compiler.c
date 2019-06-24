#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef char* string;
typedef FILE* file;

string format(string format, ...) {
    va_list values;

    va_start(values, format);
    size_t size = vsnprintf(NULL, 0, format, values) + 1;
    va_end(values);

    string buffer = (string) malloc(size + 1);

    va_start(values, format);
    vsnprintf(buffer, size, format, values);
    va_end(values);

    return buffer;
}

size_t flength(file file) {
    size_t currentPosition = ftell(file);

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);

    fseek(file, currentPosition, SEEK_SET);

    return length;
}

string readFile(string fileName) {
    file source = fopen(fileName, "r");

    int inputLength = flength(source);

    string text = malloc(inputLength + 1);
    fread(text, sizeof(char), inputLength, source);

    fclose(source);

    return text;
}

void compile(string code, string destination) {
    string gccCommand = format("gcc -w -x c -o %s -", destination);
    file gcc = popen(gccCommand, "w");

    fwrite(code, sizeof(char), strlen(code), gcc);

    fclose(gcc);
}

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("%s", "Argumentos insuficientes\n");
        exit(1);
    }

    string source = argv[1];
    string destination = (argc >= 4) ? argv[3] : "a.out";

    string code = readFile(source);

    compile(code, destination);
}
