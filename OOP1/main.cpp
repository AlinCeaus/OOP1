#include <iostream>

using namespace std;

class Fractie
{
private:
    int a, b;


public:

    Fractie(int A = 1, int B = 1) //:  b(B)
    {

       // a = int (A);
        a = A;
       b = B;
    }
    Fractie( const Fractie& fra) //: a(fra.a) // <- doar la mopstenire
    {
        this->a = fra.a;
       this->b = fra.b;
    }

    int get_a() const
    {
        return this->a;

    }
    void set_a(int a )
    {
        if(a != 0)
        {
            this->a = a;
        }

    }
    int get_b(int b)
    {
        return b;
    }
    void set_B(int B)
    {
        if(B == 0)
        {
            B = 1;
        }
        b = B;
    }
    void print()
    {
        cout << this << "\n";
        if(this->b == 1)
        {
            cout << this->a;
        }else
        {
            cout << this->a << "/" << this->b;
        }

    }

    void add(Fractie fr2)
    {
        if(b != fr2.b)
        {
            a= fr2.b*a + b*fr2.a;
            b= b*fr2.b;
        }else{
        a+=fr2.a;
        b+=fr2.b;
        }
        if(b == 0)
        {
            b = 1;
        }
    }
    void dif(Fractie fr2)
    {

        if(b != fr2.b)
        {
            a= fr2.b*a - b*fr2.a;
            b= b*fr2.b;
        }else{
        a-=fr2.a;
        b-=fr2.b;
        }
        if(b == 0)
        {
            b = 1;
        }
    }
    void inm(Fractie fr2)
    {
        a*=fr2.a;
        b*=fr2.b;
        if(b == 0)
        {
            b = 1;
        }
    }
    void imp(Fractie fr2)
    {
        a/=fr2.a;
        b/=fr2.b;
        if(b == 0)
        {
            b = 1;
        }
    }
    void simplificare()
    {
        int n = a, m = b;
        while(n != m)
        {
            if(n > m)
            {
                n -=m;
            }else
            {
                m-= n;
            }
        }
        a/=n;
        b/=n;
    }
    friend Fractie addf( const Fractie ,const Fractie );




//getteri ,setteri, metoda pt simplificare "adica 4/2 = 2/1 = 2"  ,
//la setarr si constructor sa verific daca b!= 0 daca e 0 os a fie egal cu 1
//metode pt uma produs si impartire si difreanta
};

Fractie addf(const Fractie f1,const Fractie f2)
{
   Fractie f3;
    f3.a = f1.a + f2.a;
    f3.b = f1.b + f2.b;
   // f1.a = 7;
   //f1.set_a(7);
    return f3;
}



int main()
{
  Fractie fra = Fractie(4, 2);
 // fra.print();
  cout << "\n";
  Fractie fra2 ;
  //fra.add(fra2);
  //fra.simplificare();
  cout << &fra << "\n";
  fra.print();
  cout << "\n";
  fra2.print();
  cout << "\n";

  Fractie fra4 = addf(fra, fra2);
  fra4.print();


  Fractie fra3 = fra;
  fra.set_a(5);
  fra.print();
  cout << "\n";
  fra3.print();
  cout << "\n";

}

