
#include <stdio.h>
#include "libs/libbmp.h"
#include "libs/imghelpers.h"

int main(){
  //Utilize apenas imagens .bmp com o formato 24 (true color)
  // converta em: https://online-converting.com/image/convert2bmp/
  bmp_img img;
  char filename[] = "cristo.bmp";
  printf("\n");
  IMG_TAM t = pegarTamanho(filename);
  int l = t.qtdLinhas,c = t.qtdColunas;
  int R[l][c];
  int G[l][c];
  int B[l][c];
  carregaImagem(t,R,G,B,filename);

  // MATRIZES COM FILTROS
/*
    // Matriz de convolução para o filtro "sharpen"
  int sharpen[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

  // Destacar relevo
  int relevo[3][3] = {{-2, -1, 0}, {-1, 1, 1}, {0, 1, 2}};

  // Destacar bordas
  int destacar[3][3] = {{0, 1, 0}, {1, -3, 1}, {0, -1, 0}};

  // Halftone
  int halftone[3][3] = {{6, 8, 4}, {1, 0, 3}, {5, 2, 7}};

 // Vinheta
  int vinheta[3][3] = {
    {-2, -3, -2},
    {-3, 16, -3},
    {-2, -3, -2}
};
// Clarendon
  int clarendon[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  */
  
  // manipule sua imagem aqui. 
/*for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      if (R[i][j] > 100) {
        R[i][j] -= 30;
      }
      if (G[i][j] > 100) {
        G[i][j] -= 35;
      }
      if (B[i][j] > 100) {
        B[i][j] -= 25;
      }
    }
      printf("\n");
    }
  */
  

 // GERAR BORDA PRETA DE 20 PIXELS
  /*
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        if (i < 20 || i >= l - 20 || j < 20 || j >= c - 20) {
          R[i][j] = 0;
          G[i][j] = 0;
          B[i][j] = 0;
        }
      }
    }

    // CLAREAR IMAGEM DA DIAGONAL PRINCIPAL 

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        if (i < j) {
          R[i][j] += 56;
          G[i][j] += 56;
          B[i][j] += 56;

          if (R[i][j] > 255) R[i][j] = 130;
          if (G[i][j] > 255) G[i][j] = 130;
          if (B[i][j] > 255) B[i][j] = 130;
        }
      }
    }
    */
  /*
    // ESPELHAR A IMAGEM

     for (int i = 0; i < l; i++) {
      for (int j = 0; j < c/2; j++) {
    // vetores temporarios
          int tempR = R[i][j];
          int tempG = G[i][j];
          int tempB = B[i][j];

          R[i][j] = R[i][c - j - 1];
          G[i][j] = G[i][c - j - 1];
          B[i][j] = B[i][c - j - 1];
          R[i][c - j - 1] = tempR;
          G[i][c - j - 1] = tempG;
          B[i][c - j - 1] = tempB;
      }
     }
  */

// MATRIZES DE CONVOLUÇÃO 

/*
  // Aplicar o filtros
  for (int i = 1; i < l - 1; i++) {
    for (int j = 1; j < c - 1; j++) {
      int filtroR = 0;
      int filtroG = 0;
      int filtroB = 0;

      // Aplicar a matriz de convolução para sharpen
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          filtroR += R[i + x][j + y] * sharpen[x + 1][y + 1];
          filtroG += G[i + x][j + y] * sharpen[x + 1][y + 1];
          filtroB += B[i + x][j + y] * sharpen[x + 1][y + 1];
        }
      }
      // Aplicar a matriz de convolução para destacar relevo
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          filtroR += R[i + x][j + y] * relevo[x + 1][y + 1];
          filtroG += G[i + x][j + y] * relevo[x + 1][y + 1];
          filtroB += B[i + x][j + y] * relevo[x + 1][y + 1];
        }
      }
      // Aplicar a matriz de convolução para destacar bordas
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          filtroR += R[i + x][j + y] * destacar[x + 1][y + 1];
          filtroG += G[i + x][j + y] * destacar[x + 1][y + 1];
          filtroB += B[i + x][j + y] * destacar[x + 1][y + 1];
        }
      }
      // Aplicar a matriz de convolução para halftone
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          filtroR += R[i + x][j + y] * halftone[x + 1][y + 1];
          filtroG += G[i + x][j + y] * halftone[x + 1][y + 1];
          filtroB += B[i + x][j + y] * halftone[x + 1][y + 1];
        }
      }
// Aplicar a matriz de convolução para vinheta
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          filtroR += R[i + x][j + y] * vinheta[x + 1][y + 1];
          filtroG += G[i + x][j + y] * vinheta[x + 1][y + 1];
          filtroB += B[i + x][j + y] * vinheta[x + 1][y + 1];
        }
      }

      
    }
  }
 */

  
// PHOTOSHOP INTERATIVO 
  int resposta = 0;
  
printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("• • • • • • • • • • • • • • • • • •\n\n");
printf("          PHOTOSHOP DANKA         \n\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("• • • • • • • • • • • • • • • • • •\n\n");
printf("         OPÇÕES DE FILTRO \n\n");
printf("1- Kamy\n2- Dani\n3- Preto e branco\n4- Sépia\n5- Skyline\n6- DogPatch\n7- Foto Antiga\n8- Polaroid\n9- Brooklyn\n10- Clarenton\n11- Colorir para o vermelho\n12- Colorir para o verde\n13- Colorir para o azul"); 
  printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("\n\nQual opção de filtro deseja aplicar? ");
  scanf("%d", &resposta);
  printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n\n");
  
// SWITCH PARA APLICAR FILTROS

  switch(resposta){
    case 1:{
      //FILTRO KAMY
          printf("\n\nFILTRO KAMY APLICADO!\n\n");
    for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      if (R[i][j] > 100) {
        R[i][j] -= 30;
      }
      if (G[i][j] > 100) {
        G[i][j] -= 35;
      }
      if (B[i][j] > 100) {
        B[i][j] -= 25;
      }
    }
      printf("\n");
    }
    }
    break;
    case 2:{
      //FILTRO DANI
          printf("\n\nFILTRO DANI APLICADO!\n\n");

      for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {

        R[i][j] = (R[i][j] > 255 - 50) ? 255 : R[i][j] + 10;
        G[i][j] = (G[i][j] > 255 - 50) ? 255 : G[i][j] + 25;
        B[i][j] = (B[i][j] > 255 - 50) ? 255 : B[i][j] - 5;
    }
}

int fundoR[l][c];
int fundoG[l][c];
int fundoB[l][c];

for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        fundoR[i][j] = R[i][j];
        fundoG[i][j] = G[i][j];
        fundoB[i][j] = B[i][j];
    }
}



    }
    break;
    case 3:{
      // PRETO E BRANCO
          printf("\n\nFILTRO PRETO E BRANCO APLICADO!\n\n");

for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {

          int Ri = R[i][j];
          int Gi = G[i][j];
          int Bi = B[i][j];


          int peb = (int)((Ri + Gi + Bi) / 3.0);

          // Atribuir o mesmo valor de tons de cinza a todos os canais de cor
          R[i][j] = peb;
          G[i][j] = peb;
          B[i][j] = peb;
      }
  }
      
    }
    break;
    case 4:{
      //SÉPIA
    printf("\n\nFILTRO SÉPIA APLICADO!\n\n");
  for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
          int Ri = R[i][j];
          int Gi = G[i][j];
          int Bi = B[i][j];

          int newR = (int)((0.393 * Ri) + (0.769 * Gi) + (0.189 * Bi));
          int newG = (int)((0.349 * Ri) + (0.686 * Gi) + (0.168 * Bi));
          int newB = (int)((0.272 * Ri) + (0.534 * Gi) + (0.131 * Bi));

          // Não pode passar de 255
          if (newR > 255)
              newR = 255;
          if (newG > 255)
              newG = 255;
          if (newB > 255)
              newB = 255;

          R[i][j] = newR;
          G[i][j] = newG;
          B[i][j] = newB;
      }
  }
      
    }
    break;
    case 5:{
      // SKYLINE
          printf("\n\nFILTRO SKYLINE APLICADO!\n\n");

    for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        // efeito azulado
        R[i][j] -= 10; 
        G[i][j] -= 10; 
        B[i][j] += 10; 

        // não estourar
        if (R[i][j] < 0) R[i][j] = 0;
        if (G[i][j] < 0) G[i][j] = 0;
        if (B[i][j] > 255) B[i][j] = 255;
    }
}
      
    }
    break;
    case 6:{
      // DOGPATCH
      printf("\n\nFILTRO DOGPATCH APLICADO!\n\n");

      for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        // efeito quente
        R[i][j] += 20;
        G[i][j] += 5; 
        B[i][j] -= 10; 

        // Certificar-se de que os valores estejam dentro do intervalo 0-255
        if (R[i][j] > 255) R[i][j] = 255;
        if (G[i][j] > 255) G[i][j] = 255;
        if (B[i][j] < 0) B[i][j] = 0;
    }
}
      
    }
    break;
     case 7:{
       // FOTO ANTIGA
    printf("\n\nFILTRO ANTIGA APLICADO!\n\n");
       for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        // linhas horizontais
        if (i % 20 <= 5) {
            R[i][j] += 20; 
            G[i][j] += 10; 
            B[i][j] -= 10; 
        }

        // valores entre 0-255 para nao estourar
        if (R[i][j] > 255) R[i][j] = 255;
        if (G[i][j] > 255) G[i][j] = 255;
        if (B[i][j] < 0) B[i][j] = 0;
    }
}
       
     }
    break;
    case 8:{
      //POLAROID
          printf("\n\nFILTRO POLAROID APLICADO!\n\n");
      
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        // Reduzir a intensidade das cores para deixar no efeito velho de polaroid
        R[i][j] -= 30;
        G[i][j] -= 30; 
        B[i][j] -= 20; 

        // não estourar a imagem 
        if (R[i][j] < 0) R[i][j] = 0;
        if (G[i][j] < 0) G[i][j] = 0;
        if (B[i][j] < 0) B[i][j] = 0;
    }
}
// moldura Polaroid
int bordaSuperior = 55; 
int bordaInferior = 155; 
int bordaEsquerda = 55; 
int bordaDireita = 55;  


for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        
        if (i >= bordaSuperior && i < l - bordaInferior && j >= bordaEsquerda && j < c - bordaDireita) {
            continue; 
        }
        // transformar em branco
        R[i][j] = 255; 
        G[i][j] = 255; 
        B[i][j] = 255; 
    }
} 
    }
    break;
    case 9:{
      //BROOKLYN
    printf("\n\nFILTRO BROOKLYN APLICADO!\n\n");
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        // Aumentar o contraste
        if (R[i][j] > 127) {
            R[i][j] = 255;
        } else {
            R[i][j] = 2 * R[i][j];
        }

        if (G[i][j] > 127) {
            G[i][j] = 255;
        } else {
            G[i][j] = 2 * G[i][j];
        }

        if (B[i][j] > 127) {
            B[i][j] = 255;
        } else {
            B[i][j] = 2 * B[i][j];
        }

        // Efeito quente
        R[i][j] += 50;
        G[i][j] += 25;
        B[i][j] -= 25;

        // Não estourar 
        if (R[i][j] > 255) R[i][j] = 255;
        if (G[i][j] > 255) G[i][j] = 255;
        if (B[i][j] < 0) B[i][j] = 0;
    }
}
      
    }
    break;
     case 10:{
       //CLARENTON
           printf("\n\nFILTRO CLARENTON APLICADO!\n\n");
       for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        // Aumentar o contraste
        R[i][j] = (R[i][j] > 127) ? 255 : 2 * R[i][j];
        G[i][j] = (G[i][j] > 127) ? 255 : 2 * G[i][j];
        B[i][j] = (B[i][j] > 127) ? 255 : 2 * B[i][j];
        
        B[i][j] += 50;
        if (B[i][j] > 255) B[i][j] = 255;
    }
}
     }
    break;
     case 11:{
       //COLORIR PARA O VERMELHO
    printf("\n\nFILTRO VERMELHO APLICADO!\n\n");
       for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
          // Obter os valores dos canais de cor
          int Ri = R[i][j];
          int Gi = G[i][j];
          int Bi = B[i][j];


          int Rfiltro = Ri + 50;


          if (Rfiltro > 255)
              Rfiltro = 255;

          // Atribuir os valores ajustados aos canais de cor
          R[i][j] = Rfiltro;
          G[i][j] = Gi;
          B[i][j] = Bi;
      }
  }
     }
    break;
     case 12:{
       //COLORIR PARA O VERDE
    printf("\n\nFILTRO VERDE APLICADO!\n\n");
       for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
          // Obter os valores dos canais de cor
          int Ri = R[i][j];
          int Gi = G[i][j];
          int Bi = B[i][j];


          int Gfiltro = Gi + 50;


          if (Gfiltro > 255)
              Gfiltro = 255;

          // Atribuir os valores ajustados aos canais de cor
          R[i][j] = Ri;
          G[i][j] = Gfiltro;
          B[i][j] = Bi;
      }
  }
     }
    break;
    case 13:{
      //COLORIR PARA O AZUL
          printf("\n\nFILTRO AZUL APLICADO!\n\n");
  for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
          // Obter os valores dos canais de cor
          int Ri = R[i][j];
          int Gi = G[i][j];
          int Bi = B[i][j];


          int Bfiltro = Bi + 150;


          if (Bfiltro > 255)
              Bfiltro = 255;

          // Atribuir os valores ajustados aos canais de cor
          R[i][j] = (Ri -50);
          G[i][j] = Gi;
          B[i][j] = Bfiltro;
      }
  }
      
    }
    break;
     default:
    printf("\nDigite um número válido!!! Filtro cancelado\n");
    
  }




  
// DESFOQUE INTERATIVO
  printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("\n\nDESFOQUE INTERATIVO\n\n");
  printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  int qtdDesfoque;
printf("\n\nQuantas vezes deseja desfocar a imagem? 0 se não quiser desfocar : ");
scanf("%d", &qtdDesfoque);

for (int k = 0; k < qtdDesfoque; k++) { // Repete o número de vezes que o usuário escolher
    for (int i = 1; i < l - 1; i++) {  // Loop pelas linhas da imagem 
        for (int j = 1; j < c - 1; j++) {  // Loop pelas colunas da imagem 
            int contador = 0;
          
            if (R[i][j + 1] != R[i][j] || R[i + 1][j] != R[i][j]) {
                R[i][j] = (R[i + 1][j + 1] + R[i + 1][j] + R[i - 1][j] + R[i - 1][j - 1] + R[i][j + 1] + R[i - 1][j + 1] + R[i + 1][j - 1] + R[i][j - 1]) / 8;
                contador += 8;  // pixels processados (24 no total)
            }

            if (G[i][j + 1] != G[i][j] || G[i + 1][j] != G[i][j]) {
                G[i][j] = (G[i + 1][j + 1] + G[i + 1][j] + G[i - 1][j] + G[i - 1][j - 1] + G[i][j + 1] + G[i - 1][j + 1] + G[i + 1][j - 1] + G[i][j - 1]) / 8;
                contador += 8;  
            }
          
            if (B[i][j + 1] != B[i][j] || B[i + 1][j] != B[i][j]) {
                B[i][j] = (B[i + 1][j + 1] + B[i + 1][j] + B[i - 1][j] + B[i - 1][j - 1] + B[i][j + 1] + B[i - 1][j + 1] + B[i + 1][j - 1] + B[i][j - 1]) / 8;
                contador += 8;
            }
        }
    }
}

int respostaRotacao = 0;
  printf("\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("\n\nEDIÇÃO DE IMAGEM\n\n");
  printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  printf("0- Não deseja rotacionar\n1- 90 graus para esquerda\n2- 180 graus para esquerda\n3- 90 graus para direita\n4- 180 para a direita\n\n");
    printf("Para onde deseja rotacionar a imagem? ");
  scanf("%d", &respostaRotacao);

// SWITCH DE ROTAÇÃO

  switch(respostaRotacao){

    case 0:{
    // NÃO ROTACIONAR
        printf("\n\nIMAGEM SEM ROTAÇÃO! \n\n");
    }
    break;
      
  
    case 1:{
      //90 GRAUS PARA ESQUERDA

        printf("\n\nGIRANDO 90 GRAUS PARA A ESQUERDA... \n\n");

      int R_temp[c][l];
int G_temp[c][l];
int B_temp[c][l];

for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[j][l - 1 - i] = R[i][j];
        G_temp[j][l - 1 - i] = G[i][j];
        B_temp[j][l - 1 - i] = B[i][j];
    }
}

// após a rotação
int temp = l;
l = c;
c = temp;

// devolvendo para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}
      
    }
    break;
    case 2:{
      //180 GRAUS PARA ESQUERDA

        printf("\n\nGIRANDO 180 GRAUS PARA A ESQUERDA... \n\n");

int R_temp[c][l];
int G_temp[c][l];
int B_temp[c][l];
  
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[j][l - 1 - i] = R[i][j];
        G_temp[j][l - 1 - i] = G[i][j];
        B_temp[j][l - 1 - i] = B[i][j];
    }
}

// após a rotação
int temp = l;
l = c;
c = temp;

// devolvendo para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}

  
// girando 90 graus
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[j][l - 1 - i] = R[i][j];
        G_temp[j][l - 1 - i] = G[i][j];
        B_temp[j][l - 1 - i] = B[i][j];
    }
}



// devolvendo para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}
  
      
    }
    break;
    case 3:{
      //90 GRAUS PARA DIREITA

      printf("\n\nGIRANDO 90 GRAUS PARA A DIREITA... \n\n");

int R_temp[c][l];
int G_temp[c][l];
int B_temp[c][l];

// Copie os valores da imagem original na matriz temporária, girando 90 graus para a esquerda
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[c - 1 - j][i] = R[i][j];
        G_temp[c - 1 - j][i] = G[i][j];
        B_temp[c - 1 - j][i] = B[i][j];
    }
}

// Atualize as dimensões da imagem após a rotação
int temp = l;
l = c;
c = temp;

// Copie os valores da matriz temporária de volta para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}

      
    }
    break;
    case 4:{
      //180 GRAUS PARA DIREITA

  printf("\n\nGIRANDO 180 GRAUS PARA A DIREITA... \n\n");
      
int R_temp[c][l];
int G_temp[c][l];
int B_temp[c][l];

// girando 90 graus para a esquerda
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[c - 1 - j][i] = R[i][j];
        G_temp[c - 1 - j][i] = G[i][j];
        B_temp[c - 1 - j][i] = B[i][j];
    }
}

// após a rotação
int temp = l;
l = c;
c = temp;

// devolver para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}
 

// girando 90 graus para a esquerda
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R_temp[c - 1 - j][i] = R[i][j];
        G_temp[c - 1 - j][i] = G[i][j];
        B_temp[c - 1 - j][i] = B[i][j];
    }
}

// devolvendo para as matrizes originais
for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
        R[i][j] = R_temp[i][j];
        G[i][j] = G_temp[i][j];
        B[i][j] = B_temp[i][j];
    }
}

      
    }
    break;
    
    default:{
      printf("\n\nDigite um número válido!! Rotação cancelada\n\n");
    }
  }
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
  // ESPELHAR A IMAGEM
int respostaEspelhar = 0;
  printf("\n\nDeseja espelhar a imagem? (0 para não e 1 para sim):  ");
  scanf("%d", &respostaEspelhar);

  switch(respostaEspelhar){
    case 0:
      printf("\nA IMAGEM NÃO FOI ESPELHADA!!\n\n");
    break;
    case 1:{
       printf("\nA IMAGEM FOI ESPELHADA!!\n\n");
for (int i = 0; i < l; i++) {
      for (int j = 0; j < c/2; j++) {
    // vetores temporarios
          int tempR = R[i][j];
          int tempG = G[i][j];
          int tempB = B[i][j];

          R[i][j] = R[i][c - j - 1];
          G[i][j] = G[i][c - j - 1];
          B[i][j] = B[i][c - j - 1];
          R[i][c - j - 1] = tempR;
          G[i][c - j - 1] = tempG;
          B[i][c - j - 1] = tempB;
      }
     }
      
    }      
    break;
    default:
    printf("\n\nDigite um número válido!! A imagem não foi espelhada!");
  }

  
  
  salvaImagem(t,R,G,B,"saida.bmp");
  mostrarNoReplit("saida.bmp");
  return 0;
}
