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
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

namespace NS_DataSet
{
  using namespace boost::interprocess;

  typedef enum
  {
    DATASET_IDLE,
    DATASET_PROCESSING,
  }DataSetStatus;

  typedef struct
  {
    boost::interprocess::interprocess_mutex lock;
    boost::interprocess::interprocess_condition req_cond;
    boost::interprocess::interprocess_condition rep_cond;
    DataSetStatus status;

    size_t buf_len;
  }DataSetOperation;

  class DataSetName
  {
    std::string name;
  };

  typedef allocator<DataSetName, managed_shared_memory::segment_manager>  DataSetNameAllocator;

  typedef vector<DataSetName, DataSetNameAllocator> DataSetNameVector;

  bool setup ()
  {
    bool result = true;
    try
    {
      shared_memory_object::remove("DATASET");

      managed_shared_memory segment(create_only, "DATASET", 65536);
      const DataSetNameAllocator alloc_inst (segment.get_segment_manager());
      DataSetNameVector *dataset_names = segment.construct<DataSetNameVector>("DATASETNAMES")(alloc_inst);

    }catch (std::exception &e)
    {
      shared_memory_object::remove("DATASET");
      result = false;
    }

    return result;

  }

  bool note (std::string name)
  {
    bool result = true;
    try
    {
      managed_shared_memory segment(open_only, "DATASET", 65536);
      const DataSetNameAllocator alloc_inst (segment.get_segment_manager());
      DataSetNameVector *dataset_names = segment.find<DataSetNameVector>("DATASETNAMES").first;

      bool exist = false;
      for (int j = 0; j < dataset_names->size(); j++)
      {
        if ((*dataset_names)[j].name == name)
        {
          exist = true;
        }
      }

      if (!exist)
      {
        DataSetName item;
        item.name = name;
        dataset_names->push_back (item);
      }


    }catch (std::exception &e)
    {
      result = false;
    }

  }

  bool cleanup ()
  {

  }

}

#endif /* DATASET_DATASET_H_ */
