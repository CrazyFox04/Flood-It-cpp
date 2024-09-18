# ===========================================
#            Sources CMakeLists
# ===========================================
project(Flood-It)

# Include subdirectory for model
add_subdirectory(model)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp
        ../include/Square.hpp)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        Flood-It-model
)