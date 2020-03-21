#include <iostream>
#include <map>

using namespace std;

int resultat (int a, int b, int c){
  if (a <= b and a <= c){
    if (c < b) return c * 10 + b;
    return b * 10 + c;
  }
  if (b <= a and b <= c){
    if (a < c) return a * 10 + c;
    return c * 10 + a;
  }
  else {
    if (a < b) return a * 10 + b;
    return b * 10 + a;
  }
}

void escriure (const map <int, int>& contador){
  map <int, int>::const_iterator it = contador.begin ();
  for ( ; it != contador.end(); it ++){
    cout << "  " << it -> first << " :  " << it -> second << endl;
  }
}

int max (int a, int b){
  if (a < b) return b;
  return a;
}

int min (int a, int b){
  if (a < b) return a;
  return b;
}

int main(){
  int a, b, c;
  a = b = c = 1;
  double num;
  int cont = 0;

  map <int, int> contador;

  bool seguim = true;

  while (seguim){
    num = resultat (a, b, c);

    contador[num] ++;

    c++;
    cont ++;
    if (c > 6){
      c -= 6;
      b++;
      if (b > 6){
        b -= 6;
        a++;
        if (a > 6) seguim = false;
      }
    }
  }
  cout << endl;

  escriure (contador);
  cout << endl << "  total :  " << cont << endl << endl;

  double def, emp, atc;
  double dtot, etot, atot;
  dtot = etot = atot = 0;
  double defp, empp, atcp;
  double dptot, eptot, aptot;
  dptot = eptot = aptot = 0;
  int a1, a2;
  a1 = a2 = 1;

  int d1, d2;

  while (a1 <= 6){
    d1 = d2 = 1;
    def = emp = atc = 0;
    defp = empp = atcp = 0;

    while (d1 <= 6) {

      if ((max (a1, a2) <= max (d1, d2)) and (min (a1, a2) <= min (d1, d2))){
        def ++;
        defp += 6;
      }
      else if ((max (a1, a2) > max (d1, d2)) and (min (a1, a2) > min (d1, d2))){
        atc ++;
        atcp += 6;
      }
      else {
        emp ++;
        empp += 6;
      }

      d2 ++;
      if (d2 > 6){
        d2 -= 6;
        d1 ++;
      }
    }

    dtot += def;
    etot += emp;
    atot += atc;

    cout << "Daus atac :  " << a1 << ' ' << a2 << endl;
    cout << "Defensa :  " << def << "  ( " << defp << " )" << endl;
    cout << "Empat :  " << emp << "  ( " << empp << " )" << endl;
    cout << "Atac :  " << atc << "  ( " << atcp << " )" << endl << endl;

    num = min (a1, a2) * 10 + max (a1, a2);
    num = contador[num];

    dptot += (num) * (defp);
    eptot += (num) * (empp);
    aptot += (num) * (atcp);

    a2 ++;
    if (a2 > 6){
      a1 ++;
      a2 = a1;
    }
  }
  cout << "Victoria Defensa :  " << dtot << endl;
  cout << "Empats :  " << etot << endl;
  cout << "Victoria Atac :  " << atot << endl << endl;

  double tot = dptot + eptot + aptot;

  cout << "Percentatges" << endl;
  cout << "Defensa :  " << dptot / tot * 100 << endl;
  cout << "Empate :  " << eptot / tot * 100 << endl;
  cout << "Atac :  " << aptot / tot * 100 << endl;
}
