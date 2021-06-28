#include <iostream>
#include <initializer_list>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename T>
T average_list(initializer_list<T> xD)
{
    T tot = 0;
    for (auto p = xD.begin();p!=xD.end();++p)
       tot+=*p;
    return tot;
}

void sum_values(){};

template <typename T>
double sum_values(const T& v)
{
    return v;
}

template <typename T,typename... Args>
double sum_values(const T& v, const Args&...args)
{
    double tot = 0;
    tot=tot+v+sum_values(args...);
    return tot;
}

class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
    Cpmv();
    Cpmv(string q, string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
private:
    Info *pi;
};

/*template<class T>
class TooBig
{
    T cutoff;
public:
    TooBig(const T& t) : cutoff(t){}
    bool operator()(const T & v){return v >cutoff;}
};

void outint( int n) {cout<<n<<" ";}
*/




int main()
{
    /* task 1
    auto q = average_list({15.4,10.7,9.0});
    cout<<q<<endl;
    cout<<average_list({20,30,19,17,45,38})<<endl;
    auto ad = average_list<double>({'A',70,66.33});
    cout<<ad<<endl;
    */

    /* task 2;
    Cpmv x("One","Two");
    Cpmv y = x+x;
    cout<<"Object x: "<<endl;
    x.Display();
    cout<<"Object y:"<<endl;
    y.Display();
    Cpmv z,zz;
    cout<<"z = x"<<endl;
    z=x;
    cout<<"Now object z: "<<endl;
    z.Display();
    cout<<"And object x:"<<endl;
    x.Display();
    cout<<"zz= x+y"<<endl;
    zz= x+y;
    cout<<"Object zz:"<<endl;
    zz.Display();
    cout<<"zz move(one)"<<endl;
    zz=move(x);
    cout<<"Object zz:"<<endl;
    zz.Display();
    cout<<"Object x:"<<endl;
    x.Display();
    */

    /* task 3
    cout<<sum_values(13.5,5.5,324,4,5)<<endl;
    cout<<sum_values(13.5,5,10)<<endl;
    */

    auto l = [](int x){return x > 100;};
    auto b = [](int x){return x > 200;};
    auto o = [](int n){cout<<n<<" ";};
    //TooBig<int> f100(100);

    int vals[10] = {50,100,90,180,60,210,415,88,188,201};
    list<int> yadayada(vals,vals+10);
    list<int> etcetera(vals,vals+10);
    cout<<"Original list: "<<endl;
    for_each(yadayada.begin(),yadayada.end(),o);
    cout<<endl;
    for_each(etcetera.begin(),etcetera.end(),o);
    cout<<endl;
    yadayada.remove_if(l);
    etcetera.remove_if(b);
    cout<<"Cutting list"<<endl;
    for_each(yadayada.begin(),yadayada.end(),o);
    cout<<endl;
    for_each(etcetera.begin(),etcetera.end(),o);
    cout<<endl;
    
    return 0;
}

Cpmv::Cpmv()
{
    cout<<"Created Cpmv object"<<endl;
    pi = nullptr;
}

Cpmv::Cpmv(string q, string z)
{

    pi = new Info; 
    pi->qcode =q;
    pi->zcode =z;
    cout<<"Created Cpmv object with q and z name"<<endl;
}

Cpmv::Cpmv(const Cpmv & cp)
{
    pi = new Info;
    pi->qcode=cp.pi->qcode;
    pi->zcode=cp.pi->zcode;
    cout<<"Coppied object"<<endl;
}

Cpmv::Cpmv(Cpmv && mv)
{
    pi = mv.pi;
    mv.pi = nullptr;
    cout<<"Semantics transference"<<endl;

}

Cpmv::~Cpmv()
{
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & f)
{
    cout<<"Copying assignment constructor"<<endl;

    if (this == &f)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = f.pi->qcode;
    pi->zcode = f.pi->zcode;
    return *this;

}

Cpmv & Cpmv::operator=(Cpmv && f)
{
    cout<<"Copying assignment move constructor"<<endl;

    if (this == &f)
        return *this;
    delete pi;
    pi = f.pi;
    f.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    Cpmv temp = Cpmv(obj);
    temp.pi->qcode = temp.pi->qcode + " "+pi->qcode;
    temp.pi->zcode = temp.pi->zcode + " "+pi->zcode;
    return temp;

}
void Cpmv::Display() const
{
    if (pi == nullptr)
        cout<<"Empty object"<<endl;
    else
    {
        cout<<"Qcode: "<<pi->qcode<<endl;
        cout<<"Zcode: "<<pi->zcode<<endl;
    }
}
