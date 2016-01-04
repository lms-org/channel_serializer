# channel_serializer
LMS module that logs or loads generic data channels into a single file.

## Module channel_logger

Write a list of data channels into a file that is named after the current time.

### Config
- Writes a file named `channels.cereal` if `--enable-save` was used
- **dataChannels** - Comma-separated list of data channels that should be logged

Example XML config:
```xml
<module>
  <name>channel_logger</name>
  <config>
    <dataChannels>GREY_IMAGE,SENSEBOARD</dataChannels>
  </config>
</module>
```

## Module channel_loader

Load a file from a given absolute path and deserialize all data channels that were saved by the logger.

### Config
- Reads a file named `channels.cereal` if `--enable-load` was used

Example XML config:
```xml
<module>
  <name>channel_loader</name>
</module>
```

