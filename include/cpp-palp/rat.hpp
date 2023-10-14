#pragma once

namespace cpp_palp {

  template <typename T>
  struct Rational {
    T num;
    T den;

    /// @brief Constructor that initializes a rational from an integer.
    ///
    /// @param a The integer that it will be equal to.
    Rational(T a);

    /// @brief Constructor that initializes to an arbitrary ratio.
    ///
    /// This constructor has safety checks to make sure that `a>0` and `a`,`b` are relatively prime.
    ///
    /// @param a Numerator
    /// @param b Denominator
    Rational(T a, T b);

    /// @brief Constructor used to avoid safety checks in favor of speed.
    ///
    /// @param a Numerator
    /// @param b Denominator

    static Rational<T> create_unchecked(T a, T b);

    Rational<T> operator+(const Rational<T>&) const;
    Rational<T>& operator+=(const Rational<T>&);
    //Rational<T>& operator++(const T&);

    bool operator==(const Rational<T>&) const;

  };


  template <typename T>
  T fast_gcd(T a, T b);

  //template <typename T>
  //T nonneg_gcd(T a, T b);

} // namespace cpp_palp
