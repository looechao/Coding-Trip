#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
static void run(const char* source) {  //输入一段注释
    char c;
    initScanner(source);  //输入一段注释
    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
    }
    switch (c) {
    case 0: return;
    }
}
