#ifndef POLYMPMTEST_UTILS_H
#define POLYMPMTEST_UTILS_H

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>

#include <Kokkos_Core.hpp>
#include <Kokkos_Random.hpp>

#include <netcdf.h>
namespace polyMpmTest{

class Vector2;
// TODO: Vector => Vector2
// afterwards may have: Vector3
using Vector2View = Kokkos::View<Vector2*>;
using DoubleView = Kokkos::View<double*>;
using IntView = Kokkos::View<int*>;
using BoolView = Kokkos::View<bool*>;

class Vector2 {
  private:
    double coords_[2];

  public:
    //constructors
    KOKKOS_INLINE_FUNCTION
    Vector2():coords_{0.0, 0.0}{}
    
    ~Vector2() = default;
    
    KOKKOS_INLINE_FUNCTION
    Vector2(double x1, double x2):coords_{x1,x2}{}
    
    KOKKOS_INLINE_FUNCTION
    Vector2(double x[2]):coords_{x[0], x[1]}{}

    //operators 
    KOKKOS_INLINE_FUNCTION
    double operator[](int i) const { return coords_[i]; }
    
    KOKKOS_INLINE_FUNCTION
    double &operator[](int i) { return coords_[i]; }

    
    KOKKOS_INLINE_FUNCTION
    Vector2 operator-() { return Vector2(-coords_[0], -coords_[1]); }
    
    KOKKOS_INLINE_FUNCTION
    Vector2 operator+(Vector2 v) { return Vector2(coords_[0] + v[0],
                                                 coords_[0] + v[1]); }
    
    KOKKOS_INLINE_FUNCTION
    Vector2 operator-(Vector2 v) { return Vector2(coords_[0] - v[0],
                                                 coords_[0] - v[1]); }
    
    KOKKOS_INLINE_FUNCTION
    Vector2 operator*(double scalar) const { return Vector2(coords_[0]*scalar,
                                                            coords_[0]*scalar); }
    
    KOKKOS_INLINE_FUNCTION
    double dot(Vector2 v) { return  coords_[0]*v[0]+coords_[1]*v[1]; }
    
    KOKKOS_INLINE_FUNCTION
    double cross(Vector2 v) { return (coords_[0]*v[1] - coords_[1]*v[0]); }
    
    KOKKOS_INLINE_FUNCTION
    double magnitude() {return sqrt(coords_[0]*coords_[0] +
                                    coords_[1]*coords_[1]); }
    
    KOKKOS_FUNCTION
    void operator=(const double &scalar);
    //Vector2 &operator+=(const Vector2 &v);
   
};

KOKKOS_INLINE_FUNCTION
void Vector2::operator=(const double &scalar){
    coords_[0] = scalar;
    coords_[1] = scalar;
}

KOKKOS_INLINE_FUNCTION
void initArray(Vector2* arr, int n, Vector2 fill){
    for(int i=0; i<n; i++){
        arr[i] = fill;
    }
}

KOKKOS_INLINE_FUNCTION
void initArray(double* arr, int n, double fill){
    for(int i=0; i<n; i++){
        arr[i] = fill;
    }
}

}//namespace polyMpmTest end

#endif

