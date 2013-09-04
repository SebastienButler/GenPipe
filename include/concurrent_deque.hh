/**
 * @file   concurrent_deque.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Thu Jun 27 23:11:27 2013
 *
 * @brief  Concurrent deque
 *
 *
 */
#ifndef CONCURRENT_DEQUE
# define CONCURRENT_DEQUE

# include <iostream>
# include <thread>
# include <mutex>
# include <deque>

template <typename T>
class ConcurrentDeque : public std::deque<T>
{
public:
  ConcurrentDeque()
  {
  }

  virtual bool empty()
  {
    std::lock_guard<std::mutex> lock(_mutex);
    return _deque.empty();
  }

  virtual void push_back (const T& val)
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_back(val);
  }

  virtual void push_back (T&& val)
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_back(val);
  }

  virtual void push_front (const T& val)
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_front(val);
  }

  virtual void push_front (T&& val)
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.push_front(val);
  }

  virtual void pop_back()
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.pop_back();
  }

  virtual void pop_front()
  {
    std::lock_guard<std::mutex> lock(_mutex);
    _deque.pop_front();
  }

  virtual T& front()
  {
    std::lock_guard<std::mutex> lock(_mutex);
    return _deque.front();
  }

  virtual T& back()
  {
    std::lock_guard<std::mutex> lock(_mutex);
    return _deque.back();
  }

private:
  std::mutex	_mutex;
  std::deque<T> _deque;
};

#endif //! CONCURRENT_DEQUE
