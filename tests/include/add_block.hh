/**
 * @file   add_block.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Fri Jul 26 11:40:27 2013
 *
 * @brief  Tests block: add n to a value
 *
 *
 */
#ifndef ADD_BLOCK_HH_
# define ADD_BLOCK_HH_

# include "abstract_block.hh"
# include "pipeline_input_queue.hh"
# include "pipeline_output.hh"

# include "display_block.hh"
# include "div_block.hh"

namespace pipeline
{
  // Input using "pipeline_input_queue.hh"
  typedef PipeInQueue<int> IntQueueInput;
  // Outputs
  typedef PipeOut<DisplayBlock, int> DisplayOutput;
  typedef PipeOut<DivBlock, int> DivOutput;

  class AddBlock : public AbstractBlock<IntQueueInput,
					DisplayOutput,
					DivOutput>
  {
  public:
    AddBlock(int n,
	     DisplayBlock* dis,
	     DivBlock* div)
      : _n (n)
    {
      DisplayOutput::setOutput(dis);
      DivOutput::setOutput(div);
    }

    virtual ~AddBlock()
    {
    }

  public:
    void process(int data)
    {
      if (data % 2 == 0)
      {
	++data;
	DisplayOutput::addOutput(data);
      }
      else
	DivOutput::addOutput(data);
    }

  private:
    int _n;
  };
}

#endif //! ADD_BLOCK_HH_
