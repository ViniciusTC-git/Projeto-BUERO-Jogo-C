#include <allegro.h>
//CODIGO CRIADO POR: VINICIUS TEIXEIRA 2 ANO BSI

//Funções
void sair();//Função para sair

void init();//Função iniciação do allegro

void control();//Função Controle do persongem rato

void restart();//Função Reiniciar jogo

void menu();//Menu 

void controlobjs();//Função que chama os  Controles dos objetos

void controlqueijo();

void controlveneno();

void controlratoeira();

void controlvida();

void controlgatos();


void colisaoobjs();//Função que chama as Colisoes dos objetos e personagem

void colisaoqueijo();

void colisaoratoeira();

void colisaoveneno();

void colisaovida();

void colisaogatos();


//Variaveis especiais orientadas a objetos e posições

struct personagem { int wx, wy, x, y, w, h;}; //CONTROLE DO RATO E GATO
                                      //h = altura do personagem
                                      //w = largura personagem
                                       //x = movimento do personagem para direita e esquerda.
                                      //y = movimento do personagem para cima e baixo 
                                      //wx = largura e posição da direita a esquerda
                                      //wy = largura e posição para cima e baixo
                                      
                                      
struct personagem p = {120, 2, 360, 225, 60, 80},//RATO
                                          // Posição, tamanho e altura.
                                          // valores das variaveis wx,wy,x,y,w,h.
                                          
                  p2[2] = {80, 20, 0, 0, 95, 190},//GATO DIREITA
                                           // Posição, tamanho e altura.
                                          // valores das variaveis wx,wy,x,y,w,h. 
                                                                                 
                  p3[2] = {-10, 20, 0, 0, 95, 190}; //GATO ESQUERDA
                                           // Posição, tamanho e altura.
                                           // valores das variaveis wx,wy,x,y,w,h.  


struct objetos {int x,y;};//CONTROLE E POSIÇÃO OBJETOS

                                          
struct objetos obj[4] = {0,0},//Queijo

               obj2[3] = {0,0},//Ratoeira
               
               obj3[3] = {0,0},//Veneno
               
               obj4 = {0,0},//Vida 
                                                                     
               obj5 = {0,0},//Logo Menu
               
               obj6 = {0,0};//Instruções                                                    
  
       

 //Variáveis Globais

 int colidir(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh);//CODIGO DE COLISAO DOS OBJETOS
 
 int sai    = 0;//Sair do jogo
               
 int width  = 800;//largura da tela
               
 int height = 600;// altura da tela
               
 int dir[3];// vetor de direção dos personagens
            
 int nTile[3];//vetor troca de animação dos personagens.
               
       
               

BITMAP *buffer, *imagem0, *imagem1 , *imagem2, *imagem3, *imagem4, *imagem5, *imagem6, *imagem7, *imagem8, *imagem9;//carrega as imagems

// CORES     0-TRANSPAR 1-VERDE   2-CIAN   3- ROXO  4- ROSA  5 - PRATA   
int cor[6] = {0xFF00FF, 0x527E2D, 0xC3903D,0xA459D0,0xC659B3,0xECECEC};//o numero de 0 a 5 contem cores que podem ser utilizadas para desenhar formas ou tela. 

//Variaveis do Tempo do game
int t[5];//Timer repetição dos objetos t[0]: timer de lentidão ,t[1]: timer da vida,t[2] timer de atraso t[3]: timer de repetição objs, t[4] velocidade do game.
float delay;//Atraso do game, serve para diminuir a velocidade do jogo tornando estavel para todos computadores.

void tempo() {t[4]++;}//Função que chama o timer de velocidade do game, e começa a contar 0 a infinito


// VARIAVEIS DOS PLACARES E OUTROS
int pontos = 0;//Inicio dos pontos
int up = 100;//Aumento de pontos
int vidas = 2;//Inicio das vidas  

int jogar = 0;//variavel de iniciação do game,Se jogar for  0 falso, 1 verdadeiro
    
int velocidade[6] = {15,15,13,10,12};//Vetor de velocidades individuais obj e perso



int main() {
	
        init();//INICIAÇÃO  
        
        
        
        //Variáveis Locais
	
        BITMAP* buffer = create_bitmap(800, 600);//Cria a janela do jogo 
        
	
	    imagem0 = load_bitmap("img/rato rosa 2.bmp", NULL);//carrega a imagem no rato
     	imagem1 = load_bitmap("img/queijo normal.bmp", NULL);//carrega a imagem do queijo
      	imagem2 = load_bitmap("img/ratoeiraV1.bmp", NULL);//carrega a imagem da ratoeira
        imagem3 = load_bitmap("img/gato policia  right.bmp", NULL);// carrega a imagem do gato da direita
        imagem4 = load_bitmap("img/poison.bmp", NULL);// carrega a imagem do veneno
        imagem5 = load_bitmap("img/vida.bmp", NULL);// carrega a imagem da vida   
        imagem6 = load_bitmap("img/gato policia  left.bmp", NULL);// carrega a imagem do gato da esquerda        
    	imagem7 = load_bitmap("img/Logo.bmp", NULL);
   		imagem8 = load_bitmap("img/inf.bmp", NULL);
	    imagem9 = load_bitmap("img/Cenario2.bmp", NULL);
   		
	while (!(sai || key[KEY_ESC]))//laço para que o programa fiquei ativo, a tecla esc sai do programa
	{
       
      
        
        
   
         // CENARIO DO GAME,PERSONAGENS,CONTROLES.
          
        delay = t[4];//velocidade do jogo 1
        
        
        //Funções
        menu();
        
        colisaoobjs();
        
        control();
        
        controlobjs();
        
        restart(); 

                                  
        //Cenario e personagens
        
        draw_sprite(buffer, imagem9, 0, 0);//Cenario
      
       
        draw_sprite(buffer, imagem1, obj[0].x, obj[0].y);// Queijo 0
        draw_sprite(buffer, imagem1, obj[1].x, obj[1].y);// Queijo 1
        draw_sprite(buffer, imagem1, obj[2].x, obj[2].y);// Queijo 2
        draw_sprite(buffer, imagem1, obj[3].x, obj[3].y);// Queijo 3
         
         
         
        draw_sprite(buffer, imagem2, obj2[0].x, obj2[0].y);//Ratoeira 0
        draw_sprite(buffer, imagem2, obj2[1].x, obj2[1].y);//Ratoeira 1 
        draw_sprite(buffer, imagem2, obj2[2].x, obj2[2].y);//Ratoeira 2
        
          
        draw_sprite(buffer, imagem4, obj3[0].x, obj3[0].y);//Veneno 0
        draw_sprite(buffer, imagem4, obj3[1].x, obj3[1].y);//Veneno 1
        draw_sprite(buffer, imagem4, obj3[2].x, obj3[2].y);//Veneno 2
        
        
        
        draw_sprite(buffer, imagem5, obj4.x, obj4.y);//Vida
        
        masked_blit(imagem0, buffer, p.wx + nTile[0]*72, p.wy + dir[0]*94, p.x, p.y, p.w, p.h);// Rato 
        
        masked_blit(imagem3,buffer, p2[0].wx + nTile[1]*90, p2[0].wy + dir[1]*50, p2[0].x,p2[0].y ,p2[0].w-5, p2[0].h );// Gato Direita 
        
        
		masked_blit(imagem6,buffer, p3[0].wx + nTile[2]*90, p3[0].wy + dir[2]*50, p3[0].x,p3[0].y ,p3[0].w-5, p3[0].h);// Gato Esquerda
	
   
        rectfill (buffer, 750,0,width, height, cor[5]);//barra branca da direita
        rectfill (buffer, 0,555,width, height, cor[5]);//barra branca de baixo
        rectfill (buffer, 0,0,50,600, cor [5]);//barra branca da esquerda
        rectfill (buffer, 0,0,800,40, cor [5]);//barra branca de cima
        textprintf_ex(buffer,font,400,20,0xA459D0 ,-1,"PONTUACAO %i", pontos);//PLACAS PONTOS  
        textprintf_ex(buffer,font,400,30,0xA459D0 ,-1,"VIDAS %ix", vidas);//PLACAR VIDAS
        
      // textprintf_ex(buffer,font,300,30,0xA459D0 ,-1,"tempo %i", t[3]);
      
        if (velocidade[0] == 10 || velocidade[0] == 5){textprintf_ex(buffer,font,200,30,0xA459D0 ,-1,"TEMPO LENTIDAO %i", t[0]);}//PLACAR TEMPO
        
        if (vidas<1){textprintf_ex(buffer,font,360,210,0xA459D0 ,-1,"GAME OVER");}//Mensagem de game over apos todas as vidas acabarem
        
         
        draw_sprite(buffer, imagem8, obj6.x,obj6.y);//INSTRUÇAO
        
        draw_sprite(buffer, imagem7, obj5.x,obj5.y);//LOGO MENU
        
        draw_sprite(screen, buffer, 0, 0);//tela principal para aparecer o cenario, personagem e outras imagens
		
		
	
		
		while (t[4] == delay) {} //velocidade do jogo 2
		
		clear(buffer);//limpa tela apos finalizão
		
  
    
        	
	}
	
	//Finalização
	destroy_bitmap(buffer);//finaliza a janela
	destroy_bitmap(imagem0);//finaliza o persongaem
	destroy_bitmap(imagem1);// finaliza o queijo
	destroy_bitmap(imagem2);// finaliza a ratoeira
	destroy_bitmap(imagem3);//finaliza o gato direita
	destroy_bitmap(imagem4);//finaliza veneno
	destroy_bitmap(imagem5);//finaliza vida
	destroy_bitmap(imagem6);//finaliza gato esquerda
    destroy_bitmap(imagem7);//Finaliza menu
    destroy_bitmap(imagem8);//Finaliza instruçoes
    destroy_bitmap(imagem9);//Finaliza cenario
	return 0;
}
END_OF_MAIN();




void init()
{
     //Iniciação
	allegro_init();//inicia allegro

	set_color_depth(32);//adiciona cores
	set_window_title("BUERO");//adiciona titulo
	set_close_button_callback(sair);//adiciona botão para sair
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);//adiciona o som   
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);//adiciona resolução da tela width 800 e height 600
	
    install_keyboard();//adiciona o teclado
    install_timer();// adiciona tempo
	install_int_ex(tempo, MSEC_TO_TIMER (100));//Instala um tempo/velocidade para o jogo
    
} 

void menu()
{
        if (key[KEY_ENTER])//Se pressionado a tecla enter  
        {
          obj5.x = 1000;//Menu Muda de posição
          obj5.y = 1000;//Mesma coisa
        }  
         
        if(key[KEY_SPACE] && !jogar)//Se pressionar tecla espaço o jogo inicia, !jogar e igual a 0, se dentro do if a variavel jogar for igual a 1, ai e verdadeiro  inicia game, tipo portas NOT.               
        {
          obj6.x = 1000;//Instruçoes muda posiçao
          obj6.y = 1000;//Mesma coisa  
          
          jogar = 1;//se jogar for igual a 1 os objetos começam a se movimentar  
        
          obj[0].x = 800;//Posiçao Queijo 0
          obj[0].y = 300;
          
          obj[1].x = 800;//Posiçao Queijo 1
          obj[1].y = 100;
          
          obj[2].x = 300;//Posiçao Queijo 2
          obj[2].y = 600;
          
          obj[3].x = 600;//Posiçao Queijo 3
          obj[3].y = -20;
          
          obj2[0].x = -100;//Posiçao Ratoeira 0
          obj2[0].y = 490;
          
          obj2[1].x = 623;//Posiçao Ratoeira 1
          obj2[1].y = -10;
          
          obj2[2].x = -100;//Posiçao Ratoeira 2
          obj2[2].y = 490;
          

          obj3[0].x = 200;//Posiçao Veneno 0
          obj3[0].y = 600;
          
          obj3[1].x = 300;//Posiçao Veneno 1
          obj3[1].y = -50;
          
          obj3[2].x = 800;//Posiçao Veneno 2
          obj3[2].y = 200;
          
          obj4.x = 400;//Posiçao Vida
          obj4.y = 600;
          
          p2[0].x  = -60;//Posiçao Gato direita
          p2[0].y  = 100;

         
          p3[0].x  = 800;//Posiçao Gato esquerda  
          p3[0].y  = 400; 
          
          
         
          
          } 
          if (jogar==1)
          {
            t[1]++;          
            t[3]++;
          }               
     
}     

void restart()
{
     
   if (vidas<1)//Se vida menor que 1
   {
         t[2]++;//Timer começa a contar
         
         t[3] = 0;//timer de iniciação dos objetos zera 
         t[1] = 0;//Timer vida zera  
            
         vidas = 0;//Vidas serão zeradas
               
          p.x = 360;//Rato revive para posição 360
          p.y = 225;//Mesma coisa
        
        //Trava o controle personagem
        p.y -= velocidade[0] = 0;
        p.x += velocidade[0] = 0;
        p.x -= velocidade[0] = 0;
        p.y += velocidade[0] = 0;
               
          obj[0].x = 0;//Posiçao Queijo 0
          obj[0].y = 0;
          
          obj[1].x = 0;//Posiçao Queijo 1
          obj[1].y = 0;
          
          obj[2].x = 0;//Posiçao Queijo 2
          obj[2].y = 0;
          
          obj[3].x = 0;
          obj[3].y = 0;
          
          
          obj2[0].x = 0;//Posiçao Ratoeira 0
          obj2[0].y = 0;
          
          obj2[1].x = 0;//Posiçao Ratoeira 1
          obj2[1].y = 0;
          
          obj2[2].x = 0;//Posiçao Ratoeira 2
          obj2[2].y = 0;
          
 
      
          obj3[0].x = 0;//Posiçao Veneno
          obj3[0].y = 0;
          
          obj3[1].x = 0;//Posiçao Veneno
          obj3[1].y = 0;
          
          obj3[2].x = 0;//Posiçao Veneno
          obj3[2].y = 0;
          
          
          obj4.x = 0;//Posiçao Vida
          obj4.y = 0;
          
          p2[0].x  = -50;//Posiçao Gato direita 0
          p2[0].y  = -50;

         
          p3[0].x  = -50;//Posiçao Gato esquerda  
          p3[0].y  = -50;
        
        if(t[2] == 5)//Quando o timer chegar a 5
        {
                
            rest(1000);//Atraso de 1 seg
            vidas = 3;//Vidas retornam para 2
            pontos = 0;//Pontos zerão
            
                    
          obj[0].x = 0;//Posiçao Queijo
          obj[0].y = 0;
          
          obj[1].x = 800;//Posiçao Queijo 1
          obj[1].y = 500;
          
          obj[2].x = 600;//Posiçao Queijo 2
          obj[2].y = 700;
          
          obj[3].x = 100;//Posiçao Queijo 3
          obj[3].y = 600;
      
          
          obj2[0].x = -100;//Posiçao Ratoeira 0
          obj2[0].y = 490;
          
          obj2[1].x = -100;//Posiçao Ratoeira 1
          obj2[1].y = 490;
          
          obj2[2].x = -100;//Posiçao Ratoeira 2
          obj2[2].y = 490;
          

          obj3[0].x = 200;//Posiçao Veneno 0
          obj3[0].y = 600;
          
          obj3[1].x = 300;//Posiçao Veneno 1
          obj3[1].y = -50;
          
          obj3[2].x = 800;//Posiçao Veneno 2
          obj3[2].y = 356;
          
          
          obj4.x = 600;//Posiçao Vida
          obj4.y = 800;
          
          p2[0].x  = -60;//Posiçao Gato direita 
          p2[0].y  = 100;

          
          p3[0].x  = 400;//Posiçao Gato esquerda  
          p3[0].y  = 600;
            
           
            t[2] = 0;//Timer zera
        }     
                             
   }
    
     
}


void control()//controle do personagem
{
    
    
     //Controle Personagem rato   
     if  (key[KEY_UP] && p.y > 48) {p.y -= velocidade[0]; dir[0] = 0; nTile[0]--;}
     else if(key[KEY_RIGHT]&& p.x <685) {p.x += velocidade[0]; dir[0] = 1; nTile[0]++;}
     else if(key[KEY_LEFT]&& p.x >58)  {p.x -= velocidade[0]; dir[0] = 3; nTile[0]++;}
     else if(key[KEY_DOWN]&& p.y <485) {p.y += velocidade[0]; dir[0] = 2; nTile[0]++;}
     else nTile[0]  = 1;//nTile altera as animações quando e pressionado as teclas
     if(nTile[0] <0) nTile[0] = 1;
     if(nTile[0] >1) nTile[0] = 0;
     
     
    
}

void controlobjs()
{

    controlqueijo();
    
    controlveneno();
    
    controlvida();   
 
    controlratoeira();
    
    controlgatos();
    
      if (t[3]>600)
    {
       t[3]=0;          
    }      
              
}      
   
void colisaoobjs()
{

       //COLISAO DOS OBJETOS

        colisaogatos();        
                 
        colisaoratoeira();
 
        colisaoqueijo(); 
         
        colisaoveneno(); 
         
        colisaovida(); 


     
}




         // FUNÇÃO CONTROLE DOS OBJETOS

void controlqueijo()
{ 
     //QUEIJO 0
     obj[0].x -= velocidade[3];

    if (t[3] == 30){ if(obj[0].x < -obj[0].x + 20) {obj[0].x = width;}}
    
     if (t[3] == 120)
    {
       obj[0].x = 800;
       obj[0].y = 450;
             
    }
        if (t[3] == 200)
    {
       obj[0].x = 800;
       obj[0].y = 200;
             
    }
        if (t[3] == 280)
    {
       obj[0].x = 800;
       obj[0].y = 100;
             
    }
         if (t[3] == 365)
    {
       obj[0].x = 800;
       obj[0].y = 50;
             
    }
           if (t[3] == 450)
    {
       obj[0].x = 800;
       obj[0].y = 450;
             
    }
       if (t[3] == 535)
    {
       obj[0].x = 800;
       obj[0].y = 351;
             
    }
    
    
    
    
    //QUEIJO 1
     obj[1].x += velocidade[3];
     if (t[3] == 50)
     {if(obj[1].x > width + 200) {obj[1].x = -obj[1].x;}}  
      
           if(t[3] == 50)
            {
               obj[1].x = 0;
               obj[1].y = 150;    
            }
    
           if(t[3] == 130)
            {
               obj[1].x = 0;
               obj[1].y = 500;    
            }
            
            if(t[3] == 220)
            {
               obj[1].x = 0;
               obj[1].y = 300;    
            }
            if(t[3] == 300)
            {
               obj[1].x = 0;
               obj[1].y = 70;    
            }
            if(t[3] == 380)
            {
               obj[1].x = 0;
               obj[1].y = 450;    
            }
             if(t[3] == 460)
            {
               obj[1].x = 0;
               obj[1].y = 225;    
            }
             if(t[3] == 550)
            {
               obj[1].x = 0;
               obj[1].y = 80;    
            }
            
            
     
     
     
      //QUEIJO 2      
     obj[2].y -= velocidade[3];
     
     if (t[3] == 10){if(obj[2].y < -obj[2].y - 50)  {obj[2].y = height;}}  
      
             if(t[3] == 90)
            {
               obj[2].x = 300;
               obj[2].y = 600;    
            }
              if(t[3] == 150)
            {
               obj[2].x = 150;
               obj[2].y = 600;    
            }
             if(t[3] == 210)
            {
               obj[2].x = 700;
               obj[2].y = 600;    
            }       
               if(t[3] == 290)
            {
               obj[2].x = 400;
               obj[2].y = 600;    
            }
               if(t[3] == 350)
            {
               obj[2].x = 100;
               obj[2].y = 600;    
            }
             if(t[3] == 420)
            {
               obj[2].x = 200;
               obj[2].y = 600;    
            }
             if(t[3] == 500)
            {
               obj[2].x = 600;
               obj[2].y = 600;    
            }
                if(t[3] == 560)
            {
               obj[2].x = 100;
               obj[2].y = 600;    
            }
            
                       
         //QUEIJO 3
         obj[3].y += velocidade[3];
 
         if (t[3]== 0) { if(obj[3].y > height){ obj[3].y = -obj[3].y; }} 
        
         if (t[3]== 80)
         {
            obj[3].x = 100;       
            obj[3].y = 0;       
         } 
         if (t[3]== 160)
         {
            obj[3].x = 400;       
            obj[3].y = 0;       
         } 
         if (t[3]== 220)
         {
            obj[3].x = 500;       
            obj[3].y = 0;       
         } 
         if (t[3]== 300)
         {
            obj[3].x = 300;       
            obj[3].y = 0;       
         }
         if (t[3]== 380)
         {
            obj[3].x = 700;       
            obj[3].y = 0;       
         }         
         if (t[3]== 440)
         {
            obj[3].x = 100;       
            obj[3].y = 0;       
         } 
         if (t[3]== 520)
         {
            obj[3].x = 450;       
            obj[3].y = 0;       
         }
            
   
             
    

     
}



void controlratoeira()
{
     //CONTROLE RATOEIRA 0
    obj2[0].x += velocidade[1];
    
    if(t[3] == 10){ if(obj2[0].x > width + 50) {obj2[0].x = -obj2[0].x;}}
    
    if(t[3] == 100)
    {               
          obj2[0].x = -100;
          obj2[0].y = 250;              
    }
    
        if(t[3] == 170)
    {               
          obj2[0].x = -100;
          obj2[0].y = 100;              
    }
           if(t[3] == 230)
    {               
          obj2[0].x = -100;
          obj2[0].y = 50;              
    }
            if(t[3] == 300)
    {               
          obj2[0].x = -100;
          obj2[0].y = 500;              
    }
            if(t[3] == 400)
    {               
          obj2[0].x = -100;
          obj2[0].y = 50;              
    }
          if(t[3] == 470)
    {               
          obj2[0].x = -100;
          obj2[0].y = 150;              
    }
          if(t[3] == 570)
    {               
          obj2[0].x = -100;
          obj2[0].y = 300;              
    }
        
    //CONTROLE RATOEIRA 1 
    obj2[1].y += velocidade[1];
    
    if(t[3] == 10){if(obj2[1].y > height - 50) {obj2[1].y = -obj2[1].y;}} 
    
     if(t[3] == 60)
     {
           obj2[1].x = 100;       
           obj2[1].y = 0;
     } 
      if(t[3] == 150)
     {
           obj2[1].x = 400;       
           obj2[1].y = 0;
     }      
       if(t[3] == 210)
     {
           obj2[1].x = 600;       
           obj2[1].y = 0;
     } 
       if(t[3] == 300)
     {
           obj2[1].x = 200;       
           obj2[1].y = 0;
     } 
          if(t[3] == 410)
     {
           obj2[1].x = 380;       
           obj2[1].y = 0;
     } 
         if(t[3] == 500)
     {
           obj2[1].x = 50;       
           obj2[1].y = 0;
     }
      //CONTROLE RATOEIRA 2
          obj2[2].y -= velocidade[1];
    
          if(t[3] == 10){if(obj2[2].y < -obj2[2].y - 50) {obj2[2].y = height;}}
          
               if(t[3] == 50)
               {
                     obj2[2].x = 600;       
                     obj2[2].y = 700;     
               } 
               if(t[3] == 140)
               {
                     obj2[2].x = 200;       
                     obj2[2].y = 700;     
               } 
               if(t[3] == 200)
               {
                     obj2[2].x = 350;       
                     obj2[2].y = 700;     
               }  
                 if(t[3] == 260)
               {
                     obj2[2].x = 210;       
                     obj2[2].y = 700;     
               }
                 if(t[3] == 350)
               {
                     obj2[2].x = 450;       
                     obj2[2].y = 700;     
               }
                  if(t[3] == 420)
               {
                     obj2[2].x = 500;       
                     obj2[2].y = 700;     
               } 
                       if(t[3] == 500)
               {
                     obj2[2].x = 100;       
                     obj2[2].y = 700;     
               }
                     if(t[3] == 560)
               {
                     obj2[2].x = 280;       
                     obj2[2].y = 700;     
               }
                
                      
     
}
void controlveneno()
{
     //CONTROLE VENENO 0
    obj3[0].y -= velocidade[1];
    if (t[3] == 25)
    {   
    if(obj3[0].y < -obj3[0].y - 100) 
    {
      obj3[0].y = height;            
    } 
    } 
     if (t[3] == 95)
     {
          obj3[0].x = 600;//Posiçao Veneno
          obj3[0].y = 600;    
     }        
      if (t[3] == 150)
     {
          obj3[0].x = 100;//Posiçao Veneno
          obj3[0].y = 600;    
     }          
      if (t[3] == 220)
     {
          obj3[0].x = 420;//Posiçao Veneno
          obj3[0].y = 600;    
     }
           if (t[3] == 300)
     {
          obj3[0].x = 532;//Posiçao Veneno
          obj3[0].y = 600;    
     } 
              if (t[3] == 370)
     {
          obj3[0].x = 152;//Posiçao Veneno
          obj3[0].y = 600;    
     } 
              if (t[3] == 450)
     {
          obj3[0].x = 357;//Posiçao Veneno
          obj3[0].y = 600;    
     }
              if (t[3] == 505)
     {
          obj3[0].x = 650;//Posiçao Veneno
          obj3[0].y = 600;    
     }
                if (t[3] == 560)
     {
          obj3[0].x = 429;//Posiçao Veneno
          obj3[0].y = 600;    
     }
     //CONTROLE VENENO 1
     
    obj3[1].y += velocidade[1];
    
    if (t[3] == 20)
    {   
    if(obj3[1].y > height + 150) 
    {
      obj3[1].y = -obj3[1].y ;            
    } 
    } 
     if (t[3] == 80)
     {
        obj3[1].x  = 100;    
        obj3[1].y  = 0;    
     }  
      if (t[3] == 140)
     {
        obj3[1].x  = 620;    
        obj3[1].y  = 0;    
     }
          if (t[3] == 200)
     {
        obj3[1].x  = 200;    
        obj3[1].y  = 0;    
     }   
         if (t[3] == 260)
     {
        obj3[1].x  = 381;    
        obj3[1].y  = 0;    
     }
        if (t[3] == 320)
     {
        obj3[1].x  = 600;    
        obj3[1].y  = 0;    
     }
        if (t[3] == 390)
     {
        obj3[1].x  = 356;    
        obj3[1].y  = 0;    
     } 
        if (t[3] == 445)
     {
        obj3[1].x  = 532;    
        obj3[1].y  = 0;    
     } 
       if (t[3] == 500)
     {
        obj3[1].x  = 351;    
        obj3[1].y  = 0;    
     } 
     
     //CONTROLE VENENO 2
     obj3[2].x -= velocidade[1];
    
    if (t[3] == 30)
    {   
    if(obj3[2].x < -obj3[2].x +50) 
    {
      obj3[2].x = width;            
    } 
    }
      
     if (t[3] == 113)
     {
        obj3[2].x = 800;
        obj3[2].y = 100;    
     }        
        if (t[3] == 190)
     {
        obj3[2].x = 900;
        obj3[2].y = 325;    
     }
        if (t[3] == 260)
     {
        obj3[2].x = 800;
        obj3[2].y = 150;    
     } 
         if (t[3] == 320)
     {
        obj3[2].x = 800;
        obj3[2].y = 450;    
     }         
         if (t[3] == 386)
     {
        obj3[2].x = 800;
        obj3[2].y = 350;    
     } 
          if (t[3] == 450)
     {
        obj3[2].x = 800;
        obj3[2].y = 50;    
     } 
         if (t[3] == 505)
     {
        obj3[2].x = 800;
        obj3[2].y = 280;    
     } 
         if (t[3] == 569)
     {
        obj3[2].x = 800;
        obj3[2].y = 400;    
     } 
     
     
               
     
}  
void controlvida()
{
      //CONTROLE VIDA
    
    obj4.y -= velocidade[3];
    
    
    if (t[1] == 20)//Objeto começa a subir//O objeto apareça somente quando o tempo for igual a 50
   {
    if(obj4.y < -obj4.y - 50)
    {
    obj4.y = height;
    }
    
   if(t[1] == 100)
   { 
     obj4.x = 200;
     obj4.y = 600;
     
   }
   
}
    if (t[1]>5000)
    {
     t[1]=0;
    } 
         
}     
void controlgatos()
{
      //CONTROLE GATO DIREITA 0
    if(p2[0].x < width){p2[0].x += velocidade[1]; dir[1] = 0; nTile[1]++;}
    else nTile[1]  = 1;//nTile altera as animações quando e pressionado as teclas
    if(nTile[1] <0) nTile[1] = 1;
    if(nTile[1] >1) nTile[1] = 0; 
    
    if(p2[0].x > width - 70){p2[0].x = -p2[0].x;}
    
    if (t[3] == 80)
    {
       p2[0].x = -60;
       p2[0].y = 300;
    }
    if (t[3] == 180)
    {
       p2[0].x = -60;
       p2[0].y = 400;
    }
      if (t[3] == 280)
    {
       p2[0].x = -60;
       p2[0].y = 50;
    }
    if (t[3] == 370)
    {
       p2[0].x = -60;
       p2[0].y = 80;
    }
       if (t[3] == 450)
    {
       p2[0].x = -60;
       p2[0].y = 300;
    }
    if (t[3] == 520)
    {
       p2[0].x = -60;
       p2[0].y = 100;
    }
    
    
    
    
    
    //CONTROLE GATO ESQUERDA
    if(p3[0].x > -p3[0].x - 70){p3[0].x -= velocidade[1]; dir[2] = 0; nTile[2]++;}
    else nTile[2]  = 1;//nTile altera as animações quando e pressionado as teclas
    if(nTile[2] <0) nTile[2] = 1;
    if(nTile[2] >1) nTile[2] = 0; 
    if (t[3] == 50)
    {
    if(p3[0].x < -p3[0].x - 40){p3[0].x = width + 100;}
    }
       if (t[3] == 120)
    {
       p3[0].x = 800;
       p3[0].y = 290;
    }  
       if (t[3] == 180)
    {
       p3[0].x = 800;
       p3[0].y = 150;
    }  
         if (t[3] == 245)
    {
       p3[0].x = 800;
       p3[0].y = 300;
    }    
       if (t[3] == 310)
    {
       p3[0].x = 800;
       p3[0].y = 50;
    } 
       if (t[3] == 370)
    {
       p3[0].x = 800;
       p3[0].y = 450;
    }    
         if (t[3] == 430)
    {
       p3[0].x = 800;
       p3[0].y = 300;
    } 
         if (t[3] == 495)
    {
       p3[0].x = 800;
       p3[0].y = 50;
    }
     if (t[3] == 550)
    {
       p3[0].x = 800;
       p3[0].y = 350;
    } 
       
           
}     
   
   
   
   
   //FUNÇÃO COLISAO DOS OBJETOS
   
  
void colisaoqueijo()
{
     //COLISAO DOS QUEIJOS
     
     //QUEIJO 0
      if (colidir(p.x, p.y, obj[0].x, obj[0].y , 45, 50, 35, 30))
        {
                       
        pontos += up;//Aumenta 100 pontos, up vale 100 o valor de up, passara para pontos sempre que o rato encostar no queijo.
        
        obj[0].x = 0;//Queijo vai para posição 0
        obj[0].y = 0;//Mesma coisa 
           
        } 
        
      //QUEIJO 1  
         if (colidir(p.x, p.y, obj[1].x, obj[1].y , 45, 50, 35, 30))
        {
                       
        pontos += up;//Aumenta 100 pontos, up vale 100 o valor de up, passara para pontos sempre que o rato encostar no queijo.
        
        obj[1].x = 0;//Queijo vai para posição 0
        obj[1].y = 0;//Mesma coisa
        
        
           
        } 
        
        //QUEIJO 2
        if (colidir(p.x, p.y, obj[2].x, obj[2].y , 45, 50, 35, 30))
        {
                       
        pontos += up;//Aumenta 100 pontos, up vale 100 o valor de up, passara para pontos sempre que o rato encostar no queijo.
        
        obj[2].x = 0;//Queijo vai para posição 0
        obj[2].y = 0;//Mesma coisa
        
        
           
        } 
         //QUEIJO 3
        if (colidir(p.x, p.y, obj[3].x, obj[3].y , 45, 50, 35, 30))
        {
                       
        pontos += up;//Aumenta 100 pontos, up vale 100 o valor de up, passara para pontos sempre que o rato encostar no queijo.
        
        obj[3].x = 0;//Queijo vai para posição 0
        obj[3].y = 0;//Mesma coisa
        
        
           
        } 
        

     
}     
void colisaoratoeira()
{
        
        //COLISAO RAOTEIRA 0
        
     if (colidir(p.x, p.y, obj2[0].x, obj2[0].y, 45, 50, 70, 30))
        {
                pontos -= up; //Diminui -100 pontos se colidir com ratoeira
         
                obj2[0].x = -10;//Ratoeira vai para posição -10
                obj2[0].y = -10; //Mesma coisa 
                 
       
        } 
        
     else if (pontos<0)//se pontos menor que 0 ex: -100.
        {
                pontos += up; //pontos voltam para 0

                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                
           if (velocidade[0] == 15)//Se a velocidade estiver normal, apenas descrementa - 1 vida
            { 
              vidas -=1;//Descrementa - 1 vida               
            }
            
           if (velocidade[0] == 10)//Se houve apenas uma colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida 
           {
              t[0]=0;//Timer reseta
              vidas -=1; //Descrementa - 1 vida
              velocidade[0] +=5;//Velocidade atribui + 5                 
           }    
             
           if (velocidade[0] == 5)//Se houve a segunda colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida  
           {
              t[0]=0;//Timer reseta
              vidas -=1;//Descrementa - 1 vida 
              velocidade[0] +=10;//Velocidade atribui + 10 
           }  
                
                
        }
        
                //COLISAO RAOTEIRA 1
        
     if (colidir(p.x, p.y, obj2[1].x, obj2[1].y, 45, 50, 70, 30))
        {
                pontos -= up; //Diminui -100 pontos se colidir com ratoeira
         
                obj2[1].x = -50;//Ratoeira vai para posição -10
                obj2[1].y = -10; //Mesma coisa 
                 
       
        } 
        
     else if (pontos<0)//se pontos menor que 0 ex: -100.
        {
                pontos += up; //pontos voltam para 0

                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                
           if (velocidade[0] == 15)//Se a velocidade estiver normal, apenas descrementa - 1 vida
            { 
              vidas -=1;//Descrementa - 1 vida               
            }
            
           if (velocidade[0] == 10)//Se houve apenas uma colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida 
           {
              t[0]=0;//Timer reseta
              vidas -=1; //Descrementa - 1 vida
              velocidade[0] +=5;//Velocidade atribui + 5                 
           }    
             
           if (velocidade[0] == 5)//Se houve a segunda colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida  
           {
              t[0]=0;//Timer reseta
              vidas -=1;//Descrementa - 1 vida 
              velocidade[0] +=10;//Velocidade atribui + 10 
           }  
                
                
        }
        
        
                //COLISAO RAOTEIRA 2
        
     if (colidir(p.x, p.y, obj2[2].x, obj2[2].y, 45, 50, 70, 30))
        {
                pontos -= up; //Diminui -100 pontos se colidir com ratoeira
         
                obj2[2].x = -30;//Ratoeira vai para posição -10
                obj2[2].y = -10; //Mesma coisa 
                 
       
        } 
        
     else if (pontos<0)//se pontos menor que 0 ex: -100.
        {
                pontos += up; //pontos voltam para 0

                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                
           if (velocidade[0] == 15)//Se a velocidade estiver normal, apenas descrementa - 1 vida
            { 
              vidas -=1;//Descrementa - 1 vida               
            }
            
           if (velocidade[0] == 10)//Se houve apenas uma colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida 
           {
              t[0]=0;//Timer reseta
              vidas -=1; //Descrementa - 1 vida
              velocidade[0] +=5;//Velocidade atribui + 5                 
           }    
             
           if (velocidade[0] == 5)//Se houve a segunda colisao com o veneno a velocidade sera 10, e se a pontuação for < do que 0 e houver colisão com a ratoeira descrementa - 1 vida  
           {
              t[0]=0;//Timer reseta
              vidas -=1;//Descrementa - 1 vida 
              velocidade[0] +=10;//Velocidade atribui + 10 
           }  
                
                
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            
}
void colisaoveneno()
{
        //COLISAO VENENO 0
        if(colidir(p.x, p.y, obj3[0].x, obj3[0].y, 50, 50, 25, 50))
        {
            
          velocidade[0] -= 5;//Se colidir com o veneno a velocidade sera descontada para -5
          
          obj3[0].x = 0;//Veneno vai para posição 0  
                    
          obj3[0].y = 0;//Mesma coisa
         }
          
         if (velocidade[0] == 10 || velocidade[0] == 5)//O veneno tera no maximo 2 colisoes, a primeira a velocidade sera diminuida para 10, na segunda para 5.
         
            t[0]++;//Timer ira começar a contar.
                      
  
         if (velocidade[0] == 0)//Se a velocidade for igual a 0
            {
              t[0]=0; //O Tempo de duração da lentidao do veneno ira resetar            
              vidas -= 1;//Porem vidas serão descontadas se houver mais que 2 colisoes com o veneno
              
                                                                    
              if (vidas == 5 ||vidas == 4 ||vidas == 3 ||vidas == 2 ||vidas == 1 || vidas == 0)//O maximo de vidas que serão descrementadas.
              {      
                                                                                                //OBS : VIDAS 0 ALTERAR DEPOIS DOS TESTES             
                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                        
               velocidade[0] +=15;//Quando o Rato resetar sua velocidade retorna.
              }
             
                
            }         
                                                           
		  if(t[0]>150)//Tempo maximo 
          { 
             velocidade[0] +=5;//Apos o tempo acabar a velocidade acrescenta +5.
             
             t[0]=0;//Timer reseta
          }  
         
         
         
         
         //COLISAO VENENO 1
        if(colidir(p.x, p.y, obj3[1].x, obj3[1].y, 50, 50, 25, 50))
        {
            
          velocidade[0] -= 5;//Se colidir com o veneno a velocidade sera descontada para -5
          
          obj3[1].x = 0;//Veneno vai para posição 0  
                    
          obj3[1].y = 0;//Mesma coisa
         }
          
         if (velocidade[0] == 10 || velocidade[0] == 5)//O veneno tera no maximo 2 colisoes, a primeira a velocidade sera diminuida para 10, na segunda para 5.
         
            t[0]++;//Timer ira começar a contar.
                      
  
         if (velocidade[0] == 0)//Se a velocidade for igual a 0
            {
              t[0]=0; //O Tempo de duração da lentidao do veneno ira resetar            
              vidas -= 1;//Porem vidas serão descontadas se houver mais que 2 colisoes com o veneno
              
                                                                    
              if (vidas == 5 ||vidas == 4 ||vidas == 3 ||vidas == 2 ||vidas == 1 || vidas == 0)//O maximo de vidas que serão descrementadas.
              {      
                                                                                                //OBS : VIDAS 0 ALTERAR DEPOIS DOS TESTES             
                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                        
               velocidade[0] +=15;//Quando o Rato resetar sua velocidade retorna.
              }
             
                
            }         
                                                           
		  if(t[0]>150)//Tempo maximo 
          { 
             velocidade[0] +=5;//Apos o tempo acabar a velocidade acrescenta +5.
             
             t[0]=0;//Timer reseta
          }
          
          
        //COLISAO VENENO 2
        if(colidir(p.x, p.y, obj3[2].x, obj3[2].y, 50, 50, 25, 50))
        {
            
          velocidade[0] -= 5;//Se colidir com o veneno a velocidade sera descontada para -5
          
          obj3[2].x = -50;//Veneno vai para posição 0  
                    
          obj3[2].y = -50;//Mesma coisa
         }
          
         if (velocidade[0] == 10 || velocidade[0] == 5)//O veneno tera no maximo 2 colisoes, a primeira a velocidade sera diminuida para 10, na segunda para 5.
         
            t[0]++;//Timer ira começar a contar.
                      
  
         if (velocidade[0] == 0)//Se a velocidade for igual a 0
            {
              t[0]=0; //O Tempo de duração da lentidao do veneno ira resetar            
              vidas -= 1;//Porem vidas serão descontadas se houver mais que 2 colisoes com o veneno
              
                                                                    
              if (vidas == 5 ||vidas == 4 ||vidas == 3 ||vidas == 2 ||vidas == 1 || vidas == 0)//O maximo de vidas que serão descrementadas.
              {      
                                                                                                //OBS : VIDAS 0 ALTERAR DEPOIS DOS TESTES             
                p.x = 360;//Rato revive para posição 360
                p.y = 225;//Mesma coisa
                        
               velocidade[0] +=15;//Quando o Rato resetar sua velocidade retorna.
              }
             
                
            }         
                                                           
		  if(t[0]>150)//Tempo maximo 
          { 
             velocidade[0] +=5;//Apos o tempo acabar a velocidade acrescenta +5.
             
             t[0]=0;//Timer reseta
          }
          
          
}     
void colisaovida()
{
//COLISAO VIDAS
        
        if (colidir(p.x, p.y, obj4.x, obj4.y, 45, 50, 35, 30))
        {
       
         
         vidas +=1;//Vida aumenta para + 1
         
           obj4.x = 0;
           obj4.y = 0; 
          
          if (vidas == 6)//Se vidas for maior que 5.
          
              vidas -=1;//Vida sera descrementada - 1, e ficara no laço de 5.

        }               
    
}
void colisaogatos()
{
         //COLISAO COM O GATO DIREITA
      
     if (colidir(p.x, p.y, p2[0].x, p2[0].y, 50, 30, 83, 53))
        {     
                 
            p.x = 360;//Rato revive para posição 360
            p.y = 225;//Mesma coisa 
             
     
            if (velocidade[0] == 15)//Se a velocidade estiver normal, apenas descrementa - 1 vida
            { 
              vidas -=1;//A vida descrementa - 1              
            }
            
           if (velocidade[0] == 10)//Se houve apenas uma colisao com o veneno a velocidade diminuira para 10, e se houver colisão com o gato descrementa - 1 vida
           {
              t[0]=0;//O timer reseta
              vidas -=1; //A vida descrementa - 1
              velocidade[0] +=5;// Velocidade atribui + 5               
           }    
             
           if (velocidade[0] == 5)//Se houve a segunda colisao com o veneno a velocidade diminuira para 5, e se houver colisão com o gato descrementa - 1 vida
           {
              t[0]=0;//O timer reseta
              vidas -=1; //A vida descrementa - 1
              velocidade[0] +=10; //Velocidade atribui + 10  
           } 
               
     
        } 
          //COLISAO COM O GATO ESQUERDA            
     if (colidir(p.x, p.y, p3[0].x, p3[0].y, 50, 30, 83, 53))
        {
                     
             p.x = 360;//Rato revive para posição 360
             p.y = 225;//Mesma coisa
           
           if (velocidade[0] == 15)//Se a velocidade estiver normal, apenas descrementa - 1 vida
            { 
              vidas -=1; //A vida descrementa - 1              
            }
            
           if (velocidade[0] == 10)//Se houve apenas uma colisao com o veneno a velocidade sera 10, e se houver colisão com o gato descrementa - 1 vida
           {
              t[0]=0;//Timer reseta
              vidas -=1; //A vida descrementa - 1 
              velocidade[0] +=5;//Velocidade atribui + 5                
           }    
             
           if (velocidade[0] == 5)//Se houve a segunda colisao com o veneno a velocidade sera 5, e se houver colisão com o gato descrementa - 1 vida 
           {
              t[0]=0;//Timer reseta
              vidas -=1; //A vida descrementa - 1 
              velocidade[0] +=10;//Velocidade atribui + 10 
           }  
           
           
        }   
     
     
     
}     



     

//CODIGO DE COLISAO DOS ITENS BOX COLISION
int colidir(int Ax, int Ay, int Bx, int By, int Aw, int Ah, int Bw, int Bh)
{
    if(Ax + Aw > Bx && Ax < Bx + Bw && Ay + Ah > By && Ay < By + Bh)
     
    return 1;//Se houve colisão verdadeiro
    return 0;//Se não houve colisão falso
    
    
}

void sair(){sai= 1;}
END_OF_FUNCTION(sair);

