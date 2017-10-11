/*
 * ServiceBase.h
 *
 *  Created on: 2016年9月21日
 *      Author: seeing
 */

#ifndef _SERVICEBASE_H_
#define _SERVICEBASE_H_

namespace NS_ServiceType
{

  class ServiceBase
  {
  public:
    ServiceBase()
    {
    }
    ;
    virtual ~ServiceBase()
    {
    }
    ;

    bool result;

    virtual uint32_t
    serializationLength() const = 0;
    virtual uint8_t *
    serialize(uint8_t *write_ptr, uint32_t seq) const = 0;
    virtual uint8_t *
    deserialize(uint8_t *read_ptr) = 0;
  };

} /* namespace NS_NaviCommon */

#endif /* _SERVICEBASE_H_ */
