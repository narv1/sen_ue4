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
  int stderr = 0;
  int opt;
  int i, j;
  char vorn1[N], vorn2[N], nachn[N], stra[N], plz[N], ort[N], land[N], gesamt[100];
  extern char *optarg;
  extern int optind, optopt;
  
  while ((opt = getopt(argc, argv, "egh")) != -1) {
    switch (opt) {
    case 'h':
      printf("Dieses Programm hilft Adressen eines Kundestockes X zuverwalten, die Eingabe ist wieder mit getopt gestaltet\n\nBeschreibung:\n\t-e\t\"...\"\tEingabe der Adresse erfolgt nacheinander. Reihenfolge: Vorname1, Vorname2, Nachname, Strasze, Postleitzahl, Ort, Land.\n\t-g\t\"...\"\tEingabe der Adresse erfolgt in einem Satz es ist zu beachten:\n\t\t\t1) Das die Wörter entweder mit einem \"Space\" oder mit einem \",\" zu trennen sind\n.\t\t\t.2) Das \"unbedingt\" die Reihenfolge einzuhalten ist.\n\n\t-h\t\"...\"\tBei Programm aufruf mit \"-h\" wird die Hilfe des Programms ausgegeben.\n");
      stderr++;
      break;
    case ':':
      if (optopt == 'c'){
	printf ("Option -%c requires an argument.\n", optopt);
      }
      stderr++;
      break;
    case'?':
      if (isprint (optopt)){
	printf ("Unknown option `-%c'.\nPlease Type %s, -h for more information.\n", optopt, argv[0]);
      }
      stderr++;
      break;
    case 'e':
      stderr++;
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
      k = strlength(vorn1, N);
      for(i = 0; i < k; i++){
	if (vorn1[i] == 32 || vorn1[i] == 44){
	  vorn1[i] = '\0';
	  i++;
	  for( ; i < k; i++){
	    vorn2[j] = vorn1[i];
	    j++;
	    if(k == i+1){
	      vorn2[j-1] = '\0';
	      l++;
	      break;
	    }
	  }
	}
      }
	
      i = strlength(vorn2, N);
      k = strlength(vorn1, N);
      printf("\nVorname1: %s  länge: %d", vorn1, k);
      printf("\nVorname2: %s  länge; %d\n", vorn2, i);

      if(k > i){
	j = strsearch(vorn2, N, vorn1);
      }else{
	j = strsearch(vorn1, N, vorn2);
      }
      
      printf("\n%d",j);	  
      
      if(l == 0){
	printf("\nhallo\n");
	break;
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
      break;
      
  /******************************/
  /* Aufruf des Programms mit   */
  /* "-g" speicherung in einen  */
  /*           String           */
  /******************************/
    case 'g':
      printf("Bitte geben sie die gesamte Adresse ein:\n/Formatierung: Vorname1,Vorname2,Nachname,Strasze,Postleitzahl,");
      fgets(gesamt, 100, stdin);
    
      if(stderr == 0){
	printf("This program, requires an argument.\nPls type %s -h for more information.\n",argv[0]);
	break;
      }
    }
    return 0;
  }
  return 0;
}
