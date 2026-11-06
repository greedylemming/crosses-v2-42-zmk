cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# ---------------------------------------------------------------------------
# INCLUDE PATH INTERCEPTION METHOD
# ---------------------------------------------------------------------------
# We explicitly use the 'BEFORE' keyword. This tells the build engine to prepend 
# our module's include directory to the very front of the compiler's search path.
# When any file calls #include <zmk/hid.h>, it hits our custom file first.
# ---------------------------------------------------------------------------

# Apply path precedence globally across all core Zephyr subsystems
target_include_directories(zephyr INTERFACE BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Apply path precedence explicitly to the main ZMK application context
target_include_directories(app PRIVATE BEFORE "${CMAKE_CURRENT_SOURCE_DIR}/include")
