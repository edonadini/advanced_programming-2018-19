#include<iostream>
class Matrix;
class Vector{
    int v[4];

    friend Vector operator* (const Matrix&, const Vector&);
    public:
    const int& operator[](const std::size_t& i) const noexcept{return v[i];}
    int& operator[](const std::size_t& i) noexcept {return v[i];}
};

class Matrix{
    Vector v[4];
    friend Vector operator* (const Matrix&, const Vector&);
    public:
    const Vector& operator[](const std::size_t& i) const noexcept{return v[i];}
    Vector& operator[](const std::size_t& i) noexcept {return v[i];}

};

Vector operator*(const Matrix& m, const Vector& w)
{
    Vector r;
    for (int i=0; i<4; i++) {
        r.v[i]=0;
        for (int j=0;j<4; j++) r.v[i]+=m.v[i].v[j] * w.v[j];
    }
    return r;
}

int main()
{
    Vector b;
    Matrix A;
    Vector u;
    for(int i=0;i<4; i++)
     {
         b[i]=i;
         u[i]=1;
         std::cout<<b[i]<<" "<<u[i]<<std::endl;
     }
     for(int i=0;i<4; i++) 
     {
         A[i]=u;
         for(int j=0; j<4; j++) std::cout<<A[i][j];
         std::cout<<" "<<std::endl;
     }
     // segmentation fault??
     Vector c=A*b;
     for(int i=0;i<4; i++)
     {
         std::cout<<c[i]<<std::endl;
     }
    return 0;
}