#include<iostream>
using namespace std;
int power(int b, int p){
    int pow=1;
    for(int i=1 ; i<=p ; i++){
        pow=pow*b;
    }
    return pow;
}
struct poly{
    private:
        int d;
        int *p;
    public:
    poly(int degree){
        d=degree;
        p=new int(d+1);
    }
    void insert(){
        cout<<"Enter coefficient in order high to low :- ";
        for(int i=d ; i>=0 ; i--){
            cin>>p[i];
        }
    }
    void display(){
        for(int i=d ; i>0 ; i--){
            if(p[i]==0) continue;
            else{
                cout<<p[i]<<"*x^"<<i<<" + ";
            }
        }
        cout << p[0] <<endl;
    }
    void add(poly b){
        int maxd , mind ;
        if(d>b.d){
            maxd=d;
            mind=b.d;
        }
        else{
            maxd=b.d;
            mind=d;
        }
        poly sum(maxd);
        for(int i=mind ; i>=0 ;i--){
            sum.p[i]=p[i]+b.p[i];
        }
        for(int i=maxd ; i>mind ; i--){
            if(maxd==d){
                sum.p[i]=p[i];
            }
            else if(maxd == b.d){
                sum.p[i]=b.p[i];
            }
        }
        sum.display();
    }
    void find(int x){
        int sum=0;
        for(int i=d ; i>=0 ; i--){
            sum=sum+(p[i]*power(x,i));
        }
        cout<<sum<<endl;
    }
};
int main(){
    poly p(2),p1(3),p3(4);
    p.insert();
    p.display();
    p1.insert();
    p1.display();
    //p.add(p1);
    p.find(2);
    return 0;
}
