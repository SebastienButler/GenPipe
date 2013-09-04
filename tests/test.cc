/**
 * @file   test.cc
 * @author Sébastien Butler <sebastien.butler@gmail.com>
 * @date   Fri Jul 26 14:22:27 2013
 *
 * @brief  Test of a generic pipeline.
 * Here we have a useless test: if input is even, we add 1 and we display it else we divise it by 3 and display it.
 * The pipeline constructs here look like this:
 *
 *  /=====\  if not even  /=====\
 *  | ADD |  -----------> | DIV |
 *  \=====/               \=====/
 *     |      /=========\    |
 *     |----> | DISPLAY | <--|
 *            \=========/
 *
 * The idea behind this awesome test is to show how to construct a pipeline using a threaded process queue in input
 * and how to connect blocks to each other (with several ouputs for `Addblock')
 *
 *
 */

# include <memory>

# include "display_block.hh"
# include "add_block.hh"
# include "div_block.hh"

# include "pipeline.hh"

using namespace pipeline;

int main()
{
  DisplayBlock display;
  DivBlock div(3, &display);
  std::shared_ptr<AddBlock> add = std::make_shared<AddBlock> (1, &display, &div);

  Pipeline pipe;
  pipe.run(add);

  add->addInput(0);
  add->addInput(1);
  add->addInput(2);
  add->addInput(3);
  add->addInput(4);
  add->addInput(5);
  while (true);
}
