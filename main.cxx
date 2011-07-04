#include <cstdlib>
#include <iostream>
#include <string>
#include <boost/bind.hpp>

#include "power_control.h"
#include "blender.h"
#include "toaster.h"
#include "oven.h"

using namespace std;

int main(int argc, char **argv){

  cout << "Welcome to the \"Multi Power Point.\"" << endl;
  cout << endl;

  PowerControl powerControl;

  Blender blender;
  const string blenderName("Big Red Blender");
  cout << "Plugging in my " << blenderName << endl;
  powerControl.subscribe( blenderName , boost::bind( &Blender::swizzle, &blender ), boost::bind( &Blender::stopSwizzle, &blender ) );

  Toaster toaster;
  const string toasterName("Shiny Chrome Toaster");
  cout << "Plugging in my " << toasterName << endl;
  powerControl.subscribe( toasterName, boost::bind( &Toaster::startToasting, &toaster ), boost::bind( &Toaster::cancelBurntToast, &toaster ) );

  Oven oven;
  const string ovenName("Powerful Double Oven");
  cout << "Plugging in my " << ovenName << endl;
  powerControl.subscribe( ovenName, boost::bind( &Oven::heatUp, &oven ), boost::bind( &Oven::coolDown, &oven ) );

  cout << endl;
  cout << "Hit the on switch" << endl;

  // turn on everything that subscribed
  powerControl.on();

  cout << endl;
  cout << "Hit the off switch" << endl;

  // turn on everything that subscribed
  powerControl.off();

  cout << endl;
  cout << "Unplugging my " << toasterName << endl;
  powerControl.unsubscribe( toasterName );

  cout << endl;
  cout << "Hit the on switch" << endl;

  // turn on everything that subscribed
  powerControl.on();

  cout << endl;
  cout << "Hit the off switch" << endl;

  // turn on everything that subscribed
  powerControl.off();

  return EXIT_SUCCESS;
}
