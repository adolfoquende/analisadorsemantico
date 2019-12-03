#include "analisadorLexico.c"
#include "analisadorSemantico.c"

Par token;

/*
void varDeclaraation(){

typeSpecifier();
varDeclList();

}

void typeSpecifier(){

returnTypeSpecifier()
}

void returnTypeSpecifier(){

if(token.Token==TOK_INT || token.Token==TOK_CHAR)
token=Analex();
else
{
    printf("Esperava um tipo de Dado!");
}

}

void varDeclList(){

 varDeclList();
 if(token.Token==TOK_VIRGULA)
{
token=Analex();
 varDeclInitialize();
}
 else
 {
     varDeclInitialize();
 }
 

}

void varDeclInitialize(){

//varDeclList();
varDeclId();
if(token.Token==TOK_DOISPONTO)
{
token=Analex();
simpleExpression();
}


}

*/

void verificarVariavel()
{

    if (token.Token == TOK_INT)
    {
        Variavel variavel;
        strcpy(variavel.type, token.Lexema);
        token = Analex();
        if (token.Token == TOK_ID)
        {
            strcpy(variavel.name, token.Lexema);
            token = Analex();
            if (variaveis != NULL)
            {

                if (variavelDeclarado(variaveis, &variavel) == 1)
                {
                    printf("Variavel %s ja foi declarada na linha %d!!!", token.Lexema, linha);
                }
            }
            else
            {

                if (token.Token == TOK_VIRGULA)
                {
                    token = Analex();
                    verificarVariavel();
                }
            }
        }
    }
}

int main()
{

    Variavel variaveis = null;
}