// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#ifndef DIALOG_EXAMPLE_H_
#define DIALOG_EXAMPLE_H_

#include <Wt/WApplication>
#include <Wt/WMessageBox>

using namespace Wt;

/**
 * \defgroup dialog Dialog example
 */
/*@{*/

/*! \brief An example illustrating usage of Dialogs
 */
class DialogExample : public WApplication
{
public:
  /*! \brief Create the example application.
   */
  DialogExample(const WEnvironment& env);

private:
  WMessageBox *messageBox_;
  WText *status;
  Wt::WHBoxLayout *textbox;
  
  void show();
  int p1x;
  int p1y;
  int p2x;
  int p2y;
};

/*@}*/

#endif // DIALOGEXAMPLE_H_
