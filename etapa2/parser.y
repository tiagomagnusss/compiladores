%token KW_CHAR           256
%token KW_INT            257
%token KW_FLOAT          258
%token KW_IF             261
%token KW_ELSE           263
%token KW_WHILE          264
%token KW_READ           266
%token KW_PRINT          267
%token KW_RETURN         268

%token ASSIGNMENT        269
%token OPERATOR_LE       270
%token OPERATOR_GE       271
%token OPERATOR_EQ       272
%token OPERATOR_DIF      273

%token TK_IDENTIFIER     280

%token LIT_INTEGER       281
%token LIT_FLOAT         282
%token LIT_CHAR          285
%token LIT_STRING        286                       
%token TOKEN_ERROR       290

%left '+' '-'
%left '*' '/'

%%

program: declist
	;

declist: dec declist
	| dec
	;

dec: KW_INT TK_IDENTIFIER '=' LIT_INTEGER ';'
	;

plist: expr plisttail
	|
	;

plisttail: '.' plisttail
	|
	;

expr: LIT_INTEGER
	| IDENTIFIER
	| expr '+' expr
	| expr '-' expr
	| '(' expr ')'

%%

int yyerror() {
	fprintf(stderr, "YY error at %d\n", getLineNumber());
	exit(3);
}
