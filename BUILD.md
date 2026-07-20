# NeonLauncher Build Guide

## Prerequisites

### Windows
- Qt 6.x (with MSVC compiler)
- CMake 3.16+
- Visual Studio Build Tools

### macOS
- Qt 6.x
- CMake 3.16+
- Xcode Command Line Tools

### Linux
- Qt 6.x
- CMake 3.16+
- GCC or Clang

## Build Steps

### 1. Install Qt 6
Download from: https://www.qt.io/download-open-source

### 2. Clone Repository
```bash
git clone https://github.com/mohammedmk3900-rgb/NeonLauncher-Qt.git
cd NeonLauncher-Qt
```

### 3. Configure Build
```bash
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt6
```

**Replace `/path/to/Qt6` with your Qt installation path:**
- Windows: `C:\Qt\6.x\msvc2019_64`
- macOS: `/Users/username/Qt/6.x/macos`
- Linux: `/home/username/Qt/6.x/gcc_64`

### 4. Build Project
```bash
cmake --build build --config Release
```

### 5. Run Application
```bash
# Windows
build\Release\NeonLauncher.exe

# macOS/Linux
./build/NeonLauncher
```

## Troubleshooting

### Qt Not Found
```bash
cmake -B build -DCMAKE_PREFIX_PATH=$(find ~/ -name "Qt6Config.cmake" -type f | head -1 | xargs dirname | xargs dirname | xargs dirname)
```

### Build Errors
Clean and rebuild:
```bash
rm -rf build
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt6
cmake --build build --config Release
```

### Steam Games Not Detecting
- Ensure Steam is installed at default location
- Check `launcher.db` is created in build directory
- Review debug output in console

## Development Workflow

```bash
# Create new branch for features
git checkout -b feature/your-feature bugfix/core-issues

# After testing, create PR
git push origin feature/your-feature
```
