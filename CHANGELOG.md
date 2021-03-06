# ChangeLog

## [10.1.0-rc3] - 2020-12-02
### Changed
- Log: enhance FileSink synchronisation

### Fixed
- WolfLauncher: fix log file format for a configurated DFIR-Orc
- Log: add support for SPDLOG_LEVEL env variable
- Values incorrectly displayed as addresses instead of readable strings
- Outline: missing 'qfe', 'network', 'environment' sections
- GetSectors: failure when no disk was specified
- Column filter processing inserting some empty lines (',,,,,,,,,,,,,,,')
- GetThis: fix compression level

### Added
- WolfLauncher: print a 'Ended' line in the journal with statistics

### Removed
- Dead code: ByteStreamSink

## [10.1.0-rc2] - 2020-11-20
### Changed
- Column 'ParentName': remove trailing '\'
- Autorunsc: use UTC time format
- vcpkg: update spdlog to v1.8.1

### Fixed
- Parsing issue on some MFT
- Output: fix 7z creation causing crashes
- Log: format system errors as unsigned hex values
- Log: option 'StdOutErr' will now properly includes 'stderr' output
- Log: move many errors from 'Error' level to 'Critical'
- Log: fix shadowed formatters causing some unformatted output value
- Console: fix unformatted output value of 'filters' parameter
- Option: partially ignored options '/Computer', '/FullComputer', '/SystemType'
- OrcApache: calling convention mismatch on x86 causing crashes

### Added
- Usage: add missing usage options
- WolfLauncher: print real file size for compressed items
- WolfLauncher: print archive size once completed
- WolfLauncher: print file size for queued upload items

### Removed
- Dead code: 'OutputFileOption', 'OutputDirOption'

## [10.1.0-rc1] - 2020-11-09

### Changed
- GetThis: reduce memory usage by a factor of 3 depending on configuration
- GetThis: major refactor to allow some future optmizations
- Log: split stdout and stderr data
- Log: use spdlog log library
- Log: dump log backtrace on critical errors
- Log: use new log levels
- Log: add utc timestamps (ISO 8601)
- Improve DFIR-Orc temporary directory removal
- OrcCommand: major refactor
- README: add license section
- vcpkg: update to 2020.11-1

### Fixed
- GetThis: segfault when hash xml element is empty #69
- GetThis: do not make hash if they are not configured #67
- GetThis: segfault with MaxSampleCount=0 and reportall/hash options #8
- Log: catch early logs in log files
- vcpkg: fix shared build
- ... Check commit for a complete list of other fixes

### Added
- Outline: Add '/Outline' cli option
- Build: Add compatibility with clang and llvm tools
- Build: Add compatibility with ninja
- Build: Add compatibility with VS 2019 16.8
- Build: Add option ORC_BUILD_BOOST_STACKTRACE
- Build: Enhance tools/ci/build.ps1 script
- Add support archive hierarchies in resources
- CI: Azure: Add support for Azure Artifacts

### Removed
- Remove ImportData tool
- Remove ChakraCore component
- Remove OrcSql component
- Remove dead code

## [10.0.16] - 2020-11-09
### Added
- CI: Azure: add support for release/* branches
- SystemDetails: add 'Windows' and 'RTM' tag for pre-Win10 versions
- NtfsInfo: add SecurityDirectorySize and SecurityDirectorySignatureSize

### Fixed
- CsvFileWriter: fix memory corruption

## [10.0.15] - 2020-09-28
### Added
- New 'Location' configuration keyword: '{UserProfiles}' (get profiles directories from HKLM/SOFTWARE/Microsoft/Windows NT/CurrentVersion/ProfileList)

### Fixed
- BITS: Archive were skipped when BITS server was unavailable
- CSV: Two possible csv corruptions
