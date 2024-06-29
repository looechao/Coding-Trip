#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

static char* strtoken(Token token) {
    switch (token.type) {
        // ���ַ�Token
    case TOKEN_LEFT_PAREN:      return "(";
    case TOKEN_RIGHT_PAREN:     return ")";
    case TOKEN_LEFT_BRACKET:    return "[";
    case TOKEN_RIGHT_BRACKET:   return "]";
    case TOKEN_LEFT_BRACE:      return "{";
    case TOKEN_RIGHT_BRACE:     return "}";
    case TOKEN_COMMA:           return ",";
    case TOKEN_DOT:             return ".";
    case TOKEN_SEMICOLON:       return ";";
    case TOKEN_TILDE:           return "~";
    case TOKEN_HASH:            return "#";
        // һ���ַ��������ַ���Token
    case TOKEN_PLUS:            return "+";
    case TOKEN_PLUS_PLUS:       return "++";
    case TOKEN_PLUS_EQUAL:      return "+=";
    case TOKEN_MINUS:           return "-";
    case TOKEN_MINUS_MINUS:     return "--";
    case TOKEN_MINUS_EQUAL:     return "-=";
    case TOKEN_MINUS_GREATER:   return "->";
    case TOKEN_STAR:            return "*";
    case TOKEN_STAR_EQUAL:      return "*=";
    case TOKEN_SLASH:           return "/";
    case TOKEN_SLASH_EQUAL:     return "/=";
    case TOKEN_PERCENT:         return "%";
    case TOKEN_PERCENT_EQUAL:   return "%=";
    case TOKEN_AMPER:           return "&";
    case TOKEN_AMPER_EQUAL:     return "&=";
    case TOKEN_AMPER_AMPER:     return "&&";
    case TOKEN_PIPE:            return "|";
    case TOKEN_PIPE_EQUAL:      return "|=";
    case TOKEN_PIPE_PIPE:       return "||";
    case TOKEN_HAT:             return "^";
    case TOKEN_HAT_EQUAL:       return "^=";
    case TOKEN_EQUAL:           return "=";
    case TOKEN_EQUAL_EQUAL:     return "==";
    case TOKEN_BANG:            return "!";
    case TOKEN_BANG_EQUAL:      return "!=";
    case TOKEN_LESS:            return "<";
    case TOKEN_LESS_EQUAL:      return "<=";
    case TOKEN_LESS_LESS:       return "<<";
    case TOKEN_GREATER:         return ">";
    case TOKEN_GREATER_EQUAL:   return ">=";
        // ����ֵ: ��ʶ��, �ַ�, �ַ���, ����
    case TOKEN_IDENTIFIER:      return "IDENTIFIER";
    case TOKEN_CHARACTER:       return "CHARACTER";
    case TOKEN_STRING:          return "STRING";
    case TOKEN_NUMBER:          return "NUMBER";
        // �ؼ���
    case TOKEN_SIGNED:          return "SIGNED";
    case TOKEN_UNSIGNED:        return "UNSIGNED";
    case TOKEN_CHAR:            return "CHAR";
    case TOKEN_SHORT:           return "SHORT";
    case TOKEN_INT:             return "INT";
    case TOKEN_LONG:            return "LONG";
    case TOKEN_FLOAT:           return "FLOAT";
    case TOKEN_DOUBLE:          return "DOUBLE";
    case TOKEN_STRUCT:          return "STRUCT";
    case TOKEN_UNION:           return "UNION";
    case TOKEN_ENUM:            return "ENUM";
    case TOKEN_VOID:            return "VOID";
    case TOKEN_IF:              return "IF";
    case TOKEN_ELSE:            return "ELSE";
    case TOKEN_SWITCH:          return "SWITCH";
    case TOKEN_CASE:            return "CASE";
    case TOKEN_DEFAULT:         return "DEFAULT";
    case TOKEN_WHILE:           return "WHILE";
    case TOKEN_DO:              return "DO";
    case TOKEN_FOR:             return "FOR";
    case TOKEN_BREAK:           return "BREAK";
    case TOKEN_CONTINUE:        return "CONTINUE";
    case TOKEN_RETURN:          return "RETURN";
    case TOKEN_GOTO:            return "GOTO";
    case TOKEN_CONST:           return "CONST";
    case TOKEN_SIZEOF:          return "SIZEOF";
    case TOKEN_TYPEDEF:         return "TYPEDEF";
        // ����Token
    case TOKEN_ERROR:           return "ERROR";
    case TOKEN_EOF:             return "EOF";
    }
}

static void run(const char* source) {
    initScanner(source);
    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.line != line) {
            printf("%4d:%-4d ", token.line, token.column);
            line = token.line;
        }
        else {
            printf("%4d:%-4d ", token.line, token.column);
        }
        printf("%s '%.*s'\n", strtoken(token), token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }
}


static void repl() {
    // ���û��������û�ÿ����һ�д��룬����һ�д��룬����������
    // repl��"read evaluate print loop"����д
    // ��һ�У�runһ��
    char line[1024];
    for (;;) {
        printf("> ");

        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break;
        }

        run(line);
    }
}

static char* readFile(const char* path) {
    // �û������ļ������������ļ������ݶ����ڴ棬����ĩβ���'\0'
    // ע��: ����Ӧ��ʹ�ö�̬�ڴ���䣬���Ӧ������ȷ���ļ��Ĵ�С��
    FILE* stream = fopen(path, "rb");
    if (!stream) {
        fprintf(stderr, "open file %s failed\n", path);
    }

    //ȷ���ļ���С
    fseek(stream, 0, SEEK_END);
    long n = ftell(stream);
    char* content = malloc(n + 1);

    //��ȡ�ļ������ݣ����contentvim����
    rewind(stream);  //�ص��ļ���ͷ
    int bytes = fread(content, 1, n, stream);
    content[bytes] = '\0';

    return content;
}


static void runFile(const char* path) {
    // ����'.c'�ļ�:�û������ļ��������������ļ�������������
    char* source = readFile(path);
    run(source);   //����initScanner��scanToken���ʷ�����
}


int main(int argc, const char* argv[]) {
    if (argc == 1) {
        //���û�в���������뽻��ʽ����
        repl();    //����ʽ����
    }
    else if (argc == 2) {
        // ./scanner���������һ����������Ҫ���������ļ�
        runFile(argv[1]);
    }
    else {
        fprintf(stderr, "Usage: scanner [path]\n");
        exit(1);
    }

    return 0;
}
