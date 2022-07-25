SET(target_name heap_)
project(${target_name})

SET(CPP_FILES
	heap.cpp
	main.cpp

)

SET(HEAD_FILES
	heap.h
)


add_executable(${target_name} ${CPP_FILES} ${HEAD_FILES})


