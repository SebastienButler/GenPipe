/**
 * @file   abstract_block.hh
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Thu Jun 20 23:45:17 2013
 *
 * @brief  Abstract block: unit block interface
 *
 *
 */
#ifndef ABSTRACT_BLOCK_HH_
# define ABSTRACT_BLOCK_HH_

# include <memory>

/*
 * @brief Abstract block is the main interface for pipeline block.
 * A block is defined by at least one input class (IN1) and can be
 * completed by any other input class or output class (IN_OUT...)
 *
 */
template<class IN1, class... IN_OUT>
class AbstractBlock : public virtual IN1, public virtual IN_OUT...
{
 public:
  AbstractBlock() { }
  virtual ~AbstractBlock() { }
};




#endif //! ABSTRACT_BLOCK_HH_
