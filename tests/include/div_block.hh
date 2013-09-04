/**
 * @file   div_block.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Fri Jul 26 11:51:31 2013
 *
 * @brief Tests Block: div the data by a value
 *
 *
 */
#ifndef DIV_BLOCK_HH_
# define DIV_BLOCK_HH_

# include "abstract_block.hh"
# include "pipeline_input_queue.hh"
# include "pipeline_output.hh"

# include "display_block.hh"

namespace pipeline
{
  typedef PipeInQueue<int> IntQueueInput;
  typedef PipeOut<DisplayBlock, int> DisplayOutput;

  class DivBlock : public AbstractBlock<IntQueueInput,
					DisplayOutput>
  {
  public:
    DivBlock(int n,
	     DisplayBlock* dis)
      : _n (n)
    {
      setOutput(dis);
    }

    virtual ~DivBlock()
    {
    }

  public:
    void process(int data)
    {
      addOutput(data / _n);
    }

  private:
    int _n;
  };
}

#endif //! DIV_BLOCK_HH_
