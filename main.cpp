#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <sstream>

using namespace std;

//functie ajutatoare
int array_f(int arr[], int n)
{
    vector <bool> check(n,false);
    // int ok=0// presupunem ca elementele se repeta
    int nr_el=0;

    if(nr_el<100)
    {
        for(int i=0; i<n; i++)
        {
            if(check[i]== true)
                continue;

            //count frequency
            int countt = 1;
            for(int j = i+1; j<n; j++)
            {
                if (arr[i] == arr[j])
                {
                    check[j] = true;
                    countt++;
                }
            }
            if(countt>1)
            {
                arr[i]=(rand() % 108 + 1 ); //genereaza alt numar
            }
            else if(countt==1)
            {
                nr_el++;
            }
        }
    }
    if(nr_el==99)
    {
        return 1;
    }
}

//clasele

//clasa participanti
class Info
{

public:

    string firstname;
    string lastname;
    string city;
    int long debt;
    int weight;


//declarare destructor
    ~Info();

//constructor al participantilor

    Info(string f, string l, string c, long int d, int w)
    {
        firstname=f;
        lastname=l;
        city=c;
        debt=d;
        weight=w;
    }

//adaugare info in fisier(debt,weight)
    void add()
    {
        string str, p;
        size_t pos;
        // in fisier se afla info despre nume,prenume,oras
        ifstream fin("participanti.txt");
        ofstream foutt("temp1.txt");
        while (getline(fin, str))
        {
            pos = str.find(" ");//la finalul liniei
            p = str.substr(0, pos);
            srand(time(0));
            foutt<<p<<","<<(10000 + (rand() % 90001))<<","<<(50+(rand() % 51));
        }
        foutt.close();
        fin.close();
        remove("participanti.txt");
        rename("temp1.txt","participanti.txt");
    }

};

Info::~Info(void)
{
    cout<<"Details of participant complete"<<endl;

}

// concurentii mostenesc clasa Info

class Contestant: public Info
{
public:
    int nr_c; // numar de concurs
    int nr_s;// numar superviser

//setters
    void setfisrtnume(string fn)
    {
        this->fisrtnume=fn;
    }

    void setlastnume(string ln)
    {
        this->lastnume=ln;
    }


    void setnr_s(int x)
    {
        nr_s = x;

    }
//getters
    string getfirstname()
    {

        return this->firstname;
    }

    string getlastname()
    {

        return this->lastname;
    }

    string getcity()
    {

        return this->city;
    }

    int  getWeight()
    {

        return weight;
    }

    int long getDebt()
    {

        return debt;
    }

    int long getnrC()
    {

        return nr_c;
    }

    int long getnrS()
    {

        return nr_s;
    }


    void contestant();
};

// se selecteaza 99 de concurenti din fisier in mod aleator dupa number si li se atribuie numarul de concurs
void Contestant:: Contestant()
{
    string str, p, aux;
    size_t pos;
    int r_nr[98];
    ifstream fin("participanti.txt");
    ofstream fout("jucatori.txt");
    ofstream tempp("tempp.txt",ios::out);
    nr_c=0;
    fin.open("participanti.txt",ios::in);

    for(int i=0; i<99; i++)
    {
        //generez un numar aleatoriu intre 1 si 108
        srand(time(0));//pentru a genera un numar diferit la fiecare apelare a lui rand
        r_nr[i]= (rand() % 108 + 1 ); // intre 1 si 108

    }

    if(array_f(r_nr[],98)==1)
    {
        //Citeste fiecare linie si gaseste index ce coincide cu random_nr:
        while (getline(fin, str))
        {
            bool ok=0;
            pos = str.find(",");
            p = str.substr(0, pos); //din capat pana la virgula
            str.erase(0, pos+1); // preia datele de pe linie
            //convert string to integer
            stringstream container(p);
            int pp;
            container>>pp;
            for(int i=0; i<98; i++)
            {
                if ( pp == r_nr[i])
                {
                    ok = 1; // am gasit nr
                    nr_c++;
                    // adaug jucatorul in fisierul jucatori
                    fout.open("concurenti.txt");
                    fout<< nr_c <<","; //numerotarea jucatorilor
                    fout<< str;

                    //stergem concurentul din fisierul participanti
                    //adaug date concurent in fisierul temp
                    tempp.open("tempp.txt");
                    pos = str.find("   ");
                    p = str.substr(0, pos);
                    tempp<<str<<endl;

                }
                if (ok==0) throw "Number participant doesn't exist!";
            }
        }
    }
    tempp.close();
    fin.close();
    remove("participanti.txt");
    rename("temp.txt","supraveghetori.txt");
    fout.close();
}


// supraveghetorii mostenesc clasa info

class Superviser: public Info
{
public:
    int numberS;
    char mask[15]; // square, triangle, circle;

    void setmask(char s[15])
    {
        strcpy(mask,s);

    }

    void setnumberS(int x)
    {
        numberS = x;
    }

    void debts(long int d1,long int d2)
    {
        return d1+d2;

    }

};



int main()
{
    Info info();
    info.add();

    Contestant c[99]; //vectorul concurentilor
    c.contestan();
    Superviser s[9]; //vectorul supraveghetorilor


    fstream sfile;
    sfile.open("supraveghetori.txt",ios::in);

    if (sfile.is_open())
    {
        string line;
        int index=1;
        while(getline(cfile, line))
        {
            if(index<10)
            {
                s[index].setnumberS(index);

                if (index>=1 && index<=2)
                {
                    s[index].setmask("square");
                }
                if (index>=3 && index<=5)
                {
                    s[index].setmask"triangle");
                }
                if (index>=6 && index<=8)
                {
                    s[index].setmask("circle");
                }
            }
            index++;
        }
        sfile.close();
    }

//fiecare supraveghetor are 11 concurenti
    int k = 1;
    for (int i=1; i<=9; i++)
        for (int j=1; j<=11; j++)
        {
            c[k].setnr_s(i);
            k++;
        }

//primul joc
//Red Light Green Light
    fstream cfile;
    cfile.open("concurenti.txt",ios::in);
    int n=99;
    for(int a=1; a<n; a++)
    {
        if(c[a].getnrC %2 ==0) //numarul de concurs e par
        {
            int ns=c[a].getnrS;
            s[ns].debts(s[ns].debt,c[a].debt); //adaug debt concurent la debt supraveghetor
            c[a].clear() //stergem concurent
            n--;

        }
    }
//afis
    for(int a=1; a<n; a++)
    {
        cout<<c[a].getfistname()<<","<<c[a].getlastname()<<","<<c[a].getcity()<<","<<c[a].getdebt()<<endl;

    }

//Tug of War
int nr_e=n/4;//nr concurenti pe echipa

for(int q=1; q<nr_1; q++)
{

}




    return 0;
}
