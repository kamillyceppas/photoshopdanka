/**** Funções auxiliares para trabalhar com libbmp *******/

#define MYERR(...) do { \
    printf ("ERROR @ %s %s (%d): ", __FILE__,__func__,__LINE__); \
    printf (__VA_ARGS__); \
} while (0)

unsigned char limit(x){
  if(x>255) 
    return 255;
  else if (x < 0) 
    return 0;
  else 
    return x;
  }


struct IMG_TAM{
  int qtdLinhas;
  int qtdColunas;
};
typedef struct IMG_TAM IMG_TAM;


IMG_TAM pegarTamanho(const char *filename){

  FILE *f = fopen(filename,"rb");
  if (f==NULL){
    printf("arquivo %s não existe!\n",filename);
    exit(1);
  }
  fclose(f);


  IMG_TAM t;
  bmp_img img;
  bmp_img_read(&img,filename);
  t.qtdColunas = img.img_header.biWidth;
  t.qtdLinhas = img.img_header.biHeight;
  bmp_img_free(&img);
  return t;
}

void carregaImagem(
  IMG_TAM t,
  int R[t.qtdLinhas][t.qtdColunas],
  int G[t.qtdLinhas][t.qtdColunas],
  int B[t.qtdLinhas][t.qtdColunas],
  const char *filename){
  bmp_img img;
  bmp_img_read(&img,filename);

  int width = t.qtdColunas;
  int height = t.qtdLinhas;

  for (size_t y = 0, x; y < width; y++){
    for (x = 0; x < height; x++){
      R[x][y] = img.img_pixels[x][y].red;
      G[x][y] = img.img_pixels[x][y].green;
      B[x][y] = img.img_pixels[x][y].blue;
    }
  }
  printf("- - Imagem %s carregada com %dx%d px - -\n",filename,width,height);

}

void salvaImagem(IMG_TAM t,
  int R[t.qtdLinhas][t.qtdColunas],
  int G[t.qtdLinhas][t.qtdColunas],
  int B[t.qtdLinhas][t.qtdColunas],
  const char *filename){
  bmp_img img;
  int width = t.qtdColunas;
  int height = t.qtdLinhas;
  bmp_img_init_df(&img, width, height);



  for (size_t y = 0, x; y < width; y++){
    for (x = 0; x < height; x++){
      bmp_pixel_init(&img.img_pixels[x][y], limit(R[x][y]), limit(G[x][y]), limit(B[x][y]));
    }
  }
  bmp_img_write(&img, filename);
  bmp_img_free(&img);
  printf("- - Imagem salva no caminho %s - -\n",filename);

}

void zerarPixels(IMG_TAM t,
  unsigned char PIX[t.qtdLinhas][t.qtdColunas]){
    for (size_t y = 0, x; y < t.qtdColunas; y++){
      for (x = 0; x < t.qtdLinhas; x++){
        PIX[x][y] = 0;
      }
  }
}

void mostrarNoReplit(const char *filename){
  int buffsize=256;
  char buf[buffsize];
  char fehString[] = "feh --full-screen --auto-zoom %s > /dev/null 2>&1";
  if(sizeof(filename)+sizeof(fehString)> buffsize){
    MYERR("Nome de arquivo muito grande!\n");
    return;
  }
  printf("Exibindo imagem: %s",filename);
  fflush(stdout);
  snprintf(buf, sizeof buf, fehString, filename);
  system(buf);
}
