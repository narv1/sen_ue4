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
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "myString.h"
#define N 50



int main(int argc, char *argv[])
{
  int stderr = 0;
  int opt;
  char vorn1[N], test[N], vorn2[N], nachn[N], stra[N], plz[N], ort[N], land[N], gesamt[100];
  extern char *optarg;
  extern int optind, optopt;
  
  while ((opt = getopt(argc, argv, "egh")) != -1) {
    switch (opt) {
    case 'h':
      printf("Dieses Programm hilft Adressen eines Kundestockes X zuverwalten, die Eingabe ist wieder mit getopt gestaltet\n\nBeschreibung:\n\t-e\t\"...\"\tEingabe der Adresse erfolgt nacheinander. Reihenfolge: Vorname1, Vorname2, Nachname, Strasze, Postleitzahl, Ort, Land.\n\t-g\t\"...\"\tEingabe der Adresse erfolgt in einem Satz es ist zu beachten:\n\t\t\t1) Das die Wörter entweder mit einem \"Space\" oder mit einem \",\" zu trennen sind\n.\t\t\t.2) Das \"unbedingt\" die Reihenfolge einzuhalten ist.\n\n\t-h\t\"...\"\tBei Programm aufruf mit \"-h\" wird die Hilfe des Programms ausgegeben.\n");
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

      int i, j, k = 0,  l = 0, m = 0;
      
      // Zur überprüfung der kommenden if-abfrage auf mehrere Vornamen
      k = strlength(vorn1, N);
      char lookup[] = " ,";
      l = strcspn(vorn1,lookup);
	
      for(i = 0; i < k; i++){
	if(l  == i){
	  vorn1[i] = '\0';
	  i++;
	  m = 0;
	  for( ; i < k; i++){
	    vorn2[j] = vorn1[i];
	    j++;
	    if(k - 1 == i){
	      vorn2[j - 1] = '\0'; // -1
	      m = 1;
	    }
	  }
	}
      }
      if(m == 0){
	i = strlength(vorn1, N);
	vorn1[i - 1] = '\0';
      }
      //Abfrage + Ausgabe + Verlgiech (1Vor- und 2Vornamen)
      if (m == 1){
	i = strlength(vorn1, N);
	k = strlength(vorn2, N);
	if(k <= i){
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nVorname2:\t%d\t%s\n", k, vorn2);
	  j = strsearch(vorn2, N, vorn1);
	}
	if(k > i){
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nVorname2:\t%d\t%s\n", k, vorn2);
	  j = strsearch(vorn1, N, vorn2);
	}
	if(j == -1){
	  printf("Die Woerter sind sich nicht aehnlich.\n");
	  m = 0;
	}else{
	  printf("Die Woerter sind sich aehnlich.\n");
	  m = 0;
	}
      }
      //Abfrage + Ausgabe + Verlgiech (Vor- und Nachnamen)
      if(m == 0){
	i = 0;
	i = strlength(vorn1, N);
	vorn1[i] = '\0';
	k = strlength(nachn, N);
	nachn[k - 1] = '\0';
	j = 0;
	if(k <= i){
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nNachname:\t%d\t%s\n", k - 1, nachn);
	  j = strsearch(nachn, N, vorn1);
	}
	if(k > i){
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nNachname:\t%d\t%s\n", k - 1, nachn);
	  j = strsearch(vorn1, N, nachn);
	}
	if(j == -1){
	  printf("Die Wörter sind sich nicht aehnlich.\n");
	}else{
	  printf("Die Wörter sind sich aehnlich.\n");
	}
      }
      //Ausgabe
      i = strlength(stra, N);
      stra[i - 1] = '\0';
      printf("\nStraße:\t\t%d\t%s", i - 1, stra);
      
      i = strlength(plz, N);
      plz[i - 1] = '\0';
      printf("\nPLZ:\t\t%d\t%s", i - 1, plz);
      
      i = strlength(ort, N);
      ort[i - 1] = '\0';
      printf("\nOrt:\t\t%d\t%s", i - 1, ort);
      
      i = strlength(land, N);
      land[i - 1] = '\0';
      printf("\nLand:\t\t%d\t%s\n", i - 1, land);
      return 0;
      
  /******************************/
  /* Aufruf des Programms mit   */
  /* "-g" speicherung in einen  */
  /*           String           */
  /******************************/
    case 'g':
      stderr++;
      printf("Bitte geben sie die gesamte Adresse ein:\n/Formatierung: Vorname1,Vorname2,Nachname,Strasze,Postleitzahl,Ort,Land\n");
      fgets(gesamt, 100, stdin);
    
      if(stderr == 0){
	printf("This program, requires an argument.\nPlease type %s -h for more information.\n",argv[0]);
	break;
      }
    }
    return 0;
  }
  if(stderr == 0){
    printf("This program, requires an argument.\nPlease type %s -h for more information.\n",argv[0]);
  }
  return 0;
}
