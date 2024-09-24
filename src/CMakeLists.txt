# ===========================================
#            Sources CMakeLists
# ===========================================
project(Flood-It)

# Include subdirectory for model
add_subdirectory(model)
add_subdirectory(view)

# Create the main executable
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        Flood-It-model
        Flood-It-view
)