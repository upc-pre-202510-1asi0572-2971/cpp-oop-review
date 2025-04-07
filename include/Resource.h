#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

class Resource {
public:
    enum class Type { Consumable, Usable };
protected:
    std::string name;
    bool isAvailable;
    Type resourceType;
public:
  Resource(std::string name, Type type);
  virtual ~Resource() = default;
  std::string getName() const;
  virtual bool isAvailableForUse() const = 0;
  virtual void allocate() = 0;
  virtual void release() = 0;
  virtual void use() const = 0;
  Type getResourceType() const;
};
#endif //RESOURCE_H
