# ===========================================
#          Sources view CMakeLists
# ===========================================
project(Flood-It-view)

# C++ sources files of the Flood-It-model
set(SOURCES
        GameGui.cpp
        FloodItConfiguration.cpp
        FloodItView.cpp
        FloodItGameOver.cpp
)

# Find required Qt6 components
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Enable Qt automatic handling of UI files, moc files, and resource files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Add library target for tetris_view_qtApp
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Link Qt6 libraries to the target
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Include the headers folder for linker
# Note: If needed, we can split header declarations into multiple child folders in the include folder
target_include_directories(${PROJECT_NAME} PUBLIC
        ../../include
        # If more folders or more specific folders are needed, you can add them here
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON)
