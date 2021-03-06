// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "Asset.h"
#include "Library.h"
#include "Properties.h"
#include "Tile.h"

#include <CesiumUtility/ExtensibleObject.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace Cesium3DTiles {
/**
 * @brief A 3D Tiles tileset.
 */
struct CESIUM3DTILES_API Tileset final
    : public CesiumUtility::ExtensibleObject {
  static inline constexpr const char* TypeName = "Tileset";

  /**
   * @brief Metadata about the entire tileset.
   */
  Asset asset;

  /**
   * @brief A dictionary object of metadata about per-feature properties.
   */
  std::unordered_map<std::string, Properties> properties;

  /**
   * @brief The error, in meters, introduced if this tileset is not rendered. At
   * runtime, the geometric error is used to compute screen space error (SSE),
   * i.e., the error measured in pixels.
   */
  double geometricError = double();

  /**
   * @brief The root tile.
   */
  Tile root;

  /**
   * @brief Names of 3D Tiles extensions used somewhere in this tileset.
   */
  std::vector<std::string> extensionsUsed;

  /**
   * @brief Names of 3D Tiles extensions required to properly load this tileset.
   */
  std::vector<std::string> extensionsRequired;
};
} // namespace Cesium3DTiles
