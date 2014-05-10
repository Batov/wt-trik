/*
 * Copyright (C) 2008 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */
#include <iostream>

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WEnvironment>
#include <Wt/WLineEdit>
#include <Wt/WMessageBox>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WHBoxLayout>
#include <Wt/WVBoxLayout>
#include <Wt/WTemplate>
#include <Wt/WSlider>
#include <functional>


#include "DialogExample.h"

using namespace Wt;

DialogExample::DialogExample(const WEnvironment& env)
  : WApplication(env),
    messageBox_(0)
{
  setTitle("Trik's Control Panels"); 

  WContainerWidget *buttons = new WContainerWidget(root());
  buttons->setStyleClass("buttons");

  WPushButton *button;

  Wt::WVBoxLayout *mbox     = new Wt::WVBoxLayout();
  textbox  = new Wt::WHBoxLayout();

  Wt::WHBoxLayout *hbox  = new Wt::WHBoxLayout();
  Wt::WVBoxLayout *vboxf = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *vboxs = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *vboxt = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *space = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *vboxf2 = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *vboxs2 = new Wt::WVBoxLayout();
  Wt::WVBoxLayout *vboxt2 = new Wt::WVBoxLayout();

  p1x = 0;
  p1y = 0;
  p2x = 0;
  p2y = 0;

  
  mbox->addLayout(hbox);
  mbox->addLayout(textbox);


  buttons->setLayout(mbox);
  hbox->addLayout(vboxf);
  hbox->addLayout(vboxs);
  hbox->addLayout(vboxt);
  hbox->addLayout(space);
  hbox->addLayout(vboxf2);
  hbox->addLayout(vboxs2);
  hbox->addLayout(vboxt2);
  
  status = new WText("");
  status->setText("by Batov Nikita");
  
  textbox->addWidget(status);

  button = new WPushButton("=");
  vboxf->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x>-100) p1x -= 20; if (p1y<100) p1y += 20; show(); }));

  button = new WPushButton("Left");
  vboxf->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x>-100) p1x -= 20;  show(); }));

  button = new WPushButton("=");
  vboxf->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x>-100) p1x -= 20; if (p1y>-100) p1y -= 20; show(); }));

  button = new WPushButton("Up");
  vboxs->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1y<100) p1y += 20; show(); }));
 
  button = new WPushButton("STOP");
  vboxs->addWidget(button);
  button->clicked().connect(std::bind([=]() { p1x = 0; p1y = 0; show(); }));

  button = new WPushButton("Down");
  vboxs->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1y>-100) p1y -= 20; show(); }));

  button = new WPushButton("=");
  vboxt->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x<100) p1x += 20; if (p1y<100) p1y += 20; show(); }));
  
  button = new WPushButton("Right");
  vboxt->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x<100) p1x += 20;  show(); }));

  button = new WPushButton("=");
  vboxt->addWidget(button);
  button->clicked().connect(std::bind([=]() { if (p1x<100) p1x += 20; if (p1y>-100) p1y -= 20; show(); }));
//----------------------------------
  button = new WPushButton("1");
  space->addWidget(button);
  button->clicked().connect(std::bind([=]() { system("echo 1 > /sys/class/leds/led_green/brightness"); }));

  button = new WPushButton("2");
  space->addWidget(button);
  button->clicked().connect(std::bind([=]() { system("echo 0 > /sys/class/leds/led_green/brightness"); }));

  button = new WPushButton("3");
  space->addWidget(button);
  button->clicked().connect(std::bind([=]() { system("echo 1 > /sys/class/leds/led_red/brightness"); }));

  button = new WPushButton("4");
  space->addWidget(button);
  button->clicked().connect(std::bind([=]() { system("echo 0 > /sys/class/leds/led_red/brightness"); }));

  button = new WPushButton("5");
  space->addWidget(button);

//----------------------------------
  button = new WPushButton("=");
  vboxf2->addWidget(button);

  button = new WPushButton("Left");
  vboxf2->addWidget(button);

  button = new WPushButton("=");
  vboxf2->addWidget(button);

  button = new WPushButton("Up");
  vboxs2->addWidget(button);
 
  button = new WPushButton("STOP");
  vboxs2->addWidget(button);

  button = new WPushButton("Down");
  vboxs2->addWidget(button);

  button = new WPushButton("=");
  vboxt2->addWidget(button);
  
  button = new WPushButton("Right");
  vboxt2->addWidget(button);

  button = new WPushButton("=");
  vboxt2->addWidget(button);

  styleSheet().addRule(".buttons",
		       "padding: 20px;");
  styleSheet().addRule(".buttons BUTTON",
		       "padding-left: 4px; padding-right: 4px;"
		       "margin-top: 4px; display: block");

  // avoid scrollbar problems
  styleSheet().addRule(".text", "padding: 4px 8px");
  styleSheet().addRule("body", "margin: 0px;");

}


void DialogExample::show()
{
 
  char buffer [50];
  sprintf (buffer, " X1 = %d | Y1 = %d || X2 = %d | Y2 = %d" , p1x, p1y, p2x, p2y);
  status->setText(buffer);
}


WApplication *createApplication(const WEnvironment& env)
{
  return new DialogExample(env);
}

int main(int argc, char **argv)
{
   return WRun(argc, argv, &createApplication);
}

