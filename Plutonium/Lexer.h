#pragma once
#include <string>

#define EmptyString ""

enum Category{ C_NOTHING, C_ERROR, C_EOF, TAB, LITERAL, NUMBER, IDENTIFIER, LOGICAL_OPERATOR, ALGEBRAIC_OPERATOR, LET, TO };
enum Type{ T_NOTHING, T_ERROR, LETTER, DIGIT, PLUS, MINUS, SPACE, T_EOF, SLASH, STAR, LANGLE, RANGLE, COLON, EQUAL, COMMA, DOT, QUOTE, LBRACKET, RBRACKET,  };

typedef struct{
	std::string token;
	Category	category;
}Lexeme;


typedef struct{
	char symbol;
	Type type;
}Symbol;

class Lexer
{
public:
	Lexeme lexeme;

	Lexer(std::string in = "");
	~Lexer();
	Lexeme analyze();

private:
	std::string input;
	int size;
	int first, last;
	char *ptr_caracter;
	Symbol cur_symbol;

	void add_char(void);
	void get_char(void);
	Type get_type(char&);
};
