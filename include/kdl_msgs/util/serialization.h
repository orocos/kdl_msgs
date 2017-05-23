/* Copied and adapted from ros/serialization.h: */
/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef KDL_MSGS_UTIL_SERIALIZATION_H
#define KDL_MSGS_UTIL_SERIALIZATION_H

#include <ros/serialization.h>
#include <boost/function.hpp>

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
 * \brief Plain C vector serializer.  Default implementation does nothing
 */
template<typename T, class Enabled = void>
struct CVectorSerializer
{};

/**
 * \brief Plain C vector, specialized for non-fixed-size, non-simple types
 */
template<typename T>
struct CVectorSerializer<T, typename boost::disable_if<mt::IsFixedSize<T> >::type >
{
  typedef T* IteratorType;
  typedef const T* ConstIteratorType;
  typedef boost::function<T*(std::size_t)> ResizeFcn;

  template<typename Stream>
  inline static void write(Stream& stream, const T* v, const std::size_t size)
  {
    stream.next((uint32_t)size);
    ConstIteratorType it = v;
    ConstIteratorType end = v + size;
    for (; it != end; ++it)
    {
      stream.next(*it);
    }
  }

  template<typename Stream>
  inline static std::size_t read(Stream& stream, T* v, const std::size_t max_size, const ResizeFcn& resize_fcn = ResizeFcn())
  {
    uint32_t len;
    stream.next(len);
    if ((std::size_t)len > max_size) {
      if (resize_fcn) {
        v = resize_fcn(len);
      } else {
        throw StreamOverrunException("Target vector cannot store the required number of elements");
      }
    }

    IteratorType it = v;
    IteratorType end = v + len;
    for (; it != end; ++it)
    {
      stream.next(*it);
    }
    if (resize_fcn) resize_fcn(len);

    return (std::size_t)len;
  }

  inline static uint32_t serializedLength(const T* v, const std::size_t _size)
  {
    uint32_t size = 4;
    ConstIteratorType it = v;
    ConstIteratorType end = v + _size;
    for (; it != end; ++it)
    {
      size += serializationLength(*it);
    }

    return size;
  }
};

/**
 * \brief Plain C vector, specialized for fixed-size simple types
 */
template<typename T>
struct CVectorSerializer<T, typename boost::enable_if<mt::IsSimple<T> >::type >
{
  typedef T* IteratorType;
  typedef const T* ConstIteratorType;
  typedef boost::function<T*(std::size_t)> ResizeFcn;

  template<typename Stream>
  inline static void write(Stream& stream, const T* v, const std::size_t size)
  {
    uint32_t len = (uint32_t)size;
    stream.next(len);
    if (size > 0)
    {
      uint32_t data_len = len * (uint32_t)sizeof(T);
      memcpy(stream.advance(data_len), v, data_len);
    }
  }

  template<typename Stream>
  inline static std::size_t read(Stream& stream, T* v, const std::size_t max_size, const ResizeFcn& resize_fcn = ResizeFcn())
  {
    uint32_t len;
    stream.next(len);
    if ((std::size_t)len > max_size) {
      if (resize_fcn) {
        v = resize_fcn(len);
      } else {
        throw StreamOverrunException("Target vector cannot store the required number of elements");
      }
    }

    if (len > 0)
    {
      const uint32_t data_len = (uint32_t)sizeof(T) * len;
      memcpy(v, stream.advance(data_len), data_len);
    }
    if (resize_fcn) resize_fcn(len);

    return (std::size_t)len;
  }

  inline static uint32_t serializedLength(const T* v, const std::size_t size)
  {
    return 4 + size * (uint32_t)sizeof(T);
  }
};

/**
 * \brief Plain C vector, specialized for fixed-size non-simple types
 */
template<typename T>
struct CVectorSerializer<T, typename boost::enable_if<mpl::and_<mt::IsFixedSize<T>, mpl::not_<mt::IsSimple<T> > > >::type >
{
  typedef T* IteratorType;
  typedef const T* ConstIteratorType;
  typedef boost::function<T*(std::size_t)> ResizeFcn;

  template<typename Stream>
  inline static void write(Stream& stream, const T* v, const std::size_t size)
  {
    stream.next((uint32_t)size);
    ConstIteratorType it = v;
    ConstIteratorType end = v + size;
    for (; it != end; ++it)
    {
      stream.next(*it);
    }
  }

  template<typename Stream>
  inline static std::size_t read(Stream& stream, T* v, const std::size_t max_size, const ResizeFcn& resize_fcn = ResizeFcn())
  {
    uint32_t len;
    stream.next(len);
    if ((std::size_t)len > max_size) {
      if (resize_fcn) {
        v = resize_fcn(len);
      } else {
        throw StreamOverrunException("Target vector cannot store the required number of elements");
      }
    }

    IteratorType it = v;
    IteratorType end = v + len;
    for (; it != end; ++it)
    {
      stream.next(*it);
    }
    if (resize_fcn) resize_fcn(len);

    return (std::size_t)len;
  }

  inline static uint32_t serializedLength(const T* v, const std::size_t _size)
  {
    uint32_t size = 4;
    if (_size > 0)
    {
      uint32_t len_each = serializationLength(*v);
      size += len_each * (uint32_t)_size;
    }

    return size;
  }
};

/**
 * \brief serialize version for plain C vector-like types
 */
template<typename T, typename Stream>
inline void serialize(Stream& stream, const T* t, const std::size_t size)
{
  CVectorSerializer<T>::write(stream, t, size);
}

/**
 * \brief deserialize version for plain C vector-like types
 */
template<typename T, typename Stream>
inline std::size_t deserialize(Stream& stream, T* t, const std::size_t max_size,
                               const typename CVectorSerializer<T>::ResizeFcn& resize_fcn = typename CVectorSerializer<T>::ResizeFcn())
{
  return CVectorSerializer<T>::read(stream, t, max_size, resize_fcn);
}

/**
 * \brief serializationLength version for plain C vector-like types
 */
template<typename T>
inline uint32_t serializationLength(const T* t, const std::size_t size)
{
  return CVectorSerializer<T>::serializedLength(t, size);
}

} // namespace serialization
} // namespace ros

#endif // KDL_MSGS_UTIL_SERIALIZATION_H
