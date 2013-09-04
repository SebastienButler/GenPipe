/**
 * @file   pipeline_input.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Fri Jun 21 00:11:59 2013
 *
 * @brief  Abstract class: interface for block entry
 *
 *
 */
#ifndef PIPELINE_INPUT_HH_
# define PIPELINE_INPUT_HH_

# include <memory>

namespace pipeline
{

  /**
   * @brief PipeIn is an interface defining block input.
   * It defined `addInput' and `process'.
   *
   */
  template <typename T>
  class PipeIn
  {
  public:
    PipeIn() { }
    virtual ~PipeIn() {}

  public:
    /**
     * @brief addInput add data to the block input
     *
     * @param data data
     */
    virtual void addInput(T data) = 0;

    /**
     * @brief process is the method to call to do the process in a block
     *
     * @param data data
     */
    virtual void process(T data) = 0;
  };

}

#endif //! PIPELINE_INPUT_HH_
