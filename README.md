# channel_serializer
LMS module that logs or loads generic data channels into a single file.

## Module channel_logger

Write a list of data channels into a file that is named after the current time.

### Config
- **directory** - The logging file will be created in this directory.
- **dataChannels** - Comma-separated list of data channels that should be logged

Example XML config:
```xml
<module>
  <name>channel_logger</name>
  <config>
    <directory>/tmp</directory>
    <dataChannels>GREY_IMAGE,SENSEBOARD</dataChannels>
  </config>
</module>
```

## Module channel_loader

Load a file from a given absolute path and deserialize all data channels that were saved by the logger.

### Config
- **file** - absolute path to the file that should be loaded

Example XML config:
```xml
<module>
  <name>channel_loader</name>
  <config>
    <file>/tmp/20150529-124733.cereal</file>
  </config>
</module>
```

