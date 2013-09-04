/**
 * @file   pipeline_input_queue.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Thu Jun 27 23:05:30 2013
 *
 * @brief  Pipeline entry: use a thread queue to process input.
 *
 *
 */
#ifndef PIPELINE_INPUT_QUEUE_HH_
# define PIPELINE_INPUT_QUEUE_HH_

# include <memory>
# include <thread>
# include <vector>

# include "concurrent_deque.hh"
# include "pipeline_input.hh"

namespace pipeline
{

  /**
   * @brief PipeInQueue implement PipeIn interface.
   * It use a concurrent deque to buffer the block input.
   *
   *
   */
  template <typename T>
  class PipeInQueue : public PipeIn<T>
  {
  public:
    PipeInQueue(unsigned int nbWorkersMax = 1)
      : _nbWorkersMax(nbWorkersMax),
	_nbWorkers(0)
    {
    }

    virtual ~PipeInQueue()
    {
    }

  public:
    /**
     * Start to process queue
     *
     */
    void start()
    {
      if (_nbWorkers < _nbWorkersMax)
      {
	_workersReady.push_back(true);
	_workerThreads.push_back(std::thread(&PipeInQueue<T>::processQueue,
					     this,
					     _nbWorkers));
	++_nbWorkers;
      }
    }

    /**
     * @brief add data to the concurrent deque
     *
     * @param data data
     */
    virtual void addInput(T data)
    {
      _deque.push_front(data);
    }

    /**
     * @brief Process the concurrent deque
     *
     */
    void processQueue(unsigned int id)
    {
      while (_workersReady[id])
      {
	if (_deque.empty())
	  continue;

	T data (_deque.back());
	_deque.pop_back();
	process(data);
      }
    }

    /**
     * Redefinition of process: g++-4.7 no longer performs some
     * extra unqualified lookups (see [http://gcc.gnu.org/gcc-4.7/porting_to.html])
     *
     */
    virtual void process(T data) = 0;

  private:
    ConcurrentDeque<T>		 _deque;
    std::vector<std::thread>	 _workerThreads;
    std::vector<bool>		 _workersReady;
    unsigned int		 _nbWorkersMax;
    unsigned int		 _nbWorkers;
  };

}

#endif //! PIPELINE_INPUT_QUEUE_HH_
