/**
 * @file   display_block.hh
 * @author Sébastien Butler <sebastien.butler@ge.com>
 * @date   Fri Jul 26 14:19:10 2013
 *
 * @brief  Tests block: display data
 *
 *
 */
#ifndef DISPLAY_BLOCK_HH_
# define DISPLAY_BLOCK_HH_

# include "abstract_block.hh"
# include "pipeline_input_queue.hh"

# include <iostream>

namespace pipeline
{
  typedef PipeInQueue<int> IntQueueInput;

  class DisplayBlock : public AbstractBlock<IntQueueInput>
  {
  public:
    DisplayBlock()
    {
    }

    virtual ~DisplayBlock()
    {
    }

  public:
    void process(int data)
    {
      std::cout << "Display: " << data << std::endl;
    }
  };
}

#endif //! DISPLAY_BLOCK_HH_
