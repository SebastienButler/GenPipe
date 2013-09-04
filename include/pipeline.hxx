/**
 * @file   pipeline.hxx
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Tue Jul  9 20:54:28 2013
 *
 * @brief  Implement template method from pipeline.hh
 *
 *
 */
#ifndef PIPELINE_HXX_
# define PIPELINE_HXX_

template <typename T>
inline void
Pipeline::run(std::shared_ptr<T> entry)
{
  std::thread th (&Pipeline::thread_run<T>, this, entry);
  th.detach();
}


template <typename T>
inline void
Pipeline::thread_run(std::shared_ptr<T> entry)
{
  entry->start();
  while (true)
  {

  }
}

#endif //! PIPELINE_HXX_










