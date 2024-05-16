#include<stdbool.h>
#include "scanner.h"

typedef struct {
	const char* start;
	const char* current;
	int line;
    int column;
} Scanner;

// ȫ�ֱ���

Scanner scanner;

void initScanner(const char* source) {
	// ��ʼ��scanner
	scanner.start = source;
	scanner.current = source;
	scanner.line = 1;
    scanner.column = 1;
}




static bool isAlpha(char c) {
	return (c >= 'a' && c <= 'z') ||
		   (c >= 'A' && c <= 'Z') ||
			c == '_';
}

static bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

static bool isAtEnd() {
	return *scanner.current == '\0';
}


static char peek() {
	return *scanner.current;
}

static char peekNext() {
	if (isAtEnd()) return '\0';
	return *(scanner.current+1);
}

static char advance() {
    scanner.column++;
    if (peekNext == ' ') {
        scanner.column = 0;
    }
	return *scanner.current++;
}


static bool match(char expected) {
    if (isAtEnd()) return false;
    if (peek() != expected) return false;
    scanner.current++;
    return true;
}

static TokenType checkKeyword(int start, int length, const char* rest, TokenType type) {
    if (scanner.current - scanner.start == start + length &&
        memcmp(scanner.start + start, rest, length) == 0) {
        return type;
    }
    return TOKEN_IDENTIFIER;
}

static Token errorToken(const char* message) {
    Token token;
    token.type = TOKEN_ERROR;
    token.start = message;
    token.length = (int)strlen(message);
    token.line = scanner.line;
    return token;
}

static void skipWhitespace() {
	// �����հ��ַ���' ', '\r' , '\t' '\n'
	// ����//��ͷ��ע��
	// ����scanner.line
	for (;;) {
		char c = peek();
		switch (c) {
			case ' ':
			case '\r':
			case '\t':
				advance();break;
			case '\n':
				scanner.line++;
                scanner.column = 0;
				advance(); break;
			case '/':
				if (peekNext() == '/') {
					while (!isAtEnd() && peek() != '\n') advance();
				}else {
					return;
				}
				break;
			default:
				return;
		}
	}
}


static Token makeToken(TokenType type) {
	Token token;
	token.type = type;
	token.start = scanner.start;
	token.length = (int)(scanner.current - scanner.start);
	token.line = scanner.line;
    token.column = scanner.column - token.length; // ���� token ����ʼ����
    return token;
}


static TokenType identifierType() {
    // ȷ��identifier������Ҫ�����ַ�ʽ��
    // 1. �����еĹؼ��ַ����ϣ���У�Ȼ����ȷ��
    // 2. �����еĹؼ��ַ���Trie���У�Ȼ����ȷ��
    // Trie���ķ�ʽ�����ǿռ��ϻ���ʱ���϶����ڹ�ϣ��ķ�ʽ

    char c = scanner.start[0];
    switch (c) {
        // keywords
    case 'b': return checkKeyword(1, 4, "reak", TOKEN_BREAK);
    case 'c': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'a': return checkKeyword(2, 2, "se", TOKEN_CASE);
            case 'h': return checkKeyword(2, 2, "ar", TOKEN_CHAR);
            case 'o':
                if (len > 3 && scanner.start[2] == 'n') {
                    switch (scanner.start[3]) {
                    case 's': return checkKeyword(4, 1, "t", TOKEN_CONST);
                    case 't': return checkKeyword(4, 4, "inue", TOKEN_CONTINUE);
                    }
                }
            }
        }
        break;
    }
    case 'd': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'e': return checkKeyword(2, 5, "fault", TOKEN_DEFAULT);
            case 'o':
                if (len == 2) return TOKEN_DO;
                else return checkKeyword(2, 4, "uble", TOKEN_DOUBLE);
            }
        }
        break;
    }
    case 'e': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'l': return checkKeyword(2, 2, "se", TOKEN_ELSE);
            case 'n': return checkKeyword(2, 2, "um", TOKEN_ENUM);
            }
        }
        break;
    }
    case 'f': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'l': return checkKeyword(2, 3, "oat", TOKEN_FLOAT);
            case 'o': return checkKeyword(2, 1, "r", TOKEN_FOR);
            }
        }
        break;
    }
    case 'g': return checkKeyword(1, 3, "oto", TOKEN_GOTO);
    case 'i': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'f': return checkKeyword(2, 0, "", TOKEN_IF);
            case 'n': return checkKeyword(2, 1, "t", TOKEN_INT);
            }
        }
        break;
    }
    case 'l': return checkKeyword(1, 3, "ong", TOKEN_LONG);
    case 'r': return checkKeyword(1, 5, "eturn", TOKEN_RETURN);
    case 's': {
        int len = scanner.current - scanner.start;
        if (len > 1) {
            switch (scanner.start[1]) {
            case 'h': return checkKeyword(2, 3, "ort", TOKEN_SHORT);
            case 'i':
                if (len > 2) {
                    switch (scanner.start[2]) {
                    case 'g': return checkKeyword(3, 3, "ned", TOKEN_SIGNED);
                    case 'z': return checkKeyword(3, 3, "eof", TOKEN_SIZEOF);
                    }
                }
                break;
            case 't': return checkKeyword(2, 4, "ruct", TOKEN_STRUCT);
            case 'w': return checkKeyword(2, 4, "itch", TOKEN_SWITCH);
            }
        }
        break;
    }
    case 't': return checkKeyword(1, 6, "ypedef", TOKEN_TYPEDEF);
    case 'u': {
        int len = scanner.current - scanner.start;
        if (len > 2 && scanner.start[1] == 'n') {
            switch (scanner.start[2]) {
            case 'i': return checkKeyword(3, 2, "on", TOKEN_UNION);
            case 's': return checkKeyword(3, 5, "igned", TOKEN_UNSIGNED);
            }
        }
        break;
    }
    case 'v': return checkKeyword(1, 3, "oid", TOKEN_VOID);
    case 'w': return checkKeyword(1, 4, "hile", TOKEN_WHILE);
    }

    // identifier
    return TOKEN_IDENTIFIER;
}


static Token identifier() {
	// IDENTIFIER����: ��ĸ�����ֺ��»���
	while (isAlpha(peek()) || isDigit(peek())) {
		advance();
	}
	// ������Token�����Ǳ�ʶ��, Ҳ�����ǹؼ���, identifierType()������ȷ��Token���͵�
	return makeToken(identifierType());
}

static Token string() {
    // �ַ�����"��ͷ����"��β�����Ҳ��ܿ���
    while (!isAtEnd() && peek() != '"') {
        if (peek() == '\n') {
            return errorToken("Not support multi-line string.");
        }
        advance();
    }

    if (isAtEnd()) return errorToken("Unterminated string.");

    // The closing quote.
    advance();
    return makeToken(TOKEN_STRING);
}

static Token character() {
    // �ַ�'��ͷ����'��β�����Ҳ��ܿ���
    while (!isAtEnd() && peek() != '\'') {
        if (peek() == '\n') {
            return errorToken("Not support multi-line character.");
        }
        advance();
    }

    if (isAtEnd()) return errorToken("Unterminated character.");

    // The closing single-quote.
    advance();
    return makeToken(TOKEN_CHARACTER);
}

static Token number() {
    // ����������ǽ�NUMBER�Ĺ���������:
    // 1. NUMBER���԰������ֺ����һ��'.'��
    // 2. '.'��ǰ��Ҫ������
    // 3. '.'�ź���ҲҪ������
    // ��Щ���ǺϷ���NUMBER: 123, 3.14
    // ��Щ���ǲ��Ϸ���NUMBER: 123., .14
    while (isDigit(peek())) advance();

    // Look for a fractional part.
    if (peek() == '.' && isDigit(peekNext())) {
        // Consume the "."
        advance();

        while (isDigit(peek())) advance();
    }

    return makeToken(TOKEN_NUMBER);
}

void skipComments() {
    // ֻҪû�е�����β���ļ�ĩ����һֱ��ȡ�ַ�
    while (!isAtEnd() && peek() != '\n') {
        advance();
    }
}

Token scanToken() {

    skipWhitespace();
    scanner.start = scanner.current;
    if (isAtEnd()) return makeToken(TOKEN_EOF);
    char c = advance();
    if (isAlpha(c)) return identifier();
    if (isDigit(c)) return number();

    switch (c) {
    case '(': return makeToken(TOKEN_LEFT_PAREN);
    case '[': return makeToken(TOKEN_LEFT_BRACKET);
    case '{': return makeToken(TOKEN_LEFT_BRACE);
    case ',': return makeToken(TOKEN_COMMA);
    case '.': return makeToken(TOKEN_DOT);
    case ';': return makeToken(TOKEN_SEMICOLON);
    case '~': return makeToken(TOKEN_TILDE);
    case ')': return makeToken(TOKEN_RIGHT_PAREN);
    case ']': return makeToken(TOKEN_RIGHT_BRACKET);
    case '}': return makeToken(TOKEN_RIGHT_BRACE);
    case '#': return makeToken(TOKEN_HASH);
    case '@': return errorToken("Unexpected character.");
    case '$': return errorToken("Unexpected character.");

        // one or two characters tokens
    case '+':
        if (match('+')) return makeToken(TOKEN_PLUS_PLUS);
        else if (match('=')) return makeToken(TOKEN_PLUS_EQUAL);
        else return makeToken(TOKEN_PLUS);
        // TODO
    case '-':
        if (match('-')) return makeToken(TOKEN_MINUS_MINUS);
        else if (match('=')) return makeToken(TOKEN_MINUS_EQUAL);
        else if (match('>')) return makeToken(TOKEN_MINUS_GREATER);
        else return makeToken(TOKEN_MINUS);
    case '*':
        if (match('=')) return makeToken(TOKEN_STAR_EQUAL);
        else return makeToken(TOKEN_STAR);
    case '/':
        if (match('=')) return makeToken(TOKEN_SLASH_EQUAL);
        else return makeToken(TOKEN_SLASH);
    case '%':
        if (match('=')) return makeToken(TOKEN_PERCENT_EQUAL);
        else return makeToken(TOKEN_PERCENT);
    case '&':
        if (match('&')) return makeToken(TOKEN_AMPER_AMPER);
        else if (match('=')) return makeToken(TOKEN_AMPER_EQUAL);
        else return makeToken(TOKEN_AMPER);
    case '|':
        if (match('|')) return makeToken(TOKEN_PIPE_PIPE);
        else if (match('=')) return makeToken(TOKEN_PIPE_EQUAL);
        else return makeToken(TOKEN_PIPE);
    case '^':
        if (match('=')) return makeToken(TOKEN_HAT_EQUAL);
        else return makeToken(TOKEN_HAT);
    case '=':
        if (match('=')) return makeToken(TOKEN_EQUAL_EQUAL);
        else return makeToken(TOKEN_EQUAL);
    case '!':
        if (match('=')) return makeToken(TOKEN_BANG_EQUAL);
        else return makeToken(TOKEN_BANG);
    case '<':
        if (match('=')) return makeToken(TOKEN_LESS_EQUAL);
        else if (match('<')) return makeToken(TOKEN_LESS_LESS);
        else return makeToken(TOKEN_LESS);
    case '>':
        if (match('>')) return makeToken(TOKEN_GREAER_GREATER);
        else if (match('=')) return makeToken(TOKEN_GREATER_EQUAL);
        else return makeToken(TOKEN_GREATER);
        // various-character tokens
    case '"': return string();
    case '\'': return character();
    default: errorToken("Unexpected character.");
    }

}