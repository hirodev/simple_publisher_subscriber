#include <iostream>
#include "power_control.h"

using namespace boost;

bool PowerControl::subscribe(const string &key, function< void() > onFunction, function< void() > offFunction){

  // does the key exist already
  if( m_on.find( key ) != m_on.end() || m_off.find( key ) != m_off.end() ){
    return false;
  }

  m_on[ key ] = onFunction;
  m_off[ key ] = offFunction;

  return true;
}

// remove the on and off functions subscribed
bool PowerControl::unsubscribe(const string &key){
  bool unsubscribed = false;

  map< const string, function< void() > >::iterator subscribedIter;

  subscribedIter = m_on.find( key );
  if( subscribedIter != m_on.end() ){
    m_on.erase( subscribedIter );
    unsubscribed = true;
  }

  subscribedIter = m_off.find( key );
  if( subscribedIter != m_off.end() ){
    m_off.erase( subscribedIter );
    unsubscribed = true;
  }

  return unsubscribed;
}

void PowerControl::on(){
  map< const string, function< void() > >::const_iterator onIter;
  
  for(onIter = m_on.begin(); onIter != m_on.end(); ++onIter){
    cout << "Turning on " << onIter->first << endl;
    (onIter->second)(); // call the power on function
  }
}

void PowerControl::off(){
  map< const string, function< void() > >::const_iterator offIter;
  
  for(offIter = m_off.begin(); offIter != m_off.end(); ++offIter){
    cout << "Turning off " << offIter->first << endl;
    (offIter->second)(); // call the power off function
  }
}
