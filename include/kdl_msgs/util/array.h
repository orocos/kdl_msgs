#ifndef KDL_MSGS__ARRAY_H
#define KDL_MSGS__ARRAY_H

#include <cstddef>
#include <iterator>
#include <algorithm>

#include <boost/assert.hpp>
#include <boost/swap.hpp>

#include <ros/serialization.h>

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

  // conversion
  operator T*() const {
    return elems;
  }

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


namespace ros {
namespace serialization {

/**
* \brief C-Array serializer, default implementation does nothing
*/
template<typename T, size_t N, class Enabled = void>
struct CArraySerializer
{};

/**
* \brief C-Array serializer, specialized for non-fixed-size, non-simple types
*/
template<typename T, size_t N>
struct CArraySerializer<T, N, typename boost::disable_if<mt::IsFixedSize<T> >::type>
{
 typedef T* IteratorType;
 typedef const T* ConstIteratorType;

 template<typename Stream, typename ArrayType>
 inline static void write(Stream& stream, const ArrayType& v)
 {
   ConstIteratorType it = v;
   ConstIteratorType end = v+N;
   for (; it != end; ++it)
   {
     stream.next(*it);
   }
 }

 template<typename Stream, typename ArrayType>
 inline static void read(Stream& stream, ArrayType& v)
 {
   IteratorType it = v;
   IteratorType end = v+N;
   for (; it != end; ++it)
   {
     stream.next(*it);
   }
 }

 template<typename ArrayType>
 inline static uint32_t serializedLength(const ArrayType& v)
 {
   uint32_t size = 0;
   ConstIteratorType it = v;
   ConstIteratorType end = v+N;
   for (; it != end; ++it)
   {
     size += serializationLength(*it);
   }

   return size;
 }
};

/**
* \brief C-Array serializer, specialized for fixed-size, simple types
*/
template<typename T, size_t N>
struct CArraySerializer<T, N, typename boost::enable_if<mt::IsSimple<T> >::type>
{
 typedef T* IteratorType;
 typedef const T* ConstIteratorType;

 template<typename Stream, typename ArrayType>
 inline static void write(Stream& stream, const ArrayType& v)
 {
   const uint32_t data_len = N * sizeof(T);
   memcpy(stream.advance(data_len), &v, data_len);
 }

 template<typename Stream, typename ArrayType>
 inline static void read(Stream& stream, ArrayType& v)
 {
   const uint32_t data_len = N * sizeof(T);
   memcpy(&v, stream.advance(data_len), data_len);
 }

 template<typename ArrayType>
 inline static uint32_t serializedLength(const ArrayType&)
 {
   return N * sizeof(T);
 }
};

/**
* \brief C-Array serializer, specialized for fixed-size, non-simple types
*/
template<typename T, size_t N>
struct CArraySerializer<T, N, typename boost::enable_if<mpl::and_<mt::IsFixedSize<T>, mpl::not_<mt::IsSimple<T> > > >::type>
{
 typedef T* IteratorType;
 typedef const T* ConstIteratorType;

 template<typename Stream, typename ArrayType>
 inline static void write(Stream& stream, const ArrayType& v)
 {
   ConstIteratorType it = v;
   ConstIteratorType end = v+N;
   for (; it != end; ++it)
   {
     stream.next(*it);
   }
 }

 template<typename Stream, typename ArrayType>
 inline static void read(Stream& stream, ArrayType& v)
 {
   IteratorType it = v;
   IteratorType end = v+N;
   for (; it != end; ++it)
   {
     stream.next(*it);
   }
 }

 template<typename ArrayType>
 inline static uint32_t serializedLength(const ArrayType& v)
 {
   return serializationLength(*v) * N;
 }
};

/**
 * \brief serialize version for plain C arrays
 */
template<typename T, size_t N, typename Stream>
inline void serialize(Stream& stream, const T(&t)[N])
{
  CArraySerializer<T, N>::write(stream, t);
}

/**
 * \brief deserialize version for plain C arrays
 */
template<typename T, size_t N, typename Stream>
inline void deserialize(Stream& stream, T(&t)[N])
{
  CArraySerializer<T, N>::read(stream, t);
}

/**
 * \brief serializationLength version for plain C arrays
 */
template<typename T, size_t N>
inline uint32_t serializationLength(const T(&t)[N])
{
  return CArraySerializer<T, N>::serializedLength(t);
}

/**
 * \brief serialize version for kdl_msgs::util::array
 */
template<typename T, size_t N, typename Stream>
inline void serialize(Stream& stream, const kdl_msgs::util::array<T, N>& t)
{
  CArraySerializer<T, N>::write(stream, t);
}

/**
 * \brief deserialize version for kdl_msgs::util::array
 */
template<typename T, size_t N, typename Stream>
inline void deserialize(Stream& stream, kdl_msgs::util::array<T, N>& t)
{
  CArraySerializer<T, N>::read(stream, t);
}

/**
 * \brief serializationLength version for kdl_msgs::util::array
 */
template<typename T, size_t N>
inline uint32_t serializationLength(const kdl_msgs::util::array<T, N>& t)
{
  return CArraySerializer<T, N>::serializedLength(t);
}

} // namespace serialization
} // namespace ros

#endif // KDL_MSGS__ARRAY_H
