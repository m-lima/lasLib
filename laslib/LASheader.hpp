#include <string>

using string = std::string;

struct LASHeader {

  struct NumberofPointsByReturn {
    static constexpr uint8_t MAX = 15;

    uint64_t & operator [](int i) {
      return value[i % MAX];
    }

    private:
    uint64_t value[15];
  };

  struct LegacyNumberOfPointRecordsByReturn {
    static constexpr uint8_t MAX = 5;

    uint64_t & operator [](int i) {
      return value[i % MAX];
    }

    private:
    uint64_t value[15];
  };

  static constexpr uint16_t MAX_BYTE_SIZE = 375;
  static constexpr uint8_t LEGACY_NUMBER_OF_POINT_RECORDS_BY_RETURN_SIZE = 5;
  static constexpr uint8_t NUMBER_OF_POINTS_BY_RETURN_SIZE = 15;

  string fileSignature = "LASF";
  uint16_t fileSourceID;
  uint16_t globalEncoding;
  uint32_t projectID1;
  uint16_t projectID2;
  uint16_t projectID3;
  string projectID4 = "";
  uint8_t versionMajor = 1;
  uint8_t versionMinor = 2;
  string systemIdentifier = "MFLima";
  string generatingSoftware = "MFLima PointCLoud";
  uint16_t fileCreationDayOfYear;
  uint16_t fileCreationYear;
  uint16_t headerSize = 227;
  uint32_t offsetToPointData = 227;
  uint32_t numberOfVariableLengthRecords;
  uint8_t pointDataRecordFormat;
  uint16_t pointDataRecordLength = 20;
  uint32_t legacyNumberOfPointRecords;
  LegacyNumberOfPointRecordsByReturn legacyNumberOfPointRecordsByReturn;
  double xScaleFactor = 1;
  double yScaleFactor = 1;
  double zScaleFactor = 1;
  double xOffset;
  double yOffset;
  double zOffset;
  double maxX;
  double minX;
  double maxY;
  double minY;
  double maxZ;
  double minZ;
  uint64_t startOfWaveformDataPacketRecord;
  uint64_t startOfFirstExtendedVariableLengthRecord;
  uint32_t numberOfExtendedVariableLengthRecords;
  uint64_t numberOfPointRecords;
  NumberofPointsByReturn numberOfPointsByReturn;

};
