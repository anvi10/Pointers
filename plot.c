
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

double getMinY(double * array) {
  int i = 1;
  double temp = array[0];
  for (i = 1; i < MAXCOLS; i++) {
      if (array[i] < temp ) {
          temp = array[i];
      }
  }
  return temp;
}

double getMaxY(double * array) {
  int i = 1;
  double temp = array[0];
  for (i = 1; i < MAXCOLS; i++) {
      if (array[i] > temp ) {
          temp = array[i];
      }
  }
  return temp;
}

void createPlot( char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS];
  double xx[MAXCOLS];
  clearPlot();
	
	int i;
  // Evaluate function and store in vector yy
  for (i = 0; i < MAXCOLS; ++i) {
    double x = minX + (maxX-minX)*i/MAXCOLS;
    double y = rpn_eval(funcFile,x);

    xx[i] = x;
    yy[i] = y;
  }

  //Compute maximum and minimum y in vector yy
  
  double minY = getMinY(yy);
  double maxY = getMaxY(yy);
  //Plot x axis
  for (i = 0; i < MAXCOLS; ++i) {
   if (minY < 0 && maxY > 0) {
    plotXY( i, (MAXROWS/2)-1, '_');
   } else {
    plotXY(i , MAXROWS-1, '_');
   }
  }
  //Plot y axis
  for (i = 0; i < MAXCOLS; ++i) {
    plotXY(MAXCOLS/2, i, '|');
  }
  // Plot function. Use scaling.
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1
	for (i = 0; i < MAXCOLS; ++i) {
    int x = i;
    int y = (int) ((yy[i]-minY) * MAXROWS /(maxY-minY));
    plotXY(x,MAXROWS - y - 1, '*');
  }
  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  
  createPlot(argv[1], atof(argv[2]), atof(argv[3]));
}
