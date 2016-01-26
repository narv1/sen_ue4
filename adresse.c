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


/*****************************************/
/*         Das Hauptprogramm             */
/*****************************************/
int main(int argc, char *argv[])
{
  int stderr = 0;
  int opt;
  char vorn1[N], vorn2[N], nachn[N], stra[N], plz[N], ort[N], land[N], gesamt[100];
  extern char *optarg;
  extern int optind, optopt;
  
  while ((opt = getopt(argc, argv, "egh")) != -1) {
    switch (opt) {

      // Aufruf der Hilfe mit '-h'
    case 'h':
      printf("Dieses Programm hilft Adressen eines Kundestockes X zuverwalten, die Eingabe ist wieder mit getopt gestaltet\n\nBeschreibung:\n\nAchtung in diesen Programm dürfen keine Umlaute (ä,Ä,ö,Ö,ü,Ü) oder ein ß verwendet werden. \n\t-e\t\tEingabe der Adresse erfolgt nacheinander.\n\t\t\tReihenfolge: Vorname1, Vorname2, Nachname, Strasze, Postleitzahl, Ort, Land.\n\t-g\t\tEingabe der Adresse erfolgt in einem Satz es ist zu beachten:\n\t\t\t1) Das die Wörter entweder mit einem \",\" zu trennen sind.\n\t\t\t2) Das \"unbedingt\" die Reihenfolge einzuhalten ist.\n\n\t-h\t\tBei Programm aufruf mit \"-h\" wird die Hilfe des Programms ausgegeben.\n");
      return 0;

      // Wenn ein Falsches Argument aufgerufen wurde
    case'?':
      if (isprint (optopt)){
	printf ("Unknown option `-%c'.\nPlease Type %s, -h for more information.\n", optopt, argv[0]);
      }
      stderr++;
      break;
      
      // Aufruf des Programm mit dem Argument '-e'
    case 'e':

      // Ausgabe zur Aufforderung der jeweiligen Eingabe + Eingabe des jeweiligen Elements
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
      k = strlength(vorn1, N);      // Überpfüfung der Länge des Vornamens
      char lookup[] = " ,";         // vergleichs String der Eingabe
      l = strcspn(vorn1,lookup);    // Vergleich des Vornamens mit lookup string 
                                    // zählt den string bis zum element von lookup
      // Zerlegung der beiden Vornamen in jeweils einen seperaten
      for(i = 0; i < k; i++){
	if(l == i){
	  vorn1[i] = '\0';          // Falls lookup erfolgreich, beendigung des 1 Strings mit dem Nullbyte
	  i++;
	  m = 0;                    // Markierung für spätere Ausagabe
	  for( ; i < k; i++){
	    vorn2[j] = vorn1[i];    // Sortierung des zweiten Vornamen in den zweiten String
	    j++;
	    if(k - 1 == i){         // Abfrage zur abschließung des zweiten Strings mit dem Nullbyte
	      vorn2[j - 1] = '\0'; 
	      m = 1;
	    }
	  }
	}
      }
      if(m == 0){
	i = strlength(vorn1, N);                                 // 1 Markierung
	vorn1[i - 1] = '\0';                                     // richtiges abschließen des Nullbytes auf Vornamen
      }
      //Abfrage + Ausgabe + Verlgiech (1Vor- und 2Vornamen)
      if (m == 1){                                               // Abfragen der Markierung
	i = strlength(vorn1, N);
	k = strlength(vorn2, N);
	if(k <= i){                                              // Sicherstellung auf Formatierung für strsearch
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nVorname2:\t%d\t%s\n", k, vorn2);
	  j = strsearch(vorn2, N, vorn1);                        // überprüfung auf Ähnlichkeiten
	}
	if(k > i){                                               // Gegepart
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nVorname2:\t%d\t%s\n", k, vorn2);
	  j = strsearch(vorn1, N, vorn2);                        // überprüfung auf Ähnlichkeiten
	}
	if(j == -1){                                             // Ausgabe auf Ähnlichkeit
	  printf("Die Woerter sind sich nicht aehnlich.\n");
	  m = 0;
	}else{
	  printf("Die Woerter sind sich aehnlich.\n");
	  m = 0;
	}
      }
      //Abfrage + Ausgabe + Verlgiech (Vor- und Nachnamen)
      if(m == 0){                                                // 2 Markierung
	i = 0;
	i = strlength(vorn1, N);
	vorn1[i] = '\0';                                         // richtiges abschließen des Nullbytes auf Vornamen
	k = strlength(nachn, N);
	nachn[k - 1] = '\0';                                     // richtiges abschließen des Nullbytes auf Nachnamen
	j = 0;
	if(k <= i){                                              // Sicherstellung auf Formatierung für strsearch
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nNachname:\t%d\t%s\n", k - 1, nachn);
	  j = strsearch(nachn, N, vorn1);                        // überprüfung auf Ähnlichkeiten
	}
	if(k > i){                                               // Gegenpart
	  printf("\nVorname1:\t%d\t%s", i, vorn1);
	  printf("\nNachname:\t%d\t%s\n", k - 1, nachn);
	  j = strsearch(vorn1, N, nachn);                        // überprüfung auf Ähnlichkeiten
	}
	if(j == -1){                                             // Ausgabe auf Ähnlichkeit
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
      // Aufruf der Ausgabe + Aufforderung zu Eingabe
      printf("Bitte geben sie die gesamte Adresse ein:\n/Formatierung: Vorname1,Vorname2,Nachname,Strasze,Postleitzahl,Ort,Land\n");
      fgets(gesamt, 100, stdin);

      int i2, j2, k2 = 0, l2, m2 = 0, n2, o2, marker = 0, m3 = 0;
      char beistr[1] = ",";
      char zahlen[10] = "0123456789";
      j2 = strlength(gesamt, 100);             // Zähler für for-schleifen
      
      for(i2 = 0; i2 < j2; i2++){
	if(gesamt[i2] == beistr[0]){           // Zähler der Beistriche. Vorgabe der Formatierung
	  marker++;
	}
	if(marker == 3){                       // Markierung. Überprüfung auf Eingabe mit 2.Vornamen
	  for(l2 = 0; l2 <= 10; l2++){
	    if(gesamt[i2] == zahlen[l2]){
	      m2++;
	    }
	  }
	}
	if(marker == 4){                       // Markierung. Überprüfung auf Eingabe mit 2.Vornamen
	  for(l2 = 0; l2 <= 10; l2++){
	    if(gesamt[i2] == zahlen[l2]){
	      m3++;
	    }
	  }
	}
      }
      
      if((marker == 5 || marker == 6) && (m2 == 4 || m3 == 4)){     // Erster Kontrolle auf Richtigkeit der Eingabe

	// Umsortierung auf einzelne Strings
	for(i2 = 0; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	  vorn1[i2] = gesamt[i2];
	  vorn1[i2 + 1] = '\0';
	}
	// Umsortierung auf einzelne Strings + Zweite Kontrolle auf Eingabe auf 2.Vornamen
	if(marker == 6 && m3 ==4){
	  i2++;
	  for( ; i2 < j2; i2++){
	    if(gesamt[i2] == beistr[0])break;
	    if(gesamt[i2] != beistr[0]){
	      vorn2[k2] = gesamt[i2];
	      vorn2[k2 + 1] = '\0';
	      k2++;
	    }
	  }
	}	  
	// Umsortierung auf einzelne Strings
	k2 = 0;
	i2++;
	for( ; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	  if(gesamt[i2] != beistr[0]){
	  nachn[k2] = gesamt[i2];
	  nachn[k2 + 1] = '\0';
	  k2++;
	  }
	}
	// Umsortierung auf einzelne Strings
	i2++;
	k2 = 0;
	for( ; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	  if(gesamt[i2] != beistr[0]){
	    stra[k2] = gesamt[i2];
	    stra[k2 + 1] = '\0';
	    k2++;
	  }
	}
	// Umsortierung auf einzelne Strings
	i2++;
	k2 = 0;
	for( ; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	 if(gesamt[i2] != beistr[0]){
	    plz[k2] = gesamt[i2];
	    plz[k2 + 1] = '\0';
	    k2++;
	 }
	}
	// Umsortierung auf einzelne Strings
	i2++;
	k2 = 0;
	for( ; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	 if(gesamt[i2] != beistr[0]){
	    ort[k2] = gesamt[i2];
	    ort[k2 + 1] = '\0';
	    k2++;
	  }
	}
	// Umsortierung auf einzelne Strings
	i2++;
	k2 = 0;
	for( ; i2 < j2; i2++){
	  if(gesamt[i2] == beistr[0])break;
	  if(gesamt[i2] != '\n'){
	    land[k2] = gesamt[i2];	   
	    land[k2 + 1] = '\0';
	    k2++;
	  }
	  // Bei erreichen des Nullbytes verlassen der Schleife
	  if(gesamt[i2] == '\0')break;
	}
      }else{
	// Bei Falsch Eingabe. Ausgabe
	printf("Die Postleitzahl ist auf das österreichische System gestellt 4 Zahlen oder sie haben sich nicht an die Formatierung der Eingabe gehalten.\nStarten sie das Programm neu und versuchen sie es erneut!\n");
	return 1;
      }
      //Ermittlung der Längen der einzelnen Wörter
      i2 = strlength(vorn1, N);
      j2 = strlength(nachn, N);
      k2 = strlength(stra, N);
      l2 = strlength(plz, N);
      m2 = strlength(ort, N);
      n2 = strlength(land, N);
      // Ermittlung der Länge des 2 Vornamen
      if(marker == 6){
	o2 = strlength(vorn2, N);
      }
      // Ausgabe der Einzelstrings
      if(marker == 5){
	printf("\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n",i2 , vorn1, j2, nachn, k2, stra, l2, plz, m2, ort, n2, land);
      }else{
	printf("\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n%d\t%s\n", i2, vorn1, o2, vorn2, j2,  nachn, k2, stra, l2, plz, m2, ort, n2, land);
      }
    }
    return 0;
  }
  // Ausgabe des Programms ohne Argument
  if(stderr == 0){
    printf("This program, requires an argument.\nPlease type %s -h for more information.\n",argv[0]);
  }
  return 0;
}
