/**
 * @file   pipeline.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Tue Jul  9 20:52:12 2013
 *
 * @brief  Manage processing pipeline
 *
 *
 */
#ifndef PIPELINE_HH_
# define PIPELINE_HH_

# include <memory>

namespace pipeline
{

  class Pipeline
  {
  public:
    Pipeline()
    {
    }
    ~Pipeline()
    {
    }

  public:
    template <typename T>
    void run(std::shared_ptr<T> entry);

  private:
    template <typename T>
    void thread_run(std::shared_ptr<T> entry);

  };

# include "pipeline.hxx"

} // end namespace pipeline

#endif //! PIPELINE_HH_
