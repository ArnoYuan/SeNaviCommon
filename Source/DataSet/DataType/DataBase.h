/*
 * DataBase.h
 *
 *  Created on: 2016年9月14日
 *      Author: seeing
 */

#ifndef _DATATYPE_DATABASE_H_
#define _DATATYPE_DATABASE_H_

#include "Serialization/Serialization.h"

namespace NS_DataType
{
  class DataBase
  {
  public:
    typedef boost::shared_ptr<DataBase> Ptr;
    typedef boost::shared_ptr<DataBase const> ConstPtr;
    DataBase ()
    {
    }
    ;
    virtual
    ~DataBase ()
    {
    }
    ;
  public:
    virtual uint32_t serializationLength() const = 0;
    virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const = 0;
    virtual uint8_t *deserialize(uint8_t *read_ptr) = 0;

  };

} /* namespace NS_NaviCommon */

#endif /* _DATABASE_H_ */
