# Build Troubleshooting Guide

## Common Build Errors & Solutions

### ❌ Error: "Qt6 not found"
```
CMake Error: Could not find a package configuration file provided by "Qt6"
```

**حل:**
```bash
# یک: مسیر Qt را مشخص کن
cmake -B build -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"

# دو: یا استفاده از Qt Creator
# وارد "Configure project" شو و CMake presets اصلاح کن
```

---

### ❌ Error: "qml module not found"
```
No module named 'NeonLauncher' found
```

**حل:**
```bash
# 1. اطمینان حاصل کن که QML_FILES در CMakeLists.txt درست هستند
# 2. Clean build انجام بده:
rm -rf build
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt6
cmake --build build --config Release
```

---

### ❌ Error: "MSVC compiler not found" (Windows)
```
MSVC compiler not found
```

**حل:**
```bash
# 1. Visual Studio Build Tools را نصب کن
# 2. یا استفاده از Qt Creator کن
# 3. یا Command Prompt Visual Studio را باز کن:
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cmake -B build -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"
```

---

### ❌ Error: "Database initialization failed"
```
Database failed: unable to open database file
```

**حل:**
```bash
# 1. مطمئن شو که دایرکتوری build قابل نوشتن است
# 2. وقتی برنامه اجرا می‌شود، launcher.db درست می‌شود
# 3. اگر هنوز مشکل داری:
chmod 777 build/  # Linux/macOS
```

---

### ❌ Error: "Steam not found"
```
Steam folder not found at: C:/Program Files (x86)/Steam/steamapps
```

**حل:**
- اگر Steam در مسیر مختلفی نصب است، مسیر را تغییر بده
- یا مطمئن شو که Steam نصب شده است

---

### ❌ Error: "CMAKE_CXX_COMPILER not specified"
```
CMAKE_CXX_COMPILER not set
```

**حل:**
```bash
# Windows:
cmake -B build -DCMAKE_CXX_COMPILER=cl -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"

# Linux:
cmake -B build -DCMAKE_CXX_COMPILER=g++ -DCMAKE_PREFIX_PATH=/path/to/Qt6

# macOS:
cmake -B build -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_PREFIX_PATH=/Users/username/Qt/6.5.0/macos
```

---

### ❌ Error: "Linker error: unresolved external symbols"
```
LNK2001: unresolved external symbol
```

**حل:**
```bash
# 1. تمام فایل‌های .cpp و .h درست اضافه شده اند
# 2. CMakeLists.txt را بررسی کن:
#    - GameModel.cpp و GameModel.h اضافه شده
#    - تمام Qt components linked هستند

# 3. Clean rebuild:
rm -rf build
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt6
cmake --build build --config Release
```

---

## ✅ Build & Run (Windows)

```bash
# 1. Configure
cmake -B build -DCMAKE_PREFIX_PATH="C:\Qt\6.5.0\msvc2019_64"

# 2. Build
cmake --build build --config Release

# 3. Run
build\Release\NeonLauncher.exe
```

## ✅ Build & Run (macOS/Linux)

```bash
# 1. Configure
cmake -B build -DCMAKE_PREFIX_PATH=/path/to/Qt6

# 2. Build
cmake --build build --config Release

# 3. Run
./build/NeonLauncher
```

---

## 🔍 Debug Mode (برای مسائل)

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=/path/to/Qt6
cmake --build build --config Debug

# سپس GDB یا LLDB استفاده کن:
gdb ./build/NeonLauncher
# یا Qt Creator میں Debug mode
```

---

## 📝 نکات مهم

✅ **مطمئن شو:**
- Qt 6 نصب شده است
- CMake 3.16+ نصب شده است
- Compiler (MSVC/GCC/Clang) نصب شده است
- مسیر Qt صحیح است

✅ **Clean Build کن اگر:**
- تغییرات CMakeLists.txt داد
- اضافه کردن/حذف کردن فایل‌های source
- مسائل strange compiling داشتی
