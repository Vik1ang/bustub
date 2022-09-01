add_subdirectory(primer)

add_library(bustub STATIC ${ALL_OBJECT_FILES})

set(BUSTUB_LIBS
        bustub_primer
        )

set(BUSTUB_THIRDPARTY_LIBS
        bustub_murmur3
        duckdb_pg_query
        fmt)

target_link_libraries(
        bustub
        ${BUSTUB_LIBS}
        ${BUSTUB_THIRDPARTY_LIBS}
)

target_link_directories(
        bustub PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)