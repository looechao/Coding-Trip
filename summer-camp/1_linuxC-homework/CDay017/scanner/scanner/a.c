#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
static void run(const char* source) {  //����һ��ע��
    char c;
    initScanner(source);  //����һ��ע��
    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
    }
    switch (c) {
    case 0: return;
    }
}
