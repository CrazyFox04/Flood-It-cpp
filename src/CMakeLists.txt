# ===========================================
#            Sources CMakeLists
# ===========================================
project(Flood-It)

# Include subdirectory for model
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(utils)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        Flood-It-view
        Flood-It-model
        Flood-It-utils
)