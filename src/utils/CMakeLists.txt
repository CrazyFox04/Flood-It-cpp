# ===========================================
#          Sources model CMakeLists
# ===========================================
project(Flood-It-utils)

# C++ sources files of the Flood-It-model
set(SOURCES
       FileManager.cpp
)

# Create the model library that public can use
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include the headers folder for linker
# Note : If needed, we can split headers declaration in multiple child folder in the include folder.
target_include_directories(${PROJECT_NAME} PUBLIC
        ../../include
        # If more folder or more specific you can add it here
)
