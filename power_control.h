#ifndef POWER_CONTROL_H
#define POWER_CONTROL_H

#include <map>
#include <string>
#include <boost/function.hpp>

using namespace std;

class PowerControl {
 public:
  // subsctibe to the power control
  bool subscribe(const string &key, boost::function< void() > onFunction, boost::function< void() > offFunction);
  
  // unsubscribe
  bool unsubscribe(const string &key);

  void on(); // turn on everything
  void off(); // turn off everything

 private:
  map< const string, boost::function< void() > > m_on;
  map< const string, boost::function< void() > > m_off;

};

#endif // POWER_CONTROL_H 
