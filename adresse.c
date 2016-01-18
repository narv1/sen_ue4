/*******************************************************************************************/
/*                           Willkommen zum dritten Projekt!                               */
/*               Dieses Programm zielt darauf ab einen besseren Umgang mit:                */
/*                                     -Arrays                                             */
/*                   -Verbesserung der Eingabe einer Stringzerlegung                       */
/*******************************************************************************************/


/*******************************************************************************************/
/*                               Author: Stefan Hermeter                                   */
/*                                  Klasse:5/6 ABETI                                       */
/*                                 Datum:  15.01.2016                                      */
/*******************************************************************************************/


/*****************************************/
/*      Die verwendeten Libaries         */
/* bzw. die maximale Anzahl der Vektoren */
/*****************************************/ 
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "myString.h"
#define N 50

int main(int argc, char *argv[])
{

  int opt;
  int i, j;
  char vorn1[N], vorn2[N], nachn[N], stra[N], plz[N], ort[N], land[N], gesamt[100];
  
  while ((opt = getopt(argc, argv, "eg")) != -1) {
    switch (opt) {
    case 'h':
      printf("Dieses Programm hilft Adressen eines Kundestockes X zuverwalten, die Eingabe ist wieder mit getopt gestaltet\n\nBeschreibung:\n\t-e\t\"...\"\tEingabe der Adresse erfolgt nacheinander. Reihenfolge: Vorname1, Vorname2, Nachname, Strasze, Postleitzahl, Ort, Land.\n\t-g\t\"...\"\tEingabe der Adresse erfolgt in einem Satz es ist zu beachten:\n\t\t\t1) Das die Wörter entweder mit einem \"Space\" oder mit einem \",\" zu trennen sind\n.\t\t\t.2) Das \"unbedingt\" die Reihenfolge einzuhalten ist.\n\n\t-h\t\"...\"\tBei Programm aufruf mit \"-h\" wird die Hilfe des Programms ausgegeben\n");
      break;
    case '?':
      if (optopt == 'c')
	fprintf (stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint (optopt))
	fprintf (stderr, "Unknown option `-%c'.\n", optopt);
      else
	fprintf (stderr,"Unknown option character `\\x%x'.\n", optopt);
      break;
    case 'e':
      printf("Bitte geben sie den Vornamen ein:\n(Falls vorhanden mit Leerezeichen oder \",\" den 2.Vornamen dahinter):\n");
      fgets(vorn1, N, stdin);
      printf("Bitte geben sie ihren Nachnamen ein:\n");
      fgets(nachn, N, stdin);
      printf("Bitte geben sie ihre Strasze ein:\n(Beispiel: Musterstrasze 1)\n");
      fgets(stra, N, stdin);
      printf("Bitte geben sie ihre Postleitzahl ein:\n");
      fgets(plz, N, stdin);
      printf("Bitte geben sie ihren Wohnort ein:\n");
      fgets(ort, N, stdin);
      printf("Bitte geben sie ihr Land ein:\n");
      fgets(land, N, stdin);

      int i, j, l = 0,  k = 0;
      i = strlength(vorn1, N);
      for(j = 0; j < i; j++){
	if(vorn1[j] == 32 || vorn1[j] == 44){ //ascii , = 44  space = 32    dezimalstellen
	  j++;
	  for( ; j < i; j++){
	    vorn2[k] = vorn1[j];
	    k++;
	    if(j == i){
	      j++;
	      vorn2[k] = vorn1[j];
	      break;
	    }
	  }
	  l++;
	  j = j - k ;
	  vorn1[j] = '\0';
	  vorn2[k] = '\0';
	  printf("\n%d\n",k);
	  j = strlength(vorn1, N);
	  k = strlength(vorn2, N);
	  k++;
	  printf("\nVorname1:\t%d\t%s\n", j, vorn1);
	  printf("\nVorname2:\t%d\t%s\n", k, vorn2);
	  if(j < k){
	    i = strsearch(vorn1, N, vorn2);
	    k = k - (k - j);
	    printf("\n!!%d\n",i);
	  }else{
	    i = strsearch(vorn2, N, vorn1);
	    k = j - (j - k);
	    printf("\n??%d\n",i);
	  }
	  if(i == -1){
	    printf("\nVor- und Nachname sind sich nicht aehnlich!\n");
	    break;
	  }
	  if(i == 0){
	    printf("Die Vornamen sind ab den ersten Buchstaben bis zum %d!\n identisch!", k);
	  }
	  if(i >= 2){
	    printf("Die Vornamen sind ab den %d Buchstaben bis zum %d!\n identisch!", i+1,k+i);
	  }
	  else{
	    printf("Die Vornamen sind ab den zweiten Buchstaben bis zum %d identisch!\n", k);
	  }
	}
       
      }
      if(l == 0){
	i = strlength(vorn1, N);
	printf("\nVorname:\t%d\t%s\n", i,  vorn1);
	
	k = strlength(nachn, N);
	printf("\nNachname:\t%d\t%s\n", k,  nachn);
	if(i > k){
	  j = strsearch(vorn1, N, nachn);
	  printf("\n!!!!%d\n", j);
	}else{
	  j = strsearch(nachn, N, vorn1);
	  printf("\n????%d\n", j);
	}
	if(i == -1){
	  printf("\nVor- und Nachname sind sich nicht aehnlich!\n");
	}
	if(i == 0){
	  printf("Der Vor- und der Nachname sind ab den ersten Buchstaben bis zum %d identisch!", k);
	}
	if(i >= 2){
	  printf("Die Vor- und Nachname sind ab den %d Buchstaben bis zum %d!\n identisch!", i+1, k-j-1);
	}else{
	  printf("Die Vor- und Nachname sind ab den zweiten Buchstaben bis zum %d identisch!\n", k);
	}
      }
      
      
      i = strlength(stra, N);
      stra[i] = '\0';
      printf("\nStraße:\t\t%d\t%s\n", i, stra);
 
      i = strlength(plz, N);
      plz[i] = '\0';
      printf("\nPLZ:\t\t%d\t%s\n", i, plz);
      
      i = strlength(ort, N);
      ort[i] = '\0';
      printf("\nOrt:\t\t%d\t%s\n", i, ort);
      
      i = strlength(land, N);
      land[i] = '\0';
      printf("\nLand:\t\t%d\t%s\n", i, land);

      /*      i = strlength(vorn1, N);
      k = strlength(vorn2, N);
      printf("\nVorname:%s\t%d\n", vorn1, i);
      printf("Vorname2:%s\t%d\n", vorn2, k);
      */      break;
      /******************************/
      /* Aufruf des Programms mit   */
      /* "-g" speicherung in einen  */
      /*           String           */
      /******************************/
    case 'g':
      printf("Bitte geben sie die gesamte Adresse ein:\n/Formatierung: Vorname1,Vorname2,Nachname,Strasze,Postleitzahl,");
      fgets(gesamt, 100, stdin);
      break;
    }
  }
  return 0;
}
