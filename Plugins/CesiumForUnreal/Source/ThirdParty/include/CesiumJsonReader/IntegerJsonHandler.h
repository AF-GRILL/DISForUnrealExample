#pragma once

#include "JsonHandler.h"
#include "Library.h"

#include <cassert>

namespace CesiumJsonReader {
template <typename T>
class CESIUMJSONREADER_API IntegerJsonHandler : public JsonHandler {
public:
  IntegerJsonHandler() noexcept : JsonHandler() {}

  void reset(IJsonHandler* pParent, T* pInteger) {
    JsonHandler::reset(pParent);
    this->_pInteger = pInteger;
  }

  T* getObject() { return this->_pInteger; }

  virtual IJsonHandler* readInt32(int32_t i) override {
    assert(this->_pInteger);
    *this->_pInteger = static_cast<T>(i);
    return this->parent();
  }
  virtual IJsonHandler* readUint32(uint32_t i) override {
    assert(this->_pInteger);
    *this->_pInteger = static_cast<T>(i);
    return this->parent();
  }
  virtual IJsonHandler* readInt64(int64_t i) override {
    assert(this->_pInteger);
    *this->_pInteger = static_cast<T>(i);
    return this->parent();
  }
  virtual IJsonHandler* readUint64(uint64_t i) override {
    assert(this->_pInteger);
    *this->_pInteger = static_cast<T>(i);
    return this->parent();
  }

  virtual void reportWarning(
      const std::string& warning,
      std::vector<std::string>&& context) override {
    context.push_back("(expecting an integer)");
    this->parent()->reportWarning(warning, std::move(context));
  }

private:
  T* _pInteger = nullptr;
};
} // namespace CesiumJsonReader
