
#include <iostream>
#include "stdafx.h"
#include <stdint.h>
/*
class Rational
{
public:
  Rational operator-() const {    }
  Rational operator+() const { return *this; }
 
  Rational kehrwert() const {    } //fuer die Division
 
  Rational& operator+=(Rational const& rhs) {    }
  Rational& operator-=(Rational const& rhs) { return *this += -rhs; }
  Rational& operator*=(Rational const& rhs) {    }
  Rational& operator/=(Rational const& rhs) { return *this *= kehrwert(rhs); }
};
 
Rational operator+(Rational const& lhs, Rational const& rhs) { Rational tmp(lhs); return tmp += rhs; }
Rational operator-(Rational const& lhs, Rational const& rhs) { Rational tmp(lhs); return tmp -= rhs; }
Rational operator*(Rational const& lhs, Rational const& rhs) { Rational tmp(lhs); return tmp *= rhs; }
Rational operator/(Rational const& lhs, Rational const& rhs) { Rational tmp(lhs); return tmp /= rhs; }
 
bool operator==(Rational const& lhs, Rational const& rhs) {  }
bool operator!=(Rational const& lhs, Rational const& rhs) { return !(lhs == rhs); }
bool operator<(Rational const& lhs, Rational const& rhs)  {  }
bool operator>(Rational const& lhs, Rational const& rhs)  { return rhs < lhs; }
bool operator<=(Rational const& lhs, Rational const& rhs) { return !(lhs > rhs); }
bool operator>=(Rational const& lhs, Rational const& rhs) { return !(lhs < rhs); }

*/
#pragma pack(2)
struct uint24_t 
{
    /// \brief Durch Packing und Bitfields werden nur 3byte verwendet
    uint32_t value : 24;
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Konstruktor setzt Anfangswert auf 0
    ///
    uint24_t() { value = 0; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Copy Constructor
    ///
    uint24_t(const int& rhs) {  value = rhs; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Zuweisungsoperator
    ///
    uint24_t& operator=(const int& rhs) { value = rhs; return *this; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Konstruktor für uint64_t
    ///
    uint24_t(const uint64_t& rhs) {  value = rhs; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Zuweisung für uint64_t
    ///
    uint24_t& operator=(const uint64_t& rhs) { value = rhs; return *this; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Konstruktor für uint32_t
    ///
    uint24_t(const uint32_t& rhs) {  value = rhs; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Zuweisung für uint32_t
    ///
    uint24_t& operator=(const uint32_t& rhs) { value = rhs; return *this; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Konstruktor für uint8_t
    ///
    uint24_t(const uint8_t& rhs) {  value = rhs; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Zuweisung für uint8_t
    ///
    uint24_t& operator=(const uint8_t& rhs) { value = rhs; return *this; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Konstruktor für uint16_t
    ///
    uint24_t(const uint16_t& rhs) {  value = rhs; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Zuweisung für uint16_t
    ///
    uint24_t& operator=(const uint16_t& rhs) { value = rhs; return *this; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Additionsoperator
    ///
    friend uint24_t operator+(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value + rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Additionsoperator
    ///
    friend uint24_t operator+(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value + rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Additionsoperator
    ///
    friend uint24_t operator+(const int& lhs, const uint24_t& rhs) { return operator+(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Inkrementoperator
    ///
    void operator+=(const uint24_t rhs) { value += rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Postinkrement
    ///
    void operator++(int) { value++; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Preinkrement
    ///
    void operator++() { value++; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Subtraktionsoperator
    ///
    friend uint24_t operator-(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value - rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Subtraktionsoperator
    ///
    friend uint24_t operator-(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value - rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Subtraktionsoperator
    ///
    friend uint24_t operator-(const int& lhs, const uint24_t& rhs) { return operator-(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Dekrementoperator
    ///
    void operator-=(const uint24_t rhs) { value -= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Postdrekement
    ///
    void operator--(int) { value--; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Predekrement
    ///
    void operator--() { value--; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Multiplikationsoperator
    ///
    friend uint24_t operator*(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value * rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Multiplikationsoperator
    ///
    friend uint24_t operator*(const int& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs * rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Multiplikationsoperator
    ///
    friend uint24_t operator*(const uint24_t& lhs, const int& rhs) { return operator*(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Multiplikationsoperator
    ///
    void operator*=(const uint24_t rhs) { value *= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Divisionsoperator
    ///
    friend uint24_t operator/(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        if(rhs.value == 0) return lhs;
        tmp.value = lhs.value / rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Divisionsoperator
    ///
    friend uint24_t operator/(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value / rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Divisionsoperator
    ///
    friend uint24_t operator/(const int& lhs, const uint24_t& rhs) { return operator/(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Divisionsoperator
    ///
    void operator/=(const uint24_t rhs) { value /= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Maskenoperator
    ///
    friend uint24_t operator&(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value & rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Maskenoperator
    ///
    friend uint24_t operator&(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value & rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Maskenoperator
    ///
    friend uint24_t operator&(const int& lhs, const uint24_t& rhs) { return operator&(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Maskenoperator
    ///
    void operator&=(const uint24_t rhs) { value &= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  ODER Operator
    ///
    friend uint24_t operator|(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value | rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  ODER Operator
    ///
    friend uint24_t operator|(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value | rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  ODER Operator
    ///
    friend uint24_t operator|(const int& lhs, const uint24_t& rhs) { return operator|(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  ODER Operator
    ///
    void operator|=(const uint24_t rhs) { value |= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  XOR Operator
    ///
    friend uint24_t operator^(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value ^ rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  XOR Operator
    ///
    friend uint24_t operator^(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value ^ rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  XOR Operator
    ///
    friend uint24_t operator^(const int& lhs, const uint24_t& rhs) { return operator^(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  XOR Operator
    ///
    void operator^=(const uint24_t rhs) { value ^= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Links-Shift Operator
    ///
    friend uint24_t operator<<(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value << rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Links-Shift Operator
    ///
    friend uint24_t operator<<(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value << rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Links-Shift Operator
    ///
    friend uint24_t operator<<(const int& lhs, const uint24_t& rhs) { return operator<<(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Rechts-Shift Operator
    ///
    friend uint24_t operator>>(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value >> rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Rechts-Shift Operator
    ///
    friend uint24_t operator>>(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value >> rhs;
        return tmp;
    }///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Rechts-Shift Operator
    ///
    friend uint24_t operator>>(const int& lhs, const uint24_t& rhs) { return operator>>(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Modulo Operator
    ///
    friend uint24_t operator%(const uint24_t& lhs,const uint24_t& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value % rhs.value;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Modulo Operator
    ///
    friend uint24_t operator%(const uint24_t& lhs,const int& rhs)
    {
        uint24_t tmp;
        tmp.value = lhs.value % rhs;
        return tmp;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Modulo Operator
    ///
    friend uint24_t operator%(const int& lhs, const uint24_t& rhs) { return operator%(rhs, lhs); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Modulo Operator
    ///
    void operator%=(const uint24_t rhs) { value %= rhs.value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Negationsoperator
    ///
    void operator~() { value = ~value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Negationsoperator
    ///
    void operator!() { value = !value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Vergleichsoperator
    ///
    bool operator==(const uint24_t& rhs) { return (value == rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Ungleichoperator
    ///
    bool operator!=(const uint24_t& rhs) { return (value != rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Größer-Gleich Operator
    ///
    bool operator>=(const uint24_t& rhs) { return (value >= rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Kleiner-Gleich Operator
    ///
    bool operator<=(const uint24_t& rhs) { return (value <= rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Größer Operator
    ///
    bool operator>(const uint24_t& rhs) { return (value > rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Kleiner Operator
    ///
    bool operator<(const uint24_t& rhs) { return (value > rhs.value); }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Cast to Int Operator
    ///
    operator int() const { return value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Cast to uin32_t Operator
    ///
    operator uint32_t() const { return value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Cast to uin16_t Operator
    ///
    operator uint16_t() const { return value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Cast to uin8_t Operator
    ///
    operator uint8_t() const { return value; }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details  Cast to bool Operator
    ///
    operator bool() const { return (value > 0); }
};


struct Complex {
   Complex( double r, double i ) : re(r), im(i) {}
   Complex operator+( Complex &other );
   void Display( ) {   std::cout << re << ", " << im << std::endl; }
private:
   double re, im;
};

// Operator overloaded using a member function
Complex Complex::operator+( Complex &other ) {
   return Complex( re + other.re, im + other.im );
}


int _tmain(int argc, _TCHAR* argv[])
{
   Complex a = Complex( 1.2, 3.4 );
   Complex b = Complex( 5.6, 7.8 );
   Complex c = Complex( 0.0, 0.0 );
   

   c = a + b;
   c.Display();
   
   return 0;
}