# Specify the name of the executable.
add_executable(assign02)

# Specify the source files to be compiled.
target_sources(assign02 PRIVATE assign02.c assign02.S)

# Pull in commonly used features.
target_link_libraries(assign02 PRIVATE pico_stdlib)

# Create map/bin/hex file etc.
pico_add_extra_outputs(assign02)

# Add the URL via pico_set_program_url.
apps_auto_set_url(assign02)
