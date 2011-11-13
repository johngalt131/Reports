/*
 * Record.h
 *
 *  Created on: Nov 6, 2011
 *      Author: travisstaley
 */

#ifndef RECORD_H_
#define RECORD_H_

class Record {
 public:
  Record();
  virtual ~Record();
  
  virtual void addRecord() = 0;
  
 private:
};

#endif /* RECORD_H_ */
