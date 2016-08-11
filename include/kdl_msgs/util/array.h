/* Copied and adapted from boost/array.hpp: */


#ifndef KDL_MSGS_ARRAY_H
#define KDL_MSGS_ARRAY_H

#include <cstddef>
#include <iterator>
#include <algorithm>

#include <boost/assert.hpp>
#include <boost/swap.hpp>

namespace kdl_msgs {
namespace util {

template<typename T, std::size_t N>
class array {
public:
  // type definitions
  typedef T              value_type;
  typedef T*             iterator;
  typedef const T*       const_iterator;
  typedef T&             reference;
  typedef const T&       const_reference;
  typedef std::size_t    size_type;
  typedef std::ptrdiff_t difference_type;

  // construct/copy/destruct
  array(value_type *data) : elems(data) {}
  template<typename T2> array(const array<T2, N>& other) {
      *this = other;
  }

  // implicit conversion
  operator T*() { return elems; }
  operator const T*() const { return elems; }

  // iterator support
  iterator        begin()       { return elems; }
  const_iterator  begin() const { return elems; }
  const_iterator cbegin() const { return elems; }

  iterator        end()       { return elems+N; }
  const_iterator  end() const { return elems+N; }
  const_iterator cend() const { return elems+N; }

  // reverse iterator support
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  reverse_iterator rbegin() { return reverse_iterator(end()); }
  const_reverse_iterator rbegin() const {
      return const_reverse_iterator(end());
  }
  const_reverse_iterator crbegin() const {
      return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const {
      return const_reverse_iterator(begin());
  }
  const_reverse_iterator crend() const {
      return const_reverse_iterator(begin());
  }

  // operator[]
  reference operator[](size_type i)
  {
      BOOST_ASSERT_MSG( i < N, "out of range" );
      return elems[i];
  }

  const_reference operator[](size_type i) const
  {
      BOOST_ASSERT_MSG( i < N, "out of range" );
      return elems[i];
  }

  // at() with range check
  reference at(size_type i) { rangecheck(i); return elems[i]; }
  const_reference at(size_type i) const { rangecheck(i); return elems[i]; }

  // front() and back()
  reference front()
  {
      return elems[0];
  }

  const_reference front() const
  {
      return elems[0];
  }

  reference back()
  {
      return elems[N-1];
  }

  const_reference back() const
  {
      return elems[N-1];
  }

  // size is constant
  static size_type size() { return N; }
  static bool empty() { return (N > 0); }
  static size_type max_size() { return N; }
  enum { static_size = N };

  // swap
  void swap (array<T,N>& y) {
      boost::swap(elems, y.elems);
  }

  // direct access to data (read-only)
  const T* data() const { return elems; }
  T* data() { return elems; }

  // use array as C array (direct read/write access to data)
  T* c_array() { return elems; }

  // assignment with type conversion
  template <typename T2>
  array<T,N>& operator= (const array<T2,N>& rhs) {
      std::copy(rhs.begin(),rhs.end(), begin());
      return *this;
  }

  // assign one value to all elements
  void assign (const T& value) { fill ( value ); }    // A synonym for fill
  void fill   (const T& value)
  {
      std::fill_n(begin(),size(),value);
  }

  // check range (may be private because it is static)
  static void rangecheck (size_type i) {
      if (i >= size()) {
          std::out_of_range e("array<>: index out of range");
          boost::throw_exception(e);
      }
  }

private:
  value_type* elems;
};

// comparisons
template<class T, std::size_t N>
bool operator== (const array<T,N>& x, const array<T,N>& y) {
    return std::equal(x.begin(), x.end(), y.begin());
}
template<class T, std::size_t N>
bool operator== (const array<T,N>& x, const T y[N]) {
    return std::equal(x.begin(), x.end(), y);
}
template<class T, std::size_t N>
bool operator== (const T x[N], const array<T,N>& y) {
    return std::equal(x, x+N, y.begin());
}
template<class T, std::size_t N>
bool operator< (const array<T,N>& x, const array<T,N>& y) {
    return std::lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());
}
template<class T, std::size_t N>
bool operator< (const array<T,N>& x, const T y[N]) {
    return std::lexicographical_compare(x.begin(),x.end(),y,y+N);
}
template<class T, std::size_t N>
bool operator< (const T x[N], const array<T,N>& y) {
    return std::lexicographical_compare(x,x+N,y.begin(),y.end());
}
template<class T, std::size_t N>
bool operator!= (const array<T,N>& x, const array<T,N>& y) {
    return !(x==y);
}
template<class T, std::size_t N>
bool operator!= (const array<T,N>& x, const T y[N]) {
    return !(x==y);
}
template<class T, std::size_t N>
bool operator!= (const T x[N], const array<T,N>& y) {
    return !(x==y);
}
template<class T, std::size_t N>
bool operator> (const array<T,N>& x, const array<T,N>& y) {
    return y<x;
}
template<class T, std::size_t N>
bool operator> (const array<T,N>& x, const T y[N]) {
    return y<x;
}
template<class T, std::size_t N>
bool operator> (const T x[N], const array<T,N>& y) {
    return y<x;
}
template<class T, std::size_t N>
bool operator<= (const array<T,N>& x, const array<T,N>& y) {
    return !(y<x);
}
template<class T, std::size_t N>
bool operator<= (const array<T,N>& x, const T y[N]) {
    return !(y<x);
}
template<class T, std::size_t N>
bool operator<= (const T x[N], const array<T,N>& y) {
    return !(y<x);
}
template<class T, std::size_t N>
bool operator>= (const array<T,N>& x, const array<T,N>& y) {
    return !(x<y);
}
template<class T, std::size_t N>
bool operator>= (const array<T,N>& x, const T y[N]) {
    return !(x<y);
}
template<class T, std::size_t N>
bool operator>= (const T x[N], const array<T,N>& y) {
    return !(x<y);
}

// get_array
template<class T, std::size_t N>
array<T,N> get_array(T (&x)[N]) {
  return x;
}
template<class T, std::size_t N>
array<const T,N> get_array(const T(&x)[N]) {
  return x;
}

} // namespace util
} // namespace kdl_msgs

#endif // KDL_MSGS_ARRAY_H
