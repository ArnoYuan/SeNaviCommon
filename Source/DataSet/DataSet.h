/*
 * DataSet.h
 *
 *  Created on: Sep 6, 2017
 *      Author: root
 */

#ifndef _DATASET_H_
#define _DATASET_H_

#include <map>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>

namespace NS_DataSet
{
  using namespace boost::interprocess;

  typedef enum
  {
    DATASET_IDLE,
    DATASET_PROCESSING,
  } DataSetStatus;

  typedef struct
  {
    boost::interprocess::interprocess_mutex lock;
    boost::interprocess::interprocess_condition req_cond;
    boost::interprocess::interprocess_condition rep_cond;
    DataSetStatus status;

    size_t buf_len;
  } DataSetOperation;

}

#endif /* DATASET_DATASET_H_ */
