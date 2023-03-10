file(
	GLOB_RECURSE APP_SRC
	"${CMAKE_CURRENT_LIST_DIR}/*.cpp"
)

add_executable(App ${APP_SRC})

find_package(Threads)

target_link_libraries( App raylib raygui Threads::Threads)

file(
	GLOB_RECURSE SHADER_SRC
	"${CMAKE_CURRENT_LIST_DIR}/shaders/*"
)

file(COPY ${SHADER_SRC} DESTINATION "shaders")
