	int num_chars=0,num_words=0;

%%

[a-zA-Z]+ {printf("%s",yytext);++num_words;}


%%
main()
{
	yylex();
	printf("# of words = %d, # of chars = %d\n ", num_words, num_chars);
}