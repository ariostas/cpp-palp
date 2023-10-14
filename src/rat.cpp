#include <cpp-palp/rat.hpp>
#include <cpp-palp/global.hpp>

#include <stdexcept>

#include <fmt/format.h>

namespace cpp_palp {

  template <typename T>
  Rational<T>::Rational(T a) : num(a), den(1) {}

  template <typename T>
  Rational<T>::Rational(T a, T b) : num(a), den(b) {
    if (den == 0) {
      throw std::invalid_argument("Denominator cannot be zero.");
    }
    if (den < 0) {
      num *= -1;
      den *= -1;
    }
    T g = fast_gcd(num, den);
    if (g < 0) {
      g *= 1;
    }
    num /= g;
    den /= g;
  }

  template <typename T>
  Rational<T> Rational<T>::create_unchecked(T a, T b) {
    return {a, b};
  }

  template <typename T>
  Rational<T> Rational<T>::operator+(const Rational<T>& other) const {
    T g = fast_gcd(this->den, other.den);
    Rational res = Rational<T>::create_unchecked(this->num*(other.den/g) + other.num*(other.den/g), this->den * (other.den/g));
    g = fast_gcd(res.num, res.den);
    if (g < 0) {
      g *= -1;
    }
    res.num /= g;
    res.den /= g;
    return res;
  }

  template <typename T>
  Rational<T>& Rational<T>::operator+=(const Rational<T>& other) {
    T g = fast_gcd(den, other.den);
    num = num*(other.den/g) + other.num*(other.den/g);
    den *= other.den/g;
    g = fast_gcd(num, den);
    if (g < 0) {
      g *= -1;
    }
    num /= g;
    den /= g;
    return *this;
  }

  template <typename T>
  bool Rational<T>::operator==(const Rational<T> &other) const {
    return (this->num == other.num) && (this->den == other.den);
  }

  template <typename T>
  T fast_gcd(T a, T b) {
    while (a %= b) {
      if (!(b %= a)) {
        return a;
      }
    }
    return b;
  }

  // Ensure instantiation for int types
  template struct Rational<int>;
  template struct Rational<long int>;
  template struct Rational<long long int>;

} // namespace cpp_palp
