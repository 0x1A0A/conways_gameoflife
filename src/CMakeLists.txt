file(
	GLOB_RECURSE APP_SRC
	"${CMAKE_CURRENT_LIST_DIR}/*.cpp"
)

add_executable(App ${APP_SRC})

target_link_libraries( App ${OpenCV_LIBS} raylib raygui )

