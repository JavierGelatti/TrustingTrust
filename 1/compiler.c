#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

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

typedef struct {
    file source, gcc;
    size_t inputLength;
    int i;
    bool hasErrors;
    string errorDescription;
} compiler_state;

compiler_state state;

char next() {
    if (state.i >= state.inputLength) {
        return 0;
    }

    char character = 0;
    fread(&character, sizeof(char), 1, state.source);
    state.i++;

    return character;
}

void write(string text) {
    fwrite(text, sizeof(char), strlen(text), state.gcc);
    //printf("%s", text);
}

void close() {
    fclose(state.source);
    fclose(state.gcc);
}

void raiseError(string description) {
    state.hasErrors = true;
    state.errorDescription = description;
}

file gcc(string destination) {
    string gccCommand = format("gcc -x c -o %s -", destination);
    return popen(gccCommand, "w");
}

char* character(char c) {
    return format("%c", c);
}

char* interpret(char c) {
    if (c != '\\')
        return character(c);

    c = next();
    if (c == 'n')
        return character(10);
    if (c == '\\')
        return character(92);
    if (c == '\'')
        return character(39);
    if (c == '\"')
        return character(34);

    raiseError("Unknown character");
}

void processString() {
    write("({ char var[] = {");

    int length = 1;
    char character = next();
    while(character != '\"') {
        string interpretation = interpret(character);
        for (int i = 0; i < strlen(interpretation); i++) {
            write(format("%d, ", interpretation[i]));
            length++;
        }
        character = next();
    }

    write("0};");
    write(format("int length = %d;", length));
    write("char* varP = malloc(length * sizeof(char));");
    write("for (int z = 0; z < length; z++) { varP[z] = var[z]; }");
    write("varP; })");
}

void processCharacter() {
    char character = next();
    string interpretation = interpret(character);
    write(format("%d", interpretation[0]));
    next();
}

void compile() {
    char character;
    while (character = next()) {
        if (character == '\'') {
            processCharacter();
        } else if (character == '\"') {
            processString();
        } else {
            write(format("%c", character));
        }
    }
}

int main(int argc, string argv[]) {
    if (argc < 2) {
        printf("%s", "Argumentos insuficientes\n");
        exit(1);
    }

    string source = argv[1];
    string destination = (argc >= 4) ? argv[3] : "a.out";

    state.source = fopen(source, "r");
    state.inputLength = flength(state.source);
    state.i = 0;
    state.gcc = gcc(destination);
    state.hasErrors = false;

    compile();
    close();

    if (state.hasErrors) {
        printf("ERROR: %s\n", state.errorDescription);
        exit(1);
    }
}
