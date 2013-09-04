/**
 * @file   pipeline_output.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Thu Jun 27 23:35:34 2013
 *
 * @brief  Abstract class: interface for block output
 *
 *
 */
#ifndef PIPELINE_OUTPUT_HH_
# define PIPELINE_OUTPUT_HH_

# include "pipeline_input.hh"

namespace pipeline
{
  /**
   * @brief PipeOut defined block output.
   * To be usefull, you have to use setOutput to set
   * the next block to fill.
   *
   */
  template <typename U, typename T>
  class PipeOut
  {
  public:
    PipeOut()
    {
    }

    virtual ~PipeOut()
    {
    }

    /**
     * Connect the output to an other block input
     *
     * @param in input block
     */
    virtual void setOutput(U* in)
    {
      _in = in;
    }

    /**
     * Implement addOutput, add data to `_in' input.
     *
     * @param data
     */
    virtual void addOutput(T data)
    {
      _in->addInput(data);
      _in->start();
    }

  private:
    U* _in;
  };

} //! namespace pipeline

#endif //! PIPELINE_OUTPUT_HH_
