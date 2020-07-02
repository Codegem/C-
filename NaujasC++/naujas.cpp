#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;
/* struktura aprasome */
struct preke{
                string pavadinimas;
                float kaina;
                int kiekis;
                float suma;
            };
/* skaitymo void */

void skaito(preke sar[], int &kiek);
void raso(preke sar[], int kiek, float preksuma);
void psuma (preke sar[], int kiek);
void krepsuma (preke sar[], int kiek, float &preksuma);
void rikiavimas (preke sar[], int kiek);
void brangus (preke sar[], int kiek, preke sarBr[], int kiekBr);

/* skaito raso */

ifstream in("duom.txt");
ofstream out("rez.txt");

int main()
{
    preke krepselis[100], krepselisbrangus[100];
    int n;
    skaito(krepselis, n);
    psuma(krepselis, n);

    float preksuma;
    krepsuma(krepselis, n, preksuma);
    raso(krepselis, n, preksuma);
    rikiavimas(krepselis, n);
    out << "\n surikiuotas \n";
    raso(krepselis, n, preksuma);
    int nB = 3;
    brangus(krepselis, n, krepselisbrangus, nB);
    out << "\n brangus \n";
    raso(krepselisbrangus, nB, preksuma);

    in.close();
    out.close();
    return 0;
}
// skaitymas
void skaito(preke sar[], int &kiek){
    kiek = 0;
    while(!in.eof()){
        in>>sar[kiek].pavadinimas>>sar[kiek].kaina>>sar[kiek].kiekis;
        kiek++;
    }
}
//rasymas
void raso(preke sar[], int kiek, float preksuma){
    for(int i=0; i<kiek; i++){
        out<<setw(20)<<left<<sar[i].pavadinimas; // setw (kiek poziciju uzims)
        out<<setw(5)<<right<<sar[i].kiekis; // right or left lygiavimas
        out<<setw(10)<<fixed<<setprecision(3)<<sar[i].kaina;    // setprecision kiek skaiciu po kablelio
        out<<setw(10)<<fixed<<setprecision(4)<<right<<sar[i].suma;
        out<<endl;
    }
    out << setw(10) << fixed << setprecision(5)<<preksuma;

}

void psuma (preke sar[], int kiek){
    for(int i=0; i<kiek; i++){
        sar[i].suma = sar[i].kiekis * sar[i].kaina;
    }
}

void krepsuma (preke sar[], int kiek, float &preksuma){
    preksuma=0;
    for(int i=0; i<kiek; i++){
       // sar[i].suma = sar[i].kiekis * sar[i].kaina;
        preksuma += sar[i].suma;
    }
}

// rikiavimas
void rikiavimas (preke sar[], int kiek){
    for(int i=0; i<kiek; i++)
        for(int j=1; j<kiek; j++)
            if(sar[j-1].kaina>sar[j].kaina)
                swap(sar[j-1], sar[j]);

}

// sarasas su 3 brangiausiom prekem

void brangus (preke sar[], int kiek, preke sarBr[], int kiekBr){
    for(int i=0; i<kiekBr; i++)
        for(int j=0; j<kiekBr; j++)
        if(sar[j-1].kaina>sar[j].kaina){
                swap(sar[j-1], sar[j]);
                 }
                 int k=0;
            for(int i=kiek-kiekBr; i<kiek; i++){
                sarBr[k] = sar[i];
                k++;
            }
}


// krepsinio komandos 2, 2 atskiros textines bylos, is tu dvieju po 5 zmones reik sukurtu geriausia komanda.

        // baudos, rezultatyvumas, ir pan.
        // butinai 2jose bylose.
        // vytautas.boska@kitm.lt







