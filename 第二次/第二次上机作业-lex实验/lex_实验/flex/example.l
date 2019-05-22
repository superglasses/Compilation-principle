	int num_chars = 0, num_words=0;

%%
[a-zA-Z]+ {printf("%s",yytext);++num_words;num_chars=num_chars+yyleng;}
. {printf("%s",yytext);++num_chars;}
201693045 {printf("ÍõÓí³Ì");num_chars=num_chars+9;}
%%
main()
{
	yylex();

	printf("# of words = %d, # of chars = %d\n ", num_words, num_chars);
}