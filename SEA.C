//SEA - SISTEMA ESTATÍSTICO AVANÇADO 
/* Desenvolvido por:
   André Bitencourt,
   Cleber Luiz,
   Igor Rafael,
   Richard Nascimento,
   Rodrigo Santana,
   Valnei Oliveira.
*/   
#include <stdio.h> //Biblioteca de funções de entrada e saída.
#include <conio2.h> //Biblioteca para uso de algumas funções gráficas e de entrada.
#include <math.h> //Biblioteca de operações matemáticas.

void sobre(); //Sobre o Programa.
void tela(); //Função gráfica da Tela.
void carregar_Arquivo(); //Função para Carregar arquivo.
void salvar_Arquivo(); //Função para salvar Dados em um arquivo.
void entrada_Teclado();//Entrada via Teclado.
void menor_Disco(); //Mostra o menor disco de cada mês.
void moda(); //Função de Navegação de Moda.
void desvioPadrao(); //Função de Navegação Desvio-Padrão.
void muda_Meta(); //Função para mudar Meta.
void mudaMeta_Moda(); //Mudança da Meta da Moda.
void mudaMeta_DesvioPadrao(); //Mudança da Meta do Desvio-Padrão.

//Funções de Cálculo.
float calculoDesvio_Padrao(int *vetor);
int calculoModa(int *vetor);
int posicao_MenorDisco(int *vetor);

//Variáveis Goblais.
int contGlobal, opcao;
int quant = 0; //Quantidade de Elementos.
int meta_DesvioPadrao = 20;
int meta_Moda = 70;

struct //Estrutura base.
{
     char nome[22];
     int mes[6];
     
} empresa[18]; //Limite de 18 sistemas.

char *mesNome[6]={"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho"};

int jan[18], fev[18], mar[18], abr[18], mai[18], jun[18];/*Dados agrupados por mês.*/


/*************************************FUNÇÃO PRINCIPAL****************************************/
int main()
{
     do
     {    
         clrscr(); //Limpa a Tela (Clear Screen).
         _setcursortype(_NORMALCURSOR); //Deixa o Cursor mais fino.
         //Comando para deixar o programa ocupando toda a tela ao pressionar (ALT+ENTER).
         system("mode con cols=80 lines=26");
         tela();
         gotoxy(23,4);printf("SEA - Sistema Estatistico Avancado");
         textcolor(11);     
         gotoxy(2,2);printf("Sistemas: %d", quant);
         if(quant != 0)
         {
             gotoxy(2,3);printf("F5 - Zerar");
         }
         textcolor(15);
         gotoxy(10,10);printf("1 - Entrada via Arquivo");
         gotoxy(10,12);printf("2 - Entrada via Teclado");
         gotoxy(10,14);printf("3 - Menor Utilizacao de Discos");
         gotoxy(48,10);printf("4 - Calcular Desvio-Padrao");
         gotoxy(48,12);printf("5 - Calcular Moda");
         gotoxy(48,14);printf("6 - Salvar Arquivo");
         textcolor(7);gotoxy(60,17);printf("7 - Mudar Metas");
         textcolor(13);gotoxy(69,22);printf("v1.23 FINAL");
         textcolor(10);gotoxy(5,21);printf("Seja Bem-Vindo!");
         textcolor(14);
    	 gotoxy(2,24);printf("F1 - Sobre");
         gotoxy(71,24);printf("F2 - Sair\n\n");
         gotoxy(39,20);printf("| |");
    	 gotoxy(40,20);opcao=getch();
    	 switch(opcao)
    	 {
              case 49: carregar_Arquivo(); break;
                 case 50: entrada_Teclado(); break;
                   case 51: menor_Disco(); break;
                     case 52: desvioPadrao(); break;
                       case 53: moda(); break;
                         case 54: salvar_Arquivo(); break;
                           case 55: muda_Meta(); break;
                            case 0:{
                                     opcao=getch(); 
                                     if(opcao == 59) //F1
                                     {
                                         sobre();
                                     }
                                     else
                                     if(opcao == 60) //F2
                                     {
                                         exit(0);
                                     }
                                     else
                                     if(opcao == 63) //F5
                                     {
                                         quant = 0; //Zera os sistemas.
                                     }
                                     else
                                     {
                                         gotoxy(30,16);printf("..::Opcao Invalida::..");
                                         gotoxy(20,18);printf("Pressione qualquer tecla para tentar novamente...");
                                         getch();                                
                                     }                                        
                                   }break; 
                           
                             default: gotoxy(30,16);printf("..::Opcao Invalida::..");
                                      gotoxy(20,18);printf("Pressione qualquer tecla para tentar novamente...");
                                      getch();          
         }    
          
     }while(opcao);
}
    
    
/********************************FUNCÃO GRÁFICA DA TELA***********************************/
void tela()
{
    int contLocal; 
       
    textcolor(15);     
    for(contLocal=1; contLocal<81; contLocal++)
    {
        gotoxy(contLocal,1);printf("%c",205);
        gotoxy(contLocal,23);printf("%c",205);
	}
    for(contLocal=2; contLocal<23; contLocal++)
	{
        gotoxy(1,contLocal);printf("%c",186);
        gotoxy(80,contLocal);printf("%c",186);
    }
    gotoxy(80,23);printf("%c",188);
    gotoxy(80,1);printf("%c",187);
    gotoxy(1,1);printf("%c",201);
    gotoxy(1,23);printf("%c",200);
}

/********************************ENTRADA VIA ARQUIVO**************************************/     
void carregar_Arquivo()
{
     FILE *arq;
     int contLocal, temp;
     char nome[30];
     clrscr();
     tela();
     textcolor(14);
     gotoxy(28,3);printf("..::Carregar Arquivo::..");
     textcolor(15);
     gotoxy(15,7);printf("Digite o nome do arquivo, Arquivo padrao -> \"padrao.txt\"");
     textcolor(14);
     gotoxy(28,10);textbackground(14);printf("                        ");
     textcolor(1);fflush(stdin);
     gotoxy(28,10);gets(nome);
     textbackground(0);        
     
     if(!(arq = fopen(nome,"r")))
     {
           textcolor(10);
           gotoxy(28,15); printf("ERRO ao carregar o arquivo!!!");
           gotoxy(23,17); printf("1 - Verifique se este arquivo existe.");
           gotoxy(23,18); printf("2 - Verifique as restricoes deste arquivo.");
     }
     else
     {
        fscanf(arq, "%d", &temp);
        
        if(temp <= 1 || temp > 18)
        {
            textcolor(10);
            gotoxy(19,15); printf("Seu arquivo deve conter entre 2 e 18 Sistemas.");
        }
        else
        {
            quant = temp;
            for(contGlobal=0; contGlobal<quant; contGlobal++)
            {
                 fscanf(arq, "%s", &empresa[contGlobal].nome);
             
                 for(contLocal=0; contLocal<6; contLocal++)
                 {
                     fscanf(arq, "%d", &empresa[contGlobal].mes[contLocal]);
                 }
            }
         
             for(contGlobal=0; contGlobal<quant; contGlobal++) //Agrupando Dados por Mês.
             {
                jan[contGlobal] = empresa[contGlobal].mes[0];
                fev[contGlobal] = empresa[contGlobal].mes[1];
                mar[contGlobal] = empresa[contGlobal].mes[2];
                abr[contGlobal] = empresa[contGlobal].mes[3];
                mai[contGlobal] = empresa[contGlobal].mes[4];
                jun[contGlobal] = empresa[contGlobal].mes[5];
             }
             textcolor(11);gotoxy(25,16);printf("Arquivo carregado com SUCESSO!!!");
             fclose(arq);
         }
     }
     textcolor(13);
     gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
     
     gotoxy(1,26);
     getch();
     clrscr();
}

/************************************SALVAR NO ARQUIVO*************************************/
void salvar_Arquivo()
{
     int contLocal;
     clrscr();
     tela();
     textcolor(14);
     gotoxy(28,3);printf("..::Salvar no Arquivo::..");
     FILE *salvar;
     char nome[30];
     
     if(quant == 0)
     {
         textcolor(11);
         gotoxy(28,12); printf("Nao ha nada a ser salvo!");
     }
     else
     { 
         textcolor(15);
         gotoxy(22,9);printf("Informe o nome do arquivo a ser salvo");
         gotoxy(26,11);textbackground(14);printf("                             ");
         gotoxy(26,11); textcolor(1); fflush(stdin); gets(nome);
         textbackground(0);
         if(!(salvar = fopen(nome,"w")))
         {
                   gotoxy(23,16);textcolor(10); printf("ERRO! Arquivo ou diretorio protegido.");
                   textcolor(13);
                   gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
         }
         else
         {
             fprintf(salvar, "%d", quant); 
             for(contGlobal=0; contGlobal<quant; contGlobal++)
             {
                 fprintf(salvar, "\n\n%s\n", empresa[contGlobal].nome);
            
                 for(contLocal=0; contLocal<6; contLocal++)
                 {
                     fprintf(salvar, "%d ", empresa[contGlobal].mes[contLocal]);
                 }     
             }
      
             fclose(salvar);
             textcolor(11);gotoxy(26,15);printf("Arquivo salvo com Sucesso!!!");
         }
     }
     textcolor(13);
     gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
     gotoxy(1,26);getch();
}

/***************************************ENTRADA VIA TECLADO***********************************/
void entrada_Teclado()
{
    int contLocal, temp;
    clrscr();
    tela();
    textcolor(14);
    gotoxy(29,3);printf("...::ENTRADA DE DADOS::...");
    textcolor(15);
    gotoxy(2,5);printf("Quantidade de sistemas (MAX = 18, MIN = 2): ");
    textcolor(14);
    scanf("%d",&temp);
    
    if(temp <= 1 || temp > 18)
    {
        textcolor(7);
        gotoxy(20,14);textcolor(14);printf("Deve ser informado entre 2 e 18 Sistemas");
        textcolor(13);
        gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
        gotoxy(1,26); getch();
    }
    else   
    {
        quant = temp;
        clrscr();
        tela();
        textcolor(14);
        gotoxy(29,3);printf("...::ENTRADA DE DADOS::...");
        //Recebendo nome dos Sistemas.
        for(contGlobal=0; contGlobal<quant; contGlobal++)
        {
            fflush(stdin);
            textcolor(15);
            gotoxy(2,contGlobal+5);printf("Digite o nome do Sistema %d (Sem Espacos): ", contGlobal+1);
            textcolor(10);
            gets(empresa[contGlobal].nome);
        }
        //Recebendo Gigabytes de cada mês do Sistema.  
        for(contGlobal=0; contGlobal<quant; contGlobal++)
        {
            clrscr();
            tela();
            textcolor(14);
            gotoxy(29,3);printf("...::ENTRADA DE DADOS::...");
            textcolor(15);
            gotoxy(2,5);printf("Sistema: ");textcolor(10);printf("%s",empresa[contGlobal].nome);
            
            for(contLocal=0; contLocal<6; contLocal++)
            {
                textcolor(15);
                gotoxy(2,contLocal+7);printf("Informe os GB's do mes de %s: ",mesNome[contLocal]); 
                textcolor(10);
                scanf("%d",&empresa[contGlobal].mes[contLocal]);             
            }
        }
         for(contGlobal=0; contGlobal<quant; contGlobal++) //Agrupando Dados por Mês.
         {
             jan[contGlobal] = empresa[contGlobal].mes[0];
             fev[contGlobal] = empresa[contGlobal].mes[1];
             mar[contGlobal] = empresa[contGlobal].mes[2];
             abr[contGlobal] = empresa[contGlobal].mes[3];
             mai[contGlobal] = empresa[contGlobal].mes[4];
             jun[contGlobal] = empresa[contGlobal].mes[5];
         }
         clrscr();
         tela();
         textcolor(14);
         gotoxy(29,3);printf("...::ENTRADA DE DADOS::...");
         textcolor(11);
         gotoxy(26,12);printf("Dados armazenados com SUCESSO!!!");
         textcolor(13);
         gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");    
         gotoxy(1,26);getch();       
     }
}

/*************************************MENOR DISCO DO MÊS***************************************/
void menor_Disco()
{
     int totalJan=0, totalFev=0, totalMar=0, totalAbr=0, totalMai=0, totalJun=0, posicao[6];
     float percent[6];
     
     clrscr();
     tela();
     textcolor(14);
     gotoxy(19,3);printf("...::Menor Utilizacao de Discos por Mes::...");
     if(quant != 0)
     {
          for(contGlobal=0; contGlobal<quant; contGlobal++)
          {
              totalJan = totalJan + jan[contGlobal];
              totalFev = totalFev + fev[contGlobal];
              totalMar = totalMar + mar[contGlobal];
              totalAbr = totalAbr + abr[contGlobal];
              totalMai = totalMai + mai[contGlobal];
              totalJun = totalJun + jun[contGlobal];
          }
      
          posicao[0] = posicao_MenorDisco(jan);
          posicao[1] = posicao_MenorDisco(fev);
          posicao[2] = posicao_MenorDisco(mar);
          posicao[3] = posicao_MenorDisco(abr);
          posicao[4] = posicao_MenorDisco(mai);
          posicao[5] = posicao_MenorDisco(jun);
      
          percent[0] = (float)(jan[posicao[0]] * 100) / totalJan;
          percent[1] = (float)(fev[posicao[1]] * 100) / totalFev;
          percent[2] = (float)(mar[posicao[2]] * 100) / totalMar;
          percent[3] = (float)(abr[posicao[3]] * 100) / totalAbr;
          percent[4] = (float)(mai[posicao[4]] * 100) / totalMai;
          percent[5] = (float)(jun[posicao[5]] * 100) / totalJun;
      
          gotoxy(18,8);printf("Mes            Sistema                  %%%");  
          textcolor(7);      
          for(contGlobal=0; contGlobal<6; contGlobal++)
          {
              gotoxy(17, contGlobal+10);printf("%s", mesNome[contGlobal]);
          }
      
          textcolor(10);
          for(contGlobal=0; contGlobal<6; contGlobal++)
          {
             gotoxy(33, contGlobal+10);printf("%s",empresa[posicao[contGlobal]].nome);
          }
     
          textcolor(11);
          for(contGlobal=0; contGlobal<6; contGlobal++)
          {
              gotoxy(57, contGlobal+10);printf("%.2f",percent[contGlobal]);
          }
     }
     else
     {
          gotoxy(30,12);    
          textcolor(11); printf("Nao ha nenhum dado!");                         
     }
          textcolor(13);
          gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
          gotoxy(1,26);getch();
}
     
/********************************************MODA********************************************/    
void moda()
{
        int desvioJan, desvioFev, desvioMar, desvioAbr, desvioMai, desvioJun;
        clrscr();
        textcolor(7);
        gotoxy(1,2);printf("SISTEMAS");
        gotoxy(22, 2);printf("  JAN/GB   FEV/GB   MAR/GB   ABR/GB   MAI/GB   JUN/GB");
        textcolor(11);
        gotoxy(1, 23);printf("Realizado");
        gotoxy(1,24);printf("Indicador");
        gotoxy(1,25);printf("Desvio");
               
        if(quant == 0)
        {
          gotoxy(32,12);    
          textcolor(11); printf("Nao ha nenhum dado!");                         
        }
        else
        {      
            textcolor(10);
            for(contGlobal=0; contGlobal<quant; contGlobal++)
            {
                gotoxy(1,contGlobal+4);printf("%s",empresa[contGlobal].nome);
            }
                
            textcolor(14);
            for(contGlobal=0; contGlobal<quant; contGlobal++)
            {
                 gotoxy(25, contGlobal+4);printf("%d", jan[contGlobal]);
                 gotoxy(34, contGlobal+4);printf("%d", fev[contGlobal]);
                 gotoxy(43, contGlobal+4);printf("%d", mar[contGlobal]);
                 gotoxy(52, contGlobal+4);printf("%d", abr[contGlobal]);
                 gotoxy(61, contGlobal+4);printf("%d", mai[contGlobal]);
                 gotoxy(70, contGlobal+4);printf("%d", jun[contGlobal]);
            }    
            //Desvio = Meta - Realizado.
            desvioJan = meta_Moda - calculoModa(jan);  
            desvioFev = meta_Moda - calculoModa(fev);  
            desvioMar = meta_Moda - calculoModa(mar);  
            desvioAbr = meta_Moda - calculoModa(abr);  
            desvioMai = meta_Moda - calculoModa(mai);  
            desvioJun = meta_Moda - calculoModa(jun);  
        
            textcolor(11);gotoxy(1, 23);printf("Realizado");
            textcolor(11);gotoxy(1,24);printf("Indicador");  
            textcolor(11);gotoxy(1,25);printf("Desvio");

            if(calculoModa(jan) != -1)
            {
                gotoxy(25, 23);printf("%d", calculoModa(jan));
        
                if(desvioJan > 2)
                {
                    gotoxy(23,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioJan <= 2 && desvioJan > 0)
                {
                    gotoxy(23,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioJan <= 0)
                {
                    gotoxy(23,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(25,25);printf("%d", desvioJan);
            }
            else
            {
                gotoxy(24, 24);printf("AMODAL");
            }
        
            if(calculoModa(fev) != -1)
            {
                textcolor(11);
                gotoxy(34, 23);printf("%d", calculoModa(fev));
           
                if(desvioFev > 2)
                {
                    gotoxy(32,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioFev <= 2 && desvioFev > 0)
                {
                    gotoxy(32,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioFev <= 0)
                {
                    gotoxy(32,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(34,25);printf("%d", desvioFev);
            }
            else
            {
                gotoxy(33, 24);printf("AMODAL");
            }
        
            if(calculoModa(mar) != -1)
            {
                textcolor(11);
                gotoxy(43, 23);printf("%d", calculoModa(mar));
            
                if(desvioMar > 2)
                {
                    gotoxy(41,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioMar <= 2 && desvioMar > 0)
                {
                    gotoxy(41,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioMar <= 0)
                {
                    gotoxy(41,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(43,25);printf("%d", desvioMar);
            }
            else
            {
                gotoxy(42, 24);printf("AMODAL");
            }
        
            if(calculoModa(abr) != -1)
            {
                textcolor(11);
                gotoxy(52, 23);printf("%d", calculoModa(abr)); 
            
                if(desvioAbr > 2)
                {
                    gotoxy(50,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioAbr <= 2 && desvioAbr > 0)
                {
                    gotoxy(50,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioAbr <= 0)
                {
                    gotoxy(50,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(52,25);printf("%d", desvioAbr);
            }
            else
            {
                gotoxy(51, 24);printf("AMODAL");
            }
         
            if(calculoModa(mai) != -1)
            {
                textcolor(11);
                gotoxy(61, 23);printf("%d", calculoModa(mai));
            
                if(desvioMai > 2)
                {
                    gotoxy(59,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioMai <= 2 && desvioMai > 0)
                {
                    gotoxy(59,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioMai <= 0)
                {
                    gotoxy(59,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(61,25);printf("%d", desvioMai);
            }
            else
            {
                gotoxy(60, 24);printf("AMODAL");
            }
        
            if(calculoModa(jun) != -1)
            {
                textcolor(11);
                gotoxy(70, 23);printf("%d", calculoModa(jun)); 
            
                if(desvioJun > 2)
                {
                    gotoxy(68,24);textcolor(2);printf("Conforme");
                }
                else
                if(desvioJun <= 2 && desvioJun > 0)
                {
                    gotoxy(68,24);textcolor(14);printf("Alerta");
                }
                else
                if(desvioJun <= 0)
                {
                    gotoxy(68,24);textcolor(12);printf("Nao Conf");
                }
                textcolor(11);
                gotoxy(70,25);printf("%d", desvioJun);
            }
            else
            {
                gotoxy(69, 24);printf("AMODAL");
            }
        }
        textcolor(13);
        gotoxy(1,26); printf("Pressione qualquer tecla para voltar ao menu.");
        getch();
            
}

/********************************************DESVIO-PADRÃO**************************************/
void desvioPadrao()
{        
        float desvioJan, desvioFev, desvioMar, desvioAbr, desvioMai, desvioJun;
        
        clrscr();
        textcolor(7);
        gotoxy(1,2);printf("SISTEMAS");
        gotoxy(22, 2);printf("  JAN/GB   FEV/GB   MAR/GB   ABR/GB   MAI/GB   JUN/GB");
        textcolor(11);
        gotoxy(1, 23);printf("Realizado");
        gotoxy(1,24);printf("Indicador");
        gotoxy(1,25);printf("Desvio");
       
        
        if(quant == 0)
        {
            gotoxy(32,12);printf("Nao ha nenhum dado!");                         
        }
        else
        {        
            textcolor(10);
            for(contGlobal=0; contGlobal<quant; contGlobal++)
            {
               gotoxy(1,contGlobal+4);printf("%s",empresa[contGlobal].nome);
            }
            textcolor(14);
            for(contGlobal=0; contGlobal<quant; contGlobal++)
            {
                 gotoxy(25, contGlobal+4);printf("%d", jan[contGlobal]);
                 gotoxy(34, contGlobal+4);printf("%d", fev[contGlobal]);
                 gotoxy(43, contGlobal+4);printf("%d", mar[contGlobal]);
                 gotoxy(52, contGlobal+4);printf("%d", abr[contGlobal]);
                 gotoxy(61, contGlobal+4);printf("%d", mai[contGlobal]);
                 gotoxy(70, contGlobal+4);printf("%d", jun[contGlobal]);
            }    
            //Desvio = Meta - Realizado.
            desvioJan = meta_DesvioPadrao - calculoDesvio_Padrao(jan);  
            desvioFev = meta_DesvioPadrao - calculoDesvio_Padrao(fev);  
            desvioMar = meta_DesvioPadrao - calculoDesvio_Padrao(mar);  
            desvioAbr = meta_DesvioPadrao - calculoDesvio_Padrao(abr);  
            desvioMai = meta_DesvioPadrao - calculoDesvio_Padrao(mai);  
            desvioJun = meta_DesvioPadrao - calculoDesvio_Padrao(jun);  
        
            //Condições dos Indicadores
            if(desvioJan > 2)
            {
                gotoxy(23,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioJan <= 2 && desvioJan > 0)
            {
                gotoxy(23,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioJan <= 0)
            {
                gotoxy(23,24);textcolor(12);printf("Nao Conf");
            }
        
            if(desvioFev > 2)
            {
                gotoxy(32,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioFev <= 2 && desvioFev > 0)
            {
                gotoxy(32,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioFev <= 0)
            {
                gotoxy(32,24);textcolor(12);printf("Nao Conf");
            }
        
            if(desvioMar > 2)
            {
                gotoxy(41,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioMar <= 2 && desvioMar > 0)
            {
                gotoxy(41,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioMar <= 0)
            {
                gotoxy(41,24);textcolor(12);printf("Nao Conf");
            }
        
            if(desvioAbr > 2)
            {
                gotoxy(50,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioAbr <= 2 && desvioAbr > 0)
            {
                gotoxy(50,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioAbr <= 0)
            {
                gotoxy(50,24);textcolor(12);printf("Nao Conf");
            }
        
            if(desvioMai > 2)
            {
                 gotoxy(59,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioMai <= 2 && desvioMai > 0)
            {
                gotoxy(59,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioMai <= 0)
            {
                gotoxy(59,24);textcolor(12);printf("Nao Conf");
            }
        
            if(desvioJun > 2)
            {
                gotoxy(68,24);textcolor(2);printf("Conforme");
            }
            else
            if(desvioJun <= 2 && desvioJun > 0)
            {
               gotoxy(68,24);textcolor(14);printf("Alerta");
            }
            else
            if(desvioJun <= 0)
            {
                gotoxy(68,24);textcolor(12);printf("Nao Conf");
            }
            textcolor(11);        
            gotoxy(24,25);printf("%.2f", desvioJan);
            gotoxy(33,25);printf("%.2f", desvioFev);
            gotoxy(42,25);printf("%.2f", desvioMar);
            gotoxy(51,25);printf("%.2f", desvioAbr);
            gotoxy(60,25);printf("%.2f", desvioMai);
            gotoxy(69,25);printf("%.2f", desvioJun);
            gotoxy(24, 23);printf("%.3f", calculoDesvio_Padrao(jan));
            gotoxy(33, 23);printf("%.3f", calculoDesvio_Padrao(fev));
            gotoxy(42, 23);printf("%.3f", calculoDesvio_Padrao(mar));
            gotoxy(51, 23);printf("%.3f", calculoDesvio_Padrao(abr));   
            gotoxy(60, 23);printf("%.3f", calculoDesvio_Padrao(mai));
            gotoxy(69, 23);printf("%.3f", calculoDesvio_Padrao(jun)); 
        }
        textcolor(13);
        gotoxy(1,26); printf("Pressione qualquer tecla para voltar ao menu.");
        getch();
}


void muda_Meta()
{
    do
    {
        clrscr();
        tela();
        textcolor(14);
        gotoxy(29,3);printf("...::Mudanca de Meta::...");
        textcolor(10);
        gotoxy(26,7);printf("Informe a meta que deseja alterar");
        textcolor(15);
        gotoxy(26,9);printf("1 - Moda");
        gotoxy(42,9);printf("2 - Desvio-Padrao");
        gotoxy(30,12);printf("3 - Voltar ao Menu Principal");
        textcolor(7);
        gotoxy(3,16);printf("Meta atual da Moda: ");textcolor(11);printf("%d", meta_Moda);
        textcolor(7);
        gotoxy(3,18);printf("Meta atual do Desvio-Padrao: ");textcolor(11);printf("%d", meta_DesvioPadrao);
        gotoxy(1,26);opcao=getch();
        switch(opcao)
        {
            case 49: mudaMeta_Moda(); break;
              case 50: mudaMeta_DesvioPadrao(); break;
                case 51: return;
                  default: 
                           textcolor(14);
                           gotoxy(30,19);printf("..::Opcao Invalida::..");
                           gotoxy(20,21);printf("Pressione qualquer tecla para tentar novamente...");
                           getch();
        }
    }while(opcao);
}

void mudaMeta_Moda()
{
     int meta;
     clrscr();
     tela();
     textcolor(14);
     gotoxy(29,3);printf("...::Mudanca de Meta::...");
     textcolor(15);
     gotoxy(3,8);printf("Informe a nova meta da MODA: ");
     textcolor(11);
     scanf("%d", &meta);
     if(meta <= 0)
     {
         textcolor(10);
         gotoxy(27,15);printf("ERRO! A meta deve ser maior que 0.");
     }
     else
     {
         meta_Moda = meta;
         textcolor(11);
         gotoxy(30,15);printf("Meta Atualizada com Sucesso");
     }
     textcolor(13);
     gotoxy(1,24); printf("Pressione qualquer tecla para voltar ao menu.");
     getch();
}

void mudaMeta_DesvioPadrao()
{
     int meta;
     clrscr();
     tela();
     textcolor(14);
     gotoxy(29,3);printf("...::Mudanca de Meta::...");
     textcolor(15);
     gotoxy(3,8);printf("Informe a nova meta do Desvio-Padrao: ");
     textcolor(11);
     scanf("%d", &meta);
     if(meta <= 0)
     {
         textcolor(10);
         gotoxy(27,15);printf("ERRO! A meta deve ser maior que 0.");
     }
     else
     {
         meta_DesvioPadrao = meta;
         textcolor(11);
         gotoxy(30,15);printf("Meta Atualizada com Sucesso");
     }
     textcolor(13);
     gotoxy(1,24); printf("Pressione qualquer tecla para voltar ao menu.");
     getch();
}

/************************************CÁLCULO DESVIO-PADRÃO************************************/
float calculoDesvio_Padrao(int *vetor)
{
      float soma=0, total=0, media, result, desv;
      
      for(contGlobal=0; contGlobal<quant; contGlobal++)
      {
          soma = soma + vetor[contGlobal];
      }
      
      media = soma / quant;
      
      for(contGlobal=0; contGlobal<quant; contGlobal++)
      {
          //pow = Elevando o resultado de (v1[contGlobal]-media) ao quadrado = (v1[contGlobal]-media)²
          result = pow((vetor[contGlobal] - media), 2);
          total = total + result;
      }
      
      desv = sqrt(total / (quant - 1));//sqrt = Função para cálculo da raiz quadrada.
      return desv;    
}

/**************************************CÁLCULO MODA********************************************/
int calculoModa(int *vetor)
{
     int moda, possui_Moda=0, contVezes=1, vetorVezes[quant], vetorModas[quant];
     int contLocal, contaModas=0, modaFinal;
     
     for (contGlobal=0; contGlobal<quant; contGlobal++)
     {
         for (contLocal=contGlobal+1; contLocal<quant; contLocal++)
         {
             if(vetor[contGlobal] == vetor[contLocal])
             {
                contVezes++;
             }
         }
         vetorVezes[contGlobal] = contVezes;
         contVezes = 1;
     }
     
     for (contGlobal=0; contGlobal<quant; contGlobal++)
     {
          if(vetorVezes[contGlobal] > 1)
          {
             possui_Moda = 1; 
          }
     }      
     
     if (possui_Moda)
     {
            moda = vetorVezes[0];
            
            for (contGlobal=1; contGlobal<quant; contGlobal++)
            {
               if (moda < vetorVezes[contGlobal])
               {
                   moda = vetorVezes[contGlobal];
               }
            }
            
            for (contGlobal=0; contGlobal<quant; contGlobal++)
            {
               if (vetorVezes[contGlobal] == moda)
               {
                   vetorModas[contaModas] = vetor[contGlobal];
                   contaModas++;
               } 
            }
            
            modaFinal = vetorModas[0];
            
            for (contGlobal=1; contGlobal<contaModas; contGlobal++)
            {
                if(vetorModas[contGlobal] > modaFinal)
                {
                    modaFinal = vetorModas[contGlobal];
                }
            }
             
            return modaFinal;
     }
     else
     {
         return -1;         
     }
}           

/******************************CÁLCULO DA POSIÇÃO DO MENOR DISCO*******************************/
int posicao_MenorDisco(int *vetor)
{
    int posicao;
    
    posicao = 0;
    
    for(contGlobal=1; contGlobal<quant; contGlobal++)
    {
        if(vetor[contGlobal] < vetor[posicao])
        {
            posicao = contGlobal;
        }
    } 
    return posicao;
}

/*****************************************SOBRE - F1*******************************************/               
void sobre()
{
    FILE *fp;
    char ch;
    clrscr();
    tela();
    textcolor(14);
    gotoxy(31,3);printf("...::SOBRE::...");
      
    fp = fopen("sobre.txt","r");
    if(!fp)
    {
          textcolor(15);
          gotoxy(31,10); printf("ERRO INESPERADO");
    }
    else
    {
             textcolor(10);
             gotoxy(3,5);
             ch=getc(fp);
             while(ch!=EOF)
             {                         
                 putchar(ch);
                 ch=getc(fp);                  
             }
             fclose(fp);
             tela();
     }
    textcolor(13);
    gotoxy(1,24);printf("Pressione qualquer tecla para voltar ao menu.");
    gotoxy(1,26);getch();
    clrscr();
}
