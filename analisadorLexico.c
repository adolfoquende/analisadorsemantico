#include<stdio.h>
#include "token.h"
#include<locale.h>

FILE *Arq;
char vet[100];
int cont =0;
char ch;
int linha=1,contArquivo=0;



void zera_vet()// Func��o usada para limpar o buffer do vector
{
	int i;
	for(i = 0; i < cont; i++)
	{
		vet[i] = 0;
	}
	cont = 0;
}
typedef struct
{
	char *Token; // igual char token[100]
	char *Lexema; // igual char lexema[100]
}Par;

char ler_()
{
	char letra;
	fread(&letra, 1,1,Arq);
	return letra;
}

Par Analex()
{
	int estado = 0; //Controla os estados dos automatos
	Par par;
	zera_vet();

	while(!feof(Arq))
	{

		switch(estado)
		{
			case 0: ch = ler_();
			{contArquivo++;//----------------------------------------------------------------------------------------
					if(ch==10) linha++;
					if((ch >='a' && ch<='z') || (ch>='A' && ch<='Z')||ch=='_')
					{
						vet[cont]=ch;
						cont++;
						estado = 1;
					}else if(ch=='('){
						vet[cont]=ch;
						cont++;
						estado=3;
					}else if(ch==')'){
						vet[cont]=ch;
						cont++;
						estado=4;
					}else if(ch=='{'){
						vet[cont]=ch;
						cont++;
						estado=5;
					}else if(ch=='}'){
						vet[cont]=ch;
						cont++;
						estado=6;
					}else if(ch=='['){
						vet[cont]=ch;
						cont++;
						estado=7;
					}else if(ch==']'){
						vet[cont]=ch;
						cont++;
						estado=8;
					}else if(ch==','){
						vet[cont]=ch;
						cont++;
						estado=9;
					}else if(ch=='.'){
						vet[cont]=ch;
						cont++;
						estado=10;
					}else  if(ch==';')
					{
						vet[cont]=ch;
						cont++;
						estado=11;
					}else if(ch==':')
					{
						vet[cont]=ch;
						cont++;
						estado=12;
					}else if(ch=='+')// Operadores Aritmeticos ou incremento e Decremento
					{
						vet[cont]=ch;
						cont++;
						estado=13;
					}else if(ch=='-')
					{
						vet[cont]=ch;
						cont++;
						estado=17;
					}else if(ch=='*')
					{
						vet[cont]=ch;
						cont++;
						estado=21;
					}else if(ch=='/')
					{
						vet[cont] = ch;
						cont++;
						estado = 24;
					}else if(ch=='%')
					{
						vet[cont]=ch;
						cont++;
						estado=32;
					}
					else if(ch=='=')//Operadores Relacionais ou operador de atribuicao
					{
						vet[cont]=ch;
						cont++;
						estado=35;
					}
					else if(ch== '>')
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=38;
					}else if(ch=='<')
                    {
                        vet[cont]==ch;
                        cont++;
                        estado=41;
                    }
                    else if(ch=='!')//Operadores Logicos
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=44;
                    }
                    //Operadores
                    else if(ch=='&')
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=47;
                    }
                    else if(ch=='|')
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=50;
                    }
                    else if(ch=='#')
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=53;
                    }
                    //Tipos de dados
                    else if(ch=='"'){
						vet[cont]=ch;
						cont++;
						estado=56;
					}else if((ch>='0') && (ch<='9')){
						vet[cont]=ch;
						cont++;
						estado=58;
					}

					break;
			}

			case 1: ch = ler_();
                if(feof(Arq)){
            	par.Lexema=vet;
                 par.Token= TOK_ID;
            	return par;
                    }
                    contArquivo++;
				{if(ch==10) linha++;
					while(((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch=='_')&& !feof(Arq))
					{
						vet[cont] = ch;
						cont++;
						ch = ler_();
						contArquivo++;
						if(ch==10) linha++;
						//estado = 1;
					}
					if(ch!=10 && ch!=32){

						contArquivo--;
						fseek(Arq,contArquivo,SEEK_SET);
					}
					estado = 2;
					break;
				}
			//Estado final para analise de palavras reservadas
			case 2:
				{
						par.Lexema = vet;
						if(!strcmp(par.Lexema,"int")){
						par.Token = TOK_INT;
						return par;
					}else if(!strcmp(par.Lexema,"double")){
                        par.Token=TOK_DOUBLE;
                        return par;
                    }else if(!strcmp(par.Lexema,"char")){
                        par.Token=TOK_CHAR;
                        return par;
                    }else if(!strcmp(par.Lexema,"float")){
                        par.Token=TOK_FLOAT;
                        return par;
                    }else if(!strcmp(par.Lexema,"short")){
                        par.Token=TOK_SHORT;
                        return par;
                    }else if(!strcmp(par.Lexema,"void")){
                        par.Token=TOK_VOID;
                        return par;
                    }else if(!strcmp(par.Lexema,"if")){
                        par.Token=TOK_IF;
                        return par;
                    }else if(!strcmp(par.Lexema,"else")){
                        par.Token=TOK_ELSE;
                        return par;
                    }else if(!strcmp(par.Lexema,"for")){
                        par.Token=TOK_FOR;
                        return par;
                    }else if(!strcmp(par.Lexema,"while")){
                        par.Token=TOK_WHILE;
                        return par;
                    }else if(!strcmp(par.Lexema,"case")){
                        par.Token=TOK_CASE;
                        return par;
                    }else if(!strcmp(par.Lexema,"do")){
                        par.Token=TOK_DO;
                        return par;
                    }else if(!strcmp(par.Lexema,"return")){
                        par.Token=TOK_RETURN;
                        return par;
                    }else if(!strcmp(par.Lexema,"default")){
                        par.Token=TOK_DEFAULT;
                        return par;
                    }else if(!strcmp(par.Lexema,"const")){
                        par.Token=TOK_CONST;
                        return par;
                    }else if(!strcmp(par.Lexema,"struct")){
                        par.Token=TOK_STRUCT;
                        return par;
                    }else if(!strcmp(par.Lexema,"switch")){
                        par.Token=TOK_SWITCH ;
                        return par;
                    }else if(!strcmp(par.Lexema,"typedef")){
                        par.Token=TOK_TYPEDEF;
                        return par;
                    }else if(!strcmp(par.Lexema,"goto")){
                        par.Token=TOK_GOTO;
                        return par;
                    }else if(!strcmp(par.Lexema,"volatile")){
                        par.Token=TOK_VOLATILE;
                        return par;
                    }else if(!strcmp(par.Lexema,"union")){
                        par.Token=TOK_UNION;
                        return par;
                    }else if(!strcmp(par.Lexema,"static")){
                        par.Token=TOK_STATIC;
                        return par;
                    }else if(!strcmp(par.Lexema,"sizeof")){
                        par.Token=TOK_SIZEOF;
                        return par;
                    }else if(!strcmp(par.Lexema,"singned")){
                        par.Token=TOK_SIGNED;
                        return par;
                    }else if(!strcmp(par.Lexema,"return")){
                        par.Token=TOK_RETURN;
                        return par;
                    }else if(!strcmp(par.Lexema,"REGISTER")){
                        par.Token=TOK_REGISTER;
                        return par;
                    }else if(!strcmp(par.Lexema,"long")){
                        par.Token=TOK_LONG;
                        return par;
                    }else if(!strcmp(par.Lexema,"extern")){
                        par.Token=TOK_EXTERN;
                        return par;
                    }else if(!strcmp(par.Lexema,"enum")){
                        par.Token=TOK_ENUM;
                        return par;
                    }else if(!strcmp(par.Lexema,"continue")){
                        par.Token=TOK_CONTINUE;
                        return par;
                    }else if(!strcmp(par.Lexema,"const")){
                        par.Token=TOK_CONST;
                        return par;
                    }else if(!strcmp(par.Lexema,"auto")){
                        par.Token=TOK_AUTO;
                        return par;
                    }
                    else{
                        par.Token = TOK_ID;
                        return par;
                    }
					break;
				}

			case 3:
				{
					par.Lexema=vet;
					par.Token=TOK_ACH;
					return par;
					break;
				}


			case 4:
				{
					par.Lexema=vet;
					par.Token=TOK_FCH;
					return par;
					break;
				}
			case 5:
				{
					par.Lexema=vet;
					par.Token=TOK_APT;
					return par;
					break;
				}
			case 6:
				{
					par.Lexema=vet;
					par.Token=TOK_FPT;
					return par;
					break;
				}
			case 7:
				{
					par.Lexema=vet;
					par.Token=TOK_APR;
					return par;
					break;
				}
			case 8:
				{
				par.Lexema=vet;
				par.Token=TOK_FPR;
				return par;
				break;
				}
			case 9:
				{
					par.Lexema=vet;
					par.Token=TOK_VIRGULA;
					return par;
					break;
				}
			case 10:
				{
					par.Lexema=vet;
					par.Token=TOK_PONTO;
					return par;
					break;
				}
			case 11:
				{
					par.Lexema=vet;
					par.Token=TOK_PONTOV;
					return par;
					break;
				}
			case 12:
				{
					par.Lexema=vet;
					par.Token=TOK_DOISPONTO;
					return par;
					break;
				}
            case 13: ch = ler_();
                     if(feof(Arq)){
                        par.Lexema=vet;
                         par.Token=TOK_SOMA;
                        return par;
                    }
				{contArquivo++;
                    if(ch==10) linha++;
                    if(ch=='+')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=14;
                        }
                        else
                            {
                                if(ch=='='){
                                    vet[cont]=ch;
                                    cont++;
                                    estado=15;
                                }else{
                                    estado=16;
                                     if(ch!=10 && ch!=32){
                                        contArquivo--;
                                        fseek(Arq,contArquivo,SEEK_SET);
                                    }
                                }

                            }
                    break;
				}
            //AS Tres ipoteses com o operador de soma
            case 14:
				{
                    par.Lexema=vet;
					par.Token=TOK_SOMA2;
					return par;
					break;
				}
             case 15:
				{
                    par.Lexema=vet;
					par.Token=TOK_SOMAI;
					return par;
					break;
				}
            case 16:
				{
                    par.Lexema=vet;
					par.Token=TOK_SOMA;
					return par;
					break;
				}
            case 17: ch = ler_();
                     if(feof(Arq)){
                        par.Lexema=vet;
                         par.Token=TOK_SOMA;
                        return par;
                    }
				{contArquivo++;
                    if(ch==10) linha++;
                    if(ch=='-')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=18;
                        }
                        else
                            {
                                if(ch=='='){
                                    vet[cont]=ch;
                                    cont++;
                                    estado=19;
                                }else{
                                    estado=20;
                                }
                                 if(ch!=10 && ch!=32){
                                        contArquivo--;
                                        fseek(Arq,contArquivo,SEEK_SET);
                                    }
                            }


                    break;
				}
            case 18:
				{
                    par.Lexema=vet;
					par.Token=TOK_SUB2;
					return par;
					break;
				}
             case 19:
				{
                    par.Lexema=vet;
					par.Token=TOK_SUBI;
					return par;
					break;
				}
            case 20:
				{
                    par.Lexema=vet;
					par.Token=TOK_SUB;
					return par;
					break;
				}

            case 21: ch = ler_();
                     if(feof(Arq)){
                        par.Lexema=vet;
                         par.Token=TOK_SOMA;
                        return par;
                    }
				{contArquivo++;
                    if(ch==10) linha++;
                    if(ch=='=')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=23;
                        }else{
                            estado=22;
                             if(ch!=10 && ch!=32){
                                    contArquivo--;
                                    fseek(Arq,contArquivo,SEEK_SET);
                                }
                        }
                        break;
				}
            case 22:
				{
					par.Lexema=vet;
					par.Token=TOK_MUL;
					return par;
					break;
				}
             case 23:
				{
					par.Lexema=vet;
					par.Token=TOK_MULTI;
					return par;
					break;
				}
            case 24: ch = ler_();
			contArquivo++;
				{if(ch==10) linha++;
                    if(ch=='='){//divis�o igual
                        vet[cont] = ch;
						cont++;
						estado = 26;
                    }else{
                        if(ch=='*')//comentario
                            {
                                vet[cont] = ch;
                                cont++;
                                estado =27;
                            }else{
                                if(ch=='/')//comentario
                                {
                                    vet[cont] = ch;
                                    cont++;
                                    estado = 30;
                                }else{//operador de divisao
                                    estado =25;
                                     if(ch!=10 && ch!=32){
                                        contArquivo--;
                                        fseek(Arq,contArquivo,SEEK_SET);
                                    }
                                }
                            }
                    }
					break;
				}
            case 25:
                {
                    par.Lexema=vet;
					par.Token=TOK_DIV;
					return par;
					break;
                }
            case 26:
                {
                    par.Lexema=vet;
					par.Token=TOK_DIVI;
					return par;
					break;
                }
            case 27: ch = ler_();
                contArquivo++;
                    {if(ch==10) linha++;
                        while(ch !='*')
                        {
                            vet[cont] = ch;
                            cont++;
                            estado = 27;
                            ch = ler_();
                            contArquivo++;
                            if(ch==10) linha++;
                        }
                        if(ch =='*')
                        {
                            vet[cont] = ch;
                            cont++;
                            estado = 28;
                        }
                        break;
                    }
            case 28: ch = ler_();
				{   contArquivo++;
					if(ch==10) linha++;
					while(ch=='*')
					{
						vet[cont] = ch;
						cont++;
						ch = ler_();
						contArquivo++;
						if(ch==10) linha++;
					}
					if(ch=='/')
					{
						vet[cont] = ch;
						cont++;
						estado = 29;
					}
					break;
				}
            case 29:
                {
                    par.Lexema = vet;
					par.Token = TOK_CMTB;
					return par;
					break;
                }
            case 30: ch=ler_();
                    contArquivo++;
				{
                   if(ch!=10){
                        while((ch!=10)&& !feof(Arq))
                        {
                            if(((ch >='a' && ch<='z') || (ch>='A' && ch<='Z')||ch=='_' || ch==32)&& !feof(Arq))
                            {
                               vet[cont] = ch;
                                cont++;
                                estado = 30;
                                ch = ler_();
                                contArquivo++;
                            }
                        }
                   }
                   if(ch!=32){
                        contArquivo--;
                        fseek(Arq,contArquivo,SEEK_SET);
                    }
                    estado = 31;
					break;
				}
            case 31:
                {
                    par.Lexema = vet;
					par.Token = TOK_CMT;
					return par;
					break;
                }
            case 32:ch=ler_();
                {   contArquivo++;
                    if(ch==10) linha++;
                    if(ch=='=')
                    {
                        vet[cont]=ch;
                        cont++;
                        estado=33;
                    }else{
                        estado=34;
                        if(ch!=10 && ch!=32){
                            contArquivo--;
                            fseek(Arq,contArquivo,SEEK_SET);
                        }
                    }
                }
            case 33:
                {
                    par.Lexema = vet;
					par.Token = TOK_MODI;
					return par;
					break;
                }
            case 34:
                {
                    par.Lexema = vet;
					par.Token = TOK_MOD;
					return par;
					break;
                }
            case 35:ch=ler_();
                {
                    contArquivo++;
                    if(ch==10) linha;
                    if(ch=='='){
                        vet[cont]=ch;
                        cont++;
                        estado=36;
                    }else{
                        estado=37;
                        if(ch!=10 && ch!=32){
                            contArquivo--;
                            fseek(Arq,contArquivo,SEEK_SET);
                        }
                    }
                }
            case 36:
                {
                    par.Lexema = vet;
					par.Token = TOK_COMP;
					return par;
					break;
                }
            case 37:
                {
                    par.Lexema = vet;
					par.Token = TOK_IGUAL;
					return par;
					break;
                }
            case 38: ch = ler_();
				{
				    contArquivo++;
                    if(ch==10) linha++;
                    if(ch=='=')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=39;
                        }else{
                            estado=40;
                        //O o ponteiro precisa recuar devido o proximo carecter
                            if(ch!=10 && ch!=32)
                                {
                                    contArquivo--;
                                    fseek(Arq,contArquivo,SEEK_SET);
                                }
                        }
                    break;
                }

            case 39:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_MAIG;
                        return par;
                            break;
                    }
            case 40:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_MAIOR;
                        return par;
                        break;
                    }
            case 41: ch = ler_();
                        {
                            contArquivo++;
                            if(ch==10) linha++;
                            if(ch=='=')
                                {
                                    vet[cont]=ch;
                                    cont++;
                                    estado=42;
                                }   else{
                                    estado=43;
                                //O o ponteiro precisa recuar devido o proximo carecter
                                    if(ch!=10 && ch!=32)
                                        {
                                            contArquivo--;
                                            fseek(Arq,contArquivo,SEEK_SET);
                                        }
                                }
                            break;
                        }

            case 42:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_MEIG;
                        return par;
                            break;
                    }
            case 43:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_MENOR;
                        return par;
                        break;
                    }
            case 44:ch = ler_();
					{
                            contArquivo++;
                            if(ch==10) linha++;
                            if(ch=='=')
                                {
                                    vet[cont]=ch;
                                    cont++;
                                    estado=45;
                                }else{
                                    vet[cont]=ch;
                                    cont++;
                                    estado=46;
                                    //O o ponteiro precisa recuar devido o proximo carecter
                                        if(ch!=10 && ch!=32){
                                        contArquivo--;
                                        fseek(Arq,contArquivo,SEEK_SET);
                                }

                        }
                        break;
                    }
            case 45:
                        {
                            par.Lexema=vet;
                            par.Token=TOK_DIFE;
                            return par;
                            break;
                        }
            case 46:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_ESCL;
                        return par;
                        break;
                    }
            case 47:ch = ler_();
					{
					    contArquivo++;
                        if(ch==10) linha++;
                        if(ch=='&')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=48;
                        }
                        else
                        {
                                vet[cont]=ch;
                                cont++;
                                estado=49;
                            //O o ponteiro precisa recuar devido o proximo carecter
                                if(ch!=10 && ch!=32){
                                contArquivo--;
                                fseek(Arq,contArquivo,SEEK_SET);
                                }
                        }
                        break;
				}
            case 48:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_AND;
                        return par;
                        break;
                    }
            case 49:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_TECL;
                        return par;
                        break;
                    }
            case 50:ch = ler_();
					{
					    contArquivo++;
                        if(ch==10) linha++;
                        if(ch=='|')
                        {
                            vet[cont]=ch;
                            cont++;
                            estado=51;
                        }else{
                            vet[cont]=ch;
                            cont++;
                            estado=52;
                            //O o ponteiro precisa recuar devido o proximo carecter
                                if(ch!=10 && ch!=32){
                                contArquivo--;
                                fseek(Arq,contArquivo,SEEK_SET);
                            }
                        }
                        break;
                    }
            case 51:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_OR;
                        return par;
                        break;
                    }
            case 52:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_PIPE;
                        return par;
                        break;
                    }
            case 53:
                    {
                        par.Lexema=vet;
                        par.Token=TOK_CAD;
                        return par;
                        break;
                    }
            case 54:ch = ler_();
				contArquivo++;
				{
				    if(ch==10) linha++;
					while(ch !='"')
					{
					    if((ch >='a' && ch<='z') || (ch>='A' && ch<='Z')||ch=='_')
                        {
                           vet[cont] = ch;
                            cont++;
                            ch = ler_();
                            contArquivo++;
                        }

					}
					if(ch=='"'){
						vet[cont] = ch;
						cont++;
						estado = 55;
					}
					break;
				}
            case 55:
				{
					par.Lexema = vet;
					par.Token = TOK_CHARIT;
					return par;
					break;
				}

            case 56:ch=ler_();
                contArquivo++;
                {
                    if(ch==10) linha++;
                    while(((ch>='0')&&(ch<='9'))&& !feof(Arq))
                    {
                        vet[cont] = ch;
                        cont++;
                        ch = ler_();
                        contArquivo++;
                        if(ch==10) linha++;
                    }
                    if(ch=='.')
                    {
                        vet[cont] = ch;
                        cont++;
                        estado = 57;
                    }else{
                        if(ch=='e'){
                        vet[cont] = ch;
                        cont++;
                        estado = 59;
                        }else{
                            estado=61;
                        }
                    }
                    break;
                }
                case 57:ch=ler_();
                contArquivo++;
                    {
                        if(ch==10) linha++;
                        if((ch>='0')&&(ch<='9')){
                            while(((ch>='0')&&(ch<='9'))&& !feof(Arq))
                            {
                                vet[cont] = ch;
                                cont++;
                                ch = ler_();
                                contArquivo++;
                                if(ch==10) linha++;
                            }
                        }
                        if(ch!=10 && ch!=32){
                            contArquivo--;
                            fseek(Arq,contArquivo,SEEK_SET);
                        }
                        estado=58;
                        break;
                    }
                case 58:
                    {
                        par.Lexema = vet;
                        par.Token = TOK_NUMERO_FLOAT;
                        return par;
                        break;
                    }
                case 59:ch=ler_();
                    contArquivo++;
                    {
                        if(ch==10) linha++;
                        if(((ch=='-')|| ((ch>='0')&&(ch<='9')))&& !feof(Arq))
                            {
                            vet[cont] = ch;
                            cont++;
                            estado = 60;
                        }
                        break;
                    }
                case 60:ch=ler_();
                    contArquivo++;
                    {
                        if(ch==10) linha++;
                        if((ch>='0')&&(ch<='9')){
                            while(((ch>='0')&&(ch<='9') )&& !feof(Arq))
                            {
                                vet[cont] = ch;
                                cont++;
                                ch = ler_();
                                contArquivo++;
                                if(ch==10) linha++;
                            }
                        }
                        if(ch!=10 && ch!=32){
                                contArquivo--;
                                fseek(Arq,contArquivo,SEEK_SET);
                        }
                        estado=58;
                        break;
                    }
                case 61:
                    {
                        par.Lexema = vet;
                        par.Token = TOK_NUMERO_INT;
                        return par;
                        break;
                    }

        }
	}
        par.Token = TOK_END;
        zera_vet();
        return par;
}



int main()
{

	setlocale(LC_ALL,"");
	Par par;

	Arq = fopen("teste.txt","rb");
	printf("LEXEMA                                                       TOKEN                                          Linha\n");
	printf("====================================================================================================================\n");
	par = Analex();
	while(par.Token != TOK_END)
	{
		printf("%s%s%s      \t %d\n",par.Lexema,"                               ",par.Token,linha);
		par = Analex();
	}
	return 0;
}

