#include <string>
#include "Lexer.h"

Lexer::Lexer(std::string in) :input(in), first(0), last(0)
{
	lexeme.category = C_NOTHING;
	lexeme.token = EmptyString;
	size = input.size();
}

void Lexer::add_char()
{
	lexeme.token += *(ptr_caracter);
}

void Lexer::get_char()
{
	if (++ptr_caracter != &input[size - 1])
		cur_symbol.symbol = *ptr_caracter;
	else
		cur_symbol.symbol = '\n';

	cur_symbol.type = get_type(cur_symbol.symbol);
}

Type Lexer::get_type(char &sym)
{
	if ((sym > 64 && sym < 91) || (sym > 96 && sym < 123))
		return LETTER;
	if (sym > 47 && sym < 58)
		return DIGIT;
	if (sym == '+')
		return PLUS;
	if (sym == '-')
		return MINUS;
	if (sym == '/')
		return SLASH;
	if (sym == '*')
		return STAR;
	if (sym == ' ')
		return SPACE;
	if (sym == '\n')
		return T_EOF;
	return T_ERROR;
}

Lexeme Lexer::analyze()
{
	lexeme.category = C_NOTHING;
	lexeme.token = "";

	get_char();

	while (cur_symbol.type == SPACE) 
		get_char();

	if (cur_symbol.type == T_ERROR){
		add_char();
		lexeme.category = C_ERROR;
		return lexeme;
	}

	if (cur_symbol.type == T_EOF){
		lexeme.category = C_EOF;
		return lexeme;
	}
}
