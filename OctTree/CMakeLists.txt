SET(target_name topology)
project(${target_name})

SET(CPP_FILES
	main.cpp

)

SET(HEAD_FILES
)


add_executable(${target_name} ${CPP_FILES} ${HEAD_FILES})


